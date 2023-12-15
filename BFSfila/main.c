
#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "Pilha.h"
#include "Fila.h"

int main(){

    Matriz * matriz_adj = malloc(sizeof(Matriz));
    Fila * fila = malloc(sizeof(Fila));
    Pilha * pilha = malloc(sizeof(Pilha));

    int vertice, vertice_ini, vertice_fim, x, *status, *antecessores, achou = 0, vertice_atual; 

    printf("Informe o numero de vertices para o grafo: ");
    scanf("%d", &vertice);

    status = calloc(vertice + 1, sizeof(int)); // inicializa com 0
    antecessores = calloc(vertice + 1, sizeof(int));

    inicializa_matriz(matriz_adj, vertice + 1, vertice + 1);

    printf("Inicialize a matriz adjacente do grafo:\n");

    for(int i=1; i <= vertice; i++){
        for(int j = 1; j <= vertice; j++){

            scanf("%d", &x);
            set_valor(matriz_adj, i, j, x);

        }
    }
    
    printf("Vertice inicial: ");
    scanf("%d", &vertice_ini);

    printf("Vertice final: ");
    scanf("%d", &vertice_fim);

    inicializa_fila(fila, vertice);
    
    status[vertice_ini] = 1;

    inserir(fila, vertice_ini);
    
    while(!fila_vazia(*fila) && !achou){
        remover(fila, &vertice_atual);

        if(vertice_atual == vertice_fim){
            achou = 1;
        }
        else{

            for(int i = 1; i <= vertice; i++){
                int p;

                get_valor(*matriz_adj, vertice_atual, i, &p);

                if(p == 1 && status[i] == 0){
                    status[i] = 1;
                    antecessores[i] = vertice_atual;
                    inserir(fila, i);
                }
            }
        }
    }

    printf("\n");

    if(achou){

        inicializa_pilha(pilha, vertice);

        while(vertice_atual != 0){

            empilha(pilha, vertice_atual);

            vertice_atual = antecessores[vertice_atual];
        }

        while(!pilha_vazia(*pilha)){

            desempilha(pilha, &vertice_atual);
            printf("Vertice visitado: %d\n", vertice_atual);
        }
    }
    else{
        printf("B nao eh alcancavel a partir de A.\n");
    }
    

    return 0;
}
