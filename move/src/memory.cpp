#include "memory.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct memoryy{
  public:
    void memory(){
        int x = 23;
        int* c = &x;
        cout << "The memeory is: " << c << endl;
      }
    void memory2(){
        int* a;
        int size = 3;
        a = new int[size];
        for (int i =0; i< sizeof(a);i++){
           cout<< a << endl;
        }
    } 
};

int main(int argc,char**argv){
    memoryy p;
    p.memory();
    p.memory2();
    return 0;
}