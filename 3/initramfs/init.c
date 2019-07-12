#include <unistd.h>
#include <stdio.h>

int main() {
    int f = fork();
    int count = 0;
    while (count < 5000) {
        if (f) {
            printf("Pai %d\n", count++);
        } else {
            printf("Filho %d\n", count++);
        }
    }
  return 0;
}
