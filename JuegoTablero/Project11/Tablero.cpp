#include "Tablero.h"

Tablero::Tablero()
{
	blanco = 178;
	negro = 177;
	contador = 1;
	for (int i = 0; i<_cantidad; i++)
	{
		for (int j = 0; j<_cantidad; j++)
		{

			if (i <= 2 && ((j + i) % 2 == 0))
			{
				_Tablero[i][j] = "O";
			}



			else if (i >= 5 && ((j + i) % 2 == 0)) {
				_Tablero[i][j] = "X";
			}
			else {
				_Tablero[i][j] = "  ";
			}
		}/*FIN FOR J */  //SALTO DE LINEA 
	}//FIN FOR I
}

void Tablero::MostrarTablero() { //Mostrar bien
	system("color 2");
	cout << endl; 
	cout << endl;
	for (int i = 0; i<_cantidad; i++)
	{
		//cout << i;//ESTA I SIRVE PARA INDICAR COORDENADAS VERTICALES 
		cout << " " << _cantidad - i << "  |";
		for (int j = 0; j<_cantidad; j++)
		{
			if ((_Tablero[i][j] == "X" || _Tablero[i][j] == "O" || _Tablero[i][j] == "C" || _Tablero[i][j] == "D") && ((j + i) % 2 == 0))
			{
				cout << blanco << blanco << _Tablero[i][j] << blanco << blanco;
			}
			else if (_Tablero[i][j] == "  " && (j + i) % 2 != 0)
			{
				cout << negro << negro << negro << negro << negro;
			}
			else if (_Tablero[i][j] == "  " && (j + i) % 2 == 0)
			{
				cout << blanco << blanco << blanco << blanco << blanco; ;
			}
		}/*FIN FOR J */cout << endl;  //SALTO DE LINEA 
	}//FIN FOR I
	 for (int i = 1; i < _cantidad + 1; i++) {
	 	if (i == 1)
	 		cout << "       " << i;
	 	if(i > 1 && i < 3)
	 		cout << "    " << i;
	 	if (i >= 3 && i <= 8)
	 		cout << "    " << i;

	 }
	cout << endl;
}

void Tablero::InsertarTablero(int fila, int columna, int Nfila, int Ncolumna) {
	_Tablero[Nfila][Ncolumna] = _Tablero[fila][columna];
	_Tablero[fila][columna] = "  ";
}


void Tablero::GuardaPosiciones(int fila, int columna) {
	GuardaContenido[Devolver] = _Tablero[fila][columna];
	Devolver++;
}

bool Tablero::verificaComerJ(int fila, int columna)
{
	cout << "Fila: " << fila << " Columna: " << columna << endl;
	if (fila == 6 || fila == 7 && (columna == 1 || columna == 0 || columna == 6 || columna == 7))
		return false;

	if (_Tablero[fila + 1][columna - 1] == "X" && _Tablero[fila + 2][columna - 2] == "  ") {
		cout << " Comer a la izquierda " << endl;
		return true;
	}
	if (_Tablero[fila + 1][columna + 1] == "X" && _Tablero[fila + 2][columna + 2] == "  ") {
		cout << " Comer a la derecha " << endl;
		return true;
	}
	return false;
}

string Tablero::verificaComerCPU(int fila, int columna)
{
	string comer = "0000";
	if (fila == 1 || fila == 0 && (columna == 1 || columna == 0 || columna == 6 || columna == 7))
		return "0000";

	if (_Tablero[fila][columna] == "X" && _Tablero[fila - 1][columna - 1] == "O" && _Tablero[fila - 2][columna - 2] == "  ") {
		cout << " Comer a la izquierda " << endl;
		comer = std::to_string(fila); // C++11
		comer += std::to_string(columna);
		comer += "11";
		if ((columna == 0 || columna == 1))
			comer = "0000";
	}

	if (_Tablero[fila][columna] == "X" && _Tablero[fila - 1][columna + 1] == "O" && _Tablero[fila - 2][columna + 2] == "  ") {
		cout << " Comer a la derecha " << endl;
		comer = std::to_string(fila); // C++11
		comer += std::to_string(columna);
		comer += "12";
		if ((columna == 6 || columna == 7))
			comer = "0000";
	}
	return comer;
}

void Tablero::eliminaFicha(int fila,int columna, int Ncolumna)
{
	if (columna > Ncolumna) {
		cout << "Fila " << fila << " Columna " << columna << endl;
		cout << "Izquierda" << endl;
		system("pause");
		_Tablero[fila - 1][Ncolumna] = "  ";
	}
	if (columna < Ncolumna) {
		cout << "Fila " << fila << " Columna " << Ncolumna << endl;
		cout << "Derecha" << endl;
		system("pause");
		_Tablero[fila - 1][Ncolumna - 2] = "  ";
	}
}


bool Tablero::valida(int f, int c)
{
	return _Tablero[f][c] == "O" || _Tablero[f][c] == "X";
}

string Tablero::RetonarPosicion(int fila, int columna)
{
	return _Tablero[fila][columna];
}

string Tablero::RetornaPremio(int i) {
	return GuardaContenido[i];
}

bool Tablero::Inserta( int f, int c)
{
	if (valida(f, c) == true) {
		return true;
	}
	return false;
}

string Tablero::getTablero(int i, int j)
{
	return _Tablero[i][j];
}

void Tablero::setTablero(int i, int j)
{
	_Tablero[i][j] = "X";
}

void Tablero::setVacio(int i, int j)
{
	_Tablero[i][j] = "  ";
}

string Tablero::verificaXMovimiento(int, int)
{
	string comer = "0000";
	if (fila == 1 || fila == 0 && (columna == 1 || columna == 0 || columna == 6 || columna == 7))
		return "0000";

	if (_Tablero[fila][columna] == "X" && _Tablero[fila - 1][columna - 1] == "O" && _Tablero[fila - 2][columna - 2] == "  ") {
		cout << " Comer a la izquierda " << endl;
		comer = std::to_string(fila); // C++11
		comer += std::to_string(columna);
		comer += "11";
		if ((columna == 0 || columna == 1))
			comer = "0000";
	}

	if (_Tablero[fila][columna] == "X" && _Tablero[fila - 1][columna + 1] == "O" && _Tablero[fila - 2][columna + 2] == "  ") {
		cout << " Comer a la derecha " << endl;
		comer = std::to_string(fila); // C++11
		comer += std::to_string(columna);
		comer += "12";
		if ((columna == 6 || columna == 7))
			comer = "0000";
	}
	return comer;
}

