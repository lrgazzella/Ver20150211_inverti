#include <stdlib.h>
#include <string.h>
#include "studenteStack.h"

/*
 * Aggiunge un nuovo elemento alla pila.
 * Restituisce:
 *  0   in caso di successo;
 *  -1  in caso di errore;
 */
int push(studenteStack *stack, studente newStudente) {
    int r=0;
    
    stackElement *newElement;
    
    newElement = (stackElement *)malloc(sizeof(stackElement));
    if(newElement != NULL) {
        newElement->s = newStudente;
//        strcpy(newElement->s.nome, newStudente.nome);
//        strcpy(newElement->s.cognome, newStudente.cognome);
        newElement->next = *stack;
        *stack = newElement;
    }
    else
        r = -1;
    
    return r;
}

/*
 * Estrae un elemento dalla pila, rimuovendolo.
 * Restituisce l'elemento estratto.
 * Se la pila è vuota, l'elemento restituito ha nome e cognome di lunghezza 0.
 */
studente pop(studenteStack *stack) {
    studente r;
    stackElement *temp;
    
    r.cognome[0]=0; // Set cognome to empty string, in case of empty stack
    r.nome[0]=0;    // Set nome to empty string, in case of empty stack

    if(*stack != NULL) {
        r = (*stack)->s;
//        strcpy(r.nome, (*stack)->s.nome);
//        strcpy(r.cognome, (*stack)->s.cognome);
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    
    return r;
}