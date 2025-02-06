# Documentação

Eu alterei a estrutura do projeto e utilizei conceitos que ainda não foram
ensinados na disciplina, mas que possuo conhecimento sobre. Espero que isso não
seja um problema. Mas caso venha a ser, gostaria de uma oportunidade para
resolvê-lo.

Apesar do uso de *overengineering*, achei que essa seria uma boa oportunidade
para praticar e entender melhor, além dos conceitos ensinados na disciplina, o
uso de:

- Headers
- Doxygen
- Include Guards
- Ponteiros
- Alocação e liberação de memória stack e heap
- Structs e enums

## Nível do Projeto

O projeto contempla as funcionalidades dos níveis Novato, Aventureiro e Mestre.

## Índice

- [Documentação](#documentação)
  - [Nível do Projeto](#nível-do-projeto)
  - [Índice](#índice)
  - [Estrutura do Projeto](#estrutura-do-projeto)
    - [NOTA](#nota)
  - [Compilação](#compilação)
  - [Funcionamento do projeto](#funcionamento-do-projeto)
    - [1. Registro de cartas](#1-registro-de-cartas)
    - [2. Registro de duas cartas e comparação das suas propriedades numéricas](#2-registro-de-duas-cartas-e-comparação-das-suas-propriedades-numéricas)
    - [Validação](#validação)
    - [Compatibilidade](#compatibilidade)
  - [Passo a passo dos fluxos](#passo-a-passo-dos-fluxos)
    - [Registro de cartas](#registro-de-cartas)
    - [Registro de duas cartas e comparação das suas propriedades numéricas](#registro-de-duas-cartas-e-comparação-das-suas-propriedades-numéricas)
      - [Possíveis resultados da comparação](#possíveis-resultados-da-comparação)

## Estrutura do Projeto

O projeto segue a seguinte estrutura de diretórios:

```bash
.
├── DOCUMENTACAO.md                 # Documentação do projeto
├── README.md                       # Instruções do Projeto
├── apps
│   └── CartasSuperTrunfo.c         # Arquivo principal com a função `main`
├── include                         # Arquivos de cabeçalhos contendo as declarações das funções
│   ├── card.h
│   ├── city.h
│   ├── interface.h
│   └── util.h
└── src                             # Arquivos de implementação das funções declaradas nos cabeçalhos
    ├── card.c
    ├── city.c
    ├── interface.c
    └── util.c
```

---

### NOTA

**Essa estrutura foi baseada na estrutura utilizada pelo professor Samuel
Martins no curso [Dominando Estruturas de Dados 1](https://github.com/xavecoding/dominando-estruturas-de-dados-1).
O uso de ponteiros, das funções `calloc` e `free`, da estrutura de dados
`struct`, de *include guards* e qualquer outro tema que não tenha sido abordado
na disciplina "Introdução à Programação de Computadores", foi aprendido no curso
mencionado. A excessão é o uso da documentação Doxygen, que eu aprendi enquanto
resolvia este desafio.**

## Compilação

O comando usado para compilar foi:

```bash
gcc apps/CartasSuperTrunfo.c -o CartasSuperTrunfo src/*.c -I include
```

Explicação:

- `gcc`: Compilador utilizado.
- `apps/CartasSuperTrunfo.c`: Arquivo principal com a função main.
- `-o CartasSuperTrunfo`: Nome do executável gerado.
- `src/*.c`: Arquivos com a implementação das funções declaradas nos cabeçalhos.
- `-I include`: Diretório que contém os arquivos de cabeçalho.

Deve-se especificar os arquivos ou diretórios necessários durante a compilação
para garantir que todas as dependências sejam incluídas.

## Funcionamento do projeto

O projeto possui dois fluxos:

### 1. Registro de cartas

Neste fluxo, o usuário pode registrar os dados de cidades e visualizar as
informações cadastradas logo após cada registro.

- O número máximo de cidades que podem ser cadastradas é **32**,
correspondente à quantidade de cartas no jogo original.
- As cidades são armazenadas em uma lista de ponteiros chamada `city_list`,
que é alocada na memória estática.
- Cada elemento dessa lista é um ponteiro para uma estrutura do tipo `City`,
que é alocada dinamicamente na memória heap à medida que o usuário cadastra
novas cidades.
- A estrutura `City` organiza os dados de cada cidade, incluindo:
  - Estado.
  - Código da carta.
  - Nome da cidade.
  - População.
  - Área.
  - Densidade populacional: calculada como a razão entre População e Área.
  - PIB.
  - PIB per capita: calculado como a razão entre PIB e População.
  - Número de pontos turísticos.
  - Super poder: calculado como a soma do inverso da densidade populacional
  com todas as outras propriedades de valores numéricos.

### 2. Registro de duas cartas e comparação das suas propriedades numéricas

Neste fluxo, o usuário registra os dados de duas cartas conforme solicitado
pelo programa. Após o registro, são exibidos os valores tratados de cada carta e
o resultado da comparação de cada um dos valores numéricos das cartas, incluindo
a propriedade "Super Poder" que é a soma de todas as propriedades numéricas com
o inverso da densidade populacional.

---

Ao rodar o projeto, o programa apresenta ao usuário os fluxos de execução e
pergunta ao usuário qual fluxo ele deseja executar:

```terminal
O programa possui as seguintes funcionalidades:

1. Registro de cartas: Voce pode registrar e ver os dados registrados para cada carta.
2. Registro e comparacao de duas cartas: Voce pode registrar duas cartas e ver a comparacao entre os dados registrados para cada propriedade de cada carta.

Escolha o numero da opcao que deseja executar: 
```

### Validação

Caso o usuário insira um valor inválido, uma mensagem será exibida informando
que o valor inserido é inválido e será solicitado um novo valor até que o
usuário insira uma opção válida.

### Compatibilidade

Na exibição dos dados, caracteres que podem não ser interpretados corretamente
em todos os terminais (como acentos ortográficos) foram removidos para garantir
a compatibilidade.

## Passo a passo dos fluxos

### Registro de cartas

Caso o fluxo escolhido seja o fluxo de registro de cartas, as propriedades da
primeira carta serão solicitadas uma a uma:

```bash
Escolha o numero da opcao que deseja executar: 1   # Número referente ao registro de cartas

Digite o estado: 
```

```bash
Digite o estado: A   # Valor 'A' inserido
Digite o codigo da carta:
```

```bash
Digite o estado: A
Digite o codigo da carta: A01   # Valor "A01" inserido
Digite o nome da cidade: 
```

até que todos os valores sejam inseridos:

```bash
Digite o estado: A
Digite o codigo da carta: A01
Digite o nome da cidade: Sao Paulo
Digite a populacao: 12325000
Digite a area: 1521.11
Digite o PIB: 699280000000
Digite o numero de pontos turisticos: 50
```

Após a inserção de todos os valores, o programa informa que o registro da carta
foi bem sucedido, mostra os valores tratados da carta e pergunta ao usuário se
deseja registrar outra carta:

```bash
Carta registrada com sucesso.

Estado: A
Codigo da Carta: A01
Nome da Cidade: Sao Paulo
Populacao: 12325000
Area: 1521.11 km²
Densidade Populacional: 8102.64 pessoas/km²
PIB: 699.28 bilhoes de reais
PIB per Capta: 56737 reais
Numero de Pontos Turisticos: 50

Registrar outra carta? (S/N): 
```

- Caso o usuário opte por não registrar outra carta, o programa encerra sua
execução.
- Caso o usuário opte por continuar cadastrando, o processo se repetirá até um
limite de 32 cartas registradas. Então, o programa exibe a seguinte mensagem e
termina sua execução:

```bash
Numero maximo de registros atingido.
```

---

### Registro de duas cartas e comparação das suas propriedades numéricas

Caso o fluxo escolhido seja o fluxo de registro de duas cartas e comparacao das
suas propriedades numéricas, as propriedades da primeira e segunda cartas serão
solicitadas uma a uma:

```bash
Escolha o numero da opcao que deseja executar: 2   # Número referente ao registro de duas e cartas comparação das suas propriedades numéricas

Digite o estado: 
```

```bash
Digite o estado: A   # Valor 'A' inserido
Digite o codigo da carta:
```

```bash
Digite o estado: A
Digite o codigo da carta: A01   # Valor "A01" inserido
Digite o nome da cidade: 
```

até que todos os valores sejam inseridos:

```bash
Digite o estado: A
Digite o codigo da carta: A01
Digite o nome da cidade: Sao Paulo
Digite a populacao: 12325000
Digite a area: 1521.11
Digite o PIB: 699280000000
Digite o numero de pontos turisticos: 50
```

Logo em seguida o programa pede a inserção dos dados da segunda, de um a um,
até que todos os dados sejam inseridos:

```bash
Digite o estado da segunda carta: B
Digite o codigo da segunda carta: B01
Digite o nome da cidade da segunda carta: Cidade Aleatoria
Digite a populacao da segunda carta: 150000000
Digite a area da segunda carta: 1510.08
Digite o PIB da segunda carta: 596000000000
Digite o numero de pontos turisticos da segunda carta: 39
```

Após receber os dados, o programa exibe os dados registrados e calculados
para cada carta:

```bash
Dados registrados para a carta 1:

Estado da carta 1: A
Codigo da carta 1: A01
Nome da Cidade da carta 1: Sao Paulo
Populacao da carta 1: 1232500
Area da carta 1: 1521.11 km²
Densidade Populacional da carta 1: 810.26 pessoas/km²
PIB da carta 1: 699.28 bilhoes de reais
PIB per Capta da carta 1: 567367 reais
Numero de Pontos Turisticos da carta 1: 50
Super Poder da carta 1: 699281833984.00

Dados registrados para a carta 2:

Estado da carta 2: B
Codigo da carta 2: B01
Nome da Cidade da carta 2: Cidade Aleatoria
Populacao da carta 2: 150000000
Area da carta 2: 1510.08 km²
Densidade Populacional da carta 2: 99332.49 pessoas/km²
PIB da carta 2: 596.00 bilhoes de reais
PIB per Capta da carta 2: 3973 reais
Numero de Pontos Turisticos da carta 2: 39
Super Poder da carta 2: 596149993472.00
```

Em seguida, o programa realiza e exibe a comparação das propriedades, mostrando
quem foi a carta vencedora em cada propriedade:

```bash
Comparando as cartas: Caso a carta 1 seja a vencedora, o resultado será 1. Caso a carta 2 seja a vencedora, o resultado será 0.

Qual carta tem maior populacao? 0. Portanto, a carta 2 ganhou.
Qual carta tem maior area? 1. Portanto, a carta 1 ganhou.
Qual carta tem menor densidade populacional? 1. Portanto, a carta 1 ganhou.
Qual carta tem maior PIB? 1. Portanto, a carta 1 ganhou.
Qual carta tem maior PIB per Capta? 1. Portanto, a carta 1 ganhou.
Qual carta tem maior numero de pontos turisticos? 1. Portanto, a carta 1 ganhou.
Qual carta tem maior super poder? 1. Portanto, a carta 1 ganhou.
```

#### Possíveis resultados da comparação

- `1. Portanto, a carta 1 ganhou.`
- `0. Portanto, a carta 2 ganhou.`

Após apresentar os resultados da comparação, o programa encerra sua execução.
