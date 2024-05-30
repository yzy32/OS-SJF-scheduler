#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
  int job_length = atoi(argv[1]);
  if (job_length < 0) {
    printf("Job length must be a non-negative integer\n");
    exit(1);
  }

  while (1) {
    ;
  }

  return 0;
}