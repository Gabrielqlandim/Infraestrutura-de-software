#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANTIDADE_QUADROS 4 

typedef struct {
    int pagina;   
    int ordem;    
} Quadro;


int paginaNaMemoria(Quadro quadros[], int pagina) {
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        if (quadros[i].pagina == pagina) {
            return 1;
        }
    }
    return 0;
}


void substituirPagina(Quadro quadros[], int pagina, int* ordemAtual) {
    int maisAntiga = *ordemAtual;
    int candidatos[QUANTIDADE_QUADROS];
    int quantidadeCandidatos = 0;

    
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        if (quadros[i].ordem <= maisAntiga) {
            maisAntiga = quadros[i].ordem;
            candidatos[quantidadeCandidatos++] = i;
        }
    }

    
    int indiceAleatorio = rand() % quantidadeCandidatos;
    int posicaoEscolhida = candidatos[indiceAleatorio];

    printf("Substituindo pagina %d por %d\n", quadros[posicaoEscolhida].pagina, pagina);
    quadros[posicaoEscolhida].pagina = pagina;
    quadros[posicaoEscolhida].ordem = (*ordemAtual)++;
}

int main() {
    system("cls");
    Quadro quadros[QUANTIDADE_QUADROS];
    int sequenciaPaginas[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}; 
    int quantidadePaginas = sizeof(sequenciaPaginas) / sizeof(sequenciaPaginas[0]);
    int ordemAtual = 0;

    srand(time(NULL)); 

    
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        quadros[i].pagina = -1;    
        quadros[i].ordem = -1;     
    }

    printf("Executando o algoritmo Aleatorio com FIFO:\n");

    
    for (int i = 0; i < quantidadePaginas; i++) {
        int pagina = sequenciaPaginas[i];
        printf("Acessando pagina %d:\n", pagina);

        
        if (!paginaNaMemoria(quadros, pagina)) {
            
            substituirPagina(quadros, pagina, &ordemAtual);
        } else {
            printf("Pagina %d ja esta na memoria.\n", pagina);
        }
    }

    return 0;
}
