#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "music_lib.c"

void newline(){
	printf("\n");
}

int main(){
	srand(time(NULL));
	printf("////////TESTING THE INDIVIDUAL NODES\\\\\\\\\\ \n\n");
	printf("Creating new nodes + testing print\n");

	struct song_node * test_list = insert_front(NULL, "thanks for nothing", "sum 41");
	printf("Created node for song 'thanks for nothing' by sum 41\n");
	test_list = ordered_add(test_list, "with me", "sum 41");
	printf("Created node for song 'with me' by sum 41\n");
	test_list = ordered_add(test_list, "13 voices", "sum 41");
	printf("created node for song '13 voices' by sum 41\n");
	printf("Should print 3 Sum 41 nodes - Thanks for Nothing, With Me, 13 Voices\n");

	print_list(test_list); /////////////////

	printf("Adding two (the) Script songs, and a Set It Off song with an ordered_add\n");
	test_list = ordered_add(test_list, "six degrees of seperation", "script");
	test_list = ordered_add(test_list, "hall of fame", "script");
	test_list = ordered_add(test_list, "the haunting", "set it off");
	printf("Should return an ordered list of songs:\n");

	print_list(test_list); //////////////////

	newline();

	printf("Cool! One letter works! Let's add some green day, theory of a deadman and the fray, again checking to see that our list of songs is in order\n");
	test_list = ordered_add(test_list, "holiday", "green day");
	test_list = ordered_add(test_list, "novocaine", "green day");
	test_list = ordered_add(test_list, "end of the summer", "theory of a deadman");
	test_list = ordered_add(test_list, "love don't die", "the fray");
	print_list(test_list);

	newline();

	printf("WOO! Now, let's only print certain artists :) I'm feeling kinda green day rn, so let's see their songs\n");
	print_artists(test_list, "green day");
	printf("Actually, I want some uh Sum 41!\n");
	print_artists(test_list, "sum 41");
	printf("Okay now time for Lady Gaga\n");
	print_artists(test_list, "lady gaga");
	printf("Guess this playlist doesn't have any... :'( \n");

	newline();

	printf("Using the print_node function, I want to find a couple songs\n");
	printf("13 Voices is a really good song, let's get that\n");
	print_node(find_node(test_list, "13 voices"));
	printf("So is End of the Summer actually, let's listen to that \n");
	print_node(find_node(test_list, "end of the summer"));
	printf("Go team! *self five*");

	newline();

	printf("Oooo okay now I wanna find sum 41 in the entire playlist\n");
	print_list(find_artist(test_list, "sum 41"));
	printf("It printed things after, which is great, cause all we wanted was the pointer to that artist!!");

	newline();

	printf("I'm feelin snazzy... let's hear a random song!\n");
	print_node(random_song(test_list));
	printf("Anotha one\n");
	print_node(random_song(test_list));
	printf("And ANOTHA one\n");
	print_node(random_song(test_list));

	newline();

	printf("Okok you know what. Novocaine is an inappropriate name for a song and should be nowhere in a school project. I want that node freed at once!!\n");
	free_node(test_list, "novocaine");
	print_list(test_list);
	printf("Good it's gone.\n\nAw man I just went through an awful breakup. The Fray was wrong, love DOES die >:(. I don't want that song anymore.\n");
	free_node(test_list, "love don't die");
	print_list(test_list);
	printf("Good to see we can free all our nodes!\n");

	printf("I'm becoming a monk. I'm tired of the modern age. I no longer have need of music. Begone library. Be free.\n");
	test_list = free_list(test_list);
	print_list(test_list);
	printf("*nothing printed cause its g o n e*\n\n\n");

	newline();
	newline();
	newline();
	newline();

	printf("////////TESTING THE LIBRARY\\\\\\\\\\ \n\n");
	int i;
	for(i = 0; i < 26; i++){
		library[i] = NULL;
	}

	struct song_node * still_waiting = insert_front(NULL, "still waiting", "sum 41");
	printf("Created song node 'still waiting' by sum 41\n");
	struct song_node * twistedbd = insert_front(NULL, "twisted by design", "sum 41");
	printf("Created song node 'twisted by design' by sum 41\n");
	struct song_node * end_of_sum = insert_front(NULL, "end of the summer", "theory of a deadman");
	printf("Created song node 'end of the summer' by theory of a deadmann");
	struct song_node * holiday = insert_front(NULL, "holiday", "green day");
	printf("Created song node 'holiday' by green day  \n");
	struct song_node * lovedd = insert_front(NULL, "love don't die", "the fray");
	printf("Created song node 'love don't die' by the fray");

	add_song(still_waiting);
	add_song(twistedbd);
	add_song(end_of_sum);
	add_song(holiday);
	add_song(lovedd);

	print_library();
	printf("woo our library's kool\n");

	printf("I'm really vibing with some sum 41 one right now... let's search it up [and use print list to see what we get]\n");

	print_list(find_song_artist("sum 41"));



	printf("Cool! Sum 41's great, but i wanna listen to end of the summer now by theory of a deadman, let's pull that one up using find_song\n");
	print_list(find_song("end of the summer", "theory of a deadman"));



	printf("My music tastes evolving, I want some more artists with the letter s. Maybe sia, and sam smith?\n");
	add_song(insert_front(NULL, "chandelier", "sia"));
	add_song(insert_front(NULL, "stay with me", "sam smith"));

	printf("Now let's print the entries under s\n");
	print_letter('s');

	printf("Nah I'm bored of these guys, I want sum41 again... let's print only their songs\n");
	print_artist_songs("sum 41");

	printf("Hm.. I wonder what songs I actually have now... Let's print the library\n");
	print_library();

	printf("Let's get really crazy... like REALLY crazy. Let's shuffle it up and get 3 random songs.\n");

	shuffle(3);

	printf("Sia is awful lol let's delete chandelier.\n");

	delete_song("chandelier", "sia");

	printf("Let's check to make sure it's actually gone...\n");

	print_library();

	printf("Same drill as last time... off to becoming a monk. Free the music... be free be gone!!\n");

	delete_lib();

	printf(" ~~nothing printed cause its all gone~~\n");

	print_library();


}
