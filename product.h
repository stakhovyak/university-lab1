#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "date.h"

using namespace std;

class cProduct
{
private:
  string name;
  string creator;
  double price;
  date expirationDate;
  unsigned int quantity;

public:
  // constructor
  cProduct(string n, string c, double p, date e, unsigned int q);
  
  // setter methods
  void setName(string n);
  void setCreator(string c);
  void setPrice(double p);
  void setExpirationDate(date e);
  void setQuantity(unsigned int q);

  // getter methods
  string getName();
  string getCreator();
  double getPrice();
  date getExpirationDate();
  unsigned int getQuantity();
  void showProduct()
  {
    cout << name << endl;
    cout << creator << endl;
    cout << price << endl;
    cout << expirationDate.day << " " << expirationDate.month << " " << expirationDate.year << endl;
    cout << quantity << endl;
  }
};

#endif
