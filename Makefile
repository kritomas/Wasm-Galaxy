.ONESHELL:

all : games
	cd games
	cd hex-color-guessing-game
	make all
	cd ..

debug : games
	cd games
	cd hex-color-guessing-game
	make debug
	cd ..