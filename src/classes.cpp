/*
 * ClassExample.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: bg0ttdv
 */

#include <iostream>
#include "classes.h"
#include <math.h>

using namespace ExamplesNamespace;


Sort * ExamplesNamespace::GetSortingContext(uint32_t t)
{
    Sort * result = nullptr;

    switch(t)
    {
        case Sort_SSort:
            result = new SSort;
            break;

        case Sort_BSort:
            result = new BSort;
            break;
    }

    return result;
}



void BSort::ASort()
{
	for (int i = 0; i < this->m_u32Size - 1; i++)
	{
	    for (int j = 0; j < this->m_u32Size - i - 1; j++)
	    {
	        if (this->m_pElements[j].Compare(&this->m_pElements[j+1]) > 0)
	        {
	        	this->m_pElements[j].swap(&this->m_pElements[j+1]);
	        }
	    }
	}
}

void BSort::DSort()
{
	for (int i = 0; i < this->m_u32Size - 1; i++)
	{
	    for (int j = 0; j < this->m_u32Size - i - 1; j++)
	    {
	        if (this->m_pElements[j].Compare(&this->m_pElements[j+1]) > 0)
	        {
	        	this->m_pElements[j].swap(&this->m_pElements[j+1]);
	        }
	    }
	}
}

void SSort::ASort()
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < this->m_u32Size - 1; i++)
	{
	    // Find the minimum element in unsorted array
	    min_idx = i;
	    for (j = i + 1; j < this->m_u32Size; j++) {
	     	if (this->m_pElements[j].Compare(&this->m_pElements[min_idx]) > 0) {
	       		min_idx = j;
	       	}
	    }
	    // Swap the found minimum element with the first element
	    this->m_pElements[min_idx].swap(&this->m_pElements[i]);
	}
}

void SSort::DSort()
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < this->m_u32Size - 1; i++)
	{
	    // Find the minimum element in unsorted array
	    min_idx = i;
	    for (j = i + 1; j < this->m_u32Size; j++) {
	     	if (this->m_pElements[j].Compare(&this->m_pElements[min_idx]) < 0) {
	       		min_idx = j;
	       	}
	    }
	    // Swap the found minimum element with the first element
	    this->m_pElements[min_idx].swap(&this->m_pElements[i]);
	}
}

void IntElement::swap(Element *other)
{
	int temp = this->m_digit;
	this->m_digit = ((IntElement*)other)->m_digit;
	((IntElement*)other)->m_digit = temp;
}

int IntElement::Compare(Element *other)
{
	if(m_digit > ((IntElement*)other)->m_digit)
    {
		return 1;
    }
    else if(m_digit < ((IntElement*)other)->m_digit)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void StringElement::swap(Element *other)
{
	std::string temp = this->m_text;
	this->m_text = ((StringElement*)other)->m_text;
	((StringElement*)other)->m_text = temp;
}

int StringElement::Compare(Element *other)
{
	if(this->m_text > ((StringElement*)other)->m_text)
	    {
			return 1;
	    }
	    else if(this->m_text < ((StringElement*)other)->m_text)
	    {
	        return -1;
	    }
	    else
	    {
	        return 0;
	    }
}
