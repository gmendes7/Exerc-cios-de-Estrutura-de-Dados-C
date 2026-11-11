# Lista de Exercicios - Pilhas e Filas em C

**Disciplina:** Algoritmos e Estrutura de Dados  
**Instituicao:** Universidade Anhanguera - Uniderp  
**Professor:** Ricardo Masao Kondo  
**Linguagem:** C (padrao C11)

Este projeto resolve separadamente os **8 exercicios** da lista, usando pilhas (LIFO) e filas (FIFO). Cada arquivo `.c` e independente: pode ser aberto e compilado sozinho no Dev-C++, Code::Blocks, VS Code + GCC ou terminal.

## Arquivos e funcionamento

| Questao | Arquivo | Estrutura / objetivo |
| --- | --- | --- |
| 1 | `exercicio01_xy_reverso.c` | Pilha de caracteres; divide uma string de comprimento par em X e Y e verifica se Y e o reverso de X. |
| 2 | `exercicio02_inverter_palavras.c` | Pilha de caracteres; inverte cada palavra ate o primeiro ponto, preservando a ordem das palavras e os espacos. |
| 3 | `exercicio03_palindromo.c` | Pilha de caracteres; compara a frase com seu reverso, ignorando espacos, pontuacao e diferencas de maiusculas/minusculas. |
| 4 | `exercicio04_fila_padaria.c` | Fila encadeada de clientes; cadastrar, chamar, consultar primeiro, listar e contar. |
| 5 | `exercicio05_fibonacci_pilha.c` | Pilha dinamica dos primeiros n numeros de Fibonacci; mostra do topo para a base. |
| 6 | `exercicio06_filas_par_impar_pilha.c` | Duas filas encadeadas para pares/impares e uma pilha, com processamento alternado iniciando pelos impares. |
| 7 | `exercicio07_fila_padaria_circular.c` | Fila circular com vetor redimensionavel para o atendimento da padaria; mesmas operacoes da questao 4. |
| 8 | `exercicio08_lava_rapido.c` | Fila encadeada de veiculos, uma estacao de lavagem, conclusao de servico e relatorio por tipo. |

## Como compilar e executar

### Windows - Dev-C++

1. Extraia o ZIP.
2. Abra o **Dev-C++** e selecione **Arquivo > Abrir**.
3. Abra um arquivo `.c` da lista, por exemplo `exercicio04_fila_padaria.c`.
4. Execute **Compilar e Executar** (em geral, F11).
5. Para testar outro exercicio, abra seu respectivo arquivo `.c`.

> Cada arquivo tem sua propria funcao `main`. **Nao compile os oito `.c` num unico executavel**: abra/compile um de cada vez ou use o Makefile.

### Linux, macOS ou Windows com GCC

Exemplo: compilar e executar a questao 1:

```bash
gcc -std=c11 -Wall -Wextra -pedantic exercicio01_xy_reverso.c -o exercicio01
./exercicio01
```

Para outra questao, substitua o nome do arquivo e do executavel. No Windows, execute `exercicio01.exe`.

Se tiver `make`, rode `make` para compilar todos, e `make clean` para apagar os executaveis.

## Exemplos de entrada e saida

### Questao 1

Entrada: `ABCDDCBA`  
Resultado: `VALIDA: Y e o reverso de X.`

Entrada: `ABCDABCD`  
Resultado: `INVALIDA: nao esta na forma XY.`

### Questao 2

Entrada:

```text
ESTE EXERCICIO E MUITO FACIL.
```

Saida:

```text
ETSE OICICREXE E OTIUM LICAF
```

O ponto termina a leitura e nao e reproduzido.

### Questao 3

Entradas que retornam palindromo: `ovo`, `osso`, `arara`, `luz azul`, `o lobo ama o bolo`.

### Questao 4 e 7

O menu permite cadastrar clientes (nome e senha), chamar o proximo, consultar o primeiro **sem remover**, listar os aguardando e contar a fila. As senhas devem ser positivas e nao podem se repetir enquanto estiverem na fila.

### Questao 5

Para `n = 6`, os seis termos empilhados sao `0, 1, 1, 2, 3, 5`. Como a pilha e LIFO, a saida e `5, 3, 2, 1, 1, 0` (topo para base).

### Questao 6

O programa le numeros inteiros ate receber `0`. Cada numero vai para a fila PAR ou IMPAR. O processamento retira um impar e depois um par, alternadamente; se uma fila acabar primeiro, continua com a outra. Cada numero positivo e empilhado. Cada numero negativo retira o topo da pilha, se ela nao estiver vazia. Ao final, exibe a pilha do topo ate a base.

### Questao 8

O menu cadastra placas, modelos e tipos de lavagem (1 = simples, 2 = completa), inicia a lavagem na estacao unica, permite concluir a lavagem atual e consulta a fila. Ao encerrar o expediente, o programa imprime o total de lavagens **concluidas** de cada tipo. Carros em espera ou com lavagem em andamento nao contam como atendidos.

## Decisoes de implementacao

- As questoes **4 e 7** possuem enunciados praticamente identicos. Foram feitas com **implementacoes diferentes** para demonstrar os dois tipos de fila: encadeada e circular.
- As questoes **1, 2 e 3** trabalham com caracteres no formato ASCII, suficiente para os exemplos do enunciado. Frases com caracteres UTF-8 multibyte (acentos) exigem tratamento adicional para considerar cada caractere acentuado como uma unidade.
- A questao **1** exige comprimento par e nao vazio; X e a primeira metade e Y a segunda.
- A questao **3** considera palindromos frases sem espacos, sem pontuacao e sem diferenciar maiusculas/minusculas; uma entrada sem letras ou digitos e considerada invalida.
- Na questao **5**, o limite de **94 termos** (de F0 a F93) evita ultrapassar a capacidade de `unsigned long long` (64 bits).
- Filas e pilhas vazias sao verificadas antes de retiradas, evitando acesso indevido a memoria.
- A memoria dinamica e liberada ao finalizar cada programa.

## Testes automatizados

Requer Python 3 e GCC. Na pasta raiz, execute:

```bash
python testes/testar_programas.py
```

O script compila todos os oito programas com avisos tratados como erros (`-Werror`) e testa suas entradas e saidas. Ao final, deve mostrar:

```text
SUCESSO: todos os 8 programas compilaram e passaram nos testes.
```

## Publicar no GitHub

1. Crie um repositorio **novo e vazio** no GitHub para esta lista (por exemplo, `lista-pilhas-filas-c`).
2. Abra um terminal na pasta extraida.
3. Execute os comandos abaixo, **substituindo `SEU_USUARIO` e `NOME_DO_REPOSITORIO`** pelos valores corretos:

```bash
git init
git add .
git commit -m "Implementa oito exercicios de pilhas e filas em C"
git branch -M main
git remote add origin https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO.git
git push -u origin main
```

Se voce ja tiver inicializado o repositorio ou cadastrado `origin`, adapte os comandos para evitar duplicidade.