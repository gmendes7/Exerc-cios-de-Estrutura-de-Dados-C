/* Exercicio 1 - Verificar XY, sendo Y o reverso de X. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct { char *dados; size_t topo; } Pilha;
int verificar(const char *s) {
 size_t n=strlen(s); if(n==0 || n%2) return 0;
 size_t metade=n/2; Pilha p={malloc(metade),0};
 if(!p.dados){perror("malloc");exit(EXIT_FAILURE);}
 for(size_t i=0;i<metade;i++) p.dados[p.topo++]=s[i];
 int ok=1;
 for(size_t i=metade;i<n;i++) if(p.dados[--p.topo]!=s[i]){ok=0;break;}
 free(p.dados);return ok;
}
int main(void){
 char s[4096];
 printf("Digite a string XY: ");
 if(!fgets(s,sizeof s,stdin)) return 1;
 s[strcspn(s,"\r\n")]=0;
 puts(verificar(s)?"VALIDA: Y e o reverso de X.":"INVALIDA: nao esta na forma XY.");
 return 0;
}
