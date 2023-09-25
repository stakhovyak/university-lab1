#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "product.h"
#include "date.h"

using namespace std;

class cArray
{
  unsigned int arraySize;
  cProduct **prd;
  static unsigned int index;

public:
  // constructor
  cArray(unsigned int arraySize);
  
  // destructor
  ~cArray();

  // setter methods
  void setProduct(cProduct *p);

  // getter methods
  void showAll();
  void getProductsWithName ();
  void getProductsWithNameAndPrice ();

  // add new
  void addNewProduct(const string &name, const string &creator,
		     double price, const string &expirationDate, unsigned int quantity)
  {
    cProduct *newProduct = new cProduct(name, creator,
					price, parseString(expirationDate), quantity);
    setProduct(newProduct);
  }
};

#endif 
