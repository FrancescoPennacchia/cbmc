#define N 6
 
int nondet_int();

int matrice_incidenza[N][N] = 
{
    {0,0,0,1,1,0},
    {0,0,0,0,1,0},
    {0,0,0,0,1,1},
    {1,0,0,0,0,0},
    {1,1,1,0,0,0},
    {0,0,1,0,0,0}
};


int vettore_sesso[N] =  {1,1,0,0,0,0}; // 1 Maschio, 0 Femmina

int main()
{
    // Numero dei nodi deve essere pari
    __CPROVER_assume(N % 2 == 0);

    
    int primo_insieme[N]; // 1 se appartiene all'insieme uno, altriementi 0
    int secondo_insieme[N]; 


    for(int i = 0; i < N; i++)
    {
        primo_insieme[i] = nondet_int();
        __CPROVER_assume(primo_insieme[i] == 0 || primo_insieme[i] == 1);
    }

    for(int i = 0; i < N; i++)
    {
        secondo_insieme[i] = nondet_int();
        __CPROVER_assume(secondo_insieme[i] == 0 || secondo_insieme[i] == 1);
    }


    for(int i = 0; i < N; i++)
    {
        __CPROVER_assume(primo_insieme[i] != secondo_insieme[i]);
    }


    //Verificare se almeno uno dei due insiemi è 2/3
    //Mi conto i numeri zero e numeri 1
    int cont_di_uno = 0;
    int cont_di_zero = 0;

    for(int i = 0; i < N; i++) {
        if(primo_insieme[i] == 0){    //Errore post doveva essere = a 1
            if (vettore_sesso[i] == 1) 
            {
                cont_di_uno = cont_di_uno + 1;
            }
            else {
                cont_di_zero = cont_di_zero +1;
            }
        }
    }
    float due_terzi = ((N/3)*2);
    __CPROVER_assume( cont_di_uno >=  due_terzi || cont_di_zero >= due_terzi );

    assert(0);

    // Fallisce con matching unico
    /*
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j++)
        {
            if(primo_insieme[i] == 1 && secondo_insieme [j] == 1) {
                 assert(matrice_incidenza[i][j] == 1);
             }
        }
    }*/
}