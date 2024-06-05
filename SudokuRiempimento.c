//#include<stdbool.h>

#define DIM 9

unsigned int nondet_int();

/* Inserisce i valori nella matrice */
void inserisciMatrice(int matrice[DIM][DIM])
{
    for(int i = 0; i < DIM; i++)
		for(int j = 0; j < DIM; j++)
            if(matrice[i][j] == 0)
            {
                matrice[i][j] = nondet_int();
                __CPROVER_assume(matrice[i][j] >= 1 && matrice[i][j] <= 9);
                //__CPROVER_assume(controlloRigheColonne(matrice, i, j) == 0);
                __CPROVER_assume(controlloSottoMatrice(matrice, i, j, matrice[i][j]) == 0);
            }
}

/* Cotrollo di righe e colonne Funzionante*/
int controlloRigheColonne(unsigned int matrice[DIM][DIM], int row, int col)
{  
    /* Controllo per Colonna */
    for(int i = 0; i < DIM; i++)
    	if(matrice[row][i] == matrice[row][col] && i != col)
    		return 1;

    /* Controllo per riga */
    for(int j = 0; j < DIM; j++)
        if(matrice[j][col] == matrice[row][col] && j != row)
            return 1;

    return 0;
}

/* Controllo della sottomatrice quadrata 3 x 3 */
int controlloSottoMatrice(unsigned int matrice[DIM][DIM], int row, int col, int x)
{
    int r = row - ( row % 3);
    int c = col - ( col % 3);

    for(int i = r; i < r + 3; i++)
    	for (int j = c; j < c + 3; j++)
    		if(matrice[i][j] == x && i != row && j != col)
    			return 1;

    return 0;
}

int main()
{
    unsigned int matrice[DIM][DIM] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 2},
        {7, 0, 0, 0, 2, 0, 0, 0, 1},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 6}
    }; 

    inserisciMatrice(matrice);

    assert(0);
}