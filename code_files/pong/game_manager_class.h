#pragma once
#include "ball_class.h"
#include "paddle_class.h"
#include "snowman_class.h"

#ifndef GAME_MANAGER_CLASS_H
#define GAME_MANAGER_CLASS_H

class game_manager
{
private:
    // store game window width and height, and player scores
    int width, height;
    int score1, score2; 

    // boolean to see who won
    bool p1_win, p2_win;

    // number of levels/rounds in the game
    int rounds; 

    // initialise objects for ball and players
    Ball* ball; 
    Paddle* player1; 
    Paddle* player2;

    // initialise object for snowman
    Snowman* snowman;

public:
    // initialise the game_manager class with screen width and height
    game_manager(int w, int h, int round_num);

    // ----------------------------------------------- player get functions
    // get player1 x postion 
    inline int get_p1_x() { return player1->get_x(); };

    // get player1 y postion 
    inline int get_p1_y() { return player1->get_y(); };

    // get player1 colour 
    inline unsigned int get_p1_colour() { return player1->get_colour(); };

    // get player1 height 
    inline int get_p1_height() { return player1->get_height(); };

    // get player1 width 
    inline int get_p1_width() { return player1->get_width(); };

    // get player2 x position 
    inline int get_p2_x() { return player2->get_x(); };

    // get player2 y position 
    inline int get_p2_y() { return player2->get_y(); };

    // get player2 colour 
    inline unsigned int get_p2_colour() { return player2->get_colour(); };

    // get player2 height 
    inline int get_p2_height() { return player2->get_height(); };

    // get player2 width 
    inline int get_p2_width() { return player2->get_width(); };

    // get player1 speed
    inline float get_p1_speed() { return player1->get_speed(); };

    // get player2 speed
    inline float get_p2_speed() { return player2->get_speed(); };

    // get p1 acceleration 
    inline float get_p1_accel() { return player1->get_accel(); };

    // get p2 acceleration 
    inline float get_p2_accel() { return player2->get_accel(); };

    // get player1 move boolean
    inline bool check_p1_move() { return player1->get_player_move(); };

    // get player2 move boolean
    inline bool check_p2_move() { return player2->get_player_move(); };

    // ----------------------------------------------- player set functions
    // move player1 up
    inline void move_p1_up() { player1->move_up(); };

    // move player1 down 
    inline void move_p1_down() { player1->move_down(); };

    // move player2 up
    inline void move_p2_up() { player2->move_up(); };

    // move player2 down
    inline void move_p2_down() { player2->move_down(); };

    // set player1 acceleration 
    inline void set_p1_accel(float accel) { player1->set_accel(accel); };

    // set player2 acceleration 
    inline void set_p2_accel(float accel) { player2->set_accel(accel); };

    // set player1 acceleration constant 
    inline void set_p1_accel_const(float val) { player1->set_accel_const(val); };

    // set player2 acceleration constant 
    inline void set_p2_accel_const(float val) {  player2->set_accel_const(val); };

    // add to player1 speed 
    inline void add_p1_speed(float s) { player1->add_to_speed(s); };

    // set player1 speed 
    inline void set_p1_speed(float s) { player1->set_speed(s); };

    // add to player2 speed 
    inline void add_p2_speed(float s) { player2->add_to_speed(s); };

    // set player2 speed 
    inline void set_p2_speed(float s) { player2->set_speed(s); };

    // decrease player1 acceleration 
    inline void dec_p1_accel(float val) { player1->dec_accel(val); };

    // decrease player2 acceleration 
    inline void dec_p2_accel(float val) { player2->dec_accel(val); };

    // add to player1 position 
    inline void add_p1_pos(float val) { player1->add_to_y(val); };

    // set player1 position 
    inline void set_p1_pos(float val) { player1->set_y(val); };

    // add to player2 position 
    inline void add_p2_pos(float val) { player2->add_to_y(val); };

