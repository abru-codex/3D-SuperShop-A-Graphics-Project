#ifndef MODEL_H
#define MODEL_H

#include "gl_compat.h"
#include <string>

struct ObjModel;

ObjModel* loadObjModel(const std::string& filename);
void drawObjModel(const ObjModel& model,
                  GLfloat r, GLfloat g, GLfloat b,
                  GLfloat shine = 35.0f);

#endif
