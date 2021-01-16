 #include<stdio.h>
#include<graphics.h>
struct node
{
    int color;
    int x1,x2,y1,y2;
    struct node *next;
};
void check_color(POINT *cursor_pos);
void pencil(POINT *cursor_pos,struct node **Start);
void identify_shape(POINT *cursorpos,struct node **Start);
void put(struct node **Start,int x1,int y1,int x2,int y2,int color);
void make_circle(POINT *cursor_pos,struct node **Start);
void make_rectangle(POINT *cursor_pos,struct node **Start);
void make_line(POINT *cursor_pos,struct node **Start);
void text(POINT *cursor_pos,struct node **Start);
void checkshape(POINT *cursor_pos,struct node *Start);
void fil(POINT *cursor_pos,struct node **Start);
void set_panel(void);
void triangle(POINT *cursor_pos,struct node **Start);
main()
{
struct node *Start=NULL;
int gd=0,gm;
initgraph(&gd,&gm,"");
POINT cursor_pos;
set_panel();
pencil(&cursor_pos,&Start);
    closegraph();
}
void check_color(POINT *cursor_pos)
{
    GetCursorPos(cursor_pos);
    if(cursor_pos->x>=0&&cursor_pos->x<=30&&cursor_pos->y>=10&&cursor_pos->y<=65)
        setcolor(0);
    else if(cursor_pos->x>=40&&cursor_pos->x<=70&&cursor_pos->y>=10&&cursor_pos->y<=65)
        setcolor(1);
     else if(cursor_pos->x>=80&&cursor_pos->x<=110&&cursor_pos->y>=10&&cursor_pos->y<=65)
        setcolor(2);
      else if(cursor_pos->x>=120&&cursor_pos->x<=150&&cursor_pos->y>=10&&cursor_pos->y<=65)
        setcolor(3);
       else if(cursor_pos->x>=160&&cursor_pos->x<=190&&cursor_pos->y>=10&&cursor_pos->y<=65)
        setcolor(4);
         else if(cursor_pos->x>=200&&cursor_pos->x<=230&&cursor_pos->y>=10&&cursor_pos->y<=65)
setcolor(5);
 else if(cursor_pos->x>=240&&cursor_pos->x<=270&&cursor_pos->y>=10&&cursor_pos->y<=65)
    setcolor(6);
  else if(cursor_pos->x>=280&&cursor_pos->x<=310&&cursor_pos->y>=10&&cursor_pos->y<=65)
    setcolor(7);
   else if(cursor_pos->x>=320&&cursor_pos->x<=350&&cursor_pos->y>=10&&cursor_pos->y<=65)
setcolor(8);
 else if(cursor_pos->x>=360&&cursor_pos->x<=390&&cursor_pos->y>=10&&cursor_pos->y<=65)
setcolor(9);
 else if(cursor_pos->x>=400&&cursor_pos->x<=430&&cursor_pos->y>=10&&cursor_pos->y<=65)
setcolor(10);
 else if(cursor_pos->x>=440&&cursor_pos->x<=470&&cursor_pos->y>=10&&cursor_pos->y<=65)
    setcolor(11);
  else if(cursor_pos->x>=480&&cursor_pos->x<=510&&cursor_pos->y>=10&&cursor_pos->y<=65)
setcolor(12);
 else if(cursor_pos->x>=520&&cursor_pos->x<=550&&cursor_pos->y>=10&&cursor_pos->y<=65)
setcolor(13);
 else if(cursor_pos->x>=560&&cursor_pos->x<=590&&cursor_pos->y>=10&&cursor_pos->y<=65)
setcolor(14);
 else if(cursor_pos->x>=600&&cursor_pos->x<=630&&cursor_pos->y>=10&&cursor_pos->y<=65)
setcolor(15);
}
void identify_shape(POINT *cursorpos,struct node **Start)
{

    GetCursorPos(cursorpos);
    delay(10);
if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>50&&cursorpos->y<100)
        pencil(cursorpos,Start);
