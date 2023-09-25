#include <iostream>
#include "date.h"
#include "product.h"
#include "list.h"

using std::string, std::istringstream, std::cout, std::endl, std::cin;

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
	  products.~cArray();
	  return 0;
	default:
	  cout << "the option is incorrect, please try again";
	}
    }
  products.~cArray();
}
