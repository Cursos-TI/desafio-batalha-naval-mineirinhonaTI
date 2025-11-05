#include <stdio.h>

int main()
{
    // Declaração do tabuleiro 10x10
    int tabuleiro[10][10];
    int i, j;
    // Identação do programa com no mínimo um "0" separando os navios
    // Inicializa o tabuleiro com 0 (representa água)
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // --------------------------------------------------
    // POSICIONAMENTO DOS 4 NAVIOS (tamanho 3, valor 3)
    // --------------------------------------------------

    // NAVIO HORIZONTAL (linha 4, colunas 5 a 7)
    int linha_h = 4;
    int coluna_h = 5;
    for (i = 0; i < 3; i++)
    {
        if (coluna_h + i < 10 && tabuleiro[linha_h][coluna_h + i] == 0)
        {
            tabuleiro[linha_h][coluna_h + i] = 3;
        }
    }

    // NAVIO VERTICAL (coluna 6, linhas 6 a 8)
    int linha_v = 6;
    int coluna_v = 6;
    for (i = 0; i < 3; i++)
    {
        if (linha_v + i < 10 && tabuleiro[linha_v + i][coluna_v] == 0)
        {
            tabuleiro[linha_v + i][coluna_v] = 3;
        }
    }

    // NAVIO DIAGONAL (Este comando serve para posicionar de cima para baixo, esquerda para direita)
    // Exemplo: (0,0), (1,1), (2,2)
    int linha_d1 = 0;
    int coluna_d1 = 0;
    for (i = 0; i < 3; i++)
    {
        if (linha_d1 + i < 10 && coluna_d1 + i < 10 &&
            tabuleiro[linha_d1 + i][coluna_d1 + i] == 0)
        {
            tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
        }
    }

    // NAVIO DIAGONAL  (Este comando serve para posicionar de cima para baixo, direita para esquerda)
    // Exemplo: (0,9), (1,8), (2,7)
    int linha_d2 = 0;
    int coluna_d2 = 9;
    for (i = 0; i < 3; i++)
    {
        if (linha_d2 + i < 10 && coluna_d2 - i >= 0 &&
            tabuleiro[linha_d2 + i][coluna_d2 - i] == 0)
        {
            tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
        }
    }

    // --------------------------------------------------
    // EXIBIÇÃO DO TABULEIRO
    // --------------------------------------------------

    // Cabeçalho das colunas (letras A até J)
    printf("     ");
    for (j = 0; j < 10; j++)
    {
        printf(" %c ", 'A' + j);
    }
    printf("\n");
    printf("    -----------------------------------------\n");

    // Linhas numeradas e tabuleiro completo
    for (i = 0; i < 10; i++)
    {
        printf("%2d | ", i + 1);
        for (j = 0; j < 10; j++)
        {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}