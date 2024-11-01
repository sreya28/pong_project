// ---------------------------------------------------------------------------------- Collision Detection 
static void check_player_collisions(game_manager* gm)
{
	// check player upper bound
	if ((gm->get_p1_y() + gm->get_p1_height() / 2) > arena_y)
	{
		gm->set_p1_pos(arena_y - gm->get_p1_height() / 2);
		gm->set_p1_speed(0);
	}
	if ((gm->get_p2_y() + gm->get_p2_height() / 2) > arena_y)
	{
		gm->set_p2_pos(arena_y - gm->get_p2_height() / 2);
		gm->set_p2_speed(0);
	}

	// check player lower bound
	if ((gm->get_p1_y() - gm->get_p1_height() / 2) < -arena_y)
	{
		gm->set_p1_pos(-arena_y + gm->get_p1_height() / 2);
		gm->set_p1_speed(0);
	}
	if ((gm->get_p2_y() - gm->get_p2_height() / 2) < -arena_y)
	{
		gm->set_p2_pos(-arena_y + gm->get_p2_height() / 2);
		gm->set_p2_speed(0);
	}
}

static void check_ball_snowmode_collision(game_manager* gm)
{
	// check ball collision with snowman right side
	if ((gm->get_ball_x() - gm->get_ball_width() / 2.f) < (gm->get_snowman_x() + gm->get_snowman_width() / 2.f) &&
		(gm->get_ball_x() + gm->get_ball_width() / 2.f) > (gm->get_snowman_x() - gm->get_snowman_width() / 2.f) &&
		(gm->get_ball_y() + gm->get_ball_width() / 2.f) > (gm->get_snowman_y() - gm->get_snowman_height() / 2.f) &&
		(gm->get_ball_y() - gm->get_ball_width() / 2.f) < (gm->get_snowman_y() + gm->get_snowman_height() / 2.f))
	{
		gm->invert_snowman_speed_x();
		gm->invert_ball_speed_x();
	}

	// check ball collision with snowman left side 
	else if ((gm->get_ball_x() + gm->get_ball_width() / 2.f) > (gm->get_snowman_x() - gm->get_snowman_width() / 2.f) &&
		     (gm->get_ball_x() - gm->get_ball_width() / 2.f) < (gm->get_snowman_x() + gm->get_snowman_width() / 2.f) &&
		     (gm->get_ball_y() + gm->get_ball_width() / 2.f) > (gm->get_snowman_y() - gm->get_snowman_height() / 2.f) &&
		     (gm->get_ball_y() - gm->get_ball_width() / 2) < (gm->get_snowman_y() + gm->get_snowman_height() / 2))
	{
		gm->invert_snowman_speed_x();
		gm->invert_ball_speed_x();
	}

	// check collision with bottom of snowman
	if (((gm->get_ball_y() + gm->get_ball_width()) > (gm->get_snowman_y() - gm->get_snowman_height() / 2.f)) &&
		((gm->get_ball_y() - gm->get_ball_width()) < (gm->get_snowman_y() - gm->get_snowman_height() / 2.f)) &&
		((gm->get_ball_x() + gm->get_ball_width()) > (gm->get_snowman_x() - gm->get_snowman_width() / 2.f)) &&
		((gm->get_ball_x() - gm->get_ball_width()) < (gm->get_snowman_x() + gm->get_snowman_width() / 2.f)))
	{
		// set position and invert y speed of ball
		gm->invert_snowman_speed_y();
		gm->set_ball_speed_y(-50);
	}

	// check collision with top of snowman
	else if (((gm->get_ball_y() + gm->get_ball_width()) > (gm->get_snowman_y() + gm->get_snowman_height() / 2)) &&
		     ((gm->get_ball_y() - gm->get_ball_width()) < (gm->get_snowman_y() + gm->get_snowman_height() / 2)) &&
		     ((gm->get_ball_x() + gm->get_ball_width()) > (gm->get_snowman_x() - gm->get_snowman_width() / 2.f)) &&
		     ((gm->get_ball_x() - gm->get_ball_width()) < (gm->get_snowman_x() + gm->get_snowman_width() / 2.f)))
	{
		// set position and invert y speed of ball
		gm->invert_snowman_speed_y();
		gm->set_ball_speed_y(50);
	}
}

