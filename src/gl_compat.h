#ifndef GL_COMPAT_H
#define GL_COMPAT_H

#if defined(__APPLE__)
#  if __has_include(<GLUT/glut.h>)
#    include <OpenGL/gl.h>
#    include <OpenGL/glu.h>
#    include <GLUT/glut.h>
#  else
#    include <GL/gl.h>
#    include <GL/glu.h>
#    include <GL/freeglut.h>
#  endif
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

#endif
