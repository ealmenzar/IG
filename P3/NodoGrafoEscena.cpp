#include "NodoGrafoEscena.hpp"

EntradaNGE::EntradaNGE( Objeto3D * pObjeto ){
	this->objeto = pObjeto;
	tipoE=0;
}

EntradaNGE::EntradaNGE( const Matriz4f & pMatriz ){
	matriz = new Matriz4f(pMatriz);
	tipoE=1;
}

void NodoGrafoEscena::visualizar(unsigned cv){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	for (unsigned i=0; i<entradas.size(); i++){
		if(entradas[i].tipoE==0){
			entradas[i].objeto->visualizar(cv);
		}
		else{
			glMultMatrixf(*(entradas[i].matriz));
		}
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void NodoGrafoEscena::agregar( EntradaNGE * entrada ){
	entradas.push_back(*entrada);
}

void NodoGrafoEscena::agregar( Objeto3D * pObjeto ){
	entradas.push_back(EntradaNGE(pObjeto));
}

void NodoGrafoEscena::agregar( const Matriz4f & pMatriz ){
	entradas.push_back(EntradaNGE(pMatriz));
}

