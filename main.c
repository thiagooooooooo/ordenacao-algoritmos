#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes;
long long movimentacoes;

/* Preenche vetor em ordem decrescente */
void preencherDecrescente(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = n - i;
    }
}

/* Bubble Sort */
void bubbleSort(int *v, int n) {
    comparacoes = 0;
    movimentacoes = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparacoes++;
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                movimentacoes++;
            }
        }
    }
}

/* Selection Sort */
void selectionSort(int *v, int n) {
    comparacoes = 0;
    movimentacoes = 0;

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
            movimentacoes++;
        }
    }
}

/* Executa e mede tempo */
void executarAlgoritmo(void (*alg)(int*, int), int tamanho, const char *nome) {
    int *vetor = (int*) malloc(tamanho * sizeof(int));
    clock_t inicio, fim;
    double tempo_ms;

    preencherDecrescente(vetor, tamanho);

    inicio = clock();
    alg(vetor, tamanho);
    fim = clock();

    tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("%-13s | %6d | %8.2f | %12lld | %14lld\n",
           nome, tamanho, tempo_ms, comparacoes, movimentacoes);

    free(vetor);
}

int main() {
    int tamanhos[] = {100, 1000, 10000};

    printf("Algoritmo     | Tamanho | Tempo(ms) | Comparacoes | Movimentacoes\n");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        executarAlgoritmo(bubbleSort, tamanhos[i], "Bubble Sort");
    }

    for (int i = 0; i < 3; i++) {
        executarAlgoritmo(selectionSort, tamanhos[i], "Selection Sort");
    }

    return 0;
}
