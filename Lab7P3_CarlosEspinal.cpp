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

void imprimirids(vector<Pelicula*> pelis, vector<Libro*> libs, vector<Disco*> dics) {
    for (Pelicula* peli : pelis) {
        cout << " - " << peli->getID() << " - " << peli->getTitulo() << " - " << peli->getDirector() << " - " << "stock: " << peli->getStock();
        cout << endl;
    }
    for (Libro* lib : libs) {
        cout << " - " << lib->getID() << " - " << lib->getTitulo() << " - " << lib->getAutor() << " - " << "stock: " << lib->getStock();
        cout << endl;
    }
    for (Disco* dis : dics) {
        cout << " - " << dis->getID() << " - " << dis->getTitulo() << " - " << dis->getArtista() << " - " << "stock: " << dis->getStock();
        cout << endl;
    }
}
void imprimirid2(vector<Pelicula*> pelis, vector<Libro*> libs, vector<Disco*> dics) {
    for (Pelicula* peli : pelis) {
        cout << " - " << peli->getID() << " - " << peli->getTitulo();
        cout << endl;
    }
    for (Libro* lib : libs) {
        cout << " - " << lib->getID() << " - " << lib->getTitulo();
        cout << endl;
    }
    for (Disco* dis : dics) {
        cout << " - " << dis->getID() << " - " << dis->getTitulo();
        cout << endl;
    }
}

Pelicula* recorrerlistas(vector<Pelicula*> pelis, vector<Libro*> libs, vector<Disco*> dics,int aidee) {
    Pelicula* movie = nullptr;
    for (Pelicula* peli : pelis) {
        if (peli->getID() == aidee) {
            movie = peli;
        }
    }
    

}

int main(){
    int opcion;
    vector<Pelicula*> peliculas;
    vector<Libro*> libros;
    vector<Disco*> discos;
    
    do {
        mainmenu();
        cin >> opcion;
        cout << endl << endl;
        int opcionadd, idP,stockP,intP,idbuscar;
        float precioP;
        string tituloP,artautdirec;

        switch (opcion) {
            case 1: // agregar producto
                menu2();
                cin >> opcionadd;
                switch (opcionadd) {
                    case 1://agregar libro 
                        cout << endl << endl;
                        cout << endl << "Ingrese el ID del producto: ";
                        cin >> idP;
                        cout << endl << "Ingrese el stock inicial del producto: ";
                        cin >> stockP;
                        cout << endl << "Ingrese el precio del producto: ";
                        cin >> precioP;
                        cout << endl <<"Ingrese el titulo: ";
                        cin.ignore();
                        getline(cin, tituloP);
                        cout << endl << "Ingrese el nombre del autor: ";
                        cin.ignore();
                        getline(cin, artautdirec);
                        cout << endl << "Ingrese el numero de paginas: ";
                        cin >> intP;

                        libros.push_back(new Libro(idP, precioP, stockP, tituloP, artautdirec, intP));

                        break;
                    case 2:// agregar pelicula
                        cout << endl << endl;
                        cout << endl << "Ingrese el ID del producto: ";
                        cin >> idP;
                        cout << endl << "Ingrese el stock inicial del producto: ";
                        cin >> stockP;
                        cout << endl << "Ingrese el precio del producto: ";
                        cin >> precioP;
                        cout << endl << "Ingrese el titulo: ";
                        cin.ignore();
                        getline(cin, tituloP);
                        cout << endl << "Ingrese el nombre del director: ";
                        cin.ignore();
                        getline(cin, artautdirec);
                        cout << endl << "Ingrese la duracion: ";
                        cin >> intP;

                        peliculas.push_back(new Pelicula(idP, precioP, stockP, tituloP, artautdirec, intP));

                        break;
                    case 3://agregar disco
                        cout << endl << endl;
                        cout << endl << "Ingrese el ID del producto: ";
                        cin >> idP;
                        cout << endl << "Ingrese el stock inicial del producto: ";
                        cin >> stockP;
                        cout << endl << "Ingrese el precio del producto: ";
                        cin >> precioP;
                        cout << endl << "Ingrese el titulo: ";
                        cin.ignore();
                        getline(cin, tituloP);
                        cout << endl << "Ingrese el nombre del artista: ";
                        cin.ignore();
                        getline(cin, artautdirec);
                        cout << endl << "Ingrese el numero de canciones: ";
                        cin >> intP;

                        discos.push_back(new Disco(idP, precioP, stockP, tituloP, artautdirec, intP));

                        break;
                }
                break;
            case 2://modificar stock por id

                break;
            case 3://Listar productos disponibles
                if (peliculas.size() == 0 && libros.size() == 0 && discos.size() == 0) {
                    cout << "\nNo hay ningun producto registrado, agregue un producto y vuelva a intentar\n";
                }
                else {
                    cout << "\n---- Productos Disponibles ----\n";
                    imprimirids(peliculas, libros, discos);
                }

                break;
            case 4://Agregar resena
                cout << "\n---- Productos ----\n";
                imprimirid2(peliculas, libros, discos);
                cout << "Ingrese la id del producto que desea agregar una resena: ";
                cin >> idbuscar;


                break;
            
        }

    } while (opcion != 0);
}
