#define SIZE 6

unsigned int nondet_int();

int main()
{
    unsigned int matrice[SIZE][SIZE] = 
    {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}       
    };

    unsigned int colori[SIZE]; // 0 = rosso, 1 = verde, 2 = blu (Che vengono asegnati al nodo i-eseimo)

    for(int i = 0; i < SIZE; i++)
    {
        colori[i] = nondet_int();
        __CPROVER_assume(colori[i] >= 0 && colori[i] < 3);
    }

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(matrice[i][j] == 1)
            {
                 __CPROVER_assume(colori[i] != colori[j]);
            }
        }
    }

    assert(0);
}
