#include "merge.h"

stack *stack_clone(stack *s) {
    stack *temp = stack_create();
    stack *clone = stack_create();

    while (!stack_is_empty(s)) { stack_push(temp, stack_pop(s)); }
    while (!stack_is_empty(temp)) {
        const data_type data = stack_pop(temp);
        stack_push(clone, data);
        stack_push(s, data);
    }

    stack_destroy(temp);
    return clone;
}
