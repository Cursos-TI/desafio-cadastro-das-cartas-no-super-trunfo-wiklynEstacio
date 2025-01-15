# Documentação

Alterei a estrutura do projeto e utilizei de conceitos dos quais eu já possuia
conhecimento, mas ainda não foram ensinados na disciplina. Caso isso seja um
problema, eu reescreverei o projeto.

Apesar do uso de *overengineering*, achei que essa seria uma boa oportunidade
para praticar alguns assuntos que estudei anteriormente.

## Estrutura do Projeto

O projeto segue a seguinte estrutura de diretórios:

```bash
.
├── README.md                       # Documentação do projeto
├── apps
│   └── CartasSuperTrunfo.c         # Arquivo principal com a função `main`
├── include
│   └── city.h                      # Arquivo de cabeçalho contendo declarações relacionadas às cidades
└── src
    └── city.c                      # Implementação das funções relacionadas às cidades
```

---

### NOTA

**Essa estrutura foi baseada na estrutura utilizada pelo professor Samuel
Martins no curso [Dominando Estruturas de Dados 1](https://github.com/xavecoding/dominando-estruturas-de-dados-1).
O uso de ponteiros, das funções `calloc` e `free`; da estrutura de dados
`struct`; de *include guards* e qualquer outro tema que não tenha sido ainda
abordado na disciplina "Introdução à Programação de Computadores", foi aprendido
no curso informado. A excessão é o uso de documentação Doxygen, que eu aprendi
enquanto resolvia este desafio.**

**Pensei também em adicionar validação na entrada de dados, como validação do
código da carta, por exemplo, mas não adicionei pois achei que seria ainda mais
uso de *overengineering***.

## Detalhes de implementação

O número máximo de cidades que podem ser cadastradas é 32, correspondente à
quantidade de cartas no jogo original. As cidades são armazenadas em uma lista
de ponteiros, chamada `city_list`, alocada na memória estática.

Cada ponteiro na lista aponta para uma estrutura do tipo `City`, que é alocada
dinamicamente na memória heap à medida que o usuário cadastra novas cartas. Essa
estrutura organiza os dados de cada cidade, como estado, código da carta, nome,
população, área, PIB e número de pontos turísticos.

Na exibição dos dados, os caracteres que podem não ser interpretados
corretamente em qualquer terminal, como acentos ortográficos, foram removidos
para garantir compatibilidade.

Não adicionei comentários na implementação das funções, em `city.c`, porque o
código ficaria muito poluído. Porém, adicionei documentação na declaração das
funções, em `city.h`, com o uso de Doxygen.

---

## Compilação

O comando usado para compilar foi:

```bash
gcc apps/CartasSuperTrunfo.c -o CartasSuperTrunfo src/city.c -I include
```

Explicação:

- `gcc`: Compilador utilizado.
- `apps/CartasSuperTrunfo.c`: Arquivo principal com a função main.
- `-o CartasSuperTrunfo`: Nome do executável gerado.
- `src/city.c`: Implementação das funções auxiliares.
- `-I include`: Diretório que contém os arquivos de cabeçalho.

Você precisa especificar os arquivos ou diretórios necessários durante a
compilação para garantir que todas as dependências sejam incluídas.

## Funcionamento do projeto

O fluxo básico de interação com o usuário segue as etapas abaixo:

1. O programa solicita que o usuário insira as propriedades de uma cidade, como
estado, código da carta, nome da cidade, população, entre outros detalhes.
2. O usuário fornece as propriedades, uma por uma.
3. Se todos os dados forem válidos, a cidade é adicionada à lista de cidades
registradas.
4. O programa exibe uma mensagem confirmando o registro da cidade.
5. Em seguida, as propriedades da cidade recém-registrada são exibidas na tela.
6. Se o número total de cidades registradas ainda não atingiu o limite máximo
permitido, o programa pergunta ao usuário se deseja registrar outra cidade:
    - Caso o usuário responda sim, o fluxo retorna ao passo 1.
    - Caso o usuário responda não, o programa é encerrado.
7. Se o número máximo de cidades já tiver sido alcançado, o programa é encerrado
automaticamente.
