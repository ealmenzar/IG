#include "MallaRevol.hpp"
#define PI 3.14159265358979323846

MallaRevol::MallaRevol(const char *nombre_arch, unsigned nperfiles){

	ply::read_vertices(nombre_arch, vertices);

	for(unsigned int i=0; i<vertices.size(); i+=3){
		tablaVertices.push_back(Tupla3f(vertices[i],vertices[i+1],vertices[i+2]));
	}
	
	double angulo = (2.0*PI)/nperfiles;
	int p1, p2;

	for (unsigned int i=0; i<nperfiles-1; i++){
		vector<float> sig_vertices;

		//Hallamos los puntos del siguiente perfil
		for (unsigned int j=0; j<vertices.size(); j+=3){
			sig_vertices.push_back(cos(angulo)*vertices[j]+sin(angulo)*vertices[j+2]);
			sig_vertices.push_back(vertices[j+1]);
			sig_vertices.push_back(-sin(angulo)*vertices[j]+cos(angulo)*vertices[j+2]);
		}
		
		for(unsigned int i=0; i<vertices.size(); i+=3){
		tablaVertices.push_back(Tupla3f(sig_vertices[i],sig_vertices[i+1],sig_vertices[i+2]));
		}

		int primerPerfil = i*vertices.size()/3;
		int segundoPerfil = primerPerfil + vertices.size()/3;

		//Dibujamos las caras que unen el primer perfil con el nuevo perfil que acabamos de calcular
		for (p1=primerPerfil, p2=segundoPerfil; p1<segundoPerfil-1; p1++, p2++){
			tablaCaras.push_back(Tupla3i(p1,p1+1,p2));
			tablaCaras.push_back(Tupla3i(p2,p2+1,p1+1));
		}

		vertices = sig_vertices;
	}

	//Dibujamos las caras que unen el último perfil calculado con el primero
	for (int i=0; i<(vertices.size()/3)-1; i++){
			tablaCaras.push_back(Tupla3i(p1+1,p1+2,i));
			tablaCaras.push_back(Tupla3i(p1+2,i,i+1));
			p1++;
	}


	int puntosPerfil=tablaVertices.size()/nperfiles; //almacenamos el número de puntos que hay en un perfil, 
																									//que nos servirá para dibujar las tapas

	tablaVertices.push_back(Tupla3f(0,vertices[1],0)); //centro de abajo
	tablaVertices.push_back(Tupla3f(0,vertices[vertices.size()-2],0)); //centro de arriba

	//TAPA DE ABAJO
	for(p1=0; p1<puntosPerfil*(nperfiles-1); p1+=puntosPerfil){
		p2=p1+puntosPerfil;
		tablaCaras.push_back(Tupla3i(p1,p2,tablaVertices.size()-2));
	}
	tablaCaras.push_back(Tupla3i(0,p1,tablaVertices.size()-2));

	//TAPA DE ARRIBA
	for(p1=puntosPerfil-1; p1<puntosPerfil*(nperfiles)-1; p1+=puntosPerfil){
		p2=p1+puntosPerfil;
		tablaCaras.push_back(Tupla3i(p1,p2,tablaVertices.size()-1));
	}
	tablaCaras.push_back(Tupla3i(puntosPerfil-1,p1,tablaVertices.size()-1));

}
	
