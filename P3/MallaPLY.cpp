#include "MallaPLY.hpp"

MallaPLY::MallaPLY(const char * nombre_arch){

	ply::read(nombre_arch, vertices, caras);
	
	for(int i=0; i<vertices.size(); i+=3){
		tablaVertices.push_back(Tupla3f(vertices[i],vertices[i+1],vertices[i+2]));
	}

	for(int j=0; j<caras.size(); j+=3){
		tablaCaras.push_back(Tupla3i(caras[j],caras[j+1],caras[j+2]));
	}
}