static void check_ball_collisions(game_manager* gm)
{
	// check ball collision with player 1 paddle
	if ((gm->get_ball_x() + gm->get_ball_width() / 2.f) > (gm->get_p1_x() - gm->get_p1_width() / 2.f) &&
		(gm->get_ball_x() - gm->get_ball_width() / 2.f) < (gm->get_p1_x() + gm->get_p1_width() / 2.f) &&
		(gm->get_ball_y() + gm->get_ball_width() / 2.f) > (gm->get_p1_y() - gm->get_p1_height() / 2.f) &&
		(gm->get_ball_y() - gm->get_ball_width() / 2.f) < (gm->get_p1_y() + gm->get_p1_height() / 2.f))
	{
		gm->set_ball_x(gm->get_p1_x() - gm->get_p1_width() / 2.f - gm->get_ball_width() / 2.f);
		gm->invert_ball_speed_x();
		// set ball speed y to paddle speed y to change balls direction based on collision
		gm->set_ball_speed_y((gm->get_ball_y() - gm->get_p1_y()) * ball_y_const_1 + gm->get_p1_speed() * ball_y_const_2);
		if (snow_mode) {
			snow_battle_score++;
		}
	}

	// check ball collision with player 2 paddle
	else if ((gm->get_ball_x() + gm->get_ball_width() / 2.f) > (gm->get_p2_x() - gm->get_p2_width() / 2.f) &&
		(gm->get_ball_x() - gm->get_ball_width() / 2.f) < (gm->get_p2_x() + gm->get_p2_width() / 2.f) &&
		(gm->get_ball_y() + gm->get_ball_width() / 2.f) > (gm->get_p2_y() - gm->get_p2_height() / 2.f) &&
		(gm->get_ball_y() - gm->get_ball_width() / 2) < (gm->get_p2_y() + gm->get_p2_height() / 2))
	{
		gm->set_ball_x(gm->get_p2_x() + gm->get_p2_width() / 2.f + gm->get_ball_width() / 2.f);
		gm->invert_ball_speed_x();
		// set ball speed y to paddle speed y to change balls direction based on collision
		gm->set_ball_speed_y((gm->get_ball_y() - gm->get_p2_y()) * ball_y_const_1 + gm->get_p2_speed() * ball_y_const_2);
		if (snow_mode) {
			snow_battle_score++;
		}
	}

	// check ball collision with arena
	if ((gm->get_ball_y() + gm->get_ball_width() / 2.f) > arena_y)
	{
		gm->set_ball_y(arena_y - gm->get_ball_width() / 2.f);
		gm->invert_ball_speed_y();
	}
	else if ((gm->get_ball_y() - gm->get_ball_width() / 2.f) < -arena_y)
	{
		gm->set_ball_y(-arena_y + gm->get_ball_width() / 2.f);
		gm->invert_ball_speed_y();
	}

	// check if ball hit back wall for either player side 
	// right side
	if ((gm->get_ball_x() + gm->get_ball_width() / 2.f) > arena_x)
	{
		// rebound ball
		gm->set_ball_x(arena_x - gm->get_ball_width() / 2.f);

		// reset game
		reset_game_check = true;

		// increment player 1 score
		if (!snow_mode) gm->score_up_p1();
	}
	// left side
	else if ((gm->get_ball_x() - gm->get_ball_width() / 2.f) < -arena_x)
	{
		// rebound ball
		gm->set_ball_x(-arena_x + gm->get_ball_width() / 2.f);

		// reset game
		reset_game_check = true;

		// increment player 2 score
		if (!snow_mode) gm->score_up_p2();
	}

	// check ball collision with snowman if snowmode is true
	if (snow_mode)
	{
		check_ball_snowmode_collision(gm);
	}
}

