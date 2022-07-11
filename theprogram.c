#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int dado;
    struct no *prox;

}nodo;

int menu();
void insereInicio(nodo **recebeInicio, int valor, nodo *p);
void insereMeio(nodo **recebeInicio, int valor, nodo *p);
void insereFim(nodo **recebeInicio, int valor, nodo *p);

void mostraLista(nodo *recebeInicioToShow);

void removeInicio(nodo **recebeInicio);
void removeMeio(nodo **recebeInicio);
void removeFim(nodo **recebeInicio);

int main(){
    int opcao, valor;
    nodo *inicio, *lista;
    inicio = NULL;
    opcao = menu();

     while(opcao != 8){
        switch(opcao){
            
         case 1:
             lista = (nodo*) malloc(sizeof(nodo));
              if(lista == NULL){
                    printf("\n Nao foi possivel alocar");
                }else{
                printf("\nDigite o valor a ser inserido ");
                scanf("%d", &valor);
                
                insereInicio(&inicio, valor, lista);
                }
                opcao = menu(); 
             break;

         case 2:
              lista = (nodo*) malloc(sizeof(nodo));
              if(lista == NULL){
                    printf("\n Nao foi possivel alocar");
                }else{
                printf("\nDigite o valor a ser inserido ");
                scanf("%d", &valor);
                
                insereMeio(&inicio, valor, lista);
                }
                opcao = menu();
             break; 


         case 3:
                lista = (nodo*) malloc(sizeof(nodo));
                if(lista == NULL){
                    printf("\n Nao foi possivel alocar");
                }else{
                printf("\nDigite o valor a ser inserido ");
                scanf("%d", &valor);
                
                insereFim(&inicio, valor, lista);
                }
                opcao = menu();
             break;
         case 4:
                mostraLista(inicio);
                opcao = menu();
          break;

         case 5:
            removeInicio(&inicio);
            opcao=menu();
          break;
         case 6:
            removeMeio(&inicio);
            opcao=menu();
          break;
         case 7:
                removeFim(&inicio);
                opcao=menu();
            break;
        }   
    }
    printf("\nFinalizando programa!");


}
//função que mostra o menu e pergunta a opção
int menu(){
    int op;
    printf("\n 1 - Insere no inicio ");
    printf("\n 2 - Insere no meio ");
    printf("\n 3 - Insere no fim");
    printf("\n 4 - Imprime lista");
    printf("\n 5 - Remove do inicio");
    printf("\n 6 - Remove do meio");
    printf("\n 7 - Remove do fim");
    printf("\n 8 - Fim");
    printf("\n Informe a opcao desejada: ");
    scanf("%d", &op);

    if(op<=0 || op>8){
        menu();
    }

    return op;

}



//função que insere no começo do programa
void insereInicio(nodo **recebeInicio, int valor, nodo *p){
       p->prox = *recebeInicio;
       p->dado=valor;
      *recebeInicio = p;
}

//função que insere no meio do programa
void insereMeio(nodo **recebeInicio, int valor, nodo *p){
    nodo *pontAux, *pontAux2;
    int valorRef, verifica=0;
    
     printf("\nDeseja inserir antes de qual valor?");
     scanf("%d", &valorRef);

        pontAux2 = *recebeInicio;
        while(pontAux2 != NULL){
            if(pontAux2->dado == valorRef){
                verifica = 1;
            }
            pontAux2=pontAux2->prox;
        }
    
    if(*recebeInicio == NULL){
        printf("\nNao pode inserir no meio em uma lista vazia!");
    }else if(verifica == 0){
        printf("\nValor de referencia nao existe na lista");

    }else{
    p->dado = valor;
   
    pontAux2 = *recebeInicio;

    if(valorRef == pontAux2->dado){
        printf("\nO comeco nao e um meio");//chamar as funções corretas pras consistências
    }else{
    
    pontAux = *recebeInicio;
    pontAux = pontAux->prox;

    while(pontAux->dado != valorRef){
        pontAux = pontAux->prox;
        pontAux2 = pontAux2->prox; //pontAux2->prox aponta pra onde ta o valor que tu quer inserir antes
    }
    p->prox = pontAux2->prox;
    pontAux2->prox = p;

    }

    }
}

