#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "music_library.c"

int main(){
  printf("%d\n", strcmp("radioheadparanoid android","ac/dcthunderstruck"));
  printf("%d\n", strcmp("radioheadparanoid android", "pink floydtime"));
  printf("%d\n", strcmp("radioheadparanoid android", "radioheadstreet spirit (fade out)"));

  struct song_node * song = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(song -> artist, "ac/dc");
  strcpy(song -> name, "thunderstruck");
  song -> next = NULL;

  print_songs(song);
  
  song = insert(song, "pink floyd", "time");
  print_songs(song);
  
  song = insert(song, "radiohead", "street spirit (fade out)");
  print_songs(song);

  song = insert(song, "radiohead", "paranoid android");
  print_songs(song);
   
  song = insert(song, "pearl jam",  "even flow");
  print_songs(song);
  song = insert(song, "pearl jam", "yellow ledbetter");
  print_songs(song);
  song = insert(song, "pearl jam",  "alive");
  
  printf("LINKED LIST TESTS");
  printf("\n====================================\n\n");
    
  printf("Testing print_songs:\n");
  print_songs(song);
  printf("====================================\n\n");
  printf("Testing print_song:\n");
  print_song(song);
  printf("====================================\n\n");

  printf("Testing find_song:\n");
  struct song_node* found = find_song(song, "pearl jam", "yellow ledbetter");
  find_song(song, "pearl jam", "daughter");
  printf("====================================\n\n");

  printf("Testing find_artist:\n");
  struct song_node* song_one = find_artist(song, "pearl jam");
  struct song_node* song_two = song_two = find_artist(song, "radiohead");
  find_artist(song, "presidents of the united states of america");
  printf("====================================\n\n");
  
  printf("Testing songcmp (helper function):\n");
  printf("  %d\n", songcmp(song_one -> artist, song_one -> name, song_one -> artist, song_one -> name));
  printf("  %d\n", songcmp(song_one -> artist, song_one -> name, song_two -> artist, song_two -> name));
  printf("  %d\n", songcmp(song_two -> artist, song_two -> name, song_one -> artist, song_one -> name));
  printf("====================================\n\n");
    
  printf("Testing random:\n");
  srand(time(NULL));
  print_song(random_song(song));
  print_song(random_song(song));
  print_song(random_song(song));
  print_song(random_song(song));
  print_song(random_song(song));
  print_song(random_song(song));
  printf("====================================\n\n");
  
  printf("Testing remove:\n");
  remove_song(song, "pink floyd", "time");
  printf("\n");
  remove_song(song, "pink floyd", "time");

  printf("\n");
  remove_song(song, "ac/dc", "thunderstruck");
  print_songs(song);
  printf("\n====================================\n\n");
  
  printf("Testing free_list:\n");
  print_songs(song);
  song_one = free_list(song);
  printf("list after free_list:\n");
  print_songs(song_one);
  printf("memory that has been freed, but not cleared:\n");
  print_songs(song);
  printf("\n====================================\n\n");
  
  return 0;
  
}

