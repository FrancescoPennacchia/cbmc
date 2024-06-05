
unsigned int nondet_int();

#define SIZE 3

//Controllo riga
int checkRow(char matrice[SIZE][SIZE], char player, int row){
    int cont = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (matrice[row][i] == player)
        {
            cont = cont + 1;
        }
    }
    if (cont == 3)
    {
        return 1;
    }

    return 0; 
}

//Controllo colonna
int checkCol(char matrice[SIZE][SIZE], char player, int col){
    int cont = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (matrice[i][col] == player)
        {
            cont = cont + 1;
        }
    }
    if (cont == 3)
    {
        return 1;
    }

    return 0; 
}

//Controllo diagonale
int checkDiag(char matrice[SIZE][SIZE], char player){
    int cont = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (matrice[i][i] == player)
        {
            cont = cont + 1;
        }
    }
    if (cont == 3)
    {
        return 1;
    }

    cont = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (matrice[i][SIZE - i - 1] == player)
        {
            cont = cont + 1;
        }
    }

    if (cont == 3)
    {
        return 1;
    }

    return 0; 
}

//Controllo vittoria


int main() 
{
    char matrice_tris[SIZE][SIZE] = 
    {
        {'x', 'o', 'x'},
        {'o', 'x', 'o'},
        {'x', 'o', 'x'}
    };


    assert(checkDiag(matrice_tris, 'x') == 1);

    
}