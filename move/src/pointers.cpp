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
      for (int i = 0;i<sizeof(c);i++){
         cout << "The pointer is:" << c <<endl;
      }
        //cout << "The pointer is:" << c << endl;
    }

};
};

int main(int argc,char** argv){
 pointing::pointer p;
 p.pointers_();
 return 0;
}
