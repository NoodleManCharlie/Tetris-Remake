all:
	g++ -fdiagnostics-color=always -g -I Win/include -L Win/lib -o Win/Tetris.exe Win/Brick.cpp Win/Tetris.cpp -lmingw32 -lSDL2main -lSDL2