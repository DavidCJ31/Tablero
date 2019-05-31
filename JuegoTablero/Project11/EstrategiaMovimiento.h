#pragma once
#include "Tablero.h"

class EstrategiaMovimiento
{
public:
	EstrategiaMovimiento();
	~EstrategiaMovimiento();
	virtual int movimiento(Tablero&,int,int) = 0;
};