static void check_snowman_collisions(game_manager* gm)
{
	// check snowman collision with top/bottom arena
	if ((gm->get_snowman_y() + gm->get_snowman_height() / 2.f) > arena_y)
	{
		gm->set_snowman_y(arena_y - gm->get_snowman_height() / 2.f);
		gm->invert_snowman_speed_y();
	}
	else if ((gm->get_snowman_y() - gm->get_snowman_height() / 2.f) < -arena_y)
	{
		gm->set_snowman_y(-arena_y + gm->get_snowman_height() / 2.f);
		gm->invert_snowman_speed_y();
	}

	// check snowman collision with side snow arena walls 
	// right side
	else if ((gm->get_snowman_x() + gm->get_snowman_width() / 2.f) > snow_arena_x)
	{
		// rebound ball
		gm->set_snowman_x(snow_arena_x - gm->get_snowman_width() / 2.f);
		gm->invert_snowman_speed_x();
	}
	// left side
	else if ((gm->get_snowman_x() - gm->get_snowman_width() / 2.f) < -snow_arena_x)
	{
		// rebound ball
		gm->set_snowman_x(-snow_arena_x + gm->get_snowman_width() / 2.f);
		gm->invert_snowman_speed_x();
	}
}

// ---------------------------------------------------------------------------------- Update Position Functions 
// update player positions 
static void update_player_pos(game_manager* gm, Input* input, float dt)
{
	// set player acceleration to zero
	gm->set_p1_accel(0);
	gm->set_p2_accel(0);

	// --------------------------------------------------- player 1 controls
	// update player accelerations based on move direction
	if (is_down(BUTTON_P1_UP)) gm->move_p1_up();
	if (is_down(BUTTON_P1_DOWN)) gm->move_p1_down();

	// --------------------------------------------------- player 2 controls
	// check if user is versing another player or the computer
	if (!AI_verse)
	{
		gm->set_p2_accel_const(1800);
		if (is_down(BUTTON_P2_UP)) gm->move_p2_up();
		if (is_down(BUTTON_P2_DOWN)) gm->move_p2_down();
	}
	else
	{
		// decrease paddle acceleration for AI to make it slightly easier to beat
		gm->set_p2_accel_const(AI_acc_const);

		// move paddle up or down if ball is above or below the paddle
		if (gm->get_ball_y() > gm->get_p2_y()) gm->move_p2_up();
		if (gm->get_ball_y() < gm->get_p2_y()) gm->move_p2_down();

		// set the player acceleration equal to ball position minues paddle position
		gm->set_p2_accel((gm->get_ball_y() - gm->get_p2_y()) * 100.f);

		// clamp the acceleration to 1100 if it exceeds
		if (gm->get_p2_accel() > AI_acc_const) gm->set_p2_accel(AI_acc_const);
		if (gm->get_p2_accel() < -AI_acc_const) gm->set_p2_accel(-AI_acc_const);
	}
	

	// add friction to movement 
	gm->dec_p1_accel(gm->get_p1_speed() * f_const);
	gm->dec_p2_accel(gm->get_p2_speed() * f_const);

	// update player y position where pt = po + v*dt + a*dt^2 / 2
	gm->add_p1_pos(gm->get_p1_speed() * dt + gm->get_p1_accel() * dt * dt * 0.5f);
	gm->add_p2_pos(gm->get_p2_speed() * dt + gm->get_p2_accel() * dt * dt * 0.5f);

	// update player speed
	gm->add_p1_speed(gm->get_p1_accel() * dt);
	gm->add_p2_speed(gm->get_p2_accel() * dt);

	// check for collisions between player and arena
	check_player_collisions(gm);
}

// update ball position 
static void update_ball_pos(game_manager* gm, Input* input, float dt)
{
	if (gm->check_p1_move() || gm->check_p2_move())
	{
		// update ball position
		gm->add_ball_x(gm->get_ball_speed_x() * dt);
		gm->add_ball_y(gm->get_ball_speed_y() * dt);

		// check ball collision with objects
		check_ball_collisions(gm);
	}
}

// update snowman position
static void update_snowman_pos(game_manager* gm, Input* input, float dt)
{
	// increase snow man speed if highscore is greater than 50 and then 100
	if (snow_battle_score > 10 && !snow_level_2)
	{
		snow_level = 2;
		gm->set_snowman_speed_x(snowman_speed_medium);
		gm->set_snowman_speed_y(snowman_speed_medium - 10);
		snow_level_2 = true;
		snowman_body_colour = 0xff9999;// light red
	} 

	if (snow_battle_score > 20 && !snow_level_3)
	{
		snow_level = 3;
		gm->set_snowman_speed_x(snowman_speed_hard);
		gm->set_snowman_speed_y(snowman_speed_hard - 10);
		snow_level_3 = true;
		snowman_body_colour = 0xff6666; // red
	}

	if (gm->check_p1_move() || gm->check_p2_move())
	{
		// update ball position
		gm->add_snowman_x(gm->get_snowman_speed_x() * dt);
		gm->add_snowman_y(gm->get_snowman_speed_y() * dt);

		// check snowman collision with objects
		check_snowman_collisions(gm);
	}

}

