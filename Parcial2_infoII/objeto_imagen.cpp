#include "objeto_imagen.h"

objeto_imagen::objeto_imagen(){


}

void objeto_imagen::obtener_informcion(){

   for( int ancho = 0 ; ancho < width() ; ancho++ ){

       for( int alto = 0 ; alto < height() ; alto++ ){

           colores = new RGB ;

           colores->Red = pixelColor( ancho , alto ).red() ;

           colores->Green = pixelColor( ancho , alto ).green() ;

           colores->Blue = pixelColor( ancho , alto ).blue() ;


           Lista_pixeles.push_back( *colores ) ;

           delete colores ;

       }


   }



}
