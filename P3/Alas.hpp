#ifndef ALAS_HPP
#define ALAS_HPP
#include "NodoGrafoEscena.hpp"
#include "MallaPLY.hpp"

class Alas : public NodoGrafoEscena{
	public:
		Alas();
		void fijarH(float h_nuevo);
};
#endif
