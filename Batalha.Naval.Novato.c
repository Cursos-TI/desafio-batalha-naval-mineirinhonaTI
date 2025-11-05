#include <stdio.h>

int main() {
    // Esta é a declaração da matriz que representa o tabuleiro 10x10
    int tabuleiro[10][10];
    int i, j; // variáveis para os loops, poderiam ser usadas as varíaveis y, x

    // Inicializa o tabuleiro com 0 (representa água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Este comando posiciona o navio na horizontal (tamanho 3)
    // Linha 4 (índice 4 → quinta linha)
    // Coluna 2 (índice 2 → terceira coluna, ou seja, coluna "C")
    int linha_h = 4;
    int coluna_h = 2;
    for (i = 0; i < 3; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    // Este comando posiciona o navio na vertical (tamanho 3)
    // Linha 1 (segunda linha)
    // Coluna 6 (sétima coluna → "G")
    int linha_v = 1;
    int coluna_v = 6;
    for (i = 0; i < 3; i++) {
        tabuleiro[linha_v + i][coluna_v] = 3;
    }

    // Este printf exibe o cabeçalho das colunas (letras A até J)
    printf("     ");
    for (j = 0; j < 10; j++) {
        printf(" %c ", 'A' + j); // imprime letras de A até J
    }
    printf("\n");

    printf("    -----------------------------------------\n");

    //  Este comando exibe o tabuleiro completo com as linhas numeradas de 1 a 10
    for (i = 0; i < 10; i++) {
        printf("%2d | ", i + 1); // imprime o número da linha (1–10)
        for (j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]); // imprime o conteúdo da célula (0 = água, 3 = navio)
        }
        printf("\n");
    }

    return 0; // fim do programa
}
