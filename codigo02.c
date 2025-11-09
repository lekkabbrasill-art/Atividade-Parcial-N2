#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* criaVetor(int n) {
    int *vetor = (int*) malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return vetor;
}
void imprimeVetor(int *vetor, int n) {
    int i;
    printf("\nElementos do vetor:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void liberaVetor(int *vetor) {
    free(vetor);
    printf("\nMemória liberada com sucesso!\n");
}

int main() {
    setlocale(LC_ALL, "");

    int n, i;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Valor inválido para o tamanho do vetor.\n");
        return 1;
    }

    vetor = criaVetor(n);

    for (i = 0; i < n; i++) {
        printf("Digite o valor para a posição %d: ", i);
        while (scanf("%d", &vetor[i]) != 1) {
            printf("Entrada inválida. Digite um número para a posição %d: ", i);
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }

    imprimeVetor(vetor, n);
    liberaVetor(vetor);

    return 0;
}