#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

int main(){
  printf("Printing information about directory: .\n");
  printf("Subdirectories: \n");
  long long size = 0;
  DIR *d = opendir(".");
  if (d == NULL){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  struct dirent *ent;
  while((ent = readdir(d)) != NULL){
    if (ent->d_type == DT_DIR){
      printf("%s\n", ent->d_name);
    }
  }
  closedir(d);
  printf("\n");
  printf("Regular files: \n");
  d = opendir(".");
  if (d == NULL){
    printf("errno %d error: %s\n", errno, strerror(errno));
  }
  while((ent = readdir(d)) != NULL){
    if (ent->d_type != DT_DIR){
      struct stat stats;
      int error = stat(ent->d_name, &stats);
      if (error == -1){
        printf("errno %d error: %s\n", errno, strerror(errno));
      }
      size += stats.st_size;
      printf("%s\n", ent->d_name);
    }
  }
  printf("Directory size: %lld Bytes\n", size);
  return 0;
}
