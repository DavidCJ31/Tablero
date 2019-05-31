#ifndef LETRAS_H
#define LETRAS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Fichas {
private:
	int cantidad;
	int valor;
	int Valores[23];
	int CopiaValores[23];
	int numeros[12];
	string fichasJ[12];
	string CopiaLetras[23];
	string Letra[23];
	string letra;
	ifstream lee;
	ofstream Guarda;
public:
	Fichas();
	~Fichas();
	void EliminarLetra(string);
	void MostrarCadena();
	string RellenaL();
	int RecorreValores(int);
	int TomarCantidad();
	string Repartir(int);
};
#endif // !LETRAS_H
