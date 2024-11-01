#pragma once
#ifndef SNOWMAN_CLASS_H
#define SNOWMAN_CLASS_H

class Snowman
{
private:
    // store snowman information in private variables 
    float x, y;
    float orig_x, orig_y;
    float snowman_width = 10;
    float snowman_height = 18;
    float speed_x, speed_y;

public:
    // initialise the snowman class with default values
    Snowman();

    // reset snowman position
    void Reset();

    // ----------------------------------------------- get functions
    // get x position 
    inline float get_x() { return x; };

    // get y position 
    inline float get_y() { return y; };

    // get speed x  
    inline float get_speed_x() { return speed_x; };

    // get speed y  
    inline float get_speed_y() { return speed_y; };

    // get height 
    inline float get_height() { return snowman_height; };

    // get width
    inline float get_width() { return snowman_width; };

    // ----------------------------------------------- set functions
    // set x 
    inline void set_x(float val) { x = val; };

    // set y
    inline void set_y(float val) { y = val; };

    // set speed x
    inline void set_speed_x(float val) { speed_x = val; };

    // set speed y
    inline void set_speed_y(float val) { speed_y = val; };

    // invert speed x
    inline void invert_speed_x() { speed_x *= -1; };

    // invert speed y
    inline void invert_speed_y() { speed_y *= -1; };

    // add to x
    inline void add_to_x(float val) { x += val; };

    // add to y
    inline void add_to_y(float val) { y += val; };
};
#endif
