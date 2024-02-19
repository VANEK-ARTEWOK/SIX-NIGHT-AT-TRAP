#include "TXLib.h"

struct Door
{
    int x;
    int y;
    int w;
    int h;
    HDC image;

    void draw()
    {
     txTransparentBlt(txDC(), x, y , w, h , image, 0, 0, RGB(237, 28, 36));
    }
};

struct Car
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    const char*text;

    void draw()
    {
        txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_WHITE);
        txDrawText(x,y,x+w,y+h,text);
    }
};

struct Gay
{
    int x;
    int y;
    int w;
    int h;
    int vx;
    int vy;
    HDC image;
    int n_kadr;

    void draw()
    {
        txTransparentBlt(txDC(), x, y , w, h , image, 55*n_kadr, 0, RGB(237, 28, 36));
    }
};

struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;

    void draw()
    {

        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txDrawText(x,y,x+w, y+h,text);
    }
};

 //txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Ending1, 0, 0, RGB(512, 68, 68));







int main()
{
    txCreateWindow (1540, 800);

    Button btn_start = {495,215,150,50,"ÈÃÐÀÒÜ"};
    Button btn_help = {495,345,150,50,"ÏÎÌÎÙÜ"};
    Button btn_exit = {495,485,150,50,"ÑÂÀËÈÒÜ"};

    HDC Wiliam1 =txLoadImage ("ïåðñîíàæè/ôèîëåòû÷.ñïðàéò.ïðàâûé.bmp");
    HDC Wiliam2 =txLoadImage ("ïåðñîíàæè/ôèîëåòû÷.ñïðàéò.ëåâûé.bmp");
    HDC Wiliam = Wiliam1;

    Gay gay = {643,486,60,100,10,10,Wiliam,0};

    Door door = {88,200,100,100,txLoadImage ("äâåðü.bmp")};
    Car car = {900,290,307,102,txLoadImage ("CAR.bmp"),"ÓÕÀÒÜ"};

    //int btn_gay.x = 400 ;int btn_gay.vx = 20; int btn_gay.y = 400; int btn_gay.vy = 20;

    int n_kadr = 0;


    HDC Ending1 =txLoadImage ("ÊÀÍÖÎÂÊÀ1.ËÎÃÈÊÀ.bmp");
    HDC Menu =txLoadImage ("ìåíþ.bmp");
    HDC Office =txLoadImage ("ÎÔÈÑbmp.bmp");
    HDC Location1 =txLoadImage ("ëîêàöèÿ.bmp");
    HDC spr =txLoadImage ("ÏÎÌÎÙÜ.bmp");
    HDC Location = Location1;


    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);

    string PAGE = "menu";



    while(PAGE != "exit")
    {
        txSetFillColor (TX_BLACK);
        txClear();

        txBegin();

        if(PAGE == "menu")
        {
            txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Menu, 0, 0, RGB(512, 68, 68));
            btn_start.draw();
            btn_help.draw();
            btn_exit.draw();
            if(txMouseButtons() == 1 &&
              txMouseX() > btn_start.x && txMouseX() < btn_start.x + btn_start.w &&
              txMouseY() > btn_start.y && txMouseY() < btn_start.y + btn_start.h )
            {
                PAGE = "minigame1";
            }

            if(txMouseButtons() == 1 &&
              txMouseX() > btn_help.x && txMouseX() < btn_help.x + btn_help.w &&
              txMouseY() > btn_help.y && txMouseY() < btn_help.y + btn_help.h )
            {
                PAGE = "help";
            }
            if(txMouseButtons() == 1 &&
              txMouseX() > btn_exit.x && txMouseX() < btn_exit.x + btn_exit.w &&
              txMouseY() > btn_exit.y && txMouseY() < btn_exit.y + btn_exit.h )
            {
                PAGE = "exit";
            }
        }
        if(PAGE == "help")
        {
            txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,spr, 0, 0, RGB(512, 68, 68));
            if(GetAsyncKeyState (VK_ESCAPE))
            {
                PAGE = "menu";
            }

        }


        if(PAGE == "minigame1")
        {
            txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Location1, 0, 0, RGB(512, 68, 68));
            door.draw();
            gay.draw();
            car.draw();

            n_kadr +=1;
            if(n_kadr >=4) n_kadr =0;

            if(GetAsyncKeyState ('S'))
            {
                gay.y = gay.y + gay.vy;
            }
            if(GetAsyncKeyState ('W'))
            {
                gay.y = gay.y - gay.vy;
            }
            if(GetAsyncKeyState ('A'))
            {
                Wiliam = Wiliam1;
                gay.x = gay.x - gay.vx;
            }
            if(GetAsyncKeyState ('D'))
            {
                Wiliam=Wiliam2;
                gay.x = gay.x + gay.vx;
            }
            if(gay.x>door.x && gay.x<door.x+door.w &&
               gay.y>door.y && gay.y<door.y+door.h)
            {
                PAGE = "game";

            }
            if(gay.x>car.x && gay.x<car.x+car.w &&
               gay.y>car.y && gay.y<car.y+car.h)
            {
                PAGE = "end1";

            }


        }
        if(PAGE == "game")
        {
         txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Office, 0, 0, RGB(512, 68, 68));
        }
         if(PAGE == "end1")
        {
         txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Ending1, 0, 0, RGB(512, 68, 68));
        }
        txEnd();
        txSleep(50);
    }


    txDeleteDC(Wiliam1);
    txDeleteDC(Wiliam2);

    txTextCursor (false);
    txDisableAutoPause();
    return 0;
}
