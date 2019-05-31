#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Fichas.h"
#include "Tablero.h"
#include "Jugador.h"

using namespace std;
class Juego {
private:
	Fichas * punteroLetra;
	Tablero *punteroTablero;
	Jugador *punteroJugador;

	string FichasJugador[12];
	int numeroLetras;
	string _letra;
	int _valor;
	int cantidadJugadores;
	int contador = 0;
	int turno;
	int fila;
	int columna;
	string copiaPalabra[12];
	string palabraHorizontal;
	string palabraVertical;
	int Devolver = 0;
	int Suma = 0;
	int punto = 12;
	int indiceF = 0;

	//METODOS
	bool ValidaPrimeraVez(int, int);
	void Insertar();
	bool validacionLetra(string);
	bool Ganador();
	void MostrarFichas();
	void MenuJugador();
	void menu();
	void constructorJugadores();
	void _Ganador();
	int renderizaFila(int);
	bool verificaMovimientoCruzado(int,int);
	bool verificaMovimientoValido(int, int, int);
	bool verificaMovimientoDiagonal(int, int);
	bool validaOcupado(int,int,int);
public:

	Juego();
	~Juego();
	void instrucciones();
	void Jugar();
};
#endif // !JUEGO_H