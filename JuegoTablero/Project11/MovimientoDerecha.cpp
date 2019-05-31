#include "MovimientoDerecha.h"

MovimientoDerecha::MovimientoDerecha()
{
}

MovimientoDerecha::~MovimientoDerecha()
{
}

int MovimientoDerecha::movimiento(Tablero &tablero, int i, int j)
{
	tablero.setTablero(i - 2, j + 2);
	tablero.setVacio(i - 1, j + 1);
	tablero.setVacio( i, j);
	cout << "movimiento derecha" << endl;
	return 1;
}
