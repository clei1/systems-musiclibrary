struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

void print_song(struct song_node* song);
void print_songs(struct song_node* song);
struct song_node* insert_front(struct song_node * song, char* artist, char* name);
struct song_node* free_list(struct song_node* song);
struct song_node* find_artist(struct song_node* song, char* artist);
struct song_node* find_song(struct song_node* song, char* artist, char* name);
int artistcmp(struct song_node* song_one, struct song_node* song_two);
int songcmp(struct song_node* song_one, struct song_node* song_two);
int get_num(struct song_node* song);
struct song_node* random_song(struct song_node* song);
struct song_node* remove_song(struct song_node* song, char* song_artist, char* song_name);
