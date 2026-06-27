#include "animation.h"
#include <GL/glut.h>

double door_anglex=0, door_angley=180;
double left_door_x=38, right_door_x1=62.7;
double elevator_door=0, elevator_floor=0, lift_y=0;

bool doorOpen=false, doorClose=true;
GLboolean liftUp = false, liftDown = true;

void animate()
{

    if(doorClose){
        door_anglex+=5;
        door_anglex=(door_anglex>=90?90:door_anglex);
    }
    if(doorOpen){
        door_anglex-=5;
        door_anglex=(door_anglex<=0?0:door_anglex);
    }
    if (liftUp){
        lift_y+=0.4;
        lift_y=(lift_y>=22.5?22.5:lift_y);
    }
    if(liftDown){
        lift_y-=0.2;
        lift_y=(lift_y<=0?0:lift_y);
    }

    glutPostRedisplay();

}
