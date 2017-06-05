#include "Canal.h"

Canal::Canal(){}

Canal::~Canal(){}

Canal::Canal(int c)
{
	set_numeroCanal(c);
}

void Canal::set_numeroCanal(int c)
{
	numeroCanal = c;
}

int Canal::get_numeroCanal()
{
	return numeroCanal;
}