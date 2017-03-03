/*implemention of polynomial by Array*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial Poly;
struct Polynomial
{
	int arrayOfCoefficient[maxPower+1];
	int maxPower;
}

void addTwoPolymial(Poly* firstPoly, Poly* secondPoly, Poly* resultPoly)
{
	int index = 0;
	int innerMaxPower = max(firstPoly->maxPower, secondPoly->maxPower);
	resultPoly->maxPower = innerMaxPower;

	//lack of exception judge
	for (index = innerMaxPower; index >= 0; index--)
	{
		resultPoly->arrayOfCoefficient[index] = firstPoly->arrayOfCoefficient[index]
			+ secondPoly->arrayOfCoefficient[index];
	}
	return;
}

void mutilTwoPolymial(Poly* firstPoly, Poly* secondPoly, Poly* resultPoly)
{
	int i = 0, j = 0;

	Poly* tmpPoly = (Poly*)malloc(sizeof(Poly));
	memset(tmpPoly, 0 ,sizeof(Poly));
	resultPoly->maxPower = firstPoly->maxPower + secondPoly->maxPower;
	tmpPoly->maxPower = resultPoly->maxPower;

	//time waste too much in zero item
	for(i = firstPoly->maxPower; i >= 0; i--)
	{
		for(j = firstPoly->maxPower; j >= 0; j--)
		{
			tmpPoly->arrayOfCoefficient[i+j] = firstPoly->arrayOfCoefficient[i]
				* secondPoly->arrayOfCoefficient[j];
		}
		addTwoPolymial(tmpPoly, resultPoly);
	}
}
