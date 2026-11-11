/* Exercicio 2 - Inverter as letras de cada palavra usando pilha. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct { char *dados; size_t topo,capacidade; } Pilha;
void empilhar(Pilha *p,char c){
 if(p->topo==p->capacidade){
  size_t n=p->capacidade?2*p->capacidade:32;
  char *novo=realloc(p->dados,n); if(!novo){perror("realloc");exit(1);}
  p->dados=novo;p->capacidade=n;
 }
 p->dados[p->topo++]=c;
}
void descarregar(Pilha *p){while(p->topo)putchar(p->dados[--p->topo]);}
int main(void){
 Pilha p={0};int c;
 puts("Digite texto terminado por ponto (.):");
 while((c=getchar())!=EOF && c!='.'){
  if(isspace((unsigned char)c)){descarregar(&p);putchar(c);}
  else empilhar(&p,(char)c);
 }
 descarregar(&p);putchar('\n');free(p.dados);return 0;
}
