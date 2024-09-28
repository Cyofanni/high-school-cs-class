#include <stdio.h>
#include <unistd.h>

int main() {
  execl("/bin/echo", "/bin/echo", "hello", "world", (char*) 0);
}