// ---------------------------------------------------------------------------------- Update Graphics Functions
// clear screen and redraw arena
static void clear_screen_graphics()
{
	// clear screen
	clear_screen(render_state.bg_colour);

	// draw arena
	draw_arena_borders(arena_x, arena_y, arena_colour);
}

// home screen graphics
static void draw_home_screen()
{
	// draw pong game title 
	draw_text("CHRISTMAS PONG", -40, 41, 2, score_colour);

	// christmas light cable
	draw_text("~~~~", -85, 42, 3, score_colour);
	draw_text("~~~~", 48, 42, 3, score_colour);

	// change light colours 
	colour_count++;

	if (colour_count == 100)
	{
		// switch colours
		light_c1 = 0xff3300; // red 
		light_c2 = 0xffd11a; // yellow 
		light_c3 = 0x00ff00; // lime
	}
	else if (colour_count == 200)
	{
		light_c1 = 0xffd11a; // yellow 
		light_c2 = 0x00ff00; // lime 
		light_c3 = 0xff3300; // red 
		colour_count = 0;
	}

	// left lights 
	draw_rect(-78,35,3,3, light_c1);
	draw_rect(-78, 32.5, 2, 2, light_c1);
	draw_rect(-78, 31, 1, 1, light_c1);

	draw_rect(-69,35,3,3, light_c3);
	draw_rect(-69,32.5,2,2, light_c3);
	draw_rect(-69,31,1,1, light_c3);

	draw_rect(-60,35,3,3, light_c2);
	draw_rect(-60, 32.5, 2, 2, light_c2);
	draw_rect(-60, 31, 1, 1, light_c2);

	// right lights
	draw_rect(75, 35, 3, 3, light_c2);
	draw_rect(75, 32.5, 2, 2, light_c2);
	draw_rect(75, 31, 1, 1, light_c2);

	draw_rect(65, 35, 3, 3, light_c1);
	draw_rect(65, 32.5, 2, 2, light_c1);
	draw_rect(65, 31, 1, 1, light_c1);

	draw_rect(55, 35, 3, 3, light_c3);
	draw_rect(55, 32.5, 2, 2, light_c3);
	draw_rect(55, 31, 1, 1, light_c3);

	// draw snow flakes 
	draw_text("*", -50, -25, 6, 0xb3ffff); //light blue
	draw_text("*", 30, -35, 3, 0xb3ffff); //light blue
	draw_text("*", 23, 30, 9, 0xb3ffff); //light blue

	// Verse AI option
	draw_rect(-60,0,40,40, selection_AI);
	draw_text("VERSE", -68, 5, 1.3, 0x000000);
	draw_text("COMPUTER", -75, 0, 1.3, 0x000000);

	// Multiplayer option 
	draw_rect(0, 0, 40, 40, selection_M);
	draw_text("MULTI", -10, 5, 1.3, 0x000000);
	draw_text("PLAYER", -12, 0, 1.3, 0x000000);

	// Snow Battle option
	draw_rect(60, 0, 40, 40, selection_S);
	draw_text("SNOW", 52, 5, 1.3, 0x000000);
	draw_text("BATTLE", 49, 0, 1.3, 0x000000);

	// change game difficulty settings
	draw_rect(0, -35, 45, 10, selection_D);
	draw_text("SETTINGS", -15, -34, 1.3, 0x000000);
}

// draw graphics for settings window
static void draw_settings_screen() 
{
	// choose difficulty level text
	draw_text("SET DIFFICULTY LEVEL", -35, 35, 1.3, score_colour);

	// draw difficulty level options 
	// initial selected option 
	draw_rect(0, 15, 30, 10, select_Easy);
	draw_text("EASY", -7, 16, 1.3, score_colour);

	draw_rect(0, 0, 30, 10, select_Medium);
	draw_text("MEDIUM", -11, 1, 1.3, score_colour);

	draw_rect(0, -15, 30, 10, select_Hard);
	draw_text("HARD", -7, -14, 1.3, score_colour);

	// draw snow flakes 
	draw_text("*", -50, -25, 6, 0xb3ffff); 
	draw_text("*", 50, 20, 10, 0xb3ffff); 
	draw_text("*", -80, 30, 3, 0xb3ffff);

	// draw arrow 
	draw_text(">", -30, select_arrow_y, 4, arrow_colour);

	// draw home button 
	draw_text("h", -85, -35, 3, select_Home); 
}

