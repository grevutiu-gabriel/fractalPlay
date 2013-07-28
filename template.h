void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,(GLdouble) w, 0.0, (GLdouble) h);
}

/* int main(int argc, char** argv) */
/* { */
/*   glutInit(&argc, argv); */
/*   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); */
/*   glutInitWindowSize(400,400); */
/*   glutInitWindowPosition(0,0); */
/*   glutCreateWindow(argv[0]); */

/*   init(); */
/*   glutDisplayFunc(display); */
/*   glutReshapeFunc(reshape); */
/*   glutMainLoop(); */
/* } */
