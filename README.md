# Atividade-Parcial-N2
Estrutura de dados questões teoricas

1.O que significa alocação estática de memória para um conjunto de elementos?

Alocação de memória é um conceito muito utilizado em estrutura de dados, basicamente quando falamos desse conceito estamos nos referindo a espaço de memória reservado para armazenar elementos nesse conceito a memória é reservada de forma fixa não permetindo a expansão.

2.Qual a diferença entre alocação estática e alocação dinâmica?

A principal diferença entre alocação estática e dinâmica se dá na alocação do espaço de memória.
Quando vamos a construção de uma estrutura e sabemos o tamanho de espaço que vamos utilizar devemos usar a alocação estática quee é mais rápido e fácil de usar, agora quando vamos construir uma estrutura e sabemso que vai ser utlizado para armazenar dados em grande quantidade sem definição de quantidade devemos utilizar a alocação dinâmica que permite o tamanho aumentar ou diminuir enquando o programa estiver rodaando.

3.O que é um ponteiro?

O ponteiro é uma variável que podemos utilizar para armazenar endereço de memória, essa variável é muito utilizada quando optamos pela criação de um estrutura de dados que possui alocação dinâmica, a variável ponteiro nós permite navegar pelos dados armazenados.

4.O que é uma estrutura de dados homogêneos?

A estrutura de dados homogêneos é um conceito bem simples, podemos afirma que essa estrutura é uma coleção de elementos do mesmo tipo.

5.O que é uma estrutura de dados heterogêneos?

A estrutura de dados heterogêneos é o oposto da estrutura de dados homogêneos ou seja: dados heterogêneos são um cnjunto de elementos de tipos de dados diferentes.

6.Qual a vantagem das listas sobre os vetores em termos de consumo de memória?
Exemplifique.

A principal vantagem na utilização dos vetores é a melhor performace no uso de espaço de memória sem o disperdício de memória tornando o programa mais rápido e eficiente.
Exemplo: 
Quando temos já pré estabelecido a quantidade de armazenamento que será utilizado como quantidade de alunos em uma sala de aula, podemos utilizar a estrutura dos vetores para fazer o armazenamento dos dados tornado a exeecução do programa mais rápido e sem desperdicio de memória.

7.O que é uma lista simplesmente encadeada? Apresente um diagrama para ilustrar
essa estrutura de dados.

Uma lista simplesmente encadeada é uma estrutura de dados dinâmica os elementos são ligados entre si por ponteiros onde são utilizados uma sequência de nós permitindo inserir e remover elementos facilmente

SEGUE DIAGRAMA:
[ Dado | Próximo ] -> [ Dado | Próximo ] -> [ Dado | Próximo ] -> NULL

8.O que é uma lista duplamente encadeada? Apresente um diagrama para ilustrar
essa estrutura de dados.

A lista duplamente encadeada é parecida com  lista simplesmente encadeada a diferença agora para cada nó é necessário dois ponteiros o que permite que a lista seja percorridar nos dois sentidos, para as informações que estão a frente e as informações que estão atrás o que facilita a inserção e remoção dde eelementos em quaalquer direção.

SEGUE DIAGRAMA: 
NULL ← [Prev | Dado | Next] ↔ [Prev | Dado | Next] ↔ [Prev | Dado | Next] → NULL

9.Explique o funcionamento do algoritmo de busca binária e sequencial.

Percorre a lista do início ao fim, comparando o elemento procurado com cada item, um por um, até encontrar 
Divide a lista ordenada repetidamente pela metade para encontrar o elemento desejado.
A cada passo, descarta metade dos elementos, tornando o processo muito mais rápido.

A lista deve estar ordenada.

Encontra o elemento do meio.
  
Compara com o valor procurado:
  
Se for igual → encontrado!
  
Se for menor, busca na metade direita.
  
Se for maior, busca na metade esquerda.
  
Repete o processo na metade escolhida até encontrar o elemento ou restar 1 item.

10.Explique o funcionamento dos seguintes algoritmos de ordenação: Insertion sort,
Selection sort, Merge sort, Count sort, Quicksort.

Insertion Sort

Funciona como se estivéssemos organizando cartas na mão.
A cada passo, ele pega um elemento e o insere na posição correta entre os anteriores.
Começa do segundo elemento da lista.
	Compara com os anteriores até encontrar a posição certa.
	Desloca os elementos maiores para a direita e insere o novo na posição correta.
	Repete até o final da lista

  Selection Sort

A cada passo, o algoritmo procura o menor elemento e o coloca na primeira posição não ordenada.
       Encontra o menor elemento da lista.
	Troca com o primeiro.
	Depois, procura o menor do restante e troca com o segundo, e assim por diante.

  Merge Sort

Segue o conceito de dividir para conquistar.
Divide a lista em partes menores, ordena cada uma e depois intercala (merge) tudo ordenadamente.

  Divide a lista ao meio até restarem listas de 1 elemento.
	Junta (merge) duas listas ordenadas em uma só.
	Repete até restar uma lista completa e ordenada.

  Count Sort

Conta quantas vezes cada valor aparece e depois usa essas contagens para montar a lista ordenada.
Ideal para números inteiros pequenos
	Encontra o maior valor da lista.
	Cria um vetor de contagem (índices = valores possíveis).
	Conta quantas vezes cada número aparece.
	Usa as contagens para reconstruir a lista ordenada.
