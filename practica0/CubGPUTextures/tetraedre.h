#ifndef TETRAEDRE_H
#define TETRAEDRE_H

#include <Common.h>
#include <QGLShaderProgram>
#include <QOpenGLTexture>

#include <stdio.h>


const int NumVertices = 12; //(4 faces)(1 triangles/face)(3 vertices/triangle)

typedef vec4  color4;
typedef vec4  point4;

class tetraedre
{
  public:



      tetraedre();
      tetraedre(int an, int al, int profu, GLfloat x0, GLfloat y0, GLfloat z0);
      ~tetraedre();
      void make();
      void toGPU(QGLShaderProgram *program);
      void draw();
      void aplicaTG(mat4 m);

  private:

      void tri( int a, int b, int c);
      void initTextura();

      int a; // amplada
      int h; // alcada
      int p; // profunditat
      GLdouble xorig, yorig, zorig;

      point4 vertices[4]; // 4 vertexs del tetraedre
      color4 vertex_colors[4]; // 4 colors RGBA associats a cada vertex

      int Index;
      point4 points[NumVertices]; // 12 punts: tetraedre triangulat
      color4 colors[NumVertices]; // colors en aquests punts
      vec2 vertexsTextura[NumVertices]; // coordenades de textura associades a cada vertex

      QOpenGLTexture *texture;
};

#endif // TETRAEDRE_H
