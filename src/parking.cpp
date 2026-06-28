#include "parking.h"
#include "gl_compat.h"
#include "geometry.h"

// Unit car: ~6 long (X) x 2 tall (Y) x 2.5 wide (Z), sits on y=0
void car(float r, float g, float b)
{
    // body
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    glScalef(6.0f, 1.0f, 2.5f);
    drawCube(r, g, b, r * 0.4f, g * 0.4f, b * 0.4f);
    glPopMatrix();

    // cabin / roof — set back from front bumper, narrower
    glPushMatrix();
    glTranslatef(1.2f, 1.55f, 0.2f);
    glScalef(3.2f, 0.85f, 2.1f);
    drawCube(r * 0.85f, g * 0.85f, b * 0.85f,
             r * 0.3f,  g * 0.3f,  b * 0.3f);
    glPopMatrix();

    // windshield — dark glass strip on front of cabin
    glPushMatrix();
    glTranslatef(1.15f, 1.6f, 0.25f);
    glScalef(0.15f, 0.7f, 2.0f);
    drawCube(0.05f, 0.08f, 0.12f, 0.02f, 0.02f, 0.05f);
    glPopMatrix();

    // 4 wheels (dark cuboids — keeps style with rest of scene)
    float wx[4] = { 0.6f, 4.6f, 0.6f, 4.6f };
    float wz[4] = { -0.25f, -0.25f, 2.5f, 2.5f };
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(wx[i], 0.05f, wz[i]);
        glScalef(0.9f, 0.5f, 0.25f);
        drawCube(0.05f, 0.05f, 0.05f, 0.02f, 0.02f, 0.02f);
        glPopMatrix();
    }
}

// Parking lot anchored at caller's origin: asphalt slab + lane stripes
// + 4 parked cars of varied colors. Extends roughly 60 along +X, 25 along +Z.
void parking_lot()
{
    // asphalt slab (dark gray) — 60 x 0.1 x 25, top at y=0.1
    glPushMatrix();
    glScalef(60.0f, 0.1f, 25.0f);
    drawCube(0.16f, 0.16f, 0.18f, 0.04f, 0.04f, 0.05f);
    glPopMatrix();

    // 5 white lane stripes dividing 4 bays
    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glTranslatef(4.0f + i * 12.0f, 0.11f, 4.0f);
        glScalef(0.25f, 0.04f, 17.0f);
        drawCube(0.95f, 0.95f, 0.95f, 0.5f, 0.5f, 0.5f);
        glPopMatrix();
    }

    // parked cars — one per bay, varied colors, all facing -Z
    float colors[4][3] = {
        { 0.80f, 0.10f, 0.10f },  // red
        { 0.10f, 0.30f, 0.80f },  // blue
        { 0.90f, 0.80f, 0.15f },  // yellow
        { 0.10f, 0.65f, 0.20f }   // green
    };
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(6.0f + i * 12.0f, 0.1f, 5.5f);
        car(colors[i][0], colors[i][1], colors[i][2]);
        glPopMatrix();
    }
}
