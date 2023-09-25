#include <iostream>
#include <sstream>

using std::string, std::istringstream, std::cout, std::endl, std::cin;

typedef struct sDate
{
  int day;
  int month;
  int year;
} date;

date parseString (const string &str)
{
  date input;
  istringstream value (str);
  char delemeter = '/';
  value >> input.day >> delemeter >> input.month >> delemeter >> input.year;
  return input;
}

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

int main (void)
{
  cArray products(5);

  // adding new product
  products.addNewProduct("beer","alivaria",3.99,"13/09/2024",50);

  // adding another one
  products.addNewProduct("vegetable","mother nature",2.99,"31/09/2023",10);

  // adding another one
  products.addNewProduct("beer","lidskaye",2.99,"30/08/2023",15);
  
  // adding another one
  products.addNewProduct("cake","Brest city",20.99,"23/09/2023",2);

  // adding another one
  products.addNewProduct("fruit","mother nature",5.99,"10/10/2023",62);

  products.showAll();
  
  int choice;
  cout << "Please choose the option:" << endl;
  cout << "1) list items with matching name" << endl;
  cout << "2) list items with matching name and price cheaper than specified" << endl;
  cout << "3) list items with expiration date greater than specified" << endl;
  cout << "4) exit" << endl;
  
  while (true)
    {
      cout << "Your choice: ";
      cin >> choice;

      switch (choice)
	{
	case 1:
	  products.getProductsWithName();
	  break;
	case 2:
	  products.getProductsWithNameAndPrice();
	  break;
	case 3:

	  break;
	case 4:
	  return 0;
	default:
	  cout << "the option is incorrect, please try again";
	}
    }
}
