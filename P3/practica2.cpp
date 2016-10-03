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

void P2_Inicializar( int argc, char *argv[] )
{

if (argc == 4){
	miMallaPLY = new MallaPLY(argv[1]);
	miMallaRevol = new MallaRevol(argv[2],atoi(argv[3]));
}
else if (argc == 2){
	miMallaPLY = new MallaPLY(argv[1]);
	miMallaRevol = new MallaRevol("../plys/peon.ply",40);
}
else{
	cout << "Faltan los argumentos. Ejecutar: ./prac 'nombre_archivo.ply'"<<endl;
	cout << "También puede ejecutar: ./prac 'nombre_archivo.ply perfil.ply num_perfiles'" << endl;
	exit(2);
}
 
}

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

void P2_DibujarObjetos( unsigned modo ) 
{
	if (p2_objeto_activo==0){  
		miMallaPLY->visualizar(modo);
	}

	else if (p2_objeto_activo==1){
		miMallaRevol->visualizar(modo);
	}
}
