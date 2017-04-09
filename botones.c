#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void inicio(void);
void nombre(void);
void ayuda(void);
void Fayuda(void);

#define arriba 72
#define abajo 80
#define der 77
#define izq 75

/*
                         ***********************NO TOCAR ESTOS COMENTARIOS***********************************

char teclas_direccionales,teclas_secundarias,teclas_tercearias;
char arriba='H', abajo='P', izquierda='K', derecha='M';/*DIRECCIONALES
char enter='\r',esc=27;/*TECLAS SECUNDARIAS
char F1=';', F2='<',F3=61,F4=62; /*TECLAS TERCEARIAS*/

int i,x=0, y=0,x1,y1;/*Variable para Posiciones de los botones*/
int posx,posy,cont=0;
int boton=0;
char nom[10];

/*Este arreglo contiene las coordenadas del cuadro por donde pasan las figuras*/
int cu[62]={257,266,255,268,253,271,253,380,254,382,255,384,257,386,103,386,100,387,99,389,98,393,
		98,446,99,450,100,452,103,453,447,453,450,452,451,450,452,448,452,391,451,388,450,387,
		447,386,293,386,295,384,297,382,298,380,298,271,296,268,295,266,257,266};

/*
	  ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ
	  ÛÛ           TECLADO EN C            ÛÛ
	  ÛÛ tecla pregunta = 63               ÛÛ
	  ÛÛ tecla flecha arriba = 72 || 'H'   ÛÛ
	  ÛÛ tecla flecha abajo  = 80 || 'P'   ÛÛ
	  ÛÛ tecla flecha izquierda = 75 || 'K'ÛÛ
	  ÛÛ tecla flecha derecha   = 77 ||'M' ÛÛ
	  ÛÛ tecla enter  = 13   || '\r'       ÛÛ
	  ÛÛ tecla escape = 27                 ÛÛ
	  ÛÛ tecla F3 =     61                 ÛÛ
	  ÛÛ tecla F2 = '<'      ||  60        ÛÛ
	  ÛÛ tecla F1=';'        ||  59	       ÛÛ
	  ÛÛ tecla BackSpace (<-)   = 8        ÛÛ
	  ÛÛ tecla Space  = 32                 ÛÛ
	  ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ
*/

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


	/*Botones*/
	/*play*/
	setlinestyle(0,0,NORM_WIDTH);
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	circle (53,355,27);
	line(44,335,44,375);line(44,375,69,355);line(69,355,44,335);
	floodfill (50,351,0);

	/*STOP*/
	circle ( 53,428,27);
	rectangle (42,418,63,440);
	floodfill (50,424,0);
	setlinestyle(1,0,THICK_WIDTH);
	rectangle(255,400,295,440);/*Estas son las coordenades del cuadro de seleccion de figuras*/
	ayuda();
	inicio();
}



