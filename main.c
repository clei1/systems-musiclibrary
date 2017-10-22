#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "music_library.c"

int main(){
  struct song_node * song = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(song -> artist, "ac/dc");
  strcpy(song -> name, "thunderstruck");
  song -> next = NULL;
  song = insert(song, "pink floyd", "time");
  song = insert(song, "radiohead", "street spirit (fade out)");
  song = insert(song, "radiohead", "paranoid android");
  song = insert(song, "pearl jam",  "even flow");
  song = insert(song, "pearl jam", "yellow ledbetter");
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
  song = remove_song(song, "pink floyd", "time");
  printf("\n");
  song = remove_song(song, "pink floyd", "time");

  printf("\n");
  song = remove_song(song, "ac/dc", "thunderstruck");
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


  struct song_node * table[27];
  int alpha = 0;
  while(alpha < 26){
    alpha ++;
    table[alpha] = NULL;
  }
  table[26] = 0;
  
  insert_song(table, "ac/dc", "thunderstruck");
  insert_song(table, "radiohead","paranoid android");
  insert_song(table, "pearl jam", "alive");
  insert_song(table, "presidents of the united states of america","peaches");
  insert_song(table, "pearl jam","yellow ledbetter");
  insert_song(table, "radiohead","street spirit (fade out)");
  insert_song(table, "pearl jam", "even flow");
  insert_song(table, "pink floyd","time");

  printf("====================================\n\nMUSIC LIBRARY TESTS\n\n====================================\n");
  printf("Testing print_library\n");
  print_library(table);
  printf("====================================\n\n");

  printf("Testing print_library\n");
  print_letter('a', table);
  printf("====================================\n\n");

  printf("Testing find:\n");
  find("pearl jam", "alive", table);
  find("pearl jam", "notalive", table);
  printf("====================================\n\n");

  printf("Testing find artist:\n");
  find_lib_artist("pearl jam", table);
  find_lib_artist("pink floyd", table);
  find_lib_artist("bob dylan", table);
  printf("====================================\n\n");

  printf("Testing remove_song\n");
  remove_lib_song(table,"pearl jam", "alive");
  print_library(table);
  remove_lib_song(table, "pearl jam","yellow ledbetter");
  print_library(table);
  printf("====================================\n\n");

  printf("Testing clear_library\n");
  clear_library(table);
  printf("\n");

  printf("Library after clear\n");
  print_library(table);
  printf("====================================\n\n");

  printf("Adding songs to empty library\n");
  insert_song(table, "ac/dc", "thunderstruck");
  insert_song(table, "radiohead","paranoid android");
  insert_song(table, "pearl jam", "alive");
  insert_song(table, "presidents of the united states of america","peaches");
  insert_song(table, "pearl jam","yellow ledbetter");
  insert_song(table, "radiohead","street spirit (fade out)");
  insert_song(table, "pearl jam", "even flow");
  insert_song(table, "pink floyd","time");
  print_library(table);
  print_artist("pearl jam", table); 
  print_artist("ac/dc", table);
  printf("====================================\n\n");
  
  printf("Testing shuffle\n");
  srand(time(NULL));
  print_song(shuffle(table));
  print_song(shuffle(table));
  print_song(shuffle(table));
  print_song(shuffle(table));
  print_song(shuffle(table));
  print_song(shuffle(table));
  
  return 0;
}

