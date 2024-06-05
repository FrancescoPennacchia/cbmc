const int size = 5;
int nondet_int();
int k = 3;


int matrice[5][5]= {
                   {0, 1, 1, 1, 1},
                   {1, 0, 1, 1, 1},
                   {1, 1, 0, 1, 0},
                   {1, 1, 1, 0, 1},
                   {1, 1, 1, 1, 0}
};


int main () 
{
    int i, j;

    i = nondet_int();
    assume(i >= 0 && i <=size);


    j = nondet_int();
    assume(j >= 0 && j<=size);


    k = nondet_int();
    assume(k >= 0 && k<=size);

    assume( i !=0 && j !=0);



    assert(matrice[i][j] == 1 && matrice[i][k] == 1 && matrice[k][j] == 1);


}