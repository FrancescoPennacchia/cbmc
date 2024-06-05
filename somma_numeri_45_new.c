
unsigned nondet_int();
//Ok Somma dei numeri da 1 a 9 = 45. E tutti diversi.
int main() {
    int vettore[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int k,j = 0;
    int somma = 0;
    int vet_appo[9];

    for(int i = 0; i < 9; i++) {
        vettore[i] = nondet_int();
        __CPROVER_assume(vettore[i] > 0 && vettore[i] <= 9);

        for(int j = 0; j < 9; j++) {
            if (i != j){
                __CPROVER_assume(vettore[j] != vettore[i]);
            }
        }
       
    }
    assert(9);
    for(int i = 0; i < 9; i++) {
        somma = somma + vettore[i];
    }

    for(int i = 0; i < 9; i++) {
        vet_appo[i] = vettore[i];
    }

    assert(!(somma == 45));

}