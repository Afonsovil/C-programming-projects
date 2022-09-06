#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

void Imprimir_Tabuleiro(int linha, int coluna);
void Inicializa_Tabuleiro(int linha, int coluna);
void Colocar_pecas(int linha, int coluna);
void Colocar_individual(char barco[3][3], int linha, int coluna);
int Avaliar_posicionamento(int peca, int tipo, int linha, int coluna);
void Posicionamento_1(int linha, int coluna, int posicionamento, int num_pecas);
int Verifica_afundancos(int linha, int coluna);
void modo_d1(int linha, int coluna);
void modo_d2(int linha, int coluna);
void modo_d3(int linha, int coluna);
void Coloca_X(int linha, int coluna);
int Verifica_afundancos_mini(int linha, int coluna);
void Check_other_boats(int line, int collumn);

char **tabuleiro = NULL;    //tabuleiro do jogo
int pecas[8];                   //Vector com a quantidade de peças de cada tipo

//Especificação das peças(navios) de jogo
//Barco do tipo 1 e as suas variantes
char barco1_1[3][3] = {
                        {'1', '0', '0'},
                        {'0', '0', '0'},
                        {'0', '0', '0'}
                    }; 

char barco1_2[3][3] = {
                        {'0', '1', '0'},
                        {'0', '0', '0'},
                        {'0', '0', '0'}
                    };

char barco1_3[3][3] = {
                        {'0', '0', '1'},
                        {'0', '0', '0'},
                        {'0', '0', '0'}
                    };

char barco1_4[3][3] = {
                        {'0', '0', '0'},
                        {'1', '0', '0'},
                        {'0', '0', '0'}
                    };

char barco1_5[3][3] = {
                        {'0', '0', '0'},
                        {'0', '1', '0'},
                        {'0', '0', '0'}
                    };

char barco1_6[3][3] = {
                        {'0', '0', '0'},
                        {'0', '0', '1'},
                        {'0', '0', '0'}
                    };

char barco1_7[3][3] = {
                        {'0', '0', '0'},
                        {'0', '0', '0'},
                        {'1', '0', '0'}
                    };

char barco1_8[3][3] = {
                        {'0', '0', '0'},
                        {'0', '0', '0'},
                        {'0', '1', '0'}
                    };

char barco1_9[3][3] = {
                        {'0', '0', '0'},
                        {'0', '0', '0'},
                        {'0', '0', '1'}
                    };

//Barco do tipo 2 e as suas variantes
char barco2_1[3][3] = {
                        {'2', '2', '0'},
                        {'0', '0', '0'},
                        {'0', '0', '0'}
                    };

char barco2_2[3][3] = {
                        {'0', '2', '2'},
                        {'0', '0', '0'},
                        {'0', '0', '0'}
                    };

char barco2_3[3][3] = {
                        {'0', '0', '0'},
                        {'2', '2', '0'},
                        {'0', '0', '0'}
                    };

char barco2_4[3][3] = {
                        {'0', '0', '0'},
                        {'0', '2', '2'},
                        {'0', '0', '0'}
                    };

char barco2_5[3][3] = {
                        {'0', '0', '0'},
                        {'0', '0', '0'},
                        {'2', '2', '0'}
                    };

char barco2_6[3][3] = {
                        {'0', '0', '0'},
                        {'0', '0', '0'},
                        {'0', '2', '2'}
                    };

char barco2_7[3][3] = {
                        {'2', '0', '0'},
                        {'2', '0', '0'},
                        {'0', '0', '0'}
                    };

char barco2_8[3][3] = {
                        {'0', '0', '0'},
                        {'2', '0', '0'},
                        {'2', '0', '0'}
                    };

char barco2_9[3][3] = {
                        {'0', '2', '0'},
                        {'0', '2', '0'},
                        {'0', '0', '0'}
                    };

char barco2_10[3][3] = {
                        {'0', '0', '0'},
                        {'0', '2', '0'},
                        {'0', '2', '0'}
                    };

char barco2_11[3][3] = {
                        {'0', '0', '2'},
                        {'0', '0', '2'},
                        {'0', '0', '0'}
                    };

char barco2_12[3][3] = {
                        {'0', '0', '0'},
                        {'0', '0', '2'},
                        {'0', '0', '2'}
                    };

//Barco do tipo 3 e as suas variantes
char barco3_1[3][3] = {
                        {'3', '3', '3'},
                        {'0', '0', '0'},
                        {'0', '0', '0'}
                    };

char barco3_2[3][3] = {
                        {'0', '0', '0'},
                        {'3', '3', '3'},
                        {'0', '0', '0'}
                    };

char barco3_3[3][3] = {
                        {'0', '0', '0'},
                        {'0', '0', '0'},
                        {'3', '3', '3'}
                    };

char barco3_4[3][3] = {
                        {'3', '0', '0'},
                        {'3', '0', '0'},
                        {'3', '0', '0'}
                    };

char barco3_5[3][3] = {
                        {'0', '3', '0'},
                        {'0', '3', '0'},
                        {'0', '3', '0'}
                    };
            
char barco3_6[3][3] = {
                        {'0', '0', '3'},
                        {'0', '0', '3'},
                        {'0', '0', '3'}
                    };

//Barco do tipo 4 e as suas variantes
char barco4_1[3][3] = {
                        {'4', '4', '0'},
                        {'4', '4', '0'},
                        {'0', '0', '0'}
                    };

char barco4_2[3][3] = {
                        {'0', '4', '4'},
                        {'0', '4', '4'},
                        {'0', '0', '0'}
                    };

