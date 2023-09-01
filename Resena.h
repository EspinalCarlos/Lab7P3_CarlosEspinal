#pragma once
#include <iostream>
#include <string>
template <typename T>
class Resena{
	Producto producto;
	string comentario;
	int calificacion;
public:
	Resena<T>::Resena(Producto product, string comment, int calif) {
		producto = product;
		comentario = comment;
		calificacion = calif;
	}
	Resena<T>::getProducto() {
		return producto;
	}

};

