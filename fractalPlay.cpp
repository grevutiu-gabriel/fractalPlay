#include "tree.h"
#include "template.h"
#include "constants.h"
#include "squareButton.h"
#include <unistd.h>

double rotational_button_bottom = window_h / 2.0;

tree t1(window_w / 2.0, window_h / 2.0, 110, 0.70, 0.5 * pi, pi / 8.0, 20, 16);
tree t2(window_w / 2.0, window_h / 2.0, 110, 0.70, 1.5 * pi, pi / 3.0, 20, 16);
squareButton hexButton0(left_end_l, hex_button_bottom, button_w, button_h);
squareButton hexButton1(left_end_l, hex_button_bottom + button_h, button_w, button_h);
squareButton hexButton2(left_end_l, hex_button_bottom + 2 * button_h, button_w, button_h);
squareButton pentButton0(left_end_l, pent_button_bottom, button_w, button_h);
squareButton pentButton1(left_end_l, pent_button_bottom + button_h, button_w, button_h);
squareButton pentButton2(left_end_l, pent_button_bottom + 2 * button_h, button_w, button_h);
squareButton sqreButton0(left_end_l,square_button_bottom, button_w, button_h);
squareButton sqreButton1(left_end_l,square_button_bottom + button_h, button_w, button_h);
squareButton sqreButton2(left_end_l,square_button_bottom + 2 * button_h, button_w, button_h);
squareButton crzyButton0(left_end_l, crazy_button_bottom, button_w, button_h);
squareButton crzyButton1(left_end_l, crazy_button_bottom + button_h, button_w, button_h);
squareButton crzyButton2(left_end_l, crazy_button_bottom + 2 * button_h, button_w, button_h);
squareButton rotationalButton(right_end_l, rotational_button_bottom, button_w, button_h);

void draw_palatte();
void draw_notch();
void display();
void change_rotation();
void processMouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(window_w, window_h);
  glutInitWindowPosition(0,0);
  glutCreateWindow(argv[0]);

  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(processMouse);
  glutMainLoop();
}

void draw_palatte()
{
  double i, j;
  for (j = 0; j < palate_size; ++j) 
    {
      for (i = 0; (i + palate_size) < window_w / 2.0; ++i)
	{
	  //bottom left block
	  glColor3f(1.0 - (2.5 * i / window_w), 0.0 + (j/palate_size), 1.0);
	  glBegin(GL_POINTS);
	  glVertex2f(i + palate_size,j);
	  glEnd();
	  //top left block
	  glColor3f(1.0, 1.0 - (2.5 * i / window_w),(j / palate_size));
	  glBegin(GL_POINTS);
	  glVertex2f(i + palate_size, window_h - j);
	  glEnd();
	  //bottom right block
	  glColor3f((2.5 * i / window_w), 1.0 - (j/palate_size), 0.0);
	  glBegin(GL_POINTS);
	  glVertex2f(i + window_w / 2.0, j);
	  glEnd();
	  //top right 
	  glColor3f(0.0,(2.5 * i / window_w), 1.0 - (j / palate_size));
	  glBegin(GL_POINTS);
	  glVertex2f(i + window_w / 2.0, window_h - j);
	  glEnd();
	}
    }
  for (j = 0; j < window_h; ++j)
    {
      for (i = 0; i < palate_size; ++i)
	{
	  //left side
	  glColor3f((i / palate_size), 0.0, 1.0 - (j / window_h));
	  glBegin(GL_POINTS);
	  glVertex2f(i,j);
	  glEnd();
	  //right side
	  glColor3f(1.0 - (i / palate_size), 1.0, (j / window_h));
	  glBegin(GL_POINTS);
	  glVertex2f(window_w - i, j);
	  glEnd();
	}
    }

}

void draw_buttons()
{
  //draws borders of buttonZone
  glPushAttrib(GL_CURRENT_BIT);
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINES);
  glVertex2f(right_end_l, 0); glVertex2f(right_end_l,window_h);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(right_end_r,0); glVertex2f(right_end_r,window_h);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(left_end_l, 0); glVertex2f(left_end_l,window_h);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(left_end_r,0); glVertex2f(left_end_r,window_h);
  glEnd();
  glPopAttrib();
  glFlush();
  //the buttons themselves
  hexButton0.draw(); pentButton0.draw(); sqreButton0.draw(); crzyButton0.draw(); rotationalButton.draw();
  hexButton1.draw(); pentButton1.draw(); sqreButton1.draw(); crzyButton1.draw();
  hexButton2.draw(); pentButton2.draw(); sqreButton2.draw(); crzyButton2.draw();
}

