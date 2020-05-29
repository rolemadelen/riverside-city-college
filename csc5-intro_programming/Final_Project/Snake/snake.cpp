/*
 * Jiwon Yoo
 * Snake - C++/SDL
 */

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int WIDTH = 600;
const int HEIGHT = 400;
const int FPS = 150;

/********************************************
 * collision function checks collision btwn
 * a wall and a snake. If collide return true
 * else false
 *
 * parameter : snake and the wall
 *
 * return type is boolean
 ********************************************/
bool isCollision(SDL_Rect *rect1, SDL_Rect *rect2)
{
    if(rect1-> y >= rect2-> y + rect2-> h)
        return 0;
    if(rect1-> x >= rect2-> x + rect2-> w)
        return 0;
    if(rect1-> y + rect1-> h <= rect2-> y)
        return 0;
    if(rect1-> x + rect1-> w <= rect2-> x)
        return 0;

    return 1;
}

/********************************************
 * collision function checks collision btwn
 * a wall and a snake. If collide return true
 * else false
 *
 * parameter : snake and the wall
 *
 * return type is boolean
 ********************************************/
bool isCollision(vector<SDL_Rect>& rect1, SDL_Rect *rect2)
{
    if(rect1[0].y >= rect2-> y + rect2-> h)
        return 0;
    if(rect1[0].x >= rect2-> x + rect2-> w)
        return 0;
    if(rect1[0].y + rect1[0].h <= rect2-> y)
        return 0;
    if(rect1[0].x + rect1[0].w <= rect2-> x)
        return 0;

    return 1;
}

/********************************************
 * DrawSprite function creates animation motion.
 *
 * parameter : sprite image, screen, location to put image (x,y),
 *			crop image(w,h) and step meaning frame.
 *
 * return type is void.
 ********************************************/
void DrawSprite(SDL_Surface *image, SDL_Surface *screen,
        int x, int y, int w, int h, int step)
{
    SDL_Rect rectDst,rectSrc;
    rectDst.x = x;
    rectDst.y = y;
    rectSrc.x = (step % w) * image->w/w;
    rectSrc.y = (step / w) * image->h/h;
    rectSrc.w = image->w/w;
    rectSrc.h = image->h/h;
    SDL_BlitSurface(image,&rectSrc,screen,&rectDst);
}

/********************************************
 * randVal function generates random number
 *
 * parameter : min and max
 *
 * return type is integer
 ********************************************/
int randVal(int min, int max)
{
    return (rand() % (max-min+1) + min);
}

