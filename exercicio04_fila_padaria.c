/* Exercicio 4: fila encadeada FIFO de clientes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Cliente {char nome[100]; int senha; struct Cliente *prox;} Cliente;
typedef struct {Cliente *inicio,*fim; size_t qtd;} Fila;
int ler_numero(const char *msg,int *n){char b[100],extra; for(;;){
 printf("%s",msg); if(!fgets(b,sizeof b,stdin))return 0;
 if(sscanf(b," %d %c",n,&extra)==1)return 1;
 puts("Digite um numero inteiro valido.");
}}
int ler_nome(char *s,size_t t){printf("Nome: ");if(!fgets(s,(int)t,stdin))return 0;
 s[strcspn(s,"\r\n")]=0;return 1;}
int existe(Fila *f,int senha){for(Cliente *p=f->inicio;p;p=p->prox)if(p->senha==senha)return 1;return 0;}
void cadastrar(Fila *f,const char *nome,int senha){
 Cliente *p=malloc(sizeof *p);if(!p){perror("malloc");exit(1);}
 snprintf(p->nome,sizeof p->nome,"%s",nome);p->senha=senha;p->prox=NULL;
 if(f->fim)f->fim->prox=p;else f->inicio=p;f->fim=p;f->qtd++;
 printf("Cliente cadastrado: %s (senha %d).\n",nome,senha);
}
void chamar(Fila *f){if(!f->inicio){puts("Fila vazia.");return;}
 Cliente *p=f->inicio;printf("Chamando: %s - senha %d.\n",p->nome,p->senha);
 f->inicio=p->prox;if(!f->inicio)f->fim=NULL;f->qtd--;free(p);}
void primeiro(Fila *f){if(f->inicio)printf("Primeiro: %s - senha %d.\n",f->inicio->nome,f->inicio->senha);else puts("Fila vazia.");}
void listar(Fila *f){size_t i=1;for(Cliente *p=f->inicio;p;p=p->prox)
 printf("%zu. Senha %d - %s\n",i++,p->senha,p->nome);
 if(!f->qtd)puts("Fila vazia.");}
int main(void){Fila f={0};int opcao;
 for(;;){puts("\n=== PADARIA - EXERCICIO 4 ===");
 puts("1. Cadastrar cliente\n2. Chamar proximo\n3. Ver primeiro\n4. Exibir fila\n5. Quantidade\n0. Sair");
 if(!ler_numero("Opcao: ",&opcao)||opcao==0)break;
 switch(opcao){case 1:{char nome[100];int senha;
 if(!ler_nome(nome,sizeof nome))goto fim;
 if(!*nome){puts("Nome vazio.");break;}
 if(!ler_numero("Senha: ",&senha))goto fim;
 if(senha<=0||existe(&f,senha)){puts("Senha invalida ou duplicada.");break;}
 cadastrar(&f,nome,senha);break;}
 case 2:chamar(&f);break;case 3:primeiro(&f);break;
 case 4:listar(&f);break;case 5:printf("Clientes aguardando: %zu\n",f.qtd);break;
 default:puts("Opcao invalida.");}}
fim:while(f.inicio)chamar(&f);return 0;}
