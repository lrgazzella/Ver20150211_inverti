#include <stdio.h>
#include <stdlib.h>
#include "studenteStack.h"

const char fname[]="studenti.dat";

int main(int argc, char** argv) {
    FILE *inputFile;
    studente s;
    stackElement *stack=NULL;
    int returnValue;
    
    // Apertura del file di lettura dati
    inputFile = fopen(fname, "rb");
    if(inputFile == NULL) {
        fprintf(stderr, "Impossibile aprire il file %s in lettura\n", fname);
        exit(-1);
    }
    
    // Aggiunta degli elementi alla pila
    while(fread(&s, sizeof(studente), 1, inputFile) == 1) {
        returnValue = push(&stack, s);
        if(returnValue != 0) {
            fprintf(stderr, "Si e' verificato un errore nell'aggiunta di un nuovo elemento.\n");
            exit(-1);
        }
    }
    fclose(inputFile);
    
    // Estrazione degli elementi dalla pila e stampa a schermo
    s = pop(&stack);
    while(s.cognome[0] != 0) {
        printf("%s; %s\n", s.cognome, s.nome);
        s = pop(&stack);
    }
    
    return (EXIT_SUCCESS);
}

