fractal Play
===========

## Welcome
   This is a graphics program that uses a binary tree traversal algorithm to
draw fractals. 

   If you have any questions or comments, you can contact me at seewalker.120@gmail.com.
## Dependencies
Tools necessary for compilation with the Makefile:
   The g++ compiler.
   The GL and glut libraries.
   The X window system. 
It is possible that you may do it otherwise, but this is how I've tested it.

## Usage
   Simply type 'make' into a shell to produce the executable. Running that 
executable makes for the window which the following suggestions apply to.
   When you click anywhere on the screen, the fractal re-renders to match the 
color under your cursor. The most interesting area to click, is then the pallate
around the border. The buttons on the left are in four groups: the bottom of
which will adjust the changes in angle so that a hexagon-like image is made, the
next up makes it pentagon-like, the next up makes it grid-like, and the top 
doesn't really have a word for it. Within those groups, the bottom buttom
lowers the depth of the fractal. By continually lowering the depth, you can
see how the drawing algorithm works. The top button in every group increases
the depth of the fractal; the middle button leaves the depth unchanged. 
   The slider on the right will rotate the fractal. 

## Hacking
   Some low-hanging fruit is changing the shape of the fractal by using a 
different angle in the definition. You can do this by changing the sixth 
argument to the tree constructor (named delta_angle in tree.h). delta_angle 
refers to the change in angle from iteration-to-iteration in the drawing of the
tree. If you would like to see how your new fractal builds up from depth 0, you
may even redefine the function of the buttons on the lefthand side of the 
screen. You can do this by modifying the interpretClick function.
