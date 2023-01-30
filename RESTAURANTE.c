//29.01.2023
/*
CODIGO IMPLEMENTANDO O FUNCIONAMENTO BÁSICO DE UM RESTAURANTE, REALIZANDO ALGUMAS OPERAÇÕES NECESSÁRIAS COMO:
    - FILA DE CLIENTES
    - REALIZAÇÃO DE UMA COMANDA
    - SOMA DOS ITENS PEDIDOS
    - CANCELAMENTO DE ALGUM ITEM
    - REALIZAR PAGAMENTO
    - SAIDA COM CLIENTE + ENTREGA DE CHOCOLATE

Membros da equipe:  Vanessa Rosa da Costa 12011BSI238
                    Nicolas Nery Castro Silva 12121BSI253
                    Renata Virna Balbino 12111BSI201
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cardapio.h"
#include "fila.h"

struct cliente{
    FILE *comanda;
    char nome[20];
};
typedef struct cliente Cliente;

struct item{
    int codigo;
    char nome[MAX];
    float valor;
};

struct node{
    int c;
    Item itens[3];
    struct node *next;
};

struct lista{
    Node *head;
};

struct node_fila{
    char nome[20];
    FILE *com;
    struct node_fila *next;
};

struct fila{
    No *primeiro;
    No *ultimo;
};

//inicializa o cardápio, criando a listá com os 3 nós do cardapio
Lista *cardapio_iniciar(){
    FILE *arquivo;
    char caminho_um[20] = "nome_bebidas.txt";
    char caminho_dois[20] = "nome_comidas.txt";
    char caminho_tres[20] = "nome_sobremesas.txt";
    Lista *lista;
    Node *node;
    Item vetor_aux[3];
    int codig_temp;
    float valor_temp;
    char nome_aux[MAX];

    //cria a lista e aloca memoria
    lista = criar();
    if (lista == NULL)
    {
        printf("Nao foi possivel criar lista.\n");
        exit(1);
    } else
    {
        //laço que percorre a lista e escolhe o arquivo
        for (int i = 1; i <= 3; i++)
        {
            //printf("oi\n");
            //j percorre as posições do vetor
            int j = 0;
            if (i == 1)
            {
                //printf("oii\n");
                arquivo = fopen(caminho_um,"r");
                if (arquivo == NULL)
                {
                    printf("Falha ao abrir arquivo.\n");
                    break;
                }
                
                for (j = 0; j < 3; j++)
                {
                    //printf("oie\n");
                    //le codigo do item
                    fscanf(arquivo,"%d *%s *%f",&codig_temp);
                    vetor_aux[j].codigo = codig_temp;
                    //printf("%d\n",vetor_aux[j].codigo);

                    //le nome do item
                    fgets(nome_aux,15,arquivo);
                    strcpy(vetor_aux[j].nome,nome_aux);
                    //printf("%s",vetor_aux[j].nome);

                    //le valor
                    fscanf(arquivo,"%f",&valor_temp);
                    vetor_aux[j].valor = valor_temp;
                    //printf("%.2f\n",vetor_aux[j].valor);
                }
                
            }

            if (i == 2)
            {
                //printf("oi\n");
                arquivo = fopen(caminho_dois,"r");
                if (arquivo == NULL)
                {
                    printf("Falha ao abrir arquivo.\n");
                    break;
                }
                
                for (j = 0; j < 3; j++)
                {
                    //le codigo do item
                    fscanf(arquivo,"%d *%s *%f",&codig_temp);
                    vetor_aux[j].codigo = codig_temp;
                    //printf("%d\n",vetor_aux[j].codigo);

                    //le nome do item
                    fgets(nome_aux,15,arquivo);
                    strcpy(vetor_aux[j].nome,nome_aux);
                    //printf("%s",vetor_aux[j].nome);

                    //le valor
                    fscanf(arquivo,"%f",&valor_temp);
                    vetor_aux[j].valor = valor_temp;
                    //printf("%.2f\n",vetor_aux[j].valor);
                }
            }
            
            if (i == 3)
            {
                arquivo = fopen(caminho_tres,"r");
                if (arquivo == NULL)
                {
                    printf("Falha ao abrir arquivo.\n");
                    break;
                }
                
                for (j = 0; j < 3; j++)
                {
                    //le codigo do item
                    fscanf(arquivo,"%d *%s *%f",&codig_temp);
                    vetor_aux[j].codigo = codig_temp;
                    //printf("%d\n",vetor_aux[j].codigo);

                    //le nome do item
                    fgets(nome_aux,15,arquivo);
                    strcpy(vetor_aux[j].nome,nome_aux);
                    //printf("%s",vetor_aux[j].nome);

                    //le valor
                    fscanf(arquivo,"%f",&valor_temp);
                    vetor_aux[j].valor = valor_temp;
                    //printf("%.2f\n",vetor_aux[j].valor);
                }
            }
            
            //envia a lista, o número do nó a ser criado, e o vetor de itens já completo com todos os valores
            insere(lista,i,vetor_aux);
        }
    }

    fclose(arquivo);

    return lista;
}

//funçao que adiciona uma nova pessoa a fila
//cria a comanda
void entrada(int contador, Fila *f){
    //primeiramente, cria o arquivo .txt da comanda do cliente
    FILE *c;
    Cliente *cliente;
    char nome[20];
    char comanda[25];
    int numero;
    char num[10];
    char a[10] = ".txt";
    char comanda_final[30];

    printf("\t\tINICIANDO A SUA COMANDA\n");

    printf("Insira seu nome: \n");
    scanf("%s", &nome);

    //contador que representa o nome das comandas, pela ordem de chegada dos clientes
    numero = contador;
    sprintf(num,"%d",numero);
    //concatenação das strings para poder ser usada na função fopen()
    strcat(comanda,num);
    strcat(comanda,a);

    c = fopen(comanda,"w+");

    //insere um novo cliente na fila
    insere_fila(f,nome,c);

    imprime_Fila(f);

    //fclose(c);
}

//função que recebe o pedido do cliente, e a armazena dentro da comanda
void pedido(int contador, Fila *f){
    int opc, cod, num, qtd;
    FILE *comand, *a;
    char nome[20];
    Lista *l;
    char numero[20];
    char txt[10] = ".txt";
    char comandaa[30];

    //abre a lista do cardapio
    l = cardapio_iniciar();

    //transformando o contador em string
    sprintf(numero,"%d",contador);
    
    comand = f->primeiro->com;

    printf("////////////////////////Cardápio////////////////////\n");

    //colocar os precos nos itens do cardapio
    printf("===Bebidas===\n");
    printf("\n [101]Agua\t\t\tR$1.00\n [102]Suco\t\t\tR$3.00\n [103]Refrigerante\t\t\tR$4.00\n");

    printf("===Prato principal===\n");
    printf("\n [201]Coxinha\t\t\tR$5.00\n [202]Sanduiche\t\t\tR$6.00\n [203]Pizza\t\t\tR$7.00\n");

    printf("===Sobremesas===\n");
    printf("\n [301]Bolo\t\t\tR$5.00\n [302]Brownie\t\t\tR$4.00\n [303]Trufa\t\tR$3.00\n");
    printf("///////////////////////////////////////////////////\n");

    printf("Deseja iniciar o seu pedido?\n");
    printf("[1] SIM\t\t[2] NAO\n");
    scanf("%d",&opc);
    if (opc == 2)
    {
        exit(1);
    } 
    
    while (opc == 1)
    {
        printf("///////////////////////////////////////////////////\n");
        printf("O que deseja pedir?\n");
        printf("\n[1]BEBIDAS\t\t[2]PRATO PRINCIPAL\t\t[3]SOBREMESAS\n");
        scanf("%d",&opc);

        //laço dependendo de qual nó o item do pedido está
        if (opc == 1)
        {
            printf("Digite o codigo da bebida que deseja pedir.\n");
            scanf("%d", &cod);

            //percorre as posições do vet[3] onde está on itens 
            for (int i = 0; i < 3; i++)
            {
                if (cod == l->head->itens[i].codigo)
                {
                    printf("Item: %s", l->head->itens[i].nome);
                    
                    printf("Qual a quantidade?\n");
                    scanf("%d",&qtd);

                    printf("\nPedido: %dx %s\n",qtd,l->head->itens[i].nome);

                    //guarda na comanda do cliente o que foi pedido
                    fprintf(comand,"%s%d\n",l->head->itens[i].nome,qtd);
                }
            }
        }

        if (opc == 2)
        {
            printf("Digite o codigo do prato principal que deseja pedir.\n");
            scanf("%d", &cod);

            for (int i = 0; i < 3; i++)
            {
                if (cod == l->head->next->itens[i].codigo)
                {
                    printf("Item: %s", l->head->next->itens[i].nome);
                    
                    printf("Qual a quantidade?\n");
                    scanf("%d",&qtd);

                    printf("\nPedido: %dx %s\n",qtd,l->head->next->itens[i].nome);

                    //guarda na comanda do cliente o que foi pedido
                    fprintf(comand,"%s%d\n",l->head->next->itens[i].nome,qtd);
                }
            }
        }

        if (opc == 3)
        {
            printf("Digite o codigo da sobremesa que deseja pedir.\n");
            scanf("%d", &cod);

            for (int i = 0; i < 3; i++)
            {
                if (cod == l->head->next->next->itens[i].codigo)
                {
                    printf("Item: %s", l->head->next->next->itens[i].nome);
                    
                    printf("Qual a quantidade?\n");
                    scanf("%d",&qtd);

                    printf("\nPedido: %dx %s\n",qtd,l->head->next->next->itens[i].nome);

                    //guarda na comanda do cliente o que foi pedido
                    fprintf(comand,"%s%d\n",l->head->next->itens[i].nome,qtd);
                }
            }
        }

        printf("Deseja pedir novamente?\n");
        printf("[1]SIM\t[2]NAO\n");
        scanf("%d",&opc);
        if (opc == 1)
        {
            continue;
        }
        
    }
    
    //fecha comanda
    fclose(comand);   
}

float *pagamento(int contador, Fila *f, int conta_pag){
    FILE *c;
    int qtd;
    int aux;
    int cod;
    float valor;
    float total;
    char item[20];
    char comanda[20];
    char n_ome[20];
    char w[10];
    char txt[5] = ".txt";
    Lista *l;
    Node *aux_lista;

    l = cardapio_iniciar();
    aux_lista = l->head;

    //printf("oi\n");
    aux = conta_pag;
    sprintf(item,"%d",aux);
    strcat(item,txt);

    //printf("oi\n");
    c = fopen(item,"r");
    if (c == NULL)
    {
        printf("Nao foi possivel abrir comanda.\n");
    }
    
    //printf("oi\n");
    int j = 0;
    while (!feof(c))
    {        
        
        fgets(n_ome,10,c);
        fscanf(c,"%d",&qtd);
        fgets(w,10,c);
        //printf("*%s", n_ome);
        
        for (int i = 0; i < 3; i++) //percorre os nós
        {
            //printf("oie\n");
            
            for (int k = 0; k < 3; k++) //percorre o vetor dentro do nó
            {
                //printf("oiee\n");
                //printf("%s\n",aux_lista->itens[k].nome);
                if (strcmp(aux_lista->itens[k].nome,n_ome) == 0){
                    

                    valor = aux_lista->itens[k].valor;
                    total += (valor * qtd);
                    
                    printf("\nItem:%s\tValor: %.2f\tQuantidade: %d\n", n_ome, valor, qtd);

                    continue;
                } 
            }
            
            aux_lista = aux_lista->next;
        }
        
        printf("oi\n");
        printf("Total a ser pago: %.2f\n", total);
    }
    printf("oie\n");

    //remove(item);
}

void finaliza(Fila *f){
    remove_fila(f);
}

void menu(Fila *f){
    int opcao;
    int contador = 1;
    int conta_dois = 1;

    while(1){
        printf("///////////////////////MENU//////////////////\n");
        printf("[1]ENTRADA\t\t[4]PAGAMENTO\n");
        printf("[2]PEDIDO\t\t[5]FINALIZAR\n");
        printf("[3]CANCELAMENTO\n\t\t[6]SAIR\n\n");
        
        printf("O que deseja fazer?\n");
        scanf("%d", &opcao);

        if (opcao == 1) entrada(contador,f);        
        if (opcao == 2) pedido(contador,f); 
        //if (opcao == ) cancela(opcao);
        if (opcao == 4) 
        {
            pagamento(contador,f,conta_dois);
            conta_dois++;
        }
        if (opcao == 5) finaliza(f);
        if (opcao == 6) exit(1);
        
        contador++;
        
    }

}

int main(){
    printf("\t\tBEM VINDO\n");
    printf("\t   RESTAURANTE ABACATE\n"); //NAO MEXE NO ESPAÇO

    //chama o TAD que inicializa o cardápio
    //cardapio_iniciar();

    //inicializa a fila
    Fila *f;
    f = cria_f();

    menu(f);
}
