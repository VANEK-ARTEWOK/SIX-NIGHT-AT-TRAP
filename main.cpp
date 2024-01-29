

#include "TXLib.h"


 void drawLocation1 (HDC Location1)
{
 txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Location1, 0, 0, RGB(512, 68, 68));
}

void drawEnding1 (HDC Ending1)
{
 txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Ending1, 0, 0, RGB(512, 68, 68));

}

void drawMenu (HDC Menu)
{
 txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Menu, 0, 0,RGB(512, 68, 68));
}



int main()
   {
    txCreateWindow (1540, 800);


    int x1 = 400;int vx1 = 20;int y1 = 400;int vy1 = 20;

    int n_kadr = 0;

    HDC Ending1 =txLoadImage ("КАНЦОВКА1.ЛОГИКА.bmp");
    HDC Menu =txLoadImage ("меню.bmp");
    HDC Location1 =txLoadImage ("локация.bmp");

    HDC Location = Location1;
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

     txSetFillColor (TX_ORANGE);
     drawLocation1(Location1);
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

     if(vx1>140 and vy1>250)
    {
     Location = Menu;
    }


     if(vx1>1060 and vy1>250)
    {
     Location=Ending1;
    }

     if(Location=Menu)
    {
     drawMenu(Menu);

    }


     if(Location=Ending1)
    {
     drawEnding1(Ending1);
    }
     if(Location=Location1)
    {
     drawLocation1(Location1);
    }
     txEnd();
     txSleep(50);
    }


    txDeleteDC(Wiliam1);
    txDeleteDC(Wiliam2);

    txTextCursor (false);
    return 0;
    }
