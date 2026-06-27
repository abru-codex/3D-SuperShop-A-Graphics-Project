#include "environment.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include "geometry.h"
#include "animation.h"
#include "textures.h"

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
