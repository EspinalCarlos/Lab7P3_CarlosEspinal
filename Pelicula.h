#pragma once
#include "Producto.h"
#include <iostream>
#include <string>

using namespace std;
class Pelicula:public Producto<Pelicula>{
	string titulo;
	string director;
	int duracion;
public:
	Pelicula(int ident, float price, int st, string title, string direct, int duration):Producto<Pelicula>(ident,price,st) {
		titulo = title;
		director = direct;
		duracion = duration;
	}
	~Pelicula(){}
	string getTitulo() {
		return titulo;
	}
	string getDirector() {
		return director;
	}
	int getDuracion() {
		return duracion;
	}
	void toString() {
		cout << "ID: " << id << endl << "Precio: " << precio << endl << "Stock: " << stock << endl << "Titulo: " << titulo << endl << "Director(a): " << director << endl << "Duracion: " << duracion << "\n\n";
	}
};

