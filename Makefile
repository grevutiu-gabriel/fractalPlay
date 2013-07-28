COMPILER = g++
CFLAGS = -lglut -lGLU 
DEFINITIONS = tree.h constants.h squareButton.h

fractalPlay: $(DEFINITIONS) fractalPlay.cpp
	$(COMPILER) $(CFLAGS) fractalPlay.cpp -o fractalPlay

profile: $(DEFINITION) fractalPlay.cpp
	$(COMPILER) $(CFLAGS) fractalPlay.cpp -o fracking -g -pg
