#include <stdio.h>


int main() {
    int a = 10;
#ifdef DEBUG
    printf("我是一个dccc\n");
#endif
    for (int i = 0; i < 3; i++) {
        printf("hello gcc\n");
    }
    return 0;
}