COMPILER = g++
CFLAGS = -lGLU -lGL -lglut
DEFINITIONS = tree.h constants.h squareButton.h

fractalPlay: $(DEFINITIONS) fractalPlay.cpp
	$(COMPILER) $(CFLAGS) fractalPlay.cpp -o fractalPlay -std=c++98

profile: $(DEFINITION) fractalPlay.cpp
	$(COMPILER) $(CFLAGS) fractalPlay.cpp -o fracking -g -pg
