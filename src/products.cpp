#include "products.h"
#include "gl_compat.h"
#include "geometry.h"

void chocolate_box(){
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,8);
    glTranslatef(30, 0, 119);
    glScalef(5, 7, 5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,8);
    glTranslatef(35.5, 0, 119);
    glScalef(5, 7, 5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}




void pc(){
    //monitor
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,14);
    glTranslatef(30, 10, 133.65);
    glRotatef(30, 1, 0, 0);
    glScalef(3, 2.5, 0.1);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //stand
    glPushMatrix();
    glTranslatef(31, 9.5, 134);
    glRotatef(-10, 1, 0, 0);
    glScalef(1, 1, 0.1);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glPopMatrix();


    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,14);
    glTranslatef(30, 9, 132.3);
    glScalef(3, 0.8, 2.5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}

void fruits(double r, double g, double b){
    for(double k=11;k<21;k+=1){
        for(double i=9.8, j=121.55; i<=8, j<=125.47;i-=0.3, j+=1){
            glPushMatrix();
            glTranslatef(k, i, j);
            glRotatef(22, 1, 0, 0);
            glScalef(0.5, 0.5, 0.5);
            drawSphere(r, g, b,0.6, 0.6, 0.4);
            glPopMatrix();
        }
    }
}




void fruit_shelf(){

    //shelf base
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,15);
    glTranslatef(10, 0, 119);
    glScalef(100, 7, 7);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //angled top
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,15);
    glTranslatef(9.95, 7, 119);
    glRotatef(22, 1, 0, 0);
    glScalef(100.1, 3, 10);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //angled boards up #
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,15);
    glTranslatef(10, 9.8, 120.2);
    glRotatef(22, 1, 0, 0);
    glScalef(100, 0.5, 0.5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //angled boards down#
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,15);
    glTranslatef(10, 6.2, 128.94);
    glRotatef(22, 1, 0, 0);
    glScalef(100, 0.5, 0.5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //angled boards down#
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,15);
    glTranslatef(10, 8, 124.57);
    glRotatef(22, 1, 0, 0);
    glScalef(100, 0.5, 0.5);
    drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();






    for(int i=10;i<=110;i+=10){
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,15);
        glTranslatef(i, 9.8, 120.2);
        glRotatef(22, 1, 0, 0);
        glScalef(0.5, 0.5, 10);
        drawCube(0.8, 0.9, 0.9,0.6, 0.6, 0.4);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    float red[] = {0.99, 0.97, 0.68, 0.26, 0.94};
    float green[] = {0.4, 0.06, 1, 0.74, 0.09};
    float blue[] = {0, 0.01,0, 0, 0, 0.01};

    int rgb_ind=0;
    for(double i=1; i<100; i+=10){
        glPushMatrix();
        glTranslatef(i, 0, 0);
        glScalef(0.93, 1, 1);
        fruits(red[rgb_ind], green[rgb_ind], blue[rgb_ind]);
        rgb_ind+=1;
        rgb_ind%=sizeof(red) / sizeof(red[0]);
        glPopMatrix();

        int sec_row = (rgb_ind+1)%(sizeof(red) / sizeof(red[0]));
        glPushMatrix();
        glTranslatef(i, -1.8, 4.5);
        glScalef(0.93, 1, 1);
        fruits(red[sec_row], green[sec_row], blue[sec_row]);
        glPopMatrix();
    }

}
