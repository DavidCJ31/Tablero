#include <iostream>
#include "Fichas.h"
#include "Tablero.h"
#include "Juego.h"
using namespace std;
int main() {
	bool opcion;
	short unsigned int contador = 0;
	do {
		Juego *punteroDamasEspanolas = new Juego;
		//if (contador == 0) {
		//	punteroScrabble->instrucciones();
		//}
		punteroDamasEspanolas->Jugar();
		punteroDamasEspanolas = NULL;
		system("cls");
		cout << "NUEVO JUEGO [1]" << endl;
		cout << "SALIR [0]" << endl;
		cin >> opcion;
		contador++;
	} while (opcion != 0);
	cout << "GRACIAS POR JUGAR" << endl;
	system("pause");
	cin.ignore();
}