#include "Fichas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
Fichas::Fichas()   //LISTO
{
	cantidad = 24;
	lee.open("Letras.dat", ios::in | ios::binary);
	int _contador = 0;
	while (!lee.eof()) {
		lee >> letra;
		fichasJ[_contador] = letra;
		_contador++;
	}
	lee.close();
}

Fichas::~Fichas() {}


//Eliminar 
void Fichas::EliminarLetra(string _letra) {  //LISTO
	bool bandera = false;
	for (int i = 0; i < cantidad; i++) {
		if (bandera != true) {
			if (Letra[i] == _letra) {
				for (int j = i; j < cantidad; j++) {
					Letra[j] = Letra[j + 1];
					Valores[j] = Valores[j + 1];
				}
				bandera = true;
			}
		}
	}
	cantidad--;
}

void Fichas::MostrarCadena() {   //LISTO
	for (int i = 0; i < cantidad; i++) {
		cout << "[" << Letra[i] << "]";
	}
}

string Fichas::RellenaL() { //LISTO
	int ficha;
	string aux;
	ficha = rand() % cantidad;
	aux = Letra[ficha];
	EliminarLetra(Letra[ficha]);
	return aux;
}

int Fichas::RecorreValores(int i)
{
	return CopiaValores[i];
}

int Fichas::TomarCantidad() {
	return cantidad;
}

string Fichas::Repartir(int i) {
	return fichasJ[i];
}