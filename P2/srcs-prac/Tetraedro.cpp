#include "Tetraedro.hpp"

Tetraedro::Tetraedro(){
	nombre_obj = "Tetraedro";
	tablaVertices.push_back(Tupla3f(0,-1,-1));
	tablaVertices.push_back(Tupla3f(-0.866,-1,0.5));
	tablaVertices.push_back(Tupla3f(0.866,-1,0.5));
	tablaVertices.push_back(Tupla3f(0,1.5,0));

	tablaCaras.push_back(Tupla3i(0,1,2));
	tablaCaras.push_back(Tupla3i(0,1,3));
	tablaCaras.push_back(Tupla3i(0,2,3));
	tablaCaras.push_back(Tupla3i(1,2,3));
}
