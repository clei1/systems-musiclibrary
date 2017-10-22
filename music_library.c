#include <stdio.h>
#include <stdlib.h>

//header file
#include "songs.c"

void print_library(struct song_node* library []){
  char letter = 'a';
  for(int i = 0; i < 26; i ++){
    if(library[i]){
      printf("%c list\n  ", letter + i);
      print_songs(library[i]);
    }
  }
}

void print_letter(char letter, struct song_node* library[]){
  printf("%c list\n  ", letter);
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
    if(library[i])
      library[i] = free_list(library[i]);
  }
}

void print_artist(char* artist, struct song_node* library[]){
  find_lib_artist(artist, library);
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
}

void remove_lib_song(struct song_node* library[], char* artist, char* name){
  int count = artist[0] - 'a';
  if(library[count]){
    library[count] = remove_song(library[count], artist, name);					 
   }
}

struct song_node* shuffle(struct song_node* library[]){
  int count = rand() % 26;
  while(! library[count]){
    count = rand() % 26;
  }
  return random_song(library[count]);
}
