
#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

int m1=0,m2=0;



int arr[37][3]={{0,0,0},{0,1,3},{0,2,2},{0,3,3},{0,4,2},{0,5,3},{0,6,4},{0,7,5},    {1,1,2},{1,2,1},{1,3,2},{1,4,3},{1,5,4},{1,6,3},{1,7,4},{2,2,4},{2,3,3},{2,4,2},
            {2,5,3},{2,6,3},{2,7,5},{3,3,2},{3,4,3},{3,5,4},{3,6,3},{3,7,4},{4,4,4},{4,5,3},{4,6,4},{4,7,5},{5,5,4},{5,6,5},{5,7,4},{6,6,5},{6,7,5},{7,7,6}};

void imprmovimientos(int,int,int,int,int,int);
void futrLegalMove(int,int,int,int);
main()
{
  printf("Numero minimo de movimientos de un caballo en un tablero de 8*8 :\n");
  printf("------------------------------------------");
  printf("\ Ninguna tabla de ajedrez debe ser referida como (0,0) y del mismo modo (8,8) ");
  printf("\nEl cual debe ser referido como (7,7) y del mismo modo\n");
  int ix,iy,fx,fy;
  printf("\nEscriba la posicion iniciall del caballo :\n");
  scanf("%d%d",&ix,&iy);
  printf("\nEscriba lla posicion final que se alcanza :\n");
  scanf("%d%d",&fx,&fy);
  int px=ix,py=iy;
  int temp;
  int tx,ty;
  printf("\nEl numero de movimientos es: :\n\n");
  printf("(%d, %d)",ix,iy);
  futrLegalMove(px,py,m1,m2);
 imprmovimientos(px,py,fx,fy,m1,m2);
   getch();
} 



int checkSteps(int a,int b,int c,int d)
{  
    int xdiff, ydiff;
    int i, j;
    if(c>a)
        xdiff=c-a;
    else
        xdiff=a-c;
    if(d>b)
        ydiff=d-b;
    else
        ydiff=b-d;
    for(i=0;i<37;i++)
        {
            if(((xdiff==arr[i][0])&&(ydiff==arr[i][1])) || ((xdiff==arr[i][1])&& (ydiff==arr[i] [0])))
            {
                j=arr[i][2];break;
            }
        }

        return j;
}   



void  imprmovimientos(int px,int py, int fx, int fy,int a,int b)
{    
 int temp;
 int tx,ty;
 int t1,t2;
  while(!((px==fx) && (py==fy)))
  {   
      printf(" --> ");
      temp=checkSteps(px+a,py+b,fx,fy);
      tx=px+a;
      ty=py+b;
      if(!(a==2 && b==1))
      {if((checkSteps(px+2,py+1,fx,fy)<temp) && checkMove(px+2,py+1))
      {temp=checkSteps(px+2,py+1,fx,fy);
       tx=px+2;ty=py+1;}}
      if(!(a==2 && b==-1))
      {if((checkSteps(px+2,py-1,fx,fy)<temp) && checkMove(px+2,py-1))
      {temp=checkSteps(px+2,py-1,fx,fy);
       tx=px+2;ty=py-1;}}
      if(!(a==-2 && b==1))
      {if((checkSteps(px-2,py+1,fx,fy)<temp) && checkMove(px-2,py+1))
      {temp=checkSteps(px-2,py+1,fx,fy);
       tx=px-2;ty=py+1;}}
      if(!(a==-2 && b==-1))
      {if((checkSteps(px-2,py-1,fx,fy)<temp) && checkMove(px-2,py-1))
      {temp=checkSteps(px-2,py-1,fx,fy);
       tx=px-2;ty=py-1;}}
      if(!(a==1 && b==2))
      {if((checkSteps(px+1,py+2,fx,fy)<temp) && checkMove(px+1,py+2))
      {temp=checkSteps(px+1,py+2,fx,fy);
       tx=px+1;ty=py+2;}}
      if(!(a==1 && b==-2))
      {if((checkSteps(px+1,py-2,fx,fy)<temp) && checkMove(px+1,py-2))
      {temp=checkSteps(px+1,py-2,fx,fy);
       tx=px+1;ty=py-2;}}
      if(!(a==-1 && b==2))
      {if((checkSteps(px-1,py+2,fx,fy)<temp) && checkMove(px-1,py+2))
      {temp=checkSteps(px-1,py+2,fx,fy);
       tx=px-1;ty=py+2;}}
      if(!(a==-1 && b==-2))
      {if((checkSteps(px-1,py-2,fx,fy)<temp) && checkMove(px-1,py-2))
      {temp=checkSteps(px-1,py-2,fx,fy);
       tx=px-1;ty=py-2;}}
       t1=tx-px;
       t2=ty-py;
       px=tx;
       py=ty;
       printf("(%d, %d)",px,py);
       futrLegalMove(px,py,t1,t2);
       a=m1;
       b=m2;
   }

} 

 

int checkMove(int a, int b)
{
    if(a>7 || b>7 || a<0 || b<0)
        return 0;
    else
        return 1;
}



void futrLegalMove(int px,int py,int a,int b)
{
     if(checkMove(px+2,py+1) && (a!=-2 && b!=-1))
         m1=2,m2=1;
     else
     {
         if(checkMove(px+2,py-1)&& (a!=-2 && b!=1))
             m1=2,m2=-1;
     else
     {
         if(checkMove(px-2,py+1)&& (a!=2 && b!=-1))
              m1=-2,m2=1;
     else
     {
         if(checkMove(px-2,py-1)&& (a!=2 && b!=1))
               m1=-2,m2=-1;
     else
     {
         if(checkMove(px+1,py+2)&& (b!=-2 && a!=-1))
               m2=2,m1=1;
     else
     {
         if(checkMove(px+1,py-2)&& (a!=-1 && b!=2))
               m2=-2,m1=1;
     else
     {
         if(checkMove(px-1,py+2)&& (a!=1 && b!=-2))
               m2=2,m1=-1;
     else
     {
         if(checkMove(px-1,py-2)&& (a!=1 && b!=2))
               m2=-2,m1=-1;
     }}}}}}}
}


