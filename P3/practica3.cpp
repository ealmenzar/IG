// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (implementación)
// **
// *********************************************************************
#define PI 3.14159265358979323846
#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica3.hpp"

unsigned p3_objeto_activo=0;
int grado_actual=0;
int n=0;
float m=0;
float m1=0;
float n1=PI/8;
float n2=22.5;
float i=0;

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

static Mariposa *miMariposa = NULL;

// ---------------------------------------------------------------------

void P3_Inicializar( int argc, char *argv[] )
{
	miMariposa = new Mariposa(0,0);
}

bool P3_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
	bool res=false;
	switch (toupper(tecla))
  {
	case 'O':
		p3_objeto_activo++;
		if (p3_objeto_activo>1) {p3_objeto_activo=0;}
		res=true;
		break;
	
	case 'G':
		grado_actual++;
		if (grado_actual>3) {grado_actual=0;}
		res=true;
		break;
	
	case '<':
		if (grado_actual==0){
			if (m<15){
				miMariposa->fijarH(m);
				m+=0.5;
				res=true;
			}else res=false;
		}		
		else if (grado_actual==1){ 
			if (n<15){
				miMariposa->fijarAlpha(n);
				n+=10;
				res=true;
			}else res=false;
		}
		else if (grado_actual==2){
			if(i<=4){ 
				i+=0.5;
				miMariposa->mueveDerecha(i);
			}
			if(i>4){
				n1-=PI/8;
				n2-=23;
				miMariposa->fijarVuelta(n1,n2);
			}
			res=true;
		}
		else if (grado_actual==3){
			if (m1<2){
				miMariposa->fijarHA(m1);
				m1+=0.1;
				res=true;
			}else res=false;
		}

		break;
	
	case '>':
		if (grado_actual==0){
			if (m>0){
				m-=0.5;
				miMariposa->fijarH(m);
				res=true;
			}else res=false;
		}
		else if (grado_actual==1){
			if (n>-30){ 
				n-=10;
				miMariposa->fijarAlpha(n);
				res=true;
			}else res=false;
		}
		else if (grado_actual==2){
			miMariposa->fijarVuelta(n1,n2);
			n1+=PI/8;
			n2+=23;
			res=true;
		}
		else if (grado_actual==3){
			if (m1>0){
				m1-=0.1;
				miMariposa->fijarHA(m1);
				res=true;
			}else res=false;
		}
	
		break;
	}
	return res;
}

// ---------------------------------------------------------------------

void P3_DibujarObjetos( unsigned modo ) 
{
	miMariposa->visualizar(modo);	

}