// draw ball 
void draw_ball(game_manager* gm) 
{
	draw_rect(gm->get_ball_x(), gm->get_ball_y(), gm->get_ball_width(), gm->get_ball_width(), 0xfff0b3); // light yellow
	draw_rect(gm->get_ball_x(), gm->get_ball_y(), gm->get_ball_width()/1.5f, gm->get_ball_width()/1.5f, 0xffdb4d); // warm yellow
	draw_rect(gm->get_ball_x(), gm->get_ball_y(), gm->get_ball_width()/4.f, gm->get_ball_width()/4.f, 0xe6b800); // dark yellow
}

// update ball and player graphics
static void update_game_graphics(game_manager* gm, bool end_game)
{
	// redraw player scores 
	if (!AI_verse)
	{
		draw_text("PLAYER ONE", -70, 41, 1.2, score_colour);
		draw_text("PLAYER TWO", 35, 41, 1.2, score_colour);
	}
	if (AI_verse)
	{
		draw_text("COMPUTER AI", -70, 41, 1.2, score_colour);
		draw_text("YOU", 35, 41, 1.2, score_colour);
	}

	draw_number(gm->get_p1_score(), -score_pos_x, score_pos_y, score_width, score_colour);
	draw_number(gm->get_p2_score(), score_pos_x, score_pos_y, score_width, score_colour);

	// redraw ball
	draw_ball(gm);
	
	// redraw players
	draw_rect(gm->get_p1_x(), gm->get_p1_y(), gm->get_p1_width(), gm->get_p1_height(), gm->get_p1_colour());
	draw_rect(gm->get_p2_x(), gm->get_p2_y(), gm->get_p2_width(), gm->get_p2_height(), gm->get_p2_colour());
	
	// if game has ended display winner banner
	if (end_game)
	{
		// set colour
		colour_count++;

		if (colour_count == 150) 
		{
			win_banner_colour = 0x00cc00;
		}
		else if (colour_count == 300)
		{
			win_banner_colour = 0xff0000;
			colour_count = 0;
		}

		// display winner banner 
		if (gm->get_p1_win() && !AI_verse) draw_text("PLAYER ONE", -28, 2, 2, win_banner_colour); 
		if (gm->get_p1_win() && AI_verse) draw_text("COMPUTER AI", -30, 2, 2, win_banner_colour); 
		if (gm->get_p2_win()) draw_text("PLAYER TWO", -28, 2, 2, win_banner_colour); 
		draw_text("WINS", -10, -8, 2, win_banner_colour);

		// press enter to play again
		draw_text("PRESS ENTER TO PLAY AGAIN", -44, -20, 1.2, win_banner_colour);
	}
}

// draw fire ball 
void draw_fire_ball(game_manager* gm)
{
	draw_rect(gm->get_ball_x(), gm->get_ball_y(), gm->get_ball_width(), gm->get_ball_width(), 0xffc299); // light orange
	draw_rect(gm->get_ball_x(), gm->get_ball_y(), gm->get_ball_width() / 1.5f, gm->get_ball_width() / 1.5f, 0xff6600); // orange
	draw_rect(gm->get_ball_x(), gm->get_ball_y(), gm->get_ball_width() / 4.f, gm->get_ball_width() / 4.f, 0xff0000); // red
}

