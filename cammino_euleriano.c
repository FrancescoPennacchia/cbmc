#define N 4

unsigned int nondet_int();

int main()
{
    int matrice_incidenza[N][N] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int matrice_archi_visitati[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    int vettore_grado_nodi[N] = {0, 0, 0, 0};

    // Verifichiamo se la matrice ha i nodi di grado pari
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(matrice_incidenza[i][j] == 1)
            {
                vettore_grado_nodi[i]++;
            }
        }
    }


    for (int i = 0; i < N; i++)
    {
       assert(vettore_grado_nodi[i] % 2 != 0);
    }


    int nodo_corrente = nondet_int();
    __CPROVER_assume(nodo_corrente >= 0 && nodo_corrente < N);

    for(int i = 0; i < N; i++)
    {
        int nodo_successivo = nondet_int();
        __CPROVER_assume(nodo_successivo >= 0 && nodo_successivo < N);
        __CPOVER_assume(matrice_incidenza[nodo_corrente][nodo_successivo] == 1);


        __CPROVER_assume(matrice_archi_visitati[nodo_corrente][nodo_successivo] == 0);
        __CPROVER_assume(matrice_archi_visitati[nodo_successivo][nodo_corrente] == 0);

        if(matrice_incidenza[nodo_corrente][nodo_successivo] == 1)
        {

            matrice_archi_visitati[nodo_corrente][nodo_successivo] = 1;
            nodo_corrente = nodo_successivo;
        }
    }

    int cont_archi_incidenza = 0;
    int cont_archi_visitati = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            cont_archi_incidenza = cont_archi_incidenza + matrice_incidenza[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            cont_archi_visitati = cont_archi_visitati + matrice_archi_visitati[i][j];
        }
    }

    assert(!(cont_archi_visitati == cont_archi_incidenza / 2));

}