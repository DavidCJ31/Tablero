#pragma once
#include "EstrategiaMovimiento.h"

class MovimientoIzquierda: public EstrategiaMovimiento
{
public:
	MovimientoIzquierda();
	~MovimientoIzquierda();
	virtual int movimiento(Tablero&, int, int);
};