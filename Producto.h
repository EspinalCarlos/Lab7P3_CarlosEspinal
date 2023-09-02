#pragma once
#include <iostream>
#include <vector>
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
	int getID() {
		return id;
	}
	int getStock() {
		return stock;
	}
	void setStock(int cant) {
		stock = cant;
	}
	~Producto(){}
	

};

