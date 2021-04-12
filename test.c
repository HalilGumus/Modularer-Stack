// ===================================================================
// test.c
// ===================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystack.h"

// ===================================================================
char test01(void) {
    char res;
    mystack_t *s;

    s = createStack();
    if (isEmpty(s))
        res = OK;
    else res = !OK;

    destroyStack(s);
    return res;
}

// ===================================================================
char test02(void) {
    char res = OK;
    float v[] = {1.25, 1.5, 1.75, 2.0};
    mystack_t *s;

    s = createStack();
    for (int i = 0; i < 4; i++)
        push(s, v[i]);

    if (isEmpty(s))
        res = !OK;

    for (int i = 3; res == OK && i >= 0; i--) {
        float val = top(s);
        if (val != v[i])
            res = !OK;
        else pop(s);
    }

    destroyStack(s);
    return res;
}

// ===================================================================
char test03(void) {
    char res = OK;
    float val = 1.0;
    mystack_t *s;

    s = createStack();
    for (int i = 0; i < 40; i++, val += 0.25)
        push(s, val);

    if (isEmpty(s))
        res = !OK;

    val -= 0.25;
    for (int i = 39; res == OK && i >= 0; i--, val -= 0.25) {
        float v = top(s);
        if (v != val)
            res = !OK;
        else pop(s);
    }

    destroyStack(s);
    return res;
}

// ===================================================================
int main(void) {

    if (test01() == OK)
        printf("test01 passed\n");
    else printf("!!! test01 failed !!!\n");

    if (test02() == OK)
        printf("test02 passed\n");
    else printf("!!! test02 failed !!!\n");

    if (test03() == OK)
        printf("test03 passed\n");
    else printf("!!! test03 failed !!!\n");

    return 0;
}

