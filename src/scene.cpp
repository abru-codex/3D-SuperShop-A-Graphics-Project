#include "scene.h"
#include "gl_compat.h"
#include "camera.h"
#include "building.h"
#include "shelving.h"
#include "decor.h"
#include "products.h"
#include "freezers.h"
#include "environment.h"
#include "parking.h"

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

    // car parking — west of petrol pumps, north of building
    glPushMatrix();
    glTranslatef(-90, 0, 115);
    parking_lot();
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

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(90, 1, 0.09, 100000000);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,refX,refY,refZ,0,1,0);;

    glViewport(0, 0, 1920, 1080);

    glPushMatrix();
    glScalef(0.7, 1.1, 1);
    display1st();
    glPopMatrix();


    glPushMatrix();
    glScalef(0.7, 1.1, 1);
    display2nd();
    glPopMatrix();

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
