#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANTIDADE_QUADROS 4 

typedef struct {
    int pagina;        
    int frequencia;    
} Quadro;


int paginaNaMemoria(Quadro quadros[], int pagina) {
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        if (quadros[i].pagina == pagina) {
            quadros[i].frequencia++; 
            return 1;
        }
    }
    return 0;
}


void substituirPagina(Quadro quadros[], int pagina) {
    int menorFrequencia = quadros[0].frequencia;
    int candidatos[QUANTIDADE_QUADROS];
    int quantidadeCandidatos = 0;

    
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        if (quadros[i].frequencia < menorFrequencia) {
            menorFrequencia = quadros[i].frequencia;
            quantidadeCandidatos = 1;
            candidatos[0] = i;
        } else if (quadros[i].frequencia == menorFrequencia) {
            candidatos[quantidadeCandidatos++] = i;
        }
    }

    
    int indiceAleatorio = rand() % quantidadeCandidatos;
    int posicaoEscolhida = candidatos[indiceAleatorio];

    printf("Substituindo pagina %d (frequencia %d) por %d\n", quadros[posicaoEscolhida].pagina, quadros[posicaoEscolhida].frequencia, pagina);
    quadros[posicaoEscolhida].pagina = pagina;
    quadros[posicaoEscolhida].frequencia = 1; 
}

int main() {
    system("cls");
    Quadro quadros[QUANTIDADE_QUADROS];
    int sequenciaPaginas[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}; 
    int quantidadePaginas = sizeof(sequenciaPaginas) / sizeof(sequenciaPaginas[0]);

    srand(time(NULL)); 

    
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        quadros[i].pagina = -1;    
        quadros[i].frequencia = 0; 
    }

    printf("Executando o algoritmo Aleatorio com LFU:\n");

    
    for (int i = 0; i < quantidadePaginas; i++) {
        int pagina = sequenciaPaginas[i];
        printf("Acessando pagina %d:\n", pagina);

        
        if (!paginaNaMemoria(quadros, pagina)) {
            
            substituirPagina(quadros, pagina);
        } else {
            printf("Pagina %d ja esta na memoria, atualizando frequencia.\n", pagina);
        }
    }

    return 0;
}
