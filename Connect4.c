#include <stdio.h>

int main()
{   
    printf("Iniciando");
    int gam[6][7], i, j, c, a;
    int on = 100;
    char p = 1;
    char v1[] = "O vencedor foi o jogador 1!\n";
    char v2[] = "O jogador 2 venceu o jogo!\n";
    for(i=0;i<6;i++){
        for(j=0;j<7;j++){
            gam[i][j] = 0;
        }
    }

    void show(){
            printf("\n");
            for(i=0;i<6;i++){
                printf("\n");
                for(j=0;j<7;j++){
                    if(j==0) printf("|");
                    printf(" %d |", gam[i][j]);
                 }
            }
            printf("\n----------------------------");
            printf("\n| 1 | 2 | 3 | 4 | 5 | 6 | 7 |");
            printf("\n");
        }
    int get_input(){
            printf("\nEscolha coluna PLAYER %d ", p);
            scanf("%d", &c);
            //printf("\nEscolheu a coluna %d", c);
            c = c-1;
        }
    void changep(){
            if(p==1){
              p = 2;
              return;
            }
            if(p==2){
              p = 1;
              return;
            }
        }
    int check_if_can(){
            if((c>=0)&&(c<7)){
                for(i=6;i>=0;i--){
                        if(gam[i][c] == 0){
                            //printf("\nConseguiu jogar na coluna %d na linha %d", c, i+1);
                            return i+1;
                        }
                    }
            }
            return 0;
        }
    void check(){
            a = check_if_can();
        if (a != 0){
            //printf("\nA linha %d foi jogada pelo jogador %d", a, p);
            gam[a-1][c] = p;
            changep();
        }
        else printf("\nimpossible, jogue outra coluna\n");
        }
    void checkwinner(){
            int aa = 0;
            int bb = 0;
            int cc = 0;
            void checkhor(){
                for(i=5;i>=0;i--){
                    for(j=6;j>=0;j--){
                        if(gam[i][j] == 0){
                            aa = 0;
                        }
                        if(gam[i][j] == 1){
                            if(aa<0) aa=0;
                            aa += 1;
                            if(aa>=4){
                                on = 200;
                                show();
                                printf("\n%s", v1);
                                return;
                              }
                        }
                        if(gam[i][j] == 2){
                            if(aa>0) aa=0;
                            aa -= 1;
                            if(aa<=-4){
                                on = 200;
                                 show();
                                 printf("\n%s", v2);
                                 return;
                                 }
                             }
                    }
                }
            }
            void checkver(){
                for(i=6;i>=0;i--){
                    for(j=5;j>=0;j--){
                        if(gam[j][i] == 0){
                            bb = 0;
                        }
                        if(gam[j][i] == 1){
                            if(bb<0) bb=0;
                            bb += 1;
                            if(bb>=4){
                                on = 200;
                                show();
                                printf("\n%s", v1);
                                return;
                              }
                        }
                        if(gam[j][i] == 2){
                            if(bb>0) bb=0;
                            bb -= 1;
                            if(bb<=-4){
                                on = 200;
                                 show();
                                 printf("\n%s", v2);
                                 return;
                                 }
                             }
                    }
                }
            }
            void checkdia(){
                for(int l = 0;l<=4;l++){
                    for(int i=5;i>=3;i--){ //Esquerda para Direita
                        int j = i;
                        int jj = l;
                        int cc=0;
                        for(int k=0;k<4;k++){
                            if(gam[j][jj] == 0){
                                    cc = 0;
                                }
                            if(gam[j][jj] == 1){
                                if(cc<0) cc=0;
                                cc += 1;
                                if(cc>=4){
                                    on = 200;
                                    show();
                                    printf("\n%s", v1);
                                    return;
                                    }
                                }
                            if(gam[j][jj] == 2){
                                if(cc>0) cc=0;
                                cc -= 1;
                                if(cc<=-4){
                                    on = 200;
                                    show();
                                    printf("\n%s", v2);
                                    return;
                                    }
                            }
                            j -= 1;
                            jj += 1;
                        }
                    }

                }
                for(int l = 6;l>=3;l--){
                    for(int i=5;i>=3;i--){ //Direita para esquerda
                        int j = i;
                        int jj = l;
                        int cc=0;
                        for(int k=0;k<4;k++){
                            if(gam[j][jj] == 0){
                                cc = 0;
                            }
                            if(gam[j][jj] == 1){
                                if(cc<0) cc=0;
                                cc += 1;
                                if(cc>=4){
                                    on = 200;
                                    show();
                                    printf("\n%s", v1);
                                    return;
                                    }
                                }
                            if(gam[j][jj] == 2){
                                if(cc>0) cc=0;
                                cc -= 1;
                                if(cc<=-4){
                                    on = 200;
                                    show();
                                    printf("\n%s", v2);
                                    return;
                                    }
                            }
                            j -= 1;
                            jj -= 1;
                        }
                    }

                }
            }
            void empate(){
                int emp = 1;
                for(i=0;i<6;i++){
                    for(j=0;j<7;j++){
                        if(gam[i][j] == 0){
                            emp = 0;
                            break;
                        }
                    }
                }
                if(emp==1){
                    on = 200;
                    show();
                    printf("\nO jogo acabou em empate!");
                    return;
                }
            }
            checkhor();
            checkver();
            checkdia();
            empate();
        }

    while (on != 200){
        printf("\nNew Round, player %d's turn!", p);

        show();

        get_input();

        check();

        checkwinner();

    }
    return 0;
}
