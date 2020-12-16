#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //thing for random generation
    _Bool item = 0; //if an item exists
    char map [9][9] =  //map
    {
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','X','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-'},
    };
    for (int yy = 0; yy < 9; yy++)//printing out the map
    {
        for (int xx = 0; xx < 9; xx++)
        {
            printf("%c", map[yy][xx]);
        }
        printf("\n");
    }
    printf("Welcome to bad snake. Use the arrow keys to move. \nPress Enter at anytime to quit.\nDo not touch the A.\n");//rouxxles kaarrd
    int score = 0; //score
    int rx,ry,sx,sy; //random coords
    int spikex [81] = {};//array that holds spike x coords
    int spikey [81] = {};//array that holds spike y coords
    int spikenum = 0; //number of spikes so we dont have to loop through the entire arrays
    int y = 4, x = 4; //player coords
    int in = 0; //input
    int quit = 0; //did they try and quit
    int state = 0; //differenciates between the game being played and the game being over
    while (state == 0) //playing state
    {
        while (1) //waiting for a valid input
        {
            quit = getch(); //cause arrows input a 0 first
            if (quit == 13) //enter
            {
                state = 1; //the game is over
                break;
            }
            in = getch();//the didnt want to quit clearly
            if (in == 75) //all this is just checking keycodes
            {
                map [y][x] = '-';
                //screen wrapping stuff
                if (x ==0)
                {
                    x = 8;
                }
                else
                {
                    x-=1;
                }
                map[y][x] = 'X'; //printing on screen. Same stuff below
                break;
            }
            else if (in == 72)
            {
                map [y][x] = '-';
                if (y ==0)
                {
                    y = 8;
                }
                else
                {
                    y-=1;
                }
                map[y][x] = 'X';
                break;
            }
            else if (in == 77)
            {
                map [y][x] = '-';
                if (x ==8)
                {
                    x = 0;
                }
                else
                {
                    x+=1;
                }
                map[y][x] = 'X';
                break;
            }
            else if (in == 80)
            {
                map [y][x] = '-';
                if (y ==8)
                {
                    y= 0;
                }
                else
                {
                    y+=1;
                }
                map[y][x] = 'X';
                break;
            }
            else if (quit == 13) //enter meaning they actually did want to quit
            {
                state = 1;
                break;
            }
        }
        if (y == ry && x == rx) //if they are on an item
        {
            item = 0;
            score+=50;
        }
        for (int i = 0; i < spikenum; i++)
        {
            if (y == spikey[i] && x == spikex[i])//if they are on a spike
            {
                state = 1;//end the game 
                printf("You lost with a score of %d", score); 
                break;
            }
        }
        if (state == 1)//ending the game
        {
            break;
        }
        if (item == 0)//if item is not there
        {
            rx = rand()%9;//random x coord
            ry = rand()%9;//random y coord
            while (map[ry][rx] == 'X' || map[ry][rx] == 'A') //if they chose the players location, we generate a new one
            {
                rx = rand()%9;
                ry = rand()%9;
            }
            map[ry][rx] = '0';//place item
            item = 1;
        }
        else if (item == 1)
        {
            if (score > 0)//everytime they have points, after every more they loose points as long as there is an item existing
            {
                score-=1;
            }
        }
        int chance = rand()%10;//1 in 10 chance to spawn spike
        if (chance == 0)
        {
            sx = rand()%9;//random x coord
            sy = rand()%9;//random y coord
            while (map[sy][sx] == 'X' || map[sy][sx] == '0' || map[sy][sx] == 'A')//making sure it spawns in the right spot
            {
                sx = rand()%9;
                sy = rand()%9;
            }
            map[sy][sx] = 'A';
            spikex [spikenum] = sx;
            spikey [spikenum] = sy;
            spikenum+=1;//increasing the numbers that exist so we check more.
        }
        in = 0;
        printf("\n\n\n\n\n\n\n\n\n\nScore: %d\n", score); //makes it so it doesnt look bad (jk it looks bad no matter what)
        for (int yy = 0; yy < 9; yy++)//printing map
        {
            for (int xx = 0; xx < 9; xx++)
            {
                printf("%c", map[yy][xx]);
            }
            printf("\n");
        }
    }
    return 0;//yay its over
}