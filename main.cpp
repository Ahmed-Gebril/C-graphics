
//This program is uses graphics library to make two different enveloping rectangles to a randomly generated set of points


#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include"winbgi2.h"

 //number of points
int RANGE_X = 300; //x range
int RANGE_Y = 300; //y range

void project();
void main()
{
	project();
}
void project()
{
	graphics(1000,1000);
	srand((unsigned)time(0)); //initialize random generator - uses current time as seed
	int N;
	printf("no. of random points:");
	scanf("%d",&N);
	double *x = (double*)malloc(sizeof (double) * N);// array for determining x coordinate
	double *y = (double*)malloc(sizeof (double) * N);// array for determining y coordinate
	int x_max=0,y_max=0,x_min=800,y_min=800;

	for(int i = 0; i < N; i++)
    {

		x[i] = rand() % RANGE_X;//returns random value in range [0, RANGE_X)
	}
	for(int i=0;i<N;i++)
	{
		if(x_max < x[i])
		{
			x_max=x[i];
		}
		if(x[i]<x_min)
		{
			x_min=x[i];
		}
		y[i] = rand() % RANGE_Y;//returns random value in range [0, RANGE_Y)
		if(y_max < y[i])
		{
			y_max=y[i];
		}
		if(y[i]<y_min)
		{
			y_min=y[i];
		}
	  circle(x[i],y[i],3);
	  //printf("x=%d\n y=%d\n",x,y);
	  }
	printf("x_max=%d\n x_min=%d\n y_max=%d\n y_min=%d\n",x_max,x_min,y_max,y_min);
	rectangle(x_min,y_min,x_max,y_max);///////////////////////////FOR FIRST RECTANGLE
	/////////////////////////////Center of Rectangle
	double xc=(x_max+x_min)/2;
	double yc=(y_max+y_min)/2;
	//circle(xc,yc,10);
	double y1=(x_max+y_max)-xc;///////////below point
	double x1=(x_max+y_max)-yc;///////////right point
	////circle(x_max,y_max,10);
	//circle(xc,y1,10);
	//circle(x1,yc,10);
	//line(x1,yc,xc,y1);
	//left top point
	//circle(x_min,y_min,10);
	double y2=(x_min+y_min)-xc;
	double x2=(x_min+y_min)-yc;
	//circle(x2,yc,10);
	//circle(xc,y2,10);
	//line(x2,yc,xc,y2);

	double *add=(double*)malloc(sizeof (double) * N);;
	for(int i=0;i<N;i++)
	{
		add[i]=x[i]+y[i];
	}
	double *dis1=(double*)malloc(sizeof (double) * N);;
	for(int i=0;i<N;i++)
	{
		dis1[i]=sqrt((pow((x_max-x[i]),2))+(pow((y_min-y[i]),2)));
	}
	double *dis2=(double*)malloc(sizeof (double) * N);;
	for(int i=0;i<N;i++)
	{
		dis2[i]=sqrt((pow((x_min-x[i]),2))+(pow((y_max-y[i]),2)));
	}
	/////////////////////////point a1 and b1
	double max1=add[0];
	int p1;
	for(int j=0;j<N;j++)
	{
		if(add[j]>max1)
		{
			max1=add[j];
			p1=j;
		}
	}
	//circle(x[p1],y[p1],10);
	////////////////////////////point a2 and b2
	double minds2=dis2[0];
	int p2;
	for(int j=0;j<N;j++)
	{
		if(dis2[j]<minds2)
		{
			minds2=dis2[j];
			p2=j;
		}
	}
	//circle(x[p2],y[p2],10);
	/////////point a3 and b3
	double minds1=dis1[0];
	int p3;
	for(int j=0;j<N;j++)
	{
		if(dis1[j]<minds1)
		{
			minds1=dis1[j];
			p3=j;
		}
	}
	//circle(x[p3],y[p3],10);
	////point a4 and b4
	double min4=add[0];
	int p4;
	for(int j=0;j<N;j++)
	{
		if(add[j]<min4)
		{
			min4=add[j];
			p4=j;
		}
	}
	//circle(x[p4],y[p4],10);
	//bottom left line
	double m1=(y1-yc)/(xc-x1);//SLOPE OF THE RIGHT LINE
	double a2=x[p2];
	double b2=y[p2];
	double a1=x[p1];
	double b1=y[p1];
	double a4=x[p4];
	double b4=y[p4];
	double x3=((b2*m1)-(b1*m1)+a2+(pow(m1,2)*a1))/(1+(pow(m1,2)));
	double y3=(((-1)/m1)*(x3-a2))+b2;
	//circle(x3,y3,20);
	double x4=((b2*m1)-(b4*m1)+a2+(pow(m1,2)*a4))/(1+(pow(m1,2)));
	double y4=m1*(x4-a4)+b4;
	//circle(x4,y4,20);
	line(x3,y3,x4,y4);
	//right up point
	double a3=x[p3];
	double b3=y[p3];
	double x6=((-b1*m1)+(b3*m1)+a3+(pow(m1,2)*a1))/(1+(pow(m1,2)));
	double y6=m1*(x6-a1)+b1;
	//circle(x6,y6,10);
	//left  up point
	double x5=((-a4*m1)+(b3*m1)+a3+(pow(m1,2)*b4))/(1+(pow(m1,2)));
	double y5=(((-1)/m1)*(x5-a3))+b3;
	//circle(x5,y5,30);
	line(x5,y5,x6,y6);
	line(x3,y3,x6,y6);
	line(x4,y4,x5,y5);
	printf("\n");
	printf("point touching the tilted rectangle as follows:-\n");
	printf("right most below point:  x[%d]=%lf\ty[%d]=%lf\n",p1,x[p1],p1,y[p1]);
	printf("left most below point:   x[%d]=%lf\ty[%d]=%lf\n",p2,x[p2],p2,y[p2]);
	printf("top most right point:    x[%d]=%lf\ty[%d]=%lf\n",p3,x[p3],p3,y[p3]);
	printf("top most left point:     x[%d]=%lf\ty[%d]=%lf\n",p4,x[p4],p4,y[p4]);
	//Area of the rectangle
	double area1=(x_max-x_min)*(y_max-y_min);
	double area2=(sqrt(pow((x6-x5),2)+pow((y6-y5),2)))*(sqrt(pow((x6-x3),2)+pow((y6-y3),2)));
	printf("area1=%f\n",area1);
	printf("area2=%f\n",area2);
	if(area1>area2)
	{
		printf("normal rectangle area is bigger");
	}
	else if(area2>area1)
	{
		printf("tilted rectangle area is bigger");
	}
	getch();

}
