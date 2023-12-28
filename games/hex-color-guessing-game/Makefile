COMPILER=em++

SRC=src/*.cpp
INCLUDE=-Iinclude

FLAGS=--bind -fsanitize=undefined

OUTPUT=deploy/wasm.js

all : $(SRC)
	$(COMPILER) $(SRC) $(INCLUDE) $(FLAGS) -o $(OUTPUT)