// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica1.hpp"

unsigned objeto_activo; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

Cubo *miCubo = NULL;
Tetraedro *miTetraedro = NULL;
Cilindro *miCilindro = NULL;
Cono *miCono = NULL;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P1_Inicializar( int argc, char *argv[] )
{
   
miCubo = new Cubo();  
miTetraedro = new Tetraedro();
miCilindro = new Cilindro();
miCono = new Cono();
 
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar 
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
	bool res=false;
	switch (toupper(tecla))
   {
   	case 'C':
			objeto_activo=0;
			res=true;
			break;
	  case 'T':
			objeto_activo=1;
			res=true;
			break;
	  case 'I':
			objeto_activo=2;
		break;
		case 'O':
			objeto_activo=3;
		break;
	}
	return res;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P1_DibujarObjetos( unsigned modo ) 
{
	if (objeto_activo==0){  
		miCubo->visualizar(modo);
	}else if (objeto_activo==1){
		miTetraedro->visualizar(modo);
	}else if (objeto_activo==2){
		miCilindro->visualizar(modo);
	}else if (objeto_activo==3){
		miCono->visualizar(modo);
	}
}
