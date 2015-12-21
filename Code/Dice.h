
#include<ctype.h>
#include<cstdio>
#include<cmath>
#include<cstdlib>

int i,j,cash=100;
void wheel();
void game(int r);
void game_over();
int suit_bet();
int cash_bet();
int roll_wheel();
int roll_dice();
void wheel_count(int c,int h,int s);
void dice_count(int d,int h);

int w[9][9]={
    {32,32,32,32,2,32,32,32,32},
    {32,32,32,3,5,4,32,32,32},
    {32,32,5,4,3,6,5,32,32},
    {32,4,3,6,5,3,4,6,32},
    {2,6,5,4,15,5,3,6,2},
    {32,3,6,3,4,5,4,3,32},
    {32,32,5,6,3,4,5,32,32},
    {32,32,32,4,6,6,32,32,32},
    {32,32,32,32,2,32,32,32,32}
};

void playDice(){
    int round;
    char e;
    //game intro
    printf("\t\t\tWelcome to Roullette\n\n");
    //game instruction
    printf("Game Instructions:\n\n");
    printf("Diamond(d)=%c  Hearts(h)=%c  Clubs(c)=%c  Spades(s)=%c Jack(j)=%c  Bull's Eye=%c \n",4,3,5,6,2,15);

    printf("\n-The game starts with $100 \n-You chooses how many rounds to play \n-Then bet with cash on Suits,Jack and Null spaces of the wheel on which the dice will hit \n-A dice is thrown \n-If the dice hits the betting suit then you earn the betting cash.\n");
    printf("-If the dice hits suits other than the betting one then you lose $10\n");
    printf("-If it hits any of the Null spaces which is not bet then you lose bet cash \n");
    printf("-If it hits the Jack which is bet then you earn the beting cash + $100 otherwise you earn only the bet cash \n");
    printf("-Your cash is doubled if you hit the Bull's Eye \n");
    printf("\n\n");

    printf("Press Enter to Start Game");
    scanf("%c",&e);
    if(e=='\n'){
    printf("\nThe Roullette Wheel: \n\n");
    wheel();
    printf("\n\nYour Cash: $%d",cash);
    printf("\n\nHow many rounds you want to play: ");
    scanf("%d",&round);
    printf("\n\nYour Cash : $%d \n",cash);
    game(round);
    printf("\n\n");
    printf("\t %d rounds completed!! \n\n\tYou Earned Total $%d !!\n\n",round,cash);

    }
    else{
        printf("\nSorry!!\nYou Entered The Wrong Key!!\n");
    }
}

//game on
void game(int r){
    int count;
    for(count=1;count<=r;count++){

    int suit,ca,hit,dice;
    fflush(stdin);
    suit=suit_bet();
    ca=cash_bet();
    hit=roll_wheel();
    dice=roll_dice();
    wheel_count(ca,hit,suit);
    dice_count(dice,hit);
    printf("\n");
    wheel();

printf("\n\nCash: $%d \nSuit Bet: %c  \nCash Bet: $%d  \nWheel Hit: %c  \nDice: %d\n\n\n",cash,suit,ca,hit,dice);
    }
}

//show wheel
void wheel(){
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%c  ",w[i][j]);
        }
        printf("\n");
    }
}

//betting on suit
int suit_bet(){
    char s;
    int k;
    printf("Suit Bet: ");
    s=getchar();
    s=tolower(s);

    switch(s){
        case 'h':
            k=3;
            break;
        case 'd':
            k=4;
            break;
        case 'c':
            k=5;
            break;
        case 's':
            k=6;
            break;
        case 'j':
            k=2;
            break;
        case 'n':
            k=32;
            break;
        default:
            k=0;
    }
    return k;
}

//betting on cash
int cash_bet(){
    int c;
    printf("Cash Bet: $");
    scanf("%d",&c);

   return c;
}

//rolling the wheel
int roll_wheel(){
     float m,n;
     int wh1,wh2,res;
     m=rand()/32768.0;
     n=rand()/32768.0;
     wh1=(int) (m*9);
     wh2=(int) (n*9);
     res=w[wh1][wh2];
     w[wh1][wh2]=249;
     return res;
}

//rolling the dice
int roll_dice(){
    float d;
    int res;
    d=rand()/32768.0;
    res=(int) (d*6)+1;
    return res;
}

//cash update form wheel hit
void wheel_count(int c,int h,int s){
    if(h==s){
        if(h==2){
            cash=cash+c+100;
        }else{
            cash=cash+c;
        }
    }
    else if(h==3 || h==4 || h==5 || h==6){
        cash=cash-10;
    }
    else if(h==32){
        cash=cash-c;
    }
    else if(h==2){
        cash=cash+c;
    }
    if(s==2 && h!=2){
        cash=cash-50;
    }
}

//cash update from dice throw
void dice_count(int d,int h){

    if(h==3 || h==4 || h==5 || h==6){
        if(d==6){
            cash=cash+20;
        }
    }
    else if(h==15){
            cash=2*cash;
        }
    else if(h==249){
        if(d==6){
            cash=cash+20;
        }
    }
}

//game end/over

