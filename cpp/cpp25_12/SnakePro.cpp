#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

#define WIDTH 25
#define HEIGHT 12

void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
}

class Snake {
private:
    int snakeX[100], snakeY[100];
    int foodX, foodY;
    int len;
    int dir;
    bool gameOver;
public:
    Snake();
    void drawMap();
    void keyControl();
    void gameLogic();
    bool isOver();
};

Snake::Snake(): gameOver(false), dir(2), len(3) {
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
    snakeX[1] = WIDTH / 2 - 1;
    snakeY[1] = HEIGHT / 2;
    snakeX[2] = WIDTH / 2 - 2;
    snakeY[2] = HEIGHT / 2;
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
}

void Snake::drawMap() {
    clearScreen();
    std::string screen;
    screen.append(WIDTH + 1, '#');
    screen += '\n';
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0 || j == WIDTH - 1) {
                screen += '#';
            }
            else if (j == snakeX[0] && i == snakeY[0]) {
                screen += '@';
            }
            else {
                bool isBody = false;
                for (int k = 1; k < len; k++) {
                    if (j == snakeX[k] && i == snakeY[k]) {
                        screen += '*';
                        isBody = true;
                        break;
                    }
                }
                if (!isBody) {
                    if (j == foodX && i == foodY) {
                        screen += '$';
                    }
                    else {
                        screen += ' ';
                    }
                }
            }
        }
        screen += '\n';
    }
    screen.append(WIDTH, '#');
    screen += "\n长度：" + std::to_string(len) + " 按ESC退出\n";
    std::cout << screen;
    std::cout.flush();
}

void Snake::keyControl() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 224 || ch == 0) {
            ch = _getch();
        }
        switch (ch) {
            case 72:
                if (dir != 1) dir = -1;
                break;
            case 80:
                if (dir != -1) dir = 1;
                break;
            case 75:
                if (dir != 2) dir = -2;
                break;
            case 77:
                if (dir != -2) dir = 2;
                break;
            case 27:
                gameOver = true;
                break;
        }
    }
}

void Snake::gameLogic() {
    for (int i = len - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }
    if (dir == -1) snakeY[0]--;
    if (dir == 1) snakeY[0]++;
    if (dir == -2) snakeX[0]--;
    if (dir == 2) snakeX[0]++;
    if (snakeX[0] < 0 || snakeX[0] >= WIDTH || snakeY[0] < 0 || snakeY[0] >= HEIGHT) {
        gameOver = true;
    }
    for (int i = 1; i < len; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = true;
        }
    }
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        len++;
        bool overlap;
        do {
            overlap = false;
            foodX = 1 + rand() % (WIDTH - 2);
            foodY = 1 + rand() % (HEIGHT - 2);
            for (int i = 0; i < len; i++) {
                if (snakeX[i] == foodX && snakeY[i] == foodY) {
                    overlap = true;
                    break;
                }
            }
        } while (overlap);
    }
}

bool Snake::isOver() {
    return gameOver;
}

int main() {
    system("chcp 65001 >nul");
    srand((unsigned)time(nullptr));
    Snake snake;
    DWORD lastMoveTime = GetTickCount();
    const int MOVE_DELAY = 400;  
    while (!snake.isOver()) {
        snake.keyControl();
        if (GetTickCount() - lastMoveTime >= MOVE_DELAY) {
            snake.gameLogic();
            lastMoveTime = GetTickCount();
        }
        snake.drawMap();
        Sleep(10);
    }
    std::cout << "游戏结束" << std::endl;
    system("pause");
    return 0;
}