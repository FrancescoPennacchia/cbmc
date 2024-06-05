//
// Created by franc on 31/05/2024.
//
#define SIZE 3

// Variabili
char nondet_char();
int nondet_int();
char player = '-';
char matrice_tris[SIZE][SIZE] = { {'-', '-', '-'},
                                  {'-', '-', '-'},
                                  {'-', '-', '-'} };
int i = 0;
int j = 0;

int main()
{
    // Determino il player iniziale
    player = nondet_char();
    __CPROVER_assume(player == 'A' || player == 'B');

    // Assegno valori alla matrice tris
    for(int r = 0; r < SIZE * SIZE; r++) {
        i = nondet_int();
        __CPROVER_assume(i >= 0 && i < SIZE);
        j = nondet_int();
        __CPROVER_assume(j >= 0 && j < SIZE);


        if (matrice_tris[i][j] == '-') {
            if(player == 'A') {
                matrice_tris[i][j] = 'X';
            } else {
                matrice_tris[i][j] = 'O';
            }
        }

        if( player == 'A'){
            player = 'B';
        } else {
            player = 'A';
        }
    }

    //Verifico se sono stati assegnati tutti i valori della matrice tris
    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
          __CPROVER_assume(matrice_tris[r][c] != '-');
        }
    }


    //Controllo vittoria
    __CPROVER_assume(
        (matrice_tris[0][0] == 'X' && matrice_tris[0][1] == 'X' && matrice_tris[0][2] == 'X') ||
        (matrice_tris[1][0] == 'X' && matrice_tris[1][1] == 'X' && matrice_tris[1][2] == 'X') ||
        (matrice_tris[2][0] == 'X' && matrice_tris[2][1] == 'X' && matrice_tris[2][2] == 'X') ||
        (matrice_tris[0][0] == 'X' && matrice_tris[1][1] == 'X' && matrice_tris[2][2] == 'X') ||
        (matrice_tris[0][2] == 'X' && matrice_tris[1][1] == 'X' && matrice_tris[2][0] == 'X') ||
        (matrice_tris[0][0] == 'O' && matrice_tris[0][1] == 'O' && matrice_tris[0][2] == 'O') ||
        (matrice_tris[1][0] == 'O' && matrice_tris[1][1] == 'O' && matrice_tris[1][2] == 'O') ||
        (matrice_tris[2][0] == 'O' && matrice_tris[2][1] == 'O' && matrice_tris[2][2] == 'O') ||
        (matrice_tris[0][0] == 'O' && matrice_tris[1][1] == 'O' && matrice_tris[2][2] == 'O') ||
        (matrice_tris[0][2] == 'O' && matrice_tris[1][1] == 'O' && matrice_tris[2][0] == 'O')
    );

    assert(0);
}