// draw snow man graphics
static void draw_snow_man(float x, float y)
{
	float new_y = y - 5;

	// draw body
	draw_rect(x, new_y, 10, 8, snowman_body_colour);
	draw_rect(x, new_y + 7, 7, 6, snowman_body_colour);

	// draw eyes
	draw_rect(x - 1, new_y + 8, 1, 1, 0x000000);
	draw_rect(x + 1, new_y + 8, 1, 1, 0x000000);

	// draw nose
	draw_rect(x, new_y + 6, 0.6, 0.6, 0xff6600);
	draw_rect(x + 0.25, new_y + 5.95, 0.5, 0.5, 0xff6600);
	draw_rect(x + 0.5, new_y + 5.90, 0.5, 0.5, 0xff6600);
	draw_rect(x + 0.75, new_y + 5.85, 0.5, 0.5, 0xff6600);
	draw_rect(x + 1, new_y + 5.80, 0.5, 0.5, 0xff6600);
	draw_rect(x + 1.25, new_y + 5.75, 0.5, 0.5, 0xff6600);
	draw_rect(x + 1.4, new_y + 5.75, 0.5, 0.5, 0xff6600);

	// draw hat 
	draw_rect(x, new_y + 10.5, 10, 1, 0x5cd65c);
	draw_rect(x, new_y + 12.5, 5, 3, 0x5cd65c);

	// draw scarf
	draw_rect(x, new_y + 4, 7.5, 1, 0x5cd65c);
	draw_rect(x - 0.5, new_y + 3, 1, 1, 0x5cd65c);
	draw_rect(x + 0.5, new_y + 3, 1, 1, 0x5cd65c);
	draw_rect(x - 1, new_y + 2.5, 1, 1, 0x5cd65c);
	draw_rect(x + 1, new_y + 2.5, 1, 1, 0x5cd65c);
	draw_rect(x - 1.5, new_y + 2, 1, 1, 0x5cd65c);
	draw_rect(x + 1.5, new_y + 2, 1, 1, 0x5cd65c);
}

// draw snow battle arena
static void draw_snow_battle_arena() 
{
	// draw snow zone
	draw_rect(0, 0, snow_arena_x * 2, 90, 0x80dfff);
	draw_text("*", -29, 22, 22, 0x99e6ff);

	// draw player fire zone
	draw_rect(64, 0, 48, 90, 0xffb3b3);
	draw_rect(-64, 0, 48, 90, 0xffb3b3);
}

// update snow battle graphics 
static void update_snow_battle_graphics(game_manager* gm)
{
	// redraw player high score 
	draw_text("HIGHSCORE", -85, 40, 1.2, score_colour); 
	draw_number(snow_battle_highscore, -48 , 38.75, 1.2, score_colour);

	// draw player level
	draw_text("LEVEL", 62, 40, 1.2, score_colour);
	draw_number(snow_level, 82, 38.75, 1.2, score_colour);

	// redraw ball
	draw_fire_ball(gm);

	// redraw players
	draw_rect(gm->get_p1_x(), gm->get_p1_y(), gm->get_p1_width(), gm->get_p1_height(), 0xff0000);
	draw_rect(gm->get_p2_x(), gm->get_p2_y(), gm->get_p2_width(), gm->get_p2_height(), 0xff0000);

	// redraw snowman 
	draw_snow_man(gm->get_snowman_x(), gm->get_snowman_y());
}

// ---------------------------------------------------------------------------------- Reset game 
static void reset_game(game_manager* gm)
{
	if (gm->get_p1_score() < 5 && gm->get_p2_score() < 5)
	{
		// pause for half a second
		reset_counter++;

		// set reset_game_check to false again
		if (reset_counter > 100)
		{
			// reset ball and paddle
			gm->reset_ball();
			gm->reset_p1();
			gm->reset_p2();

			// reset snow battle game
			if (snow_mode)
			{
				snowman_body_colour = 0xffffff;
				gm->reset_snowman();
				snow_level_2 = snow_level_3 = false;
				if (snow_battle_score > snow_battle_highscore) snow_battle_highscore = snow_battle_score;
				snow_battle_score = 0;
			}

			// invert ball speed direction
			gm->invert_ball_speed_x();

			reset_game_check = false;
			reset_counter = 0;
		}
	}
}

static void reset_game_mode(game_manager* gm)
{
	// reset ball and paddle
	gm->reset_ball();
	gm->reset_p1();
	gm->reset_p2();

	// reset snowman
	if (snow_mode) gm->reset_snowman();
}

static bool check_end_game(game_manager* gm)
{
	if (gm->get_p1_score() == 5)
	{
		gm->set_p1_win(true);
		return true;
	}
	else if (gm->get_p2_score() == 5)
	{
		gm->set_p2_win(true);
		return true;
	}

	return false;
}

