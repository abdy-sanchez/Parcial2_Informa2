#include "objeto_imagen.h"



int main()
{

    objeto_imagen imagen ;

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

       imagen.obtener_informcion() ;

       int n = imagen.comparacion_pixeles( 16, 16 ) ;

       switch( n ){

           case 0 :{

            cout << endl << " Sub Muestreo" << endl << endl ;

            imagen.Sub_Muestreo();

            imagen.Escribir_RGB() ;

           }break;

           case 1:{

           cout << endl << " Sobre Muestreo" << endl << endl ;

            //imagen.Sobre_Muestreo() ;

           }break;

           case 2 :{
           cout << " Iguales" << endl ;
           }break;

       }


    }else{

      cout << " [Ocurrio un ERROR]" << endl ;

    }

    cout << endl ;   

    return 0;
}