else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>90&&cursorpos->y<140)
    fil(cursorpos,Start);
    else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>130&&cursorpos->y<180)
        text(cursorpos,Start);
    else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>170&&cursorpos->y<220)
    writeimagefile("paint with ug.jpeg");
 else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>210&&cursorpos->y<260)
 make_line(cursorpos,Start);
else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>250&&cursorpos->y<300)
make_rectangle(cursorpos,Start);
else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>290&&cursorpos->y<340)
make_circle(cursorpos,Start);
else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>330&&cursorpos->y<380)
{
    cleardevice();
    set_panel();

}
else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>370&&cursorpos->y<420){
cleardevice();
set_panel();
    readimagefile("paint with ug.jpeg",80,80,600,500);
}
else if(cursorpos->x>0&&cursorpos->x<100&&cursorpos->y>410&&cursorpos->y<460)
    triangle(cursorpos,Start);
}
void pencil(POINT *cursor_pos,struct node **Start)
{
    int x1,y1;
while(1)
{
       if(GetAsyncKeyState(VK_TAB))
 identify_shape(cursor_pos,Start);
     else if(GetAsyncKeyState(VK_SHIFT))
            check_color(cursor_pos);
          else if(GetAsyncKeyState(VK_LBUTTON))
    {
        GetCursorPos(cursor_pos);
        x1=cursor_pos->x;
        y1=cursor_pos->y;
        putpixel(x1-5,y1-20,getcolor());
    }
}
}

