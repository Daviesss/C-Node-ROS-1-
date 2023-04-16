#include <iostream>

int main (){
   int *numpPtr  = new int;

   std::cout << "*numptr" << *numpPtr << std::endl;

   std::cout << "numptr" << numpPtr << std::endl;

   std::cout << "&numptr" << &numpPtr << std::endl;

   //Value of 42
   *numpPtr = 42;
    
   std::cout << "*numptr Assigned to value of: " << *numpPtr << std::endl;

   std::cout << "*numptr" << *numpPtr << std::endl;

   std::cout << "*numptr" << *numpPtr << std::endl;

   std::cout << "*numptr" << *numpPtr << std::endl;
}   