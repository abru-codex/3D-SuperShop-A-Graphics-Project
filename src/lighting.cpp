#include "lighting.h"
#include <GL/gl.h>

bool night_mode = false;

void light0()
{
    GLfloat day_ambient[]    = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat day_diffuse[]    = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat day_specular[]   = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat night_ambient[]  = { 0.05, 0.05, 0.10, 1.0 };
    GLfloat night_diffuse[]  = { 0.15, 0.15, 0.25, 1.0 };
    GLfloat night_specular[] = { 0.2,  0.2,  0.3,  1.0 };

    GLfloat *ambient  = night_mode ? night_ambient  : day_ambient;
    GLfloat *diffuse  = night_mode ? night_diffuse  : day_diffuse;
    GLfloat *specular = night_mode ? night_specular : day_specular;

    GLfloat light_position[] = { -5.0, 0.0, 0.0, 1.0 };

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}


void light1()
{
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 30.0, 50.0, 0.0, 1.0 };

    glEnable( GL_LIGHT1);

    glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv( GL_LIGHT1, GL_POSITION, light_position);
    GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 35.0);
}


void light2()
{
    GLfloat day_ambient[]    = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat day_diffuse[]    = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat day_specular[]   = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat night_ambient[]  = { 0.05, 0.05, 0.10, 1.0 };
    GLfloat night_diffuse[]  = { 0.15, 0.15, 0.25, 1.0 };
    GLfloat night_specular[] = { 0.2,  0.2,  0.3,  1.0 };

    GLfloat *ambient  = night_mode ? night_ambient  : day_ambient;
    GLfloat *diffuse  = night_mode ? night_diffuse  : day_diffuse;
    GLfloat *specular = night_mode ? night_specular : day_specular;

    GLfloat light_position[]  = { -10.0, 10.5, 0.0, 0.0 };
    GLfloat light_direction[] = { 0.0, -1.0, 0.0 };

    glLightfv(GL_LIGHT2, GL_AMBIENT,  ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_direction);

    glEnable(GL_LIGHT2);
}
