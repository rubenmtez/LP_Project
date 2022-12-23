#pragma once
#include "Bicicleta.h"
#include "BicicletaMTB.h"
#include "BicicletaCarretera.h"
#include <fstream>

/**
* Conjunto de metodos necesarios para testear el correcto funcionamiento del sistema.
* 
**/

Talla randomTalla();
Quadre randomQuadre();
Roda randomRoda();
Fre randomFre();
bool randomBool();
Categoria randomCategoria();
Modalitat randomModalitat();
ModalitatC randomModalitatC();

bool compare_txt(ifstream& input1, ifstream& input2);
