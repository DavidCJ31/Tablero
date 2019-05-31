#include "MovimientoIzquierda.h"

MovimientoIzquierda::MovimientoIzquierda()
{
}

MovimientoIzquierda::~MovimientoIzquierda()
{
}

int MovimientoIzquierda::movimiento(Tablero &tablero, int i, int j)
{
	tablero.setTablero(i - 2, j - 2);
	tablero.setVacio(i - 1, j - 1);
	tablero.setVacio(i, j);
	cout << "movimiento izquierda" << endl;
	return 1;
}
