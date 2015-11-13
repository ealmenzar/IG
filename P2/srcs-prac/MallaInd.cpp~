#include "MallaInd.hpp"
 
void MallaInd::visualizar(unsigned modo_vis){
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, &tablaVertices.front());
	//glColor3f(1,1,0);

	switch(modo_vis){
		case 0:
			glEnableClientState(GL_VERTEX_ARRAY);
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			glDrawElements(GL_TRIANGLES, tablaCaras.size()*3, GL_UNSIGNED_INT, &tablaCaras.front());
			glDisableClientState(GL_VERTEX_ARRAY);
		break;
		case 1:
			glEnableClientState(GL_VERTEX_ARRAY);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDrawElements(GL_TRIANGLES, tablaCaras.size()*3, GL_UNSIGNED_INT, &tablaCaras.front());
			glDisableClientState(GL_VERTEX_ARRAY);
		break;
		case 2:
			glEnableClientState(GL_VERTEX_ARRAY);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawElements(GL_TRIANGLES, tablaCaras.size()*3, GL_UNSIGNED_INT, &tablaCaras.front());
			glDisableClientState(GL_VERTEX_ARRAY);
		break;
		case 3:
			glEnableClientState(GL_VERTEX_ARRAY);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			for (int i=0; i<=tablaCaras.size(); i++){
				if (i%2==0){
					caraColor1.push_back(tablaCaras[i]);
				}
				else{
					caraColor2.push_back(tablaCaras[i]);
				}
			}
			glColor3f(0.3,0.1,0.27);
			glDrawElements(GL_TRIANGLES, caraColor1.size()*3, GL_UNSIGNED_INT, &caraColor1.front());
			glColor3f(0.4,0.05,0.16);
			glDrawElements(GL_TRIANGLES, caraColor2.size()*3, GL_UNSIGNED_INT, &caraColor2.front());
			glDisableClientState(GL_VERTEX_ARRAY);
		break;

	}
}

