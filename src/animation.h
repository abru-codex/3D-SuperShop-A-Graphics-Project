#ifndef ANIMATION_H
#define ANIMATION_H

#include <GL/gl.h>

extern double door_anglex, door_angley;
extern double left_door_x, right_door_x1;
extern double elevator_door, elevator_floor, lift_y;

extern bool doorOpen, doorClose;
extern GLboolean liftUp, liftDown;

void animate();

#endif
