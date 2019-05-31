#include "Juego.h"

Juego::Juego()
{
	punteroLetra = new Fichas();
	punteroTablero = new Tablero();
	turno = 0;
	_letra = "";
	_valor = 0;
	punto = 12;
}

Juego::~Juego(){}


void Juego::MostrarFichas() {
	for (int i = 0; i < 12; i++) {
		cout << "[" << FichasJugador[i] << "]";
	}
}


/*
Instrucciones del tablero
*/
void Juego::instrucciones()
{
	cout << "BIENVENIDOS A DAMAS ESPANOLAS (TABLERO)" << endl;
	cout << "HECHO POR DAVID CORDERO J. & SAMANTA ALFARO C." << endl;
	cout << "Las damas es un juego de mesa para dos contrincantes." << endl;
	cout << "El juego consiste en mover las piezas en diagonal" << endl;
	cout << "a traves de los cuadros de un tablero" << endl;
	cout << "con la intencion de capturar(comer) las piezas del jugador contrario" << endl;
	cout << "pasando por encima de dichas piezas." << endl;
	cout << "Cada jugador dispone de 12 piezas de un mismo color(uno O y otro X)" << endl;
	cout << "que al principio de la partida se colocan en las casillas." << endl;
	cout << "El objetivo del juego de damas es capturar las fichas del oponente o acorralarlas" << endl;
	cout << "para que los unicos movimientos que puedan realizar sean los que lleven a su captura." << endl;
	cout << "Se juega por turnos alternos." << endl;
	cout << "Empieza a jugar quien tiene las fichas claras(O)." << endl;
	cout << "En su turno cada jugador mueve una pieza propia." << endl;
	cout << "Las piezas se mueven(cuando no comen) una posición adelante(nunca hacia atrás) " << endl;
	cout << "en diagonal a la derecha o a la izquierda, a una posición adyacente vacía." << endl;

	cout << endl;
	cout << endl;
}

void Juego::menu() {
	char opcion = '0';
	system("Color 2");
	cout << endl;
	cout << "BIENVENIDOS A DAMAS ESPANOLAS (TABLERO)" << endl;
	cout << "[1] Como jugar" << endl;
	cout << "[2] Jugar" << endl;
	try {
	cout << "Digite la opcion que desea: "; cin >> opcion;
	system("cls");
		switch (opcion) {
		case '1': { instrucciones();
			system("pause");
			system("cls");
			menu();
			break;
		}
		case '2':
			break;
		default: cout << "Opcion no disponible" << endl;
			menu();
			break;
		}
	}
	catch (...) {
		menu();
	}
}

void Juego::MenuJugador() {
	int opcion = 0;
	string _palabra;
	cout << endl;

	system("cls");
	Insertar();
	system("cls");
}


void Juego::constructorJugadores()
{
	string nombre;
	int CPU;
		Jugador A;
		Jugador B;
		punteroJugador = new Jugador[2];
		punteroJugador[0] = A;
		punteroJugador[1] = B;
		cout << "Nombre Jugador 1" << endl;
		cin >> nombre;
		punteroJugador[0].setNombre(nombre);
		srand(time(NULL));
		CPU = rand()%4;
		switch (CPU)
		{
		case 0:
			nombre = "Laura";
			break;
		case 1:
			nombre = "Juan";
			break;
		case 2:
			nombre = "Maria";
			break;
		case 3:
			nombre = "Joel";
			break;
		case 4:
			nombre = "Fernanda";
			break;
		default:
			nombre = "Goku";
			break;
		}
		punteroJugador[1].setNombre(nombre);
		punteroJugador[0].setTurno(true);
		punteroJugador[1].setTurno(false);
		turno = 0;
		for (int i = indiceF; i < 12; i++) {
			punteroJugador[0].ColocarFichas(punteroLetra->Repartir(i));
		}
		indiceF = 12;
		for (int i = indiceF; i < 24; i++) {
			punteroJugador[1].ColocarFichas(punteroLetra->Repartir(i));
		}
}

void Juego::Jugar() {
	menu();
	punteroTablero->MostrarTablero();
	constructorJugadores();
	system("pause");
	system("cls");
	do {
			if (punteroJugador[0].getTurno() == true && punteroJugador[1].getTurno() == false) {
				cout << endl;
				MenuJugador();
				punteroJugador[0].setTurno(false);
				punteroJugador[1].setTurno(true);
				turno = 1;
				cout << endl;
			}
			else {
				if (punteroJugador[1].getTurno() == true && punteroJugador[0].getTurno() == false) {
					MenuJugador();
					cout << endl;
					punteroJugador[1].setTurno(false);
					punteroJugador[0].setTurno(true);
					turno = 0;
					cout << endl;
				}
			}
} while (Ganador() == false);
    _Ganador();
	system("pause");
	system("cls");
}

bool Juego::validacionLetra(string _letra) {
		if (punteroJugador[turno].validarLetra(_letra) == true) {
			return true;
		}
		else {
			return false;
		}
}

