#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#define tam 300

int main()
{
    char palavraCerta[5][20] = {"arroz", "corinthians", "uberaba", "minecraft", "jogo"};
    char letrasDigitadas[tam];
    char pergunta;
    int i;
    int k;
    int tamanhoPalavra;
    int tamanhoDigitado;
    char palavra[20];
    int acertouPalavra;
    int acertouLetra;
    int nenhumaLetra;
    int jogo;
    int errado;

    strcpy(palavra, "");
    pergunta = 's';
    acertouPalavra = jogo = errado = nenhumaLetra = 0;

    srand(time(NULL));
    // i = rand() % 5;
    i = 0;
    k = 0;
    tamanhoPalavra = strlen(palavraCerta[i]);

    for (k = 0; k < tam; k++)
    {
        letrasDigitadas[k] = '\0';
    }

    k = 0;

    while (pergunta == 's')
    {
        printf("digite uma letra ou a palavra correta: ");
        fflush(stdin);
        scanf("%s", palavra);
        acertouLetra = 0;
        tamanhoDigitado = strlen(palavra);
        if (tamanhoDigitado == 1)
        {
            letrasDigitadas[k] = palavra[0];
            k++;
        }

        if (strcmp(palavra, palavraCerta[i]) == 0)
        {
            printf("Voce acertou a palavra!\n");
            acertouPalavra = 1; // usar essa variável pra perguntar se deseja continuar jogando
            jogo = 1;
            printf("\nAperte qualquer tecla para continuar...");
            getch();
            system("cls");
        }
        for (int j = 0; j < tamanhoPalavra; j++)
        {
            if (palavra[0] == palavraCerta[i][j] && tamanhoDigitado == 1)
            {
                printf("Essa letra estah certa!\n");
                acertouLetra = 1;
            }
        }
        if (acertouLetra == 0 && tamanhoDigitado == 1)
        {
            printf("Voce errou a Letra!\n");
            errado++;
            printf("%d/6 ERROS\n", errado);
        }
        if (strcmp(palavra, palavraCerta[i]) != 0 && tamanhoDigitado > 1)
        {
            printf("Voce errou a palavra!\n");
            errado++;
            printf("%d/6 ERROS\n", errado);
        }
        if (acertouPalavra == 1)
        {
            printf("<< sim (s) >>\n");
            printf("<< nao (n) >>\n");
            printf("Deseja jogar novamente ?: ");
            fflush(stdin);
            scanf("%c", &pergunta);
            while (pergunta != 's' && pergunta != 'n')
            {
                printf("Digite uma resposta valida: ");
                fflush(stdin);
                scanf("%c", &pergunta);
            }
        }
    }
    printf("\n\n\nletras digitadas: ");
    for (k = 0; k < tam; k++)
    {
        printf("%c ", letrasDigitadas[k]);
    }
    printf("\n\n\nPROGRAMA FINALIZADO!\n\n\n");

    return 0;
}