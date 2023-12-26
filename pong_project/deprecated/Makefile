# g++ -std=c++17 main.cpp sound.cpp ball.cpp paddle.cpp game.cpp -I /opt/homebrew/opt/sdl2/include/SDL2 -I /opt/homebrew/opt/sdl2_ttf/include/SDL2 -I /opt/homebrew/opt/sdl2_mixer/include/SDL2 -F/Library/Frameworks -framework SDL2 -framework SDL2_ttf -framework SDL2_mixer
# working makefile for mac os silicon (This is deprecated, use the CMakeLists.txt in the root directory instead to build the project)
# determine the OS
UNAME_S := $(shell uname -s)
$(info OS: $(UNAME_S))

ifeq ($(UNAME_S),Darwin)
CC = g++ -std=c++17

OBJFILES = main.o sound.o ball.o paddle.o game.o

INCLUDES = -I /opt/homebrew/opt/sdl2/include/SDL2 -I /opt/homebrew/opt/sdl2_ttf/include/SDL2 -I /opt/homebrew/opt/sdl2_mixer/include/SDL2
# INCLUDES = -I /Library/Frameworks/SDL2_mixer.framework/Headers -I /Library/Frameworks/SDL2_ttf.framework/Headers -I /Library/Frameworks/SDL2.framework/Headers

LINCLUDES = -F/Library/Frameworks -framework SDL2 -framework SDL2_ttf -framework SDL2_mixer

all: pong

pong: $(OBJFILES)
	$(CC) $(OBJFILES) $(INCLUDES) $(LINCLUDES) -o pong
	
main.o: main.cpp
	$(CC) -c main.cpp $(INCLUDES)

sound.o: sound.cpp
	$(CC) -c sound.cpp $(INCLUDES)

ball.o: ball.cpp
	$(CC) -c ball.cpp $(INCLUDES)

paddle.o: paddle.cpp
	$(CC) -c paddle.cpp $(INCLUDES)

game.o: game.cpp
	$(CC) -c game.cpp $(INCLUDES)

clean:
	rm -f *.o pong
endif

ifeq ($(UNAME_S),Linux)
CC = g++ -std=c++17

OBJFILES = main.o sound.o ball.o paddle.o game.o

INCLUDES = -I /usr/include/SDL2 -I /usr/include/SDL2_ttf -I /usr/include/SDL2_mixer

LINCLUDES = -lSDL2 -lSDL2_ttf -lSDL2_mixer

all: pong

pong: $(OBJFILES)
	$(CC) $(OBJFILES) $(INCLUDES) $(LINCLUDES) -o pong

main.o: main.cpp
	$(CC) -c main.cpp $(INCLUDES)

sound.o: sound.cpp
	$(CC) -c sound.cpp $(INCLUDES)

ball.o: ball.cpp
	$(CC) -c ball.cpp $(INCLUDES)

paddle.o: paddle.cpp
	$(CC) -c paddle.cpp $(INCLUDES)

game.o: game.cpp
	$(CC) -c game.cpp $(INCLUDES)

clean:
	rm -f *.o pong

endif