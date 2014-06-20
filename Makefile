#
# Makefile
# Dodson, Wolfrath 2014
#

CC= g++
CFLAGS= -O3
OUT= simulator
LIBS= -lglut -lfreeimage -lXmu -lXext -lGL -lXi -lGLU

all:
	$(CC) $(CFLAGS) main.cpp -o $(OUT) $(LIBS)

clean:
	rm $(OUT)
