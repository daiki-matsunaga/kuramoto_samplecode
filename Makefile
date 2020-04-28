CC = g++
RM = /bin/rm
LIB = -lm -Wall
TARGET = run

VPATH = include src
INCLUDE = basic.hpp
SOURCE = main.cpp
OBJ += Particle.o output.o calc.o main.o
OBJD := ${addprefix obj/, ${OBJ}}
override CFLAGS += -O3 -I include

${TARGET} : ${OBJ} ${INCLUDE}
		${CC} -o $@ ${OBJD} ${LIB}

%.o : %.cpp
	${CC} -c ${LIB} ${CFLAGS} $< -o ./obj/$@

clean: main.cpp
	$(RM) -f $(TARGET) ./obj/*.o
	find ./result -maxdepth 5 -name "result*.dat" -exec $(RM) {} \;
