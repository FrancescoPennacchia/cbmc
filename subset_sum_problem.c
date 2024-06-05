//
// Created by franc on 31/05/2024.
//
#define SIZE 6
#define SIZE_SUBSET 3

int nondet_int();

int insieme_s[SIZE] = {3, 34, 4, 12, 5, 2};

int sottoinsieme_s[3] = {0, 0, 0};

int valori_selezionati[SIZE] = {0, 0, 0, 0, 0, 0};

int valore = 9;
int somma = 0;
int selezione = 0;

int main() {

    for(int i = 0; i < SIZE_SUBSET; i++) {
        selezione = nondet_int();
        __CPROVER_assume(selezione >= 0 && selezione < SIZE);

        if(valori_selezionati[selezione] == 0) {
            valori_selezionati[selezione] = 1;
            sottoinsieme_s[i] = insieme_s[selezione];
        }
    }

    for(int i = 0; i < SIZE_SUBSET; i++) {
        somma = somma + sottoinsieme_s[i];
    }

    assert(somma == valore);
}