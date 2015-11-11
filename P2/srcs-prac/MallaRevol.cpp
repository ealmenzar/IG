#include "MallaRevol.hpp"
#define PI 3.14159265358979323846

MallaRevol::MallaRevol(const char *nombre_arch, unsigned nperfiles){

	ply::read_vertices(nombre_arch, vertices);
	//cout<< "LEE"<<endl;
	for(unsigned int i=0; i<vertices.size(); i+=3){
		tablaVertices.push_back(Tupla3f(vertices[i],vertices[i+1],vertices[i+2]));
		//cout<<"introduzco: " << vertices[i] << "," << vertices[i+1] << "," << vertices[i+2] << endl;
	}
	//cout<<"primer perfil en tablaVertices"<<endl;
	
	double angulo = (2.0*PI)/nperfiles;

	for (unsigned int i=0; i<nperfiles-1; i++){
		vector<float> sig_vertices;
		//cout<<"SIZE VERTICES: " << vertices.size() << endl;
		for (unsigned int j=0; j<vertices.size(); j+=3){
			sig_vertices.push_back(cos(angulo)*vertices[j]+sin(angulo)*vertices[j+2]);
			sig_vertices.push_back(vertices[j+1]);
			sig_vertices.push_back(-sin(angulo)*vertices[j]+cos(angulo)*vertices[j+2]);
			//cout << "creo: " << cos(angulo)*vertices[j]+sin(angulo)*vertices[j+2] << ", " << vertices[j+1] << ", " << -sin(angulo)*vertices[j]+cos(angulo)*vertices[j+2] << endl;
		}
		//cout<<"se calcula sig_vertices"<<endl;
		for(unsigned int i=0; i<vertices.size(); i+=3){
		tablaVertices.push_back(Tupla3f(sig_vertices[i],sig_vertices[i+1],sig_vertices[i+2]));
		}
		//cout<<"se almacena sig_vertices en tablaVertices"<<endl;
		//cout << "tamaño de vertices = " << vertices.size()/3 << endl;
		int primerPerfil = i*vertices.size()/3;
		int segundoPerfil = primerPerfil + vertices.size()/3;
		//cout<<"primerPerfil = " << primerPerfil << endl;
		//cout <<"segundoPerfil = " << segundoPerfil << endl;
		int p1, p2;
		for (p1=primerPerfil, p2=segundoPerfil; p1<segundoPerfil-1; p1++, p2++){
			tablaCaras.push_back(Tupla3i(p1,p1+1,p2));
			//cout<<"uno "<<p1<<" con "<<p1+1<<" con "<<p2<<endl;
			tablaCaras.push_back(Tupla3i(p2,p2+1,p1+1));
			//cout<<"y uno "<<p2<<" con "<<p2+1<<" con "<<p1+1<<endl;
		}
		for (int i=0; i<(vertices.size()/3)-1; i++){
			tablaCaras.push_back(Tupla3i(p1+1,p1+2,i));
			tablaCaras.push_back(Tupla3i(p1+2,i,i+1));
			p1++;
		}	
		//cout << "p1 = " << p1 << endl;
		//cout << "p2 = " << p2 << endl;

		vertices = sig_vertices;
	}
}
	
