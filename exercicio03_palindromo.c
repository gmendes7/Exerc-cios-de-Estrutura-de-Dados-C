/* Exercicio 3 - Palindromo usando pilha de caracteres. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int palindromo(const char *s){
 size_t n=strlen(s),topo=0;
 char *pilha=malloc(n?n:1);if(!pilha){perror("malloc");exit(1);}
 for(size_t i=0;i<n;i++)if(isalnum((unsigned char)s[i]))
  pilha[topo++]=(char)tolower((unsigned char)s[i]);
 if(!topo){free(pilha);return 0;}
 int ok=1;
 for(size_t i=0;i<n;i++)if(isalnum((unsigned char)s[i])){
  if((char)tolower((unsigned char)s[i])!=pilha[--topo]){ok=0;break;}
 }
 free(pilha);return ok;
}
int main(void){
 char texto[4096];
 printf("Digite palavra ou frase: ");
 if(!fgets(texto,sizeof texto,stdin))return 1;
 puts(palindromo(texto)?"E palindromo.":"Nao e palindromo.");
 return 0;
}
