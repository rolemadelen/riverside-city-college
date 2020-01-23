#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int WIDTH = 600;
const int HEIGHT = 600;

void dumbAI();

///////////////////////////////////////////////
//used in DumbAi vs Player
// generate random number 0 to 9
int randNum()
{
    return rand() % 9;
}

/////////////////////////////////////////////////////////////
/*
* draws four rectangle that represents the TICTACTOE grid.
*
* parameter is screen, location (x,y), width and height
*
* return type is void
*/
void drawTTT(SDL_Surface *screen,int x, int y, int w, int h)
{
    SDL_Rect wall ={x,y,w,h};
    SDL_FillRect(screen,&wall,SDL_MapRGB(screen->format,0x00,0x00,0x00));
}
/////////////////////////////////////////////////////////////
/*
* purpose of this function is to add image to the screen at
* desired location.
*
* parameter : screen, image, location(x,y)
*
* return type is void
*/
void drawImage(SDL_Surface *screen, SDL_Surface *image, int x, int y)
{
    SDL_Rect loc = {x,y};
    SDL_BlitSurface(image,NULL,screen,&loc);
}
////////////////////////////////////////////////////////////
/*
* purpose of this function is to determine whether grid
* is full or not, meaning a player can't place anymore O,X
*
* parameter : boolean array, size
*
* return type is boolean
*/
bool isFull(bool arr[], int size = 9)
{
    int chk = 0;
    for(int i = 0; i < size; i ++)
    {
        //if there's no more place to put in TICTACTOE
        if(arr[i] == 1)
        {
            chk ++;
        }

        if(chk == 9)
            return true;
    }
}
////////////////////////////////////////////////////////////////
/*
* purpose of this fucntion is to determine whether a player 'O'
* has a three consecutive 'O's : a row in ver, horizon, or diagonal
*
* parameter : boolean array of player 1
*
* return type is boolean
*/
bool winner_player1(bool O[])
{
     if(O[0]==1 && O[1]==1 && O[2]==1)
        return true;
    else if(O[3]==1 && O[4]==1 && O[5]==1)
        return true;
    else if(O[6]==1 && O[7]==1 && O[8]==1)
        return true;
    else if(O[0]==1 && O[3]==1 && O[6]==1)
        return true;
    else if(O[1]==1 && O[4]==1 && O[7]==1)
        return true;
    else if(O[2]==1 && O[5]==1 && O[8]==1)
        return true;
    else if(O[0]==1 && O[4]==1 && O[8]==1)
        return true;
    else if(O[2]==1 && O[4]==1 && O[6]==1)
        return true;
}
////////////////////////////////////////////////////////////////
/*
* purpose of this fucntion is to determine whether a player 'X'
* has a three consecutive 'X's : a row in ver, horizon, or diagonal
*
* parameter : boolean array of player 2
*
* return type is boolean
*/
bool winner_player2(bool X[])
{
    if(X[0]==1 && X[1]==1 && X[2]==1)
        return true;
    else if(X[3]==1 && X[4]==1 && X[5]==1)
        return true;
    else if(X[6]==1 && X[7]==1 && X[8]==1)
        return true;
    else if(X[0]==1 && X[3]==1 && X[6]==1)
        return true;
    else if(X[1]==1 && X[4]==1 && X[7]==1)
        return true;
    else if(X[2]==1 && X[5]==1 && X[8]==1)
        return true;
    else if(X[0]==1 && X[4]==1 && X[8]==1)
        return true;
    else if(X[2]==1 && X[4]==1 && X[6]==1)
        return true;
}
///////////////////////////////////////////////
int main(int argc, char** argv)
{
    //declare vars
    SDL_Surface *screen = NULL;
    SDL_Event event;
    SDL_Event restart;
    //game Vars
    SDL_Surface *start = NULL;
    SDL_Surface *gameover = NULL;
    SDL_Surface *player = NULL;
    SDL_Surface *winnerO = NULL;
    SDL_Surface *winnerX = NULL;
    SDL_Surface *O = NULL;
    SDL_Surface *X = NULL;

    //switch
    bool done = false;

    //used to determine the winner
    //place = determine if TIC TAC TOE board is full
    bool place[9] = {0,0,0,
                    0,0,0,
                    0,0,0};
    //to determine winner
    bool placeO[9] = {0,0,0,
                      0,0,0,
                      0,0,0};
    //to determine winner
     bool placeX[9] = {0,0,0,
                      0,0,0,
                      0,0,0};

    int cnt = 0;
    //moues location
    int x = 0;
    int y = 0;
    int xClick = 0;
    int yClick = 0;
    //init every sub-systems
    SDL_Init(SDL_INIT_EVERYTHING);

    //create a screen 600x400
    screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_ANYFORMAT);

    //load player 'O' and 'X' image
    player = IMG_Load("./player/O.bmp");
    start = IMG_Load("./player/start.bmp");
    O = IMG_Load("./player/O.bmp");
    X = IMG_Load("./player/X.bmp");
    gameover = IMG_Load("./player/gameover.bmp");
    winnerO = IMG_Load("./player/winnero.bmp");
    winnerX = IMG_Load("./player/winnerx.bmp");

    //color keying color
    Uint32 magenta = SDL_MapRGB(screen->format,0xff,0x00,0xff);

	//start screen
	while(!done)
	{
		while(SDL_PollEvent(&event))
		{
            SDL_BlitSurface(start,NULL,screen,NULL);
			if(event.type == SDL_KEYDOWN)
			{
			//if press 1, DumbAI vs Player
				if(event.key.keysym.sym == SDLK_1)
				{
					dumbAI();
					return 0;
				}
				//if press 2, Player vs Player
				if(event.key.keysym.sym == SDLK_2)
				{
					done = true;
				}
				//if press ESC, exit.
				if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 0;
                }
			}
		}
		SDL_Flip(screen);
	}

	done = false;
    //start program
    while(!done)
    {
        //hide mouse cursor
        SDL_ShowCursor(0);

        //fill screen with white
        SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0xff,0xff,0xff));

        while(SDL_PollEvent(&event))
        {
			//event types
            switch(event.type)
            {
			//If user ex'ed out the window, exit.
            case SDL_QUIT:
                done = true;
                break;

			//get mouse motion
            case SDL_MOUSEMOTION:
                {
                    x = event.motion.x;
                    y = event.motion.y;
                }
                break;
				//mouse click event
            case SDL_MOUSEBUTTONDOWN:
                {
                    switch(event.button.button)
                    {
					//if left mouse is clicked at ......
                    case SDL_BUTTON_LEFT:
                        {
                            xClick = event.button.x;
                            yClick = event.button.y;

                            //first box
                            if(xClick <189 && yClick < 179)
                            {
								//if first box is empty place O or X
                                if(placeO[0] == 0 && placeX[0] == 0)
                                {
									//if cnt = 2 player 1 = O
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[0] = 1;
                                        place[0] = 1;
                                        cnt ++;
                                    }
									//else player 2 = X
                                    else
                                    {
                                        placeX[0] = 1;
                                        place[0] = 1;
                                        cnt ++;
                                    }
                                }
                                printf("FIRST BOX\n");
                            }
                            //second boy
                            else if(xClick > 210 && xClick <390 && yClick < 179)
                            {
                                if(placeO[1] == 0 && placeX[1] == 0)
                               {
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[1] = 1;
                                        place[1] = 1;
                                        cnt ++;
                                    }
                                    else
                                    {
                                        placeX[1] = 1;
                                        place[1] = 1;
                                        cnt ++;
                                    }
                               }
                                printf("SECOND BOX\n");
                            }
                            //third box
                            else if(xClick > 410 && yClick < 179)
                            {
                                if(placeO[2] == 0 && placeX[2] == 0)
                                {
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[2] = 1;
                                        place[2] = 1;
                                        cnt ++;
                                    }
                                    else
                                    {
                                        placeX[2] = 1;
                                        place[2] = 1;
                                        cnt ++;
                                    }
                                }
                                printf("THIRD BOX\n");
                            }
                            //fourth box
                            else if(xClick <189 && yClick > 199 && yClick < 379)
                            {
                                if(placeO[3] == 0 && placeX[3] == 0)
                                {
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[3] = 1;
                                        place[3] = 1;
                                        cnt ++;
                                    }
                                    else
                                    {
                                        placeX[3] = 1;
                                        place[3] = 1;
                                        cnt ++;
                                    }
                                }
                                printf("FOURTH BOX\n");
                            }
                            //fifth box
                            else if(xClick > 210 && xClick <390 && yClick > 199 && yClick < 379)
                            {
                                if(placeO[4] == 0 && placeX[4] == 0)
                                {
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[4] = 1;
                                        place[4] = 1;
                                        cnt ++;
                                    }
                                    else
                                    {
                                        placeX[4] = 1;
                                        place[4] = 1;
                                        cnt ++;
                                    }
                                }

                                printf("FIFTH BOX\n");
                            }
                            //sixth box
                            else if(xClick > 410 && yClick >200 && yClick < 381)
                            {
                                if(placeO[5] == 0 && placeX[5] == 0)
                                {
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[5] = 1;
                                        place[5] = 1;
                                        cnt ++;
                                    }
                                    else
                                    {
                                        placeX[5] = 1;
                                        place[5] = 1;
                                        cnt ++;
                                    }
                                }
                                printf("SIXTH BOX\n");
                            }
                            //seventh box
                            else if(xClick <189 && yClick > 399)
                            {
                                if(placeO[6] == 0 && placeX[6] == 0)
                                {
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[6] = 1;
                                        place[6] = 1;
                                        cnt ++;
                                    }
                                    else
                                    {
                                        placeX[6] = 1;
                                        place[6] = 1;
                                        cnt ++;
                                    }
                                }
                                printf("SEVENTH BOX\n");
                            }
                            //eigth box
                            else if(xClick > 210 && xClick <390 && yClick > 401 && yClick < 581)
                            {
                                if(placeO[7] == 0 && placeX[7] == 0)
                                {
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[7] = 1;
                                        place[7] = 1;
                                        cnt ++;
                                    }
                                    else
                                    {
                                        placeX[7] = 1;
                                        place[7] = 1;
                                        cnt ++;
                                    }
                                }
                                printf("EIGHT BOX\n");
                            }
                            //nineth box
                            else if(xClick > 410 && yClick > 399 && yClick < 580)
                            {
                                if(placeO[8] == 0 && placeX[8] == 0)
                                {
                                    if(cnt % 2 == 0)
                                    {
                                        placeO[8] = 1;
                                        place[8] = 1;
                                        cnt ++;
                                    }
                                    else
                                    {
                                        placeX[8] = 1;
                                        place[8] = 1;
                                        cnt ++;
                                    }
                                }
                                printf("NINETH BOX\n");
                            }


                            player = IMG_Load("./player/X.bmp");

                            if(cnt % 2 == 0)
                                 player = IMG_Load("./player/O.bmp");
                        }
                        break;
                    }
                }
            }
        }

        //horizontal TicTacToe line
        drawTTT(screen,0,0,WIDTH,20);
        drawTTT(screen,0,180,WIDTH,20);
        drawTTT(screen,0,380,WIDTH,20);
        drawTTT(screen,0,580,WIDTH,20);
        //vetical TicTacToe line
        drawTTT(screen,0,0,20,HEIGHT);
        drawTTT(screen,190,0,20,HEIGHT);
        drawTTT(screen,390,0,20,HEIGHT);
        drawTTT(screen,580,0,20,HEIGHT);

        //Mouse Cursor, draw O and X to screen
        drawImage(screen,player,x,y);

        //Draw O at the grid if user selects.
        if(placeO[0] == 1)
            drawImage(screen,O,40,20);
        if(placeO[1] == 1)
            drawImage(screen,O,240,30);
        if(placeO[2] == 1)
            drawImage(screen,O,440,30);
        if(placeO[3] == 1)
            drawImage(screen,O,40,210);
        if(placeO[4] == 1)
            drawImage(screen,O,240,210);
        if(placeO[5] == 1)
            drawImage(screen,O,440,210);
        if(placeO[6] == 1)
            drawImage(screen,O,40,420);
        if(placeO[7] == 1)
            drawImage(screen,O,240,420);
        if(placeO[8] == 1)
            drawImage(screen,O,440,420);

        //Draw X at the grid if player selects.
       if(placeX[0] == 1)
            drawImage(screen,X,40,20);
        if(placeX[1] == 1)
            drawImage(screen,X,240,30);
        if(placeX[2] == 1)
            drawImage(screen,X,430,30);
        if(placeX[3] == 1)
            drawImage(screen,X,40,210);
        if(placeX[4] == 1)
            drawImage(screen,X,230,210);
        if(placeX[5] == 1)
            drawImage(screen,X,430,210);
        if(placeX[6] == 1)
            drawImage(screen,X,40,410);
        if(placeX[7] == 1)
            drawImage(screen,X,230,410);
        if(placeX[8] == 1)
            drawImage(screen,X,430,410);

         //return true if player 1 is the winner
       if(winner_player1(placeO) == true)
       {
           //plater 1 is the winner
           drawImage(screen,winnerO,0,0);
            SDL_Flip(screen);
			//try again?
           while(SDL_PollEvent(&restart))
           {
               switch(restart.type)
               {
                   case SDL_KEYDOWN:
                    {
						// if pressed Y, try again.
                          if(restart.key.keysym.sym == SDLK_y)
                        {
                            cnt = 0;
                            for(int i = 0; i < 9; i ++)
                            {
                                place[i] = 0;
                                placeO[i] = 0;
                                placeX[i] = 0;
                            }
							//player 1 always start first
                            player = IMG_Load("./player/O.bmp");
                        }
						//if n is pressed, QUIT
                        else if(restart.key.keysym.sym == SDLK_n)
                            done = true;
                    }

                }
                   break;
           }
        }
       else if(winner_player2(placeX)== true)
       {
           //player 2 is the winner
           //plater 1 is the winner
           drawImage(screen,winnerX,0,0);
            SDL_Flip(screen);
			//try again?
           while(SDL_PollEvent(&restart))
           {
               switch(restart.type)
               {
                   case SDL_KEYDOWN:
                    {
						//if y is pressed, try again
                        if(restart.key.keysym.sym == SDLK_y)
                        {
                            cnt = 0;
                            for(int i = 0; i < 9; i ++)
                            {
                                place[i] = 0;
                                placeO[i] = 0;
                                placeX[i] = 0;
                            }
							//player 1 starts first
                            player = IMG_Load("./player/O.bmp");
                        }
						//else QUIT
                        else if(restart.key.keysym.sym == SDLK_n)
                            done = true;
                    }
                   break;
               }
           }
       }

		//color keying
       SDL_SetColorKey(player,SDL_SRCCOLORKEY,magenta);
       SDL_SetColorKey(O,SDL_SRCCOLORKEY,magenta);
       SDL_SetColorKey(X,SDL_SRCCOLORKEY,magenta);

        //start the game again?
		//this is for when nobody won the game
        if(isFull(place) == true )
        {
            //game over
            drawImage(screen,gameover,0,0);

            if(SDL_PollEvent(&event))
            {
                if(event.type == SDL_KEYDOWN)
                {
                    //if yes start over
                    if(event.key.keysym.sym == SDLK_y)
                    {
                        cnt = 0;
                        for(int i = 0; i < 9; i++)
                        {
                            place[i] = 0;
                            placeO[i] = 0;
                            placeX[i] = 0;
                        }
                         player = IMG_Load("./player/O.bmp");
                    }
                    //if no quit
                    else if(event.key.keysym.sym == SDLK_n)
                    {
                        done = true;
                    }

                }
            }
        }
        SDL_Flip(screen);
    }

    SDL_FreeSurface(screen);
    SDL_FreeSurface(start);
    SDL_FreeSurface(winnerO);
    SDL_FreeSurface(winnerX);
    SDL_FreeSurface(gameover);
    SDL_FreeSurface(player);

    SDL_Quit();

    return 0;
}

