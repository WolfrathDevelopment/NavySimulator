#
# Makefile
# Navy Simulator
# Dodson, Wolfrath 2014
#

CC= g++
CFLAGS= -O3 -I include/
OUT= simulator
LIBS= -lglut -lfreeimage -lXmu -lXext -lGL -lXi -lGLU

SOURCES= 	src/main.cpp \
			src/GLManager.cpp

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT) $(LIBS)

clean:
	rm $(OUT)
