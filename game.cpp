#include <iostream>
#include "help.h"
#include <windows.h>
using namespace std;
int live = 3;
int scores = 0;
bool allbricks[6][14];
bool easy = false;
bool hard = false;

void boundary()
{
    myRect(40, 75, 840, 600, 255, 255, 255, 255, 255, 255);
}

void bricks()
{
    int brick_width = 50;
    int brick_height = 20;
    int start_x = 60;
    int start_y = 85;

    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 14; col++)
        {
            allbricks[row][col] = true;

            int x1 = start_x + col * (brick_width + 5);
            int y1 = start_y + row * (brick_height + 5);
            int x2 = x1 + brick_width;
            int y2 = y1 + brick_height;

            int R, G, B;
            if (row == 0)
            {
                R = 47; G = 79; B = 79;
            }
            else if (row == 1)
            {
                R = 178; G = 34; B = 34;
            }
            else if (row == 2)
            {
                R = 85; G = 107; B = 47;
            }
            else if (row == 3)
            {
                R = 25; G = 25; B = 112;
            }
            else if (row == 4)
            {
                R = 139; G = 0; B = 139;
            }
            else
            {
                R = 139; G = 69; B = 19;
            }


            myRect(x1, y1, x2, y2, R, G, B, R, G, B);

        }
    }
}

void title()
{
    drawText(20, 300, 20, 0, 191, 255, "BRICK BREAKER");

}
void lives()
{
    myRect(900, 100, 1100, 150, 255, 255, 255, 255, 255, 255);
    drawText(20, 920, 110, 0, 0, 0, "LIVES = ", true, live);
}

void score()
{
    myRect(900, 200, 1150, 250, 255, 255, 255, 255, 255, 255);
    drawText(20, 920, 210, 0, 0, 0, "SCORE = ", true, scores);
}
void difficulty()
{
    my_rec(40, 75, 840, 800, 147, 202, 237, 147, 202, 237, 10);

    my_rec(300, 300, 550, 420, 0, 0, 0, 255, 255, 255, 20);
    my_rec(300, 500, 550, 620, 0, 0, 0, 255, 255, 255, 20);
    drawText(30, 100, 100, 0, 0, 0, "SELECT DIIFICULTY LEVEL");
    drawText(20, 180, 220, 0, 0, 0, "E for Easy and H for Hard");
    drawText(40, 350, 320, 0, 0, 0, "EASY");
    drawText(40, 350, 520, 0, 0, 0, "HARD");


}
void easy_hard(int button)
{
    if (isKeyPressed(button))
    {

        if (button == 8)
        {
            easy = true;
        }
        else if (button == 9)
        {
            hard = true;
        }
        else if (button == 7)
        {
            exit(0);
        }
    }
}

void movement()
{
    //Paddle movement
    myRect(350, 530, 470, 540, 0, 0, 0, 0, 0, 0);

    int x = 350, y = 530, width = 470, height = 540;

    int x1 = 400, y1 = 500, x2 = 420, y2 = 520;
    int nx = 5;
    int ny = -5;

    int arrow;

    lives();
    score();

    while (live > 0)
    {
        if (isKeyPressed(arrow))
        {
            if (arrow == 7)
            {
                break;
            }

            myRect(x, y, width, height, 255, 255, 255, 255, 255, 255);
            if (arrow == 1 && x > 50)
            {
                x -= 20;
                width -= 20;
            }
            else if (arrow == 3 && width < 830)
            {
                x += 20;
                width += 20;
            }
            myRect(x, y, width, height, 0, 0, 0, 0, 0, 0);
        }

        if (easy)
        {
            Sleep(20);

        }
        else if (hard)
        {
            Sleep(5);
        }

        //Ball movement
        myEllipse(x1, y1, x2, y2, 255, 255, 255, 255, 255, 255);

        x1 += nx;
        x2 += nx;
        y1 += ny;
        y2 += ny;

        //wall
        if (x1 <= 40 || x2 >= 840)
        {
            nx = -nx;
        }
        if (y1 <= 75)
        {
            ny = -ny;
        }

        //paddle
        if (y2 >= y && x1 >= x && x2 <= width)
        {
            ny = -ny;
        }

        //brick
        int brick_width = 50;
        int brick_height = 20;
        int start_x = 60;
        int start_y = 85;

        bool brick_toot = false;
        for (int row = 0; row < 6 && !brick_toot; row++)
        {
            for (int col = 0; col < 14; col++)
            {
                if (!allbricks[row][col])
                {
                    continue;
                }

                int bx1 = start_x + col * (brick_width + 5);
                int by1 = start_y + row * (brick_height + 5);
                int bx2 = bx1 + brick_width;
                int by2 = by1 + brick_height;

                if (x2 >= bx1 && x1 <= bx2 && y2 >= by1 && y1 <= by2)
                {
                    allbricks[row][col] = false;
                    myRect(bx1, by1, bx2, by2, 255, 255, 255, 255, 255, 255);

                    //center difference
                    int ballCenterX = (x1 + x2) / 2;
                    int ballCenterY = (y1 + y2) / 2;
                    int brickCenterX = (bx1 + bx2) / 2;
                    int brickCenterY = (by1 + by2) / 2;

                    int diffX = ballCenterX - brickCenterX;
                    int diffY = ballCenterY - brickCenterY;

                    if (abs(diffX) > abs(diffY))
                    {
                        nx = -nx;
                    }
                    else
                    {
                        ny = -ny;
                    }

                    scores++;
                    score();
                    brick_toot = true;
                    break;
                }
            }
        }

        myEllipse(x1, y1, x2, y2, 255, 0, 0, 255, 0, 0);

        if (y2 >= 600)
        {
            myEllipse(x1, y1, x2, y2, 255, 255, 255, 255, 255, 255);
            live--;
            lives();
            Sleep(1000);

            x1 = 400; y1 = 500;
            x2 = 420; y2 = 520;
            nx = 5; ny = -5;
        }


        bool all_bricks_toot = true;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 14; j++)
            {
                if (allbricks[i][j])
                {
                    all_bricks_toot = false;
                    break;
                }
            }
        }

        if (all_bricks_toot)
        {
            drawText(30, 300, 300, 0, 255, 0, "YOU WIN!");
            return;
        }

        if (easy)
        {
            Sleep(20);
        }
        else if (hard)
        {
            Sleep(1);
        }
    }

    drawText(30, 300, 300, 255, 0, 0, "GAME OVER");
}

void start()
{
    my_rec(40, 75, 840, 800, 147, 202, 237, 227, 11, 92, 10);

    my_rec(275, 200, 600, 300, 0, 0, 0, 255, 255, 255, 5);
    my_rec(275, 400, 600, 500, 0, 0, 0, 255, 255, 255, 5);
    my_rec(275, 600, 600, 700, 0, 0, 0, 255, 255, 255, 5);
    drawText(40, 200, 100, 255, 255, 255, "Brick Breaker");
    drawText(30, 340, 225, 0, 0, 0, "Resume");
    drawText(30, 310, 425, 0, 0, 0, "New Game");
    drawText(30, 375, 625, 0, 0, 0, "Exit");
}

int main()
{
    int in = 0;
    start();
    while (!isKeyPressed(in))
    {


        if (isKeyPressed(in))
        {
            if (in == 7)
            {
                exit(0);
            }
            if (in == 11)
            {
                system("cls");
                difficulty();
                int but = 0;
                while (!easy && !hard)
                {
                    easy_hard(but);
                }
                system("cls");

                title();
                boundary();
                bricks();
                movement();
            }
        }
    }


    return 0;
}
