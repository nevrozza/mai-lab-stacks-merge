//
// Created by nevrozq on 25.12.2025.
//

#ifndef MERGE_H
#define MERGE_H
#include "../stack/stack.h"

stack *stack_clone(stack *s);

stack *merge_sorted_stacks(stack *s1, stack *s2);
#endif //MERGE_H
