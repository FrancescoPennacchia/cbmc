
#define SIZE 9

unsigned int nondet_int();

unsigned int sudoku[SIZE][SIZE] =
        { {3, 0, 2, 6, 0, 0, 9, 0, 1},
          {0, 0, 0, 9, 1, 0, 0, 0, 2},
          {0, 9, 0, 0, 5, 4, 0, 0, 8},
          {0, 2, 0, 0, 4, 5, 8, 1, 7},
          {8, 5, 0, 7, 0, 0, 3, 0, 0},
          {4, 0, 0, 0, 0, 0, 2, 6, 5},
          {6, 0, 5, 0, 0, 9, 0, 2, 0},
          {0, 3, 0, 0, 0, 2, 5, 0, 0},
          {0, 0, 9, 5, 0, 8, 0, 4, 6} };

unsigned int sudoku_vuota[SIZE][SIZE];

int controllaRiga(unsigned int sudoku[SIZE][SIZE], unsigned int row, unsigned int col, unsigned int num) {
    for ( int i = 0; i < SIZE; i++) {
        if (sudoku[row][i] == num && col != i) {
            return 0;
        }
    }


    return 1;
}

 int controllaColonna(unsigned int sudoku[SIZE][SIZE], unsigned int row, unsigned int col, unsigned int num) {
    for ( int i = 0; i < SIZE; i++) {
        if (sudoku[i][col] == num && i != row) {
            return 0;
        }
    }
    return 1;
}

int controllaQuadrato(unsigned int sudoku[SIZE][SIZE], unsigned int row, unsigned int col, unsigned int num) {
     int row_start = row - (row % 3);
     int col_start = col - (col % 3);

    for ( int i = row_start; i < row_start + 3; i++) {
        for ( int j = col_start; j < col_start + 3; j++) {
            if (sudoku[i][j] == num && i != row && j != col) {
                return 0;
            }
        }
    }
    return 1;
}

 int main() {
    // Riempimento
    for ( int i = 0; i < 9; i++) {
        for ( int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {

                sudoku[i][j] = nondet_int();
                __CPROVER_assume(sudoku[i][j] >= 1 && sudoku[i][j] <= 9);
                __CPROVER_assume(controllaRiga(sudoku, i, j, sudoku[i][j]) == 1);
                __CPROVER_assume(controllaColonna(sudoku, i,j, sudoku[i][j]) == 1);
                __CPROVER_assume(controllaQuadrato(sudoku, i, j, sudoku[i][j]) == 1);
            }
        }
    }

    for ( int i = 0; i < 9; i++) {
        for ( int j = 0; j < 9; j++) {
            sudoku_vuota[i][j] = sudoku[i][j];
        }
    }

    assert(0);
}
