#include "student.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


namespace uiuc {
class student{
    public:
       double phone_number = 100.0 ;
       void age(){
        cout << phone_number << endl;
    }
};

};

int main(int argc,char**argv){
  uiuc::student p;
  p.age();
  return 0;
}