#include <stdio.h>
#include <string.h>

#include "merge/merge.h"
#include "stack/stack.h"

data_type stack_append_scanf(stack *s) {
    data_type data;
    scanf("%d", &data.value);
    stack_push(s, data);
    return data;
}

int main(void) {
    stack *s = stack_create();

    while (true) {
        char cmd[10];
        scanf("%s9s", cmd);

        if (strcmp(cmd, "exit") == 0) {
            break;
        } else if (strcmp(cmd, "push") == 0) {
            data_type data = stack_append_scanf(s);
            printf("Pushed %d\n", data.value);
        } else if (strcmp(cmd, "fill") == 0) {
            int n;
            scanf("%d", &n);
            if (n <= 0) {
                printf("N must be positive\n");
            } else {
                for (int i = 1; i <= n; i++) {
                    stack_append_scanf(s);
                }
            }
        } else if (strcmp(cmd, "pop") == 0) {
            if (stack_is_empty(s)) {
                printf("Stack empty\n");
            } else {
                data_type data = stack_pop(s);
                printf("Popped %d\n", data.value);
            }
        } else if (strcmp(cmd, "print") == 0) {
            stack_print(s);
        } else if (strcmp(cmd, "sort") == 0) {
            merge_sort_stack(s);
            printf("Sorted\n");
        } else {
            printf("Unknown command\n");
        }
    }

    stack_destroy(s);
    printf("Bye!\n");

    return 0;
}
