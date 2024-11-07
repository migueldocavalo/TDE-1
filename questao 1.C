#include <stdio.h>

#define MAX_P 4
#define NOME_MAX 20

typedef struct {
    int id;
    char nome[NOME_MAX];
    float valor;
} Produto;

int main() {
    Produto p[MAX_P];

    for (int i = 0; i < MAX_P; i++) {
        printf("ID do produto %d: ", i + 1);
        scanf("%d", &p[i].id);
        printf("Nome do produto %d: ", i + 1);
        scanf("%s", p[i].nome);
        printf("Valor do produto %d: ", i + 1);
        scanf("%f", &p[i].valor);
    }

    printf("\nDados dos Produtos:\n");
    for (int i = 0; i < MAX_P; i++) {
        printf("Produto %d:\nID: %d\nNome: %s\nValor: %.2f\n-----------------------\n",
               i + 1, p[i].id, p[i].nome, p[i].valor);
    }

    float valorLimite;
    printf("Valor para contar produtos abaixo dele: ");
    scanf("%f", &valorLimite);
    int qtd = 0;
    for (int i = 0; i < MAX_P; i++) {
        if (p[i].valor < valorLimite) {
            qtd++;
        }
    }
    printf("Quantidade de produtos abaixo de %.2f: %d\n", valorLimite, qtd);

    int idBusca;
    printf("ID do produto a ser buscado: ");
    scanf("%d", &idBusca);
    for (int i = 0; i < MAX_P; i++) {
        if (p[i].id == idBusca) {
            printf("Produto encontrado:\nID: %d\nNome: %s\nValor: %.2f\n",
                   p[i].id, p[i].nome, p[i].valor);
        
    }
    else{
        printf("Produto com ID %d não encontrado.\n", idBusca);
    }
    }

    int idAtualiza;
    float novoValor;
    printf("ID do produto para atualizar o valor: ");
    scanf("%d", &idAtualiza);
    printf("Novo valor: ");
    scanf("%f", &novoValor);
    for (int i = 0; i < MAX_P; i++) {
        if (p[i].id == idAtualiza) {
            p[i].valor = novoValor;
            printf("Valor do produto ID %d atualizado para %.2f.\n", idAtualiza, novoValor);
        
    }
    else{
        printf("Produto com ID %d não encontrado para atualizar.\n", idAtualiza);
    }
    }

    float soma = 0;
    for (int i = 0; i < MAX_P; i++) {
        soma += p[i].valor;
    }
    float media = soma / MAX_P;
    printf("Média dos preços: %.2f\n", media);

    printf("Produtos acima da média (%.2f):\n", media);
    for (int i = 0; i < MAX_P; i++) {
        if (p[i].valor > media) {
            printf("ID: %d, Nome: %s, Valor: %.2f\n", p[i].id, p[i].nome, p[i].valor);
        }
    }

    return 0;
}
