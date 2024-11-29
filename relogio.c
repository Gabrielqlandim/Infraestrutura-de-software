#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE_QUADROS 4 

typedef struct {
    int pagina;    
    int bitReferencia;  
} Quadro;


int paginaNaMemoria(Quadro quadros[], int pagina) {
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        if (quadros[i].pagina == pagina) {
            quadros[i].bitReferencia = 1; 
            return 1;
        }
    }
    return 0;
}


void segundaChance(Quadro quadros[], int *ponteiro, int pagina) {
    while (1) {
        
        if (quadros[*ponteiro].bitReferencia == 0) {
            printf("Substituindo pagina %d por %d\n", quadros[*ponteiro].pagina, pagina);
            quadros[*ponteiro].pagina = pagina;   
            quadros[*ponteiro].bitReferencia = 1;    
            *ponteiro = (*ponteiro + 1) % QUANTIDADE_QUADROS; 
            break;
        } else {
            
            quadros[*ponteiro].bitReferencia = 0;
            *ponteiro = (*ponteiro + 1) % QUANTIDADE_QUADROS;
        }
    }
}

int main() {
    system("cls");
    Quadro quadros[QUANTIDADE_QUADROS];
    int ponteiro = 0; 
    int sequenciaPaginas[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}; 
    int quantidadePaginas = sizeof(sequenciaPaginas) / sizeof(sequenciaPaginas[0]);

    
    for (int i = 0; i < QUANTIDADE_QUADROS; i++) {
        quadros[i].pagina = -1;   
        quadros[i].bitReferencia = 0;   
    }

    printf("Executando o algoritmo de Segunda Chance:\n");

    
    for (int i = 0; i < quantidadePaginas; i++) {
        int pagina = sequenciaPaginas[i];
        printf("Acessando pagina %d:\n", pagina);

        
        if (!paginaNaMemoria(quadros, pagina)) {
            
            segundaChance(quadros, &ponteiro, pagina);
        } else {
            printf("Pagina %d ja esta na memoria, atualizando bit de referencia.\n", pagina);
        }
    }

    return 0;
}