void change_rotation()
{
  double h = (rotational_button_bottom - window_h / 2.0);
  double adjust = h * (pi / (window_h / 2.0));
  t1.set_origin_angle(t1.get_origin_angle() + adjust);
  t2.set_origin_angle(t2.get_origin_angle() + adjust);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  t1.draw(t1.get_origin_angle(),t1.get_origin_horiz(),t1.get_origin_vert(), 0);
  t2.draw(t2.get_origin_angle(),t2.get_origin_horiz(),t2.get_origin_vert(), 0);
  draw_palatte(); 
  draw_buttons();  
  glFlush();
  change_rotation();
}

void interpretClick(int x, int y)
{
if (x >= right_end_l && x <= right_end_r)
	{
	  rotational_button_bottom = y;
	}
 else if (x >= left_end_l && x <= left_end_r)
   {
     if (hexButton0.inRange(x,y) )
       {
	 t1.set_delta_angle(pi / 3.0);
	 t1.set_origin_length(110);
	 t2.set_delta_angle(pi / 3.0);
	 t2.set_origin_length(110);
	 t1.set_max_depth(t1.get_max_depth() - 1);
       }
     else if (hexButton1.inRange(x,y) )
       {
	 t1.set_delta_angle(pi / 3.0);
	 t1.set_origin_length(110);
	 t2.set_delta_angle(pi / 3.0);
	 t2.set_origin_length(110);
       }
     else if (hexButton2.inRange(x,y) )
       {
	 t1.set_delta_angle(pi / 3.0);
	 t1.set_origin_length(110);
	 t2.set_delta_angle(pi / 3.0);
	 t2.set_origin_length(110);
	 t1.set_max_depth(t1.get_max_depth() + 1);
       }
     else if (pentButton0.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 2.5);
	 t1.set_origin_length(110);
	 t2.set_delta_angle(pi / 2.5);
	 t2.set_origin_length(110);
	 t1.set_max_depth(t1.get_max_depth() - 1);
       }
     else if (pentButton1.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 2.5);
	 t1.set_origin_length(110);
	 t2.set_delta_angle(pi / 2.5);
	 t2.set_origin_length(110);
       }
     else if (pentButton2.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 2.5);
	 t1.set_origin_length(110);
	 t2.set_delta_angle(pi / 2.5);
	 t2.set_origin_length(110);
	 t1.set_max_depth(t1.get_max_depth() + 1);
       }
     else if (sqreButton0.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 2.0);
	 t1.set_origin_length(140);
	 t2.set_delta_angle(pi / 2.0);
	 t2.set_origin_length(140);
	 t1.set_max_depth(t1.get_max_depth() - 1);
       }
     else if (sqreButton1.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 2.0);
	 t1.set_origin_length(140);
	 t2.set_delta_angle(pi / 2.0);
	 t2.set_origin_length(140);
       }
     else if (sqreButton2.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 2.0);
	 t1.set_origin_length(140);
	 t2.set_delta_angle(pi / 2.0);
	 t2.set_origin_length(140);
	 t1.set_max_depth(t1.get_max_depth() + 1);
       }
     else if (crzyButton0.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 1.2);
	 t1.set_origin_length(330);
	 t2.set_delta_angle(pi / 1.2);
	 t2.set_origin_length(330);
	 t1.set_max_depth(t1.get_max_depth() - 1);
       }
     else if (crzyButton1.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 1.2);
	 t1.set_origin_length(330);
	 t2.set_delta_angle(pi / 1.2);
	 t2.set_origin_length(330);
       }
     else if (crzyButton2.inRange(x,y))
       {
	 t1.set_delta_angle(pi / 1.2);
	 t1.set_origin_length(330);
	 t2.set_delta_angle(pi / 1.2);
	 t2.set_origin_length(330);
	 t1.set_max_depth(t1.get_max_depth() + 1);
       }
   }
 else 
   {
     struct { GLubyte red, green, blue; } pixel;
     glReadPixels(x,y,1,1,GL_RGB, GL_UNSIGNED_BYTE, &pixel);
     glColor3f(pixel.red / 256.0 , pixel.green / 256.0 , pixel.blue / 256.0);
   }
}
void processMouse(int button, int state, int x, int y)
{
  y = window_h - y;
  if (state == GLUT_DOWN)
    {
      interpretClick(x,y);
      display();
    }
}
