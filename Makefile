.ONESHELL:

all : games
	cd games
	cd hex-color-guessing-game
	make all
	cd ../tic-tac-toe
	make all

debug : games
	cd games
	cd hex-color-guessing-game
	make debug
	cd ../tic-tac-toe
	make debug