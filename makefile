tunezz: music_lib.o
	gcc -o tunezz main.c

music_lib.o: node_funcs.o music_lib.c
	gcc -c music_lib.c

node_funcs.o: node_funcs.c
		gcc -c node_funcs.c

run: tunezz
	./tunezz
