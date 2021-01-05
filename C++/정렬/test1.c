#include <stdio.h>

void func(int* arg);

int main(void) {
    int arg = 5;
    printf("before func(), arg: %d\n", arg);
    func(arg);
    printf("after func(), arg: %d\n", arg);
    return 0;
}

void func(int* arg) {
    printf("in func(), arg: %d\n", arg);
}