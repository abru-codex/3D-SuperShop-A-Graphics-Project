#include "people.h"
#include "gl_compat.h"
#include "geometry.h"

static void setMaterial(float r, float g, float b, float shine = 35.0f)
{
    GLfloat noMat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat ambient[] = { r * 0.22f, g * 0.22f, b * 0.22f, 1.0f };
    GLfloat diffuse[] = { r, g, b, 1.0f };
    GLfloat specular[] = { 0.35f, 0.35f, 0.35f, 1.0f };
    GLfloat shininess[] = { shine };

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, noMat);
}

static void cubePart(float x, float y, float z,
                     float sx, float sy, float sz,
                     float r, float g, float b,
                     float shine = 35.0f)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sx, sy, sz);
    drawCube(r, g, b, r * 0.25f, g * 0.25f, b * 0.25f, shine);
    glPopMatrix();
}

static void spherePart(float x, float y, float z,
                       float sx, float sy, float sz,
                       float r, float g, float b,
                       float shine = 35.0f)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sx, sy, sz);
    drawSphere(r, g, b, r * 0.25f, g * 0.25f, b * 0.25f, shine, 24, 24);
    glPopMatrix();
}

static void verticalCylinder(float x, float y, float z,
                             float radius, float height,
                             float r, float g, float b,
                             int slices = 24)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(-90.0f, 1, 0, 0);
    setMaterial(r, g, b);
    drawCylinder(radius, height, slices);
    glPopMatrix();
}

static void conePart(float x, float y, float z,
                     float radius, float height,
                     float r, float g, float b)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(-90.0f, 1, 0, 0);
    setMaterial(r, g, b, 30.0f);
    glutSolidCone(radius, height, 28, 8);
    glPopMatrix();
}

static void headAndHair(bool female)
{
    spherePart(0.0f, 5.65f, 0.0f, 0.58f, 0.68f, 0.58f, 0.82f, 0.60f, 0.42f, 35.0f);
    spherePart(0.0f, 6.03f, -0.05f, 0.62f, 0.24f, 0.62f, 0.08f, 0.045f, 0.03f, 18.0f);

    if (female) {
        spherePart(-0.52f, 5.65f, -0.04f, 0.2f, 0.55f, 0.2f, 0.08f, 0.045f, 0.03f, 18.0f);
        spherePart( 0.52f, 5.65f, -0.04f, 0.2f, 0.55f, 0.2f, 0.08f, 0.045f, 0.03f, 18.0f);
    }

    // simple face direction marker
    spherePart(-0.18f, 5.72f, -0.52f, 0.055f, 0.055f, 0.055f, 0.02f, 0.02f, 0.02f, 10.0f);
    spherePart( 0.18f, 5.72f, -0.52f, 0.055f, 0.055f, 0.055f, 0.02f, 0.02f, 0.02f, 10.0f);
}

static void arms(float skinR, float skinG, float skinB, bool reaching)
{
    if (reaching) {
        cubePart(-0.95f, 4.0f, -0.08f, 0.28f, 1.25f, 0.26f, skinR, skinG, skinB);
        cubePart( 0.78f, 4.38f, -0.45f, 1.18f, 0.24f, 0.24f, skinR, skinG, skinB);
        spherePart(1.95f, 4.48f, -0.48f, 0.18f, 0.18f, 0.18f, skinR, skinG, skinB);
    } else {
        cubePart(-0.94f, 2.82f, -0.04f, 0.26f, 1.36f, 0.24f, skinR, skinG, skinB);
        cubePart( 0.68f, 2.82f, -0.04f, 0.26f, 1.36f, 0.24f, skinR, skinG, skinB);
    }
}

static void shoppingBasket()
{
    cubePart(1.05f, 2.05f, -0.72f, 0.92f, 0.42f, 0.62f, 0.82f, 0.14f, 0.08f, 25.0f);
    cubePart(1.14f, 2.45f, -0.58f, 0.74f, 0.08f, 0.08f, 0.08f, 0.08f, 0.08f, 18.0f);
}

static void shoppingCart()
{
    cubePart(-1.9f, 1.05f, -1.1f, 2.3f, 0.1f, 1.2f, 0.72f, 0.72f, 0.7f, 45.0f);
    cubePart(-1.9f, 1.75f, -1.1f, 2.3f, 0.1f, 1.2f, 0.72f, 0.72f, 0.7f, 45.0f);
    cubePart(-1.9f, 1.05f, -1.1f, 0.1f, 0.75f, 1.2f, 0.72f, 0.72f, 0.7f, 45.0f);
    cubePart( 0.3f, 1.05f, -1.1f, 0.1f, 0.75f, 1.2f, 0.72f, 0.72f, 0.7f, 45.0f);
    cubePart(-2.15f, 1.9f, -0.48f, 0.18f, 0.1f, 1.4f, 0.1f, 0.1f, 0.11f, 30.0f);

    spherePart(-1.55f, 0.52f, -1.02f, 0.2f, 0.2f, 0.1f, 0.025f, 0.025f, 0.028f, 18.0f);
    spherePart(-1.55f, 0.52f, -0.12f, 0.2f, 0.2f, 0.1f, 0.025f, 0.025f, 0.028f, 18.0f);
    spherePart( 0.05f, 0.52f, -1.02f, 0.2f, 0.2f, 0.1f, 0.025f, 0.025f, 0.028f, 18.0f);
    spherePart( 0.05f, 0.52f, -0.12f, 0.2f, 0.2f, 0.1f, 0.025f, 0.025f, 0.028f, 18.0f);
}

