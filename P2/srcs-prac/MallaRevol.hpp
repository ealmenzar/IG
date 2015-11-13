#ifndef MALLAREVOLHPP
#define MALLAREVOL_HPP

#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include <vector>
#include "aux.hpp"
#include "MallaInd.hpp"
#include "file_ply_stl.hpp"

class MallaRevol : public MallaInd {
   public:
      MallaRevol(const char *nombre_arch, unsigned nperfiles); 
			std::vector<float> vertices;
			
} ;
#endif
