//
// Created by franc on 28/05/2024.
//
#define MAX 4

int matrice_incidenza[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
};

int matrice_matching_unico[MAX][MAX] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
};

int colori[MAX] = {0, 0, 0, 0};

int nondet_int();

int main()
{
    //Assegnamento colori
    for (int i = 0; i < MAX; i++) {
        colori[i] = nondet_int();
        __CPROVER_assume(colori[i] == 0 || colori[i] == 1);
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (matrice_incidenza[i][j] == 1) {
                __CPROVER_assume(colori[i] != colori[j]);
            }
        }
    }

    //Matching unico
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(matrice_incidenza[i][j] == 1)
            {
                if(colori[i] != colori[j])
                {
                    matrice_matching_unico[i][j] = 1;
                }
            }
        }
    }




    assert(0);
    return 0;
}