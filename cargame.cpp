#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

const int LANE_LEFT = 3;
const int LANE_CENTER = 7;
const int LANE_RIGHT = 11;
const int WIDTH = 15;
const int HEIGHT = 20;
const int NUM_ENEMIES = 3;

int laneX[3] = {LANE_LEFT, LANE_CENTER, LANE_RIGHT};

int playerLane = 1;
int enemyLanes[NUM_ENEMIES];
int enemyY[NUM_ENEMIES];
bool gameOver = false;
int score = 0;
int speed = 150;

void setCursorPosition(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void drawGame()
{
    setCursorPosition(0, 0);
    for (int i = 0; i < HEIGHT - 1; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            bool printed = false;

            if (j == 0 || j == 5 || j == 9 || j == WIDTH - 1)
            {
                cout << "|";
                printed = true;
            }

            for (int k = 0; k < NUM_ENEMIES; k++)
            {
                if (i == enemyY[k] && j == laneX[enemyLanes[k]])
                {
                    cout << "V";
                    printed = true;
                    break;
                }
            }

            if (!printed && i == HEIGHT - 2 && j == laneX[playerLane])
            {
                cout << "A"; 
                printed = true;
            }

            if (!printed)
                cout << " ";
        }
        cout << endl;
    }

    cout << "\nScore: " << score << endl;
}

void drawGameOver()
{
    system("cls");
    cout << "\nGAME OVER! Final Score: " << score << endl;
    cout << "\nThanks for playing!\n";
}

void handleInput()
{
    if (_kbhit())
    {
        int ch = _getch();
        if (ch == 224)
        {
            int arrow = _getch();
            if (arrow == 75 && playerLane > 0)
                playerLane--;
            else if (arrow == 77 && playerLane < 2)
                playerLane++;
        }
        else if (ch == 27)
        {
            gameOver = true;
        }
    }
}

void updateLogic()
{
    for (int i = 0; i < NUM_ENEMIES; i++)
    {
        enemyY[i]++;

        if (enemyY[i] == HEIGHT - 2 && enemyLanes[i] == playerLane)
        {
            gameOver = true;
            return;
        }

        if (enemyY[i] >= HEIGHT - 1)
        {
            enemyY[i] = 0;
            enemyLanes[i] = rand() % 3;
            score++;

            if (speed > 50 && score % 5 == 0)
                speed -= 10;
        }
    }
}

void showInstructions()
{
    system("cls");
    cout << "INSTRUCTIONS:\n";
    cout << ". Use LEFT arrow (<--) to move left.\n";
    cout << ". Use RIGHT arrow (-->) to move right.\n";
    cout << ". Avoid enemy cars (V). Colliding ends the game.\n";
    cout << ". Press ESC anytime to exit.\n";
    cout << "\nPress any key to return to the menu...";
    _getch();
    system("cls");
}

void startMenu()
{
    while (true)
    {
        system("cls");
        cout <<"******************************************\n";
        cout <<"*       WELCOME TO CAR RACING GAME       *\n";
        cout <<"******************************************\n";
        cout << "Press 'S' to Start the Game\n";
        cout << "Press 'I' for Instructions\n";
        cout << "Press ESC to Exit\n";

        char choice = _getch();
        if (choice == 's' || choice == 'S')
        {
            system("cls");

            playerLane = 1;
            score = 0;
            speed = 150;
            gameOver = false;
            for (int i = 0; i < NUM_ENEMIES; i++)
            {
                enemyLanes[i] = rand() % 3;
                enemyY[i] = rand() % (HEIGHT / 2);
            }
            break;
        }
        else if (choice == 'i' || choice == 'I')
        {
            showInstructions();
        }
        else if (choice == 27)
        {
            exit(0);
        }
    }
}

int main()
{
    srand(time(0));
    hideCursor();

    while (true)
    {
        startMenu();

        while (!gameOver)
        {
            drawGame();
            handleInput();
            updateLogic();
            Sleep(speed);
        }

        drawGameOver();

        cout << "\nPress 'R' to Restart or ESC to Exit...";
        char again = _getch();
        if (again == 'r' || again == 'R')
            continue;
        else
            break;
    }

    return 0;
}
