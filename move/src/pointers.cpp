#include <iostream>

using std::cout;
using std::cin;
using std::endl;


namespace pointing{
class pointer{
public:
    int x;
    int c;
    int s;

    void pointers_(){
      x = 2;
      int* c = &x;
      *c = 99;
      cout << "The pointer is:" << c <<endl;
    }

};
};

int main(int argc,char** argv){
 pointing::pointer p;
 p.pointers_();
 return 0;
}
/*
int main (){
   int *numpPtr  = new int;

   std::cout << "*numptr" << *numpPtr << std::endl;

   std::cout << "numptr" << numpPtr << std::endl;

   std::cout << "&numptr" << &numpPtr << std::endl;

   //Value of 42
   *numpPtr = 42;

   std::cout << "*numptr Assigned to value of " << *numpPtr << std::endl;

   std::cout << "*numptr" << *numpPtr << std::endl;

   std::cout << "*numptr" << *numpPtr << std::endl;

   std::cout << "*numptr" << *numpPtr << std::endl;
}
*/