//  ---------------------------------------------------------------------------------- Game Windows
static void check_return_home_key(game_manager* gm, Input* input)
{
	// check if escape key is pressed 
	if (pressed(BUTTON_EXIT)) {

		if (!settings_mode)
		{
			reset_game_mode(gm);
			gm->reset_score();
			no_selection = true;
		}
		else no_selection = true;
	}
}

static void home_screen(game_manager* gm, Input* input, float dt) {
	// draw graphics for game modes
	draw_home_screen();

	// if right or left arrow change selection value  
	if (pressed(BUTTON_RIGHT) && !right_pressed)
	{
		select_val++;
		right_pressed = true;
	}
	if (released(BUTTON_RIGHT)) right_pressed = false; 
	if (pressed(BUTTON_LEFT) && !left_pressed)
	{
		select_val--;
		left_pressed = true;
	}
	if (released(BUTTON_LEFT)) left_pressed = false;

	if (select_val > 3) select_val = 3;
	if (select_val < 0) select_val = 0;

	switch (select_val)
	{
		// MULTIPLAYER
		case 1:
		{
			// update graphics 
			selection_AI = unselected_colour;
			selection_M = select_colour;
			selection_S = unselected_colour;
			selection_D = unselected_colour;

			// if user presses down arrow to go to change difficulty 
			if (pressed(BUTTON_DOWN))
			{
				select_val = 3; 
			}

			// enter multiplayer mode and exit home screen 
			if (pressed(BUTTON_ENTER))
			{
				no_selection = false;
				AI_verse = false;
				snow_mode = false;
				settings_mode = false;
				select_val = 0;
			}
	 
		} break;

		// SNOW BATTLE
		case 2:
		{
			selection_AI = unselected_colour;
			selection_M = unselected_colour;
			selection_S = select_colour;
			selection_D = unselected_colour;

			// enter verse computer mode and exit home screen 
			if (pressed(BUTTON_ENTER))
			{
				no_selection = false;
				AI_verse = false; 
				snow_mode = true;
				settings_mode = false;
				select_val = 0;
			}
		} break;
		
		// COMPUTER AI
		case 0:
		{
			selection_AI = select_colour;
			selection_M = unselected_colour;
			selection_S = unselected_colour;
			selection_D = unselected_colour;

			// enter verse computer mode and exit home screen 
			if (pressed(BUTTON_ENTER))
			{
				no_selection = false;
				AI_verse = true;
				snow_mode = false; 
				settings_mode = false;
				select_val = 0;
			}
		} break;

		// select difficulty
		case 3:
		{
			selection_AI = unselected_colour;
			selection_M = unselected_colour;
			selection_S = unselected_colour;
			selection_D = select_colour;

			// if user presses up arrow to go to change difficulty 
			if (pressed(BUTTON_UP))
			{
				select_val = 1;
			}

			// if user presses enter, go to settings window 
			if (pressed(BUTTON_ENTER))
			{
				no_selection = false;
				AI_verse = false;
				snow_mode = false;
				settings_mode = true;
				select_val = 0;
			}
		} break;

		default:
		{

		}
	}
}

static void game_screen(game_manager* gm, Input* input, float dt) 
{
	// draw snowflake in arena
	draw_text("*", -29, 22, 22, 0xffe6e6); //light red

	// if no one has won, keep playing
	if (!check_end_game(gm))
	{
		// reset game if collision with arena side walls
		if (reset_game_check) reset_game(gm);
		else 
		{
			// update player position 
			update_player_pos(gm, input, dt);

			// update ball position 
			update_ball_pos(gm, input, dt);
		}
	}
	else if (pressed(BUTTON_ENTER))
	{
		gm->reset_score();
		reset_game(gm);
	}

	// update graphics
	update_game_graphics(gm, check_end_game(gm));
}

static void snow_mode_screen(game_manager* gm, Input* input, float dt)
{
	// draw snow battle arena
	draw_snow_battle_arena();

	// reset game if collision with arena side walls
	if (reset_game_check) reset_game(gm);
	else
	{
		// update snowman positio 
		update_snowman_pos(gm, input, dt);

		// update player position 
		update_player_pos(gm, input, dt);

		// update ball position 
		update_ball_pos(gm, input, dt);
	}
	
	// update graphics
	update_snow_battle_graphics(gm);	
}

