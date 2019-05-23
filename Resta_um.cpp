#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int matriz[8] [8] = {{0, 65, 66, 67, 68, 69, 70, 71},
                             {49, 0, 0, 220, 220, 220, 0, 0},
                             {50, 0, 0, 220, 220, 220, 0, 0},
                             {51, 220, 220, 220, 220, 220, 220, 220},
                             {52, 220, 220, 220, 176, 220, 220, 220},
                             {53, 220, 220, 220, 220, 220, 220, 220},
                             {54, 0, 0, 220, 220, 220, 0, 0},
                             {55, 0, 0, 220, 220, 220, 0, 0}};

FILE * arquivo;
char texto[100];

int comando;
char player[20];

void tabuleiro();
void jogo();
void inicial();

int main(){
    int y,z;

    for( y = 0; y < 12; ++y){
        for(z = 2; z < 10; ++z){
            if (z%2 == 0){
                system("COLOR 2");
                    printf(" RESTA UM ");
                }
            else{
                system("COLOR 04");
                printf(" RESTA UM ");
                }
        }
    }

    inicial();

    if(comando == 4){
        return 0;
    }

    if(comando != 4 || 2 || 1){
        system("cls");
        inicial();
        printf("\nDigite um dos comandos acima\n");
        scanf("%d", &comando);
    }

return 0;
}
void jogo(){
    int j, coluna, resp = 0;
    char i, direcao;
    int contador;

    system("cls");
    printf("Jogador: %s\n\n",player);
    printf("Movimento: %d\n\n",contador);
    for(int m = 0; m < 8; ++m){
        printf("  ");
            for (int n = 0; n < 8; ++n) {
                printf(" %c ", matriz [m] [n]);
                printf("\t");
                }
            printf("\n\n");
    }
    printf("\n\n");

        printf("digite a coluna: ");
        scanf("%c", &i);
        scanf("%c", &i);

    switch (i){
        case 'a':
            coluna = 1;
            break;

        case 'b':
            coluna = 2;
            break;

        case 'c':
            coluna = 3;
            break;

        case 'd':
            coluna = 4;
            break;

        case 'e':
            coluna = 5;
            break;

        case 'f':
            coluna = 6;
            break;

        case 'g':
        	coluna = 7;
            break;

        default:
            printf(" \ncordenada invalida\n");
            break;
        }
        printf("digite a linha: ");
        scanf("%d", &j);
        if(j == 0){printf(" \ncordenada invalida\n");}

//vericacao
        if(matriz[j][coluna] == 220){

            printf("direcao: ");
            scanf("%c", &direcao);
            scanf("%c", &direcao);
            printf("\n\nTem certeza? ");
            scanf("%d", &resp);
        if(resp == 1){
				
            switch (direcao){           	
//movimentacao
			for(contador=0;contador<32;contador++){
			
                case 'w':
                    if((matriz[j - 1][coluna] == 220 ) && (matriz[j - 2][coluna] == 176)){
                        matriz[j][coluna]  = 176;
                        matriz[j - 1][coluna] = 176;
                        matriz[j - 2][coluna] = 220;
                    	contador=contador+1;
                            }
                    else{printf("jogada invalida");}
                    break;

                case 'd':
                    if((matriz[j][coluna + 1] == 220 ) && (matriz[j][coluna + 2] == 176)){
                        matriz[j][coluna]  = 176;
                        matriz[j][coluna + 1] = 176;
                        matriz[j][coluna + 2] = 220;
                    	contador=contador+1;
                    }
                    else{printf("jogada invalida");}
                    break;

                case 's':
                    if((matriz[j + 1][coluna] == 220 ) && (matriz[j + 2][coluna] == 176)){
                        matriz[j][coluna]  = 176;
                        matriz[j + 1][coluna] = 176;
                        matriz[j + 2][coluna] = 220;
                    	contador=contador+1;
                        }
                    else{printf("jogada invalida");}
                    break;

                case 'a':
                    if((matriz[j][coluna - 1] == 220 ) && (matriz[j][coluna - 2] == 176)){
                        matriz[j][coluna]  = 176;
                        matriz[j][coluna - 1] = 176;
                        matriz[j][coluna - 2] = 220;
                        contador=contador+1;
                        }
                    else{printf("jogada invalida");}
                    break;

                    default:
                        printf("\nselecione corretamente a direcao\n");
                    break;
            }
        //  }else{

            }
        }
        else{printf("\nEscolha uma peca valida\n");}
	}
}
void tabuleiro(){

    int f;
    system("COLOR 05");
    printf("\n\n\n\n\n\n\n\n\t\t\tINICIAR JOGO: digite a tecla 1\n\n\t\t\t\t\t");
    scanf("%d", &f);
    system("cls");

     system("COLOR 06");
     printf("\n\n\n\n\n\n\n\n\t\t\tNOME DO JOGADOR: ");
     scanf("%s", &player);
     system("cls");
     system("COLOR 05");
     while(f == 1){
     jogo();
     }
}
void inicial(){

    system("cls");
    system("COLOR 6");

    arquivo = fopen("C:\\Users\\PC\\Desktop\\arte.txt", "r");
    printf("%s", texto);
    while(fgets(texto, 100, arquivo) != NULL) { printf("%s", texto); }

    fclose(arquivo);

    system("COLOR 2");
    printf("\n\n(1) Iniciar o jogo");
    printf("\n\n(2) Ver as regras\n");
    printf("\n(3) Ranking\n");
    printf("\n(4) Sair\n");
    scanf("%d", &comando);

    while(comando == 2){
        system("cls");
        arquivo = fopen("regras.txt", "r");

    while(fgets(texto, 100, arquivo) != NULL) { printf("%s", texto); }

        fclose(arquivo);
        printf("\n\nPressione qualquer tecla para voltar");
        getch();
        inicial();

    }
    while(comando == 1){
            printf("\a");
            system("cls");
            tabuleiro();
            inicial();
    }
}
