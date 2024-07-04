#include "RootFinder.hh"
#include <iostream>
#include <cmath>

double func(double x){ 
return sin(x)-(0.5*x); //Function 
}

int main(){

RootFinder finder(func);

double min=1;
double max=3;
double precision=0.0001;

double out=finder.GetRoot1(min,max,precision); //Testing first method
int count=finder.GetCounter();
std::cout<<out<<"  Number of iterations: "<<count<<std::endl;

out=finder.GetRoot2(min,max,precision); //Testing second method
count=finder.GetCounter();
std::cout<<out<<"  Number of iterations: "<<count<<std::endl;

out=finder.GetRoot3(min,max,precision); //Testing third method
count=finder.GetCounter();
std::cout<<out<<"  Number of iterations: "<<count<<std::endl;

out=finder.GetRoot(min,max,precision); //Testing best solution
count=finder.GetCounter();
std::cout<<out<<"  Number of iterations: "<<count<<std::endl;
return 0;

}
