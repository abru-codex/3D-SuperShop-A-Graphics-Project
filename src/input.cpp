#include "input.h"
#include "gl_compat.h"
#include <cstdlib>
#include <cmath>
#include "camera.h"
#include "animation.h"
#include "textures.h"
#include "lighting.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static const double WALK_STEP  = 2.0;
static const double YAW_STEP   = 3.0 * M_PI / 180.0;
static const double PITCH_STEP = 2.0 * M_PI / 180.0;
static const double PITCH_MAX  = 85.0 * M_PI / 180.0;

static void getForward(double& fx, double& fy, double& fz)
{
    fx = refX - eyeX;
    fy = refY - eyeY;
    fz = refZ - eyeZ;
    double l = std::sqrt(fx*fx + fy*fy + fz*fz);
    if (l > 1e-6) { fx /= l; fy /= l; fz /= l; }
    else          { fx = 0;  fy = 0;  fz = -1; }
}

static void walk(double dx, double dy, double dz, double step)
{
    eyeX += dx * step; refX += dx * step;
    eyeY += dy * step; refY += dy * step;
    eyeZ += dz * step; refZ += dz * step;
}

static void setForward(double fx, double fy, double fz)
{
    refX = eyeX + fx;
    refY = eyeY + fy;
    refZ = eyeZ + fz;
}

static void rotateYaw(double angle)
{
    double fx, fy, fz; getForward(fx, fy, fz);
    double pitch = std::asin(fy);
    double yaw   = std::atan2(fx, fz);
    yaw += angle;
    double cp = std::cos(pitch);
    setForward(cp * std::sin(yaw), std::sin(pitch), cp * std::cos(yaw));
}

static void rotatePitch(double angle)
{
    double fx, fy, fz; getForward(fx, fy, fz);
    double pitch = std::asin(fy) + angle;
    if (pitch >  PITCH_MAX) pitch =  PITCH_MAX;
    if (pitch < -PITCH_MAX) pitch = -PITCH_MAX;
    double yaw = std::atan2(fx, fz);
    double cp  = std::cos(pitch);
    setForward(cp * std::sin(yaw), std::sin(pitch), cp * std::cos(yaw));
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
    double fx, fy, fz; getForward(fx, fy, fz);
    // right = forward × (0,1,0) = (-fz, 0, fx)
    double rx = -fz, ry = 0, rz = fx;
    double rl = std::sqrt(rx*rx + rz*rz);
    if (rl > 1e-6) { rx /= rl; rz /= rl; }

    switch (key) {
    case 'w': walk(fx, fy, fz,  WALK_STEP); break;
    case 's': walk(fx, fy, fz, -WALK_STEP); break;
    case 'a': walk(rx, ry, rz, -WALK_STEP); break;
    case 'd': walk(rx, ry, rz,  WALK_STEP); break;
    case 'r': walk(0,  1,  0,   WALK_STEP); break;
    case 'f': walk(0,  1,  0,  -WALK_STEP); break;

    case 'y':
        if (doorClose) { doorClose = false; doorOpen  = true;  }
        else if (doorOpen) { doorClose = true; doorOpen = false; }
        break;
    case '=':
        elevator_door = (elevator_door == 0) ? 22.5 : 0;
        break;
    case '-':
        if (liftDown) { liftUp = true; liftDown = false; }
        else if (liftUp) { liftDown = true; liftUp = false; }
        break;

    case '0': eyeX = 65;  eyeY = 50; eyeZ = 90;  refX = -10; refY = 30; refZ = 0; break;
    case '1': eyeX = 17;  eyeY = 20; eyeZ = 90;  refX = 110; refY = 30; refZ = 0; break;
    case '4': eyeX = 40;  eyeY = 10; eyeZ = 150; refX = 55;  refY = 10; refZ = 0; break;
    case '5': eyeX = 40;  eyeY = 20; eyeZ = 40;  refX = -40; refY = 30; refZ = 0; break;
    case '6': eyeX = -20; eyeY = 20; eyeZ = 60;  refX = 40;  refY = 20; refZ = 0; break;
    case '7': eyeX = 40;  eyeY = 40; eyeZ = 40;  refX = 0;   refY = 30; refZ = 0; break;

    case '9':
        night_mode = !night_mode;
        sky_texture = night_mode ? 30 : 29;
        // glLight*(GL_POSITION) bakes current MODELVIEW into the position.
        // Reset to identity so re-applied lights land in world space.
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        light0();
        light2();
        glPopMatrix();
        break;

    case 27: exit(0);
    }
    glutPostRedisplay();
}

void mySpecialFunc(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_LEFT:  rotateYaw(-YAW_STEP); break;
    case GLUT_KEY_RIGHT: rotateYaw( YAW_STEP); break;
    case GLUT_KEY_UP:    rotatePitch( PITCH_STEP); break;
    case GLUT_KEY_DOWN:  rotatePitch(-PITCH_STEP); break;
    }
    glutPostRedisplay();
}
