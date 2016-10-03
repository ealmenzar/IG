#ifndef MARIPOSA_HPP
#define MARIPOSA_HPP
#include <math.h>
#include "NodoGrafoEscena.hpp"
#include "Alas.hpp"
#include "Cuerpo.hpp"
#include "Flor.hpp"

class Mariposa : public NodoGrafoEscena{
	private:
		float h,alpha;
	public:
		Mariposa(float h_inicial, float alpha_inicial);
		void fijarAlpha(float alpha_nuevo);
		void fijarH(float h_nuevo);
		void fijarHA(float h_nuevo);
		void fijarVuelta(float alpha_nuevo, float angulo_nuevo);
		void mueveDerecha(float i);
};
#endif