char barco4_3[3][3] = {
                        {'0', '0', '0'},
                        {'4', '4', '0'},
                        {'4', '4', '0'}
                    };

char barco4_4[3][3] = {
                        {'0', '0', '0'},
                        {'0', '4', '4'},
                        {'0', '4', '4'}
                    };

//Barco do tipo 5 e as suas variantes
char barco5_1[3][3] = {
                        {'5', '5', '5'},
                        {'0', '5', '0'},
                        {'0', '5', '0'},
                    };

char barco5_2[3][3] = {
                        {'5', '0', '0'},
                        {'5', '5', '5'},
                        {'5', '0', '0'},
                    };

char barco5_3[3][3] = {
                        {'0', '5', '0'},
                        {'0', '5', '0'},
                        {'5', '5', '5'},
                    };

char barco5_4[3][3] = {
                        {'0', '0', '5'},
                        {'5', '5', '5'},
                        {'0', '0', '5'},
                    };

//Barco do tipo 6 e as suas variantes
char barco6_1[3][3] = {
                        {'0', '6', '0'},
                        {'6', '0', '6'},
                        {'6', '6', '6'}
                    };

char barco6_2[3][3] = {
                        {'0', '6', '6'},
                        {'6', '0', '6'},
                        {'0', '6', '6'}
                    };

char barco6_3[3][3] = {
                        {'6', '6', '6'},
                        {'6', '0', '6'},
                        {'0', '6', '0'}
                    };

char barco6_4[3][3] = {
                        {'6', '6', '0'},
                        {'6', '0', '6'},
                        {'6', '6', '0'}
                    };
                    
//Barco do tipo 7 e as suas variantes
char barco7_1[3][3] = {
                        {'7', '0', '7'},
                        {'7', '7', '7'},
                        {'7', '0', '7'}
                    };

char barco7_2[3][3] = {
                        {'7', '7', '7'},
                        {'0', '7', '0'},
                        {'7', '7', '7'}
                    };

//Barco do tipo 8
char barco8[3][3] = {
                        {'8', '8', '8'},
                        {'8', '0', '8'},
                        {'8', '8', '8'}
                    };
                    