/////////////////////////////////
//DUMB AI VS PLAYER
//DUMB AI VS PLAYER
//DUMB AI VS PLAYER
//DUMB AI VS PLAYER
/////////////////////////////////
void dumbAI()
{
	srand((unsigned)time(NULL));

    //declare vars
    SDL_Surface *screen = NULL;
    SDL_Event event;
    SDL_Event restart;
    //game Vars
    SDL_Surface *gameover = NULL;
    SDL_Surface *player = NULL;
    SDL_Surface *winnerO = NULL;
    SDL_Surface *winnerX = NULL;
    SDL_Surface *O = NULL;
    SDL_Surface *X = NULL;

    //switch
    bool done = false;

    //used to determine the winner
    //place = determine if TIC TAC TOE board is full
    bool place[9] = {0,0,0,
                    0,0,0,
                    0,0,0};
    //to determine winner
    bool placeO[9] = {0,0,0,
                      0,0,0,
                      0,0,0};
    //to determine winner
     bool placeX[9] = {0,0,0,
                      0,0,0,
                      0,0,0};

	int dumbAI = randNum();

    int cnt = 0;
    //moues location
    int x = 0;
    int y = 0;
    int xClick = 0;
    int yClick = 0;
    //init every sub-systems
    SDL_Init(SDL_INIT_EVERYTHING);

    //create a screen 600x400
    screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_ANYFORMAT);

    //load player 'O' and 'X' image
    player = IMG_Load("./player/O.bmp");
    O = IMG_Load("./player/O.bmp");
    X = IMG_Load("./player/X.bmp");
    gameover = IMG_Load("./player/gameover.bmp");
    winnerO = IMG_Load("./player/winnero.bmp");
    winnerX = IMG_Load("./player/winnerx.bmp");

    //color keying color
    Uint32 magenta = SDL_MapRGB(screen->format,0xff,0x00,0xff);

    //start program
    while(!done)
    {
        //hide mouse cursor
        SDL_ShowCursor(0);

        //fill screen with white
        SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0xff,0xff,0xff));
        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
            case SDL_QUIT:
                done = true;
                break;

			//get mouse motion to click
            case SDL_MOUSEMOTION:
                {
                    x = event.motion.x;
                    y = event.motion.y;
                }
                break;

				//if mouse is clicked
            case SDL_MOUSEBUTTONDOWN:
                {
                    switch(event.button.button)
                    {
					//if left mouse is clicekd at ......
                    case SDL_BUTTON_LEFT:
                        {
                            xClick = event.button.x;
                            yClick = event.button.y;

                            //first box
                            if(xClick <189 && yClick < 179)
                            {
								//make sure first box is empty
                                if(placeO[0] == 0 && placeX[0] == 0)
                                {
                                     placeO[0] = 1;
                                    place[0] = 1;

									//pafter players selection
									//dumpAI pick a box
                                   do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                    place[dumbAI] = 1;

                                }
                                printf("FIRST BOX\n");
                            }
                            //second boy
                            else if(xClick > 210 && xClick <390 && yClick < 179)
                            {
                                if(placeO[1] == 0 && placeX[1] == 0)
                               {
                                    placeO[1] = 1;
                                    place[1] = 1;
                                    do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                      place[dumbAI] = 1;

								}
                                printf("SECOND BOX\n");
                            }
                            //third box
                            else if(xClick > 410 && yClick < 179)
                            {
                                if(placeO[2] == 0 && placeX[2] == 0)
                                {
                                    placeO[2] = 1;
                                    place[2] = 1;
                                    do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                      place[dumbAI] = 1;

                                }
                                printf("THIRD BOX\n");
                            }
                            //fourth box
                            else if(xClick <189 && yClick > 199 && yClick < 379)
                            {
                                if(placeO[3] == 0 && placeX[3] == 0)
                                {
                                    placeO[3] = 1;
                                    place[3] = 1;
                                    do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                      place[dumbAI] = 1;

                                }
                                printf("FOURTH BOX\n");
                            }
                            //fifth box
                            else if(xClick > 210 && xClick <390 && yClick > 199 && yClick < 379)
                            {
                                if(placeO[4] == 0 && placeX[4] == 0)
                                {
                                    placeO[4] = 1;
                                    place[4] = 1;
                                    do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                      place[dumbAI] = 1;

                                }

                                printf("FIFTH BOX\n");
                            }
                            //sixth box
                            else if(xClick > 410 && yClick >200 && yClick < 381)
                            {
                                if(placeO[5] == 0 && placeX[5] == 0)
                                {
                                    placeO[5] = 1;
                                    place[5] = 1;
                                    do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                      place[dumbAI] = 1;

                                }
                                printf("SIXTH BOX\n");
                            }
                            //seventh box
                            else if(xClick <189 && yClick > 399)
                            {
                                if(placeO[6] == 0 && placeX[6] == 0)
                                {
                                    placeO[6] = 1;
                                    place[6] = 1;
                                    do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                      place[dumbAI] = 1;

                                }
                                printf("SEVENTH BOX\n");
                            }
                            //eigth box
                            else if(xClick > 210 && xClick <390 && yClick > 401 && yClick < 581)
                            {
                                if(placeO[7] == 0 && placeX[7] == 0)
                                {
                                    placeO[7] = 1;
                                    place[7] = 1;
                                    do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                      place[dumbAI] = 1;

								}
                                printf("EIGHT BOX\n");
                            }
                            //nineth box
                            else if(xClick > 410 && yClick > 399 && yClick < 580)
                            {
                                if(placeO[8] == 0 && placeX[8] == 0)
                                {
                                    placeO[8] = 1;
                                    place[8] = 1;
                                    do
                                    {
                                        dumbAI = randNum();
                                    }while(placeO[dumbAI] == 1);
                                    placeX[dumbAI] = 1;
                                      place[dumbAI] = 1;

                                }
                                printf("NINETH BOX\n");
                            }

                        }
                        break;
                    }
                }
            }
        }

        //horizontal TicTacToe line
        drawTTT(screen,0,0,WIDTH,20);
        drawTTT(screen,0,180,WIDTH,20);
        drawTTT(screen,0,380,WIDTH,20);
        drawTTT(screen,0,580,WIDTH,20);
        //vetical TicTacToe line
        drawTTT(screen,0,0,20,HEIGHT);
        drawTTT(screen,190,0,20,HEIGHT);
        drawTTT(screen,390,0,20,HEIGHT);
        drawTTT(screen,580,0,20,HEIGHT);

        //draw O and X to screen
        drawImage(screen,player,x,y);

        //Draw O at the grid if user selects.
        if(placeO[0] == 1)
            drawImage(screen,O,40,20);
        if(placeO[1] == 1)
            drawImage(screen,O,240,30);
        if(placeO[2] == 1)
            drawImage(screen,O,440,30);
        if(placeO[3] == 1)
            drawImage(screen,O,40,210);
        if(placeO[4] == 1)
            drawImage(screen,O,240,210);
        if(placeO[5] == 1)
            drawImage(screen,O,440,210);
        if(placeO[6] == 1)
            drawImage(screen,O,40,420);
        if(placeO[7] == 1)
            drawImage(screen,O,240,420);
        if(placeO[8] == 1)
            drawImage(screen,O,440,420);

        //Draw X at the grid if player selects.
       if(placeX[0] == 1)
            drawImage(screen,X,40,20);
        if(placeX[1] == 1)
            drawImage(screen,X,240,30);
        if(placeX[2] == 1)
            drawImage(screen,X,430,30);
        if(placeX[3] == 1)
            drawImage(screen,X,40,210);
        if(placeX[4] == 1)
            drawImage(screen,X,230,210);
        if(placeX[5] == 1)
            drawImage(screen,X,430,210);
        if(placeX[6] == 1)
            drawImage(screen,X,40,410);
        if(placeX[7] == 1)
            drawImage(screen,X,230,410);
        if(placeX[8] == 1)
            drawImage(screen,X,430,410);

         //return true if player 1 is the winner
       if(winner_player1(placeO) == true)
       {
           //plater 1 is the winner
           drawImage(screen,winnerO,0,0);
            SDL_Flip(screen);

           while(SDL_PollEvent(&restart))
           {
               switch(restart.type)
               {
                   case SDL_KEYDOWN:
                    {
                          if(restart.key.keysym.sym == SDLK_y)
                        {
                            cnt = 0;
                            for(int i = 0; i < 9; i ++)
                            {
                                place[i] = 0;
                                placeO[i] = 0;
                                placeX[i] = 0;
                            }
                            player = IMG_Load("./player/O.bmp");
                        }
                        else if(restart.key.keysym.sym == SDLK_n)
                            done = true;
                    }

                }
                   break;
           }
        }
       else if(winner_player2(placeX)== true)
       {
           //player 2 is the winner
           //plater 1 is the winner
           drawImage(screen,winnerX,0,0);
            SDL_Flip(screen);
           while(SDL_PollEvent(&restart))
           {
               switch(restart.type)
               {
                   case SDL_KEYDOWN:
                    {
                        if(restart.key.keysym.sym == SDLK_y)
                        {
                            cnt = 0;
                            for(int i = 0; i < 9; i ++)
                            {
                                place[i] = 0;
                                placeO[i] = 0;
                                placeX[i] = 0;
                            }
                            player = IMG_Load("./player/O.bmp");
                        }
                        else if(restart.key.keysym.sym == SDLK_n)
                            done = true;
                    }
                   break;
               }
           }
       }

		//color keying
       SDL_SetColorKey(player,SDL_SRCCOLORKEY,magenta);
       SDL_SetColorKey(O,SDL_SRCCOLORKEY,magenta);
       SDL_SetColorKey(X,SDL_SRCCOLORKEY,magenta);
        //start the game again?
        if(isFull(place) == true )
        {
            //game over
            drawImage(screen,gameover,0,0);

            if(SDL_PollEvent(&event))
            {
                if(event.type == SDL_KEYDOWN)
                {
                    //if yes start over
                    if(event.key.keysym.sym == SDLK_y)
                    {
                        cnt = 0;
                        for(int i = 0; i < 9; i++)
                        {
                            place[i] = 0;
                            placeO[i] = 0;
                            placeX[i] = 0;
                        }
                         player = IMG_Load("./player/O.bmp");
                    }
                    //if no quit
                    else if(event.key.keysym.sym == SDLK_n)
                    {
                        done = true;
                    }

                }
            }
        }
        SDL_Flip(screen);
    }

    SDL_FreeSurface(screen);
    SDL_FreeSurface(winnerO);
    SDL_FreeSurface(winnerX);
    SDL_FreeSurface(gameover);
    SDL_FreeSurface(player);

    SDL_Quit();

    return ;
}
