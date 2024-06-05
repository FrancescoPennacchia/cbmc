/* Risolvere un sistema di equazioni lineari 2x2 */
/* Determinare se il determinate è diverso da zero, se uguale a zero non ha soluzioni */
/* Se diverso da zero la soluzione può essere scirtta X = Inversa * B */
/* Metodo Cramer */
/* Oppure potevamo utilizzare il metodo per sostiuzione (Semplice) */

int nondet_int();                        // Quello che sta scritto sotto, possiamo usarlo per nondet_int();
                                         // signed/unsigned __CPROVER_bitvector[n] nome_variabile Per assegnare fino a 5 bit

int coefficienti[2][2];                  // matrice dei coefficienti
int termini_noti[2];                     // matrice colonna dei termini noti
float soluzioni[2];                      // matrice colonna delle incognite
int matrice_complementare[2][2];         // matrice dei complementi algebrici
float matrice_inversa[2][2];             // matrice inversa

int determinante;                        // determinante della matrice

int main() {

    /* Inserimento valori matrice coefficienti */
    for (int i=0; i < 2; i++) {
        for (int j=0; j < 2; j++) {
            coefficienti[i][j] = nondet_int();
            __CPROVER_assume(coefficienti[i][j] >= -20 && coefficienti[i][j] <= 20);
        }
    }

    /* Inserimento termini noti */
    for(int i=0; i < 2; i++) {
        termini_noti[i] = nondet_int();
        __CPROVER_assume(termini_noti[i] >= -20 && termini_noti[i] <= 20);
    }


    /* Calcolo determinante */
    determinante = (coefficienti[0][0] * coefficienti[1][1]) - (coefficienti[0][1] * coefficienti[1][0]);
    __CPROVER_assume(determinante != 0);
    assert( determinante == 0);

    /* Complemento della matrice */
    matrice_complementare[0][0] =       coefficienti[1][1];
    matrice_complementare[0][1] =  -1 * coefficienti[0][1];
    matrice_complementare[1][0] =  -1 * coefficienti[1][0];
    matrice_complementare[1][1] =       coefficienti[0][0];

    /* Inversa Elementi della matrice complementare diviso il determinante */
    for (int i=0; i < 2; i++) {
        for (int j=0; j < 2; j++) {
            matrice_inversa[i][j] = matrice_complementare[i][j] / determinante;
        }
    }

    /* Calcolo delle soluzioni */
    for (int i=0; i < 2; i++) {
        for (int j=0; j < 2; j++) {
            soluzioni[i] += matrice_inversa[i][j] * termini_noti[j];
        }
    }



    assert(0);
}