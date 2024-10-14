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
    char palavraCerta[5][20] = {"arroz", "corinthians", "uberaba", "tempo", "jogo"};
    char letrasDigitadas[tam];
    char palavraPreenchendo[20];
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
    int totalLetrasDigitadas;

    strcpy(palavra, "");
    pergunta = 's';
    acertouPalavra = jogo = errado = nenhumaLetra = totalLetrasDigitadas = 0;

    srand(time(NULL));
    i = rand() % 5; // Escolhe uma palavra eleatória que está no vetor
    tamanhoPalavra = strlen(palavraCerta[i]);

    for (k = 0; k < tamanhoPalavra; k++)
    {
        palavraPreenchendo[k] = '_';
    }
    palavraPreenchendo[tamanhoPalavra] = '\0'; // Adiciona o terminador de string

    for (k = 0; k < tam; k++)
    {
        letrasDigitadas[k] = '\0';
    }

    while (pergunta == 's')
    {

        if (errado == 0)
        {
            printf(" ____\n");
            printf("|    |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n\n");
        }
        else if (errado == 1)
        {
            printf(" ____\n");
            printf("|    |\n");
            printf("|    O\n");
            printf("|\n");
            printf("|\n");
            printf("|\n\n");
        }
        else if (errado == 2)
        {
            printf(" ____\n");
            printf("|    |\n");
            printf("|    O\n");
            printf("|    |\n");
            printf("|\n");
            printf("|\n\n");
        }
        else if (errado == 3)
        {
            printf(" ____\n");
            printf("|    |\n");
            printf("|    O\n");
            printf("|   /|\n");
            printf("|\n");
            printf("|\n\n");
        }
        else if (errado == 4)
        {
            printf(" ____\n");
            printf("|    |\n");
            printf("|    O\n");
            printf("|   /|\\ \n");
            printf("|\n");
            printf("|\n\n");
        }
        else if (errado == 5)
        {
            printf(" ____\n");
            printf("|    |\n");
            printf("|    O\n");
            printf("|   /|\\ \n");
            printf("|   /\n");
            printf("|\n\n");
        }
        if (errado == 6)
        {
            printf(" ____\n");
            printf("|    |\n");
            printf("|    O\n");
            printf("|   /|\\ \n");
            printf("|   / \\\n");
            printf("|\n\n");
        }
        if (errado < 6)
        {
            printf("Digite uma letra ou a palavra correta: ");
            fflush(stdin);
            scanf("%s", palavra);
        }
        system("cls");
        acertouLetra = 0;
        tamanhoDigitado = strlen(palavra);

        // Se o jogador digitar uma única letra
        if (tamanhoDigitado == 1)
        {
            letrasDigitadas[totalLetrasDigitadas] = palavra[0];
            totalLetrasDigitadas++;

            // Verifica se a letra está correta
            for (int j = 0; j < tamanhoPalavra; j++)
            {
                if (palavra[0] == palavraCerta[i][j])
                {
                    palavraPreenchendo[j] = palavra[0]; // Substitui o _ pela letra correta
                    acertouLetra = 1;
                }
            }

            if (acertouLetra)
            {
                printf("Essa letra estah certa!\n");
            }
            else
            {
                printf("Voce errou a Letra!\n");
                errado++;
            }
        }

        // Se o jogador digitar a palavra completa
        if (strcmp(palavra, palavraCerta[i]) == 0)
        {
            printf("Voce acertou a palavra!\n");
            acertouPalavra = 1;
            jogo = 1;
            strcpy(palavraPreenchendo, palavraCerta[i]); // Preenche toda a palavra
            printf("\nPressione qualquer tecla para continuar. . .");
            getch();
            system("cls");
        }
        else if (tamanhoDigitado > 1 && strcmp(palavra, palavraCerta[i]) != 0)
        {
            printf("Voce errou a palavra!\n");
            errado++;
            printf("%d/6 ERROS\n", errado);
        }

        // Exibe a palavra preenchendo as letras corretas
        printf("\nPalavra: %s\n", palavraPreenchendo);

        // Exibe as letras digitadas até o momento
        printf("\n\nLetras digitadas: ");
        for (int j = 0; j < totalLetrasDigitadas; j++)
        {
            int repetido = 0;
            for (k = 0; k < j; k++)
            {
                if (letrasDigitadas[j] == letrasDigitadas[k])
                {
                    repetido = 1;
                }
            }
            if (repetido == 0 && letrasDigitadas[j] != '\0')
            {
                printf("%c ", letrasDigitadas[j]);
            }
        }
        printf("\n\n");

        // Verifica se o jogador errou a letra/palavra 6 vezes
        if (errado == 6)
        {
            printf(" ____\n");
            printf("|    |\n");
            printf("|    O\n");
            printf("|   /|\\ \n");
            printf("|   / \\\n");
            printf("|\n\n");

            printf("\n\nVoce perdeu!\n\n");
            acertouPalavra = 1;
        }

        // Verifica se o jogador acertou a palavra e quer continuar
        if (acertouPalavra == 1)
        {
            printf("Deseja jogar novamente ?");
            printf("\n<< sim (s) >>\n");
            printf("<< nao (n) >>\n\n");
            fflush(stdin);
            scanf("%c", &pergunta);
            while (pergunta != 's' && pergunta != 'n')
            {
                printf("Digite uma resposta valida: ");
                fflush(stdin);
                scanf("%c", &pergunta);
            }
            if (pergunta == 's')
            {
                printf("\nPressione qualquer tecla para continuar. . .");
                getch();
                system("cls");
            }
            // Reinicializa as variáveis para serem usadas novamente
            strcpy(palavra, "");
            acertouPalavra = jogo = errado = nenhumaLetra = totalLetrasDigitadas = 0;

            srand(time(NULL));
            i = rand() % 5;
            tamanhoPalavra = strlen(palavraCerta[i]);

            for (k = 0; k < tamanhoPalavra; k++)
            {
                palavraPreenchendo[k] = '_';
            }
            palavraPreenchendo[tamanhoPalavra] = '\0';

            for (k = 0; k < tam; k++)
            {
                letrasDigitadas[k] = '\0';
            }
        }
    }

    return 0;
}