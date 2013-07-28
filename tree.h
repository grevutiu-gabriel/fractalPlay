#ifndef SEEWALD_TREE
#define SEEWALD_TREE
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//The list of parameters in the tree's constructor is
// Initial Horizontal Position
// Initial Vertical Position
// Initial Line Length
// Ratio of Length Decrease from one iteration to the next
// Intial Angle
// Change in Angle from one iteration to the next
// Initial Width of the line
// Max depth
class tree {
  static const double pi = 3.14159;
  typedef double T;

public:
  tree(  T init_horiz, T init_vert,T init_length, T init_ratio_length, T init_angle,T init_delta_angle, T init_line_width, short init_max_depth) { 
    origin_horiz = init_horiz; origin_vert = init_vert; origin_length = init_length; ratio_length = init_ratio_length; origin_angle = init_angle; delta_angle = init_delta_angle; origin_line_width = init_line_width; max_depth = init_max_depth; }
  tree() { origin_horiz = 0; origin_vert = 0; origin_length = 0; ratio_length = 0; origin_angle = 0; delta_angle = 0; origin_line_width = 0; max_depth = 0; }

  T get_origin_horiz() const { return origin_horiz; }
  T get_origin_vert() const { return origin_vert; }
  T get_origin_length() const { return origin_length; }
  T get_ratio_length () const { return ratio_length; }
  T get_origin_angle () const { return origin_angle; }
  T get_delta_angle () const { return delta_angle;  }
  T get_origin_line_width() const { return origin_line_width; }
  T get_max_depth() const { return max_depth; }

  void set_origin_horiz(T new_origin_horiz) { origin_horiz = new_origin_horiz; }
  void set_origin_vert(T new_origin_vert)  { origin_vert = new_origin_vert; }
  void set_origin_length(T new_origin_length)  { origin_length = new_origin_length; }
  void set_ratio_length (T new_ratio_length)  { ratio_length = new_ratio_length; }
  void set_origin_angle (T new_origin_angle) { origin_angle = new_origin_angle; }
  void set_delta_angle (T new_delta_angle) { delta_angle = new_delta_angle;  }
  void set_origin_line_width(T new_line_width)  { origin_line_width = new_line_width; }
  void set_max_depth(short new_max_depth) { max_depth = new_max_depth; }

  void draw(double angle, double prev_endpt_x, double  prev_endpt_y, int depth) {
    if (depth < max_depth)
      {
	double new_length = origin_length * pow(ratio_length,depth);
	double new_endpt_x = prev_endpt_x + (cos(angle) * new_length);
	double new_endpt_y = prev_endpt_y + (sin(angle) * new_length);
	glBegin(GL_LINES);
	glVertex2f(prev_endpt_x, prev_endpt_y);
	glVertex2f(new_endpt_x, new_endpt_y);
	glEnd();
	draw(angle - delta_angle, new_endpt_x, new_endpt_y, ++depth);
	--depth;
	draw(angle + delta_angle, new_endpt_x, new_endpt_y, ++depth);
      }
}
 
private:
  T origin_horiz; 
  T origin_vert;
  T origin_length; 
  T ratio_length; 
  T origin_angle;
  T delta_angle; 
  T origin_line_width;
  T ratio_line_width; 
  short max_depth; 
};
#endif
