#define size 4
#define clique_size 3

//Verificare esistenza clique
int nondet_int();

int main()
{
    int matrice_incidenza[size][size] =
    {
        {0,1,1,1},
        {1,0,0,1},
        {1,0,0,1}, 
        {1,1,1,0}
    };

    int nodi[clique_size] = {0,1,3};

    /*
    unsigned int nodi[clique_size];
    for(int i = 0; i < clique_size; i++){
           nodi[i] = nondet_int();
           __CPROVER_assume(nodi[i] >= 0 && nodi[i] < size);
    }
    */


    //assert(0);


    for(int i = 0; i < clique_size; i++){
        for(int j = 0; j < clique_size; j++){
            //__CPROVER_assume(i != j);
            if (i != j)
            {

                assert(matrice_incidenza[i][j] != 1);
                //assert(0);
            }
        }
    }

    assert(0);
}