void Juego::Insertar()
{
	int opcion = 1;
	int fila, Nfila;
	int columna, Ncolumna;
	string ficha;
	bool bandera = true;
	bool respuesta = true;
	char otra;
		do {
			int i = 0;
			system("cls");
			punteroTablero->MostrarTablero();
			if (punteroJugador[0].getTurno()) {
				do {
					cout << endl; cout << "JUGADOR [1]: " << punteroJugador[turno].getNombre() << endl;
					cout << "Fichas comidas " << punteroJugador[turno].getPuntosTotales() << endl;
					punteroJugador[0].MostrarFichas();
					cout << "Cantidad " << punteroJugador[0].getCantidad() << endl;
					cout << "Escoja una ficha" << endl;
					cout << "Fila: "; cin >> fila; cout << endl;
					cout << "Columna: "; cin >> columna; cout << endl;
					fila = renderizaFila(fila);
					if (punteroTablero->Inserta(fila, columna - 1) == true && punteroTablero->RetonarPosicion(fila, columna - 1) == "O") {
						while (punteroTablero->verificaComerJ(fila, columna - 1)) {
							punteroTablero->MostrarTablero();
							cout << "Nueva posicion" << endl;
							cout << "Fila: "; cin >> Nfila; cout << endl;
							cout << "Columna: "; cin >> Ncolumna; cout << endl;
							Nfila = renderizaFila(Nfila);
							if (!verificaMovimientoCruzado(columna - 1, Ncolumna - 1) && verificaMovimientoValido(fila, Nfila, 0) && verificaMovimientoDiagonal(fila, Nfila)) {
								punteroTablero->eliminaFicha(Nfila, columna, Ncolumna); //Elmimina posicion comida
								punteroTablero->InsertarTablero(fila, columna - 1, Nfila, Ncolumna - 1);
								system("cls");
								cout << "Movimiento correcto" << endl;
								fila = Nfila;
								columna = Ncolumna;
								punteroJugador[1].tomarLetraJugador();
								punteroJugador[0].setPuntosTotales(1);
								system("pause");
								opcion = 0;
								bandera = false;
							}
							else {
								cout << "No es un movimineto valido aa" << endl;
								system("pause");
							}
						}
						if (bandera == true && opcion == 1) {
							cout << "Nueva posicion" << endl;
							cout << "Fila: "; cin >> Nfila; cout << endl;
							cout << "Columna: "; cin >> Ncolumna; cout << endl;
							Nfila = renderizaFila(Nfila);
							if (!verificaMovimientoCruzado(columna - 1, Ncolumna - 1) && verificaMovimientoValido(fila, Nfila, 0) && !verificaMovimientoDiagonal(fila, Nfila) && validaOcupado(Nfila, columna, Ncolumna)) {
								punteroTablero->InsertarTablero(fila, columna - 1, Nfila, Ncolumna - 1);
								system("cls");
								cout << "Movimiento correcto" << endl;
								system("pause");
								opcion = 0;
							}
							else {
								cout << "No es un movimineto valido bb" << endl;
								system("pause");
							}
						}
					}
					else {
						cout << "No tienes fichas en esa pocision" << endl;
						system("pause");
					}
				} while (!respuesta);
			}
			else {
				cout << endl; cout << "CPU [2]: " << punteroJugador[turno].getNombre() << endl;
				cout << "Fichas comidas " << punteroJugador[turno].getPuntosTotales() << endl;
				punteroJugador[1].MostrarFichas();
				cout << "Cantidad " << punteroJugador[1].getCantidad() << endl;

				// CPU
				cout<<punteroJugador[1].analiza(*punteroTablero)<<endl;

//				punteroJugador[1].analiza(*punteroTablero);
//				getEstrategia()->movimiento(*punteroTablero);

				system("pause");
				opcion = 0;

			}

		} while (opcion != 0);
}


bool Juego::ValidaPrimeraVez(int fila, int columna) {	
	return (fila == 7 || columna == 7);
}

bool Juego::Ganador() {
	if (punteroJugador[0].getCantidad() == 0 || punteroJugador[1].getCantidad() == 0) {
		return true;
	}
	return false;
}

void Juego::_Ganador() {

	if (punteroJugador[0].getCantidad() > punteroJugador[1].getCantidad()) {
		cout << "EL GANADOR ES: " << punteroJugador[0].getNombre() << endl;
	}
	else {
		cout << "EL GANADOR ES: " << punteroJugador[1].getNombre() << endl;
	}
}

int Juego::renderizaFila(int fila)
{
	switch (fila)
	{
	case 1:
		fila = 7;
		break;
	case 2:
		fila = 6;
		break;
	case 3:
		fila = 5;
		break;
	case 4:
		fila = 4;
		break;
	case 5:
		fila = 3;
		break;
	case 6:
		fila = 2;
		break;
	case 7:
		fila = 1;
		break;
	case 8:
		fila = 0;
		break;
	default:
		cerr << "Posicion invalida";
		break;
	}
	return fila;
}

bool Juego::verificaMovimientoCruzado(int columna, int Ncolumna)
{
	return columna==Ncolumna;
}

bool Juego::verificaMovimientoDiagonal(int fila, int Nfila) //Reparar este metodo
{
	return (Nfila - fila >= 2);
}

bool Juego::validaOcupado(int Nfila, int columna,int Ncolumna)
{
	cout << punteroTablero->getTablero(Nfila, Ncolumna) << endl;
	system("pause");
	if (columna < Ncolumna) {
		if (punteroTablero->getTablero(Nfila, Ncolumna + 1) == "X" || punteroTablero->getTablero(Nfila, Ncolumna + 1) == "O") {
			cout << punteroTablero->getTablero(Nfila, Ncolumna+1) << endl;
			system("pause");
			return false;
		}
	}
	if (columna > Ncolumna) {
		if (punteroTablero->getTablero(Nfila, Ncolumna - 1) == "X" || punteroTablero->getTablero(Nfila, Ncolumna - 1) == "O") {
			cout << punteroTablero->getTablero(Nfila, Ncolumna-1) << endl;
			system("pause");
			return false;
		}
	}
	return true;
}

bool Juego::verificaMovimientoValido(int fila, int Nfila, int jugador)
{
	if (fila == Nfila) {
		return false;
	}
	if (jugador == 0) {
		return fila < Nfila;
	}
	else {
		return fila > Nfila;
	}
	return false;
}