#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ll.h"

struct song_node * library[26];
srand( time(NULL) );

char get_song_index(song_node * new_song){
	char * author = new_song -> artist;
	char index = *author[0] - 'a';
	return index;
}

char get_author_index(char artist[]){
	char index = *author[0] - 'a';
	return index;
}

void add_song(song_node * new_song){
	ordered_add(library[get_song_index(new_song)], new_song);
}

struct song_node * find_song(char name[], char artist[]){
	return find_node(library[get_author_index(artist)], name);
} 

struct song_node * find_song(char artist[]){
	return find_node_by_artist(library[get_author_index(artist), artist));
}

void print_letter(char letter){
	print_list(library[letter - 'a']);
}

void print_artist_songs(char artist[]){
	print_artists(library[get_author_index(artist)], artist);
}

void print_library(){
	int i = 0;
	for(;i < 26;i++){
		printf("Printing artists that begin with %c\n", 'a' + i);
		print_list(library['a' + i]);
	}
}

void delete_song(struct * song_node){
	delete_node(library[get_song_index(song_node)], song_node);
}

void delete_lib(){
	int i = 0;
	for(;i < 26;i++){
		free_list(library[i]);
	}
}




