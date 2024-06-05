//#include <iostream>
#define N 6

int nondet_int();
int nondet_bool();

int matrice_incidenza[N][N] = 
{
    {0,1,0,1,0,0},
    {1,0,1,0,0,0},
    {0,1,0,1,0,1},
    {1,0,1,0,1,0},
    {0,0,0,1,0,1},
    {0,0,1,0,1,0}
};

int matrice_matching[N][N] = 
{
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}
};

int vettore_sesso[N] = {0,1,0,1,1,1}; // 1 Maschio, 0 Femmina
int primo_insieme[N]; // 1 se appartiene all'insieme uno, altrimenti 0
int secondo_insieme[N]; 
int vettore_nodi_presi[N] = {0,0,0,0,0,0};

int main()
{
    // Numero dei nodi deve essere pari
    __CPROVER_assume(N % 2 == 0);

    for(int i = 0; i < N; i++)
    {
        primo_insieme[i] = nondet_int();
        __CPROVER_assume(primo_insieme[i] == 0 || primo_insieme[i] == 1);
        secondo_insieme[i] = 1 - primo_insieme[i];
    }

    // Mi creo la matrice dei matching unici
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(vettore_nodi_presi[i] == 0 && vettore_nodi_presi[j] == 0)
            {
                if(matrice_incidenza[i][j] == 1 && matrice_incidenza[j][i] == 1)
                {
                    if((primo_insieme[i] == 1 && secondo_insieme[j] == 1) || (primo_insieme[j] == 1 && secondo_insieme[i] == 1)) { 
                        vettore_nodi_presi[i] = 1;
                        vettore_nodi_presi[j] = 1;
                        matrice_matching[i][j] = 1;
                        matrice_matching[j][i] = 1;
                        break;               
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        (vettore_nodi_presi[i] == 1);
    }

    // Verificare se almeno uno dei due insiemi è 2/3
    // Mi conto i numeri zero e numeri 1
    float cont_di_uno = 0;
    float cont_di_zero = 0;
    
    for(int i = 0; i < N; i++) {
        if(primo_insieme[i] == 1){
            if (vettore_sesso[i] == 1) 
            {
                cont_di_uno = cont_di_uno + 1;
            }
            else {
                cont_di_zero = cont_di_zero +1;
            }
        }
    }
    float due_terzi = (2.0 / 3.0) * N;
    __CPROVER_assume(cont_di_uno >= due_terzi || cont_di_zero >= due_terzi);
    assert(0);

}
