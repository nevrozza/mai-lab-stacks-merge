#include "merge.h"

// deepcopy
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

/*
 * Attention!!
 * Рассматриваются стэки отсортированные так, что
 * [1, 2, 3] <- вершина
 */
stack *merge_sorted_stacks(stack *s1, stack *s2) {
    stack *a = stack_clone(s1);
    stack *b = stack_clone(s2);

    stack *rev_a = stack_create();
    stack *rev_b = stack_create();

    // Переворот нужен для сохранения порядка элементов в результате
    // [3, 2, 1]
    while (!stack_is_empty(a)) stack_push(rev_a, stack_pop(a));
    while (!stack_is_empty(b)) stack_push(rev_b, stack_pop(b));

    stack_destroy(a);
    stack_destroy(b);

    stack *result = stack_create();
    while (!stack_is_empty(rev_a) && !stack_is_empty(rev_b)) {
        // [1, 2, 3] – первым закидываем то, что меньше
        if (stack_peek(rev_a).value <= stack_peek(rev_b).value) {
            stack_push(result, stack_pop(rev_a));
        } else {
            stack_push(result, stack_pop(rev_b));
        }
    }

    // Corner cases
    while (!stack_is_empty(rev_a)) stack_push(result, stack_pop(rev_a));
    while (!stack_is_empty(rev_b)) stack_push(result, stack_pop(rev_b));

    stack_destroy(rev_a);
    stack_destroy(rev_b);

    return result;
}
