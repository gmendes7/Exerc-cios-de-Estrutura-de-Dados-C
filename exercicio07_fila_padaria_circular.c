/* Exercicio 7: fila circular dinamica de clientes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {char nome[100];int senha;} Cliente;
typedef struct {Cliente *dados;size_t capacidade,inicio,qtd;} Fila;
int ler_int(const char *msg,int *n){char b[100],extra;for(;;){
 printf("%s",msg);if(!fgets(b,sizeof b,stdin))return 0;
 if(sscanf(b," %d %c",n,&extra)==1)return 1;puts("Numero invalido.");
}}
Cliente *pos(Fila *f,size_t i){return &f->dados[(f->inicio+i)%f->capacidade];}
int existe(Fila *f,int senha){for(size_t i=0;i<f->qtd;i++)if(pos(f,i)->senha==senha)return 1;return 0;}
void inserir(Fila *f,Cliente c){
 if(f->qtd==f->capacidade){size_t cap=f->capacidade?f->capacidade*2:4;
 Cliente *novo=malloc(cap*sizeof *novo);if(!novo){perror("malloc");exit(1);}
 for(size_t i=0;i<f->qtd;i++)novo[i]=*pos(f,i);
 free(f->dados);f->dados=novo;f->capacidade=cap;f->inicio=0;}
 *pos(f,f->qtd++)=c;
}
void chamar(Fila *f){if(!f->qtd){puts("Fila vazia.");return;}
 Cliente c=*pos(f,0);printf("Chamando: %s - senha %d.\n",c.nome,c.senha);
 f->inicio=(f->inicio+1)%f->capacidade;f->qtd--;
}
void consultar(Fila *f){if(!f->qtd){puts("Fila vazia.");return;}
 Cliente *c=pos(f,0);printf("Primeiro aguardando: %s - senha %d.\n",c->nome,c->senha);}
void listar(Fila *f){if(!f->qtd)puts("Fila vazia.");
 for(size_t i=0;i<f->qtd;i++){Cliente *c=pos(f,i);
 printf("%zu. Senha %d - %s\n",i+1,c->senha,c->nome);}}
int main(void){Fila f={0};int o;for(;;){
 puts("\n=== PADARIA - EXERCICIO 7 ===");
 puts("1. Cadastrar\n2. Chamar proximo\n3. Consultar primeiro\n4. Exibir fila\n5. Quantidade\n0. Sair");
 if(!ler_int("Opcao: ",&o)||o==0)break;
 switch(o){case 1:{Cliente c;
 printf("Nome: ");if(!fgets(c.nome,sizeof c.nome,stdin))goto fim;
 c.nome[strcspn(c.nome,"\r\n")]=0;if(!*c.nome){puts("Nome vazio.");break;}
 if(!ler_int("Senha: ",&c.senha))goto fim;
 if(c.senha<=0||existe(&f,c.senha)){puts("Senha invalida ou repetida.");break;}
 inserir(&f,c);puts("Cliente cadastrado.");break;}
 case 2:chamar(&f);break;case 3:consultar(&f);break;case 4:listar(&f);break;
 case 5:printf("Total aguardando: %zu\n",f.qtd);break;default:puts("Opcao invalida.");}}
fim:free(f.dados);return 0;}
