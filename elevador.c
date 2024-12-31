#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int item;
    struct No* prox;
}No;

//Estruta da Fila
typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializarfila(Fila* fila){
    fila -> inicio = NULL;
    fila -> fim = NULL;
}


int VerificaFila(Fila* fila){
    if(fila->inicio == NULL){
        return 0; //Fila Vazia
    }else{
        return 1; //Tem algo na Fila
    }
}

void verifica_andar(Fila* fila, int* andar_atual){
    int prox_fila = fila -> inicio -> item;
    int andar_min = 0, andar_max = 5;

    if(prox_fila == *andar_atual){
        return; //Não faz nada
    }else{
        if(prox_fila < andar_min || prox_fila > andar_max){
                printf("andar indisponível");
            }else{
                movimenta(prox_fila, andar_atual);
            }
    }

} 

void movimenta(int prox_fila,int* andar_atual){
    if(prox_fila > *andar_atual){
        while(*andar_atual < prox_fila){
            (*andar_atual)++;
            printf("subindo... andar: %d\n", *andar_atual);
        }
    }else{
        while (*andar_atual > prox_fila){
            (*andar_atual)--;
            printf("descendo... andar: %d\n", *andar_atual);
        }
    }
}

void main(){

    int andar_atual = 0;
    int* ptr_andar = &andar_atual;

    Fila fila;
    inicializarfila(&fila);

    // Criando um nó para a fila com um andar
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->item = 3; // Exemplo de andar na fila
    novoNo->prox = NULL;

    // Inserindo o nó na fila
    fila.inicio = novoNo;
    fila.fim = novoNo;


    if(VerificaFila(&fila) == 1){
        verifica_andar(&fila, ptr_andar);
    }

    return 0;
}