static void male(float shirtR, float shirtG, float shirtB,
                 float pantsR, float pantsG, float pantsB,
                 bool reaching, bool basket, bool cart)
{
    const float skinR = 0.78f;
    const float skinG = 0.55f;
    const float skinB = 0.38f;

    verticalCylinder(-0.32f, 0.25f, 0.0f, 0.16f, 2.75f, pantsR, pantsG, pantsB);
    verticalCylinder( 0.32f, 0.25f, 0.0f, 0.16f, 2.75f, pantsR, pantsG, pantsB);
    cubePart(-0.56f, 0.0f, -0.25f, 0.48f, 0.18f, 0.6f, 0.035f, 0.035f, 0.04f);
    cubePart( 0.08f, 0.0f, -0.25f, 0.48f, 0.18f, 0.6f, 0.035f, 0.035f, 0.04f);
    verticalCylinder(0.0f, 2.85f, 0.0f, 0.58f, 1.65f, shirtR, shirtG, shirtB);
    spherePart(0.0f, 4.1f, 0.0f, 0.66f, 0.92f, 0.48f, shirtR, shirtG, shirtB, 45.0f);
    arms(skinR, skinG, skinB, reaching);
    headAndHair(false);

    if (basket) shoppingBasket();
    if (cart) shoppingCart();
}

static void female(float dressR, float dressG, float dressB,
                   float pantsR, float pantsG, float pantsB,
                   bool reaching, bool basket, bool cart)
{
    const float skinR = 0.80f;
    const float skinG = 0.58f;
    const float skinB = 0.42f;

    verticalCylinder(-0.28f, 0.2f, 0.0f, 0.13f, 2.35f, pantsR, pantsG, pantsB);
    verticalCylinder( 0.28f, 0.2f, 0.0f, 0.13f, 2.35f, pantsR, pantsG, pantsB);
    cubePart(-0.48f, 0.0f, -0.22f, 0.42f, 0.16f, 0.55f, 0.035f, 0.035f, 0.04f);
    cubePart( 0.06f, 0.0f, -0.22f, 0.42f, 0.16f, 0.55f, 0.035f, 0.035f, 0.04f);
    conePart(0.0f, 2.35f, 0.0f, 0.92f, 1.85f, dressR, dressG, dressB);
    spherePart(0.0f, 4.15f, 0.0f, 0.58f, 0.78f, 0.45f, dressR, dressG, dressB, 45.0f);
    arms(skinR, skinG, skinB, reaching);
    headAndHair(true);

    if (basket) shoppingBasket();
    if (cart) shoppingCart();
}

static void shopperAt(float x, float z, float angle, bool isFemale,
                      float topR, float topG, float topB,
                      float pantsR, float pantsG, float pantsB,
                      bool reaching, bool basket, bool cart)
{
    glPushMatrix();
    glTranslatef(x, 0.25f, z);
    glRotatef(angle, 0, 1, 0);
    glScalef(1.25f, 1.25f, 1.25f);

    if (isFemale) {
        female(topR, topG, topB, pantsR, pantsG, pantsB, reaching, basket, cart);
    } else {
        male(topR, topG, topB, pantsR, pantsG, pantsB, reaching, basket, cart);
    }

    glPopMatrix();
}

void shoppers()
{
    // First floor visible interior after the building's local 0.5 scale:
    // keep shoppers inside x=0..100, z=0..100.
    shopperAt(24.0f, 22.0f,  20.0f, false, 0.15f, 0.38f, 0.80f, 0.06f, 0.07f, 0.10f, true,  false, true);
    shopperAt(46.0f, 35.0f, -65.0f, true,  0.82f, 0.18f, 0.28f, 0.10f, 0.10f, 0.12f, true,  true,  false);
    shopperAt(72.0f, 22.0f, 145.0f, false, 0.10f, 0.56f, 0.30f, 0.08f, 0.12f, 0.22f, false, true,  false);
    shopperAt(32.0f, 72.0f, -110.0f, true,  0.58f, 0.22f, 0.68f, 0.12f, 0.08f, 0.06f, false, false, true);
    shopperAt(78.0f, 72.0f,  90.0f, false, 0.72f, 0.52f, 0.14f, 0.06f, 0.08f, 0.16f, true,  false, false);
}

void billCounterPeople()
{
    // Cash counter sits around x=124..133 and z=75..90 after its scene transform.
    shopperAt(129.0f, 78.0f, 0.0f, false,
              0.05f, 0.26f, 0.55f, 0.04f, 0.05f, 0.08f,
              true, false, false);

    shopperAt(126.0f, 93.5f, 180.0f, true,
              0.75f, 0.20f, 0.30f, 0.08f, 0.08f, 0.10f,
              true, true, false);

    // Payment card and small cash note on top of the counter.
    cubePart(126.6f, 7.8f, 88.9f, 1.2f, 0.06f, 0.55f, 0.02f, 0.10f, 0.55f, 20.0f);
    cubePart(128.0f, 7.9f, 88.7f, 0.9f, 0.05f, 0.45f, 0.1f, 0.75f, 0.22f, 20.0f);
}
