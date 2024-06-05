#define SIZE 4

unsigned int nondet_int();

int main() {
    int matrice_incidenza[SIZE][SIZE] = {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0}
    };

    int matrice_archi[SIZE][SIZE] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };


    // Verificare se è connesso
    int nodo_check = nondet_int();
    __CPROVER_assume(nodo_check >= 0 && nodo_check < SIZE);
    int contatore = 0;
    for(int i = 0; i < SIZE; i ++)
    {
        if (matrice_incidenza[nodo_check][i] == 1)
        {
            contatore++;
        }
    }
    __CPROVER_assume(contatore != 0);


    int vettore_gradi[SIZE] = {0,0,0,0};
    // Verificare se tutti i nodi sono di grado pari
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            vettore_gradi[i] += matrice_incidenza[i][j];
        }
    }


    for(int i = 0; i < SIZE; i++)
    {
        if(vettore_gradi[i] % 2 != 0)
        {
            assert(0);
        }
    }

    //assert(0);

    int nodo_successivo = 0;
    int nodo_corrente = nondet_int();
    __CPROVER_assume(nodo_corrente >= 0 && nodo_corrente < SIZE);

    for(int i = 0; i < SIZE; i++)
    {
        if(matrice_incidenza[nodo_corrente][i] == 1)
        {
           matrice_archi[nodo_corrente][i] = 1;
           nodo_corrente = i;
        }

    }


    int contatore_archi = 0;







}