#include "Data.h"
#include <iostream>
using namespace std;


bool Data::dataValida() const
{
	bool correcte = false;
	if (m_any > 0)
		if ((m_mes > 0) && (m_mes <= N_MESOS))
		{
			int diesMes = nDiesMes[m_mes - 1];
			if (m_mes == 2)
			{
				bool esTraspas = (m_any % 4) == 0 && ((m_any % 100) != 0 || (m_any % 400) == 0);
				if (esTraspas)
					diesMes++;
			}
			if ((m_dia > 0) && (m_dia <= diesMes))
				correcte = true;
		}

	return correcte;
}

bool Data::operator!=(const Data& data) const
{
	return ((m_dia != data.m_dia) || (m_mes != data.m_mes) || (m_any != data.m_any));
	
}



Data Data::operator+(int nDies) const
{
	Data dataNova(*this);
	while (nDies > 0)
	{
		int diaAux = dataNova.m_dia + nDies;
		if (diaAux > nDiesMes[dataNova.m_mes - 1])
		{
			nDies -= (nDiesMes[dataNova.m_mes - 1] - dataNova.m_dia + 1);
			dataNova.m_dia = 1;
			dataNova.m_mes++;
			if (dataNova.m_mes > N_MESOS)
			{
				dataNova.m_any++;
				dataNova.m_mes = 1;
			}
		}
		else
		{
			dataNova.m_dia = diaAux;
			nDies = 0;
		}
	}
	return dataNova;
}

Data Data::operator-(int nDies) const
{
	Data dataNova(*this);
	while (nDies > 0)
	{
		int diaAux = dataNova.m_dia - nDies;
		if (diaAux <= 0)
		{
			nDies = -1 * diaAux;
			int mesAux = dataNova.m_mes - 1;
			if (mesAux == 0)
			{
				dataNova.m_any--;
				dataNova.m_mes = 12;
			}
			else
			{
				dataNova.m_mes = mesAux;
			}
			dataNova.m_dia = nDiesMes[dataNova.m_mes - 1];

		}
		else
		{
			nDies = 0;
			dataNova.m_dia = diaAux;
		}

	}
	return dataNova;
}


bool Data::operator==(const Data& data) const
{
	return ((m_dia == data.m_dia) && (m_mes == data.m_mes) && (m_any == data.m_any));
}

bool Data::operator<(const Data& data) const
{
	return ((m_any < data.m_any) || ((m_any == data.m_any) && (m_mes < data.m_mes)) ||
		((m_any == data.m_any) && (m_mes == data.m_mes) && (m_dia < data.m_dia)));
}

bool Data::operator<=(const Data& data) const
{
	return ((m_any < data.m_any) || ((m_any == data.m_any) && (m_mes < data.m_mes)) ||
		((m_any == data.m_any) && (m_mes == data.m_mes) && (m_dia <= data.m_dia)));
}

Data& Data::operator=(const Data& data)
{
	m_dia = data.m_dia;
	m_mes = data.m_mes;
	m_any = data.m_any;
	return *this;
}
