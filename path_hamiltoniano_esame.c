#define SIZE 4

unsigned int nondet_int();
/*Per segnarmi che l'ho  visitato*/
int nodi_visitati[SIZE] = {0, 0, 0, 0};

/*Per segnarmi in che ordine l'ho visistato*/
int ordine_visite[SIZE] = {0, 0, 0, 0};

int matrice_incidenza[SIZE][SIZE] = {
    {0, 1, 0, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 0}
};

int nodo_corrente = 0;
int nodo_successivo = 0;
int contatore_ordine = 0;

int main() {
    nodi_visitati[nodo_corrente] = 1;
    ordine_visite[contatore_ordine] = nodo_corrente;

    //Visita
    for(int i = 0; i < SIZE -1; i++)
    {
        int nodo_successivo = nondet_int();
        __CPROVER_assume(nodo_successivo >= 0 && nodo_successivo < SIZE);
        __CPOVER_assume(matrice_incidenza[nodo_corrente][nodo_successivo] == 1);
        __CPOVER_assume(nodi_visitati[nodo_successivo] == 0);

        nodi_visitati[nodo_successivo] = 1;

        if(contatore_ordine < SIZE){
            contatore_ordine = contatore_ordine + 1;
            ordine_visite[contatore_ordine] = nodo_successivo;  
        }
       

        nodo_corrente = nodo_successivo;
    }

    /*for(int i = 0; i < SIZE; i++) {
        assert(!nodi_visitati[i] == 1);
    }*/

    assert(0);
    //Controllo se ho visitato tutto
    //assert(!(nodi_visitati[0] == 1 && nodi_visitati[1] == 1 && nodi_visitati[2] == 1 && nodi_visitati[3] == 1));

    /*
          for(int i = 0; i < SIZE; i++) {
        __CPROVER_assume(nodi_visitati[i] == 1);
    }
        assert(0);
    }
    */
   
}


/*

int nodi_visitati[SIZE] = {0, 0, 0, 0};

/*Per segnarmi in che ordine l'ho visistato
int ordine_visite[SIZE] = {0, 0, 0, 0};

int matrice_incidenza[SIZE][SIZE] = {
    {0, 1, 0, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 0}
};

int nodo_corrente = 0; //Nodo start
int nodo_successivo = 0;
int contatore_ordine = 1;

int main() {
    nodi_visitati[nodo_corrente] = 1;
    ordine_visite[nodo_corrente] = contatore_ordine;

    //Visita
    for(int i = 0; i < SIZE; i++)
    {
        int nodo_successivo = nondet_int();
        __CPROVER_assume(nodo_successivo >= 0 && nodo_successivo < SIZE);
        __CPOVER_assume(matrice_incidenza[nodo_corrente][nodo_successivo] == 1);
        __CPOVER_assume(nodi_visitati[nodo_successivo] == 0);

        nodi_visitati[nodo_successivo] = 1;
        nodo_corrente = nodo_successivo;

        contatore_ordine = contatore_ordine + 1;
        ordine_visite[nodo_corrente] = contatore_ordine;        
    }
    //assert(0);
    //Controllo se ho visitato tutto
    //assert(!(nodi_visitati[0] == 1 && nodi_visitati[1] == 1 && nodi_visitati[2] == 1 && nodi_visitati[3] == 1));

    for(int i = 0; i < SIZE; i++) {
        assert(!nodi_visitati[i] == 1);
    }
} */