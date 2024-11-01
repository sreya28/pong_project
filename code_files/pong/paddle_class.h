#pragma once
#ifndef PADDLE_CLASS_H
#define PADDLE_CLASS_H

class Paddle
{
private:
    // store position and direction of the paddle in private variable 
    float x, y;
    float orig_x, orig_y;
    unsigned int paddle_colour; 
    float paddle_width;
    float paddle_height; 
    int window_height; 
    float speed, acceleration; 
    float acc_constant;
    bool player_move;

public:
    // initialise the Paddle class with default values 
    Paddle(float pos_x, int win_height);

    // reset paddle to original position, speed and acceleration and set player_move to false
    void Reset();

    // move paddle up the screen
    inline void move_up()
    {
        acceleration += acc_constant;
        player_move = true;
    }

    // move paddle down the screen
    inline void move_down() 
    { 
        acceleration -= acc_constant;
        player_move = true;
    }

    // ----------------------------------------------- get functions
    // get paddle colour 
    inline unsigned int get_colour() { return paddle_colour; }

    // get paddle width 
    inline int get_width() { return paddle_width; }

    // get paddle height 
    inline int get_height() { return paddle_height; }

    // get current x position of paddle
    inline int get_x() { return x; }

    // get current y position of paddle
    inline int get_y() { return y; }

    // get paddle speed 
    inline float get_speed() { return speed; }

    // get paddle acceleration 
    inline float get_accel() { return acceleration; }

    // get player move boolean
    inline bool get_player_move() { return player_move; };

    // ----------------------------------------------- set functions
    // update paddle speed
    inline void add_to_speed(float s) { speed += s; }

    // set paddle speed
    inline void set_speed(float s) { speed = s; }

    // set paddle acceleration 
    inline void set_accel(float accel) { acceleration = accel; }

    // set the acceleration constant 
    inline void set_accel_const(float val) { acc_constant = val; };

    // decrease paddle acceleration 
    inline void dec_accel(float val) { acceleration -= val; }

    // set paddle y position  
    inline void set_y(float pos_y) { y = pos_y; }

    // add to paddle y position  
    inline void add_to_y(float pos_y) { y += pos_y; }

    // output position of paddle
    void disp_paddle_data();
};

#endif

