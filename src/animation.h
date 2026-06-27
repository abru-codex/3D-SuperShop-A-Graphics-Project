#ifndef ANIMATION_H
#define ANIMATION_H

#include <GL/gl.h>

extern double door_anglex;
extern double elevator_door, lift_y;

extern bool doorOpen, doorClose;
extern GLboolean liftUp, liftDown;

void animate();

#endif
