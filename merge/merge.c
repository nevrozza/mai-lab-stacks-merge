#include "merge.h"

#include <time.h>

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

// sry for inplace =/
void merge_sort_stack(stack *s) {
    if (stack_size(s) <= 1) {
        return;
    }

    size_t n = stack_size(s);
    size_t mid = n / 2;

    stack *left = stack_create();
    stack *right = stack_create();
    stack *temp = stack_create();

    // [1, 2, 3, 4] <- вершина
    // [1, 2, 3, 4] -> [4, 3, 2, 1]
    for (size_t i = 0; i < n; i++) {
        stack_push(temp, stack_pop(s));
    }

    // [4, 3, 2, 1] <- вершина
    // left=[1, 2] right=[3, 4]
    for (size_t i = 0; i < mid; i++) {
        stack_push(left, stack_pop(temp));
    }
    for (size_t i = mid; i < n; i++) {
        stack_push(right, stack_pop(temp));
    }
    stack_destroy(temp);


    merge_sort_stack(left);
    merge_sort_stack(right);


    stack *sorted = merge_sorted_stacks(left, right);

    stack *tmp = stack_create();
    while (!stack_is_empty(s)) stack_pop(s);
    while (!stack_is_empty(sorted)) { stack_push(tmp, stack_pop(sorted)); }
    while (!stack_is_empty(tmp)) { stack_push(s, stack_pop(sorted)); }

    stack_destroy(left);
    stack_destroy(right);
    stack_destroy(sorted);
    stack_destroy(tmp);
}
