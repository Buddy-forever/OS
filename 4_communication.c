#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) {
        // Child reads
        char msg[20];
        read(fd[0], msg, sizeof(msg));
        printf("Child got: %s\n", msg);
    } else {
        // Parent writes
        write(fd[1], "Hi Child", 9);
    }
    return 0;
}




/*
Output:
Child got: Hi Child
*/
