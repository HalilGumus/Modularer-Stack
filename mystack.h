// -------------------------------------------------------------------
// mystack.h
// -------------------------------------------------------------------

#ifndef _MYSTACK_H
#define _MYSTACK_H

// Konstanten --------------------------------------------------------
#define OK                0
#define EMPTY_STACK       3
#define ALLOC_ERROR      12

// Vorwärtsdeklaration (unvollständiger Datentyp) --------------------
typedef struct mystack_s mystack_t;

// Schnittstelle (Interface) -----------------------------------------
// erzeugt einen leeren Stack
mystack_t *createStack();
// prüft, ob der Stack s leer ist
char isEmpty(mystack_t *stack);
// legt den Wert value auf den Stack s
void push(mystack_t *stack, float value);
// liefert das zuletzt eingefügte Element des Stacks s
float top(mystack_t *stack);
// entfernt das zuletzt eingefügte Element vom Stack s
float pop(mystack_t *stack);
// liefert den Inhalt der Fehlervariablen
char getError(mystack_t *stack);
// zerstört den Stack und gibt belegten Speicherplatz frei
void destroyStack(mystack_t *stack);

#endif

