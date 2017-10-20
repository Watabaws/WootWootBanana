struct song_node {
	char * title;
	char * artist;
	struct song_node * next;
};

struct song_node * library[26];

// List methods
struct song_node * insert_front(struct song_node *, char *, char *);
struct song_node * insert_node_front(struct song_node *, struct song_node *);
void print_node(struct song_node *);
void print_list(struct song_node *);
void print_artists(struct song_node *, char *);
struct song_node * ordered_add(struct song_node *, char *, char *);
struct song_node * find_node(struct song_node *, char *);
struct song_node * random_song(struct song_node *);
struct song_node *free_node(struct song_node *, char *);
struct song_node * free_list(struct song_node *);

// Library methods
int get_song_index(struct song_node *);
char get_author_index(char *);
void add_song(struct song_node *);
struct song_node * find_song(char *, char *);
struct song_node * find_song_artist(char *);
void print_letter(char);
void print_artist_songs(char *);
void print_library();
void delete_song(char *, char * );
void delete_lib();
