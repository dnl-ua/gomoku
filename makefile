all: main

main: main.cpp
	g++ Gomoku.cpp Gomoku.h main.cpp -o main -lncurses && ./main
