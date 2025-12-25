//
// Created by nevrozq on 25.12.2025.
//

#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    // int key;
    int value;
} data_type;

typedef struct stack stack;

stack *stack_create(void);

void stack_destroy(stack *s);

bool stack_is_empty(const stack *s);

size_t stack_size(const stack *s);

void stack_push(stack *s, data_type item);

data_type stack_pop(stack *s);

data_type stack_peek(const stack *s);

void stack_print(const stack *s);

#endif //STACK_H
