#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "node_funcs.c"

int get_song_index(struct song_node * new_song){
	char * author = new_song -> artist;
	int index = (int)author[0] - 97;
	//printf("index is: %d\n", index);
	return index;
}

void add_song(struct song_node * new_song){
	int index = get_song_index(new_song);
	if(library[index]){
		//printf("%d\n", index);
		//print_node(new_song);
		library[index] = ordered_add(library[index], new_song -> title, new_song -> artist);
	}
	else { library[index] = new_song; }
}

char get_author_index(char * artist){
	char index = artist[0] - 97;
	return index;
}

struct song_node * find_song(char * name, char * artist){
	return find_node(library[get_author_index(artist)], name);
}

struct song_node * find_song_artist(char * artist){
	return find_artist(library[get_author_index(artist)], artist);
}

void print_letter(char letter){
	print_list(library[letter - 97]);
}

void print_artist_songs(char * artist){
	print_artists(library[get_author_index(artist)], artist);
}

void shuffle(int num_songs){
	while(num_songs > 0){
		int index = rand() % 26;
		if(library[index]){
			print_node(random_song(library[index]));
			num_songs--;
		}
	}
}

void print_library(){
	int i = 0;
	for(;i <  26;i++){
		//printf("%d", ind);
		if(library[i]){
			printf("Printing songs by artists that start with %c:\n", i+97);
			print_list(library[i]);
			printf("\n");
		}
	}
}

void delete_song(char * title, char * artist){
	int index = artist[0] - 97;
	free_node(library[index], title);

}

void delete_lib(){
	int i = 0;
	for(;i < 26;i++){
		library[i] = free_list(library[i]);
	}
}
