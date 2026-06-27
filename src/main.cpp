#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
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

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("SuperShop");

    LoadTexture("bmp/ceil.bmp");           // 1
    LoadTexture("bmp/wall.bmp");           // 2
    LoadTexture("bmp/floor.bmp");          // 3
    LoadTexture("bmp/swapno.bmp");         // 4
    LoadTexture("bmp/grass.bmp");          // 5
    LoadTexture("bmp/window.bmp");         // 6 mirror
    LoadTexture("bmp/redstripe.bmp");      // 7 shelf stripe
    LoadTexture("bmp/sale.bmp");           // 8
    LoadTexture("bmp/road.bmp");           // 9
    LoadTexture("bmp/brick.bmp");          // 10
    LoadTexture("bmp/fence.bmp");          // 11
    LoadTexture("bmp/fuelpumplower.bmp");  // 12
    LoadTexture("bmp/fuelpumpupper.bmp");  // 13
    LoadTexture("bmp/black.bmp");          // 14
    LoadTexture("bmp/wood.bmp");           // 15
    LoadTexture("bmp/noodles.bmp");        // 16
    LoadTexture("bmp/kitten.bmp");         // 17
    LoadTexture("bmp/chef.bmp");           // 18
    LoadTexture("bmp/oat.bmp");            // 19
    LoadTexture("bmp/chilli.bmp");         // 20
    LoadTexture("bmp/choco1.bmp");         // 21
    LoadTexture("bmp/choco2.bmp");         // 22
    LoadTexture("bmp/ac.bmp");             // 23
    LoadTexture("bmp/signs.bmp");          // 24
    LoadTexture("bmp/ice_cream.bmp");      // 25
    LoadTexture("bmp/freezer_inside.bmp"); // 26
    LoadTexture("bmp/frozen_food.bmp");    // 27
    LoadTexture("bmp/cola.bmp");           // 28
    LoadTexture("bmp/sky.bmp");            // 29 day
    LoadTexture("bmp/nightsky.bmp");       // 30 night

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    light0();
    light1();
    light2();

    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(animate);

    glutMainLoop();
    return 0;
}
