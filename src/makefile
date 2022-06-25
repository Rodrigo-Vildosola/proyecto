CC 					= g++ 
CVERSION 			= -std=c++17 
CFLAGS 				= -Wall -Wundef -Wpedantic -Werror -Wextra -Wuninitialized -Winit-self
TARGET 				= play

HEADERS 			:= game.hpp textureManager.hpp gameObject.hpp
OBJS 				:= main.o game.o textureManager.o gameObject.o

# ----------------------------------------------------------------------- #
# ----------------------------------------------------------------------- #

SDL2_path 			= /opt/homebrew/Cellar/sdl2/2.0.22/include/SDL2
lib_path 			= /opt/homebrew/Cellar/sdl2/2.0.22/lib

IMAGE_path 			= /opt/homebrew/Cellar/sdl2_image/2.0.5/include/SDL2
libimage_path 		= /opt/homebrew/Cellar/sdl2_image/2.0.5/lib

# ----------------------------------------------------------------------- #
# ----------------------------------------------------------------------- #


INCLUDES 			= -I$(SDL2_path) -I$(IMAGE_path) 
LIBS 				= -L$(lib_path) -lSDL2 -L$(libimage_path) -lSDL2_image
DIR 				= ../objDir/


# ----------------------------------------------------------------------- #

all: $(TARGET)

$(TARGET): $(OBJS)
	@cd $(DIR); \
	$(CC) $(CVERSION) $(INCLUDES) $(LIBS) $^ -o $@;
	@echo "$@ created"


%.o: %.cpp $(HEADERS)
	@$(CC) $(CVERSION) $(INCLUDES) -c $< -o $(DIR)$@ 
	@echo "$@ created"

# ----------------------------------------------------------------------- #

run:
	cd $(DIR) && ./$(TARGET)

clean:
	cd $(DIR) && rm $(TARGET) $(OBJS) $(deps)
