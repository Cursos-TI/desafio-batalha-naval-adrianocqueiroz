#include <stdio.h>
#include <stdlib.h>

// Define os tamanhos dos tabuleiros para facilitar a manutenção
#define TAMANHO_NOVATO 5
#define TAMANHO_AVENTUREIRO 10
#define TAMANHO_MESTRE 5

// Protótipos das funções para cada nível e habilidade
void nivelNovato();
void nivelAventureiro();
void nivelMestre();
void exibirMatriz(int linhas, int colunas, int matriz[linhas][colunas]);
void habilidadeCone(int tamanho, int matriz[tamanho][tamanho]);
void habilidadeCruz(int tamanho, int matriz[tamanho][tamanho]);
void habilidadeOctaedro(int tamanho, int matriz[tamanho][tamanho]);


int main() {
    printf("====================================================\n");
    printf("### DESAFIO BATALHA NAVAL - MATECHECK ###\n");
    printf("====================================================\n\n");

    // Execução sequencial de cada nível do desafio
    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    return 0;
}

/**
 * @brief Nível Novato: Posiciona dois navios (vertical e horizontal) e exibe suas coordenadas.
 */
void nivelNovato() {
    printf("----------------------------------------\n");
    printf("🏅 NÍVEL NOVATO 🏅\n");
    printf("----------------------------------------\n");

    // Para o nível novato, não precisamos de uma matriz, apenas exibir as coordenadas.
    // Vamos definir as coordenadas dos navios manualmente.

    // Navio 1 (Horizontal - 3 partes)
    printf("Navio 1 (Horizontal) ocupa as coordenadas:\n");
    printf(" - (Linha: 1, Coluna: 1)\n");
    printf(" - (Linha: 1, Coluna: 2)\n");
    printf(" - (Linha: 1, Coluna: 3)\n\n");

    // Navio 2 (Vertical - 2 partes)
    printf("Navio 2 (Vertical) ocupa as coordenadas:\n");
    printf(" - (Linha: 3, Coluna: 0)\n");
    printf(" - (Linha: 4, Coluna: 0)\n\n");
}


/**
 * @brief Nível Aventureiro: Tabuleiro 10x10 com 4 navios (incluindo diagonais).
 * Exibe o tabuleiro completo: 0 para água, 3 para navio.
 */
void nivelAventureiro() {
    printf("----------------------------------------\n");
    printf("🏅 NÍVEL AVENTUREIRO 🏅\n");
    printf("----------------------------------------\n");
    printf("Tabuleiro 10x10 (0 = Agua, 3 = Navio):\n\n");

    int tabuleiro[TAMANHO_AVENTUREIRO][TAMANHO_AVENTUREIRO] = {0}; // Inicializa tudo com 0 (água)
    int i;

    // Posicionando os navios (valor 3)
    // Navio 1: Horizontal (4 partes)
    for (i = 1; i <= 4; i++) {
        tabuleiro[1][i] = 3;
    }

    // Navio 2: Vertical (3 partes)
    for (i = 5; i <= 7; i++) {
        tabuleiro[i][8] = 3;
    }

    // Navio 3: Diagonal (principal - 3 partes)
    for (i = 0; i < 3; i++) {
        tabuleiro[4 + i][3 + i] = 3;
    }

    // Navio 4: Diagonal (secundária - 3 partes)
     for (i = 0; i < 3; i++) {
        tabuleiro[7 - i][1 + i] = 3;
    }

    // Exibindo o tabuleiro completo
    exibirMatriz(TAMANHO_AVENTUREIRO, TAMANHO_AVENTUREIRO, tabuleiro);
}

/**
 * @brief Nível Mestre: Exibe matrizes 5x5 com padrões de habilidades especiais.
 * 0 para área não afetada, 1 para área afetada.
 */
void nivelMestre() {
    printf("\n----------------------------------------\n");
    printf("🏅 NÍVEL MESTRE 🏅\n");
    printf("----------------------------------------\n");
    printf("Exibindo áreas de habilidades especiais (0 = Nao afetado, 1 = Afetado):\n");

    int matrizHabilidade[TAMANHO_MESTRE][TAMANHO_MESTRE];

    // Habilidade em Cone
    printf("\nHabilidade em CONE:\n");
    habilidadeCone(TAMANHO_MESTRE, matrizHabilidade);
    exibirMatriz(3, TAMANHO_MESTRE, matrizHabilidade); // Exibe apenas 3 linhas conforme exemplo

    // Habilidade em Cruz
    printf("\nHabilidade em CRUZ:\n");
    habilidadeCruz(TAMANHO_MESTRE, matrizHabilidade);
    exibirMatriz(3, TAMANHO_MESTRE, matrizHabilidade); // Exibe apenas 3 linhas conforme exemplo

    // Habilidade em Octaedro
    printf("\nHabilidade em OCTAEDRO:\n");
    habilidadeOctaedro(TAMANHO_MESTRE, matrizHabilidade);
    exibirMatriz(3, TAMANHO_MESTRE, matrizHabilidade); // Exibe apenas 3 linhas conforme exemplo
}


// --- Funções Auxiliares ---

/**
 * @brief Função genérica para exibir qualquer matriz bidimensional de inteiros.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param matriz A matriz a ser exibida.
 */
void exibirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n"); // Nova linha ao final de cada linha da matriz
    }
}

/**
 * @brief Preenche uma matriz com o padrão de habilidade em Cone.
 */
void habilidadeCone(int tamanho, int matriz[tamanho][tamanho]) {
    // Inicializa a matriz com zeros
    for(int i=0; i<tamanho; i++) for(int j=0; j<tamanho; j++) matriz[i][j] = 0;

    // Define o padrão exato do exemplo
    matriz[0][2] = 1;
    matriz[1][1] = 1; matriz[1][2] = 1; matriz[1][3] = 1;
    matriz[2][0] = 1; matriz[2][1] = 1; matriz[2][2] = 1; matriz[2][3] = 1; matriz[2][4] = 1;
}

/**
 * @brief Preenche uma matriz com o padrão de habilidade em Cruz.
 */
void habilidadeCruz(int tamanho, int matriz[tamanho][tamanho]) {
    // Inicializa a matriz com zeros
    for(int i=0; i<tamanho; i++) for(int j=0; j<tamanho; j++) matriz[i][j] = 0;
    
    // Define o padrão exato do exemplo
    matriz[0][2] = 1;
    matriz[1][0] = 1; matriz[1][1] = 1; matriz[1][2] = 1; matriz[1][3] = 1; matriz[1][4] = 1;
    matriz[2][2] = 1;
}

/**
 * @brief Preenche uma matriz com o padrão de habilidade em Octaedro (Diamante).
 */
void habilidadeOctaedro(int tamanho, int matriz[tamanho][tamanho]) {
    // Inicializa a matriz com zeros
    for(int i=0; i<tamanho; i++) for(int j=0; j<tamanho; j++) matriz[i][j] = 0;

    // Define o padrão exato do exemplo
    matriz[0][2] = 1;
    matriz[1][1] = 1; matriz[1][2] = 1; matriz[1][3] = 1;
    matriz[2][2] = 1;
}
