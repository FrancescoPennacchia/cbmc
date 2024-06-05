
int nondet_int();
int i, j;
/*
Somma dei numeri da 1 a 9 = 45.
Ed almeno due uguali.
*/

int main()
{


    int array[9];
    int somma = 0;

    for(int k =0; k < 9; k++) 
    {
        array[k] = nondet_int();
        __CPROVER_assume(array[k] > 0 && array[k] <= 9);
    }

    for(int k=0; k < 9; k++) 
    {
        somma = somma + array[k];
    }


    i = nondet_int();
    __CPROVER_assume(i >= 0 && i < 9);

    j = nondet_int();
    __CPROVER_assume(j >=  0 && j < 9);

    __CPROVER_assume( i != j);

    __CPROVER_assume(array[i] != array[j]);

    __CPROVER_assume( somma == 45);



    assert(0);

} 