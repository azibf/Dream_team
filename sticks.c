#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int hard_level = 0;
char chhard_level = 0;
int big_counter = 0;
int end_game = 0;
int time_seed;
char chplayers_num = '0';
int players_num = 0;
int sticks_counter;



void cleaning() // очистка экрана
{
    system("@cls||clear");
}


int human_step() // обработка хода человека
{
    char a;
    printf("Enter number from 1 to 3:");
    scanf(" %c", &a);
    while ((a != '1') && (a != '2') && (a != '3'))
    {
        printf("Incorrect number of sticks! Enter number from 1 to 3:");
        scanf(" %c", &a);
        printf("%c", a);
    }
    return a - '0';
}

int computer_step() // обработка хода компьютера
{
    int a;
    if (sticks_counter < 4 && sticks_counter > 1) a = sticks_counter - 1;
    else if (sticks_counter == 1) a = 1;
    else
    {
        if (hard_level == 1) a = 1 + rand() % 3; // если выбран первый уровень сложности, то ходы генерируются рандомно
        else // если выбран второй уровень сложности, то компьютер старается свети к ситуации, когда остается 4 спички
        {
            a = sticks_counter % 4;
            if (a == 0) a = 2;
        }
    }
    return a;
}


void draw_sticks()
{
    printf("There are %d sticks now\n", sticks_counter);
    for (int i = 0; i < sticks_counter; ++i) printf("|");
    printf("\n");
}


int one_player_mode()
{
    int result = 0;
    int step;
    step = human_step();
    sticks_counter -= step;
    draw_sticks();
    if (sticks_counter <= 0) return 2;
    step = computer_step();
    sticks_counter -= step;
    printf("I took %d stick(s)\n", step);
    draw_sticks();
    if (sticks_counter <= 0) return 1;
    return 0;
}


int two_players_mode()
{
    int result = 0;
    int step;
    printf("Player 1\n");
    step = human_step();
    sticks_counter -= step;
    draw_sticks();
    if (sticks_counter <= 0) return 2;
    printf("Player 2\n");
    step = human_step();
    sticks_counter -= step;
    draw_sticks();
    if (sticks_counter <= 0) return 1;
    return 0;
}


void start()
{
    ++big_counter;
    time_seed = time(NULL);
    srand(time_seed);
    end_game = 0;
    printf("Enter quantity of sticks > 0, if entered number <= 0, quantity will generate\n");
    scanf("%d", &sticks_counter);
    if (sticks_counter <= 0)
    {
        sticks_counter = 1 + (rand() % 20);
        printf("Quantity of sticks: %d\n", sticks_counter);
    }
    printf("Enter quantity of players\n1 player - 1, 2 players - 2\n");
    scanf(" %c", &chplayers_num);
    while((chplayers_num != '1') && (chplayers_num != '2'))
    {
        printf("Wrong quantity of players\n1 player - 1, 2 players - 2\n");
        scanf(" %c", &chplayers_num);
    }
    players_num = chplayers_num - '0';
    if (players_num == 1)
    {
        printf("Enter 1 to play simple game and 2 to hard\n");
        scanf(" %c", &chhard_level);
        while((chhard_level != '1') && (chhard_level != '2'))
        {
            printf("Wrong hard level!\n simple - 1, hard - 2\n");
            scanf(" %c", &chhard_level);
        }
        hard_level = chhard_level - '0';
        
    }
    cleaning();
    printf("BIG GAME: %d\n", big_counter);
}



int main()
{
    int result;
    printf("Hello!\nI want to play with you...\n...\n");
    printf("Sticks!\n");
    printf("(I know, that it is modified nim)\n");
    int q = 1;
    while (q != 0)
    {
        start();
        while (end_game == 0)
            {
                if (players_num == 1) end_game = one_player_mode();
                else end_game = two_players_mode();
                printf("Tap Enter to continue");
                getch();
                cleaning();
            }
        switch(end_game * players_num)
        {
            case 1: {printf("You won!\n"); break;}
            case 4: {printf("Player 2 won\n"); break;}
            default:
            {
                if (players_num == 1) printf("You lost!\n");
                else printf("Player 1 won!\n");
                break;
            }
        }
        printf("Enter 0 to stop and other number continue\n");
        scanf("%d", &q);
    }
}
