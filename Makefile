CC= g++
CFLAGS= -c -g -Wall -I include/ -I usr/ -Ofast -march=native
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
	@-rm $(OBJECTS)

.cpp.o:
	@$(CC) $(CFLAGS) $< -o $@
	@echo "CC $<"
	

clean:
	@-rm -rf $(OBJECTS) $(OUTPUT)
