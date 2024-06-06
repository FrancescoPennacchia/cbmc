//
// Created by franc on 05/06/2024.
//
#define N 5

int matrice_incidenza_pesi[N][N] = {
        {0, 2, 0, 0, 1},
        {2, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {1, 0, 0, 5, 0}
};

unsigned int nondet_int();
unsigned int nodo_start = 0;
unsigned int nodo_arrivo = 4;
unsigned int nodo_corrente = nodo_start;
unsigned int nodo_successivo;
unsigned int somma = 0;

int main()
{
    ordine_nodi_presi[nodo_start] = contatore;

    for(int i = 0; i < N; i++)
    {
        nodo_successivo = nondet_int();
        __CPROVER_assume(nodo_successivo >= 0 && nodo_successivo < N);
        __CPROVER_assume(matrice_incidenza_pesi[nodo_corrente][nodo_successivo] != 0);

        somma = somma + matrice_incidenza_pesi[nodo_corrente][nodo_successivo];
        nodo_corrente = nodo_successivo;

        if(nodo_corrente == nodo_arrivo)
        {
            break;
        }
    }

    assert(somma == 8);
}