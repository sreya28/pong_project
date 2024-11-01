#include "snowman_class.h"
#include <iostream>

// initialise the snowman class 
Snowman::Snowman()
{
	// set x speed
	speed_x = 40; 

	// set original x position to random value between snowzone x min and max (-40 to 40)
	x = orig_x = rand() % 70 + (-35);
	y = orig_y = rand() % 60 + (-30);

	// check if y is set in ball position
	while (y < 13 && y > -13) y = orig_y = rand() % 60 + (-30);

	// set y speed to random value between max snowzone y and min y (-90 to 90)
	speed_y = 30;
}

void Snowman::Reset()
{
	// set x speed
	speed_x = 40;

	// set original x position to random value between snowzone x min and max (-40 to 40)
	x = rand() % 70 + (-35);
	y = rand() % 60 + (-30);

	// check if y is set in ball position
	while (y < 13 && y > -13) y = rand() % 60 + (-30);

	// set y speed to random value between max snowzone y and min y (-90 to 90)
	speed_y = 30;
}
