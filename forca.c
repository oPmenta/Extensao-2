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
    if (tema == 0 || tema == 9)
    {
        printf("TEMA: Personagem da Nintendo\n\n");
    }
    if (tema == 1 || tema == 10)
    {
        printf("TEMA: Time brasileiro de futebol\n\n");
    }
    if (tema == 2 || tema == 11)
    {
        printf("TEMA: Cidade de Minas Gerais\n\n");
    }
    if (tema == 3 || tema == 12)
    {
        printf("TEMA: Ave\n\n");
    }
    if (tema == 4 || tema == 13)
    {
        printf("TEMA: Instrumento musical\n\n");
    }
    if (tema == 5 || tema == 14)
    {
        printf("TEMA: Mamifero\n\n");
    }
    if (tema == 6 || tema == 15)
    {
        printf("TEMA: Fruta vermelha\n\n");
    }
    if (tema == 7 || tema == 16)
    {
        printf("TEMA: Idioma\n\n");
    }
    if (tema == 8 || tema == 17)
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
    char palavraCerta[18][20] = {"mario", "corinthians", "uberaba", "coruja", "guitarra", "baleia", "framboesa", "russo", "submarino", "link", "botafogo", "betim", "pinguim", "flauta", "morcego", "groselha", "hindi", "trem"};
    char palavrasUsadas[18][20];
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
    totalPalavras = 18;

    srand(time(NULL));

    while (pergunta == 's')
    {
        // reinicializa o vetor de palavras usadas se todas já tiverem sido usadas
        if (totalUsadas == totalPalavras)
        {
            totalUsadas = 0;
            printf("\t JOGO DA FORCA\n\n");
            printf("Todas as palavras ja foram utilizadas!\n\n");
            printf("Deseja continuar jogando? \n<< s >> ou << n >>: ");
            fflush(stdin);
            scanf("%c", &pergunta);
            while (pergunta != 's' && pergunta != 'n')
            {
                printf("\n\nDigite << s >> ou << n >>: ");
                fflush(stdin);
                scanf("%c", &pergunta);
            }
            if (pergunta == 's')
            {
                printf("\n\nReiniciando as palavras!");
                Sleep(500);
                printf("\n3...");
                Sleep(500);
                printf("\n2...");
                Sleep(500);
                printf("\n1...");
                Sleep(500);
                system("cls");
            }
        }
        if (pergunta == 's')
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

            // seleciona uma palavra aleatória que ainda não foi usada
            do
            {
                i = rand() % 18;
                // verifica se a palavra já foi usada
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

            // adiciona a palavra selecionada ao vetor de palavras usadas
            strcpy(palavrasUsadas[totalUsadas], palavraCerta[i]);
            totalUsadas++;

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

            printf("\n\n\n- Curiosidade\n");
            if (tema == 0)
                printf("\nMario originalmente se chamava Jumpman em seu primeiro jogo, Donkey Kong (1981). Seu nome foi mudado para Mario em homenagem a Mario Segale, o proprietario do armazem que a Nintendo alugava nos EUA. \n");
            if (tema == 1)
                printf("\nAlem de ser o melhor time do mundo, o mascote do clube, o Mosqueteiro, surgiu de uma cronica do jornal A Gazeta Esportiva apos um amistoso contra o Barracas da Argentina. O texto comparava a garra dos jogadores corintianos com Os Tres Mosqueteiros de Alexandre Dumas. \n");
            if (tema == 2)
                printf("\nO nome Uberaba vem do termo tupi Y-beraba, que significa agua clara. \n");
            if (tema == 3)
                printf("\nA ave tem a capacidade de rodar cabeca em ateh 135 graus para cada lado, mas nao eh verdade que elas conseguem dar uma volta completa com a cabeca, o que muitas pessoas acreditam.  \n");
            if (tema == 4)
                printf("\nA guitarra eh um instrumento extremamente versatil, capaz de se adaptar a diversos generos musicas, como rock, pop, jazz e musica classica. Essa capacidade de se inserir em tantos estilos musicas ajudou a populariza-la globalmente. \n");
            if (tema == 5)
                printf("\nAlgumas especies de baleias, como as baleias-jubarte, tem a capacidade de mudar de cor para se camuflar. \n");
            if (tema == 6)
                printf("\nO consumo de framboesa reduz a inflamacao no corpo e ajuda a prevenir o surgimento de alguns tipos de cancer, como colon, prostata, mama e endometrio. \n");
            if (tema == 7)
                printf("\nO russo eh uma das 4 linguas mais traduzidas do mundo. \n");
            if (tema == 8)
                printf("\nNos submarinos existem camaras especiais que atraves do ar comprimido faz com que a quantidade de agua dentro delas possa ser aumentada ou diminuida. Assim sendo, o submarino afunda ou flutua. \n");
            if (tema == 9)
                printf("\nLink apareceu em mais de 20 jogos desde sua criação e ja fez Crossovers em alguns jogos como Super Smash Bros, Tetris, Mario Kart 8 entre outros. \n");
            if (tema == 10)
                printf("\nO Botafogo detem o recorde de titulos consecutivos do Campeonato Carioca, tendo vencido o torneio por sete anos seguidos, de 1968 a 1974. \n");
            if (tema == 11)
                printf("\nA regiao onde hoje fica Betim era uma importante rota de bandeirantes que vinham de Sao Paulo a Pitangui.  \n");
            if (tema == 12)
                printf("\nEmbora sejam otimos nadadores, os pinguins, apesar de serem aves, nao podem voar. Eles vivem principalmente em regioes do hemisferio sul, como a Antartica. \n");
            if (tema == 13)
                printf("\nA flauta eh um dos instrumentos musicais mais antigos ja encontrados. Arqueologos ja encontraram flautas feitas de ossos de animais, casca de arvore e outros materiais. \n");
            if (tema == 14)
                printf("\nOs morcegos sao os unicos mamiferos que conseguem voar de verdade, ao contrario de animais como esquilos-voadores, que apenas planam. \n");
            if (tema == 15)
                printf("\nA groselha pode ser consumida fresca, mas tambem eh comumente usada para fazer geleias, compotas, sucos, xaropes e ate vinhos. \n");
            if (tema == 16)
                printf("\nO hindi eh a terceira lingua mais falada no mundo, com mais de 600 milhoes de falantes, atras apenas do ingles e do mandarim. \n");
            if (tema == 17)
                printf("\nTrens sao considerados um dos meios de transporte mais seguros do mundo. Acidentes ferroviarios sao raros em comparacao com acidentes de carro ou aviao. \n");

            printf("\nPressione qualquer tecla para voltar ao MENU. . .");
            getch();
            system("cls");
        }
        // Reinicializa as variáveis para serem usadas novamente
        acertouPalavra = errado = totalLetrasDigitadas = completouPalavra = 0;
    }

    return 0;
}