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


    void draw()
    {
        txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_WHITE);

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
    HDC image_r;
    HDC image_l;
    HDC image;
    int n_kadr;

    void draw()
    {
        txTransparentBlt(txDC(), x, y , w, h , image, 57*n_kadr, 0, RGB(63, 72, 204));
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

struct Canister
{
    int x;
    int y;
    int w;
    int h;
    HDC image;

    void draw()
    {
     txTransparentBlt(txDC(), x, y , w, h , image, 0, 0, (TX_WHITE));

    }
};
struct Axe
{
    int x;
    int y;
    int w;
    int h;
    HDC image;

    void draw()
    {
     txTransparentBlt(txDC(), x, y , w, h , image, 0, 0, (TX_WHITE));


    }
};

struct Laugh
{
    int x;
    int y;
    int w;
    int h;
    const char* text;

    void draw()
    {
        txSetColor(TX_GRAY);
        txSetFillColor(TX_GRAY);
        txDrawText(x,y,x+w,y+h,text);

    }
};



int main()
{
    txCreateWindow (1540, 800);

    Axe axe ={50,281,225,225,txLoadImage("топор.bmp")};
    Canister canister ={410,620,225,267,txLoadImage("канистраа.bmp")};


    Button btn_start = {495,215,150,50,"»√–ј“№"};
    Button btn_help = {495,345,150,50,"ѕќћќў№"};
    Button btn_exit = {495,485,150,50,"—¬јЋ»“№"};

    Gay gay = {643,486,57,95,10,10,txLoadImage("персонажи/фиолетыч.спрайт.правый.bmp"), txLoadImage("персонажи/фиолетыч.спрайт.левый.bmp"), txLoadImage("персонажи/фиолетыч.спрайт.левый.bmp"),0};

    Door door = {88,200,100,100,txLoadImage ("дверь.bmp")};
    Car car = {900,290,307,102,txLoadImage ("CAR.bmp")};

    HDC Ending3 =txLoadImage (" јЌ÷ќ¬ ј3.плоха€.bmp");
    HDC Ending2 =txLoadImage (" јЌ÷ќ¬ ј2.’ќ–ќЎјя.bmp");
    HDC Ending1 =txLoadImage (" јЌ÷ќ¬ ј1.Ћќ√» ј.bmp");

    HDC Menu =txLoadImage ("меню.bmp");

    HDC Axe =txLoadImage ("топор.bmp");
    HDC Canister =txLoadImage ("канистраа.bmp");
    Laugh laugh = {1170,550,1455,650,"¬≈–Ќ”“№ Ќј«јƒ"};
    HDC MACK =txLoadImage ("офис/ћј— ј .bmp");
    HDC Office =txLoadImage ("офис/ќ‘»—bmp.bmp");
    HDC Office_LEFT =txLoadImage ("офис/ќ‘»—2bmp.bmp");
    HDC Office_RIGHT =txLoadImage ("офис/ќ‘»—3.bmp");
    HDC Office_DOOR =txLoadImage ("офис/ќ‘»—2дверь.bmp");
    HDC Fon_Location = Office;


    HDC Dead =txLoadImage ("смерть.bmp");
    HDC Location1 =txLoadImage ("локаци€.bmp");
    HDC spr =txLoadImage ("ѕќћќў№.bmp");
    HDC Location = Location1;

    HDC KAM1 =txLoadImage ("камеры/сцена.пусто.bmp");
    HDC KAM2 =txLoadImage ("камеры/зал.пусто.bmp");
    HDC KAM3 =txLoadImage ("камеры/бухта1.bmp");
    HDC KAM4 =txLoadImage ("камеры/запчасти.пусто.bmp");
    HDC KAM5 =txLoadImage ("камеры/веселье.пусто.bmp");
    HDC KAM6 =txLoadImage ("камеры/туалет.пусто.bmp");
    HDC KAM7 =txLoadImage ("камеры/каридор.пусто.bmp");
    HDC KAM8 =txLoadImage ("камеры/склад.пусто.bmp");
    HDC KAMvent1 =txLoadImage ("камеры/вентел€цы€.пусто.bmp");
    HDC KAMvent2 =txLoadImage ("камеры/вентел€цы€2.пусто.bmp");

    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);

    string PAGE = "menu";

    bool door_open = true;


    while(PAGE != "exit")
    {
        txSetFillColor (TX_BLACK);
        txClear();

        txBegin();

        if(PAGE == "menu")
        {
            txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Menu, 0, 0, RGB(512, 68, 68));


            btn_help.draw();
            btn_exit.draw();
            btn_start.draw();

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

            gay.n_kadr +=1;
            if(gay.n_kadr >=4) gay.n_kadr =0;

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
                gay.image = gay.image_l;
                gay.x = gay.x - gay.vx;
            }
            if(GetAsyncKeyState ('D'))
            {
                gay.image = gay.image_r;
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
            if(GetAsyncKeyState (VK_ESCAPE))
            {
                PAGE = "menu";
            }

        }
        if(PAGE == "game")
        {

         txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Fon_Location, 0, 0, RGB(237, 0, 0));


         if(GetAsyncKeyState (VK_ESCAPE))
          {
                PAGE = "menu";
          }

        if(GetAsyncKeyState ('S'))
        {
           Fon_Location = Office_RIGHT;
        }



          if(GetAsyncKeyState ('O'))
          {
          Fon_Location = Office;

          }
        if(GetAsyncKeyState ('W'))
        {
            Fon_Location = Office;
        }


        if(GetAsyncKeyState ('D'))
         {
            Fon_Location = Office;
         }

        if(GetAsyncKeyState ('A') && !door_open)
         {
            Fon_Location = Office_DOOR;

         }
        if(GetAsyncKeyState ('A') && door_open)
         {
            Fon_Location = Office_LEFT;
         }


          if(GetAsyncKeyState ('N'))
           {
            Fon_Location = KAM1 ;
           }





        if(Fon_Location == Office_LEFT)
        {
           if(GetAsyncKeyState ('K') )
            {
                Fon_Location = Office_DOOR;
                door_open = false;
            }
           if(GetAsyncKeyState ('J') )
            {
                Fon_Location = Office_LEFT;
                door_open = true;
            }
           if(GetAsyncKeyState ('D'))
            {
                Fon_Location = Office;
            }  ;
        }
        if(Fon_Location == Office_DOOR)
        {
           if(GetAsyncKeyState ('K') )
            {
                Fon_Location = Office_DOOR;
                door_open = false;
            }
           if(GetAsyncKeyState ('J') )
            {
                Fon_Location = Office_LEFT;
                door_open = true;
            }
           if(GetAsyncKeyState ('D'))
            {
                Fon_Location = Office;
            }  ;
        }

         if(Fon_Location == Office_RIGHT)
        {

           canister.draw();
           axe.draw();
            if(GetAsyncKeyState ('W'))
           {
            Fon_Location = Office;
           }
            if(GetAsyncKeyState ('L'))
            {
             Fon_Location = MACK;
            }

            if(txMouseButtons() == 1 &&
              txMouseX() > axe.x && txMouseX() < axe.x + axe.w &&
              txMouseY() > axe.y && txMouseY() < axe.y + axe.h )
             {
                PAGE = "end3";
             }

           if(txMouseButtons() == 1 &&
              txMouseX() > canister.x && txMouseX() < canister.x + canister.w &&
              txMouseY() > canister.y && txMouseY() < canister.y + canister.h )
             {
                PAGE = "end2";
             }
         }

         if(Fon_Location == KAM1)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }
          if(Fon_Location == KAM2)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }


         if(Fon_Location == KAM3)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }
          if(Fon_Location == KAM2)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }

         if(Fon_Location == KAM4)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }
          if(Fon_Location == KAM5)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }

         if(Fon_Location == KAM6)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }
          if(Fon_Location == KAM7)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }
          if(Fon_Location == KAM8)
           {
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }

         if(Fon_Location == KAMvent1)
           {
             laugh.draw();
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }
          if(Fon_Location == KAMvent2)
           {
             laugh.draw();
             if(GetAsyncKeyState ('1'))
              {
               Fon_Location = KAM1 ;
              }
             if(GetAsyncKeyState ('2'))
              {
               Fon_Location = KAM2 ;
              }
             if(GetAsyncKeyState ('3'))
              {
               Fon_Location = KAM3 ;
              }
             if(GetAsyncKeyState ('4'))
              {
               Fon_Location = KAM4 ;
              }
             if(GetAsyncKeyState ('5'))
              {
               Fon_Location = KAM5 ;
              }
             if(GetAsyncKeyState ('6'))
              {
               Fon_Location = KAM6 ;
              }
             if(GetAsyncKeyState ('7'))
              {
               Fon_Location = KAM7 ;
              }
             if(GetAsyncKeyState ('8'))
              {
               Fon_Location = KAM8 ;
              }
             if(GetAsyncKeyState ('9'))
              {
               Fon_Location = KAMvent1 ;
              }
             if(GetAsyncKeyState ('0'))
              {
               Fon_Location = KAMvent2 ;
              }
             if(GetAsyncKeyState ('B'))
              {
               Fon_Location = Office ;
              }

           }





      }
     if(PAGE == "end1")
     {
         txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Ending1, 0, 0, RGB(512, 68, 68));
         if(GetAsyncKeyState (VK_ESCAPE))
         {
                PAGE = "menu";
         }
     }
     if(PAGE == "end2")
     {
         txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Ending2, 0, 0, RGB(512, 68, 68));
         if(GetAsyncKeyState (VK_ESCAPE))
         {
                PAGE = "menu";
         }
     }
     if(PAGE == "end3")
     {
         txTransparentBlt(txDC(),0 ,0  , 1540, 800  ,Ending3, 0, 0, RGB(512, 68, 68));
         if(GetAsyncKeyState (VK_ESCAPE))
         {
                PAGE = "menu";
         }
     }
        txEnd();
        txSleep(50);
    }
    txDeleteDC(gay.image);
    txDeleteDC(gay.image_l);
    txDeleteDC(gay.image_r);

    txTextCursor (false);
    txDisableAutoPause();
    return 0;
}
