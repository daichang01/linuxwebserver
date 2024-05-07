#include <stdio.h>
#include <string.h>

int main() {

    char * buf; //指针没有指向合法内存

    strcpy(buf, "hello");

    return 0;
}