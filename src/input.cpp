#include "input.h"
#include <GL/glut.h>
#include <cstdlib>
#include "camera.h"
#include "animation.h"
#include "textures.h"
#include "lighting.h"

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'y':
        //double door_angle=0, left_door_x=38, right_door_x1=50.45, right_door_x1=62.7;
        if(doorClose) doorClose=false, doorOpen=true;
        else if(doorOpen) doorClose=true, doorOpen=false;
        break;
    case '=':
        if(elevator_door==0) elevator_door=22.5;
        else elevator_door=0;
        break;

    case '-':
        if(liftDown) liftUp=true, liftDown=false;
        else if(liftUp) liftDown=true, liftUp=false;
        break;

    case '0': //back to default eye point and ref point
        eyeX=65, eyeY=50, eyeZ=90, refX = -10, refY=30,refZ=0;
        break;
    case '1':
        eyeX=17, eyeY=20, eyeZ=90, refX = 110, refY=30,refZ=0;
        break;
    case '2':
        //glDisable(GL_LIGHTING);
        light0();
        break;
    case '3':
        //glDisable(GL_LIGHTING);
        light2();
        break;
    case '4':
        eyeX=40, eyeY=10, eyeZ=150, refX = 55, refY=10,refZ=0;
        break;
    case '5':
        eyeX=40, eyeY=20, eyeZ=40, refX = -40, refY=30,refZ=0; //door open ground
        break;
    case '6':
        eyeX=-20, eyeY=20, eyeZ=60, refX = 40, refY=20,refZ=0; //lift working
        break;
    case '7':
        eyeX=40, eyeY=40, eyeZ=40, refX = 0, refY=30,refZ=0; //2nd floor view
        break;
    case '9':
        night_mode = !night_mode;
        sky_texture = night_mode ? 30 : 29;
        // glLight*(GL_POSITION) bakes current MODELVIEW into the
        // position. Reset to identity so re-applied lights land in
        // world space (matches startup), otherwise re-toggle drifts.
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        light0();
        light2();
        glPopMatrix();
        break;

    case '8':
        light1();
        break;
    case 'w': // move eye point upwards along Y axis
        eyeY+=1.0;
        break;
    case 's': // move eye point downwards along Y axis
        eyeY-=1.0;
        break;
    case 'a': // move eye point left along X axis
        eyeX-=1.0;
        break;
    case 'd': // move eye point right along X axis
        eyeX+=1.0;
        break;
    case 'o':  //zoom out
        eyeZ+=1;
        break;
    case 'i': //zoom in
        eyeZ-=1;
        break;
    case 'q': //back to default eye point and ref point
            eyeX=100, eyeY=10, eyeZ=100, refX = 40, refY=10,refZ=0;
        break;
    case 'j': // move ref point upwards along Y axis
        refY+=1.0;
        break;
    case 'n': // move ref point downwards along Y axis
        refY-=1.0;
        break;
    case 'b': // move ref point left along X axis
        refX-=1.0;
        break;
    case 'm': // move eye point right along X axis
        refX+=1.0;
        break;
    case 'k':  //move ref point away from screen/ along z axis
        refZ+=1;
        break;
    case 'l': //move ref point towards screen/ along z axis
        refZ-=1;
        break;

    case 27:    // Escape key
        exit(1);
    }
    glutPostRedisplay();
}
