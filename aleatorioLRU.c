#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANTIDADE_QUADROS 4 

typedef struct {
    int pagina;     
    int tempo;      
} Quadro;


int paginaNaMemoria(Quadro quadros[], int pagina, int tempoAtual) {
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        if (quadros[i].pagina == pagina) {
            quadros[i].tempo = tempoAtual; 
            return 1;
        }
    }
    return 0;
}


void substituirPagina(Quadro quadros[], int pagina, int tempoAtual) {
    int paginaEscolhida = -1;
    int menorTempo = tempoAtual;
    int candidatos[QUANTIDADE_QUADROS];
    int quantidadeCandidatos = 0;

    
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        if (quadros[i].tempo < menorTempo) {
            menorTempo = quadros[i].tempo;
            quantidadeCandidatos = 1;
            candidatos[0] = i;
        } else if (quadros[i].tempo == menorTempo) {
            candidatos[quantidadeCandidatos++] = i;
        }
    }

    
    if (quantidadeCandidatos > 0) {
        int indiceAleatorio = rand() % quantidadeCandidatos;
        paginaEscolhida = candidatos[indiceAleatorio];
    }

    
    printf("Substituindo pagina %d por %d\n", quadros[paginaEscolhida].pagina, pagina);
    quadros[paginaEscolhida].pagina = pagina;
    quadros[paginaEscolhida].tempo = tempoAtual;
}

int main() {
    system("cls");
    Quadro quadros[QUANTIDADE_QUADROS];
    int sequenciaPaginas[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}; 
    int quantidadePaginas = sizeof(sequenciaPaginas) / sizeof(sequenciaPaginas[0]);
    int tempoAtual = 0; 

    srand(time(NULL)); 

    
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        quadros[i].pagina = -1;    
        quadros[i].tempo = -1;     
    }

    printf("Executando o algoritmo Aleatorio com LRU:\n");

    
    for (int i = 0; i < quantidadePaginas; i++) {
        int pagina = sequenciaPaginas[i];
        printf("Acessando pagina %d:\n", pagina);

        
        if (!paginaNaMemoria(quadros, pagina, tempoAtual)) {
            
            substituirPagina(quadros, pagina, tempoAtual);
        } else {
            printf("Pagina %d ja esta na memoria, atualizando o tempo.\n", pagina);
        }

        tempoAtual++; 
    }

    return 0;
}
