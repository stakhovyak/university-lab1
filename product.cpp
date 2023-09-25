#include <iostream>
#include "product.h"

cProduct::cProduct(string n, string c, double p, date e, unsigned int q)
{
  this->name = n;
  this->creator = c;
  this->price = p;
  this->expirationDate = e;
  this->quantity = q;
}

// setter methods
void cProduct::setName(string n) { this->name = n; }
void cProduct::setCreator(string c) { this->creator = c; }
void cProduct::setPrice(double p) { this->price = p; }
void cProduct::setExpirationDate(date e) { this->expirationDate = e; }
void cProduct::setQuantity(unsigned int q) { this->quantity = q; }

// getter methods
string cProduct::getName() { return name; }
string cProduct::getCreator() { return creator; }
double cProduct::getPrice() { return price; }
date cProduct::getExpirationDate() { return expirationDate; }
unsigned int cProduct::getQuantity() { return quantity; }
