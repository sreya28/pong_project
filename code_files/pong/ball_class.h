#pragma once
#ifndef BALL_CLASS_H
#define BALL_CLASS_H

class Ball
{
private:
    // store ball information in private variable 
    float x, y;
    float orig_x, orig_y;
    float ball_width; 
    float speed_x, speed_y;
    float rebound_const;

public:
    // initialise the Ball class with default values
    Ball();

    // reset ball position and direction 
    void Reset();

    // ----------------------------------------------- get functions
    // get balls width 
    inline int get_width() { return ball_width; }
    
    // get balls current x position 
    inline int get_x() { return x; }
   
    // get balls current y position 
    inline int get_y() { return y; }

    // get balls speed_x
    inline float get_speed_x() { return speed_x;  };

    // get balls speed_y
    inline float get_speed_y() { return speed_y; };

    // ----------------------------------------------- set functions
    // set ball x 
    inline void set_x(float val) { x = val; };

    // set ball y
    inline void set_y(float val) { y = val; };

    // set ball speed x
    inline void set_speed_x(float val) { speed_x = val; };

    // set ball speed y
    inline void set_speed_y(float val) { speed_y = val; };

    // invert ball speed x
    inline void invert_speed_x() { speed_x *= -rebound_const; };

    // invert ball speed y
    inline void invert_speed_y() { speed_y *= -rebound_const; };

    // add to ball x
    inline void add_to_x(float val) { x += val; };

    // add to ball y
    inline void add_to_y(float val) { y += val; };
};
#endif
