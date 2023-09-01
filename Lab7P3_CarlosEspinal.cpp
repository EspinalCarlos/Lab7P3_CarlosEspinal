#include <iostream>
#include <string>
#include <vector>
#include "Producto.h"
#include "Libro.h"
#include "Resena.h"
#include "Pelicula.h"
#include "Disco.h"

using namespace std;

void mainmenu() {
    cout << "---- Menu Principal ----\n\n" << "1. Agregar nuevo producto \n" << "2. Modificar Stock \n" << "3. Listar productos disponibles \n" << "4. Agregar resena \n" << "5. Ver resenas de producto \n" << "0. Salida \n\n" << "Ingrese la opcion que desea acceder: ";
}
void menu2() {
    cout << "---- Tipos de Producto ---- \n" << "1. Libro\n" <<"2. Pelicula\n"<<"3. Disco\n\n"<< "Ingrese el tipo que quiere agregar: ";
}


int main(){
    int opcion;
    do {
        mainmenu();
        cin >> opcion;
        cout << endl << endl;

        switch (opcion) {
            case 1:
                
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            
        }

    } while (opcion != 0);
}
