#include "game.h"

IMAGE bk;
IMAGE start;
IMAGE quit;
IMAGE gamebk;
IMAGE dimian;
IMAGE setting;
MenuOp menuState=Home;
POINT playerPos={30,450};

int main()
{
    initgraph(WIDTH,HEIGTH);  //创建窗口 1280x720
    startloadImg();                       //加载主界面

    while (true) {
        ExMessage msg={0};
        //处理消息，不断地获取鼠标消息。
        while (peekmessage(&msg,EX_MOUSE))
        {
            BeginBatchDraw();    //双缓存
            startupScene(&msg);
            EndBatchDraw();      //双缓存
            if (menuState == Start)
            {
                while (menuState == Start)
                {
                    BeginBatchDraw();
                    putgamebk();
                    setfillcolor(WHITE);
                    solidcircle(playerPos.x,playerPos.y,30);
                    EndBatchDraw();
                    palyGame();
                    Sleep(50);
                }
            }
        }
    }
}

void startloadImg()
{

    loadimage(&bk, _T("image/background.png"),WIDTH,HEIGTH);  //背景
    loadimage(&start, _T("image/start.jpg"));  //开始游戏
    loadimage(&quit, _T("image/quit.jpg"));  //退出游戏
    loadimage(&gamebk, _T("image/gamebk.jpg"),1280,720);
    loadimage(&dimian, _T("image/dimian.jpg"));
    loadimage(&setting, _T("image/setting.png"),40,40);

    putimage(0,0, &bk);
    putimage(WIDTH/2-88, HEIGTH/2-50,170,50, &start,0,0);
    putimage(WIDTH/2-88, HEIGTH/2+50,170,50, &quit,0,0);
}

void palyGame()
{
    int kx=0,ky=0;
    int sheep=10;
    DIR currentDir =ZERO;
    if ((GetAsyncKeyState('W') || GetAsyncKeyState('w'))
        && currentDir != 's')
    {
        currentDir = UP;
    }
    else if ((GetAsyncKeyState('S') || GetAsyncKeyState('s'))
        && currentDir != 'w')
    {
        currentDir = DOWN;
    }
    else if ((GetAsyncKeyState('A') || GetAsyncKeyState('a'))
        && currentDir != 'd')
    {
        currentDir = LEFT;
    }
    else if ((GetAsyncKeyState('D') || GetAsyncKeyState('d'))
        && currentDir !='a')
    {
        currentDir = RIGHT;
    }

    switch (currentDir)
    {
        case UP:ky = -1;
            break;
        case DOWN:ky = 1;
            break;
        case LEFT:kx = -1;
            break;
        case RIGHT:kx = 1;
            break;
        default:
            break;
    }
    if (playerPos.y+sheep*ky<=450&&playerPos.x+sheep*kx>20)
    {
        playerPos.x+=sheep*kx;
        playerPos.y+=sheep*ky;
    }
}
//启动场景
void startupScene(ExMessage *msg)
{
    //鼠标左边点击切换场景
    if (menuState==Home)
    {
        if(isInRect(msg,550,310,170,50)&&msg->message == WM_LBUTTONUP)
        {
            menuState=Start;
            putgamebk();
        }
        else if (isInRect(msg,550,410,170,50)&&msg->message == WM_LBUTTONUP)
        {
            menuState=Quit;
            exit(0);
        }
    }
}

bool isInRect(ExMessage *msg, int x, int y, int w, int h)
{
    if (msg->x>x&&msg->x<w+x&&msg->y>y&&msg->y<h+y)
        return true;
    else
        return false;
}

void putgamebk()
{
    cleardevice();
    putimage(0,0,&gamebk);
    putimage(0,0,&setting);
    for (int i=0;i<20;i++) //铺设地面砖块，右边的在窗口外面用于后面的场景
    {
        for (int j=0;j<5;j++) //5层高的地面
        {
            putimage(i*120,(10+j)*48, &dimian);
        }
    }
}