#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if (argc != 2) {
        printf("Usage: sleep number-of-ticks\n");
        exit(0);
  }
  int ticks = atoi(argv[1]);
  sleep(ticks);
  exit(0);
}
