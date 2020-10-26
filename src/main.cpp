//============================================================================
// Name        : Example_1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "classes.h"

using namespace ExamplesNamespace;
using namespace std;

#define NUMBEROFSORTELEMENTS 10

//TODO overloaded operator printing
//void printArr(Element *arr);

int main()
{
	IntElement *sortelement1 = new IntElement[NUMBEROFSORTELEMENTS];
	sortelement1[0].setValue(1);
	sortelement1[1].setValue(10);
	sortelement1[2].setValue(12);
	sortelement1[3].setValue(15);
	sortelement1[4].setValue(17);
	sortelement1[5].setValue(19);
	sortelement1[6].setValue(21);
	sortelement1[7].setValue(41);
	sortelement1[8].setValue(51);
	sortelement1[9].setValue(71);

	Sort *sortctx1 = GetSortingContext(Sort_SSort);

	sortctx1->SetElementsArray(sortelement1, NUMBEROFSORTELEMENTS);
	sortctx1->DSort();

//	printArr(sortelement1);

	StringElement *sortelement = new StringElement[NUMBEROFSORTELEMENTS];
	sortelement[0].setValue("lion");
	sortelement[1].setValue("elephant");
	sortelement[2].setValue("sheep");
	sortelement[3].setValue("ram");
	sortelement[4].setValue("giraffe");
	sortelement[5].setValue("fish");
	sortelement[6].setValue("dog");
	sortelement[7].setValue("cat");
	sortelement[8].setValue("bird");
	sortelement[9].setValue("horse");

	Sort *sortctx2 = GetSortingContext(Sort_BSort);

	sortctx2->SetElementsArray(sortelement, NUMBEROFSORTELEMENTS);
	sortctx2->ASort();

//	printArr(sortelement);

	return 0;
}

