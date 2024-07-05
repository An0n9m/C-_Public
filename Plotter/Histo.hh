#ifndef _HISTO_HH_ 
#define _HISTO_HH_
#include <vector>
#include <string>
#include "Drawable.hh"
#include "Graph.hh"

class Histo : public Drawable{ //Inherited
double n,min,max,interval;
long fNunderflow=0,fNoverflow=0;
public:
Histo(const char* name,double n,double min,double max); //Constructor	
void Fill(double x);
long GetUnder(){return fNunderflow;}
long GetOver(){return fNoverflow;}
void Clear();
void Draw(bool is_err=false);
double Integral();
double GetMean();
double GetRMS();
};
#endif

