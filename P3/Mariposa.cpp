#include "Mariposa.hpp"

Mariposa::Mariposa(float h_inicial, float alpha_inicial){
	h = h_inicial;
	alpha = alpha_inicial;
	agregar(new Flor);
	agregar(MAT_Escalado(1.0,1.0,1.0));
	agregar(MAT_Escalado(1.0,1.0,1.0));
	agregar(MAT_Escalado(1.0,1.0,1.0));
	agregar(MAT_Escalado(1.0,1.0,1.0));
	agregar(new Cuerpo);
	agregar(new Alas);
}

void Mariposa::fijarAlpha(float alpha_nuevo){
	alpha = alpha_nuevo;
	*(entradas[1].matriz) = MAT_Rotacion(alpha_nuevo,0,0,1);
}

void Mariposa::mueveDerecha(float i){
	*(entradas[4].matriz) = MAT_Traslacion(i,1.0,1.0);
}

void Mariposa::fijarVuelta(float alpha_nuevo, float angulo_nuevo){
	alpha = alpha_nuevo;
	*(entradas[2].matriz) = MAT_Traslacion((cos(alpha_nuevo)+sin(alpha_nuevo)),0,(-sin(alpha_nuevo)+cos(alpha_nuevo)));
	*(entradas[3].matriz) = MAT_Rotacion(angulo_nuevo,0,1,0);
}

void Mariposa::fijarH(float h_nuevo){
	h = h_nuevo;
	Alas *hijo = (Alas *) entradas[6].objeto;
	hijo->fijarH(h_nuevo);
}

void Mariposa::fijarHA(float h_nuevo){
	h = h_nuevo;
	Flor *hijo1 = (Flor *) entradas[0].objeto;
	hijo1->fijarH(h_nuevo);
}

Cuerpo::Cuerpo(){
	agregar(MAT_Traslacion(0.0,2.0,0.0));
	agregar(MAT_Escalado(0.05,0.05,0.05));
	agregar(new MallaPLY("../plys/ant.ply"));
}

Alas::Alas(){
	agregar(MAT_Traslacion(0.0,2.0,0.0));
	agregar(MAT_Escalado(0,0,0));
	agregar(new MallaPLY("../plys/butterfly.ply"));
}

void Alas::fijarH(float h_nuevo){
	*(entradas[1].matriz) = MAT_Escalado(h_nuevo,h_nuevo,h_nuevo);
}

Flor::Flor(){
	agregar(MAT_Escalado(0,0,0));
	agregar(MAT_Traslacion(0.0,7.0,0.0));
	agregar(new MallaPLY("../plys/flower.ply"));
}

void Flor::fijarH(float h_nuevo){
	*(entradas[0].matriz) = MAT_Escalado(h_nuevo/2,h_nuevo/2,h_nuevo/2);
}

