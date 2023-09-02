#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Resena{
	T temp;
	string comentario;
	int calificacion;
public:
	Resena() {}
	Resena(string comment, int calif) {
		comentario = comment;
		calificacion = calif;
	}
	T getProducto() {
		return temp;
	}

	void setProducto(T t) {
		temp = t;
	}
	
	string getComentario() {
		return comentario;
	}
	int getCalificacion() {
		return calificacion;
	}
	void toString() {
		cout <<"Comentario: " << comentario << endl << "Calificacion: " << calificacion;
	}

};

