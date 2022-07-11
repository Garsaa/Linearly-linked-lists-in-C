#include <stdio.h>
#include <stdlib.h>


typedef struct emp{

    int codigo;
    float salarioUltimoMes;
    struct emp *prox;

}financas;

int menu();
void mostraLista(financas *recebeInicioToShow);
void insereFunc(financas **recebeInicioToInsert, financas *novoPont, int recebeCodigo);
void insereInicio(financas **recebeInicio, financas *p);
void insereMeio(financas *proximo, financas *anterior, financas *novoPont);
void insereFim(financas **recebeInicio, financas*p);

//desenvolvimento da função main
int main(){
    int opcao, controlaCodigo=0;
    financas *inicio, *lista;
    inicio = NULL;

    opcao = menu();

      while(opcao != 3){        //implementação casual com menu caso surja necessidade de mais funções
        switch(opcao){
            
         case 1:
            controlaCodigo++;
             lista = (financas*) malloc(sizeof(financas));
              if(lista == NULL){
                    printf("\n Nao foi possivel alocar");
                }else{
                    insereFunc(&inicio, lista, controlaCodigo);
                }
             opcao = menu(); 
             break;

         case 2: 
            mostraLista(inicio);
            opcao = menu(); 
            break;
        }     
    }


    printf("\nFinalizando programa!");



    
}

//função que exibe o menu e pede operação
int menu(){
    int op;
    printf("\n====MENU====");
    printf("\n 1 - Inserir funcionario");
    printf("\n 2 - Exibir a lista atual");
    printf("\n 3 - Fim");
    printf("\n Informe a opcao desejada: ");
    scanf("%d", &op);

    while(op<=0 || op>3){
        menu();
    }

    return op;

}


//função que define onde será inserido o elemento na lista
void insereFunc(financas **recebeInicioToInsert, financas *novoPont, int recebeCodigo){
    financas *pontAux, *pontAux2;
    int check = 0;
    novoPont->codigo = recebeCodigo;

    printf("\n Qual o salario do funcionario de codigo: %d ?", recebeCodigo);
    scanf("%f", &novoPont->salarioUltimoMes); 

    while(novoPont->salarioUltimoMes<0){
        printf("\nNao ha salarios negativos");
        scanf("%f", &novoPont->salarioUltimoMes);
    }
    
    if(*recebeInicioToInsert == NULL){
         novoPont->prox = NULL;
        *recebeInicioToInsert = novoPont;
    }else{  
        pontAux = *recebeInicioToInsert;
        pontAux2 = *recebeInicioToInsert;

            if(novoPont->salarioUltimoMes < pontAux2->salarioUltimoMes){
                insereInicio(&*recebeInicioToInsert, novoPont);
            }else{
             pontAux = pontAux->prox; 
             while(novoPont->salarioUltimoMes > pontAux2->salarioUltimoMes && novoPont->salarioUltimoMes > pontAux->salarioUltimoMes && check==0){
                pontAux2 = pontAux2->prox;
                pontAux = pontAux->prox;
                if(pontAux2->prox == NULL){
                insereFim(&*recebeInicioToInsert, novoPont);
                check=1;
                pontAux = pontAux2;
                }
             }

             if(check==0){
                insereMeio(pontAux, pontAux2, novoPont);
             }

        }

    }


}


//função que insere no meio
void insereMeio(financas *proximo, financas *anterior, financas *novoPont){
    novoPont->prox = anterior->prox;
    anterior->prox = novoPont;
    
}



//função que insere no inicio
void insereInicio(financas **recebeInicio, financas *p){
       p->prox = *recebeInicio;
       *recebeInicio = p;
}



//funcao que insere no fim
void insereFim(financas **recebeInicio, financas*p){
     financas *pontAuxiliar;
        p->prox = NULL; 

        pontAuxiliar = *recebeInicio;

        while(pontAuxiliar->prox != NULL){
            pontAuxiliar = pontAuxiliar->prox;
        }
            pontAuxiliar->prox = p;

}



//função que imprime a lista
void mostraLista(financas *recebeInicioToShow){ 
    financas *lista;

    lista = recebeInicioToShow;

    if(recebeInicioToShow == NULL){
        printf("\nNao ha o que imprimir, a lista esta vazia!");
    }else{
        while(lista != NULL){
            printf("\nCodigo do funcionario = %d  /  Seu ultimo salario : %f", lista->codigo, lista->salarioUltimoMes);
            lista = lista->prox; 
        }
    }
}
