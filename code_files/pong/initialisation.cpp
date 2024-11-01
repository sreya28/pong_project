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
