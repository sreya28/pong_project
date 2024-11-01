

// function to get button states and set it to the variable input
Input get_button_states(Input input, HWND window)
{
	// input
	MSG message;

	// loop through all buttons and set changed to false in each iteration
	for (int i = 0; i > BUTTON_COUNT; i++)
	{
		input.buttons[i].changed = false;
	}

	// check if a button has been pressed and change input state
	while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
	{
		switch (message.message)
		{
			case WM_KEYUP:

			case WM_KEYDOWN:
			{
				unsigned int vk_code = (unsigned int)message.wParam;
				bool is_down = ((message.lParam & (1 << 31)) == 0);

				// shift key for player 1 paddle up movement
				if ( vk_code == VK_SHIFT)
				{
					input.buttons[BUTTON_P2_UP].changed = is_down != input.buttons[BUTTON_P1_UP].is_down;
					input.buttons[BUTTON_P2_UP].is_down = is_down;
				} 

				// space key for player 1 paddle down movement
				if (vk_code == VK_SPACE)
				{
					input.buttons[BUTTON_P2_DOWN].changed = is_down != input.buttons[BUTTON_P1_DOWN].is_down;
					input.buttons[BUTTON_P2_DOWN].is_down = is_down;
				} 

				if (vk_code == VK_UP)
				{
					input.buttons[BUTTON_P1_UP].changed = is_down != input.buttons[BUTTON_P2_UP].is_down;
					input.buttons[BUTTON_P1_UP].is_down = is_down;

					input.buttons[BUTTON_UP].is_down = is_down;
					input.buttons[BUTTON_UP].changed = true;
				}

				// down arrow key for player 2 paddle down movement
				if (vk_code == VK_DOWN)
				{
					input.buttons[BUTTON_P1_DOWN].changed = is_down != input.buttons[BUTTON_P2_DOWN].is_down;
					input.buttons[BUTTON_P1_DOWN].is_down = is_down;

					input.buttons[BUTTON_DOWN].is_down = is_down;
					input.buttons[BUTTON_DOWN].changed = true;
				}
				
				// right key for selection in home screen
				if (vk_code == VK_RIGHT)
				{
					input.buttons[BUTTON_RIGHT].is_down = is_down;
					input.buttons[BUTTON_RIGHT].changed = true;
				}
				
				// left key for selection in home screen
				if (vk_code == VK_LEFT)
				{
					input.buttons[BUTTON_LEFT].is_down = is_down;
					input.buttons[BUTTON_LEFT].changed = true;
				}
				
				// enter key for selection in home screen
				if (vk_code == VK_RETURN)
				{
					input.buttons[BUTTON_ENTER].is_down = is_down;
					input.buttons[BUTTON_ENTER].changed = true;
				}

				// R key for reset game
				if (vk_code == 0x52)
				{
					input.buttons[BUTTON_RESET].changed = is_down != input.buttons[BUTTON_RESET].is_down;
					input.buttons[BUTTON_RESET].is_down = is_down;
				} 

				// escape key for exit game
				if (vk_code == VK_ESCAPE)
				{
					input.buttons[BUTTON_EXIT].changed = is_down != input.buttons[BUTTON_EXIT].is_down;
					input.buttons[BUTTON_EXIT].is_down = is_down;
				}

			} break;

			default:
			{
				TranslateMessage(&message);
				DispatchMessage(&message);

			}
		}
	}
	return input;
}