# Final_ED1
Trabalho final de Estrutura de Dados 1, 2022/2

Nesse trabalho, inicialmente planejamos em utilizar o cardápio a partir de arquivos .txt. Para realizarmos isso, dividimos o cardápio em três arquivos .txt, cada um responsável por um tipo de item: bebidas, comidas e sobremesas. Depois disso, foi necessário criar uma lista encadeada com três nós, e em cada nó guardar em structs as informações dos itens. Essa struct é composta por:
  - int c : indica se o nó está armazenando bebidas, comidas ou sobremesas
  - Item vet[3] : um vetor de tamanho 3, que guarda três struct Item. Struct essa que armazena os dados do item como o código, o nome e o valor.
  - *next : ponteiro pro próximo nó

O programa tem a fila dos clientes que foi criada por meio de lista encadeada. Cada nó da fila dos clientes é composto pelo nome do cliente e por um arquivo .txt que representa a sua respectiva comanda.
Depois disso, dividimos o programa em 5 principais funções:
  - ENTRADA : adiciona a pessoa na fila e cria a comanda
  - PEDIDO : o cliente entra qual o código do item que ele deseja, e tal item é printado dentro do arquivo txt que é a comanda dele juntamente com a quantidade de itens que foi pedida
  - PAGAMENTO : a partir dos dados printados, será feita a procura dentro da lista do cardápio, os vlaores serão multiplicados por suas quantidades e o valor final a ser pago será printado na tela. 
  - FINALIZAR : deleta a comanda do cliente e remove o primeiro da fila após ele ser atendido. O cliente também recebe o chocolate, esse que é removido da pilha de chocolate.

Fizemos os módulos "cardapio.h" e "fila_clientes.h", utilizando o princípio dos TADs, para assim facilitar e poluir menor o código principal do restaurante. Há também em anexo os arquivos .txt base para a criação do cardápio. Para o uso das bibliotecas, como foram apenas duas as utilizadas, optamos por não criar o MAKEFILE e no lugar compilar todas as bibliotecas juntas no gcc. Na hora compilação, foi feito da seguinte forma:
  gcc -o rest RESTAURANTE.c cardapio.c fila.c
Não houveram problemas quanto a compilação quando rodamos o programa dessa maneira. 

O programa não é perfeito, ainda há muito espaço para melhoras e aperfeiçoamentos mas, para aquilo a qual ele se propõe fazer, ele funciona muito bem. 
