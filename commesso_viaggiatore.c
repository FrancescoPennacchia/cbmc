//
// Created by franc on 18/06/2024.
//
#define N 4

unsigned int nondet_int();

unsigned int matrice_incidenza_pesi[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
};

unsigned int nodi_visitati[N] = {0, 0, 0, 0};
unsigned int nodo_start = 0;
unsigned int somma = 0;
unsigned int minimo_greedy = 0;
unsigned int nodo_corrente = 0;
unsigned int nodo_successivo = 0;


int distanza_minima(int nodo_corrente){
    int min = 1000;
    int nodo_minimo;

    for(int j = 0; j < N; j++){
        if(matrice_incidenza_pesi[nodo_corrente][j] < min && matrice_incidenza_pesi[nodo_corrente][j] != 0){
            min = matrice_incidenza_pesi[nodo_corrente][j];
            nodo_minimo = j;
        }
    }
    return nodo_minimo;
}

int cammino_minimo(int nodo_corrente){
    int nodo_successivo = distanza_minima(nodo_corrente);
    somma = somma + matrice_incidenza_pesi[nodo_corrente][nodo_successivo];
    nodi_visitati[nodo_successivo] = 1;
    nodo_corrente = nodo_successivo;

    if(nodo_corrente == nodo_start){
        return somma;
    }
    else{
        cammino_minimo(nodo_corrente);
    }
}

/*
 * Soluzione chat GPT
 *
int distanza_minima(int nodo_corrente) {
    int min = INF;
    int nodo_minimo = -1;

    for (int j = 0; j < N; j++) {
        if (matrice_incidenza_pesi[nodo_corrente][j] < min && matrice_incidenza_pesi[nodo_corrente][j] != 0 && nodi_visitati[j] == 0) {
            min = matrice_incidenza_pesi[nodo_corrente][j];
            nodo_minimo = j;
        }
    }
    return nodo_minimo;
}

int cammino_minimo(int nodo_corrente) {
    nodi_visitati[nodo_corrente] = 1;
    int nodo_successivo = distanza_minima(nodo_corrente);

    if (nodo_successivo == -1) {
        // Se non ci sono più nodi visitabili, ritorna a nodo_start
        somma += matrice_incidenza_pesi[nodo_corrente][nodo_start];
        return somma;
    }

    somma += matrice_incidenza_pesi[nodo_corrente][nodo_successivo];
    nodo_corrente = nodo_successivo;

    if (nodo_corrente == nodo_start) {
        return somma;
    } else {
        return cammino_minimo(nodo_corrente);
    }
}

 */

int main() {
    nodi_visitati[nodo_start] = 1;
    nodo_corrente = nodo_start;

    minimo_greedy = cammino_minimo(nodo_corrente);

/*
    for(int i = 0; i < N; i++){
        nodo_successivo = nondet_int();
        __CPROVER_assume(nodo_successivo >= 0 && nodo_successivo < N);
        __CPROVER_assume(matrice_incidenza_pesi[nodo_corrente][nodo_successivo] != 0);

        somma = somma + matrice_incidenza_pesi[nodo_corrente][nodo_successivo];
        nodi_visitati[nodo_successivo] = nodi_visitati[nodo_successivo] + 1;

        if(nodo_corrente == nodo_start){
            break;
        }

        nodo_corrente = nodo_successivo;

    }



    for(int i = 0; i < N; i++){
        if(i != nodo_start){
            __CPROVER_assume(nodi_visitati[i] == 1);
        } else {
            __CPROVER_assume(nodi_visitati[i] == 2);
        }
    }*/

    __CPROVER_assume(somma == minimo_greedy);
    assert(0);

}