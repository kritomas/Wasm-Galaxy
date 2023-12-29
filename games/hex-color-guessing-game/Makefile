COMPILER=em++

SRC=src/*.cpp
INCLUDE=-Iinclude

FLAGS=-lembind -Wall
DEBUG_FLAGS=-O0 -g

OUTPUT=deploy/wasm.js

all : $(SRC)
	$(COMPILER) $(SRC) $(INCLUDE) $(FLAGS) -o $(OUTPUT)

debug : $(SRC)
	$(COMPILER) $(SRC) $(INCLUDE) $(FLAGS) $(DEBUG_FLAGS) -o $(OUTPUT)