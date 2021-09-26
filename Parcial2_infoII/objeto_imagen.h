#ifndef OBJETO_IMAGEN_H
#define OBJETO_IMAGEN_H

#include <iostream>
#include <QImage>
#include <string>
#include <list>
using namespace std;

struct RGB ;

class objeto_imagen: public QImage
{
public:

    objeto_imagen();

    void obtener_informcion() ;

private:

   list < RGB > Lista_pixeles ;

   list < RGB >::iterator Iterador_LP ;

   RGB *colores ;

};


struct RGB{

    unsigned int Red ;

    unsigned int Green ;

    unsigned int Blue ;

};

#endif // OBJETO_IMAGEN_H
