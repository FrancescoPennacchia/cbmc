#define N 4

unsigned int nondet_int();

int main()  
{
    int vettore_visite[N] = {0, 0, 0, 0};

    int matrice_incidenza[N][N] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };


    int nodo_corrente = nondet_int();
    __CPROVER_assume(nodo_corrente >= 0 && nodo_corrente < N);
    vettore_visite[nodo_corrente] = 1;

    for(int i = 0; i < N; i++)
    {
        int nodo_successivo = nondet_int();
        __CPROVER_assume(nodo_successivo >= 0 && nodo_successivo < N);
        __CPOVER_assume(matrice_incidenza[nodo_corrente][nodo_successivo] == 1);


        if(matrice_incidenza[nodo_corrente][nodo_successivo] == 1)
        {
            vettore_visite[nodo_successivo] = vettore_visite[nodo_successivo] + 1;
            nodo_corrente = nodo_successivo;
        }
    }

    assert(!(vettore_visite[0] == 2 && vettore_visite[1] == 1 && vettore_visite[2] == 1 && vettore_visite[3] == 1));
}