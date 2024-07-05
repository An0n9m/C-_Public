#include "Histo.hh"
#include "Graph.hh"
#include "Drawable.hh"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
Histo::Histo(const char* name,double tmpn, double tmpmin, double tmpmax) : Drawable(name){ //Constructor and inheritance
n=tmpn;
min=tmpmin;
max=tmpmax;
fName=name;
option=" -b";
interval=(max-min)/n;
for(double i=min;i<=max;i+=interval){
fData.push_back(Point {i,0,0});
}
}
void Histo::Fill(double x){ //Y Coordinate filling function
if(x>=min&&x<=max){
int i=(x-min)/interval;
fData[i].Y+=1;
}
else if(x<min)fNunderflow++;
else fNoverflow++;
}
void Histo::Clear(){ //Clearing graph
fNunderflow=0,fNoverflow=0;
for(int i=min;i<=max;i++){
fData[i].Y=0;
}
}
double Histo::Integral(){ //Sums up point, finds integral
double integral=0;
for(int i=min;i<=max;i++){
integral+=fData[i].Y;
}
return integral;
}
double Histo::GetMean(){ //Finds mean value
double mean=0;
for(int i=min;i<=max;i++){
mean+=(fData[i].X*fData[i].Y)/Integral();
}
return mean;
}
double Histo::GetRMS(){ //Finds RMS
double x=0,n;
for(int i=min;i<=max;i++){
x+=((fData[i].X*fData[i].X)*fData[i].Y)/Integral();
}
n=sqrt(x-(GetMean()*GetMean()));

return n;
}
void Histo::Draw(bool is_err){
Drawable::Draw(is_err);
}