    // set player2 position 
    inline void set_p2_pos(float val) { player2->set_y(val); };

    // ----------------------------------------------- ball get functions
    // get ball width
    inline int get_ball_width() { return ball->get_width(); };

    // get ball x position 
    inline int get_ball_x() { return ball->get_x();  };

    // get ball y position 
    inline int get_ball_y() { return ball->get_y(); };

    // get ball speed x
    inline float get_ball_speed_x() { return ball->get_speed_x(); };

    // get ball speed y
    inline float get_ball_speed_y() { return ball->get_speed_y(); };

    // ----------------------------------------------- ball set functions
    // set ball x
    inline void set_ball_x(float val) { ball->set_x(val); };

    // set ball y
    inline void set_ball_y(float val) { ball->set_y(val); };

    // add to ball x
    inline void add_ball_x(float val) { ball->add_to_x(val); };

    // add to ball y
    inline void add_ball_y(float val) { ball->add_to_y(val); };

    // invert ball speed x
    inline void invert_ball_speed_x() { ball->invert_speed_x(); };

    // invert ball speed y
    inline void invert_ball_speed_y() { ball->invert_speed_y(); };

    // set ball speed x
    inline void set_ball_speed_x(float val) { ball->set_speed_x(val); };
    
    // set ball speed y
    inline void set_ball_speed_y(float val) { ball->set_speed_y(val); };

    // ----------------------------------------------- snowman get functions
    // get snowman width
    inline float get_snowman_width() { return snowman->get_width(); };

    // get snowman height
    inline float get_snowman_height() { return snowman->get_height(); };

    // get snowman x position 
    inline float get_snowman_x() { return snowman->get_x(); };

    // get snowman y position 
    inline float get_snowman_y() { return snowman->get_y(); };

    // get snowman speed x
    inline float get_snowman_speed_x() { return snowman->get_speed_x(); };

    // get snowman speed y
    inline float get_snowman_speed_y() { return snowman->get_speed_y(); };

    // ----------------------------------------------- snowman set functions
    // set snowman x
    inline void set_snowman_x(float val) { snowman->set_x(val); };

    // set snowman y
    inline void set_snowman_y(float val) { snowman->set_y(val); };

    // add to snowman x
    inline void add_snowman_x(float val) { snowman->add_to_x(val); };

    // add to snowman y
    inline void add_snowman_y(float val) { snowman->add_to_y(val); };

    // invert snowman speed x
    inline void invert_snowman_speed_x() { snowman->invert_speed_x(); };

    // invert snowman speed y
    inline void invert_snowman_speed_y() { snowman->invert_speed_y(); };

    // set snowman speed x
    inline void set_snowman_speed_x(float val) { snowman->set_speed_x(val); };

    // set snowman speed y
    inline void set_snowman_speed_y(float val) { snowman->set_speed_y(val); };

    // ----------------------------------------------- player scores
    // increase player1 score
    inline void score_up_p1() { score1++; };

    // get player1 score
    inline int get_p1_score() { return score1; };

    // increase player2 score
    inline void score_up_p2() { score2++; };

    // get player2 score
    inline int get_p2_score() { return score2; };

    // get winner status p1
    inline bool get_p1_win() { return p1_win; };

    // get winner status p2
    inline bool get_p2_win() { return p2_win; };

    // set winner status p1
    inline void set_p1_win(bool val) { p1_win = val; };

    // set winner status p2
    inline void set_p2_win(bool val) { p2_win = val; };
     
    // ----------------------------------------------- reset functions
    inline void reset_ball() { ball->Reset(); };
    inline void reset_p1() { player1->Reset(); };
    inline void reset_p2() { player2->Reset(); };
    inline void reset_snowman() { snowman->Reset(); };
    inline void reset_score() { score1 = score2 = 0; };

    // ----------------------------------------------- end game 
    // initialise the game_manager destructor to free memory when required
    ~game_manager();
    
};

#endif

