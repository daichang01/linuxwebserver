#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];  // 文件描述符数组
    char buf;
    char *message = "Hello from parent!";

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {  // 子进程
        close(pipefd[1]);  // 关闭写端
        while (read(pipefd[0], &buf, 1) > 0) {
            write(STDOUT_FILENO, &buf, 1);
        }
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
    } else {  // 父进程
        close(pipefd[0]);  // 关闭读端
        write(pipefd[1], message, strlen(message));
        close(pipefd[1]);
        wait(NULL);  // 等待子进程结束
    }

    return 0;
}