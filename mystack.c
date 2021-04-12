// ===================================================================
// mystack.c (Stack realisiert mit dynamischen Array)
// ===================================================================

#include <stdlib.h>
#include "mystack.h"
#include <stdio.h>

// ===================================================================
struct mystack_s {
    /// Größe des Arrays
    int size;
    /// Speichert einen Fehler-Code für die zuletzt ausgeführte Operation
    char error;
    /// Indexstelle
    int next;
    /// Float Array mit Werten
    float* values;
};


// erzeugt einen leeren Stack
mystack_t *createStack(){
    mystack_t* s;

    s = (mystack_t *)calloc(1,sizeof(mystack_t)); // Manuelle Speicherreservierung (muss freigegeben werden)
     s-> size=8;
     s ->next= 0;
     s -> error= 0 ;
     s -> values = ( float* ) calloc( 8, sizeof (float)); // Manuelle Speicherreservierung (muss freigegeben werden)
     return s;
}

// prüft, ob der Stack s leer ist
char isEmpty(mystack_t *stack){
    if ( stack -> next == 0)
        return 1;
    else {
        return 0;
    }
}

// verdoppelt Speicherbereich und kopiert auf s
void increase(mystack_t* stack){
    stack->size = stack->size * 2;
    stack->values = (float*)realloc(stack->values, stack->size * sizeof(float));
}

// prüft ob der Stack s leer ist
char isFull(mystack_t* stack){
    if(stack->next == stack->size){
        return 1;
    } else {
        return 0;
    }
}

// legt den Wert value auf den Stack s
void push(mystack_t *stack, float value){
    if(isFull(stack)){
        increase(stack);
    }
     stack -> values[stack->next] = value;
     stack -> next++;
}

// liefert das zuletzt eingefügte Element des Stacks s
float top(mystack_t *stack){
    if (isEmpty(stack)) {
        stack -> error = EMPTY_STACK;
        printf("Kann top() nicht auf Leeren Stack anwenden\n");
        return 0;
    }
    return stack->values[stack->next-1];
}

// liefert und entfernt das zuletzt eingefügte Element vom Stack s
float pop(mystack_t *stack){
      if (isEmpty(stack)) {                     // Wenn Array leer ist
          stack -> error = EMPTY_STACK;         // setze error = 1
          printf("Kann pop() nicht auf Leeren Stack anwenden\n");
          return 0;                             // springe aus der Funktion raus
      }
      stack->next--;
      return stack->values[stack->next];
}

// liefert den Inhalt der Fehlervariablen
char getError(mystack_t *stack){
     return stack -> error;
}

// zerstört den Stack und gibt belegten Speicherplatz frei
void destroyStack(mystack_t *stack){
    free( stack -> values); // Muss freigegeben werden weil in Zeile 29 Speicher reserviert wurde
     free( stack); // Muss freigegeben werden weil in Zeile 25 Speicher reserviert wurde
}