#include "Cilindro.hpp"
#define PI 3.14159265358979323846

Cilindro::Cilindro(){
	nombre_obj = "Cilindro";
	num_caras = 50; // DEBE SER MÍNIMO 5
	num_vertices = (num_caras-2)*2;
	angulo = (2*PI)/(num_vertices/2);
	rad = angulo;
	
	tablaVertices.push_back(Tupla3f(0,-1,1));
	tablaVertices.push_back(Tupla3f(0,1,1));
	
	for (int i=1; i<num_vertices/2; i++){
		tablaVertices.push_back(Tupla3f(sin(rad),-1,cos(rad)));	
		tablaVertices.push_back(Tupla3f(sin(rad),1,cos(rad)));
		rad = rad+angulo;
	}

	tablaVertices.push_back(Tupla3f(0,-1,0)); //centro de la base inferior del cilindro
	tablaVertices.push_back(Tupla3f(0,1,0)); //centro de la base superior del cilindro
	
	for (int i=0; i<num_vertices-2; i++){	
		tablaCaras.push_back(Tupla3i(i,i+1,i+2));
	}
		tablaCaras.push_back(Tupla3i(num_vertices-2,num_vertices-1,0));
		tablaCaras.push_back(Tupla3i(num_vertices-1,0,1));
	for (int i=0; i<num_vertices-2; i++){
		if (i%2==0){
			tablaCaras.push_back(Tupla3i(i,num_vertices,i+2));
		} 
		else{
			tablaCaras.push_back(Tupla3i(i,num_vertices+1,i+2));
		}		
	}
	if (num_vertices%2==0){
		tablaCaras.push_back(Tupla3i(num_vertices-2,num_vertices,0));
		tablaCaras.push_back(Tupla3i(num_vertices-1,num_vertices+1,1));
	}
	else if (num_vertices%2!=0){
		tablaCaras.push_back(Tupla3i(num_vertices-2,num_vertices+1,1));
		tablaCaras.push_back(Tupla3i(num_vertices-1,num_vertices,0));
	}		
}
