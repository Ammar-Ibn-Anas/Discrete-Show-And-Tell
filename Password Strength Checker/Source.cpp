#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<iomanip>
using namespace std;

void gotoRowCol(int rpos, int cpos)
{
    COORD scrn{};
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void color(int k)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
}
void hideConsoleCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
void line(int r1, int c1, int r2, int c2, char sym, int rows = 120, int cols = 240)
{
    for (float i = 0; i <= 1; i += 0.01)
    {
        int X = ceil(c1 * (1 - i)) + (c2 * (i));
        int Y = ceil(r1 * (1 - i)) + (r2 * (i));
        if (r1 == r2)
            Y = r1;
        if (c1 == c2)
            X = c1;
        gotoRowCol(Y, X);
        cout << sym;
    }
}
void dibba(int r, int c, int d, int rows, int cols)
{
    line(r, c, r + d, c, -37, rows, cols);
    line(r + d, c, r + d, c + d, -37, rows, cols);
    line(r + d, c + d, r, c + d, -37, rows, cols);
    line(r, c + d, r, c, -37, rows, cols);
}
void display(int rows, int cols, int length)
{
    line(rows, cols, rows, cols + length, -37);
    line(rows, cols + length, rows + length / 2, cols + length, -37);
    line(rows + length / 2, cols + length, rows + length / 2, cols, -37);
    line(rows + length / 2, cols, rows, cols, -37);
}
void printgrid(int distance, int rows, int cols)
{
    for (int r = 0; r < distance * 10; r += distance)
    {
        for (int c = 0; c < distance * 10; c += distance)
        {
            dibba(r, c, distance, rows, cols);
        }
    }
}
void printnumbers(int distance)
{
    color(14);
    int num = 1;
    int eo = 1;
    for (int r = distance * 10; r >= distance / 2; r -= distance, eo++)
    {
        if (eo % 2 == 0)
        {
            for (int c = distance * 10; c >= distance / 2; c -= distance)
            {
                gotoRowCol(r - distance / 2, c - distance / 2);
                cout << setw(2) << num++;
            }
        }
        else
        {
            for (int c = distance / 2; c <= distance * 10; c += distance)
            {
                gotoRowCol(r - distance / 2, c);
                cout << setw(2) << num++;
            }
        }
    }

    color(15);
}
void diceroll(int& die, int& move, int r, int c)
{
    int nofsix = 0;
    move = 0;
    while (true)
    {
        die = rand();
        die = die % 6 + 1;
        move += die;
        if (die != 6)
        {
            gotoRowCol(r, c);
            cout << die;
            return;
        }
        if (die == 6)
        {
            nofsix++;
        }
        if (nofsix == 3)
        {
            move = 0;
            gotoRowCol(r, c);
            cout << "X";
            return;
        }
        gotoRowCol(r, c);
        cout << die;
    }
}
void intro(int rows, int cols, char p1name[], char p2name[])
{
    color(11);
    gotoRowCol(rows / 2, cols / 2 - 20);
    cout << "WELCOME TO SNAKES AND LADDERS GAME MADE BY AMMAR ANAS";
    Sleep(5000);
    system("cls");
    gotoRowCol(rows / 2, cols / 2 - 35);
    cout << "RUN THIS GAME IN A WINDOW LAYOUT OF 125 ROWS/HEIGHT AND 230 COLUMNS/WIDTH FOR THE BEST EXPERIENCE";
    Sleep(5000);
    system("cls");
    gotoRowCol(rows / 2, cols / 2 - 25);
    cout << "WITH THAT ASIDE PLEASE HAVE FUN AND ENJOY YOURSELF!!! THANK YOU FOR PLAYING MY GAME <3";
    Sleep(5000);
    system("cls");
    color(15);
    gotoRowCol(rows / 2, cols / 2 - 20);
    cout << "Enter player 1 name: ";
    int size = 0;
    while (true)
    {
        p1name[size++] = _getche();
        if (p1name[size - 1] == 13)
            break;
    }
    p1name[size] = '\0';
    system("cls");
    gotoRowCol(rows / 2, cols / 2 - 20);
    cout << "Enter player 2 name: ";
    size = 0;
    while (true)
    {
        p2name[size++] = _getche();
        if (p2name[size - 1] == 13)
            break;
    }
    p2name[size] = '\0';
    system("Cls");
    color(15);
}
void printsnakes()
{
    char sym = -37;
    color(4);
    line(110, 50, 100, 30, -37);
    line(65, 26, 90, 26, -37);
    line(65, 100, 75, 90, -37);
    line(54, 54, 93, 65, -37);
    line(44, 54, 65, 40, -37);
    line(5, 100, 27, 115, -37);
    line(15, 88, 55, 88, -37);
    line(5, 15, 80, 63, -37);
    color(15);
}
void printladders()
{
    color(10);
    line(110, 63, 100, 53, -37);
    line(110, 100, 75, 115, -37);
    line(100, 20, 80, 30, -37);
    line(90, 5, 30, 15, -37);
    line(90, 90, 20, 40, -37);
    line(50, 110, 40, 75, -37);
    line(27, 100, 5, 87, -37);
}
void p1grid(int pos, int sym, int distance)
{
    int row = (pos - 1) / 10;
    int col = (pos - 1) % 10;
    if (row % 2 == 1) {
        col = 9 - col;
    }
    int screenRow = ((10 - row) * distance - distance / 2) - 5;
    int screenCol = (col * distance + distance / 2) - 5;
    color(2);
    gotoRowCol(screenRow, screenCol);
    cout << (char)sym;
    gotoRowCol(screenRow + 1, screenCol);
    cout << (char)sym;
    gotoRowCol(screenRow + 1, screenCol + 1);
    cout << (char)sym;
    gotoRowCol(screenRow, screenCol + 1);
    cout << (char)sym;
    gotoRowCol(screenRow + 2, screenCol);
    cout << (char)sym;
    gotoRowCol(screenRow + 2, screenCol + 1);
    cout << (char)sym;
    gotoRowCol(screenRow + 1, screenCol + 2);
    cout << (char)sym;
    gotoRowCol(screenRow, screenCol + 2);
    cout << (char)sym;
    gotoRowCol(screenRow + 2, screenCol + 2);
    cout << (char)sym;
    color(15);
}
void p2grid(int pos, int sym, int distance)
{
    int row = (pos - 1) / 10;
    int col = (pos - 1) % 10;
    if (row % 2 == 1) {
        col = 9 - col;
    }
    int screenRow = ((10 - row) * distance - distance / 2) + 3;
    int screenCol = (col * distance + distance / 2) - 5;
    color(13);
    gotoRowCol(screenRow, screenCol);
    cout << (char)sym;
    gotoRowCol(screenRow + 1, screenCol);
    cout << (char)sym;
    gotoRowCol(screenRow + 1, screenCol + 1);
    cout << (char)sym;
    gotoRowCol(screenRow, screenCol + 1);
    cout << (char)sym;
    gotoRowCol(screenRow + 2, screenCol);
    cout << (char)sym;
    gotoRowCol(screenRow + 2, screenCol + 1);
    cout << (char)sym;
    gotoRowCol(screenRow + 1, screenCol + 2);
    cout << (char)sym;
    gotoRowCol(screenRow, screenCol + 2);
    cout << (char)sym;
    gotoRowCol(screenRow + 2, screenCol + 2);
    cout << (char)sym;
    color(15);
}
void sal(int snakes[], int ladders[])
{
    snakes[10] = 5;
    snakes[43] = 23;
    snakes[56] = 26;
    snakes[49] = 33;
    snakes[65] = 44;
    snakes[99] = 35;
    snakes[88] = 53;
    snakes[92] = 71;

    ladders[6] = 16;
    ladders[9] = 31;
    ladders[19] = 38;
    ladders[28] = 84;
    ladders[21] = 79;
    ladders[51] = 67;
    ladders[72] = 93;
}
void check(int snakes[], int ladders[], int& position) {
    if (snakes[position] != 0) {
        position = snakes[position];
    }
    else if (ladders[position] != 0) {
        position = ladders[position];
    }
}
void main()
{
    hideConsoleCursor();
    srand(time(0));
    int rows = 120, cols = 220, die, move;
    int posp1 = 0, posp2 = 0;
    char p1name[15], p2name[15];
    int snakes[101] = { 0 };
    int ladders[101] = { 0 };
    sal(snakes, ladders);
    intro(rows, cols, p1name, p2name);
    printgrid(rows / 10, rows, cols);
    printnumbers(rows / 10);
    dibba(rows * 3 / 4 - 5, cols * 7 / 8 - 5, 10, rows, cols);
    display(rows / 4, cols * 3 / 4, 40);
    printsnakes();
    printladders();
    while ((posp1 != 100) && (posp2 != 100))
    {
        gotoRowCol(rows / 4 + 10, cols * 3 / 4 + 12);
        cout << string(25, ' ');
        gotoRowCol(rows / 4 + 12, cols * 3 / 4 + 12);
        cout << string(25, ' ');
        gotoRowCol(rows / 4 + 14, cols * 3 / 4 + 12);
        cout << string(25, ' ');

        color(15);
        gotoRowCol(rows / 4 + 10, cols * 3 / 4 + 12);
        cout << "Player "; color(10); cout << p1name; color(15);
        gotoRowCol(rows / 4 + 12, cols * 3 / 4 + 12);
        cout << "PRESS SPACE TO ROLL DICE";
        char key;
        while (true)
        {
            key = _getch();
            if (key == 32)
                break;
        }

        gotoRowCol(rows / 4 + 14, cols * 3 / 4 + 12);
        cout << "          ";
        diceroll(die, move, rows * 3 / 4, cols * 7 / 8);
        gotoRowCol(rows / 4 + 14, cols * 3 / 4 + 12);
        if (move == 0)
        {
            cout << "Null";
        }
        else
        {
            cout << "Move: " << setw(2) << move;
            p1grid(posp1, ' ', rows / 10);
            printsnakes();
            printladders();
            posp1 += move;
            if (posp1 > 100)
                posp1 = 100;
            check(snakes, ladders, posp1);
            p1grid(posp1, -37, rows / 10);

        }
        if (posp1 == 100)
            break;
        _getch();

        gotoRowCol(rows / 4 + 10, cols * 3 / 4 + 12);
        cout << string(25, ' ');
        gotoRowCol(rows / 4 + 12, cols * 3 / 4 + 12);
        cout << string(25, ' ');
        gotoRowCol(rows / 4 + 14, cols * 3 / 4 + 12);
        cout << string(25, ' ');

        gotoRowCol(rows / 4 + 10, cols * 3 / 4 + 12);
        cout << "Player "; color(13); cout << p2name; color(15);
        gotoRowCol(rows / 4 + 12, cols * 3 / 4 + 12);
        cout << "PRESS SPACE TO ROLL DICE";
        while (true)
        {
            key = _getch();
            if (key == 32)
                break;
        }

        gotoRowCol(rows / 4 + 14, cols * 3 / 4 + 12);
        cout << "          ";
        diceroll(die, move, rows * 3 / 4, cols * 7 / 8);
        gotoRowCol(rows / 4 + 14, cols * 3 / 4 + 12);
        if (move == 0)
        {
            cout << "Null";
        }
        else
        {
            cout << "Move: " << setw(2) << move;
            p2grid(posp2, ' ', rows / 10);
            printsnakes();
            printladders();
            posp2 += move;
            if (posp2 > 100)
                posp2 = 100;
            check(snakes, ladders, posp2);
            p2grid(posp2, -37, rows / 10);
        }
        _getch();
    }
    _getch();
    system("cls");
    gotoRowCol(125 / 2, 235 / 2 - 10);
    if (posp1 == 100)
    {
        color(10);
        cout << p1name;
    }
    if (posp2 == 100)
    {
        color(13);
        cout << p2name;
    }
    gotoRowCol(125 / 2 + 2, 235 / 2 - 5);
    color(15);
    cout << "WON!!";
    Sleep(1000);
    _getch();
    return;

}