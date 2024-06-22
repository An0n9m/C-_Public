#include <exception>
#include <iostream>
using namespace std;

int main()
{
  char* array = 0;
  unsigned long NMbytes = 10000;
  unsigned long delta = NMbytes;
  
  while (true) {
    try {
      if (delta < 10) break;
      cout << "Try " << NMbytes << " MB ...... ";
      array = new char [NMbytes*1024*1024];
    }
    catch (bad_alloc& e) {
      cout << "Fail :(" << endl;
      delta /= 2;
      NMbytes -= delta;
      
      continue;
    }
    
    cout << "Success :)" << endl;
    delete [] array;
    NMbytes += delta;

  }
  
  cout << "Maximum available memory: " << NMbytes << " MB" << endl;

  return 0; //Written By An0n9m
}
