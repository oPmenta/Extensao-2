#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#define tam 300

void temas(int tema);
void letras(int totalLetrasDigitadas, char letrasDigitadas[]);

void temas(int tema)
{
    if (tema == 0)
    {
        printf("TEMA: Personagem da Nintendo\n\n");
    }
    if (tema == 1)
    {
        printf("TEMA: Time Paulista de futebol\n\n");
    }
    if (tema == 2)
    {
        printf("TEMA: Cidade de Minas Gerais\n\n");
    }
    if (tema == 3)
    {
        printf("TEMA: Ave\n\n");
    }
    if (tema == 4)
    {
        printf("TEMA: Instrumento musical\n\n");
    }
    if (tema == 5)
    {
        printf("TEMA: Mamifero\n\n");
    }
    if (tema == 6)
    {
        printf("TEMA: Fruta vermelha\n\n");
    }
    if (tema == 7)
    {
        printf("TEMA: Idioma\n\n");
    }
    if (tema == 8)
    {
        printf("TEMA: Veiculo\n\n");
    }
}

void letras(int totalLetrasDigitadas, char letrasDigitadas[])
{
    // Exibe as letras digitadas até o momento
    printf("\nLetras digitadas: ");
    for (int j = 0; j < totalLetrasDigitadas; j++)
    {
        int repetido = 0;
        for (int k = 0; k < j; k++)
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
}

int main()
{
    char palavraCerta[9][20] = {"mario", "corinthians", "uberaba", "ganso", "guitarra", "baleia", "framboesa", "mandarim", "submarino"};
    char palavrasUsadas[9][20];
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
    int errado;
    int totalLetrasDigitadas;
    int tema;
    int cont;
    int completouPalavra;
    int totalPalavras;
    int jaUsada;
    int totalUsadas;

    strcpy(palavra, "");
    pergunta = 's';
    acertouPalavra = errado = totalLetrasDigitadas = tema = completouPalavra = totalUsadas = 0;
    totalPalavras = 9;

    srand(time(NULL));

    while (pergunta == 's')
    {
        printf("\t JOGO DA FORCA\n\n");
        printf(" ____\n");
        printf("|    |\n");
        printf("|    O\n");
        printf("|   /|\\ \n");
        printf("|   / \\\n");
        printf("|\n");
        printf("\n\nPressione qualquer tecla para iniciar o jogo. . .");
        getch();
        system("cls");

        // Seleciona uma palavra aleatória que ainda não foi usada
        do
        {
            i = rand() % 9;
            // Verifica se a palavra já foi usada
            jaUsada = 0;
            for (int j = 0; j < totalUsadas; j++)
            {
                if (strcmp(palavraCerta[i], palavrasUsadas[j]) == 0)
                {
                    jaUsada = 1;
                    j = totalUsadas;
                }
            }
        } while (jaUsada == 1);

        // Adiciona a palavra selecionada ao vetor de palavras usadas
        strcpy(palavrasUsadas[totalUsadas], palavraCerta[i]);
        totalUsadas++;

        // Reinicializa o vetor de palavras usadas se todas já tiverem sido usadas
        if (totalUsadas == totalPalavras)
        {
            totalUsadas = 0;
        }

        tema = i;
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
        while (acertouPalavra == 0 && errado < 6)
        {
            cont = 0;
            for (k = 0; k < tamanhoPalavra; k++)
            {
                if (palavraPreenchendo[k] != '_')
                {
                    cont++;
                }
                if (cont == tamanhoPalavra)
                {
                    acertouPalavra = 1;
                    completouPalavra = 1;
                }
            }

            // Preenche toda a palavra
            if (strcmp(palavra, palavraCerta[i]) == 0)
            {
                system("cls");
                acertouPalavra = 1;
                completouPalavra = 1;
                strcpy(palavraPreenchendo, palavraCerta[i]);
            }

            if (errado == 0)
            {
                temas(tema);

                printf(" ____\n");
                printf("|    |\n");
                printf("|\n");
                printf("|\n");
                printf("|\n");
                printf("|\n");

                // Exibe a palavra preenchendo as letras corretas
                printf("   %s\n", palavraPreenchendo);

                // Exibe as letras digitadas até o momento
                letras(totalLetrasDigitadas, letrasDigitadas);
            }
            else if (errado == 1)
            {
                temas(tema);

                printf(" ____\n");
                printf("|    |\n");
                printf("|    O\n");
                printf("|\n");
                printf("|\n");
                printf("|\n");

                // Exibe a palavra preenchendo as letras corretas
                printf("   %s\n", palavraPreenchendo);

                // Exibe as letras digitadas até o momento
                letras(totalLetrasDigitadas, letrasDigitadas);
            }
            else if (errado == 2)
            {
                temas(tema);

                printf(" ____\n");
                printf("|    |\n");
                printf("|    O\n");
                printf("|    |\n");
                printf("|\n");
                printf("|\n");

                // Exibe a palavra preenchendo as letras corretas
                printf("   %s\n", palavraPreenchendo);

                // Exibe as letras digitadas até o momento
                letras(totalLetrasDigitadas, letrasDigitadas);
            }
            else if (errado == 3)
            {
                temas(tema);

                printf(" ____\n");
                printf("|    |\n");
                printf("|    O\n");
                printf("|   /|\n");
                printf("|\n");
                printf("|\n");

                // Exibe a palavra preenchendo as letras corretas
                printf("   %s\n", palavraPreenchendo);

                // Exibe as letras digitadas até o momento
                letras(totalLetrasDigitadas, letrasDigitadas);
            }
            else if (errado == 4)
            {
                temas(tema);

                printf(" ____\n");
                printf("|    |\n");
                printf("|    O\n");
                printf("|   /|\\ \n");
                printf("|\n");
                printf("|\n");

                // Exibe a palavra preenchendo as letras corretas
                printf("   %s\n", palavraPreenchendo);

                // Exibe as letras digitadas até o momento
                letras(totalLetrasDigitadas, letrasDigitadas);
            }
            else if (errado == 5)
            {
                temas(tema);

                printf(" ____\n");
                printf("|    |\n");
                printf("|    O\n");
                printf("|   /|\\ \n");
                printf("|   /\n");
                printf("|\n");

                // Exibe a palavra preenchendo as letras corretas
                printf("   %s\n", palavraPreenchendo);

                // Exibe as letras digitadas até o momento
                letras(totalLetrasDigitadas, letrasDigitadas);
            }

            if (errado < 6 && acertouPalavra == 0)
            {
                printf("\n\nDigite uma letra ou uma palavra: ");
                fflush(stdin);
                scanf("%s", palavra);
                system("cls");
                for (int j = 0; palavra[j] != '\0'; j++)
                {
                    palavra[j] = tolower(palavra[j]);
                }
            }
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
                if (acertouLetra == 0)
                {
                    errado++;
                }
            }

            // Se o jogador digitar uma palavra errada
            if (tamanhoDigitado > 1 && strcmp(palavra, palavraCerta[i]) != 0)
            {
                errado++;
            }

            // Verifica se o jogador errou a letra/palavra 6 vezes
            if (errado == 6)
            {
                temas(tema);

                printf(" ____\n");
                printf("|    |\n");
                printf("|    O\n");
                printf("|   /|\\ \n");
                printf("|   / \\\n");
                printf("|\n");

                // Exibe a palavra preenchendo as letras corretas
                printf("   %s\n", palavraPreenchendo);

                // Exibe as letras digitadas até o momento
                letras(totalLetrasDigitadas, letrasDigitadas);

                printf("\n\nVoce perdeu!\n\n");
                printf("A palavra era: %s\n", palavraCerta[i]);
                acertouPalavra = 1;
            }
        }

        // Verifica se o jogador acertou a palavra e quer continuar
        if (completouPalavra == 1)
        {
            printf("\n\nVoce acertou a palavra!\n");
        }

        printf("\nPressione qualquer tecla para voltar ao MENU. . .");
        getch();
        system("cls");

        // Reinicializa as variáveis para serem usadas novamente
        acertouPalavra = errado = totalLetrasDigitadas = completouPalavra = 0;
    }

    return 0;
}