int main(void) {
    int nondet_int();
    int array[9];
    int somma = 0;

    for(int i=0; i < 9; i++) {
        array[i] = nondet_int();
        __CPROVER_assume(array[i] > 0 && array[i] <= 9);
    }

    for(int i=0; i < 9; i++) {
        somma = somma + array[i];
    }

    __CPROVER_assume(somma == 45);
    __CPROVER_assume(array[0] != array[1]);

    assert(0);
}