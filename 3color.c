/*  
    • initializes the representation of the graph, e.g., a two-dimensional array that encodes the transition matrix of the given graph (with 6 nodes),
    • guesses a 3-coloring,
    • and checks whether the graph is 3-colorable 
*/


// L'idea è assegnare dei colori per ogni nodo, 3 colori, per comodità gli indico come 3 numeri interi quindi credo un array di dimensione 6 contente il colore di ciascun nodo.
// E poi ne verifico la colorabilità in base alla matrice di incidenza nodi / archi

#define SIZE 6
unsigned int nondet_int();

void check3Color(int *matrice[SIZE][SIZE], int colori[SIZE])
{
    for(int i = 0; i < SIZE; i++) 
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(matrice[i][j] == 1){
                __CPROVER_assume(colori[i] != colori[j]);                                                           // Sicuramente il colore tra il nodo e il nodo adiacente deve essere diverso
            }
        }
    }
}

int main () 
{

    unsigned int matrice[SIZE][SIZE] = 
    {
        {0, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 0}  
    }; 

    unsigned int colori[SIZE];


    /* Assegnamento non deterministico dei numeri */
    for(int i = 0; i < SIZE; i++)
    {
        colori[i] = nondet_int();
        __CPROVER_assume(colori[i] >= 1 && colori[i] <= 3);                                                 // Tre colori 1 - 2 - 3
    }


    for(int i = 0; i < SIZE; i++) 
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(matrice[i][j] == 1){
                __CPROVER_assume(colori[i] != colori[j]);                                                           // Sicuramente il colore tra il nodo e il nodo adiacente deve essere diverso
            }
        }
    }


    assert(0);

}