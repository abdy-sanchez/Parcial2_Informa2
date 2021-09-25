#include <iostream>
#include <QImage>
#include <string>
using namespace std;

int main()
{

    QImage imagen ;

    string base_direccion, nombre_imagen ;

    bool flag ;

    base_direccion = "../Parcial2_infoII/Imagenes/" ;       //Definimos la ruta de donde se extraerá la imagen

    cout << " Ingrese el nombre de su Imagen con su formato correspondiente." << endl << endl ;

    cout << " Nombre: " ;

    cin >> nombre_imagen ;

    cout << endl ;

    base_direccion.append( nombre_imagen ) ;    //Añadimos el nombre de la imagen a la ruta

    flag = imagen.load( base_direccion.c_str() ) ;      //Cargamos la imagen deseada

    if( flag ){

       cout << " [Imagen Correctamente Cargada]" << endl ;

    }else{

      cout << " [Ocurrio un ERROR]" << endl ;

    }

    cout << endl ;
    return 0;
}
