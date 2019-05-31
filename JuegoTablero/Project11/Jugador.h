#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <string>
#include "EstrategiaMovimiento.h"
#include "MovimientoDerecha.h"
#include "MovimientoIzquierda.h"

using namespace std;
const int Ntablero = 8;

class Jugador {
private:
	string nombreJugador;
	string fichasJugador[12];
	string RespaldoFichas[12];
	bool turnoJugador;
	int contador;
	int puntosTotales;
	int I;
	int contadorTurnos;
	int cantidad;
	//CPU
	//Estrategia
	EstrategiaMovimiento *estrategia;
	EstrategiaMovimiento* getEstrategia();
	void setEstrategia(EstrategiaMovimiento*);

public:
	Jugador();
	~Jugador();
	void setNombre(string);
	void setPuntosTotales(int);
	int getPuntosTotales();
	void setTurno(bool);
	void setContadorTurnos(int);
	int getContadorTurnos();
	int getCantidad();
	void ColocarFichas(string);
	string getNombre();
	bool getTurno();
	void MostrarFichas();
	bool validarLetra(string);
	void tomarLetraJugador();
	void cambiarLetraJugador(string,string &);
	void Rellenar(string);
	void DevolverFichas();
	string RetornaLetra(int);

	//CPU

	int analiza(Tablero&);
	int mueveXFicha(Tablero&);


};
#endif // !JUEGADOR_H