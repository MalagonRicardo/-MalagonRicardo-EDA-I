// Práctica 3 Movimientos validos en piezas de ajedrez con estructuras
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (){

    int tablero[8][8];
    int ren, col;

    struct caballo{
        int ren;
        int col;
    };

    struct alfil{
        int ren;
        int col;
    };

    struct torre{
        int ren;
        int col;
    };

    struct reina{
        int ren;
        int col;
    };

    struct rey{
        int ren;
        int col;
    };

    int opcion = 0;

    while(true){
        printf("\n     ¿Que desea hacer?\n");
        printf("  1.Movimientos del Caballo\n  2.Movimientos del Alfil\n  3.Movimientos de la Torre\n  4.Movimientos de la Reina\n  5.Movimientos del Rey\n  6.Salir\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                for (ren=0; ren<8; ren++){
                    for (col=0; col<8; col++){
                        tablero[ren][col]=0; 
                    }
                }

                printf("Posicion del Caballo\n");
                printf("Escriba la coordenada x:"); 
                scanf("%d", &col);
                printf("Escriba la coordenada y:");
                scanf("%d", &ren);
                struct caballo coord = {ren, col};
                printf("x = %d\n", coord.col);
                printf("y = %d\n", coord.ren);
                tablero[ren][col]=1;

                int renC1, colC1;
                renC1=ren+2;
                colC1=col+1;
                    tablero[renC1][colC1]=2;

                int renC2, colC2;
                renC2=ren+2;
                colC2=col-1;
                    tablero[renC2][colC2]=2;

                int renC3, colC3;
                renC3=ren-2;
                colC3=col+1;
                    tablero[renC3][colC3]=2;

                int renC4, colC4;
                renC4=ren-2;
                colC4=col-1;
                    tablero[renC4][colC4]=2;

                int renC5, colC5;
                renC5=ren+1;
                colC5=col+2;
                    tablero[renC5][colC5]=2;

                int renC6, colC6;
                renC6=ren-1;
                colC6=col+2;
                    tablero[renC6][colC6]=2;

                int renC7, colC7;
                renC7=ren+1;
                colC7=col-2;
                    tablero[renC7][colC7]=2;

                int renC8, colC8;
                renC8=ren-1;
                colC8=col-2;
                    tablero[renC8][colC8]=2;

                for (ren=0; ren<8; ren++){
                    printf("\n");
                    for(col=0; col<8; col++){
                        if(tablero[ren][col]==0){
                            printf("o\t");
                        }
                        if(tablero[ren][col]==1){
                            printf("C\t");
                        }
                        if(tablero[ren][col]==2){
                            printf("X\t");
                        }  
                    }
                    printf("\n");
                }   
            break;
            case 2:

                for (ren=0; ren<8; ren++){
                    for (col=0; col<8; col++){
                        tablero[ren][col]=0; 
                    }
                }

                printf("Posicion del Alfil\n");
                printf("Escriba la coordenada x:"); 
                scanf("%d", &col);
                printf("Escriba la coordenada y:");
                scanf("%d", &ren);
                struct alfil coord2 = {ren, col};
                printf("x = %d\n", coord2.col);
                printf("y = %d\n", coord2.ren);
                tablero[ren][col]=1;

                int renA1, colA1;
                renA1=ren-1;
                colA1=col-1;
                while(renA1>=0 && colA1>=0){
                    tablero[renA1][colA1]=2;
                    renA1--;
                    colA1--;
                }
                int renA2, colA2;
                renA2=ren-1;
                colA2=col+1;
                while(renA2>=0 && colA2<=7){
                    tablero[renA2][colA2]=2;
                    renA2--;
                    colA2++;
                }
                int renA3, colA3;
                renA3=ren+1;
                colA3=col-1;
                while(renA3<=7 && colA3>=0){
                    tablero[renA3][colA3]=2;
                    renA3++;
                    colA3--;
                }
                int renA4, colA4;
                renA4=ren+1;
                colA4=col+1;
                while(renA4<=7 && colA4<=7){
                    tablero[renA4][colA4]=2;
                    renA4++;
                    colA4++;
                }
                for (ren=0; ren<8; ren++){
                    printf("\n");
                    for(col=0; col<8; col++){
                        if(tablero[ren][col]==0){
                            printf("o\t");
                        }
                        if(tablero[ren][col]==1){
                            printf("A\t");
                        }
                        if(tablero[ren][col]==2){
                            printf("X\t");
                        }  
                    }
                    printf("\n");
                }   

             break;
            case 3:
                for (ren=0; ren<8; ren++){
                    for (col=0; col<8; col++){
                        tablero[ren][col]=0; 
                    }
                }

                printf("Posicion de la Torre\n");
                printf("Escriba la coordenada x:"); 
                scanf("%d", &col);
                printf("Escriba la coordenada y:");
                scanf("%d", &ren);
                struct torre coord3 = {ren, col};
                printf("x = %d\n", coord3.col);
                printf("y = %d\n", coord3.ren);
                tablero[ren][col]=1;

                int renT1, colT1;
                renT1=ren+1;
                colT1=col;
                while(renT1<=7){
                    tablero[renT1][colT1]=2;
                    renT1++;
                }
                int renT2, colT2;
                renT2=ren-1;
                colT2=col;
                while(renT2>=0){
                    tablero[renT2][colT2]=2;
                    renT2--;
                }
                int renT3, colT3;
                renT3=ren;
                colT3=col+1;
                while(colT3<=7){
                    tablero[renT3][colT3]=2;
                    colT3++;

                }
                int renT4, colT4;
                renT4=ren;
                colT4=col-1;
                while(colT4>=0){
                    tablero[renT4][colT4]=2;
                    colT4--;
                }
                for (ren=0; ren<8; ren++){
                    printf("\n");
                    for(col=0; col<8; col++){
                        if(tablero[ren][col]==0){
                            printf("o\t");
                        }
                        if(tablero[ren][col]==1){
                            printf("T\t");
                        }
                        if(tablero[ren][col]==2){
                            printf("X\t");
                        }  
                    }
                    printf("\n");
                }   
             break;
            case 4:
                for (ren=0; ren<8; ren++){
                    for (col=0; col<8; col++){
                        tablero[ren][col]=0; 
                    }
                }

                printf("Posicion de la Reina\n");
                printf("Escriba la coordenada x:"); 
                scanf("%d", &col);
                printf("Escriba la coordenada y:");
                scanf("%d", &ren);
                struct reina coord4 = {ren, col};
                printf("x = %d\n", coord4.col);
                printf("y = %d\n", coord4.ren);
                tablero[ren][col]=1;

                int renQ1, colQ1;
                renQ1=ren-1;
                colQ1=col-1;
                while(renQ1>=0 && colQ1>=0){
                    tablero[renQ1][colQ1]=2;
                    renQ1--;
                    colQ1--;
                }
                int renQ2, colQ2;
                renQ2=ren-1;
                colQ2=col+1;
                while(renQ2>=0 && colQ2<=7){
                    tablero[renQ2][colQ2]=2;
                    renQ2--;
                    colQ2++;
                }
                int renQ3, colQ3;
                renQ3=ren+1;
                colQ3=col-1;
                while(renQ3<=7 && colQ3>=0){
                    tablero[renQ3][colQ3]=2;
                    renQ3++;
                    colQ3--;
                }
                int renQ4, colQ4;
                renQ4=ren+1;
                colQ4=col+1;
                while(renQ4<=7 && colQ4<=7){
                    tablero[renQ4][colQ4]=2;
                    renQ4++;
                    colQ4++;
                }
                int renQ5, colQ5;
                renQ5=ren+1;
                colQ5=col;
                while(renQ5<=7){
                    tablero[renQ5][colQ5]=2;
                    renQ5++;
                }
                int renQ6, colQ6;
                renQ6=ren-1;
                colQ6=col;
                while(renQ6>=0){
                    tablero[renQ6][colQ6]=2;
                    renQ6--;
                }
                int renQ7, colQ7;
                renQ7=ren;
                colQ7=col+1;
                while(colQ7<=7){
                    tablero[renQ7][colQ7]=2;
                    colQ7++;

                }
                int renQ8, colQ8;
                renQ8=ren;
                colQ8=col-1;
                while(colQ8>=0){
                    tablero[renQ8][colQ8]=2;
                    colQ8--;
                }
                for (ren=0; ren<8; ren++){
                    printf("\n");
                    for(col=0; col<8; col++){
                        if(tablero[ren][col]==0){
                            printf("o\t");
                        }
                        if(tablero[ren][col]==1){
                            printf("Q\t");
                        }
                        if(tablero[ren][col]==2){
                            printf("X\t");
                        }  
                    }
                    printf("\n");
                }   
             break;
            case 5:
                for (ren=0; ren<8; ren++){
                    for (col=0; col<8; col++){
                        tablero[ren][col]=0; 
                    }
                }

                printf("Posicion del Rey\n");
                printf("Escriba la coordenada x:"); 
                scanf("%d", &col);
                printf("Escriba la coordenada y:");
                scanf("%d", &ren);
                struct rey coord5 = {ren, col};
                printf("x = %d\n", coord5.col);
                printf("y = %d\n", coord5.ren);
                tablero[ren][col]=1;

                int renR1, colR1;
                renR1=ren-1;
                colR1=col-1;
                tablero[renR1][colR1]=2;

                int renR2, colR2;
                renR2=ren-1;
                colR2=col+1;
                tablero[renR2][colR2]=2;

                int renR3, colR3;
                renR3=ren+1;
                colR3=col-1;
                tablero[renR3][colR3]=2;

                int renR4, colR4;
                renR4=ren+1;
                colR4=col+1;
                tablero[renR4][colR4]=2;

                int renR5, colR5;
                renR5=ren+1;
                colR5=col;
                tablero[renR5][colR5]=2;

                int renR6, colR6;
                renR6=ren-1;
                colR6=col;
                tablero[renR6][colR6]=2;

                int renR7, colR7;
                renR7=ren;
                colR7=col+1;
                tablero[renR7][colR7]=2;

                int renR8, colR8;
                renR8=ren;
                colR8=col-1;
                tablero[renR8][colR8]=2;

                for (ren=0; ren<8; ren++){
                    printf("\n");
                    for(col=0; col<8; col++){
                        if(tablero[ren][col]==0){
                            printf("o\t");
                        }
                        if(tablero[ren][col]==1){
                            printf("R\t");
                        }
                        if(tablero[ren][col]==2){
                            printf("X\t");
                        }  
                    }
                    printf("\n");
                } 
             break;
            case 6:
            exit(0);
        }
    }
    return 0;
}