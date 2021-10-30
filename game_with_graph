#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int counter_win, counter_lose, counter_for_draw, counter;
int last_winner;
int end_game = 0;
int time_seed;
// last_winner = 1 - human won
// last_winner = -1 - computer won


void write_opponents(int a) // вывод предмета, соотвествующего числу
{
    switch((char)a)
    {
        case(1) :
        {
            printf("scissors\n");
            printf("                 @@@@@@@@@@@@\n               @@@@@@@@@@@@@@@@\n              @@@@@        @@@@@                        @@@@@@@@@@\n             @@@@@          @@@@@                   @@@@@@@@@@@@@@@             \n             @@@@@@        &@@@@@               /@@@@@@@@@@@@@@                 \n              @@@@@@@    @@@@@@@             @@@@@@@@@@@@@@&                    \n                @@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@                        \n                    &@@@@&  @@@@@@@@@@@@@@@@@@@@@@@@.                           \n                                @@@@@@@@@@@@@@@@@                               \n                                   @@@@@@@@@@&                                  \n                               %@@@@@@@@@@@@@@@@@                               \n                   .@@@@@@. @@@@@@@@@@@@@@@@@@@@@@@@@                           \n                @@@@@@@@@@@@@@@@@@%       @@@@@@@@@@@@@@                        \n              @@@@@@@    @@@@@@@             @@@@@@@@@@@@@@@                    \n             @@@@@@        /@@@@@                @@@@@@@@@@@@@@,                \n             @@@@@          @@@@@                   @@@@@@@@@@@@@@@             \n              @@@@@,       @@@@@                        @@@@@@@@@@              \n               @@@@@@@@@@@@@@@@                                                 \n                 (@@@@@@@@@@#");
            break;
        }
        case(2) :
        {
            printf("paper\n");
            printf("                     &&&&&&&@%      .                                       .   \n                    &&&   ,@&&&&&&&&&&&&&&@.                                    \n                    &&*                 %@&&&&&&&&&&&&                          \n                   %&&                             &&&  &@&&@                   \n                   &&@                    ,&&&&&&&&&&&&&&&&&&                   \n                   &&        /@&&&&&&&&&&&&&@#             &&(                  \n                  &&&      /&&&@/                          &&&                  \n                  &&        &&/                             &&                  \n                 &&&        @&&                  ,@&&&&     &&@                 \n              . ,&&          &&        @&&&&@/        .     %&&                 \n                &&@          &&@                   .&&&&     &&@                \n               &&&           (&&        /@&&&&@(             &&&                \n              @&&        .    &&@                             &&@.              \n             @&&              (&&               (@             &&               \n            @&&                &&&    &&&&&@                   @&&              \n           &&&                  &&                              &&&             \n         ,&&&&@*                @&&  .      #@&                  &&&         .  \n            (@&&&&&&&&&&&&&@#    &&&                              &&&     .     \n                         *@&&&&&&&&&@                              &&&   .      \n                                   &&@                              @&&.        \n                                    &&&                  &&&&&&&&&&&&&&@        \n                                     &&&   ,&@&&&&&&&&&&&&&@,                   \n                                      &&&&&&&@%");
            break;
        }
        case(3) :
        {
            printf("rock\n");
            printf("                                                #@&                            \n                                    /@@@@@@@@@@@@@@@@@@@@,                      \n                       *%@@@@@@@@@@@@@#*      %@@%  ,@@@@@@@@@.                 \n                  ,@@@@@@@#                 @@@.         (@@@@@@@@@.            \n                @@@@@,                   *@@@                 %@@@@@@@@%        \n             *@@@@                     @@@,                       *@@@@@@       \n           %@@@                      @@*                             @@@@@      \n         &@@@                                                        *@@@@%     \n       @@@@                    @@*                                 (  &@@@@/    \n     &@@@                   &@@@@                                .@@   @@@@@    \n   %@@@.        .#&@@@@@@@@@@@@@@@@@&/                           @@@    @@@@@   \n .@@@@@@@@@@@@@@@@@*            .%@@@@@@@@@@@@@@@#.             /@@      @@@@@  \n%@@@@@@@@.                                 .(@@@@@@@@@@@@@@@@@@@@@@      .@@@@@ \n @@@@@@.                                                ,@@@. @@@@@       @@@@@#\n  (@@@@@                                           (@@@#        @@@       &@@@@@\n   @@@@@&                                    &@@@@.             @@@      @@@@# \n      @@@@@@                             @@@@@%                  .@@@    @@@@   \n        @@@@@@*                      ,@@@@*                        @@@ (@@@.    \n          ,@@@@@@/                  @@@,                            *@@@@#      \n             /@@@@@@@             /@@@                              /@@@        \n                ,@@@@@@@.        *@@@                             .@@@          \n                    &@@@@@@%    *@@@                         ,%@@@@@*           \n                       .@@@@@@@@@@@@   ,/%&&@@@@@@@@@@@@@@@@@@@@#*              \n                           ,@@@@@@@@@@@@@@@@@#*.    ");
            break;
        }
        case(4) :
        {
            printf("lizard\n");
            printf("                                                         ./                     \n                                                        .@  .&/                 \n                                                        @@@@(        ,*(((((/,  \n                                                    @@@@@@@%,     @@@@/ .@@@@@@.\n                                                   @@@@@&      *@@@@@@@@@@@@@@, \n                                                   .@@@@@@.&@@@@@@@@@@@@@  @%   \n                                                   .%@@@@@@@@@@@@@@@@@@@@@/     \n                                               (@@@@@@@@@@@@@@@@@@(             \n                                            @@@@@@@@@@@@@@@@@@@                 \n                                         %@@@@@@@@@@@@@@@@@@@@@@                \n                                       %@@@@@@@@@@@@@@@,    @@@@                \n                                      @@@@@@@@@@@@@@*      @@@@  %*             \n                        .            @@@@@@@@@@@@@        ,@@@@@                \n                         @.  *@@@@@@@@@@@@@@@@@%            @@@&*               \n                     @@@@@@@@@@@@@@@@@@@@@@@@@      @     #    (@@              \n                        @@@@.     .@@@@@@@@@@@     /@@@@%                       \n                     %.           &@@@@@@@@@@@@@@@@@@@@*                        \n                                 ,@@@@@@@@  (@@@@@(.                            \n                                 @@@@@@@&                                       \n                                @@@@@@@,                                        \n                               @@@@@@@                                          \n                             @@@@@@@                                            \n                           @@@@@@@*                                             \n                        &@@@@@@@                                                \n                   ,&@@@@@@@&                                                   \n            *@@@@@@@@@@%                                                        \n        %@@@@*                                                                  \n     ,@@.                                                                       \n   .@,                                                                          \n  #(                                                                            \n ,,                                                                             \n .      ");
            break;
        }
        case(5) :
        {
            printf("Spock\n");
            printf("                                    .@@  @*                                     \n                          @@/       @@@ @@@                                     \n                          @@@       @@@ @@@                                     \n                        *# @@@      @@@ @@@                                     \n                        @@@ @@@     @@@*@@@#                                    \n                         @@*@@@@    @@@@@@@@                                    \n                         @@@ @@@%   @@@@@@@@                                    \n                          @@@@@@@@&@@@@@@@@@                                    \n                          @@@@@@@@@@@@@@@@@@       *@@@@@                       \n                           @&@@@@@@@@@@@&@&@      @@@@@                         \n                           @@@@@@@@@@@@@@@@@@ %@@@@@@@                          \n                           @@@@@@@@@@@@@@@@@@@@@@@@@                            \n                           @@@@@@@@@@@@@@@@@@@@@@@                              \n                            @@@@@@@@@@@@@@@@@@@@@                               \n                             @@@@@@@@@@@@@@@@@@                                 \n                              @@@@@@@@@@@@@@.                                   \n                              @@@@@@@@@@@@@  ");
            break;
        }
    }
}


