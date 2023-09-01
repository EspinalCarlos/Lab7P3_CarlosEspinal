#pragma once
#include "Producto.h"
#include <string>
using namespace std;
class Libro :public Producto<Libro> {
	string titulo;
	string autor;
	int numPaginas;
public:
	Libro(int ident, float price, int st, string title, string author, int numPages):Producto<Libro>(ident,price,st){
		titulo = title;
		autor = author;
		numPaginas = numPages;
	}
	~Libro(){}
	string getTitulo() {
		return titulo;
	}
	string getAutor() {
		return autor;
	}
	int getNumPaginas() {
		return numPaginas;
	}
	void toString(){
		cout << "ID: " << id << endl << "Precio: "<< precio << endl << "Stock: "<< stock << endl << "Titulo: "<< titulo << endl << "Autor(a): "<< autor << endl << "Numero de paginas: " << numPaginas << "\n\n";
	}
};

