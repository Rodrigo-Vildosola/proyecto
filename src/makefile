CC = g++ 
flags = -std=c++17
exe = play


# ----------------------------------------------------------------------- #
# ----------------------------------------------------------------------- #

SDL2_path = /opt/homebrew/Cellar/sdl2/2.0.22/include/SDL2
lib_path = /opt/homebrew/Cellar/sdl2/2.0.22/lib


IMAGE_path = /opt/homebrew/Cellar/sdl2_image/2.0.5/include/SDL2
libimage_path = /opt/homebrew/Cellar/sdl2_image/2.0.5/lib

# ----------------------------------------------------------------------- #
# ----------------------------------------------------------------------- #


includes = -I$(SDL2_path) -I$(IMAGE_path) 
libraries = -L$(lib_path) -lSDL2 -L$(libimage_path) -lSDL2_image
objectDump = ../objDir/


# ----------------------------------------------------------------------- #

all: main.o game.o textureManager.o gameObject.o
	@cd $(objectDump) && $(CC) $(flags) *.o -o $(exe) $(includes) $(libraries);
	@echo "executable file created"


main.o: main.cpp game.hpp textureManager.hpp gameObject.hpp
	@$(CC) $(flags) -c main.cpp -o $(objectDump)main.o $(includes)
	@echo "main.o created"


game.o: game.cpp game.hpp
	@$(CC) $(flags) -c game.cpp -o $(objectDump)game.o $(includes)
	@echo "game.o created"


textureManager.o: textureManager.cpp textureManager.hpp
	@$(CC) $(flags) -c textureManager.cpp -o $(objectDump)textureManager.o $(includes)
	@echo "textureManager.o created"


gameObject.o: gameObject.cpp gameObject.hpp
	@$(CC) $(flags) -c gameObject.cpp -o $(objectDump)gameObject.o $(includes)
	@echo "gameObject.o created"

# ----------------------------------------------------------------------- #

run:
	cd $(objectDump) && ./play

clean:
	cd $(objectDump) && rm play *.o
