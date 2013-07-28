#ifndef SEEWALD_BUTTON
#define SEEWALD_BUTTON
#include <GL/gl.h>
#include <GL/glut.h>
class squareButton {
public:
  squareButton(double R, double G, double B, double X, double Y, double H, double W) { r = R; g = G; b = B; x = X; y = Y; h = H; w = W; }
  squareButton(double X, double Y, double H, double W) { r = 1.0; g = 1.0; b = 1.0; x = X; y = Y; h = H; w = W; }

  void setR(double newR) { r = newR; }
  void setG(double newG) { g = newG; }
  void setB(double newB) { b = newB; }
  void setW(double newH) { h = newH; }
  void setH(double newW) { w = newW; }
  void setX(double newX) { x = newX; }
  void setY(double newY) { y = newY; }

  double getR() { return r; }
  double getG() { return g; }
  double getB() { return b; }
  double getW() { return w; }
  double getH() { return h; }
  double getX() { return x; }
  double getY() { return y; }

bool inRange(double hitX, double hitY) { return (hitX > x && hitX < (x + w) && hitY > y && hitY < (y + h)); }

  void draw() {
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(getR(),getG(),getB());
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x, y + h);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glEnd();
    glPopAttrib();
    glFlush();
  }
 
private:
  double r;
  double g;
  double b;
  double h;
  double w;
  double x; //refers to x coordinate of the bottom left corner
  double y; //refers to y coordinate of the bottom left corner
};
#endif
