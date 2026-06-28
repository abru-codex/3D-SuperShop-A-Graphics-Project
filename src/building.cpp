#include "building.h"
#include "gl_compat.h"
#include "geometry.h"
#include "decor.h"

void entrance(){
    //white border ______
    glPushMatrix();
    glTranslatef(40, 35, 199.5);
    glScalef(50, 1, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


     //white border | left
    glPushMatrix();
    glTranslatef(40, 0, 199.5);
    glScalef(1, 45, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


    //white border | right
    glPushMatrix();
    glTranslatef(90, 0, 199.5);
    glScalef(1, 45, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


     //white border middle |
    glPushMatrix();
    glTranslatef(65, 35, 200);
    glScalef(1, 9, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();





    //create left windows on entrance
    glPushMatrix();
    mirror();
    glPopMatrix();

    //create right windows on entrance
    glPushMatrix();
    glTranslatef(90.5, 0, 0);
    glScalef(0.97,1,1);
    mirror();
    glPopMatrix();



    //white border leftmost |
    glPushMatrix();
    glTranslatef(0, 0, 199.5);
    glScalef(1, 45, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


    //white border | rightmost
    glPushMatrix();
    glTranslatef(129, 0, 199.5);
    glScalef(1, 45, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();






}






void base(){

    //back
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glScalef(200, 110, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //up
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    glTranslatef(0,45,0);
    glRotatef(90, 1, 0, 0);
    glScalef(200, 200, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //floor
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    glTranslatef(0,0,0);
    glRotatef(90, 1, 0, 0);
    glScalef(200, 200, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //left
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glTranslatef(0, 0, 20);
    glRotatef(-90, 0, 1, 0);
    glScalef(180, 110, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //right
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glTranslatef(200, 0, 0);
    glRotatef(-90, 0, 1, 0);
    glScalef(200.0, 110, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //front
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0, 45, 199.8);
    glScalef(200.0, 70, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




    //entrance
    glPushMatrix();
    glTranslatef(35, 0, 0);
    entrance();
    glPopMatrix();




    //shop concrete outline
    glPushMatrix();
    glTranslatef(-10,-0.1,-10);
    glRotatef(90, 1, 0, 0);
    glScalef(220, 220, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


    //grass outside
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,5);
    glTranslatef(-1500,-0.17,-1500);
    glRotatef(90, 1, 0, 0);
    glScalef(3000, 3000, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




    //wall left of entrance
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glTranslatef(0, 0, 199.2);
    glScalef(35, 45, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //wall right of entrance
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glTranslatef(165, 0, 199.2);
    glScalef(35, 45, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}

void base2(){
    //front
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glTranslatef(0, -25, 199);
    glScalef(200, 70, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //left above lift
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glTranslatef(0, 20, 0);
    glRotatef(-90, 0, 1, 0);
    glScalef(20, 20, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //up
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    glTranslatef(0,40.5,0);
    glRotatef(90, 1, 0, 0);
    glScalef(200, 200, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //floor
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    glTranslatef(0,-24.5,-0.1);
    glRotatef(90, 1, 0, 0);
    glScalef(200, 200, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}