void put(struct node **Start,int x1,int y1,int x2,int y2,int color)
{ struct node *temp,*t;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->color=color;
    temp->next=NULL;
    temp->x1=x1;
    temp->x2=x2;
    temp->y1=y1;
    temp->y2=y2;
    if(*Start==NULL)
        *Start=temp;
        else
        {
            t=*Start;
            while(t->next!=NULL)
                t=t->next;
            t->next=temp;
        }
}
void make_circle(POINT *cursor_pos,struct node **Start)
{ int color;
     int i=0,j=0,x1,y1,x2,y2,x,y;
     while(1)
     {
           if(GetAsyncKeyState(VK_TAB))
            identify_shape(cursor_pos,Start);
          else if(GetAsyncKeyState(VK_SHIFT))
            check_color(cursor_pos);
        else if(GetAsyncKeyState(VK_LBUTTON)&&i==0)
    {
        GetCursorPos(cursor_pos);
        x1=cursor_pos->x;
        y1=cursor_pos->y;
        i++;
    }
    else if(GetAsyncKeyState(VK_LBUTTON))
    { if(0<j){
        color=getcolor();
        setcolor(getbkcolor());
        circle(x1+(x2-x1)/2,y1+(y2-y1)/2,((x2-x1)/2));
        setcolor(color);
        }
                 GetCursorPos(cursor_pos);
          x2=cursor_pos->x;
        y2=cursor_pos->y;
        circle(x1+(x2-x1)/2,y1+(y2-y1)/2,((x2-x1)/2));
        j++;
    }
    else if(!GetAsyncKeyState(VK_LBUTTON)&&i==1)
    { setcolor(getbkcolor());
        circle(x1+(x2-x1)/2,y1+(y2-y1)/2,((x2-x1)/2));
        setcolor(color);
        GetCursorPos(cursor_pos);
          x2=cursor_pos->x;
        y2=cursor_pos->y;
        setcolor(color);
        circle(x1+(x2-x1)/2,y1+(y2-y1)/2,((x2-x1)/2));
put(Start,x1,y1,x2,y2,getcolor());
        i=0;j=0;
    }
    delay(50);
     }
}
void make_rectangle(POINT *cursor_pos,struct node **Start)
{    int color;
     int i=0,y=0,x1,x2,y1,y2;
     while(1)
     {
         GetCursorPos(cursor_pos);
         if(GetAsyncKeyState(VK_TAB))
            identify_shape(cursor_pos,Start);
        else if(GetAsyncKeyState(VK_SHIFT))
            check_color(cursor_pos);

         else if(GetAsyncKeyState(VK_LBUTTON)&&i==0)
    {
        x1=cursor_pos->x;
        y1=cursor_pos->y;
        i++;
    }
    else if(GetAsyncKeyState(VK_LBUTTON))
    {  if(y>0){
        color=getcolor();
        setcolor(getbkcolor());
        rectangle(x1,y1,x2,y2);
        setcolor(color);
    }
    GetCursorPos(cursor_pos);
        x2=cursor_pos->x;
        y2=cursor_pos->y;
        rectangle(x1,y1,x2,y2);
    y++;
    }
    else if(!GetAsyncKeyState(VK_LBUTTON)&&i==1)
    {
        setcolor(getbkcolor());
        rectangle(x1,y1,x2,y2);
        setcolor(color);
        GetCursorPos(cursor_pos);
        x2=cursor_pos->x;
        y2=cursor_pos->y;
        i++;
    }
    if(i==2){
            setcolor(getbkcolor());
     rectangle(x1,y1,x2,y2);
    setcolor(color);
       rectangle(x1,y1,x2,y2);
       put(Start,x1,y1,x2,y2,getcolor());
    i=0;
    y=0;}
    delay(50);

    }

}
void make_line(POINT *cursor_pos,struct node **Start)
{ int i=0,x1,x2,y1,y2,color;
    while(1)
{ color=getcolor();
  GetCursorPos(cursor_pos);
  if(GetAsyncKeyState(VK_TAB))
            identify_shape(cursor_pos,Start);
    else if(GetAsyncKeyState(VK_SHIFT))
            check_color(cursor_pos);
    else if(GetAsyncKeyState(VK_LBUTTON)&&i==0)
    { line(x1-5,y1-20,x2-5,y2-20);
        x1=cursor_pos->x;
        y1=cursor_pos->y;
        i++;
    }
    else if(!GetAsyncKeyState(VK_LBUTTON)&&i==1)
    {
        setcolor(getbkcolor());
     line(x1-5,y1-20,x2-5,y2-20);
     setcolor(color);
        GetCursorPos(cursor_pos);
        x2=cursor_pos->x;
        y2=cursor_pos->y;
        i++;
    }
    else if(GetAsyncKeyState(VK_LBUTTON))
    { setcolor(getbkcolor());
     line(x1-5,y1-20,x2-5,y2-20);
     setcolor(color);
              GetCursorPos(cursor_pos);
        x2=cursor_pos->x;
        y2=cursor_pos->y;
           line(x1-5,y1-20,x2-5,y2-20);
    }
 if(i==2){
            setcolor(getbkcolor());
     line(x1-5,y1-20,x2-5,y2-20);
    setcolor(color);
        line(x1-5,y1-20,x2-5,y2-20);
    i=0;
    }
    delay(50);
    }
}
void text(POINT *cursor_pos,struct node **Start)
{ char text[20],ch;
int i=0,x,y,color;
   if(GetAsyncKeyState(VK_TAB))
            identify_shape(cursor_pos,Start);
 else if(GetAsyncKeyState(VK_SHIFT))
            check_color(cursor_pos);

     outtextxy(550,240,"Enter text");
    while(1)
    {
        ch=getch();
        if(ch==13)
           {
               text[i]=NULL;
               break;
           }
           text[i]=ch;

        i++;
    }
    outtextxy(550,280,text);
    outtextxy(500,300,"enter x & y axis");
 while(1){
        if(GetAsyncKeyState(VK_LBUTTON)){
GetCursorPos(cursor_pos);
    outtextxy(cursor_pos->x,cursor_pos->y,text);
    color=getcolor();
     setcolor(getbkcolor());
     outtextxy(550,240,"Enter text");
     outtextxy(550,280,text);
    outtextxy(500,300,"enter x & y axis");
    setcolor(color);
    break;}
    }
    pencil(cursor_pos,Start);
}
void checkshape(POINT *cursor_pos,struct node *Start)
{
    while(Start!=NULL)
    {
        if(Start->x1<=cursor_pos->x&&Start->x2>=cursor_pos->x&&Start->y1<=cursor_pos->y&&Start->y2>=cursor_pos->y)
    {
        setfillstyle(SOLID_FILL,getcolor());
        floodfill(cursor_pos->x,cursor_pos->y,Start->color);
        break;
    }
    Start=Start->next;
    }

}
void fil(POINT *cursor_pos,struct node **Start)
{
    while(1)
    {
          if(GetAsyncKeyState(VK_TAB))
            identify_shape(cursor_pos,Start);
         else if(GetAsyncKeyState(VK_SHIFT))
            check_color(cursor_pos);
        else if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(cursor_pos);
            checkshape(cursor_pos,*Start);
        }
    }
}
void set_panel(void)
{ int i=0,x=0;
setcolor(WHITE);
    rectangle(0,50,100,80);
    settextstyle(3,0,3);
    outtextxy(10,53,"Pencil");
     rectangle(0,90,100,120);
      outtextxy(10,93,"Fill");
       rectangle(0,130,100,160);
      outtextxy(10,133,"Text");
       rectangle(0,170,100,200);
      outtextxy(10,173,"Save");
       rectangle(0,210,100,240);
      outtextxy(10,213,"Line");
       rectangle(0,250,100,280);
      outtextxy(10,253,"Rectangle");
       rectangle(0,290,100,320);
      outtextxy(10,293,"Circle");
 rectangle(0,330,100,360);
      outtextxy(10,333,"Clear");
rectangle(0,370,100,400);
      outtextxy(10,373,"Load");
      rectangle(0,410,100,440);
      outtextxy(10,413,"Triangle");
while(i<16)
{
    setfillstyle(SOLID_FILL,i);
    rectangle(x,10,x+30,40);
    floodfill(x+2,14,WHITE);
    x=x+40;
    i++;
}
}
void triangle(POINT *cursor_pos,struct node **Start)
{    int color;
     int i=0,y=0,x1,x2,y1,y2;
     while(1)
     {
         GetCursorPos(cursor_pos);
         if(GetAsyncKeyState(VK_TAB))
            identify_shape(cursor_pos,Start);
        else if(GetAsyncKeyState(VK_SHIFT))
            check_color(cursor_pos);

         else if(GetAsyncKeyState(VK_LBUTTON)&&i==0)
    {
        x1=cursor_pos->x;
        y1=cursor_pos->y;
        i++;
    }
    else if(GetAsyncKeyState(VK_LBUTTON))
    {  if(y>0){
        color=getcolor();
        setcolor(getbkcolor());
        line(x1,y1,x1-(x2-x1),y2);
        line(x1,y1,x1+(x2-x1),y2);
        line(x1-(x2-x1),y2,x2,y2);
        setcolor(color);
    }
    GetCursorPos(cursor_pos);
        x2=cursor_pos->x;
        y2=cursor_pos->y;
 line(x1,y1,x1-(x2-x1),y2);
        line(x1,y1,x1+(x2-x1),y2);
        line(x1-(x2-x1),y2,x2,y2);
    y++;
    }
    else if(!GetAsyncKeyState(VK_LBUTTON)&&i==1)
    {
        setcolor(getbkcolor());
        line(x1,y1,x1-(x2-x1),y2);
        line(x1,y1,x1+(x2-x1),y2);
        line(x1-(x2-x1),y2,x2,y2);

        setcolor(color);
        GetCursorPos(cursor_pos);
        x2=cursor_pos->x;
        y2=cursor_pos->y;
        i++;
    }
    if(i==2){

 line(x1,y1,x1-(x2-x1),y2);
        line(x1,y1,x1+(x2-x1),y2);
        line(x1-(x2-x1),y2,x2,y2);


    put(Start,x1,y1,x2,y2,getcolor());
    i=0;
    y=0;}
    delay(50);

    }

}