int main(int argc, char *argv[])
{
    int option;
    int linha = 9, coluna = 9;  //valores pré definidos para as dimensões do tabuleiro
    int modo = 0;               //'''''''''''''''''''''''''' o modo de jogo
    int posicionamento = 0;     //'''''''''''''''''''''''''' o posicionamento das peças
    int disparo = 1;            //'''''''''''''''''''''''''' o modo de disparo
    int i, j, num_pecas = 0;

    while((option = getopt(argc, argv, "ht:j:p:1:2:3:4:5:6:7:8:")) != -1)
    {
        switch(option)
        {
            case 'h':
                        printf("Menu de ajuda\n");
                        printf("Arguments:\n");
                        printf("  -h\t\tMenu de ajuda com indicações do funcionamento do programa\n");
                        printf("  -t\t\tArgumento após o qual deve ser inserido o número de linhas e de colunas, da forma: (linhaxcoluna)\n");
                        printf("  -j\t\tArgumento utilizado para se inserir o modo de jogo(0 a 2)\n");
                        printf("  -p\t\tArgumento utilizado para inserir o modo de posicionamento das peças pelo computador(1 a 2)\n");
                        printf("  -d\t\tArgumento utilizado para inserir o modo de disparo utilizado pelo computador(1 a 3)\n");
                        printf("  -1\t\tArguemnto utilizado para inserir o número de peças do tipo 1(Minímo 1)\n");
                        printf("  -2\t\tArguemnto utilizado para inserir o número de peças do tipo 1\n");
                        printf("  -3\t\tArguemnto utilizado para inserir o número de peças do tipo 1\n");
                        printf("  -4\t\tArguemnto utilizado para inserir o número de peças do tipo 1\n");
                        printf("  -5\t\tArguemnto utilizado para inserir o número de peças do tipo 1\n");
                        printf("  -6\t\tArguemnto utilizado para inserir o número de peças do tipo 1\n");
                        printf("  -7\t\tArguemnto utilizado para inserir o número de peças do tipo 1\n");
                        printf("  -8\t\tArguemnto utilizado para inserir o número de peças do tipo 1\n");
                        
                        break;

            case 't':
                        if((sscanf(optarg, "%dx%d", &linha, &coluna) != -1))
                        {
                            printf("O número de linhas e de colunas foi lido\n");
                        }

                        if((linha % 3 != 0) || (coluna % 3 != 0))
                        {
                            printf("O número de linhas e de colunas têm de ser múltiplo de 3!\n");
                            printf("Corra o programa outra vez de forma certa!\n");
                            return -1;
                        }

                        if((linha < 9) || (coluna < 9))
                        {
                            printf("Erro!!!!\n");
                            printf("O número minímo de linhas e de colunas é 9!\n");
                            printf("Corra o programa outra vez de forma certa!\n");
                            return -1;    
                        }

                        if((linha > 15) || (coluna > 24))
                        {
                            printf("Erro!!!!\n");
                            printf("O número máximo de linhas é 15 e o número máximo de colunas é 24!\n");
                            printf("Corra o programa outra vez de forma certa!\n");
                            return -1;
                        }
                        break;

            case 'j':
                        sscanf(optarg, "%d", &modo);
                        if((modo < 0) || (modo > 2))
                        {
                            printf("Modo de jogo inválido!\n");
                            printf("Corra o programa novamente com argumento -h para saber como deve invocar o programa\n");
                            return -1;
                        }

                        break;

            case 'p':
                        sscanf(optarg, "%d", &posicionamento);
                        if((posicionamento != 1) || (posicionamento != 2))
                        {
                            printf("Modo de posicionamento inválido!\n");
                            printf("Corra o programa novamente com argumento -h para saber como deve invocar o programa\n");
                            return -1;                        
                        }

                        break;

            case 'd':
                        sscanf(optarg, "%d", &disparo);
                        if((disparo < 1) || (disparo > 3))
                        {
                            printf("Modo de disparo inválido!\n");
                            printf("Corra o programa novamente com argumento -h para saber como deve invocar o programa\n");
                            return -1;                        
                        }

                        break;

            case '1':
                        sscanf(optarg, "%d", &pecas[0]);
                        if(pecas[0] < 1)
                        {
                            printf("Número de peças do tipo 1 inválido!\n");
                            printf("Corra o programa novamente com argumento -h para saber como deve invocar o programa\n");
                            return -1;                        
                        }
                        break;

            case '2':  
                        sscanf(optarg, "%d", &pecas[1]);
                        break;

            case '3':
                        sscanf(optarg, "%d", &pecas[2]);
                        break;

            case '4':
                        sscanf(optarg, "%d", &pecas[3]);
                        break;

            case '5':
                        sscanf(optarg, "%d", &pecas[4]);
                        break;

            case '6':
                        sscanf(optarg, "%d", &pecas[5]);
                        break;

            case '7':
                        sscanf(optarg, "%d", &pecas[6]);
                        break;

            case '8':
                        sscanf(optarg, "%d", &pecas[7]);
                        break;
        }

    }

    //restrição 2
    for(i=0; i<9; i++)
    {
        num_pecas += pecas[i];
    }
    
    //se o número de peças for maior ao número de peças que cabem no tabuleiro
    if(num_pecas > (linha*coluna)/9)
    {
        printf("Número de peças maior ao número de peças permitido no tabuleiro!\n");
        exit(0);
    }

    tabuleiro = (char **) malloc((linha+2) * sizeof(char *));   //alocação das linhas do tabuleiro
    if(tabuleiro == NULL)
    {
        printf("Não foi possível alocar as linhas do tabuleiro de jogo\n");
        exit(EXIT_FAILURE);
    }

    //Inicialização das linhas
    for(i=0; i < (linha+2); i++)
    {
        tabuleiro[i] = NULL;
    }

    //Alocação das colunas do tabuleiro
    for(i=0; i < coluna+2; i++)
    {
        tabuleiro[i] = (char *) malloc((coluna+2) * sizeof(char));
        if(tabuleiro[i] == NULL)
        {
            printf("Não foi possível alocar as colunas da linha %d do tabuleiro de jogo\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    //Inicialização do Tabuleiro
    Inicializa_Tabuleiro(linha+2, coluna+2);

    //Imprimir Tabuleiro vazio
    Imprimir_Tabuleiro(linha+2, coluna+2);

    printf("\n\n");

    //teste para ver se consigo imprimir o vector de peças
    for(i=0; i<8; i++)
    {
        printf("Peça %d = %d\n", i+1, pecas[i]);
    }

    /*
    int j;  // teste para saber se o tabuleiro está a ser bem inicializado
    for(i=0; i<linha+2; i++)
    {
        for(j=0; j<coluna+2; j++)
        {
            printf("%c", tabuleiro[i][j]);
        }
        printf("\n");
    }
    */  
    
    /*
    //Colocar peça no tabuleiro
    Colocar_individual(barco8, 4, 4);

    //Imprimir Tabuleiro com a peça
    Imprimir_Tabuleiro(linha+2, coluna+2);
    */

    /*
    switch(modo)
    {
        case 0:
                //Modo de jogo 0
                Posicionamento_1(linha+2, coluna+2, posicionamento);
                //Imprimir Tabuleiro com as peças
                Imprimir_Tabuleiro(linha+2, coluna+2);
                break;

        case 1:
                //Modo de jogo 0
                
                break;

        case 2:
                //Modo de jogo 0
                
                break;
    }

    */
    
    Posicionamento_1(linha+2, coluna+2, 0, num_pecas);
    //Imprimir Tabuleiro com a peça
    Imprimir_Tabuleiro(linha+2, coluna+2);

    modo_d3(linha+2, coluna+2);

    return 0;
}

/*
 * Function name: Imprimir_Tabuleiro()
 *
 * Argumentos: 
 *              tabuleiro (char **) - tabuleiro com a informação das peças
 *              linha (int) - número de linhas
 *              coluna (int) - númrero de colunas
 *
 * Returned:
 *          Nenhum valor é retornado              
 *
 * Description:
 *          A função recebe o tabuleiro e impreme-o, com exceção das linhas e colunas com o caracter 'x'(zona inválida do tabuleiro)
 *          A função imprime o número da linha por ordem decrescente, bem como a letra da coluna por ordem crescente          
 *          Se a função imprimir o caracter '0', significa que nesse local não existe nenhum barco(água), 
 *          se imprimir um número de 1 a 9 quer dizer que nesse local há um barco ou parte dele
 *
 *****************************************************************************************************
*/

void Imprimir_Tabuleiro(int linha, int coluna)
{
    int i, j;
    int aux_linha = linha - 1;

    for(i=1; i < linha-1; i++)
    {
        if(aux_linha > 10)
            printf(" %d", aux_linha-1);
        else
            printf("  %d", aux_linha-1);
        
        for(j=1; j < coluna-1; j++)
        {
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
        aux_linha--;
    }

    printf("    ");
    for(j=1; j < coluna-1; j++)
    {
        printf("%c ", 'A'+j-1);
    }
    printf("\n");

    return ;
}

/************************************************************
 * Function name: Inicializa_Tabuleiro() 
 *
 *Argumentos:
 *              tabuleiro (char ***) - Tabuleiro de jogo       
 *              linha (int) - número de linhas do tabuleiro
 *              coluna (int) - número de colunas do tabuleiro
 *
 *Return:
 *          Nothing is returned
 *
 *Description:
 *              A 1ª linha e última do tabuleiro, bem como a 1ª e última coluna, devem ser inicializadas
 *              com o caracter 'k', estas linhas e colunas apenas servem para facilitar as comparações utilizadas
 *              a seguir
 *
 ****************************************************************
*/

void Inicializa_Tabuleiro(int linha, int coluna)
{
    int i, j;

    for(i=0; i < linha; i++)
    {
        for(j=0; j < coluna; j++)
        {
            if((i == 0) || (i == linha-1) || (j == 0) || (j == coluna-1))
                tabuleiro[i][j] = 'k';
            else
                tabuleiro[i][j] = '0';
        }
    }
    printf("A incialização do tabuleiro foi efectuada com sucesso!!!\n");

    return ;
}

/************************************************************
 * Function name: Colocar_individual() 
 *
 * Argumentos:
 *              barco (char **) - Tipo de barco a posicionar       
 *              linha (int) e coluna (int) - Local de posicionamento no tabuleiro 
 *
 * Return:
 *          Nothing is returned
 *
 * Description:
 *              A peça enviada para a função(matriz 3x3), é copiada para o tabuleiro
 *
 ****************************************************************
*/
void Colocar_individual(char barco[3][3], int linha, int coluna)
{
    int i, j;

    for(i=0; i < 3; i++)
    {
        for(j=0; j<3; j++)
        {
            tabuleiro[linha+i][coluna+j] = barco[i][j];
        }
    }
    return ;
}

/************************************************************
 * Function name: Avaliar_posicionamento() 
 *
 * Argumentos:
 *              peça (int) - Tipo de barco a posicionar       
 *              tipo (int) - Forma de colocar a peça
 *              linha (int) e coluna (int) - Local de posicionamento no tabuleiro 
 *
 * Return:
 *          Inteiro
 *
 * Description:
 *              A peça enviada para a função e é verificada se a mesma pode ser posicionada.
 *               Se sim, return 1, senão return 0
 *
 ****************************************************************
*/
int Avaliar_posicionamento(int peca, int tipo, int linha, int coluna)
{
    int i;

    //printf("fsbsbgnhfmhfm\n");

    switch(peca)
    {
        case 1:
                switch(tipo)
                {
                    case 1:
                            if(linha == 1)
                                return 1;

                            //percorrer a linha 
                            for(i=0; i<3; i++)
                            {
                                if((tabuleiro[linha-1][coluna+i-1] != '0') && (tabuleiro[linha-1][coluna+i-1] != 'k'))
                                    return 0;
                            }

                            //percorrer a coluna
                            for(i=0; i<3; i++)
                            {
                                if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                                    return 0;
                            }

                            return 1;

                    case 2:

                            if(linha == 1)
                                return 1;

                            //percorrer a linha
                            for(i=0; i<3; i++)
                            {
                                if((tabuleiro[linha-1][coluna+i] != '0') && (tabuleiro[linha-1][coluna+i] != 'k'))
                                    return 0;
                            }

                            return 1;

                    case 3:

                        //percorrer a linha
                        for(i=0; i<3; i++)
                        {
                            if((tabuleiro[linha-1][coluna+1+i] != '0') && (tabuleiro[linha-1][coluna+1+i] != 'k'))
                                    return 0;
                        }

                        return 1;

                    case 4:

                        if(coluna == 1)
                            return 1;

                        
                        //percorrer a coluna
                        for(i=0; i<3; i++)
                        {
                            if((tabuleiro[linha+i][coluna-1] != '0') && (tabuleiro[linha+i][coluna-1] != 'k'))
                                return 0;
                        }

                        return 1;
                        
                    case 5:

                        return 1;

                    case 6:

                        return 1;
                        
                    case 7:

                        //percorrer a coluna
                        for(i=0; i<2; i++)
                        {
                            if((tabuleiro[linha+1+i][coluna-1] != '0') && (tabuleiro[linha+1+i][coluna-1] != 'k'))
                                return 0;
                        }

                        return 1;

                    case 8:

                        return 1;

                    case 9:

                        return 1;

                }

            break;

        case 2:
                switch(tipo)
                {
                    case 1:

                        //percorrer linha
                        for(i=0; i<4; i++)
                        {
                            if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                                return 0;
                        }

                        //percorrer coluna
                        for(i=0; i<3; i++)
                        {
                            if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                                return 0;
                        }
               
                        return 1;

                    case 2:

                        //percorrer linha
                        for(i=0; i<4; i++)
                        {
                            if((tabuleiro[linha-1][coluna+i] != '0') && (tabuleiro[linha-1][coluna+i] != 'k'))
                                return 0;
                        }

                        return 1;

                    case 3:

                        //percorrer coluna
                        for(i=0; i<3; i++)
                        {
                            if((tabuleiro[linha+i][coluna-1] != '0') && (tabuleiro[linha+i][coluna-1] != 'k'))
                                return 0;
                        }

                        return 1;

                    case 4:

                        return 1;

                    case 5:

                        //percorrer coluna
                        for(i=0; i<2; i++)
                        {
                            if((tabuleiro[linha+1+i][coluna-1] != '0') && (tabuleiro[linha+1+i][coluna-1] != 'k'))
                                return 0;
                        }

                        return 1;

                    case 6:

                        return 1;

                    case 7:

                        //percorrer linha
                        for(i=0; i<3; i++)
                        {
                            if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                                return 0;
                        }

                        //percorrer coluna
                        for(i=0; i<4; i++)
                        {
                            if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                                return 0;
                        }

                        return 1;
                        
                    case 8:

                        //percorrer coluna
                        for(i=0; i<3; i++)
                        {
                            if((tabuleiro[linha+i][coluna-1] != '0') && (tabuleiro[linha+i][coluna-1] != 'k'))
                                return 0;
                        }

                        return 1;

                    case 9:

                        //percorrer linha
                        for(i=0; i<3; i++)
                        {
                            if((tabuleiro[linha-1][coluna+i] != '0') && (tabuleiro[linha-1][coluna+i] != 'k'))
                                return 0;
                        }

                        return 1;
                        
                    case 10:

                        return 1;

                    case 11:

                        //percorrer linha
                        for(i=0; i<3; i++)
                        {
                            if((tabuleiro[linha-1][coluna+1+i] != '0') && (tabuleiro[linha-1][coluna+1+i] != 'k'))
                                return 0;
                        }

                        return 1;
                        
                    case 12:

                        return 1;
                }

            break;

        case 3:

            switch(tipo)
            {
                case 1:

                    //percorrer linha
                    for(i=0; i<5; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;

                case 2:

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha+i][coluna-1] != '0') && (tabuleiro[linha+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;

                case 3:

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha+1+i][coluna-1] != '0') && (tabuleiro[linha+1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;

                case 4:

                    //percorrer linha
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 5:

                    //percorrer linha
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1][coluna+i] != '0') && (tabuleiro[linha-1][coluna+i] != 'k'))
                            return 0;
                    }

                    return 1;

                case 6:

                    //percorrer linha
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1][coluna+1+i] != '0') && (tabuleiro[linha-1][coluna+1+i] != 'k'))
                            return 0;
                    }

                    return 1;
                    
            }

            break;
    
        case 4:

            switch(tipo)
            {
                case 1:

                    //percorrer linha
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                                      
                case 2:

                    //percorrer linha
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1][coluna+i] != '0') && (tabuleiro[linha-1][coluna+i] != 'k'))
                            return 0;
                    }
                    
                    return 1;


                case 3:

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha+i][coluna-1] != '0') && (tabuleiro[linha+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 4:

                    return 1;
            
            }

            break;

        case 5:

            switch(tipo)
            {
                case 1:

                    //percorrer linha
                    for(i=0; i<5; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 2:

                    //percorrer linha
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 3:

                    //percorrer linha
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1][coluna+i] != '0') && (tabuleiro[linha-1][coluna+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha+1+i][coluna-1] != '0') && (tabuleiro[linha+1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 4:

                    //percorrer linha
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1][coluna+1+i] != '0') && (tabuleiro[linha-1][coluna+1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha+i][coluna-1] != '0') && (tabuleiro[linha+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
            }

            break;

        case 6:

            switch(tipo)
            {
                case 1:

                    //percorrer linha
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha-1][coluna+i] != '0') && (tabuleiro[linha-1][coluna+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha+i][coluna-1] != '0') && (tabuleiro[linha+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 2:

                    //percorrer linha
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1][coluna+i] != '0') && (tabuleiro[linha-1][coluna+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<3; i++)
                    {
                        if((tabuleiro[linha+i][coluna-1] != '0') && (tabuleiro[linha+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 3:

                    //percorrer linha
                    for(i=0; i<5; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 4:

                    //percorrer linha
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
            }

            break;

        case 7:

            switch(tipo)
            {
                case 1:

                    //percorrer linha
                    for(i=0; i<5; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
                case 2:

                    //percorrer linha
                    for(i=0; i<5; i++)
                    {
                        if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                            return 0;
                    }

                    //percorrer coluna
                    for(i=0; i<4; i++)
                    {
                        if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                            return 0;
                    }

                    return 1;
                    
            }

            break;

        case 8:

            //percorrer linha
            for(i=0; i<5; i++)
            {
                if((tabuleiro[linha-1][coluna-1+i] != '0') && (tabuleiro[linha-1][coluna-1+i] != 'k'))
                    return 0;
            }

            //percorrer coluna
            for(i=0; i<4; i++)
            {
                if((tabuleiro[linha-1+i][coluna-1] != '0') && (tabuleiro[linha-1+i][coluna-1] != 'k'))
                    return 0;
            }

            return 1;
                    
            break;

    }

    return 0;
}


/************************************************************
 * Function name: Posicionamento_1() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *              posicionamento(int) - Tipo de posicionamento a ser tomado
 *
 * Description:
 *              Function responsible for put the pieces in the board, respecting all the rules
 ***********************************************************************************************
*/
void Posicionamento_1(int linha, int coluna, int posicionamento, int num_pecas)
{
    int i, j;
    int aleat_peca, aleat_tipo, aux, count;
    //time_t t1;

    //como estava srand((unsigned) time(&t1));    //generate different boards each time the program is executed
    srand(time(0));    //generate different boards each time the program is executed

    if(posicionamento == 1)
    {
        //restrição 3
        for(i=8; i>0; i--)
        {
            for(j=0; j<i; j++)
            {
                if(pecas[i]>pecas[j])
                {
                    printf("A restrição 3 não é cumprida!!!\n");
                    exit(0);
                }
            }
        }

        //restrição 4
        if(num_pecas>((linha/3) * (coluna/3)))
        {
            printf("A restrição 4 não é cumprida!!!\n");
            exit(0);
        }

    }

    for(i=1; i<linha-1; i+=3)
    {
        for(j=1; j<coluna-1; j+=3)
        {
            count = 0;
            aux = 0;

            //printf("Valor de i: %d e de j: %d\n", i, j);  //verificar se estamos a percorrer bem o tabuleiro

            //Imprimir Tabuleiro com a peça colocada anteriormente
            //Imprimir_Tabuleiro(linha, coluna);
    

            do{
                aleat_peca = rand()%9;

                if((pecas[0] == 0) && (pecas[1] == 0) && (pecas[2] == 0) && (pecas[3] == 0) && (pecas[4] == 0) && (pecas[5] == 0) && (pecas[6] == 0) && (pecas[7] == 0))
                    return;

            }while(pecas[aleat_peca] <= 0);

            //printf("Peça a posicionar: %d\n", aleat_peca+1);

            do{
                switch(aleat_peca+1)
                {
                    case 1:
                        aleat_tipo = rand()%9 +1;
                        break;

                    case 2:
                        aleat_tipo = rand()%12 +1;
                        break;

                    case 3:
                        aleat_tipo = rand()%6 +1;
                        break;

                    case 4:
                        aleat_tipo = rand()%4 +1;
                        break;

                    case 5:
                        aleat_tipo = rand()%4 +1;
                        break;

                    case 6:
                        aleat_tipo = rand()%4 +1;
                        break;

                    case 7:
                        aleat_tipo = rand()%2 +1;
                        break;

                    case 8:
                        aleat_tipo = 1;
                        break;
                }

                aux = Avaliar_posicionamento(aleat_peca + 1, aleat_tipo, i, j);

                //if(aux == 1)
                  //  printf("Hello\n");

                if(aux == 0)
                    count++;

            }while((aux == 0) && (count != 3));

            if((aux == 1) && (count < 3))    //a peça pode ser colocada
            {
                pecas[aleat_peca] -= 1;
            }

            /*
            if((count == 2) && (pecas[0] <= 0))     //se não houver peça do tipo 1, passamos para a próxima 
            {                                       //matriz 3x3
                printf("Peça: %d Tipo: %d\n", aleat_peca+1, aleat_tipo);
                printf("Valor de j: %d\n", j);
            }*/                           

            //printf("Modo de posicionamneto da peça: %d\n", aleat_tipo);

            if((pecas[0] > 0) && (count == 3))      //se houver peça do tipo 1, coloca-se a mesma no centro da
            {                                       //matriz 3x3
                Colocar_individual(barco1_5, i, j);
                pecas[0] -= 1;
                continue;
            }
            else
            {
                if(count == 3)
                    continue;
            }

            //printf("colocar j: %d\n\n", j);

            switch(aleat_peca + 1)
            {
                case 1:
                
                    switch(aleat_tipo)
                    {
                        case 1:
                    
                            Colocar_individual(barco1_1, i, j);
                            break;
                    
                        case 2:

                            Colocar_individual(barco1_2, i, j);
                            break;
                        case 3:

                            Colocar_individual(barco1_3, i, j);
                            break;
                    
                        case 4:

                            Colocar_individual(barco1_4, i, j);
                            break;

                        case 5:

                            Colocar_individual(barco1_5, i, j);
                            break;
                        
                        case 6:

                            Colocar_individual(barco1_6, i, j);
                            break;
                        
                        case 7:

                            Colocar_individual(barco1_7, i, j);
                            break;
                        
                        case 8:

                            Colocar_individual(barco1_8, i, j);
                            break;
                        
                        case 9:

                            Colocar_individual(barco1_9, i, j);
                            break;
                        
                    }

                break;

            case 2:

                switch(aleat_tipo)
                {
                    case 1:

                        Colocar_individual(barco2_1, i, j);
                        break;
                        
                    case 2:

                        Colocar_individual(barco2_2, i, j);
                        break;
                        
                    case 3:

                        Colocar_individual(barco2_3, i, j);
                        break;
                        
                    case 4:

                        Colocar_individual(barco2_4, i, j);
                        break;
                        
                    case 5:

                        Colocar_individual(barco2_5, i, j);
                        break;
                        
                    case 6:

                        Colocar_individual(barco2_6, i, j);
                        break;
                        
                    case 7:

                        Colocar_individual(barco2_7, i, j);
                        break;
                        
                    case 8:

                        Colocar_individual(barco2_8, i, j);
                        break;
                        
                    case 9:

                        Colocar_individual(barco2_9, i, j);
                        break;
                        
                    case 10:

                        Colocar_individual(barco2_10, i, j);
                        break;
                        
                    case 11:

                        Colocar_individual(barco2_11, i, j);
                        break;
                        
                    case 12:

                        Colocar_individual(barco2_12, i, j);
                        break;
                            
                }

                break;

            case 3:

                switch(aleat_tipo)
                {
                    case 1:

                        Colocar_individual(barco3_1, i, j);
                        break;
                        
                    case 2:

                        Colocar_individual(barco3_2, i, j);
                        break;
                    
                    case 3:

                        Colocar_individual(barco3_3, i, j);
                        break;
                    
                    case 4:

                        Colocar_individual(barco3_4, i, j);
                        break;
                    
                    case 5:

                        Colocar_individual(barco3_5, i, j);
                        break;
                    
                    case 6:

                        Colocar_individual(barco3_6, i, j);
                        break;
                    
                }

            break;
    
        case 4:

            switch(aleat_tipo)
            {
                case 1:

                    Colocar_individual(barco4_1, i, j);
                    break;
                                      
                case 2:

                    Colocar_individual(barco4_2, i, j);
                    break;
                    
                case 3:

                    Colocar_individual(barco4_3, i, j);
                    break;
                    
                case 4:

                    Colocar_individual(barco4_4, i, j);
                    break;
                    
            }

            break;

        case 5:

            switch(aleat_tipo)
            {
                case 1:

                    Colocar_individual(barco5_1, i, j);
                    break;
                    
                case 2:

                    Colocar_individual(barco5_2, i, j);
                    break;
                    
                case 3:

                    Colocar_individual(barco5_3, i, j);
                    break;
                    
                case 4:

                    Colocar_individual(barco5_4, i, j);
                    break;
                    
            }

            break;

        case 6:

            switch(aleat_tipo)
            {
                case 1:

                    Colocar_individual(barco6_1, i, j);
                    break;
                    
                case 2:

                    Colocar_individual(barco6_2, i, j);
                    break;
                    
                case 3:

                    Colocar_individual(barco6_3, i, j);
                    break;
                    
                case 4:

                    Colocar_individual(barco6_4, i, j);
                    break;
                                        
            }

            break;

        case 7:

            switch(aleat_tipo)
            {
                case 1:

                    Colocar_individual(barco7_1, i, j);
                    break;
                    
                case 2:

                    Colocar_individual(barco7_2, i, j);
                    break;
                    
            }

            break;

        case 8:

            Colocar_individual(barco8, i, j);
            break;                        
        }

        }
    }

    return ;
}


/************************************************************
 * Function name: modo_d1() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *
 * Description:
 *              This function selects a random coordinate to shoot which is different
 *              from coordinates choosen before
 ***********************************************************************************************
*/
void modo_d1(int linha, int coluna)
{
	int cord_linha;
	int cord_coluna;

	while(Verifica_afundancos(linha, coluna) == 0)
	{
        sleep(1);

		do{
			cord_linha = rand() % linha + 1;
			cord_coluna = rand() % coluna + 1;

            if((cord_linha == linha))
            {
                cord_linha--;
            } 		

            if(cord_coluna == coluna)
            {
                cord_coluna--;
            }

		}while(tabuleiro[cord_linha][cord_coluna] == '-');

        tabuleiro[cord_linha][cord_coluna] = '-';

        printf("\n\n");
        Imprimir_Tabuleiro(linha, coluna);  //Watch the board after the computer have shoot
	}

	return;
}

/************************************************************
 * Function name: Verifica_afundancos() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *
 * Description:
 *              This function verifies if there is still a piece in the board
 ***********************************************************************************************
*/
int Verifica_afundancos(int linha, int coluna)
{
    int i,j;
	for(i=1; i<linha; i++)
	{
		for(j=1; j< coluna; j++)
		{
			if((tabuleiro[i][j] == '1') || (tabuleiro[i][j] == '2') || (tabuleiro[i][j] == '3') || (tabuleiro[i][j] == '4') || (tabuleiro[i][j] == '5') || (tabuleiro[i][j] == '6') || (tabuleiro[i][j] == '7') || (tabuleiro[i][j] == '8'))
				return 0;
		}
	}
	
	return 1;	
}

/************************************************************
 * Function name: modo_d2() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *
 * Description:
 *              This function shoots to the boat according a spiecific order while the boat exist
 **************************************************************************************************
*/
void modo_d2(int linha, int coluna)
{
	int i, j, k;

	for(i=1; i<linha-1; i+=3)
	{
		for(j=1; j<coluna-1; j+=3)
		{
			k = 1;
			do{
                sleep(1);

                printf("\n\n");
                Imprimir_Tabuleiro(linha, coluna);
				switch(k)
				{
					case 1: tabuleiro[i+1][j+1] = '-';
						break;

					case 2:
						tabuleiro[i][j+1] = '-';													
						break;

					case 3:
						tabuleiro[i+2][j+1] = '-';
						break;

					case 4:
						tabuleiro[i+1][j] = '-';
						break;

					case 5:
						tabuleiro[i+1][j+2] = '-';
						break;

					case 6:
						tabuleiro[i][j] = '-';
						break;

					case 7:
						tabuleiro[i+2][j+2] = '-';
						break;

					case 8:
						tabuleiro[i][j+2] = '-';
						break;
					
					case 9:
						tabuleiro[i+2][j] = '-';
						break;
				}
				k++;
			}while(Verifica_afundancos_mini(i, j) == 0);
		}
	}

}

/************************************************************
 * Function name: Verifica_afundancos_mini() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *
 * Returned:
 *          This function returns 1 if there is not any piece in the matrix 3x3 and 0 otherwise  
 *
 * Description:
 *              This function verifies if there is still a piece in the matrix 3x3
 ***********************************************************************************************
*/
int Verifica_afundancos_mini(int linha, int coluna)
{
	int i, j;

	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if((tabuleiro[linha+i][coluna+j] == '1') || (tabuleiro[linha+i][coluna+j] == '2') || (tabuleiro[linha+i][coluna+j] == '3') || (tabuleiro[linha+i][coluna+j] == '4') || (tabuleiro[linha+i][coluna+j] == '5') || (tabuleiro[linha+i][coluna+j] == '6') || (tabuleiro[linha+i][coluna+j] == '7') || (tabuleiro[linha+i][coluna+j] == '8'))
				return 0;
		}
	}
	
	return 1;	
}


/************************************************************
 * Function name: modo_d3() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *
 * Description:
 *              This function shoot exactly like modo_d2, but don't spend bullets on unnecessary shoots.
 *              In other words, this function put an X next to  the piece after that got shooted
 *              this permits that the computer don't spend time or bullets shooting in places where obviously
 *              are not boats
 **************************************************************************************************
*/
void modo_d3(int linha, int coluna)
{
	int i, j, k;

	for(i=1; i<linha-1; i+=3)
	{
		for(j=1; j<coluna-1; j+=3)
		{
			k = 1;
            Check_other_boats(i, j);
			do{
                sleep(1);

                printf("\n\n");
                Imprimir_Tabuleiro(linha, coluna);
				switch(k)
				{
					case 1: 
                        if(tabuleiro[i+1][j+1] != 'X')
                        {
                            tabuleiro[i+1][j+1] = '-';
                        }
						break;

					case 2:
                        if(tabuleiro[i][j+1] != 'X')
                        {
                            tabuleiro[i][j+1] = '-';
                        }													
						break;

					case 3:
                        if(tabuleiro[i+2][j+1] != 'X')
                        {
                            tabuleiro[i+2][j+1] = '-';
                        }
						break;

					case 4:
                        if(tabuleiro[i+1][j] != 'X')
                        {
                            tabuleiro[i+1][j] = '-';
                        }
						break;

					case 5:
                        if(tabuleiro[i+1][j+2] != 'X')
                        {
                            tabuleiro[i+1][j+2] = '-';
						}
						break;

					case 6:
                        if(tabuleiro[i][j] != 'X')
                        {
						    tabuleiro[i][j] = '-';
						}
                        break;

					case 7:
                        if(tabuleiro[i+2][j+2] != 'X')
                        {
                            tabuleiro[i+2][j+2] = '-';
                        }
                        break;

					case 8:
                        if(tabuleiro[i][j+2] != 'X')
                        {
						    tabuleiro[i][j+2] = '-';	
                        }
                        break;
					
					case 9:
                        if(tabuleiro[i+2][j] != 'X')
                        {
						    tabuleiro[i+2][j] = '-';
						}
                        break;
				}
				k++;
			}while(Verifica_afundancos_mini(i, j) == 0);
		}
	}
}

/************************************************************
 * Function name: Check_other_boats() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *
 * Description:
 *              This function puts an 'X' if there is a boat nearby
 **************************************************************************************************
*/
void Check_other_boats(int line, int collumn)
{
    int i;
    int j;

    //Put 'X' in collumn right before of the piece(matrix 3x3)    if(board[line][collumn+3] == 'k')
    if(!(tabuleiro[line][collumn+3] == 'k'))
    {
        //Put X charcater
        for(i=0; i<3; i++)
        {
            if(tabuleiro[line+i][collumn+3] == '0')
            {
                if((tabuleiro[line+i][collumn+2] != 'k') && (tabuleiro[line+i][collumn+2] != '0'))
                {
                    tabuleiro[line+i][collumn+3] = 'X';
                }
            }
        }
        if(tabuleiro[line+i][collumn+3] == '0')
        {
            if((tabuleiro[line+i-1][collumn+2] != 'k') && (tabuleiro[line+i-1][collumn+2] != '0'))
            {
                tabuleiro[line+i][collumn+3] = 'X';
            }
        }
    }

    //Put 'X' in the line right before of the piece(matrix 3x3) 
    if((tabuleiro[line+3][collumn] == 'k'))
    {
        //Put X charcater
        for(i=0; i<3; i++)
        {
            if(tabuleiro[line+3][collumn+i] == '0')
            {
                if((tabuleiro[line+2][collumn+i] != 'k') && (tabuleiro[line+2][collumn+i] != '0'))
                {
                    tabuleiro[line+3][collumn+i] = 'X';
                }
            }
        }
    }
}

/************************************************************
 * Function name: Check_other_boats() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *
 * Description:
 *              This function puts an 'X' if there is a boat nearby
 **************************************************************************************************
*/
void modo_djogador(char play[3])
{
    char collumn_letter = play[0];
    char line_digits[2] = {play[1], play[2]};
    int collumn = collumn_letter - 'A' + 1;
    int line = atoi(line_digits) + 1;

    if(tabuleiro[line][0] == 'k')
    {
        line--;
    }
    if(tabuleiro[0][collumn] == 'k')
    {
        collumn--;
    }

    if((tabuleiro[line][collumn] == '0') || (tabuleiro[line][collumn] == '0'))
    {
        printf("-");
    }
    else
    {
        printf("%c", tabuleiro[line][collumn]);
    }

    tabuleiro[line][collumn] = '-';

    return ;
}

/************************************************************
 * Function name: Check_other_boats() 
 *
 * Argumentos:
 *              linha (int) - Número de linhas do tabuleiro       
 *              coluna (int) - Número de colunas do tabuleiro
 *
 * Description:
 *              This function puts an 'X' if there is a boat nearby
 **************************************************************************************************
*/
void jogador_dispara(int line, int collumn)
{
    char aux[3];
    
    do{
        printf("Digite as coordenadas de disparo(use a notação colunalinha, por exemplo A12)\n");
        scanf("%s", aux);

        modo_djogador(aux);

    }while(Verifica_afundancos(line, collumn) == 0);    

    return ;
}