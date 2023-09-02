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
template<typename T>
T recorrerlista(vector<T> pelis, int aidee) {
    T movie = nullptr;
    for (T peli : pelis) {
        if (peli->getID() == aidee) {
            movie = peli; 
        }
    }
    
    return movie;
}
template<typename T>
void imprimirresenas2(vector<Resena<T>*> rl) {
    for (Resena<T>* reseL : rl) {
        cout << " - " << (reseL->getProducto())->getID() << " - "; 
    }
}
template<typename T>
void buscar(vector<Resena<T>*> vr,int idquebusca) {
    for (Resena<T>* r : vr) {
        if ((r->getProducto())->getID() == idquebusca) {
            cout << "\n---------\n" << "Calificacion: " << r->getCalificacion() << endl << "Comentario: " << r->getComentario() << "\n---------\n";
        }
    }
}
template<typename T>
void freeMemory(vector<T> vec) {
    for (T t : vec) {
        delete t;
    }
}

int main(){
    int opcion;
    vector<Pelicula*> peliculas;
    vector<Libro*> libros;
    vector<Disco*> discos;
    vector<Resena<Libro*>*> resenalibros; 
    vector<Resena<Pelicula*>*> resenapeliculas;
    vector<Resena<Disco*>*> resenadiscos;
    
    do {
        mainmenu();
        cin >> opcion;
        cout << endl << endl;
        int opcionadd, idP,stockP,intP,idbuscar,calific,newstock;
        float precioP;
        string tituloP,artautdirec,coment;
        Pelicula* mov = nullptr;
        Libro* bok = nullptr;
        Disco* dic = nullptr;


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
                cout << "\n---- Productos Disponibles ----\n";
                imprimirid2(peliculas, libros, discos);
                cout << endl;
                cout << "Ingrese la id del producto a cambiar: ";
                cin >> idbuscar;
                bok = recorrerlista<Libro*>(libros, idbuscar);
                mov = recorrerlista<Pelicula*>(peliculas, idbuscar);
                dic = recorrerlista<Disco*>(discos, idbuscar);

                if (bok != nullptr) {
                    cout << "Ingrese el nuevo stock: ";
                    cin >> newstock;
                    bok->setStock(newstock);

                }
                else if (mov != nullptr) {
                    cout << "Ingrese el nuevo stock: ";
                    cin >> newstock;
                    mov->setStock(newstock);
                }
                else if (dic != nullptr) {
                    cout << "Ingrese el nuevo stock: ";
                    cin >> newstock;
                    dic->setStock(newstock);
                }


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
                bok = recorrerlista<Libro*>(libros, idbuscar);
                mov = recorrerlista<Pelicula*>(peliculas, idbuscar);
                dic = recorrerlista<Disco*>(discos, idbuscar);
                

                if (bok != nullptr) {
                    cout << "Ingrese la calificacion: ";
                    cin >> calific;
                    cout << "Ingrese un comentario: ";
                    cin.ignore();
                    getline(cin, coment);
                    Resena<Libro*>* resL = new Resena<Libro*>(coment, calific);
                    resL->setProducto(bok);
                    resenalibros.push_back(resL);

                    
                }
                else if (mov != nullptr) {
                    cout << "Ingrese la calificacion: ";
                    cin >> calific;
                    cout << "Ingrese un comentario: ";
                    cin.ignore();
                    getline(cin, coment);
                    Resena<Pelicula*>* resL = new Resena<Pelicula*>(coment, calific);
                    resL->setProducto(mov);
                    resenapeliculas.push_back(resL);
                }
                else if (dic != nullptr) {
                    cout << "Ingrese la calificacion: ";
                    cin >> calific;
                    cout << "Ingrese un comentario: ";
                    cin.ignore();
                    getline(cin, coment);
                    Resena<Disco*>* resL = new Resena<Disco*>(coment, calific);
                    resL->setProducto(dic);
                    resenadiscos.push_back(resL);
                }


                break;
            case 5:
                cout << "\n---- Productos ----\n";
                imprimirresenas2<Libro*>(resenalibros);
                imprimirresenas2<Pelicula*>(resenapeliculas);
                imprimirresenas2<Disco*>(resenadiscos);
                cout << endl;
                cout << "Ingrese la id del producto que desea analizar: ";
                cin >> idbuscar;
                buscar<Libro*>(resenalibros, idbuscar);
                buscar<Pelicula*>(resenapeliculas, idbuscar);
                buscar<Disco*>(resenadiscos, idbuscar);

                break;
            
        }

    } while (opcion != 0);
    //liberacion de memoria
    freeMemory<Pelicula*>(peliculas);
    freeMemory<Libro*>(libros);
    freeMemory<Disco*>(discos);
    freeMemory<Resena<Libro*>*>(resenalibros);
    freeMemory<Resena<Pelicula*>*>(resenapeliculas);
    freeMemory<Resena<Disco*>*>(resenadiscos);



}