void inicio(){
	char teclas;
	posy=2;
	 do{

     /*
                        **********************NO TOCAR ESTOS COMENTARIOS************************
     do  {
      teclas_secundarias=getch();


      if (teclas_secundarias==0){
	teclas_direccionales=getch();

	teclas_secundarias=' ';
      }

    }
     while (!(teclas_secundarias==enter || teclas_secundarias==esc
     || teclas_direccionales==arriba || teclas_direccionales==derecha
     ||teclas_direccionales==abajo  || teclas_direccionales==izquierda));*/

	 switch(teclas=getch()){
	 	case arriba:/*Estes es el boton de play en "posy=0"*/
	 		if (posy==1){
		 	setcolor(WHITE);
    		setlinestyle(1,0,THICK_WIDTH);
			rectangle(23,325+(posy*70),85,390+(posy*70));
	 		posy = 0;
	 		setcolor(0);
			rectangle(23,325+(posy*70),85,390+(posy*70));
		}
		break;
		case abajo:/*Este es el boton Estop en "posy=1"*/
			if (posy==0||(posy==2)&&teclas!=abajo){
				if(posy==0){
					setcolor(WHITE);
					setlinestyle(1,0,THICK_WIDTH);
					rectangle(23,325+(posy*70),85,390+(posy*70));
				}else{
					setcolor(7);
					setlinestyle(1,0,THICK_WIDTH);
					rectangle(255,400,295,440);
				}
    		setlinestyle(1,0,THICK_WIDTH);
			rectangle(23,325+(posy*70),85,390+(posy*70));
	 		posy = 1;
	 		setcolor(0);
			rectangle(23,325+(posy*70),85,390+(posy*70));
		}
		break;
		case der:/*En "posy=2" es el recuadro que encierra la figura*/
		if(posy==1||posy==0){
			setcolor(WHITE);
			rectangle(23,325+(posy*70),85,390+(posy*70));
			setcolor(0);
			setlinestyle(1,0,THICK_WIDTH);
			rectangle(255,400,295,440);
			posy=2;
		}
		break;
		case izq:
			if (posy==2){

			setcolor(7);
			setlinestyle(1,0,THICK_WIDTH);
			rectangle(255,400,295,440);
	 		posy = 1;
	 		setcolor(0);
			rectangle(23,325+(posy*70),85,390+(posy*70));
		}
		break;
	 }



      /*setfillstyle(1,WHITE);
	  bar(23,325+(posy*70),85,390+(posy*70));*/
      /*setlinestyle(0,0,NORM_WIDTH);
      setfillstyle(1,BLACK);
      setcolor(BLACK);
      setfillstyle(SOLID_FILL,0);
	  circle (53,356,27);
	  line(44,335,44,375);line(44,375,69,355);line(69,355,44,335);
      floodfill (50,351,0);

      circle(53,428,27);
      rectangle (42,418,63,440);
      floodfill (50,424,0);*/
      /*setcolor(0);
      setlinestyle(1,0,THICK_WIDTH);
	  rectangle(23,325+(posy*70),85,390+(posy*70));*/


/*



	  if(teclas_secundarias==enter && posy==1) /* teclas_direccionales=' ';*/
		/*  aqui se manda  llamar a la funcion  para ingresar el nombre*/

}  while (teclas!=27);

}







void ayuda()
{



	int ta1[8]= {19,10, 21,1 ,25,10, 19,10};
	int ta2[8]= {29,13, 37,8, 34,16, 29,13};
	int ta3[8]= {35,22, 43,25, 35,29, 35,22};
	int ta4[8]= {34,34, 37,43, 29,39, 34,34};
	int ta5[8]= {25,41, 22,50, 19,41, 25,41};
	int ta6[8]= {14,39, 6,44, 11,35, 14,39};
	int ta7[8]= {8,29, 1,26, 8,22, 8,29};
	int ta8[8]= {10,16, 7,8, 14,12, 10,16};

	setfillstyle(1,GREEN);setcolor(BLACK);
	fillellipse(22,26,11,11);ellipse(22,26,0,365,11,11);

	fillpoly(4,ta1);drawpoly(4,ta1);fillpoly(4,ta2);drawpoly(4,ta2);
	fillpoly(4,ta3);drawpoly(4,ta3);fillpoly(4,ta4);drawpoly(4,ta4);
	fillpoly(4,ta5);drawpoly(4,ta5);fillpoly(4,ta6);drawpoly(4,ta6);
	fillpoly(4,ta7);drawpoly(4,ta7);fillpoly(4,ta8);drawpoly(4,ta8);
	setfillstyle(1,WHITE);setcolor(WHITE);
/*	line(20,19,24,19);line(24,19,24,24);line(24,24,22,24); */


settextstyle(1,0,2);
outtextxy(16,12,"?");
/*	line(22,24,22,27); */   bar(21,30,22,31);


	}



 /*funcion que continene la funcionalidad del boton de ayuda*/


void Fayuda(void)

{

	 char a;

	/*aqui ubicaran la ayuda*/
	/*este bar es un ejemplo que confirma que  muestra otra pantalla,cambiar para hacer la ayuda*/
	setfillstyle(1,15);
	bar(0,0,640,480);



	  setcolor(0);
	settextstyle(5,0,4);
	outtextxy(226,30,"AYUDA");
	settextstyle(1,0,4);
	outtextxy(101,91,"universidad nacional de ingenieria    "  );
	outtextxy(101,142,"	geometria computacional             "               );
	outtextxy(101,193,"grupo 2m5-co                            "          );
	outtextxy(101,260,"ingenieria en computacion                "           );
	outtextxy(101,312,"facultad de electrotecnia y computacion") ;
	/**/

	do{
		a=getch();
   }while(a!='s');

}
