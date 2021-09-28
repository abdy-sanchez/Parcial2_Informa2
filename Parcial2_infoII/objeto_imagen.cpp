#include "objeto_imagen.h"

objeto_imagen::objeto_imagen(){


}

void objeto_imagen::obtener_informcion(){


   for( int alto = 0 ; alto < height() ; alto++ ){

       for( int ancho = 0 ; ancho < width() ; ancho++ ){

           colores = new RGB ;


           colores->Red = pixelColor( ancho , alto ).red() ;

           if( colores->Red == 255 ){

               colores->Red = 254 ;

           }else if( colores->Red == 0 ){

              colores->Red = 1 ;
           }

           colores->Green = pixelColor( ancho , alto ).green() ;

           if( colores->Green == 255 ){

               colores->Green = 254 ;

           }else if( colores->Green == 0 ){

                colores->Green = 1 ;
           }

           colores->Blue = pixelColor( ancho , alto ).blue() ;

           if( colores->Blue == 255 ){

               colores->Blue = 254 ;

           }else if( colores->Blue == 0 ){

                colores->Blue = 1 ;
           }


           pixel.push_back( *colores ) ;

           delete colores ;

       }

       Lista_pixeles.push_back( pixel ) ;

       pixel.clear() ;


   }



}

int objeto_imagen::comparacion_pixeles( int px, int py ){

    int densidad_pixeles = px*py ;

    int ancho_iamgen, alto_imagen, d2_p2 ;

    ancho_iamgen = width() ;

    alto_imagen = height() ;

    d2_p2 = ancho_iamgen * alto_imagen ;




    if( densidad_pixeles < d2_p2 ){ //Nuestra matriz es más pequeña [Sub Muestreo]

        RPX =  ( ancho_iamgen )/( px ) ;

        RPY = ( alto_imagen )/( py ) ;

        tam_repre_px = ( RPX )*( RPY ) ;

        return 0 ;

    }else if( densidad_pixeles > d2_p2 ){   //Nuestra matriz es más pequeña [Sobre Muestreo]

        RPX = ( px )/( ancho_iamgen ) ;

        RPY = ( py )/( alto_imagen ) ;

        tam_repre_px = ( RPX )*( RPY ) ;

        return  1 ;
    }
    else{           //Tamaños Iguales

        return 2 ;
    }


}

void objeto_imagen::Sub_Muestreo(){

    int cont = 0, pX = 0 , pY = 0, pixcont = 0, limX = 0 ;

    long long int prom_R = 0 , prom_G = 0, prom_B = 0 ;

    while( cont < (width() * height() ) ){

        for( int y = 0 ; y < RPY ; y++ ){


            for( int x = 0 ; x < RPX ; x++ ){


                prom_R = Lista_pixeles[pY+y][pX+x].Red + prom_R ;

                prom_G = Lista_pixeles[pY+y][pX+x].Green + prom_G ;

                prom_B = Lista_pixeles[pY+y][pX+x].Blue + prom_B ;

                cont++ ;


            }

           limX++ ;



        }//fin for fuera

        if( limX == RPX ){

            pX = pX + RPX ;

            limX = 0 ;

            if( pX == width() ){

                pY = pY + RPY ;

                pX = 0 ;
            }

        }


        colores = new RGB ;

        colores->Red = prom_R/tam_repre_px ;

        colores->Green = prom_G/tam_repre_px ;

        colores->Blue = prom_B/tam_repre_px ;

        pixel.push_back( *colores ) ;

        pixcont++ ;

        if( pixcont == 16 ){

            Redimension.push_back( pixel ) ;

            pixel.clear() ;

            pixcont = 0 ;
        }



        prom_R = 0 ;

        prom_G = 0 ;

        prom_B = 0 ;

    }//fin while

}



/*void objeto_imagen::Sobre_Muestreo(){

    for( Iterador_LP = Lista_pixeles.begin() ; Iterador_LP != Lista_pixeles.end() ; Iterador_LP++ ){

        colores = new RGB ;

        colores->Red = Iterador_LP->Red ;

        colores->Green = Iterador_LP->Green ;

        colores->Blue = Iterador_LP->Blue ;

        for( int cont = 1 ; cont <= tam_repre_px ; cont++ ){

            Redimension.push_back( *colores ) ;

        }

        delete colores ;

    }

}*/

void objeto_imagen::Escribir_RGB(){


    for( int y = 0 ; y < 16 ; y++ ){

        cout << "{" ;


        for( int x = 0 ; x < 16 ; x++ ){


            cout << "{" << Redimension[y][x].Red << "," << Redimension[y][x].Green << "," << Redimension[y][x].Blue << "}," ;


        }

        cout << "}," ;

        cout << endl ;

    }



}
