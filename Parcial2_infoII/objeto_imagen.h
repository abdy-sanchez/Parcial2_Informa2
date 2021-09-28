#ifndef OBJETO_IMAGEN_H
#define OBJETO_IMAGEN_H

#include <iostream>
#include <QImage>
#include <string>
#include <vector>

using namespace std;

struct RGB ;

class objeto_imagen: public QImage
{
public:

    objeto_imagen();

    void obtener_informcion() ;

    int comparacion_pixeles( int px, int py );

    void Sub_Muestreo() ;

    void Sobre_Muestreo() ;

    void Escribir_RGB();

private:

   vector < vector < RGB > > Lista_pixeles ;

   vector < vector < RGB > > Redimension ;

   vector < RGB > pixel ;

   RGB *colores ;

   int tam_repre_px, RPX, RPY ;



};


struct RGB{

    unsigned int Red ;

    unsigned int Green ;

    unsigned int Blue ;

};

#endif // OBJETO_IMAGEN_H
