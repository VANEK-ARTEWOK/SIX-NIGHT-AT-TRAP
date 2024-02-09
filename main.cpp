

#include "TXLib.h"
struct Door
 {
  int x5;
  int y5;
  int w5;
  int h5;
  const char*text;

  void draw()
 {
  txSetColor(TX_BLUE) ;
  txSetFillColor(TX_BLUE);
  txRectangle(x5,y5,x5+w5, y5+h5);
  txSetColor(TX_RED);
  txSetFillColor(TX_RED);
  txDrawText(520,240,830,285,"����");
 }
 struct Car
 {
  int x4;
  int y4;
  int w4;
  int h4;
  const char*text;

  void draw()
 {
  txTransparentBlt(txDC(),800 ,135  , 522, 171  ,Car, 0, 0, TX_WHITE);
  txDrawText(800,135,1300,330,"�����");
 }
struct Gay
 {
  int x;
  int y;
  int w;
  int h;


  void draw()
 {

  txTransparentBlt(txDC(), x, y , 180, 309  ,Wiliam, 180*n_kadr, 0, RGB(237, 28, 36));

 }
 struct ButtonStart
 {
  int x1;
  int y1;
  int w1;
  int h1;
  const char*text;

  void draw()
 {
  txSetColor(RGB(163, 73, 164)) ;
  txSetFillColor(RGB (163, 73, 164));
  txRectangle(x1,y1,x1+w1, y1+h1);
  txSetColor(TX_WHITE);
  txSetFillColor(TX_WHITE);
  txDrawText(520,240,830,285,"������");
 }
};

struct ButtonHelp
 {
  int x2;
  int y2;
  int w2;
  int h2;
  const char*text;
   void draw()
  {
   txSetColor(RGB(163, 73, 164));
   txSetFillColor(RGB(163, 73, 164));
   txRectangle(x2,y2,x2+w2, y2+h2);
   txSetColor(TX_WHITE);
   txSetFillColor(TX_WHITE);
   txDrawText(520,360,830,415,"������");
  }
 };
struct ButtonExit
 {
  int x3;
  int y3;
  int w3;
  int h3;
  const char*text;
   void draw()
  {
   txSetColor(RGB(163, 73, 164));
   txSetFillColor(RGB(163, 73, 164));
   txRectangle(x3,y3,x3+w3, y3+h3);
   txSetColor(TX_WHITE);
   txSetFillColor(TX_WHITE);
   txDrawText(520,500,830,570,"�������");
  }
};

 //txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Ending1, 0, 0, RGB(512, 68, 68));







int main()
   {
    txCreateWindow (1540, 800);

    ButtonStart btn_start = {495,215,855-495,300-215,"������"};
    ButtonHelp btn_help = {495,345,855-495,432-345,"������"};
    ButtonExit btn_exit = {495,485,855-495,580-485,"�������"};

    Gay btn_gay = {643,486,60,100};

    ButtonHelp btn_door = {88,345,100,100,"����"};
    ButtonExit btn_car = {900,290,366,120,"�����"};

    int x = 400;int vx = 20;int y = 400;int vy = 20;

    int n_kadr = 0;


    HDC Ending1 =txLoadImage ("��������1.������.bmp");
    HDC Menu =txLoadImage ("����.bmp");
    HDC Location1 =txLoadImage ("�������.bmp");
    HDC �elp =txLoadImage ("������.bmp");
    HDC Location = Location1;
    HDC Wiliam1 =txLoadImage ("���������/��������.������.������.bmp");
    HDC Wiliam2 =txLoadImage ("���������/��������.������.�����.bmp");
    HDC Wiliam = Wiliam1;

    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);

    string PAGE = "menu";



  while(true)
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
          txMouseX() > btn_start.x1 && txMouseX() < btn_start.x1 + btn_start.w1 &&
          txMouseY() > btn_start.y1 && txMouseY() < btn_start.y1 + btn_start.h1 )
       {
        PAGE = "minigame";
       }
       if(txMouseButtons() == 1 &&
          txMouseX() > btn_help.x2 && txMouseX() < btn_help.x2 + btn_help.w2 &&
          txMouseY() > btn_help.y2 && txMouseY() < btn_help.y2 + btn_help.h2 )
       {
        PAGE = "help";
       }
        if(txMouseButtons() == 1 &&
          txMouseX() > btn_exit.x3 && txMouseX() < btn_exit.x3 + btn_exit.w3 &&
          txMouseY() > btn_exit.y3 && txMouseY() < btn_exit.y3 + btn_exit.h3 )
       {
        PAGE = "game";
       }
     }
    if(PAGE == "help")
     {
      txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Help, 0, 0, RGB(512, 68, 68));
     }


     if(PAGE == "minigame")
     {
     txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Location1, 0, 0, RGB(512, 68, 68));







     n_kadr +=1;
     if(n_kadr >=4)n_kadr =0;

     if(GetAsyncKeyState ('S'))
    {
     y = y + vy;

    }
     if(GetAsyncKeyState ('W'))
    {
     y = y - vy;

    }
     if(GetAsyncKeyState ('A'))
    {

     Wiliam = Wiliam1;
     x = x - vx;

    }
     if(GetAsyncKeyState ('D'))
    {

     Wiliam=Wiliam2;
     x = x + vx;
    }


    }


     txEnd();
     txSleep(50);
    }


    txDeleteDC(Wiliam1);
    txDeleteDC(Wiliam2);

    txTextCursor (false);
    return 0;
    }
