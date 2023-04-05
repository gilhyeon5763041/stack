#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_STACK_SIZE 10

typedef int element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

StackType* create(int size) {
    StackType* sp = malloc(sizeof(StackType));
    sp->top = -1;
    return sp;
}

void push(StackType* sp, element item) {
    if (sp->top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "스택 포화 오류 \n");
        return;
    }
    sp->top++;
    sp->data[sp->top] = item;
}

element pop(StackType* sp) {
    if (sp->top == -1) {
        fprintf(stderr, "스택 공백 에러\n");
        return -1;
    }
    element r = sp->data[sp->top];
    sp->top--;
    return r;
}

element peek(StackType* sp) {
    if (sp->top == -1) {
        fprintf(stderr, "스택 공백 에러\n");
        return -1;
    }
    return sp->data[sp->top];
}

int main(void) {
    srand(time(NULL));
    int rand_num;
    StackType* s = create(MAX_STACK_SIZE);
    for (int i = 0; i < 30; i++) {
        rand_num = rand() % 100 + 1;
        if (rand_num % 2 == 0) {
            push(s, rand_num);
            printf("[push]%d\n", peek(s));
        }
        else {
            pop(s);
            printf("[pop]%d\n", peek(s));
        }
    }
    return 0;
}