#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "BmpLoader.h"
#include "geometry.h"
#include "lighting.h"
#include "camera.h"
#include "textures.h"
#include "animation.h"
#include "shelving.h"
#include "freezers.h"
#include "products.h"
#include "decor.h"
#include "building.h"
#include "environment.h"
#include "scene.h"
#include "input.h"

double Txval=0,Tyval=0,Tzval=0;

GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
static GLfloat v_pyramid[5][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 0.0, 0.0},
    {1.0, 4.0, 1.0}
};

static GLubyte p_Indices[4][3] =
{
    {4, 1, 2},
    {4, 2, 3},
    {4, 3, 0},
    {4, 0, 1}
};

static GLubyte quadIndices[1][4] =
{
    {0, 3, 2, 1}
};

static GLfloat colors[5][3] =
{
    {0.0, 0.0, 1.0},
    {0.5, 0.0, 1.0},
    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {0.8, 0.0, 0.0}
};

void cubeColor(float x, float y, float z, float a, float b, float c, int shine)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { x, y, z, 1.0 };
    GLfloat mat_diffuse[] = { a, b, c, 1.0 };
    GLfloat mat_specular[] = { 1, 1,1 , 1.0 };
    GLfloat mat_shininess[] = {shine};
//front phase niye kaaj hoche
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glutSolidCube(3);

}

void cube(float x, float y, float z)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { x, y, z, 1.0 };
    GLfloat mat_diffuse[] = { 0.6, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1, 1,1 , 1.0 };
    GLfloat mat_shininess[] = {60};
//front phase niye kaaj hoche
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

   glutSolidCube(3);

}

static void idle(void)
{
    glutPostRedisplay();
}



int main (int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // glutInitWindowPosition(500, 200);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("SuperShop");


    //ceil
    LoadTexture("bmp/ceil.bmp");
    //wall
    LoadTexture("bmp/wall.bmp");
    //floor
    LoadTexture("bmp/floor.bmp");
    //swapno logo
    LoadTexture("bmp/swapno.bmp");
    //grass
    LoadTexture("bmp/grass.bmp");
    //window mirror 6
    LoadTexture("bmp/window.bmp");
    //red stripe for shelf 7
    LoadTexture("bmp/redstripe.bmp");
    //sale box 8
    LoadTexture("bmp/sale.bmp");
    //road 9
    LoadTexture("bmp/road.bmp");
    //concrete brick 10
    LoadTexture("bmp/brick.bmp");
    //concrete brick 11
    LoadTexture("bmp/fence.bmp");
    //pretrol pump lower 12
    LoadTexture("bmp/fuelpumplower.bmp");
    //pretrol pump upper 13
    LoadTexture("bmp/fuelpumpupper.bmp");
    //black 14
    LoadTexture("bmp/black.bmp");
    //wood 15
    LoadTexture("bmp/wood.bmp");
    //wood 16
    LoadTexture("bmp/noodles.bmp");
    //wood 17
    LoadTexture("bmp/kitten.bmp");
    //wood 18
    LoadTexture("bmp/chef.bmp");
    //wood 19
    LoadTexture("bmp/oat.bmp");
    //wood 20
    LoadTexture("bmp/chilli.bmp");
    //wood 21
    LoadTexture("bmp/choco1.bmp");
    //wood 22
    LoadTexture("bmp/choco2.bmp");
    //ac 23
    LoadTexture("bmp/ac.bmp");
    //signs 24
    LoadTexture("bmp/signs.bmp");
    //ice creAm 25
    LoadTexture("bmp/ice_cream.bmp");
    //freezer inside 26
    LoadTexture("bmp/freezer_inside.bmp");
    //frozen food 27
    LoadTexture("bmp/frozen_food.bmp");
    //colafreeze 28
    LoadTexture("bmp/cola.bmp");
    //day_sky 29
    LoadTexture("bmp/sky.bmp");
    //night sky 30
    LoadTexture("bmp/nightsky.bmp");


    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);


    light0();


    //spot
    light1();
    light2();



    //glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);
     //glutIdleFunc(idle);

     //glClearColor(1,1,1,1);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    glutMainLoop();

    return 0;
}
