#include <iostream>
#include "list.h"
#include "product.h"

// index counter
unsigned int cArray::index = 0;

// constructor
cArray::cArray(unsigned int arraySize)
{
  this->arraySize = arraySize;
  prd = new cProduct *[arraySize];
}

// destructor
cArray::~cArray()
{
  for (int i = 0; i < arraySize; i++)
    {
      delete prd[i];
    }
  
  delete[] prd;
}

// setter methods
void cArray::setProduct(cProduct *p)
{
  if (index >= 0 && index < arraySize)
    prd[index] = p;
  else
    cout << "Invalid index!";

  index++;
}

// getter methods
void cArray::showAll()
{
  for (int i = 0; i < arraySize; i++)
    if (prd[i] != nullptr)
      prd[i]->showProduct();
}

void cArray::getProductsWithName ()
{
  string name;
  cout << "\nenter the name: ";
  cin >> name;
  cout << endl;
  for (int i = 0; i < arraySize; i++)
    {
      if (prd[i] != nullptr && prd[i]->getName() == name)
	prd[i]->showProduct();
    }
}

void cArray::getProductsWithNameAndPrice ()
{
  string name;
  double price;
  
  cout << "\nenter the name: ";
  cin >> name;
  cout << endl;
  
  cout << "\nenter the price: ";
  cin >> price;
  cout << endl;
  
  for (int i = 0; i < arraySize; i++)
    {
      if (prd[i] != nullptr && prd[i]->getName() == name && prd[i]->getPrice() <= price)
	prd[i]->showProduct();
    }
}
