//
// Created by franc on 31/05/2024.
//
#define MAX 4

int nondet_int();

int matrice_incidenza[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
};

int vertici[MAX] = {0, 0, 0, 0};

int nodo_corrente = 0;
int nodo_successivo = 0;
int nodo_start = 0;

int main()
{
    nodo_corrente = nondet_int();
    __CPROVER_assume(nodo_corrente >= 0 && nodo_corrente < MAX);
    vertici[nodo_corrente] = 1;
    nodo_start = nodo_corrente;

    for (int i = 0; i < MAX; i++) {
        nodo_successivo = nondet_int();
        __CPROVER_assume(nodo_successivo >= 0 && nodo_successivo < MAX);
        __CPROVER_assume(nodo_successivo != nodo_corrente);
        __CPROVER_assume(matrice_incidenza[nodo_corrente][nodo_successivo] == 1);
        vertici[nodo_successivo] = vertici[nodo_successivo] + 1;
        nodo_corrente = nodo_successivo;
    }

    for(int i = 0; i < MAX; i++)
    {
        if (i != nodo_start) {
            __CPROVER_assume(vertici[i] == 1);
        } else {
            __CPROVER_assume(vertici[i] == 2);
        }
    }

    assert(0);
}