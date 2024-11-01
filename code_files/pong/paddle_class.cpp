#include <iostream>
#include "paddle_class.h"

using namespace std;

// initialise the Paddle class at position 0,0 
Paddle::Paddle(float pos_x, int win_height)
{
    x = orig_x = pos_x;
    y = orig_y = 0;
    paddle_colour = 0x00cc00; // 0xff8000; // burnt orange
    paddle_width = 3.5;
    paddle_height = 14;
    window_height = win_height; 
    speed = 0.f; 
    acceleration = 0; 
    acc_constant = 1800;
    player_move = false;
}

void Paddle::Reset()
{
    y = orig_y;
    speed = 0.f;
    acceleration = 0;
    player_move = false;
}


// output position of paddle
void Paddle::disp_paddle_data()
{
    cout << "Paddle [" << x << "," << y << "]" << endl;
}
