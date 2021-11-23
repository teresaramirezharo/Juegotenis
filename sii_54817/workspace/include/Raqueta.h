// Raqueta.h: interface for the Raqueta class.
//
//////////////////////////////////////////////////////////////////////
#ifndef Raqueta_

#define Raqueta_

#include "Plano.h"
#include "Vector2D.h"



class Raqueta : public Plano  
{
public:
	Vector2D velocidad;

	Raqueta();
	virtual ~Raqueta();

	void Mueve(float t);
};

#endif
