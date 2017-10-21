struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

void print_list(struct song_node *);

struct song_node * insert_front(struct song_node *, int);

struct song_node * free_list(struct song_node *);
