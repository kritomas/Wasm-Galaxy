COMPILER=em++

SRC=src/*.cpp
INCLUDE=-Iinclude

FLAGS=--bind -Wall -sEXPORTED_FUNCTIONS=_main,_csqr -sEXPORTED_RUNTIME_METHODS=cwrap,ccall

OUTPUT=deploy/wasm.js

all : $(SRC)
	$(COMPILER) $(SRC) $(INCLUDE) $(FLAGS) -o $(OUTPUT)