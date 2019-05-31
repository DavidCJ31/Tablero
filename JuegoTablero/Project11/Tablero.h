#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
const int _cantidad = 8;
class Tablero {
private:
	string _Tablero[_cantidad][_cantidad];
	string GuardaContenido[7];
	int Devolver = 0;
	char blanco = 178;
	char negro = 177;
	int  contador = 1;
public:
	Tablero();
	void MostrarTablero();

	void InsertarTablero(int, int, int, int);
	void GuardaPosiciones(int, int);
	bool verificaComerJ(int, int);
	string verificaComerCPU(int, int);
	void eliminaFicha(int,int, int);
	bool valida(int, int);
	string RetonarPosicion(int, int);
	string RetornaPremio(int);
	bool Inserta(int, int);
	string getTablero(int,int);
	void setTablero(int,int);
	void setVacio(int, int);
	string verificaXMovimiento(int,int);
};
#endif // !TABLERO_H