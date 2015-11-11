#include "Cono.hpp"
#define PI 3.14159265358979323846

Cono::Cono(){
	nombre_obj = "Cono";
	num_caras = 50; // DEBE SER MÍNIMO 4
	num_vertices = num_caras;
	angulo = (2*PI)/(num_vertices-1);
	rad = angulo;
	
	tablaVertices.push_back(Tupla3f(0,1,0));
	tablaVertices.push_back(Tupla3f(0,-1,1));
	
	for (int i=1; i<num_vertices-1; i++){
		tablaVertices.push_back(Tupla3f(sin(rad),-1,cos(rad)));	
		rad = rad+angulo;
	}

	tablaVertices.push_back(Tupla3f(0,-1,0)); //centro de la base inferior del cono
	
	for (int i=1; i<num_vertices-1; i++){	
		tablaCaras.push_back(Tupla3i(0,i,i+1));
	}
		tablaCaras.push_back(Tupla3i(0,num_vertices-1,1));
	for (int i=1; i<num_vertices-1; i++){
			tablaCaras.push_back(Tupla3i(i,num_vertices,i+1));		
	}
	tablaCaras.push_back(Tupla3i(num_vertices-1,num_vertices,1));
}
