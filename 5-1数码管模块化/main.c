#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

void main()
{
	while(1)
	{
	Nixie(1,3);
	Nixie(1,'.');
	Nixie(2,0);
	Nixie(3,2);
	Nixie(4,3);
	Nixie(5,2);
	}
}