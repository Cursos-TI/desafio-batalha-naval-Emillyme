// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#include <stdio.h>

#define tamanho_tabuleiro 10
#define tamanho_navio 3

int main()
{
    int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro] = {0};
    int navioHorizontal[tamanho_navio] = {3, 3, 3};
    int navioVertical[tamanho_navio] = {3, 3, 3};
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int linhaHorizontal = 4, colunaHorizontal = 2;
    int linhaVertical = 1, colunaVertical = 6;

    if (colunaHorizontal + tamanho_navio <= tamanho_tabuleiro &&
        linhaVertical + tamanho_navio <= tamanho_tabuleiro) {
        
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }

        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        }

        printf("   ");
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            printf("%c ", linha[j]);
        }
        printf("\n");

        for (int i = 0; i < tamanho_tabuleiro; i++) {
            printf("%2d ", i + 1);
            for (int j = 0; j < tamanho_tabuleiro; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("o navio passou do tabuleiro.\n");
    }

    return 0;
}


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

