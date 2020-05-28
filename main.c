#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <errno.h>
#include <pthread.h>
#include <semaphore.h>


#define N 5

void child_process(int i){
    printf("[child %d] entry\n", i);
  }

int main(void) {
  for(int i=0; i<N; i++){
    switch(fork()){
      case -1:
        perror("fork() error");
        exit(EXIT_FAILURE);
        break;

      case 0:
        printf("[child %d] entry\n", i);
        exit(EXIT_SUCCESS);
        break;

      default:
        ;
    }
  }

  while (wait(NULL) != -1) ;

  exit(0);
}