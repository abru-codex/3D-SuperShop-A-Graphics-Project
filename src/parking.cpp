#include "parking.h"
#include "gl_compat.h"
#include "geometry.h"
#include "model.h"

static void block(float x, float y, float z,
                  float sx, float sy, float sz,
                  float r, float g, float b,
                  float shine = 30.0f)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sx, sy, sz);
    drawCube(r, g, b, r * 0.25f, g * 0.25f, b * 0.25f, shine);
    glPopMatrix();
}

static void cubeCar(float r, float g, float b)
{
    // body
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    glScalef(6.0f, 1.0f, 2.5f);
    drawCube(r, g, b, r * 0.4f, g * 0.4f, b * 0.4f);
    glPopMatrix();

    // cabin / roof
    glPushMatrix();
    glTranslatef(1.2f, 1.55f, 0.2f);
    glScalef(3.2f, 0.85f, 2.1f);
    drawCube(r * 0.85f, g * 0.85f, b * 0.85f,
             r * 0.3f,  g * 0.3f,  b * 0.3f);
    glPopMatrix();

    // windshield
    glPushMatrix();
    glTranslatef(1.15f, 1.6f, 0.25f);
    glScalef(0.15f, 0.7f, 2.0f);
    drawCube(0.05f, 0.08f, 0.12f, 0.02f, 0.02f, 0.05f);
    glPopMatrix();

    // 4 wheels
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

// Unit car: ~6 long (X) x 2 tall (Y) x 2.5 wide (Z), sits on y=0
void car(float r, float g, float b)
{
    static ObjModel* sedan =
        loadObjModel("assets/models/sketchfab-simple-car/simple-car.obj");

    if (!sedan) {
        sedan = loadObjModel("assets/models/kenney-car/sedan.obj");
    }

    if (!sedan) {
        cubeCar(r, g, b);
        return;
    }

    glPushMatrix();
    glTranslatef(3.05f, 0.0f, 1.25f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(1.55f, 1.0f, 2.35f);
    drawObjModel(*sedan, r, g, b);
    glPopMatrix();
}

// Parking lot anchored at caller's origin: asphalt slab + driveway, lane
// stripes, and 4 parked cars of varied colors.
void parking_lot()
{
    // asphalt slab (dark gray) — 60 x 0.1 x 25, top at y=0.1
    glPushMatrix();
    glScalef(60.0f, 0.1f, 25.0f);
    drawCube(0.16f, 0.16f, 0.18f, 0.04f, 0.04f, 0.05f);
    glPopMatrix();

    // subtle asphalt patches
    block(3.0f, 0.105f, 2.5f, 18.0f, 0.025f, 5.0f, 0.11f, 0.11f, 0.12f, 8.0f);
    block(29.0f, 0.106f, 18.5f, 22.0f, 0.025f, 3.0f, 0.12f, 0.12f, 0.13f, 8.0f);
    block(47.0f, 0.107f, 8.5f, 10.0f, 0.025f, 7.0f, 0.10f, 0.10f, 0.11f, 8.0f);

    // driveway to the front road
    glPushMatrix();
    glTranslatef(42.0f, 0.0f, 25.0f);
    glScalef(12.0f, 0.1f, 20.0f);
    drawCube(0.16f, 0.16f, 0.18f, 0.04f, 0.04f, 0.05f);
    glPopMatrix();

    // concrete curbs around lot edges
    block(0.0f, 0.12f, -0.6f, 60.0f, 0.35f, 0.45f, 0.62f, 0.62f, 0.58f, 20.0f);
    block(-0.6f, 0.12f, 0.0f, 0.45f, 0.35f, 25.0f, 0.62f, 0.62f, 0.58f, 20.0f);
    block(60.0f, 0.12f, 0.0f, 0.45f, 0.35f, 25.0f, 0.62f, 0.62f, 0.58f, 20.0f);

    // 5 white lane stripes dividing 4 bays
    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glTranslatef(4.0f + i * 12.0f, 0.11f, 4.0f);
        glScalef(0.25f, 0.04f, 17.0f);
        drawCube(0.95f, 0.95f, 0.95f, 0.5f, 0.5f, 0.5f);
        glPopMatrix();
    }

    // wheel stops and tire marks
    for (int i = 0; i < 4; i++) {
        float x = 5.3f + i * 12.0f;
        block(x, 0.18f, 18.0f, 7.0f, 0.28f, 0.45f, 0.78f, 0.78f, 0.72f, 25.0f);
        block(x + 0.8f, 0.13f, 9.0f, 0.22f, 0.03f, 5.2f, 0.035f, 0.035f, 0.038f, 5.0f);
        block(x + 3.5f, 0.13f, 9.0f, 0.22f, 0.03f, 5.2f, 0.035f, 0.035f, 0.038f, 5.0f);
    }

    // driveway center marking and small entry arrows
    block(47.85f, 0.13f, 27.0f, 0.35f, 0.035f, 5.0f, 0.92f, 0.82f, 0.12f, 25.0f);
    block(47.85f, 0.13f, 36.0f, 0.35f, 0.035f, 5.0f, 0.92f, 0.82f, 0.12f, 25.0f);
    block(46.5f, 0.13f, 43.0f, 1.4f, 0.035f, 0.35f, 0.92f, 0.82f, 0.12f, 25.0f);
    block(49.1f, 0.13f, 43.0f, 1.4f, 0.035f, 0.35f, 0.92f, 0.82f, 0.12f, 25.0f);

    // random thin surface cracks
    block(12.0f, 0.14f, 20.5f, 8.0f, 0.025f, 0.12f, 0.025f, 0.025f, 0.028f, 5.0f);
    block(37.0f, 0.14f, 2.0f, 10.0f, 0.025f, 0.12f, 0.025f, 0.025f, 0.028f, 5.0f);
    block(53.0f, 0.14f, 16.0f, 0.12f, 0.025f, 5.5f, 0.025f, 0.025f, 0.028f, 5.0f);

    // parked cars — one per bay, varied colors, all facing -Z
    float colors[4][3] = {
        { 0.80f, 0.10f, 0.10f },  // red
        { 0.10f, 0.30f, 0.80f },  // blue
        { 0.90f, 0.80f, 0.15f },  // yellow
        { 0.10f, 0.65f, 0.20f }   // green
    };
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(5.1f + i * 12.0f, 0.1f, 5.1f);
        glScalef(1.28f, 1.28f, 1.28f);
        car(colors[i][0], colors[i][1], colors[i][2]);
        glPopMatrix();
    }
}
