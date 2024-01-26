

#include "TXLib.h"

int main()
   {
    txCreateWindow (1540, 800);

    int y = 300;int vy = 20;int x = 400;int vx = 20;
    int x1 = 400;int vx1 = 20;int y1 = 400;int vy1 = 20;
    int x2 = 400;int vx2 = 20;int y2 = 400;int vy2 = 20;
    int n_kadr = 0;



    HDC Wiliam1 =txLoadImage ("персонажи/фиолетыч.спрайт.правый.bmp");
    HDC Wiliam2 =txLoadImage ("персонажи/фиолетыч.спрайт.левый.bmp");
    HDC Wiliam = Wiliam1;
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
  while(true)
    {
     txSetFillColor (TX_BLACK);
     txClear();

     txBegin();
     txSetFillColor (TX_RED);
     txCircle(x, y, 50);
     x = x + vx;
     y = y + vy;


     if(y > 800-50 or y < 50)
    {
        vy =- vy;
    }
     if(y > 1540-50 or y < 50)
    {
     vx =- vx;

    }
     txSetFillColor (TX_ORANGE);

     txTransparentBlt(txDC(), x1, y1 , 180, 309  ,Wiliam, 180*n_kadr, 0, RGB(237, 28, 36));

     n_kadr +=1;
     if(n_kadr >=4)n_kadr =0;

     if(GetAsyncKeyState ('S'))
    {
     y1 = y1 + vy1;

    }
     if(GetAsyncKeyState ('W'))
    {
     y1 = y1 - vy1;

    }
     if(GetAsyncKeyState ('A'))
    {

     Wiliam = Wiliam1;
     x1 = x1 - vx1;

    }
     if(GetAsyncKeyState ('D'))
    {

     Wiliam=Wiliam2;
     x1 = x1 + vx1;
    }


     txEnd();
     txSleep(10);
    }


    txDeleteDC(Wiliam1);
    txDeleteDC(Wiliam2);

    txTextCursor (false);
    return 0;
    }