//função que insere no fim
void insereFim(nodo **recebeInicio, int valor, nodo*p){
     nodo *pontAuxiliar;
     p->dado = valor;
     p->prox = NULL; 
      
      if(*recebeInicio == NULL){
        printf("\nInserindo em lista vazia!");
         *recebeInicio = p;
       }else{
            pontAuxiliar = *recebeInicio;
            while(pontAuxiliar->prox != NULL)
            {
                pontAuxiliar = pontAuxiliar->prox;
            }
            pontAuxiliar->prox = p;
      }
}

//função que remove do inicio
void removeInicio(nodo **recebeInicio){
    nodo *pontAux;
    pontAux = *recebeInicio;

    if(*recebeInicio == NULL){
        printf("\nImpossivel remover de lista vazia!");
    }else if(pontAux->prox == NULL){
        *recebeInicio = NULL;
    }else{
    int valorRetirado;

    valorRetirado = pontAux->dado;

    *recebeInicio = pontAux->prox;
    free(pontAux);
    printf("\nRetirado o valor %d", valorRetirado);
    }

}

//função que remove do meio
void removeMeio(nodo **recebeInicio){
    if(*recebeInicio == NULL){
        printf("\nImpossivel remover de uma lista vazia");
    }else{
        nodo *pontAux, *pontAux2;
        int valorRemovido, verifica=0;

        printf("\nQual valor desejas remover?");
        scanf("%d", &valorRemovido);
        
        pontAux = *recebeInicio;
        while(pontAux!=NULL){
            if(pontAux->dado == valorRemovido){
                verifica=1;
            }
            pontAux = pontAux->prox;
        }
    
        if(verifica=0){
            printf("\nValor a ser removido nao existe na lista!");
        }else{
            pontAux = *recebeInicio;
            if(pontAux->prox == NULL){
                *recebeInicio = NULL;
                free(pontAux);
            }else{
                pontAux2 = *recebeInicio;
                pontAux = pontAux->prox;
                while(pontAux!=NULL && pontAux->dado != valorRemovido){
                    pontAux2 = pontAux2->prox; //vai apontar pro valor que vai ser removido
                    pontAux= pontAux->prox; //é o valor que vai ser removido
                }

                pontAux2->prox = pontAux->prox;
                free(pontAux);
            }

        }
        printf("\nValor removido!");
    }


}

//função que remove do fim
void removeFim(nodo **recebeInicio){
    int valorRetirado;
    nodo *antigo, *pontAuxiliar;
    antigo = NULL;
    pontAuxiliar = *recebeInicio;

    if(*recebeInicio == NULL){
        printf("\nImpossivel remover de lista vazia!");
    }else{
        while(pontAuxiliar->prox!= NULL){
            antigo = pontAuxiliar; //vai apontar pro último que aponta pra NULL, esse aqui vai apontar pro novo último
            pontAuxiliar = pontAuxiliar->prox;
        }
        valorRetirado = pontAuxiliar->dado;
        if(antigo != NULL){
            antigo->prox=NULL;
        }else{
            *recebeInicio = NULL;
        }
        printf("\nRetirado o valor: %d", valorRetirado);
        free(pontAuxiliar);
    }



}

//função que imprime a lista
void mostraLista(nodo *recebeInicioToShow){ 
    nodo *lista;

    lista = recebeInicioToShow;

    if(recebeInicioToShow == NULL){
        printf("\nNao ha o que imprimir, a lista esta vazia!");
    }else{
        while(lista!= NULL){
            printf("\nValor = %d", lista->dado);
            lista = lista->prox; 
        }
    }




}












