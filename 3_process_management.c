#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());

        int fd = open("demo.txt", O_CREAT | O_WRONLY, 0644);
        write(fd, "Hi from child\n", 14);
        close(fd);

        execlp("echo", "echo", "Executed echo via exec", NULL);
        exit(0);
    } else {
        wait(NULL);
        printf("Parent PID: %d\n", getpid());
        printf("Child finished\n");
    }

    return 0;
}

/*
Output:
Child PID: 12345
Executed echo via exec
Parent PID: 12344
Child finished
*/
