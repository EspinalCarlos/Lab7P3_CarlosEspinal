#pragma once
#include "Producto.h"
#include <string>
#include <iostream>
using namespace std;
class Disco:public Producto<Disco>{
	string titulo;
	string artista;
	int numCanciones;
public:
	Disco(int ident, float price, int st, string title, string artist, int cnum) :Producto<Disco>(ident, price, st) {
		titulo = title;
		artista = artist;
		numCanciones = cnum;
	}
	~Disco(){}
	string getTitulo() {
		return titulo;
	}
	string getArtista() {
		return artista;
	}
	int getNumCanciones() {
		return numCanciones;
	}
	void toString() {
		cout << "ID: " << id << endl << "Precio: " << precio << endl << "Stock: " << stock << endl << "Titulo: " << titulo << endl << "Artista: "<< artista << endl << "Numero de Canciones: "<< numCanciones << "\n\n";
	}
};

