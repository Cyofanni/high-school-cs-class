#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  pid_t pid = fork();
  if (pid > 0) {
    for (int i = 0; i < 10; i++) {
      printf("PARENT: %d\n", i);
    }
    pid = wait(NULL);
    printf("PARENT: child %d exited with unknown status\n", pid);
  }
  else if (!pid) {
    for (int i = 0; i < 10; i++) {
      printf("CHILD: %d\n", i);
    }
  }
}
