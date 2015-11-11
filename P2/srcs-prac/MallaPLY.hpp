#ifndef MALLAPLY_HPP
#define MALLAPLY_HPP

#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include <vector>
#include "aux.hpp"
#include "MallaInd.hpp"
#include "file_ply_stl.hpp"

class MallaPLY : public MallaInd {
   public:
			std::vector<float> vertices;
			std::vector<int> caras;
      MallaPLY( const char *nombre_arch ) ; 
} ;

#endif
