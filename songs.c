#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "songs.h"

void print_song(struct song_node* song){
  printf("%s: %s", song -> artist, song -> name);
}

void print_songs(struct song_node* song){
  struct song_node *current_song = song;
  while(current_song){
    print_song(current_song);
    printf(" | ");
    current_song = current_song -> next;
  }
  printf("\n");
}

struct song_node* insert_front(struct song_node * song, char* artist, char* name){
  struct song_node * new_song = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new_song -> artist, artist);
  strcpy(new_song -> name, name);
  new_song -> next = song;
  printf("Successfully inserted %s: %s\n", artist, name);
  return new_song;
}

struct song_node* free_list(struct song_node* song){
  struct song_node* current_song = song;
  struct song_node* next_song;
  while(current_song){
    next_song = current_song -> next;
    printf("freeing song ");
    print_song(current_song);
    printf("\n");
    free(current_song);
    current_song = next_song;
  }
  return current_song;
}

struct song_node* find_artist(struct song_node* song, char* artist){
  printf("looking for [%s]\n", artist);
  struct song_node* search_song = song;
  char current[256];
  while(search_song){
    strcpy(current, search_song -> artist);
    if(! strcmp(current, artist)){
      printf("artist found! ");
      print_songs(search_song);
      return search_song;
    }
    search_song = search_song -> next;
  }
  printf("artist not found\n");
  return search_song;
}

struct song_node* find_song(struct song_node* song, char* artist, char* name){
  printf("looking for [%s: %s]\n", artist, name);
  struct song_node* target_song = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(target_song -> artist, artist);
  strcpy(target_song -> name, name);
  
  struct song_node* found_artist = find_artist(song, artist);
  while(found_artist){
    if(!songcmp(found_artist, target_song)){
      free(target_song);
      printf("song found ");
      print_song(found_artist);
      return found_artist;
    }
    found_artist = found_artist -> next;
  }
  
  free(target_song);
  printf("song not found\n");
  return found_artist;
}

int artistcmp(struct song_node* song_one, struct song_node* song_two){
  char one[256];
  char two[256];

  strcpy(one, song_one -> artist);
  strcpy(two, song_two -> artist);
  int ret = strcmp(one, two);

  return ret;
}

int songcmp(struct song_node* song_one, struct song_node* song_two){
  printf("comparing [");
  print_song(song_one);
  printf("] to [");
  print_song(song_two);
  printf("]\n");
  int ret = artistcmp(song_one, song_two);
  if(! ret){
    char one[256];
    char two[256];
    strcpy(one, song_one -> name);
    strcpy(two, song_two -> name);
    ret = strcmp(one, two);
  }
  return ret;
}

int get_num(struct song_node* song){
  struct song_node* length_song = song;
  int number_song = 0;
  while(length_song){
    length_song = length_song -> next;
    number_song++;
  }
  return number_song;
}

struct song_node* random_song(struct song_node* song){
  struct song_node* current_song = song;
  int number_songs = get_num(song);
  int rand_num = rand() % number_songs;
  //printf("%d", rand_num);

  while(rand_num){
    current_song = current_song -> next;
    rand_num -= 1;
  }
 
  rand_num = rand() % number_songs;
  return current_song;
}

struct song_node* remove_song(struct song_node* song, char* song_artist, char* song_name){
  printf("removing [%s: %s]\n", song_artist, song_name);

  struct song_node* current_song;
  current_song = find_song(song, song_artist, song_name);
  if(! current_song){
    printf("%s: %s not found", song_artist, song_name);
    return current_song;
  }

  current_song = song;
  struct song_node * new_song = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new_song -> artist, song_artist);
  strcpy(new_song -> name, song_name);

  
  while(songcmp(new_song, current_song -> next)){
    current_song = current_song -> next;
  }
  
  free(new_song);

  struct song_node* being_removed = current_song -> next;
  current_song -> next = (current_song -> next) -> next;
  free(being_removed);

  return song;
}

int main(){

  struct song_node * song = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(song -> artist, "ac/dc");
  strcpy(song -> name, "thunderstruck");
  song -> next = NULL;
  
  printf("LINKED LIST TESTS\n");
  printf("====================================\n\n");
    
  printf("Testing print_songs:\n");
  print_songs(song);
  printf("====================================\n\n");
  
  printf("Testing print_song:\n");
  print_song(song);
  printf("\n");
  printf("====================================\n\n");

  printf("Testing insert_front:\n");
  song = insert_front(song, "radiohead", "street spirit (fade out)");
  print_songs(song);
  printf("\n");
  song = insert_front(song, "radiohead", "paranoid android");
  print_songs(song);
  printf("\n");
  song = insert_front(song, "pink floyd", "time");
  print_songs(song);
  printf("\n");
  song = insert_front(song, "pearl jam", "yellow ledbetter");
  song = insert_front(song, "pearl jam",  "even flow");
  song = insert_front(song, "pearl jam",  "alive");
  printf("\n");
  printf("====================================\n\n");
  
  printf("Testing find_song:\n");
  find_song(song, "pearl jam", "yellow ledbetter");
  printf("\n");
  printf("====================================\n\n");
  
  printf("Testing find_artist:\n");
  struct song_node* song_one = find_artist(song, "pearl jam");
  struct song_node* song_two = song_two = find_artist(song, "radiohead");
  find_artist(song, "presidents of the united states of america");
  printf("====================================\n\n");

  printf("Testing songcmp (helper function):\n");
  printf("%d\n", songcmp(song_one, song_one));
  printf("%d\n", songcmp(song_one, song_two));
  printf("%d\n", songcmp(song_two, song_one));
  printf("====================================\n\n");

  printf("Testing random:\n");
  srand(time(NULL));
  print_song(random_song(song));
  printf("\n");
  print_song(random_song(song));
  printf("\n");
  print_song(random_song(song));
  printf("\n");
  print_song(random_song(song));
  printf("\n");
  print_song(random_song(song));
  printf("\n");
  print_song(random_song(song));
  printf("\n");
  printf("====================================\n\n");

  printf("Testing remove:\n");
  print_songs(song);
  song_one = remove_song(song, "pink floyd", "time");
  printf("\n");
  print_songs(song_one);
  song_one = remove_song(song, "pink floyd", "time");
  printf("\n");
  printf("====================================\n\n");

  printf("Testing free_list:\n");
  song_one = free_list(song);
  printf("list after free_list:\n");
  print_songs(song_one);
  printf("memory that has been freed, but not cleared:\n");
  print_songs(song);
  printf("====================================\n\n");
  
  return 0;
}
