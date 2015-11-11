// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 2  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica2.hpp"

unsigned p2_objeto_activo;

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

static MallaPLY *miMallaPLY = NULL;
static MallaRevol *miMallaRevol = NULL;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P2_Inicializar( int argc, char *argv[] )
{
if (argc != 2){
cout << "Falta el archivo PLY" << endl;
exit(2);
}
//const char *archivo = argv[1];  
miMallaPLY = new MallaPLY(argv[1]);
miMallaRevol = new MallaRevol("/home/marina/Escritorio/IG/p2/plys/peon.ply",3);
 
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar 
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'p2_objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
	bool res=false;
	switch (toupper(tecla))
   {

	case 'O':
		p2_objeto_activo++;
		if (p2_objeto_activo>1) {p2_objeto_activo=0;}
		res=true;
		break;
	}
	return res;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P2_DibujarObjetos( unsigned modo ) 
{
	if (p2_objeto_activo==0){  
		miMallaPLY->visualizar(modo);
	}

	else if (p2_objeto_activo==1){
		miMallaRevol->visualizar(modo);
	}
}






