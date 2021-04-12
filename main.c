// ===================================================================
// Arithmetischen Ausdruck (gegeben in UPN) bewerten
// ===================================================================

#include "mystack.h"
#include <stdio.h>

// ===================================================================
int main(void) {
    mystack_t* s;
    s = createStack();

    //Beispiel: Berechnung von 5.1*(((91+28)*(4.3+6))+777) = 10213.77
    //in umgekehrter polnischer Notation:
    //5.1 91 28 + 4.3 6 + * 777 + *

    push(s, 5.1);
    push(s, 91);
    push(s, 28);
    push(s, pop(s)+pop(s));
    push(s, 4.3);
    push(s, 6);
    push(s, pop(s)+pop(s));
    push(s, pop(s)*pop(s));
    push(s, 777);
    push(s, pop(s)+pop(s));
    push(s, pop(s)*pop(s));

    printf("Gleichung: 5.1*(((91+28)*(4.3+6))+777) = 10213.77\n");
    printf("UPN: %f\n", pop(s));

    destroyStack(s);
    return 0;
}