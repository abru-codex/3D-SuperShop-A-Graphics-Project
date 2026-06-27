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




void display1st(){


    //first floor
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    base();
    glPopMatrix();

    glPushMatrix();
    place_shelves();
    glPopMatrix();




    glPushMatrix();
    door();
    glPopMatrix();

    glPushMatrix();
    surroundings();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(190, 0, 60);
    glRotatef(-90, 0, 1, 0);
    glScalef(0.5,1,1);
    cash_counter();
    glPopMatrix();


    for(int i=0; i>-30; i-=10){
        glPushMatrix();
        glTranslatef(20, 0, -45+i);
        glScalef(0.8, 0.8, 0.8);
        chocolate_box();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(43, 5.5, -65+i);
        chocolates(5,5);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(47.6, 5.5, -65+i);
        chocolates(5,5);
        glPopMatrix();
    }



    glPushMatrix();
    petrol_pump();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-3.5,0, -107);
    glScalef(0.87, 0.9, 0.9);
    fruit_shelf();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(60, 0, 0);
    petrol_pump();
    glPopMatrix();

    glPushMatrix();
    ac();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-17, -1.6, -50);
    signs();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(-17, -1.6, -40);
    wall_lights();
    glPopMatrix();


}




void elevator(){

    //back
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(-10, lift_y, 0);
    glScalef(10,22.5,0.01);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //left
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(-10, lift_y, 0);
    glScalef(0.01,22.5,10);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //front
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(-10, lift_y, 10);
    glScalef(10,22.5,0.01);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //door
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(0, elevator_door, 0);
    glScalef(0.01,22.5,10);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //bottom
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(-10, lift_y, 0);
    glScalef(10,0.01,10);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //top
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(-10, lift_y+22.5, 0);
    glScalef(10,0.01,10);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //Elevator closed
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(0, (lift_y==0?22.5:0), 0);
    glScalef(0.01,22.5,10);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




}

void drawPizza() {
    glColor3f(1.0, 0.8, 0.0); // Set color to represent pizza crust

    // Draw pizza crust (a sphere)
    glutSolidSphere(1.0, 100, 100);

    // Draw pizza toppings (cylinders for simplicity)
    glColor3f(1.0, 0.0, 0.0); // Set color to represent pepperoni

    for (float angle = 0; angle < 360; angle += 30.0) {
        float radian = angle * 3.14159 / 180.0;
        float x = 0.6 * cos(radian);
        float y = 0.6 * sin(radian);

        glPushMatrix();
        glTranslatef(x, y, 0.1); // Adjust the z-coordinate for the toppings
        drawCylinder(0.2, 0.1, 50); // Draw a pepperoni (cylinder)
        glPopMatrix();
    }
}


void display2nd(){



    //spotlight
    glPushMatrix();
    glTranslatef(99, 20, 98.5);
    drawPizza();
    glPopMatrix();


    //second floor
    glPushMatrix();
    glTranslatef(0, 35, 0);
    glScalef(0.5, 0.5, 0.5);
    base2();
    glPopMatrix();


    glPushMatrix();
    elevator();
    glPopMatrix();


    //left wall freezer
    glPushMatrix();
    glTranslatef(-0.3, 22.5, 100);
    glRotatef(90, 0, 1, 0);
    //elevator();
    foodfreezer();
    glPopMatrix();


    /*
    //back wall freezer
    glPushMatrix();
    glTranslatef(10, 22.5, 0);
    foodfreezer();
    glPopMatrix();
    */


    //right wall freezer
    glPushMatrix();
    glTranslatef(99, 22.5, 0);
    glRotatef(-90, 0, 1, 0);
    glScalef(1.32, 1.2, 1);
    foodfreezer();
    glPopMatrix();


    for(float i=85.5; i>10; i-=10.1){
        glPushMatrix();
        glTranslatef(i, 22.5, 0);
        glScalef(1.3, 1.3, 1.3);
        colafreezer();
        glPopMatrix();
    }



    for(float i=30; i<80; i+=10.2){
        glPushMatrix();
        glTranslatef(40, 22.5,i);
        glScalef(1, 1.2, 2);
        icefreezer();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(50.2, 22.5,i+10);
        glRotatef(90, 0, 1, 0);
        glScalef(1, 1.2, 2);
        icefreezer();
        glPopMatrix();
    }




    glPushMatrix();
    glTranslatef(0, 30, 0);
    ac();
    glPopMatrix();
}


void sky(){
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,sky_texture);
    //glTranslatef(30, 0, 120);
    glScalef(10,10,10);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}

void round_sky(){
    glPushMatrix();
    //glTranslatef(-300, -100, -100);
    glTranslatef(30, 0, 120);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 0, 120);
    glRotatef(-20, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(49, 0, 123);
    glRotatef(-30, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(56, 0, 128);
    glRotatef(-45, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(62.55, 0, 134);
    glRotatef(-60, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(67.45, 0, 142);
    glRotatef(-70, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(70.5, 0, 150);
    glRotatef(-80, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(72, 0, 160);
    glRotatef(-90, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(72, 0, 170);
    glRotatef(-100, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(70.5, 0, 180);
    glRotatef(-110, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(66.5, 0, 190);
    glRotatef(-120, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(62, 0, 198);
    glRotatef(-130, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55.5, 0, 205.525);
    glRotatef(-140, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(48, 0, 212);
    glRotatef(-150, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 0, 216.6);
    glRotatef(-160, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(31, 0, 219.5);
    glRotatef(-170, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22, 0, 221.1);
    glRotatef(-180, 0, 1, 0);
    glScalef(1, 1, 0.05);
    sky();
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(90, 1, 0.09, 100000000);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,refX,refY,refZ,0,1,0);;

    glViewport(0, 0, 1900, 1000);

    glPushMatrix();
    glScalef(0.7, 1.1, 1);
    display1st();
    glPopMatrix();


    glPushMatrix();
    glScalef(0.7, 1.1, 1);
    display2nd();
    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(-10, 0, -40);
//    glScalef(10, 10, 1);
//    round_sky();
//    glPopMatrix();


    glPushMatrix();
    glTranslatef(-400, 0, -400);
    glScalef(80, 80, 0.1);
    sky();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-400, 0, -400);
    glRotatef(-90, 0, 1, 0);
    glScalef(80, 80, 0.1);
    sky();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(400, 0, -400);
    glRotatef(-90, 0, 1, 0);
    glScalef(80, 80, 0.1);
    sky();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(400, 0, 400);
    glRotatef(-180, 0, 1, 0);
    glScalef(80, 80, 0.1);
    sky();
    glPopMatrix();



    glFlush();
    glutSwapBuffers();

}


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
        if(sky_texture==29) sky_texture=30;
        else sky_texture=29;
        break;

    case '8':
        light1();
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
