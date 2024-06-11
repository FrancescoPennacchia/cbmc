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
                __CPROVER_assume(controlloRigheColonne(matrice, i, j) == 0);
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
            { {3, 0, 2, 6, 0, 0, 9, 0, 1},
              {0, 0, 0, 9, 1, 0, 0, 0, 2},
              {0, 9, 0, 0, 5, 4, 0, 0, 8},
              {0, 2, 0, 0, 4, 5, 8, 1, 7},
              {8, 5, 0, 7, 0, 0, 3, 0, 0},
              {4, 0, 0, 0, 0, 0, 2, 6, 5},
              {6, 0, 5, 0, 0, 9, 0, 2, 0},
              {0, 3, 0, 0, 0, 2, 5, 0, 0},
              {0, 0, 9, 5, 0, 8, 0, 4, 6} };

    unsigned int matrice_vuota[DIM][DIM];

    inserisciMatrice(matrice);

    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            matrice_vuota[i][j] = matrice[i][j];


    assert(0);
}