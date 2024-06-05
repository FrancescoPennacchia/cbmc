#include <stdio.h>
#define N 5

unsigned int nondet_int();


int main()
{
    int next_i = 0;
    int next_j = 0;
    int current_i = 0;
    int current_j = 0;

    int matrix_path[N][N] = {
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    /*
    int matrix_path[N][N] = {
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}

    */

    int matrix_obstacle[N][N] = {
        {0, 0, 1, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0}
    };


    //Test current_i != N - 1 && current_j != N - 1
    while (1) {
        next_i = nondet_int();
        __CPROVER_assume(next_i >= 0 && next_i < N );
        next_j = nondet_int();
        __CPROVER_assume(next_j >= 0 && next_j < N );


        __CPROVER_assume(next_i == current_i +1 || next_i == current_i - 1 || next_i == current_i);
        __CPROVER_assume(next_j == current_j +1 || next_j == current_j - 1 || next_j == current_j);
        __CPROVER_assume(next_i != current_i || next_j != current_j);
        __CPROVER_assume(matrix_obstacle[next_i][next_j] == 0 && matrix_path[next_i][next_j] == 0);
        matrix_path[next_i][next_j] = 1;

        current_i = next_i;
        current_j = next_j;

        assert(!(current_i == N - 1 && current_j == N - 1));
    } 

    //assert(0);
}


