#include <iostream>
#include "ball_class.h"

using namespace std;

// initialise the Ball class with default values
Ball::Ball()
{
    x = orig_x = 0;
    y = orig_y = 0;

    ball_width = 4;

    // set random x direction 
    int rand_dir = rand() % 2 + 1;
    if(rand_dir == 1) speed_x = 80;
    if(rand_dir == 2) speed_x = -80;

    // set a random y speed between -35 and 35
    speed_y = rand() % 71 + (-35);

    rebound_const = 1;
};

// reset ball position and direction 
void Ball::Reset()
{
    x = orig_x;
    y = orig_y;
    // set a random y speed between -35 and 35
    speed_y = rand() % 71 + (-35);
}
