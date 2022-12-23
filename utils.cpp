#include "utils.h"
using namespace std;

Talla randomTalla()
{
	static Talla map[] =
	{
		Talla::XS,
		Talla::S,
		Talla::M,
		Talla::L,
		Talla::XL
	};
	return map[rand() % (sizeof(map) / sizeof(map[0]))];
};

Quadre randomQuadre()
{
	static Quadre map[] =
	{
		Quadre::ALUMINI,
		Quadre::CARBONO,

	};
	return map[rand() % (sizeof(map) / sizeof(map[0]))];
};

Roda randomRoda()
{
	static Roda map[] =
	{
		Roda::RODA_14,
		Roda::RODA_20,
		Roda::RODA_26,
		Roda::RODA_27,
		Roda::RODA_29,
		Roda::RODA_700,

	};
	return map[rand() % (sizeof(map) / sizeof(map[0]))];
};

Fre randomFre()
{
	static Fre map[] =
	{
		Fre::DISC,
		Fre::RIM

	};
	return map[rand() % (sizeof(map) / sizeof(map[0]))];
};

bool randomBool()
{
	return bool(rand() % 2);
}

Categoria randomCategoria()
{
	static Categoria map[] =
	{
		Categoria::RIGIDA,
		Categoria::DOBLE,

	};
	return map[rand() % (sizeof(map) / sizeof(map[0]))];
}

Modalitat randomModalitat()
{
	static Modalitat map[] =
	{
		Modalitat::DESCENS,
		Modalitat::ENDURO,
		Modalitat::RALLY,
		Modalitat::TRAIL,


	};
	return map[rand() % (sizeof(map) / sizeof(map[0]))];
}

ModalitatC randomModalitatC()
{
	static ModalitatC map[] =
	{
		ModalitatC::AERO,
		ModalitatC::GRANFONDO,
		ModalitatC::GRAVEL,
		ModalitatC::RENDIMIENTO,


	};
	return map[rand() % (sizeof(map) / sizeof(map[0]))];
}


bool compare_txt(ifstream& input1, ifstream& input2)
{
	const string file_contents1{istreambuf_iterator<char>(input1), istreambuf_iterator<char>()};
	const string file_contents2{istreambuf_iterator<char>(input2), istreambuf_iterator<char>()};
	return file_contents1 == file_contents2;
}
