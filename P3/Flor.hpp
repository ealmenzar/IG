#ifndef FLOR_HPP
#define FLOR_HPP
#include "NodoGrafoEscena.hpp"
#include "MallaPLY.hpp"

class Flor : public NodoGrafoEscena{
	public:
		Flor();
		void fijarH(float h_nuevo);
};
#endif
