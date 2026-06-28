#include "animation.h"
#include "gl_compat.h"

double door_anglex=0;
double elevator_door=0, lift_y=0;
double road_car_x=-85;

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

    road_car_x += 0.35;
    if (road_car_x > 230) {
        road_car_x = -85;
    }

    glutPostRedisplay();

}
