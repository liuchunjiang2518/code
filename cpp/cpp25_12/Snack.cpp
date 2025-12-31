#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

#define WIDTH 25
#define HEIGHT 12

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
    system("cls");
    for (int i = 0; i <= WIDTH; i++) {
        std::cout << '#';
    }
    std::cout << std::endl;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0;j < WIDTH; j++) {
            if (j == 0 || j == WIDTH - 1) {
                std::cout << '#';
            }
            else if (j == snakeX[0] && i == snakeY[0]) {
                std::cout << '@';
            }
            else {
                bool isBody = false;
                for (int k = 1; k < len; k++) {
                    if (j == snakeX[k] && i == snakeY[k]) {
                        std::cout << '*';
                        isBody = true;
                        break;
                    }
                }
                if (!isBody) {
                    if (j == foodX && i == foodY) {
                        std::cout << '$';
                    }
                    else {
                        std::cout << ' ';
                    }
                }
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < WIDTH; i++) {
        std::cout << '#';
    }
    std::cout << std::endl;
    std::cout << "长度：" << len << "按ESC退出" << std::endl;
}

void Snake::keyControl() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 224 || ch == 0) {
            ch = _getch();
        }
        switch (ch) {
            case 72:
                if (dir != 1) {
                    dir = -1;
                }
                break;
            case 80:
                if (dir != -1) {
                    dir = 1;
                }
                break;
            case 75:
                if (dir != 2) {
                    dir = -2;
                }
                break;
            case 77:
                if (dir != -2) {
                    dir = 2;
                }
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
    if (dir == -1) {
        snakeY[0]--;
    }
    if (dir == 1) {
        snakeY[0]++;
    }
    if (dir == -2) {
        snakeX[0]--;
    }
    if (dir == 2) {
        snakeX[0]++;
    }
    if (snakeX[0] < 0 || snakeX[0] >= WIDTH || snakeY[0] <0 || snakeY[0] >= HEIGHT) {
        gameOver = true;
    }
    for (int i = 1; i < len; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = true;
        }
    }
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        len++;
        bool flag;
        do {
            flag = true;
            foodX = rand() % WIDTH;
            foodY = rand() % HEIGHT;
            for (int i = 0; i < len; i++) {
                if (snakeX[i] == foodX && snakeY[i] == foodY) {
                    flag = false;
                }
            }
        } while (!flag);
    }
}

bool Snake::isOver() {
    return gameOver;
}

int main() {
    system("chcp 65001 >nul");
    Snake snake;
    while (!snake.isOver()) {
        snake.drawMap();
        snake.keyControl();
        snake.gameLogic();
        Sleep(180);
    }
    std::cout << "游戏结束" << std::endl;
    system("pause");
    return 0;
}