all:
	g++ -fdiagnostics-color=always -g -I Win\include -L Win\lib -o Win\Tetris.exe Win\Blocks.cpp Win\Tetris.cpp