#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {
 int valor;
 struct elemento* prox;
};
typedef struct elemento Lista;

Lista* inicializa (void){
 return NULL;
}

struct elemento *CriaElemento(int numero){
  struct elemento *resp = (struct elemento*) malloc(sizeof(struct elemento));
  resp->valor=numero;
  resp->prox=NULL;
  return resp;
}

struct elemento *InsereFim(struct elemento *lista, int numero){
  struct elemento *aux;
  struct elemento *novo=CriaElemento(numero);
  if(lista==NULL){
    lista=novo;
  }else{
    aux=lista;
    while(aux->prox != NULL)
      aux=aux->prox;
    aux->prox=novo;
  }
  return lista;
}

struct elemento *Concatena(struct elemento *lista1, struct elemento *lista2){
  struct elemento *aux;
  Lista* p;
  for (p = lista2; p != NULL; p = p->prox)
    lista1=InsereFim(lista1, p->valor);
  return lista1;
}

void imprime (Lista* l){
 Lista* p;
 for (p = l; p != NULL; p = p->prox)
 printf("info = %d\n", p->valor);
}

Lista* remover (Lista* l, int v) {
 Lista* ant = NULL;
 Lista* p = l; 
 while (p != NULL && p->valor != v) {
 ant = p;
 p = p->prox;
 }
 if (p == NULL)
 return l; 
 if (ant == NULL) {
 l = p->prox;
 }
 else {
 ant->prox = p->prox;
 }
 free(p);
 return l;
}

int main(void) {
  Lista* a;
  Lista* b;
  Lista* c;
  a = inicializa();
  b = inicializa();
  c = inicializa();
  int continuar=1;
  while(continuar){
    int escolha;
    printf("\nPara inserir um numero em alguma das listas digite 1;\n\nPara remover um numero em alguma das listas digite 2;\n\nPara unir duas listas digite 3;\n\nPara encerrar o programa digite 4;\n");
    scanf("%d", &escolha);
    if(escolha==1){
      printf("\nPara alterar a lista 'a' digite 1;\n\nPara alterar a lista 'b' digite 2;\n\nPara alterar a lista 'c' digite 3;\n");
      scanf("%d", &escolha);
      if(escolha==1){
        printf("Digite o número que deseja inserir: ");
        scanf("%d", &escolha);
        a=InsereFim(a, escolha);
      }
      if(escolha==2){
        printf("Digite o número que deseja inserir: ");
        scanf("%d", &escolha);
        b=InsereFim(b, escolha);
      }
      if(escolha==3){
        printf("Digite o número que deseja inserir: ");
        scanf("%d", &escolha);
        c=InsereFim(c, escolha);
      }
    }
    if(escolha==2){
      printf("\nPara alterar a lista 'a' digite 1;\n\nPara alterar a lista 'b' digite 2;\n\nPara alterar a lista 'c' digite 3;\n");
      scanf("%d", &escolha);
      if(escolha==1){
        printf("Digite o número que deseja remover: ");
        scanf("%d", &escolha);
        a=remover(a, escolha);
      }
      if(escolha==2){
        printf("Digite o número que deseja remover: ");
        scanf("%d", &escolha);
        b=remover(b, escolha);
      }
      if(escolha==3){
        printf("Digite o número que deseja remover: ");
        scanf("%d", &escolha);
        c=remover(c, escolha);
      }
    }
    if(escolha==3){
      printf("\nPara alterar a lista 'a' digite 1;\n\nPara alterar a lista 'b' digite 2;\n\nPara alterar a lista 'c' digite 3;\n");
      scanf("%d", &escolha);
      if(escolha==1){
        printf("\nPara adicionar a lista 'b' ao final da lista 'a' digite 1;\n\nPara adicionar a lista 'c' ao final da lista 'a' digite 2;\n");
        scanf("%d", &escolha);
        if(escolha==1){
          a=Concatena(a, b);
          b = inicializa();
        }
        if(escolha==2){
          a=Concatena(a, c);
          c = inicializa();
        }
      }
      if(escolha==2){
        printf("\nPara adicionar a lista 'a' ao final da lista 'b' digite 1;\n\nPara adicionar a lista 'c' ao final da lista 'b' digite 2;\n");
        scanf("%d", &escolha);
        if(escolha==1){
          a=Concatena(b, a);
          a = inicializa();
        }
        if(escolha==2){
          a=Concatena(b, c);
          c = inicializa();
        }
      }
      if(escolha==3){
        printf("\nPara adicionar a lista 'a' ao final da lista 'c' digite 1;\n\nPara adicionar a lista 'b' ao final da lista 'a' digite 2;\n");
        scanf("%d", &escolha);
        if(escolha==1){
          a=Concatena(b, a);
          a = inicializa();
        }
        if(escolha==2){
          a=Concatena(b, c);
          c = inicializa();
        }
      }
    }
    if(escolha==4){
      continuar=0;
    }
    printf("\nLista 'a';\n");
    imprime(a);
    printf("\nLista 'b';\n");
    imprime(b);
    printf("\nLista 'c';\n");
    imprime(c);
    printf("\n\n\n");
  }
  printf("\n\nThe End.\n\n");
}