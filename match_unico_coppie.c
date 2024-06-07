//
// Created by franc on 07/06/2024.
//
/*
 * Creare due insiemi tramite non dedeterminismo, i nodi che sono in un insieme non possono essere nell'altro
 * Verificare se almeno uno dei due insiemi è 2/3
 * Vedere se esiste un matching unico tra i due insiemi
 */

#define N 4

int matrice_incidenza[N][N] = {
    {0, 1, 0, 1},
    {1, 0, 0, 0},
    {0, 0, 0, 1},
    {1, 0, 1, 0}
};

int matrice_matching[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
};

int nondet_int();
int vettore_sesso[N];
int primo_insieme[N];
int secondo_insieme[N];
int cont = 0;
int k = 0;
int vettore_nodi_presi[N] = {0,0,0, 0};

int main()
{
    // Numero dei nodi deve essere pari
    assert(N % 2 == 0);

    for(int i = 0; i < N; i++)
    {
        //Vettore sesso 1 maschi, 0 femmine
        vettore_sesso[i] = nondet_int();
        __CPROVER_assume(vettore_sesso[i] == 1 || vettore_sesso[i] == 0);

        //Primo insieme
        primo_insieme[i] = nondet_int();
        __CPROVER_assume(primo_insieme[i] == 1 || primo_insieme[i] == 0);
        //Secondo Insieme
        secondo_insieme[i] = nondet_int();
        __CPROVER_assume(secondo_insieme[i] == 1 || secondo_insieme[i] == 0);
        // Il primo e il secondo insieme devono essere diversi
        __CPROVER_assume(primo_insieme[i] != secondo_insieme[i]);
        //__CPROVER_assume(primo_insieme[i] == 1 || secondo_insieme[i] == 1);
    }

    //Almeno 2/3 nell'insime 1

    for(int i = 0; i < N; i++)
    {
        if(vettore_sesso[i] ==  1){
            if(primo_insieme[i] == 1)
            {
                cont = cont + 1;
            }
        }
    }
    float due_terzi = (2.0 / 3.0) * N;
    __CPROVER_assume(cont >= due_terzi);



    for(int i = 0; i < N; i++)
    {
        k = nondet_int();
        if(vettore_nodi_presi[i] == 0 && vettore_nodi_presi[k] == 0){
            vettore_nodi_presi[i] = 1;
            vettore_nodi_presi[k] = 1;
            __CPROVER_assume(k >= 0 && k < N);
            __CPROVER_assume(matrice_incidenza[i][k] == 1);
            __CPROVER_assume(primo_insieme[i] == 1 && secondo_insieme[k] == 1);
            matrice_matching[i][k] = 1;
            matrice_matching[k][i] = 1;
        }
    }

    /*
     *     for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(primo_insieme[i] == 1 && secondo_insieme[j] == 1)
            {
                if(matrice_matching[i][j] == 0)
                {
                    matrice_matching[i][j] = 1;
                }
            }
        }
    }
     */


    for(int i = 0; i < N; i++)
    {
        cont = 0;
        for(int j = 0; j < N; j++){
            if(matrice_matching[i][j] == 1)
            {
                cont = cont + 1;
            }
        }
        __CPROVER_assume(cont == 1);
    }


    assert(0);
}