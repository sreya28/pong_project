// ------------------------------------------------------------------------------------ File Inclusions
#include <Windows.h>
#include "game_manager_class.h"
#include "paddle_class.h"
#include "ball_class.h"
#include "snowman_class.h"
#include "global_variables.cpp"
#include "graphics_renderer.cpp"
#include "window_state_handler.cpp"
#include "game_controlls.cpp"
#include "game_play.cpp"

// ------------------------------------------------------------------------------------ Window Main 
int WinMain(HINSTANCE h_inst, HINSTANCE h_prev_inst, LPSTR lp_cmd_line, int n_show_cmd)
{
	// initialise window class and create window (functions in window_state_handler.cpp)
	HWND window = create_window(h_inst, h_prev_inst, lp_cmd_line, n_show_cmd, render_state);
	HDC hdc = GetDC(window);

	// create button input variable (struct variable in global_variables.cpp)
	Input input = {};

	// initialise game
	game_manager gm = game_manager(render_state.width, render_state.height, round_num);

	// get start time of frame to find delta time step 
	LARGE_INTEGER frame_begin_time;
	QueryPerformanceCounter(&frame_begin_time);

	float performance_frequency;
	{
		LARGE_INTEGER perf;
		QueryPerformanceFrequency(&perf);
		performance_frequency = (float)perf.QuadPart;
	}

	// keep the window open until game stops running
	while (running)
	{
		// get input button states (from game_controls.cpp)
		input = get_button_states(input, window);

		// simulate
		input = simulate_game(&gm, &input, delta_time);

		// render
		render_game(hdc);

		// get finish time of frame 
		LARGE_INTEGER frame_end_time;
		QueryPerformanceCounter(&frame_end_time);

		// calculate delta
		delta_time = (float)(frame_end_time.QuadPart - frame_begin_time.QuadPart) / performance_frequency;
		frame_begin_time = frame_end_time;
	}
}
