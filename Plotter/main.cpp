#include <iostream>
#include <vector>
#include <string>
#include "Drawable.hh"
#include "Graph.hh"
#include "Histo.hh"
#include <cmath>
int main(){

Graph gr("graph");
Histo hi("histo",10,5,10);

for (double i=0;i<10;i+=0.001){ //Testing graph
gr.AddPoint(i,sin(i),sqrt(sin(i)));
}
gr.Draw();

hi.Fill(2); //Testing histo
hi.Fill(15);
hi.Fill(7.5);
hi.Fill(7.7);
hi.Fill(7.7);
hi.Fill(7.7);
hi.Fill(8.8);
hi.Draw(true);
return 0;
}