void check_winners(int a) // вывод результата раунда
{
    time_seed = time(NULL);
    srand(time_seed);
    int b = rand() % 5 + 1;
    write_opponents(a); printf("\n vs \n"); write_opponents(b); printf("\n");
    if (a == b)
    {
        printf("Draw!\n");
        if (counter >= 5) last_winner = 0;
    }
    else if ((((a - b) + 5) % 5 % 2) == 0)
    {
        printf("You won!\n");
        if (counter < 5) ++counter_win;
        else
        {
            if (last_winner == 1) end_game = 1;
            else last_winner = 1;
        }
    }
    else
    {
        printf("You lose!\n");
        if (counter < 5) ++counter_lose;
        else
        {
            if (last_winner == -1) end_game = -1;
            else last_winner = -1;
        }
    }
}


void cleaning() // очистка экрана
{
    system("@cls||clear");
}


void remain_rules() // напоминаем правила
{
    printf("Scissors decapitate Scissors cuts paper,\npaper covers rock, rock crushes lizard,\nlizard poisons Spock, Spock smashes scissors,\nscissors decapitates lizard, lizard eats paper,\npaper disproves Spock, Spock vaporizes rock,\nand as it always has, rock crushes scissors.\n");
}


int main()
{
    int a;
    printf("Hello!\nI want to play with you...\n...\n");
    printf("Rock-scissors-paper-lizard-Spock!\n");
    while ((counter < 5 || (counter_win - counter_lose) == 0) && (end_game == 0))
    {
        printf("Round: %d\n", counter+1);
        if (counter < 5)
        {
            printf("Just a human vs The most beautiful and clever computer\n");
            printf("           %d : %d\n", counter_win, counter_lose);
        }
        else
        {
            printf("Determination of the winner in case of a draw\n");
        }
        printf("Enter 1 - scissors, 2 - paper, 3 - rock, 4 - lizard, 5 - Spock, other number - remind rules\n");
        scanf("%d", &a);
        while((a < 1) || (a > 5)){
            remain_rules();
            scanf("%d", &a);
        }
        check_winners(a);
        ++counter;
        printf("Tap Enter to continue");
        getch();
        cleaning();
    }
    if (end_game == 1 || counter_win > counter_lose) printf("YOU WON EVERYTHING!!!");
    else printf("YOU LOSE EVERYTHING!!!");
    getch();
}
