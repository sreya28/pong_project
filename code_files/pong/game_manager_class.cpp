#include <iostream>
#include "game_manager_class.h"
#include "ball_class.h"
#include "paddle_class.h"
#include "snowman_class.h"

using namespace std;

// initialise the game_manager class with screen width and height
game_manager::game_manager(int w, int h, int round_num)
{
	srand(time(NULL));

	rounds = round_num;

	score1 = score2 = 0;

	width = w; 
	height = h;

	ball = new Ball();

	player1 = new Paddle(80,h);
	player2 = new Paddle(-80,h);

	snowman = new Snowman();

	p1_win = false; 
	p2_win = false;
}

// initialise the game_manager destructor to free memory when required
game_manager::~game_manager()
{
	delete ball, player1, player2;
}
