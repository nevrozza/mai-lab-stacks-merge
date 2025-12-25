#include "stack.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

struct stack {
    data_type *data;
    size_t capacity;
    size_t count;
};

stack *stack_create(void) {
    stack *s = malloc(sizeof(stack));
    data_type *data = malloc(INITIAL_CAPACITY * sizeof(data_type));

    if (s == NULL || data == NULL) {
        memory_error();
        return NULL; // suppress IDE
    }

    s->data = data;
    s->capacity = INITIAL_CAPACITY;
    s->count = 0;

    return s;
}

void stack_destroy(stack *s) {
    if (s != NULL) {
        free(s->data);
        free(s);
    }
}

static void stack_realloc(stack *s, size_t new_capacity) {
    data_type *new_data = realloc(s->data, new_capacity * sizeof(data_type));

    if (new_data == NULL) { memory_error(); }

    s->data = new_data;
    s->capacity = new_capacity;
}

bool stack_is_empty(const stack *s) {
    return s->count == 0;
}

size_t stack_size(const stack *s) {
    return s->count;
}

void stack_push(stack *s, data_type item) {
    if (s->count == s->capacity) {
        stack_realloc(s, s->capacity * 2);
    }
    s->data[s->count++] = item;
}

data_type stack_pop(stack *s) {
    if (stack_is_empty(s)) { error("Stack is empty"); }
    return s->data[--s->count];
}

data_type stack_peek(const stack *s) {
    if (stack_is_empty(s)) { error("Stack is empty"); }
    return s->data[s->count - 1];
}

void stack_print(const stack *s) {
    if (stack_is_empty(s)) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < s->count; i++) {
        if (i > 0) printf(", ");
        printf("(%d)", s->data[i].value); // s->data[i].key,
    }
    printf("]  <-- вершина\n");
}
