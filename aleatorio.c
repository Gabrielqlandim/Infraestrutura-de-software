#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void adicionarQuadro(int lista[], int pagina){
    int aleatorio = rand() % 4;
    printf("Substituindo pagina %d por %d no indice %d\n", lista[aleatorio], pagina, aleatorio);
    lista[aleatorio] = pagina;
    Sleep(1000);
}

int existeLista(int pagina, int lista[]){
    for(int i=0; i<4;i++){
        if(pagina == lista[i])
            return 1;
    }
    return 0;
}



int main(void){
    system("cls");
    srand(time(NULL));
    int lista[4] = {-1,-1,-1,-1};
    int sequenciaPaginas[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int tamanhoDaLista = sizeof(sequenciaPaginas)/sizeof(sequenciaPaginas[0]);
    
    for(int i=0; i<tamanhoDaLista;i++){
        int pagina = sequenciaPaginas[i];
        Sleep(1000);

        if(!existeLista(pagina, lista))
            adicionarQuadro(lista, pagina);

        else{
            printf("Page fault: %d\n", pagina);
            Sleep(1000);
        }
    }
    return 0;
}
