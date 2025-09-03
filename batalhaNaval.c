// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
// Sugestão: Expanda o tabuleiro para uma matriz 10x10.
// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

// #include <stdio.h>

// #define tamanho_tabuleiro 10
// #define tamanho_navio 3

// int main()
// {
//     int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro] = {0};
//     int navio[tamanho_navio] = {3, 3, 3};
//     char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

//     int linhaHorizontal = 6, colunaHorizontal = 2;
//     int linhaVertical = 1, colunaVertical = 8;
//     int linhaDiagonal1 = 2, colunaDiagonal1 = 3;
//     int linhaDiagonal2 = 5, colunaDiagonal2 = 9;

//     if (colunaHorizontal + tamanho_navio <= tamanho_tabuleiro) {
//         for (int i = 0; i < tamanho_navio; i++) {
//             tabuleiro[linhaHorizontal][colunaHorizontal + i] = navio[i];
//         }
//     }

//     if (linhaVertical + tamanho_navio <= tamanho_tabuleiro) {
//         for (int i = 0; i < tamanho_navio; i++) {
//             tabuleiro[linhaVertical + i][colunaVertical] = navio[i];
//         }
//     }

//     // Navios diagonais
//     if (linhaDiagonal1 + tamanho_navio <= tamanho_tabuleiro &&
//         colunaDiagonal1 + tamanho_navio <= tamanho_tabuleiro) {
//         for (int i = 0; i < tamanho_navio; i++) {
//             tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = navio[i];
//         }
//     }

//     if (linhaDiagonal2 + tamanho_navio <= tamanho_tabuleiro &&
//         colunaDiagonal2 - (tamanho_navio - 1) >= 0) {
//         for (int i = 0; i < tamanho_navio; i++) {
//             tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = navio[i];
//         }
//     }

//     printf("   ");
//     for (int j = 0; j < tamanho_tabuleiro; j++) {
//         printf("%c ", linha[j]);
//     }
//     printf("\n");

//     for (int i = 0; i < tamanho_tabuleiro; i++) {
//         printf("%2d ", i + 1);
//         for (int j = 0; j < tamanho_tabuleiro; j++) {
//             printf("%d ", tabuleiro[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

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

#include <stdio.h>
#include <stdlib.h>

#define tam 10 // tabuleiro 10x10
#define nav 3  // tamanho navio
#define mask 5 // tamanho da habilidade
#define hit 5  // efeito do hit

void faz_cone(int m[mask][mask])
{
    int meio = mask / 2;
    for (int linha = 0; linha < mask; linha++)
    {
        for (int coluna = 0; coluna < mask; coluna++)
        {
            if (abs(coluna - meio) <= linha)
            {
                m[linha][coluna] = 1;
            }
            else
            {
                m[linha][coluna] = 0;
            }
        }
    }
}

void faz_cruz(int m[mask][mask])
{
    int meio = mask / 2;
    for (int linha = 0; linha < mask; linha++)
    {
        for (int coluna = 0; coluna < mask; coluna++)
        {
            if (linha == meio || coluna == meio)
            {
                m[linha][coluna] = 1;
            }
            else
            {
                m[linha][coluna] = 0;
            }
        }
    }
}

void faz_losango(int m[mask][mask])
{
    int meio = mask / 2;
    int raio = meio;
    for (int linha = 0; linha < mask; linha++)
    {
        for (int coluna = 0; coluna < mask; coluna++)
        {
            if (abs(linha - meio) + abs(coluna - meio) <= raio)
            {
                m[linha][coluna] = 1;
            }
            else
            {
                m[linha][coluna] = 0;
            }
        }
    }
}

void poe_mascara(int efeito[tam][tam], int m[mask][mask], int linhaOrigem, int colunaOrigem)
{
    int meio = mask / 2;
    for (int linha = 0; linha < mask; linha++)
    {
        for (int coluna = 0; coluna < mask; coluna++)
        {
            if (m[linha][coluna] == 1)
            {
                int linhaTab = linhaOrigem + (linha - meio);
                int colTab = colunaOrigem + (coluna - meio);
                if (linhaTab >= 0 && linhaTab < tam && colTab >= 0 && colTab < tam)
                {
                    efeito[linhaTab][colTab] = 1;
                }
            }
        }
    }
}

void mostra(int tab[tam][tam], int efeito[tam][tam], char letras[tam])
{
    printf("   ");
    for (int coluna = 0; coluna < tam; coluna++)
    {
        printf("%c ", letras[coluna]);
    }
    printf("\n");

    for (int linha = 0; linha < tam; linha++)
    {
        printf("%2d ", linha + 1);
        for (int coluna = 0; coluna < tam; coluna++)
        {
            if (efeito[linha][coluna] == 1 && tab[linha][coluna] == 0)
            {
                printf("%d ", hit);
            }
            else
            {
                printf("%d ", tab[linha][coluna]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int tab[tam][tam] = {0};
    int efeito[tam][tam] = {0};
    char letras[tam] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    for (int i = 0; i < nav; i++)
    {
        tab[4][2 + i] = 3;
    }

    int c[mask][mask];
    int x[mask][mask];
    int l[mask][mask];
    faz_cone(c);
    faz_cruz(x);
    faz_losango(l);

    poe_mascara(efeito, c, 2, 2);
    poe_mascara(efeito, x, 6, 6);
    poe_mascara(efeito, l, 8, 3);

    mostra(tab, efeito, letras);
    return 0;
}
