#include "shelving.h"
#include "gl_compat.h"
#include "geometry.h"

void product(){
    //16-20
    int n = 16;
    for(float i=1; i<47; i+=2.08){

        for(int j=0; j<1; j+=1){
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,n);
            glTranslatef(i, 0, 118.4-j*0.25);
            glRotated(-15, 1, 0, 0);
            glScalef(2, 2, 0.25);
            drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
            glDisable(GL_TEXTURE_2D);
            glPopMatrix();

        }
        n+=1;
        if(n>20) n=16;
    }
}


void chocolates(float width, float height){
    //16-20
    int n = 20;
    for(float k=0;k<0.4;k+=0.11){
        for(float i=1; i<height; i+=2.08){
            for(int j=0; j<width; j+=1){
                glPushMatrix();
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D,n);
                glTranslatef(i, k, 118.2-j*0.55);
                glScalef(2, 0.1, 0.75);
                drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();

            }
            if(n==20) n=21;
            else n=20;
        }
    }
}

void shelf(){

    //first shelf rack___
    glPushMatrix();
    glTranslatef(0, 13.5, 90.7);
    glScalef(50, 0.4, 3);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


    //___
    glPushMatrix();
    glTranslatef(0, 9, 90.7);
    glScalef(50, 0.4, 3);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    //---
    glPushMatrix();
    glTranslatef(0, 4.5, 90.7);
    glScalef(50, 0.4, 3);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    //___
    glPushMatrix();
    glTranslatef(0, 0, 90.7);
    glScalef(50, 1, 3);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();

    //red stripe 3
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glTranslatef(0, 13.5, 93.72);
    glScalef(50, 0.6, 0);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //red stripe 2
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glTranslatef(0, 9, 93.72);
    glScalef(50, 0.6, 0);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //red stripe 1
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glTranslatef(0, 4.5, 93.72);
    glScalef(50, 0.6, 0);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //red stripe down 0
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glTranslatef(0, 0, 93.72);
    glScalef(50, 1, 0);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //red stripe left down
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glTranslatef(-0.01, 0, 90);
    glScalef(0, 1, 3.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //red stripe left up
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glTranslatef(-0.01, 0, 90);
    glScalef(0, 15, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //red stripe right up
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glTranslatef(50.01, 0, 90);
    glScalef(0, 15, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //red stripe right down
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glTranslatef(50.01, 0, 90);
    glScalef(0, 1, 3.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    //spine
    glPushMatrix();
    glTranslatef(0, 0, 90);
    glScalef(50, 15, 0.8);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();



    // TO DO
    glPushMatrix();
    glTranslatef(0, 1.5, -25);
    product();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5.2, -25);
    product();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 9.4, -25);
    product();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 14.32, -25);
    chocolates();
    glPopMatrix();

}


void double_shelf(){
    glPushMatrix();
    shelf();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50, 0, 180.2);
    glRotatef(180, 0, 1, 0);
    shelf();
    glPopMatrix();
}

void place_shelves(){


    for(int i=10; i>-31; i-=10){
        //LEFT
        glPushMatrix();
        glTranslatef(10, 0, (i<-11?10:i));
        glScalef(0.5, 0.9, 0.5);
        double_shelf();
        glPopMatrix();

        //right
        glPushMatrix();
        glTranslatef(60, 0, i);
        glScalef(0.5, 0.9, 0.5);
        double_shelf();
        glPopMatrix();
    }

    //left wall shelf


    for(int i=25.5; i<100; i+=22){
        //left wall shelf
        glPushMatrix();
        glTranslatef(-90, 0, (i+20>=90?80:i+10));
        glRotatef(90, 0, 1, 0);
        glScalef(0.5, 1.2, 1);
        shelf();
        glPopMatrix();


        //right wall shelf
        glPushMatrix();
        glTranslatef(190, 0, i-23);
        glRotatef(-90, 0, 1, 0);
        glScalef(0.5, 1.2, 1);
        shelf();
        glPopMatrix();

    }

    glPushMatrix();
    glTranslatef(-90, 0, 99.5);
    glRotatef(90, 0, 1, 0);
    glScalef(0.5, 1.2, 1);
    shelf();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(190, 0, 0);
    glRotatef(-90, 0, 1, 0);
    glScalef(0.5, 1.2, 1);
    shelf();
    glPopMatrix();




}
