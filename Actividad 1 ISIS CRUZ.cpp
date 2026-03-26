/******************************************************************************

Programa: Mayor o Menor de edad.
Autor: isis Cruz
Fecha: 25/marzo/2026

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {

	string nombre;
	int edad;

	cout << "Ingresa tu nombre: ";
	cin >> nombre;

	cout << "Ingresa tu edad: ";
	cin >> edad;

	if (edad >= 18) {

		cout << " Bienvenido " << nombre << ", Eres mayor de edad."<< endl;
	} else {
		cout <<  "Bienvenido " << nombre << ", Eres menor de edad, lo siento." << endl;
	}
	return 0;
}