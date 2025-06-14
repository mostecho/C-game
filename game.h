#ifndef GAME_H
#define GAME_H
#include <graphics.h>
#include <iostream>

using namespace std;

#define WIDTH 1280
#define HEIGTH 720

void startloadImg();
void startupScene(ExMessage *msg);
bool isInRect(ExMessage *msg, int x, int y, int w, int h);
void playGame();
void putgamebk();

enum MenuOp
{
    Start=1,     //开始按钮，进入关卡。
    Quit,       //结束按钮，退出游戏。
    Home       //主界面
};
enum DIR
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ZERO
};

#endif //GAME_H