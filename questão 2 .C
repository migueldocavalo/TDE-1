
#define MAX_CLUBES 10

struct Clube {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int golsPro;
    int golsContra;
};

int main() {
    struct Clube clubes[MAX_CLUBES];
    int n = 0;

    
    while (n < MAX_CLUBES) {
        printf("Cadastrar Clube %d:\n", n + 1);
        printf("ID: ");
        scanf("%d", &clubes[n].id);
        printf("Nome: ");
        scanf(" %[^\n]", clubes[n].nome);
        printf("Vitórias: ");
        scanf("%d", &clubes[n].vitorias);
        printf("Empates: ");
        scanf("%d", &clubes[n].empates);
        printf("Derrotas: ");
        scanf("%d", &clubes[n].derrotas);
        printf("Gols Pró: ");
        scanf("%d", &clubes[n].golsPro);
        printf("Gols Contra: ");
        scanf("%d", &clubes[n].golsContra);
        n++;

        char continuar;
        printf("Cadastrar outro clube? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar != 's') {
            break;
        }
    }

    printf("\nPontuação dos clubes:\n");
    for (int i = 0; i < n; i++) {
        int pontuacao = (clubes[i].vitorias * 3) + (clubes[i].empates * 1);
        printf("Clube: %s, Pontuação: %d\n", clubes[i].nome, pontuacao);
    }

    int idbusca;
    printf("\nBuscar clube pelo ID: ");
    scanf("%d", &idbusca);
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (clubes[i].id == idbusca) {
            printf("Clube encontrado: %s\n", clubes[i].nome);
            printf("Vitórias: %d, Empates: %d, Derrotas: %d\n", clubes[i].vitorias, clubes[i].empates, clubes[i].derrotas);
            printf("Gols Pró: %d, Gols Contra: %d\n", clubes[i].golsPro, clubes[i].golsContra);
    
    }
    else{
        printf("Clube com ID %d não encontrado.\n", idbusca);
    }}
    int totalGolsPro = 0;
    for (int i = 0; i < n; i++) {
        totalGolsPro += clubes[i].golsPro;
    }
    float mediaGolsPro = (float)totalGolsPro / n;

    printf("\nClubes com gols pró acima da média (%.2f):\n", mediaGolsPro);
    for (int i = 0; i < n; i++) {
        if (clubes[i].golsPro > mediaGolsPro) {
            printf("Clube: %s, Gols Pró: %d\n", clubes[i].nome, clubes[i].golsPro);
        }
    }

    printf("\nSaldo de Gols:\n");
    for (int i = 0; i < n; i++) {
        int saldoGols = clubes[i].golsPro - clubes[i].golsContra;
        printf("Clube: %s, Saldo: %d\n", clubes[i].nome, saldoGols);
    }

    int melhor = 0, pior = 0;
    for (int i = 1; i < n; i++) {
        int pontosAtual = (clubes[i].vitorias * 3) + (clubes[i].empates * 1);
        int pontosMelhor = (clubes[melhor].vitorias * 3) + (clubes[melhor].empates * 1);
        int pontosPior = (clubes[pior].vitorias * 3) + (clubes[pior].empates * 1);

        if (pontosAtual > pontosMelhor) {
            melhor = i;
        }
        if (pontosAtual < pontosPior) {
            pior = i;
        }
    }
    printf("\nMelhor Clube:\n");
    printf("Nome: %s, Pontuação: %d\n", clubes[melhor].nome, (clubes[melhor].vitorias * 3) + (clubes[melhor].empates * 1));
    printf("Pior Clube:\n");
    printf("Nome: %s, Pontuação: %d\n", clubes[pior].nome, (clubes[pior].vitorias * 3) + (clubes[pior].empates * 1));

    return 0;
}
