#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header_tunez.h"

int compare_nodes(struct song_node * first, struct song_node * second){
	if(strcmp(first -> artist, second -> artist)){
		return strcmp(first -> artist, second -> artist);
	}
	return strcmp(first -> title, second -> title);
}

struct song_node * insert_front(struct song_node * ogfront, char * titl, char * artis){
	struct song_node *newnod = (struct song_node *) malloc(1 * sizeof(struct song_node));
	newnod -> title = titl;
	newnod -> artist = artis;
	newnod -> next = ogfront;
	return newnod;
}

struct song_node * insert_node_front(struct song_node * ogfront, struct song_node * nof){
	struct song_node *newnod = (struct song_node *) malloc(1 * sizeof(struct song_node));
	nof -> next = ogfront;
	return newnod;
}

struct song_node * ordered_add(struct song_node * list, char * title, char * artist){
	struct song_node * new_song = insert_front(NULL, title, artist);
	//If the node we wanna insert is supposed to go first:
	if(compare_nodes(list, new_song) >= 0){
		//printf("inserted front\n");
		return insert_front(list, title, artist);
	}

	//If the node goes somewhere in the middle:
	struct song_node * ogf  = list;

	while(list->next){
		if(compare_nodes(list -> next, new_song) >= 0){
			//print_node(new_song);
			//print_node(insert_front(list -> next, title, artist));
			//print_node(list -> next);
			list -> next = insert_front(list -> next, title, artist);
			return ogf;
		}
		list = list -> next;
	}
	//If the node goes at the end:
	if(!(list -> next)){
		list -> next = insert_front(NULL, title, artist);
		return ogf;
	}
}

void print_node(struct song_node * tbp){
	printf("\tTitle: %s | Artist: %s\n", tbp -> title, tbp -> artist);
}

void print_list(struct song_node * tbp){
	while(tbp){
		print_node(tbp);
		tbp = tbp -> next;
	}
}

void print_artists(struct song_node * tbp, char artist[]){
	while(tbp){
		if(!(strcmp(tbp -> artist, artist))){
			print_node(tbp);
		}
		tbp = tbp -> next;
	}
}

struct song_node * find_node(struct song_node * list, char song_title[]){
	while(list){
		if(list -> title == song_title){
			return list;
		}
		list = list -> next;
	}
	return NULL;
}
struct song_node * find_artist(struct song_node * list, char artist_title[]){
	while(list){
		if(!(strcmp(list -> artist, artist_title))){
			return list;
		}
		list = list -> next;
	}
	return NULL;
}
void init_rand(){
	srand(time(NULL));
}

struct song_node * random_song(struct song_node * list){
	init_rand();
	int ctr = 0;
	struct song_node * og_list = list;
	while(list){
		ctr++;
		list = list -> next;
	}
	int index = rand() % ctr;
	while(index != 0){
		og_list = og_list -> next;
		index --;
	}
	return og_list;
	/*Do random stuff to get to a random node and return it? */
}

struct song_node * free_node(struct song_node * list, char * song_title){
	struct song_node * og_list = list;
	if(!(strcmp(list -> title, song_title))){
		struct song_node * newFront = list -> next;
		free(list);
		return newFront;
	}
	while(list){
		if(!(strcmp(list -> next -> title, song_title))){
			struct song_node * tbf = list -> next;
			list -> next = list -> next -> next;
			free(tbf);
			return og_list;
		}
		list = list -> next;
	}
}

struct song_node * free_list(struct song_node* tbf){
	while(tbf){
		struct song_node * beingfreed = tbf;
		tbf = tbf -> next;
		free(beingfreed);
	}
	return tbf;
}
