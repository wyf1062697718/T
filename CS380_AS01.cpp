#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>


#define x_o 400 //origin
#define y_o 400 //origin

void  DDAline(int  x0, int  y0, int  x1, int  y1)
{
	int  dx, dy, epsl, k;   float  x, y, xIncre, yIncre;
	dx = x1 - x0;    dy = y1 - y0;    x = x0;  y = y0;
	if (abs(dx) > abs(dy)) epsl = abs(dx);
	else  epsl = abs(dy);
	xIncre = (float)(dx) / epsl;
	yIncre = (float)(dy) / epsl;
	for (k = 0; k <= epsl; k++)
	{
		putpixel((int)(x + 0.5), (int)(y + 0.5), RED);
		x += xIncre;   y += yIncre;
	}
}


void   circlePoint(int  x1, int  y1, int  x, int  y)
{
	putpixel(((x + x1) + x_o), (y_o - (y + y1)), RED);  putpixel(((-x + x1) + x_o), (y_o - (y + y1)), RED);
	putpixel(((y + x1) + x_o), (y_o - (x + y1)), RED);  putpixel(((-y + x1) + x_o), (y_o - (x + y1)), RED);
	putpixel(((x + x1) + x_o), (y_o - (-y + y1)), RED); putpixel(((-x + x1) + x_o), (y_o - (-y + y1)), RED);
	putpixel(((y + x1) + x_o), (y_o - (-x + y1)), RED); putpixel(((-y + x1) + x_o), (y_o - (-x + y1)), RED);
}



void   MidBhcircle(int x0, int y0, int  r) //draw circle
{
	int  x, y, d;
	x = 0; y = r; d = 1 - r;
	while (x < y)
	{
		circlePoint(x0, y0 , x , y);
		if (d < 0) d += 2 * x + 3;
		else { d += 2 * (x - y) + 5; y--; }
		x++;
	}
}


void   MidBhllipse(int x0, int y0, int  a, int  b) //draw ellipse
{
	int   x, y;      float  d1, d2;
	x = 0;  y = b;
	d1 = b * b + a * a*(-b + 0.25);
	putpixel(x_o+(x + x0), y_o - (y + y0), RED);
	putpixel(x_o +(-x + x0), y_o - (-y + y0), RED);
	putpixel(x_o+(-x + x0), y_o - (y + y0), RED);
	putpixel(x_o+(x + x0), y_o - (-y + y0), RED);
	while (b*b*(x + 1) < a*a*(y - 0.5))
	{
		if (d1 <= 0)
		{
			d1 += b * b*(2 * x + 3);
			x++;
		}
		else
		{
			d1 += (b*b*(2 * x + 3) + a * a*(-2 * y + 2));
			x++;  y--;
		}
		putpixel(x + x_o, y_o - y, RED);     putpixel(-x + x_o, y_o +y, RED);
		putpixel(-x + x_o, y_o - y, RED);    putpixel(x + x_o, y_o + y, RED);
	}   
	d2 = b * b*(x + 0.5)*(x + 0.5) + a * a*(y - 1)*(y - 1) - a * a*b*b;
	while (y > 0)
	{
		if (d2 <= 0)
		{
			d2 += b * b*(2 * x + 2) + a * a*(-2 * y + 3);
			x++;  y--;
		}
		else { d2 += a * a*(-2 * y + 3);   y--; }
		putpixel(x + x_o, y_o - y,RED);     putpixel(-x + x_o, y_o + y, RED);
		putpixel(-x + x_o, y_o - y, RED);    putpixel(x + x_o, y_o + y, RED);

	}
}

void main()
{
	int x0, y0, x1, y1;
	initgraph(1000, 1000);
	setcolor(BLUE);    //Coordinate axis color
	line(x_o, 0, x_o, y_o * 2);			//Coordinate x axis
	line(0, y_o, x_o * 2, y_o);			 //Coordinate y axis
	DDAline(0, 0, 800, 800);
	MidBhcircle( 0,0,300 );
	MidBhllipse(0,0,100,400);
	_getch();
	closegraph();
}
