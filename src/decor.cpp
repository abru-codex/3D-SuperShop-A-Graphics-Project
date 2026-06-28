#include "decor.h"
#include "gl_compat.h"
#include "geometry.h"
#include "animation.h"
#include "products.h"

void mirror(){

    //00
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(0, 10, 198.7);
    glScalef(40, 35, 0.7);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();





    //white border left-bottom
    glPushMatrix();
    glTranslatef(0, 0, 199.2);
    glScalef(40, 10, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    //white border left-bottom windows
    glPushMatrix();
    glTranslatef(0, 27.5, 199.2);
    glScalef(40, 0.8, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    // left |
    glPushMatrix();
    glTranslatef(20, 10, 199.2);
    glScalef(0.8, 35, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

}


void door(){

    //door_angle=0, left_door_x=38, right_door_x1=50.45, right_door_x1=62.7,
    glPushMatrix();
    glTranslatef(38, 0, 99.4);
    glRotatef(-1*door_anglex, 0, 1, 0);
    glScalef(12, 17.3, 0.5);
    drawCube(1, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 6);
    glTranslatef(38, 18, 99.4);
    glScalef(12, 5, 0.5);
    drawCube(1, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 6);
    glTranslatef(50.2, 18, 99.4);
    glScalef(12, 5, 0.5);
    drawCube(1, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    glPushMatrix();

    //closed
    //glTranslatef(50.45, 0, 99.4);
    //open
    glTranslatef(62.5, 0, 99.4);
    glRotatef(180+door_anglex, 0, 1, 0);
    glScalef(12.5, 17.3, 0.5);
    drawCube(1, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();
}


void cash_counter(){

    //|...:
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,7);
    glTranslatef(30, 0, 115);
    glScalef(7, 7.5, 14);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //:__:
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(37, 1, 124);
    glScalef(15, 6.5, 5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //:...|
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,7);
    glTranslatef(52, 0, 119);
    glScalef(7, 7.5, 10);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //white top
    glPushMatrix();
    glTranslatef(29.5, 7.6, 123.5);
    glScalef(30.5, 0.3, 5.5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();



    //white bottom left
    glPushMatrix();
    glTranslatef(29.5, 0, 114.5);
    glScalef(8, 0.3, 15);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    //white bottom right
    glPushMatrix();
    glTranslatef(51.5, 0, 118.5);
    glScalef(8, 0.3, 11);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


    //pc
    glPushMatrix();
    glTranslatef(0,-0.9,-8);
    glScalef(1.4,1,1);
    pc();
    glPopMatrix();



}

void surroundings(){

    //road
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,9);
    glTranslatef(-60, 0, 160);
    glScalef(300, 0.1, 20);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //shop brick concrete outline
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,10);
    glTranslatef(-50, -0.08, -40);
    glScalef(200, 0.1, 200);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //fence back
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,11);
    glTranslatef(-50, 0, -40);
    glScalef(200, 10, 1);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //fence left
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,11);
    glTranslatef(-50, 0, -40);
    glScalef(1, 10, 200);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //fence right
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,11);
    glTranslatef(150, 0, -40);
    glScalef(1, 10, 200);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}



void petrol_pump(){
    //head red
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,13);
    glTranslatef(20, 12.25, 140);
    glScalef(7, 4, 1.5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //head display
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,12);
    glTranslatef(20.75, 2.25, 140);
    glScalef(5.5, 10, 1.4);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //head red
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,13);
    glTranslatef(20, 0, 140);
    glScalef(7, 2, 1.5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}


void ac(){
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,23);
    glTranslatef(20, 19, 1);
    glScalef(8,2.5,2);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,23);
    glTranslatef(70, 19, 1);
    glScalef(8,2.5,2);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}



void signs(){
    glPushMatrix();
    glTranslatef(60, 22.2, 120);
    glScalef(0.3,2,0.3);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(67.7, 22.2, 120);
    glScalef(0.3,2,0.3);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,24);
    glTranslatef(60, 19, 120);
    glScalef(8,3.5,0.3);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}




void wall_lights(){
    glPushMatrix();
    glTranslatef(51, 23.6, 116);
    glScalef(16,0.3,23);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(84, 23.6, 90);
    glScalef(16,0.3,23);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(33.5, 23.6, 64);
    glScalef(16,0.3,23);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(84, 23.6, 41);
    glScalef(16,0.3,23);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

}
