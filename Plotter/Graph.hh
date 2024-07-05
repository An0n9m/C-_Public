#ifndef _GRAPH_HH_
#define _GRAPH_HH_
#include "Drawable.hh"

class Graph : public Drawable{ //Inherited
public:
Graph(const char* name); //Constructor
Graph(const char* name,int size); //Constructor overload
void AddPoint(double X, double Y, double Yerr=0);
void AddPoint(double X, double Y, double Yerr, int size);
void SetPoint(double X, double Y, double Yerr,unsigned int i);
void Draw(bool is_err=false);
void Sort();
};
#endif