static void settings_mode_screen(game_manager* gm, Input* input, float dt)
{
	// draw graphics for settings window
	draw_settings_screen();

	// if down arrow change selection value 
	if (pressed(BUTTON_DOWN) && !right_pressed)
	{
		select_val++;
		right_pressed = true;
	}
	if (released(BUTTON_DOWN)) right_pressed = false;
	if (pressed(BUTTON_UP) && !left_pressed)
	{
		select_val--;
		left_pressed = true;
	}
	if (released(BUTTON_UP)) left_pressed = false;

	if (select_val > 4) select_val = 4;
	if (select_val < 0) select_val = 0;

	switch (select_val)
	{
		case 0:
		{
			arrow_colour = arrow_off;
			if (select_Easy != selected_diff) select_Easy = unselected_colour;
		} break;
		// EASY
		case 1:
		{
			if (select_Easy != selected_diff) select_Easy = select_colour;
			if (select_Medium != selected_diff) select_Medium = unselected_colour;
			if (select_Hard != selected_diff) select_Hard = unselected_colour;
			select_Home = unselected_colour;
			arrow_colour = arrow_on;

			select_arrow_y = 20;

			// enter multiplayer mode and exit home screen 
			if (pressed(BUTTON_ENTER))
			{
				AI_acc_const = AI_acc_const_easy;
				gm->set_ball_speed_x(ball_speed_easy);

				select_Easy = selected_diff;
				select_Hard = unselected_colour;
				select_Medium = unselected_colour;
			}

		} break;

		// MEDIUM 
		case 2:
		{

			if (select_Easy != selected_diff) select_Easy = unselected_colour;
			if (select_Medium != selected_diff) select_Medium = select_colour;
			if (select_Hard != selected_diff) select_Hard = unselected_colour;
			select_Home = unselected_colour;
			arrow_colour = arrow_on;

			select_arrow_y = 5;

			// enter multiplayer mode and exit home screen 
			if (pressed(BUTTON_ENTER))
			{
				AI_acc_const = AI_acc_const_medium;
				gm->set_ball_speed_x(ball_speed_medium);

				select_Medium = selected_diff;
				select_Easy = unselected_colour;
				select_Hard = unselected_colour;
			}

		} break;

		// HARD 
		case 3:
		{
			if (select_Easy != selected_diff) select_Easy = unselected_colour;
			if (select_Medium != selected_diff) select_Medium = unselected_colour;
			if (select_Hard != selected_diff) select_Hard = select_colour;
			select_Home = unselected_colour;
			arrow_colour = arrow_on;

			select_arrow_y = -10;

			// enter multiplayer mode and exit home screen 
			if (pressed(BUTTON_ENTER))
			{
				AI_acc_const = AI_acc_const_hard;
				ball_y_const_2 = ball_y_const_2_hard; 
				gm->set_ball_speed_x(ball_speed_hard);

				select_Hard = selected_diff;
				select_Easy = unselected_colour;
				select_Medium = unselected_colour;
			}

		} break;

		case 4:
		{
			if (select_Easy != selected_diff) select_Easy = unselected_colour;
			if (select_Medium != selected_diff) select_Medium = unselected_colour;
			if (select_Hard != selected_diff) select_Hard = unselected_colour;
			select_Home = selected_Home;
			arrow_colour = arrow_off;

			// enter multiplayer mode and exit home screen 
			if (pressed(BUTTON_ENTER))
			{
				no_selection = true;
				settings_mode = false;
				select_val = 0;

				Sleep(1000);
			}
		} break;
	}
}

// ---------------------------------------------------------------------------------- Simulate Game 
static Input simulate_game(game_manager* gm, Input* input, float dt)
{
	// clear screen and draw background 
	clear_screen_graphics();

	// open home screen if game mode has not been selected
	if (no_selection) 
	{
		home_screen(gm, input, dt);
	} 
	else  
	{
		// check if player wants to exit window
		check_return_home_key(gm, input);

		if (snow_mode) snow_mode_screen(gm, input, dt);
		else if (settings_mode) settings_mode_screen(gm, input, dt);
		else game_screen(gm, input, dt);
	}
	
	// return user input 
	return *input;
}