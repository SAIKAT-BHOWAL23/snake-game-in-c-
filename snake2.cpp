//#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

using namespace std;

const int width = 20;
const int height = 20;

bool gameover;
int x, y, fruitx, fruity, score;

int tailx[100], taily[100],ntail;

enum directions { STOP = 0, UP, DOWN, LEFT, RIGHT };
directions dir;

void setup()
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;

    fruitx = rand() % width;
    fruity = rand() % height;
}

void draw()
{
    system("CLS");

    for (int i = 0; i < width; i++)
    {
        cout << "#";
    }

    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "#";
            }
            else if (i == y && j == x)
            {
                cout << "$";
            }
            else if (i == fruity && j == fruitx)
            {
                cout << "f";
            }
            else
            {
               bool print =false;
                for(int k=0;k<ntail-1;k++)
                {
                  if(i==taily[i] && j==tailx[i])
                  {
                    cout<<"$";

                    print =true;
                  }
                }if(!print)
                cout<<" ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
    {
        cout << "#";
    }

    cout << endl << endl;
    cout << "Score: " << score << endl;
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'w':
                dir = UP;
                break;

            case 'a':
                dir = LEFT;
                break;

            case 's':
                dir = DOWN;
                break;

            case 'd':
                dir = RIGHT;
                break;
        }
    }
}

void logic()
{
  int prevx=tailx[0];
  int prevy=taily[0];


  tailx[0]=x;
  taily[0]=y;

  int prev2x,prev2y;

  for(int i=1;i<ntail;i++)

  {
    prev2x=tailx[i];
    prev2y=taily[i];
    tailx[i]=prevx;
    taily[i]=prevy;
    prevx=prev2x;
    prevy=prev2y;

  }






    switch (dir)
    {
        case UP:
            y--;
            break;

        case DOWN:
            y++;
            break;

        case LEFT:
            x--;
            break;

        case RIGHT:
            x++;
            break;

        default:
            break;
    }

    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        gameover = true;
    }

    for(int i=0;i<ntail;i++)
    {
      if(x==tailx[i] && y==taily[i])
      {
        gameover=true;

      }
    }

    if (x == fruitx && y == fruity)
    {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        ntail++;
    }
}

int main()
{
    setup();

    while (!gameover)
    {
        draw();
        input();
        logic();
        Sleep(60);
    }

    return 0;
}
