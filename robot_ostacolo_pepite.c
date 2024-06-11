//
// Created by franc on 11/06/2024.
//

// Evitare ostacoli, il numero di pepite raccolte deve essere pari, deve arrivare al traguardo in al più nxn mosse
#define N 5

unsigned int nondet_int();

int next_i = 0;
int next_j = 0;
int current_i = 0;
int current_j = 0;

int contatore_pepite;

char matrix_path[N][N] = {
        {'-', '-', '-', '-', '-'},
        {'-', 'x', '-', 'x', '-'},
        {'p', '-', 'p', '-', '-'},
        {'-', '-', 'x', 'p', '-'},
        {'-', 'p', '-', 'p', '-'}
};


int main() {

    while(current_i != N  && current_j != N)
    {
        next_i = nondet_int();
        __CPROVER_assume(next_i >= 0 && next_i <= N);
        __CPROVER_assume(next_i == current_i + 1 || next_i == current_i - 1 || next_i == current_i);

        next_j = nondet_int();
        __CPROVER_assume(next_j >= 0 && next_j <= N);
        __CPROVER_assume(next_j == current_j + 1 || next_j == current_j - 1 || next_j == current_j);

        __CPROVER_assume(matrix_path[next_i][next_j] != 'x');

        if(matrix_path[next_i][next_j] == 'p')
        {
            contatore_pepite = contatore_pepite + 1;
            matrix_path[next_i][next_j] = '-';
        }

        current_i = next_i;
        current_j = next_j;


    }

    __CPROVER_assume(contatore_pepite % 2 == 0);

    assert((current_i == N - 1 && current_j == N - 1));
    //assert(0);
}