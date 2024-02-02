

#include "TXLib.h"

 struct ButtonStart
 {
  int x;
  int y;
  int w;
  int h;
  void draw.start()
 {
  txSetColor(TX_RED);
  txSetFillColor(TX_RED);
  txRectangle(x,y,x+w, y+h);
  txDrawText(520,240,830,285,"������");
 }
};

struct ButtonHelp
 {
  int x;
  int y;
  int w;
  int h;
  void draw.help()
 {
  txSetColor(TX_RED);
  txSetFillColor(TX_RED);
  txRectangle(x,y,x+w, y+h);
  txDrawText(520,360,830,415,"������")
 }
 };
struct ButtonExit
 {
  int x;
  int y;
  int w;
  int h;
  void draw.exit()
 {
  txSetColor(TX_RED);
  txSetFillColor(TX_RED);
  txRectangle(x,y,x+w, y+h);
  txDrawText(520,500,830,570,"�������")
 }
 };

 //txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Ending1, 0, 0, RGB(512, 68, 68));







int main()
   {
    txCreateWindow (1540, 800);



    int x1 = 400;int vx1 = 20;int y1 = 400;int vy1 = 20;

    int n_kadr = 0;

    ButtonStart btn_START = {500,225,850,300,"������"};
    Button btn_HELP = {500,340,850,430,"������"};
    Button btn_EXIT = {500,485,850,575,"�������"};

    HDC Ending1 =txLoadImage ("��������1.������.bmp");
    HDC Menu =txLoadImage ("����.bmp");
    HDC Location1 =txLoadImage ("�������.bmp");

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
      btn_START.draw();
      if(txMouseButtons() == 1 &&
          txMouseX() > btn.x && txMouseX() < btn.x + btn.w &&
          txMouseY() > btn.y && txMouseY() < btn.y + btn.h )
       {
        PAGE = "game";
       }
       if(txMouseButtons() == 1 &&
          txMouseX() > btn.x && txMouseX() < btn.x + btn.w &&
          txMouseY() > btn.y && txMouseY() < btn.y + btn.h )
       {
        PAGE = "game";
       }
        if(txMouseButtons() == 1 &&
          txMouseX() > btn.x && txMouseX() < btn.x + btn.w &&
          txMouseY() > btn.y && txMouseY() < btn.y + btn.h )
       {
        PAGE = "game";
       }







     }




     if(PAGE == "game")
     {
     txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Location1, 0, 0, RGB(512, 68, 68));
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


    }


     txEnd();
     txSleep(50);
    }


    txDeleteDC(Wiliam1);
    txDeleteDC(Wiliam2);

    txTextCursor (false);
    return 0;
    }
