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
    free_list(library[i]));
  }
}

void print_artist(char* artist, struct song_node* library[]){
  print_songs(find_lib_artist(artist, library));
}

/*
void shuffle(){
  srand(time(NULL));
  for(int i = 0; i < 26; i++){
    
  }
}
*/

int main(){
  printf("====================================\n\nMUSIC LIBRARY TESTS\n\n====================================\n");
  printf("Testing print_library\n");

  struct song_node* a = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(a -> artist, "ac/dc");
  strcpy(a -> name, "thunderstruck");

  struct song_node* p = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(p -> artist, "pearl jam");
  strcpy(p -> name, "alive");
  
  struct song_node * table[27];
  int alpha = 0;
  while(alpha < 26){
    alpha ++;
    table[alpha] = NULL;
  }
  table[26] = 0;

  print_library(table);

  
  

  return 0;
}
