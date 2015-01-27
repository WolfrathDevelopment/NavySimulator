CC= g++
#CFLAGS= -c -g -Wall -I include/ -I usr/ -O2 -march=native
CFLAGS= -c -g -Wall -I include/ -I usr/
SOURCES= $(shell find * -type f -name '*.cpp')
OBJECTS= $(SOURCES:.cpp=.o)
OUTPUT= simulator

LIBS= -lglut -lfreeimage -lXmu -lXext -lGL -lXi -lGLU

# Are we compiling on a mac?

UNAME= $(shell uname)

ifeq ($(UNAME), "Darwin")
LIBS= -framework Cocoa -framework OpenGL -framework GLUT
endif


all: $(SOURCES) $(OUTPUT)
	@echo "Done."

$(OUTPUT): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $@ $(LIBS)
	@echo "LD $@"

.cpp.o:
	@$(CC) $(CFLAGS) $< -o $@
	@echo "CC $<"
	

clean:
	@-rm -rf $(OBJECTS) $(OUTPUT)

love:
	@echo "Not war?"
