#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
/*Este arreglo contiene las coordenadas del cuadro por donde pasan las figuras*/
int cu[62]={257,266,255,268,253,271,253,380,254,382,255,384,257,386,103,386,100,387,99,389,98,393,
		98,446,99,450,100,452,103,453,447,453,450,452,451,450,452,448,452,391,451,388,450,387,
		447,386,293,386,295,384,297,382,298,380,298,271,296,268,295,266,257,266};

void main (void)
{
	int gdriver=DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bin");
	errorcode=graphresult();
	if (errorcode!=grOk)
	{
		printf("Ha ocurrido un error al inicializar modo grafico");
		printf("Presiones un tecla para salir");
		getch();
		exit(0);
	}

	/*Pagina#1 Inicio Juego*/
	cleardevice();

	setcolor(15);
	setfillstyle(SOLID_FILL,15); /*Esta parte dibujo el fondo blanco*/
	rectangle(0,0,640,480);floodfill(1,1,15); 

	setcolor(7);
	setfillstyle(SOLID_FILL,7);
	fillpoly(31,cu);/*Esta linea dibuja el cuadro por donde pasan las figuras (tanto horizontal, como vertical)*/
	circle(275,148,120);floodfill(287,163,7);



	/*Carita*/
	setcolor(0);
	setfillstyle(SOLID_FILL,14);
	circle(275,148,71);floodfill(287,163,0);
	
	/*Ojos*/
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	circle(257,121,11);floodfill(260,130,0);
	circle(293,121,11);floodfill(295,130,0);
	
	/*Boca*/
	rectangle(244,166,309,173);floodfill(247,170,0);

	/*botones*/

	/*play*/
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	circle (51,355,27);
	line(44,335,44,375);line(44,375,69,355);line(69,355,44,335);
	floodfill (50,351,0);

	/*STOP*/
	circle ( 53,428,27);
	rectangle (42,418,63,440);
	floodfill (50,424,0);

	/*pregunta*/
	
	circle (53,30,17);
	outtextxy(50,27,"?");

	getch();
}