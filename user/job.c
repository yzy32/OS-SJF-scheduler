#include "kernel/types.h"
#include "user/user.h"

// void job_info(int job_length) {
//   printf("length: %d, turnaround time: TODO:\n", job_length);
// }

int main(int argc, char *argv[]){
  int job_length = atoi(argv[1]);
  if (job_length < 0) {
    printf("Job length must be a non-negative integer\n");
    exit(1);
  }
  uint64 tBegin = uptime();
  uint64 tEnd = tBegin;
  while (tEnd - tBegin <= job_length) {tEnd = uptime();}
  uint64 tTerminated = uptime();
  printf("%d\n", tTerminated - tBegin);


  return 0;
}