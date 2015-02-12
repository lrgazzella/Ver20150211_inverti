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
    
    studenteStack nuovo;
    nuovo = (studenteStack)malloc(sizeof(stackElement));
    
    if(nuovo != NULL){
        strcpy(nuovo->s.cognome, newStudente.cognome);
        strcpy(nuovo->s.nome, newStudente.nome);
        
        nuovo->next = *stack;
        *stack = nuovo;
        
                 
    }else{
        r=-1;
    }
    
    return r;
}

/*
 * Estrae un elemento dalla pila, rimuovendolo.
 * Restituisce l'elemento estratto.
 * Se la pila è vuota, l'elemento restituito ha nome e cognome di lunghezza 0.
 */
studente pop(studenteStack *stack) {
    studente r;
    
    
   stackElement * ultimo = NULL;
    
    if(*stack != NULL){
        r = (*stack)->s;
        
        ultimo = *stack;
        *stack = (*stack)->next;
        free(ultimo);
    }
    
    
    return r;
}