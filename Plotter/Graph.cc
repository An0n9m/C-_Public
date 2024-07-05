#include "Graph.hh"
#include "Drawable.hh"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

Graph::Graph(const char* name) : Drawable(name){ //Constructor and inheritance
Drawable::fName=name;
}
Graph::Graph(const char* name,int size) : Drawable(name){ //Overloaded constructor
Drawable::fName=name;
Drawable::fData.resize(size);
}
void Graph::AddPoint(double X, double Y, double Yerr){ //Adding points
Drawable::fData.push_back(Point {X,Y,Yerr});
}
void Graph::SetPoint(double X, double Y, double Yerr,unsigned int i){ //Setting point
if(i>Drawable::fData.size()){
	Drawable::fData.resize(i-1);
	Graph::AddPoint(X,Y,Yerr);
}
else{
	Drawable::fData[i]=(Point {X,Y,Yerr});
}
}	
void Graph::Draw(bool is_err){
	Drawable::Draw(is_err);
}
void Graph::Sort(){ //Sorter function
	std::sort(Drawable::fData.begin(),Drawable::fData.end(),[](Point a, Point b){
	return (a.X<b.X);
	});
}
