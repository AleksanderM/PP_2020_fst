/*
 * ClassExample.h
 *
 *  Created on: Oct 6, 2020
 *      Author: bg0ttdv
 */

#ifndef CLASSEXAMPLE_H_
#define CLASSEXAMPLE_H_

#include <string>

namespace ExamplesNamespace
{

#define Sort_SSort 0
#define Sort_BSort 1

class Element
{
public:
    virtual ~Element() {}
    virtual int Compare(Element *other) = 0;
    virtual void swap(Element *other) = 0;
    virtual void printValue() = 0;
};

class Sort
{
protected:
    Element* m_pElements;
    uint32_t m_u32Size;

public:
        Sort() {}
        virtual ~Sort() { delete m_pElements;}

        virtual void ASort() = 0;
        virtual void DSort() = 0;

        void SetElementsArray(Element *pElementsP, uint32_t u32SizeP) {m_pElements = pElementsP; m_u32Size = u32SizeP;}
};

class BSort : public Sort
{
public:
    void ASort();
    void DSort();
};

class SSort : public Sort
{
public:
    void ASort();
    void DSort();

};

class IntElement : public Element
{
    int m_digit;

public:
    void setValue(int digit) {m_digit = digit;}
    IntElement():m_digit(0) {}
    IntElement(int digit):m_digit(digit) {}
    ~IntElement(){}
    void swap(Element *other);
    int Compare(Element *other);
    void printValue();
};

class StringElement : public Element
{
	std::string m_text;
public:
	void setValue(std::string text) {this->m_text = text;}
	StringElement():m_text("") {}
	StringElement(std::string text):m_text(text) {}
	~StringElement() {}
	void swap(Element *other);
	int Compare(Element *other);
	void printValue();
};

Sort * GetSortingContext(uint32_t t);

}
#endif /* CLASSEXAMPLE_H_ */
