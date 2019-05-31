#include "Jugador.h"

Jugador::Jugador() {
	contador = 0;
	puntosTotales = 0;
	I = 0;
	contadorTurnos = 0;
	cantidad = 12;
	estrategia = new MovimientoDerecha();
}

Jugador::~Jugador() {}

void Jugador::setNombre(string nombreJugador)
{
	this->nombreJugador = nombreJugador;
}

void Jugador::setPuntosTotales(int puntos)
{
	this->puntosTotales += puntos;
}

int Jugador::getPuntosTotales()
{
	return puntosTotales;
}

void Jugador::setTurno(bool turnoJugador)
{
	this->turnoJugador = turnoJugador;
}

void Jugador::setContadorTurnos(int contadorTurnos)
{
	this->contadorTurnos = contadorTurnos;
}

int Jugador::getContadorTurnos()
{
	return this->contadorTurnos;
}

int Jugador::getCantidad()
{
	return cantidad;
}



string Jugador::getNombre()
{
	return this->nombreJugador;
}

bool Jugador::getTurno()
{
	return this->turnoJugador;
}


void Jugador::ColocarFichas(string _fichasJugador) {
	fichasJugador[contador++] = _fichasJugador;
}

void Jugador::MostrarFichas() {
	for (int i = 0; i < cantidad; i++) {
		cout << "[" << fichasJugador[i] << "]";
	}
	cout << endl;
}

bool Jugador::validarLetra(string _letra) {
	for (int i = 0; i < cantidad; i++) {
		if (fichasJugador[i] == _letra) {
			return true;
		}
	}
	return false;
}

void Jugador::tomarLetraJugador()
{
	cantidad--;
}

void Jugador::cambiarLetraJugador(string _letra,string &_nuevaLetra) {
	for (int i = 0; i < cantidad; i++) {
		if (fichasJugador[i] == _letra) {
			fichasJugador[i] = _nuevaLetra;
			break;
		}
	}
}

void Jugador::Rellenar(string letra) {
	for (int i = 0; i < cantidad; i++) {
		if (fichasJugador[i] == " ") {
			fichasJugador[i] = letra;
			break;
		}
	}
}

void Jugador::DevolverFichas() {
	int CONTA = 0;
	for (int i = 0; i < cantidad; i++) {
		if (fichasJugador[i] == " ") {
			fichasJugador[i] = RespaldoFichas[CONTA];
			CONTA++;
		}
	}
	I = 0;
}

string Jugador::RetornaLetra(int i) {
	return fichasJugador[i];
}

int Jugador::analiza(Tablero &tablero)
{
	cout << "TURNO COMPUTADORA PENSANDO JUGADA...." << endl;
	int I = 0;
	int J = 0;
	string comer = "0000";
	string aux;
	string n1,n2,n3,n4;
	for (int i = 0; i < Ntablero; i++) {
		for (int j = 0; j < Ntablero; j++) {
			comer = tablero.verificaComerCPU(i, j);
			if (comer != "0000") {
				cout << "Comer:-> " << comer << endl;
				I = i;
				J = j;
				aux = comer;
				n1 = aux[0];
				n2 = aux[1];
				n3 = aux[2];
				n4 = aux[3];
			}
			comer.clear();
		}
	}

	//cout <<"Fila: "<< n1 << " " << I << endl;
	//cout << "Columna: " << n2 << " " << J << endl;
	//cout << "Comer: " << n3 << endl;
	//cout << "Direccion: " << n4 << endl;
	cout << "Comer " << aux << endl;
//	system("pause");

	if (n3 == "1" && n4 == "2") {
		setEstrategia(new MovimientoDerecha());
		estrategia->movimiento(tablero, I, J);
	}
	if (n3 == "1" && n4 == "1") {
		setEstrategia(new MovimientoIzquierda());
		estrategia->movimiento(tablero, I, J);
	}

	return 0;
}

int Jugador::mueveXFicha(Tablero &tablero)
{
	int I = 0;
	int J = 0;
	string comer = "0000";
	string aux;
	string n1, n2, n3, n4;
	for (int i = 0; i < Ntablero; i++) {
		for (int j = 0; j < Ntablero; j++) {
			comer = tablero.verificaComerCPU(i, j);
			if (comer != "0000") {
				I = i;
				J = j;
				aux = comer;
				n1 = aux[0];
				n2 = aux[1];
				n3 = aux[2];
			}
			comer.clear();
		}
	}

	if (n3 == "0" && n4 == "0") {

	}
	if (n3 == "0" && n4 == "0") {

	}

	return 0;
}

EstrategiaMovimiento * Jugador::getEstrategia()
{
	return estrategia;
}

void Jugador::setEstrategia(EstrategiaMovimiento *estrategia)
{
	this->estrategia = estrategia;
}
