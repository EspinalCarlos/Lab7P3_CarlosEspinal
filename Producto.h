#pragma once
#include <iostream>
#include<string>
template <typename T>
class Producto{
protected:
	int id;
	float precio;
	int stock;

public:
	Producto(int ident, float price, int st) {
		id = ident;
		precio = price;
		stock = st;
	}
	int getPrecio() {
		return precio;
	}
	void setStock(int cant) {
		stock = cant;
	}
	~Producto(){}
	

};

