#define N 8
int nondet_int();


int check_main_diagonal(int *matrix[N][N], int row, int col) {
    int i, j;

    // Controllo verso l'alto e verso destra
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (matrix[i][j] == 1) {
            return 1; // C'è una regina sulla diagonale principale
        }
    }

    // Controllo verso il basso e verso la sinistra
    for (i = row + 1, j = col + 1; i < N && j < N; i++, j++) {
        if (matrix[i][j] == 1) {
            return 1; // C'è una regina sulla diagonale principale
        }
    }

    return 0; // Nessuna regina sulla diagonale principale
}

// Funzione per controllare la diagonale secondaria (dal basso a destra verso l'alto a sinistra)
int check_secondary_diagonal(int *matrix[N][N], int row, int col) {
    int i, j;

    // Controllo verso l'alto e verso sinistra
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (matrix[i][j] == 1) {
            return 1; // C'è una regina sulla diagonale secondaria
        }
    }

    // Controllo verso il basso e verso destra
    for (i = row + 1, j = col - 1; i < N && j >= 0; i++, j--) {
        if (matrix[i][j] == 1) {
            return 1; // C'è una regina sulla diagonale secondaria
        }
    }

    return 0; // Nessuna regina sulla diagonale secondaria
}

// Funzione per controllare se una regina minaccia un'altra regina sulla diagonale
int check_diagonals(int *matrix[N][N], int row, int col) {
    if (check_main_diagonal(&matrix, row, col) || check_secondary_diagonal(&matrix, row, col)) {
        return 1; // Una regina minaccia l'altra sulla diagonale
    } else {
        return 0; // Le regine sono al sicuro sulla diagonale
    }
}


int main() {
    int n_regine = 8;
    int cont_regine = 0;

    int matrice_posizione_regine [8][8] = 
    {
        (0,0,0,0,0,0,0,0),
        (0,0,0,0,0,0,0,0),
        (0,0,0,0,0,0,0,0),
        (0,0,0,0,0,0,0,0),
        (0,0,0,0,0,0,0,0),
        (0,0,0,0,0,0,0,0),
        (0,0,0,0,0,0,0,0),
        (0,0,0,0,0,0,0,0)
    };


    for(int y = 0; y < 8; y++) 
    {
        int i = nondet_int();
        __CPROVER_assume(i >= 0 && i < 8);
        int j = nondet_int();
        __CPROVER_assume(j >= 0 && j < 8);

        //Riga
        __CPROVER_assume(matrice_posizione_regine[0][j] == 0 && matrice_posizione_regine[1][j] == 0 && matrice_posizione_regine[2][j] == 0 && matrice_posizione_regine[3][j] == 0 && matrice_posizione_regine[4][j] == 0 && matrice_posizione_regine[5][j] == 0 && matrice_posizione_regine[6][j] == 0 && matrice_posizione_regine[7][j] == 0);
        //Colonna
        __CPROVER_assume(matrice_posizione_regine[i][0] == 0 && matrice_posizione_regine[i][1] == 0 && matrice_posizione_regine[i][2] == 0 && matrice_posizione_regine[i][3] == 0 && matrice_posizione_regine[i][4] == 0 && matrice_posizione_regine[i][5] == 0 && matrice_posizione_regine[i][6] == 0 && matrice_posizione_regine[i][7] == 0);
        //Diagonale
        __CPROVER_assume(check_diagonals(&matrice_posizione_regine, i, j) == 0);
        matrice_posizione_regine[i][j] = 1;

        cont_regine = cont_regine + 1;

    }
    assert(!(cont_regine == 8));

}