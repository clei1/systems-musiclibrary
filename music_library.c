#include <stdio.h>
#include <stdlib.h>

//header file
#include "music_library.h"
#include "songs.c"

void print_library(struct song_node* library []){
  char letter = 'a';
  for(int i = 0; i < 26; i ++){
    if(library[i]){
      printf("%c list\n", letter + i);
      print_songs(library[i]);
    }
  }
}

void print_letter(char letter, struct song_node* library[]){
  printf("%c list\n", letter);
  print_songs(library[letter - 'a']);
}

struct song_node* find_lib_artist(char* artist, struct song_node* library[]){
  int counter = artist[0] - 'a';
  return find_artist(library[counter], artist);
}

struct song_node * find(char* artist, char* name, struct song_node* library[]){
  return find_song(find_lib_artist(artist, library), artist, name);
}

void clear_library(struct song_node* library[]){
  for(int i = 0; i < 26; i ++){
    free_list(library[i]);
  }
}

void print_artist(char* artist, struct song_node* library[]){
  print_songs(find_lib_artist(artist, library));
}

struct song_node* shuffle(struct song_node* library[]){
  srand(time(NULL));
  int count = rand() % 26;
  while(library[count]){
    count = rand() % 26;
  }
  return random_song(library[count]);
}

void insert_song(struct song_node* library[], char* artist, char* name){
  int count = artist[0] - 'a';
  if(! library[count]){
    struct song_node * new_song = (struct song_node *) malloc(sizeof(struct song_node));
    strcpy(new_song -> artist, artist);
    strcpy(new_song -> name, name);
    new_song -> next = NULL;
    library[count] = new_song;
  }
  else{
    library[count] = insert(library[count], artist, name);
  }
  //return library[count];
}

int main(){
  printf("====================================\n\nMUSIC LIBRARY TESTS\n\n====================================\n");
  printf("Testing print_library\n");

  /*
  struct song_node* a = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(a -> artist, "ac/dc");
  strcpy(a -> name, "thunderstruck");

  struct song_node* p = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(p -> artist, "pearl jam");
  strcpy(p -> name, "alive");
  */
  
  struct song_node * table[27];
  int alpha = 0;
  while(alpha < 26){
    alpha ++;
    table[alpha] = NULL;
  }
  table[26] = 0;

  print_library(table);
  insert_song(table, "ac/dc", "thunderstruck");
  insert_song(table, "pearl jam", "alive");
  print_library(table);

  return 0;
}
