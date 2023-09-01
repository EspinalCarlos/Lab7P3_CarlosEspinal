#pragma once
#include <iostream>
#include <string>
template <typename T>
class Resena{
	Producto<T> producto;
	string comentario;
	int calificacion;
public:
	Resena(Producto<T> product, string comment, int calif) {
		producto = product;
		comentario = comment;
		calificacion = calif;
	}
	Producto<T> getProducto() {
		return producto;
	}
	string getComentario() {
		return comentario;
	}
	int getCalificacion() {
		return calificacion;
	}
	void toString() {
		cout << "Producto: \n" << "Comentario: " << comentario << endl << "Calificacion: " << calificacion;
	}

};

