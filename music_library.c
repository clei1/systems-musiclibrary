#include <stdio.h>
#include <stdlib.h>

//header file
#include "music_library.h"
#include "songs.c"


void print_library(struct song_node* library){
  while(library);
}
/*
  void print_letter(){

  }

  struct song_node * find(){

  }

  struct song_node * find_artist(){

  }

  void clear_library(){

  }

  void print_artist(){

  }

  void shuffle(){

  }
*/

int main(){
  printf("====================================\n\nMUSIC LIBRARY TESTS\n\n====================================\n");
  printf("Testing print_library\n");

  struct song_node* a = (struct song_node *) malloc(sizeof(struct song_node));
  a -> artist = "ac/dc";
  a -> name = "thunderstruck";

  struct song_node* p = (struct song_node *) malloc(sizeof(struct song_node));
  p -> artist = "pearl jam";
  p -> name = "alive";
  
  struct song_node * table[27];
  int alpha = 0;
  while(alpha < 26){
    alpha ++;
    table[alpha] = NULL;
  }
  table[alpha] = 0;

  

  return 0;
}
