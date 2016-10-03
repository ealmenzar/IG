#ifndef NODOGRAFOESCENA_HPP
#define NODOGRAFOESCENA_HPP
#include "Objeto3D.hpp"
#include <vector>
#include "tuplasg.hpp"
#include "matrizg.hpp"
#include "matrices-tr.hpp"

struct EntradaNGE{
	unsigned char tipoE ; // 0=objeto, 1=transformacion
	union{ 
		Objeto3D * objeto ; // ptr. a un objeto (propietario)
		Matriz4f * matriz ; // ptr. a matriz 4x4 transf. (prop.)
	} ;
	// constructores (uno por tipo)
	EntradaNGE( Objeto3D * pObjeto ) ; // (copia solo puntero)
	EntradaNGE( const Matriz4f & pMatriz ); // (crea copia)
} ;

class NodoGrafoEscena : public Objeto3D{
	protected:
		std::vector<EntradaNGE> entradas ; // vector de entradas
	public:
		// visualiza usando OpenGL
		virtual void visualizar( unsigned cv ) ;
		// añadir una entrada (al final).
		void agregar( EntradaNGE * entrada ); // genérica
		// construir una entrada y añadirla (al final)
		void agregar( Objeto3D * pObjeto ); // objeto
		void agregar( const Matriz4f & pMatriz ); // matriz
} ;
#endif