int main(int argc, char** argv)
{
    //seed
    srand((unsigned)time(NULL));

    //set caption (screen title)
    SDL_WM_SetCaption("Snake - JY", NULL);

    //declare vars
    SDL_Surface *screen = NULL;
    SDL_Surface *title = NULL;
    SDL_Surface *startC = NULL;
    SDL_Surface *exitC = NULL;
    SDL_Surface *gameover = NULL;
    SDL_Surface *gameover2 = NULL;
    SDL_Surface *sprite = NULL;

    //delcare event and switch
    SDL_Event event;
    bool done = false;

    //direction - motion
    //initial : move upward when game starts
    bool b[4] = {0,1,0,0};

    //used in Regulating FPS
    Uint32 start;

    //count number of pellet's eaten by a snake
    int pelletNum = 0;
    int badPelletNum = 0;
    int superPelletNum = 0;
    int point = 0;

    //determine the speed of a game
    int delay;

    //used to re-generate the location of
    //bad and good pellet
    int badFoodGen = 0;
    int goodFoodGen = 0;

    //initilize SDL and Music
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);

    // Delcare music and load music
    Mix_Music* music;
    music = Mix_LoadMUS("./snake/TippinOfCows_Moosader.ogg");

    //set screen size
    screen = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|
            SDL_DOUBLEBUF|SDL_ANYFORMAT|SDL_FULLSCREEN);

    //create snake head
    SDL_Rect snakeHead = {300,200,10,10};
    vector<SDL_Rect> snake;
    snake.push_back(snakeHead);

    SDL_Rect pellet ={randVal(5,37) * 10,
        randVal(3,37) * 10,10,10};
    SDL_Rect badPellet = {randVal(3,57) * 10,
        randVal(3,37) * 10,10,10};

    //Creating wall or boundaries
    SDL_Rect field[4];
    //left wall
    field[0].x = 0;
    field[0].y = 0;
    field[0].w = 20;
    field[0].h = HEIGHT;
    //top wall
    field[1].x = 0;
    field[1].y = 0;
    field[1].w = WIDTH;
    field[1].h = 20;
    //bottom wall
    field[2].x = 0;
    field[2].y = HEIGHT - 20;
    field[2].w = WIDTH;
    field[2].h = 20;
    //right wall
    field[3].x = WIDTH-20;
    field[3].y = 0;
    field[3].w = 25;
    field[3].h = HEIGHT;

    //colors for snake, boundaries, and pellet
    Uint32 wall = SDL_MapRGB(screen->format,0,0,66);
    Uint32 white = SDL_MapRGB(screen->format,255,255,255);
    Uint32 green = SDL_MapRGB(screen->format,0,255,0);
    Uint32 red = SDL_MapRGB(screen->format,255,0,0);
    Uint32 yellow = SDL_MapRGB(screen->format,255,255,0);

    //Loading Image
    //title page
    title = IMG_Load("./snake/title.bmp");
    startC = IMG_Load("./snake/startClick.bmp");
    exitC = IMG_Load("./snake/quitClick.bmp");
    //gameover page
    gameover = IMG_Load("./snake/gameover.bmp");
    gameover2 = IMG_Load("./snake/gameover2.bmp");
    //simple gem sprite
    sprite = IMG_Load("./pic/gems.png");
    //sprite
    int step = 0;

    //main menu
    while(!done)
    {
        //while waiting for an event
        while(SDL_PollEvent(&event))
        {
            //output corresponding picture
            step++;
            SDL_BlitSurface(title,NULL,screen,NULL);

            //location of start and quit ICON
            SDL_Rect start = {75,180,140,50};
            SDL_Rect quit = {75,273,120,40};

            //mouse location init.
            int x = 0;
            int y = 0;
            switch(event.type)
            {
                //get mouse motion
                case SDL_MOUSEMOTION:
                    {
                        //location of mouse at x and y
                        x = event.motion.x;
                        y = event.motion.y;

                        //if mouse is where START button is START button changes to red
                        if(x>start.x&&x<start.x+start.w&&y>start.y&&y<start.y+start.h)
                        {
                            SDL_FillRect(screen,&start,SDL_MapRGB(screen->format,255,0,255));
                            SDL_BlitSurface(startC,NULL,screen,NULL);
                        }
                        //if mouse is where QUIT button is QUIT button changes to red
                        if(x>quit.x&&x<quit.x+quit.w&&y>quit.y&&y<quit.y+quit.h)
                        {
                            SDL_FillRect(screen,&quit,SDL_MapRGB(screen->format,255,0,255));
                            SDL_BlitSurface(exitC,NULL,screen,NULL);
                        }
                    }
                    break;
                    //mouse click event
                case SDL_MOUSEBUTTONDOWN:
                    {
                        //location of mouse at x and y
                        x = event.button.x;
                        y = event.button.y;
                        //if click at start boundary, start game.
                        if(x>start.x&&x<start.x+start.w&&y>start.y&&y<start.y+start.h)
                        {
                            SDL_FillRect(screen,&start,SDL_MapRGB(screen->format,0,0,0));
                            done = true;
                        }
                        //if click at quit boundary, quit.
                        if(x>quit.x&&x<quit.x+quit.w&&y>quit.y&&y<quit.y+quit.h)
                        {
                            SDL_FillRect(screen,&quit,SDL_MapRGB(screen->format,0,0,0));
                            return 0;
                        }
                    }
                    break;
            }

            //simple sprite motion next to Main Menu "SNAKE"
            DrawSprite(sprite,screen,509,43,4,3,step);
            //if step reachs the end set = first picture
            if(step==11)
                step = 0;
        }
        //flip the main menu screen
        SDL_Flip(screen);
    }

    //Init DONE to false to start second while loop
    done = false;

    //play music
    Mix_PlayMusic(music,-1);


    // game start
    while(!done)
    {
        //hide cursuor
        SDL_ShowCursor(0);

        //set initial delay/speed to 80
        //every time snake eats a pellet snake moves
        // pelletNum*2 faster
        delay = 80 - pelletNum*2 - superPelletNum + badPelletNum;

        //no faster than delay 20
        if(delay <= 20)
            delay = 20;

        //fill screen with white
        SDL_FillRect(screen,&screen->clip_rect,white);

        //fill good pellet with red
        //fill bad pellet with yellow
        SDL_FillRect(screen,&pellet,red);
        SDL_FillRect(screen,&badPellet,yellow);

        //get ms for FPS
        start = SDL_GetTicks();

        //while waiting for an evnet
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                //get key from a user
                case SDL_KEYDOWN:
                    {
                        //if UP arrow key is pressed
                        if(event.key.keysym.sym == SDLK_UP)
                        {
                            //if snake i smoving downward can't go upward
                            if(b[2])
                            {
                                b[0] = 0;
                                b[1] = 0;
                                b[2] = 1;
                                b[3] = 0;
                            }
                            //otherwise change direction to UP
                            else
                            {
                                //set UP = true
                                b[0] = 1;
                                b[1] = 0;
                                b[2] = 0;
                                b[3] = 0;
                            }
                        }

                        //if LEFT arrow key is pressed
                        if(event.key.keysym.sym == SDLK_LEFT)
                        {
                            //if moving to right, can't goto left
                            if(b[3])
                            {
                                b[0] = 0;
                                b[1] = 0;
                                b[2] = 0;
                                b[3] = 1;
                            }
                            //otherwise chnage dir to LEFT
                            else
                            {
                                //set LEFT = true
                                b[0] = 0;
                                b[1] = 1;
                                b[2] = 0;
                                b[3] = 0;
                            }
                        }

                        //if DOWN arrow key is press
                        if(event.key.keysym.sym == SDLK_DOWN)
                        {
                            //if going upward, can't move downward
                            if(b[0])
                            {
                                b[0] = 1;
                                b[1] = 0;
                                b[2] = 0;
                                b[3] = 0;
                            }
                            //otherwise change dir to DOWN
                            else
                            {
                                //set DOWN = true
                                b[0] = 0;
                                b[1] = 0;
                                b[2] = 1;
                                b[3] = 0;
                            }
                        }

                        //if RIGHT arrow key is press
                        if(event.key.keysym.sym == SDLK_RIGHT)
                        {
                            //if moving to right, can't move to left
                            if(b[1])
                            {
                                b[0] = 0;
                                b[1] = 1;
                                b[2] = 0;
                                b[3] = 0;
                            }
                            //otherwise chnage dir to RIGHT
                            else
                            {
                                //set RIGHT = true
                                b[0] = 0;
                                b[1] = 0;
                                b[2] = 0;
                                b[3] = 1;
                            }
                        }

                        //if ESC key is pressed QUIT
                        if(event.key.keysym.sym == SDLK_ESCAPE)
                            done = true;
                    }
                    break;
            }
        }

        //if UP key is pressed
        if(b[0])
        {
            //these 2 variable will store a number of
            //places snake moved. Used as timer for
            //food to re-generate.
            badFoodGen ++;
            goodFoodGen ++;

            //snake moves 10 spaces at a time
            snake[0].y-=10;
            //delay the space
            SDL_Delay(delay);

            //moving snake part
            for(int i = snake.size()-1; i > 0;i--)
            {
                snake[i].x = snake[i-1].x;
                snake[i].y = snake[i-1].y;
            }

            //GAME OVER PART
            //check collision btwn snake and the wall
            for(int i = 0; i < 4; i++)
                //if collision happened
                if(isCollision(&snake[0],&field[i]))
                {
                    //gameover page shows for 2 sec and QUIT.
                    SDL_BlitSurface(gameover,NULL,screen,NULL);
                    SDL_Flip(screen);
                    Mix_PauseMusic();
                    SDL_Delay(2000);
                    done = true;
                }
        }
        //if LEFT key == true
        else if(b[1])
        {
            //(See above b[0])
            badFoodGen ++;
            goodFoodGen ++;

            snake[0].x -=10;

            SDL_Delay(delay);

            //snake moving
            for(int i = snake.size()-1; i > 0;i--)
            {
                snake[i].y = snake[i-1].y;
                snake[i].x = snake[i-1].x;
            }

            //gameover part
            for(int i = 0; i < 4; i++)
                if(isCollision(&snake[0],&field[i]))
                {
                    SDL_BlitSurface(gameover,NULL,screen,NULL);
                    SDL_Flip(screen);
                    Mix_PauseMusic();
                    SDL_Delay(2000);
                    done=true;
                }

        }
        //if DOWN key == true
        else if(b[2])
        {
            //see above --> if(b[0])
            badFoodGen ++;
            goodFoodGen ++;

            snake[0].y +=10;

            SDL_Delay(delay);

            //moving snake parts
            for(int i = snake.size()-1; i > 0;i--)
            {
                snake[i].x = snake[i-1].x;
                snake[i].y = snake[i-1].y;
            }
            //game over part
            for(int i = 0; i < 4; i++)
                if(isCollision(&snake[0],&field[i]))
                {
                    SDL_BlitSurface(gameover,NULL,screen,NULL);
                    SDL_Flip(screen);
                    Mix_PauseMusic();
                    SDL_Delay(2000);
                    done = true;
                }
        }
        //if RIGHT key == true
        else if(b[3])
        {
            //see above --> b[0]
            badFoodGen ++;
            goodFoodGen ++;

            snake[0].x +=10;

            SDL_Delay(delay);

            //snake moving part
            for(int i = snake.size()-1; i > 0;i--)
            {
                snake[i].y = snake[i-1].y;
                snake[i].x = snake[i-1].x;
            }
            //game over parts
            for(int i = 0; i < 4; i++)
                if(isCollision(&snake[0],&field[i]))
                {
                    SDL_BlitSurface(gameover,NULL,screen,NULL);
                    SDL_Flip(screen);
                    Mix_PauseMusic();
                    SDL_Delay(2000);
                    done = true;
                }
        }

        //Self Collision
        for(unsigned int i = 2; i<snake.size();i++)
        {
            //if snakeHead collides with any of its body parts
            if(snake[0].x == snake[i].x && snake[i].y == snake[0].y)
            {
                //gameover
                SDL_BlitSurface(gameover2,NULL,screen,NULL);
                SDL_Flip(screen);
                Mix_PauseMusic();
                SDL_Delay(2000);
                done = true;
            }
        }

        //if snake colide with Good pellet
        //generate new Good pellet
        if(isCollision(&snake[0],&pellet))
        {
            //x and y Random Location
            pellet.x = randVal(3,57) * 10;
            pellet.y = randVal(3,37) * 10;

            //snake parts
            SDL_Rect temp = {0,0,10,10};

            //For some reason snake needs size of 3
            //to start to create a body parts.
            //so push back TWO temp rectangle;
            //haven't solved the issue yet.
            if(pelletNum == 0)
            {
                snake.push_back(temp);
                snake.push_back(temp);
            }
            //after very first one works fine
            //push back ONE temp rect.
            else
                snake.push_back(temp);

            //add 1 to number of Pellets eaten
            pelletNum ++;

            //point + 1
            point ++;

            //Init FoodGen to 0 so it doesn't
            //re-generate to new location without collision
            goodFoodGen = 0;
        }

        //if snake collide with bad pellet
        //snake moves 2 frame slower and decreasse size by 1
        else if(isCollision(&snake[0],&badPellet))
        {
            //badFood is Super for first 30 steps
            if(badFoodGen <= 10 + pelletNum)
            {
                //duration remain at 10
                if(badFoodGen <= 10)
                    badFoodGen = 10;

                //number of super pellet eaten + 1
                superPelletNum ++;

                //if ate SuperFood regenerate
                badPellet.x = randVal(3,57) * 10;
                badPellet.y = randVal(3,37) * 10;

                //SuperFood increase size by TWO
                SDL_Rect temp = {0,0,10,10};

                snake.push_back(temp);
                snake.push_back(temp);

                point += 2;

            }
            //if collide when is not SuperFood
            else
            {
                //generate in new location
                badPellet.x = randVal(3,57) * 10;
                badPellet.y = randVal(3,37) * 10;
                //decrease size by 1
                snake.pop_back();
                //store the number of badPellet eaten.
                badPelletNum ++;

                //point -1
                point --;
            }
            //reset timer(?) of badFood
            badFoodGen = 0;
        }

        //make sure pellet doesn't generate where snake body is
        for(int i = 1; i < snake.size(); i++)
        {
            //if goodPellet generate where snakeBody is re-gen
            if(&snake[i].x == &pellet.x && &snake[i].y == &pellet.y)
            {
                pellet.x = randVal(3,57) * 10;
                pellet.y = randVal(3,37) * 10;
            }
            //if badPellet gen where snakeBody is re-gen
            if(&snake[i].x == &badPellet.x && &snake[i].y == &badPellet.y)
            {
                badPellet.x = randVal(3,57) * 10;
                badPellet.y = randVal(3,37) * 10;
            }
        }

        //when badPellet is SuperPellet
        //change the color of the badPellet

        if(badFoodGen <= 10 + pelletNum)
        {
            //change color to somewhat gray
            SDL_FillRect(screen,&badPellet,SDL_MapRGB(screen->format,200,200,200));
        }

        //snake gets faster as player eat pellets
        //and timer is determined by number of places
        //snake moved.
        //make sure Food automatically generates no faster
        //or no slower than it did at first time.
        if(badFoodGen == 40 + pelletNum*2)
        {
            badFoodGen = 0;
            badPellet.x = randVal(3,57) * 10;
            badPellet.y = randVal(3,37) * 10;
        }
        if(goodFoodGen == 50 + pelletNum*2)
        {
            goodFoodGen = 0;
            pellet.x = randVal(3,57) * 10;
            pellet.y = randVal(3,37) * 10;
        }

        //coloring snakes with GREEN
        for(unsigned int i = 0; i < snake.size();i++)
        {
            SDL_FillRect(screen,&snake[0],SDL_MapRGB(screen->format,0,100,0));
            SDL_FillRect(screen,&snake[i],green);
        }
        //color of the wall
        for(int i = 0; i < 4; i++)
            SDL_FillRect(screen,&field[i],wall);

        //flip the screen
        SDL_Flip(screen);

        //FPS
        if(1000/FPS>SDL_GetTicks()-start)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }

    //File I/O
    //output Num of Pellet and Size

    ofstream outfile;
    ifstream infile;
    //if not exist make one so ofstream first
    //then ifstream.
    outfile.open("MaxPellet.txt");
    infile.open("MaxPellet.txt");

    outfile << "Max Pellet : " << pelletNum << endl;
    outfile << "Max Bad Pellet : " << badPelletNum << endl;
    outfile << "Max Super Pellet : " << superPelletNum << endl;
    outfile << "Max Points Earned : " << point << endl;
    outfile << "Largest Size : " << snake.size()-1 << endl;

    //close ifstream
    infile.close();
    outfile.close();

    //free surface and music to avoid memory leaks
    SDL_FreeSurface(screen);
    SDL_FreeSurface(title);
    SDL_FreeSurface(startC);
    SDL_FreeSurface(exitC);
    SDL_FreeSurface(gameover);
    SDL_FreeSurface(gameover2);
    SDL_FreeSurface(sprite);
    Mix_FreeMusic(music);

    //close SDL and Audio
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
