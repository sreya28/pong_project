// ------------------------------------------------------------------------------------ Result Handling 
LRESULT get_results(LRESULT result, HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param)
{
	switch (u_msg)
	{
		case WM_CLOSE:

		case WM_DESTROY:
		{
			running = false;
		} break;

		case WM_SIZE:
		{
			// get window information 
			RECT rect;
			GetClientRect(hwnd, &rect);

			// calculate window width and height to get buffer size
			render_state.width = rect.right - rect.left;
			render_state.height = rect.bottom - rect.top;
			int size = render_state.width * render_state.height * sizeof(unsigned int);

			// when window size changes, free memory then re allocate based on new window size 
			if (render_state.memory) VirtualFree(render_state.memory, 0, MEM_RELEASE);
			render_state.memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			// buffer bitmap info
			render_state.bitmap_info.bmiHeader.biSize = sizeof(render_state.bitmap_info.bmiHeader);
			render_state.bitmap_info.bmiHeader.biWidth = render_state.width;
			render_state.bitmap_info.bmiHeader.biHeight = render_state.height;
			render_state.bitmap_info.bmiHeader.biPlanes = 1; 
			render_state.bitmap_info.bmiHeader.biBitCount = 32;
			render_state.bitmap_info.bmiHeader.biCompression = BI_RGB;
		} break; 

		default:
		{
			result = DefWindowProc(hwnd, u_msg, w_param, l_param);
		}
	}
	return result;
}

// ------------------------------------------------------------------------------------ Handle Window States 
LRESULT CALLBACK window_callback(HWND hwnd, UINT u_msg, WPARAM w_param, LPARAM l_param)
{
	LRESULT result = 0;

	// handle states using function get results 
	return get_results(result, hwnd, u_msg, w_param, l_param);
}

// ------------------------------------------------------------------------------------ Create Window
HWND create_window(HINSTANCE h_inst, HINSTANCE h_prev_inst, LPSTR lp_cmd_line, int n_show_cmd, Render_State render_state)
{
	// create the window class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Window Class";
	window_class.lpfnWndProc = window_callback;

	// register the window class
	RegisterClass(&window_class);

	// create the window
	HWND window = CreateWindow(
		window_class.lpszClassName,
		"Pong Game",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		render_state.orig_width,
		render_state.orig_height,
		0,
		0,
		h_inst,
		0);

	return window;
}