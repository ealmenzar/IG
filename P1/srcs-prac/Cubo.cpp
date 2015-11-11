#include "Cubo.hpp"

Cubo::Cubo(){
	nombre_obj = "Cubo";	
	
	tablaVertices.push_back(Tupla3f(-0.5,-0.5,0.5));	
	tablaVertices.push_back(Tupla3f(-0.5,-0.5,-0.5));
	tablaVertices.push_back(Tupla3f(0.5,-0.5,-0.5));
	tablaVertices.push_back(Tupla3f(0.5,-0.5,0.5));
	tablaVertices.push_back(Tupla3f(-0.5,0.5,0.5));
	tablaVertices.push_back(Tupla3f(-0.5,0.5,-0.5));
	tablaVertices.push_back(Tupla3f(0.5,0.5,-0.5));
	tablaVertices.push_back(Tupla3f(0.5,0.5,0.5));

	tablaCaras.push_back(Tupla3i(0,1,2));
	tablaCaras.push_back(Tupla3i(0,3,2));
	tablaCaras.push_back(Tupla3i(2,6,7));
	tablaCaras.push_back(Tupla3i(7,3,2));
	tablaCaras.push_back(Tupla3i(4,5,6));
	tablaCaras.push_back(Tupla3i(4,6,7));
	tablaCaras.push_back(Tupla3i(0,5,1));
	tablaCaras.push_back(Tupla3i(5,0,4));
	tablaCaras.push_back(Tupla3i(0,7,3));
	tablaCaras.push_back(Tupla3i(0,7,4));
	tablaCaras.push_back(Tupla3i(1,6,2));
	tablaCaras.push_back(Tupla3i(6,1,5));
}
