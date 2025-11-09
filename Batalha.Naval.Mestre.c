#include <stdio.h>
novo commit
#define LINHA 10
#define COLUNA 10

int main()
{
    int tabuleiro[LINHA][COLUNA];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // -----------------------------
    // POSICIONAMENTO DOS NAVIOS
    // -----------------------------
//Navios horizontais, verticais e diagonais  identificados pelo nr 3 e não se sobrepõe "há espaço entre eles"
    // Navio horizontal
    int linha_h = 4, coluna_h = 5;
    for (i = 0; i < 3; i++)
    {
        if (coluna_h + i < COLUNA)
            tabuleiro[linha_h][coluna_h + i] = 3;
    }

    // Navio vertical
    int linha_v = 6, coluna_v = 6;
    for (i = 0; i < 3; i++)
    {
        if (linha_v + i < LINHA)
            tabuleiro[linha_v + i][coluna_v] = 3;
    }

    // Navio diagonal de cima para baixo, da esquerda para a direita
    int linha_d1 = 0, coluna_d1 = 0;
    for (i = 0; i < 3; i++)
    {
        if (linha_d1 + i < LINHA && coluna_d1 + i < COLUNA)
            tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
    }

    // Navio diagonal de cima para baixo, da direita para a esquerda
    int linha_d2 = 0, coluna_d2 = 9;
    for (i = 0; i < 3; i++)
    {
        if (linha_d2 + i < LINHA && coluna_d2 - i >= 0)
            tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
    }

    // -----------------------------
    // MATRIZES DE HABILIDADES 5x5
    // -----------------------------

    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}};

    // -----------------------------
    // PONTOS DE ORIGEM NO TABULEIRO
    // -----------------------------
    int linha_cone = 1, col_cone = 2;
    int linha_cruz = 5, col_cruz = 5;
    int linha_octa = 8, col_octa = 7;

    // -----------------------------
    // SOBREPOSIÇÃO DAS HABILIDADES
    // -----------------------------

    // Cone
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int lin = linha_cone + (i - 2); // deslocamento vertical
            int col = col_cone + (j - 2);   // deslocamento horizontal
            if (lin >= 0 && lin < LINHA && col >= 0 && col < COLUNA && cone[i][j] == 1)
            {
                tabuleiro[lin][col] = 5;
            }
        }
    }

    // Cruz
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int lin = linha_cruz + (i - 2);
            int col = col_cruz + (j - 2);
            if (lin >= 0 && lin < LINHA && col >= 0 && col < COLUNA && cruz[i][j] == 1)
            {
                tabuleiro[lin][col] = 5;
            }
        }
    }

    // Octaedro
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int lin = linha_octa + (i - 2);
            int col = col_octa + (j - 2);
            if (lin >= 0 && lin < LINHA && col >= 0 && col < COLUNA && octaedro[i][j] == 1)
            {
                tabuleiro[lin][col] = 5;
            }
        }
    }

    // -----------------------------
    // EXIBIÇÃO DO TABULEIRO
    // -----------------------------
    printf("     ");
    for (j = 0; j < COLUNA; j++)
    {
        printf(" %c ", 'A' + j);
    }
    printf("\n    -----------------------------------------\n");

    for (i = 0; i < LINHA; i++)
    {
        printf("%2d | ", i + 1);
        for (j = 0; j < COLUNA; j++)
        {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
