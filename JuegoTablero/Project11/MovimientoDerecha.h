#pragma once

#include "EstrategiaMovimiento.h"

class MovimientoDerecha: public EstrategiaMovimiento
{
public:
	MovimientoDerecha();
	~MovimientoDerecha();
	virtual int movimiento(Tablero&, int, int);
};