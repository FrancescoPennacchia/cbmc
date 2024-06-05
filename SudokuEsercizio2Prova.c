#include<stdbool.h>
#define SIZE 9


unsigned nondet_int();

bool controlloDellaRiga(unsigned int mat[SIZE][SIZE], int value, int rig, int col) {

    for(int i = 0; i < SIZE; i ++){
        if(mat[rig][i] == value){
            return true;
        }
        
    }
    return false;
}



int main () {
    unsigned int matrice[SIZE][SIZE] = {
        {0,0,9,8,0,0,1,0,0},
        {1,6,2,0,7,0,5,0,0},
        {0,3,0,1,2,9,7,0,0},
        {0,2,6,0,8,0,3,0,0},
        {3,4,5,0,0,6,0,0,0},
        {0,0,1,7,4,3,0,0,6},
        {9,1,0,6,5,8,4,0,0},
        {0,0,0,3,0,0,0,0,5},
        {2,0,4,9,0,0,0,8,0}
    };


    __CPROVER_assert(controlloDellaRiga(matrice, 1, 1, 1 ) == 0);


    assert(0);
}