#include "kernel/types.h"
#include "user/user.h"

#define job_count 1

int main(int argc, char *argv[]) {
  if (argc > job_count+1) {
    printf("Usage: testDrive <job1-ticks> ... <job10-ticks>\n");
    exit(1);
  }

  int pids[job_count];
  int children_count = 0;
  for (int i=0; i<job_count; i++){
    int job_length = atoi(argv[i+1]);
    if (job_length < 0) {
      printf("Job %d's length must be a non-negative integer\n", i);
      continue;
    }
    
    int rc = fork();
    if (rc < 0){
      printf("fork failed\n");
      exit(1);
    } else if (rc==0){
      printf("Child %d will run for %d seconds.\n", i, job_length);
      char *length = argv[i+1];
      char *job_argv[] = { "job", length };
      exec("/job", job_argv);
      exit(0);
    } else {
      pids[children_count++] = rc;
      printf("Hello from the parent process! Child PID: %d\n", rc);
    }
    
  }

  for (int i = 0; i < children_count; i++){
    wait(&pids[i]);
  }

  printf("Bye! (from the parent process)\n");
  return 0;
}