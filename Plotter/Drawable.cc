#include "Drawable.hh"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <cmath>
Drawable::Drawable(const char* name){ //Constructor
	Drawable::fName=name;
}
void Drawable::Print(){ //Print function for testing
	for (int i=0;i<fData.size();i++){
	std::cout<<fData[i].X<<" "<<fData[i].Y<<" "<<fData[i].Yerr<<std::endl;
}
}
void Drawable::Draw(bool is_err){ //Creates .dat file and relies on linux tool kst2. Creates arguments for kst command
	if(Drawable::checker==false){	
	Drawable::filename=fName;
	filename+="_tmp.dat";
	std::ofstream fout(filename);
	std::string tmp="kst2 ";
	tmp+=filename;
	tmp+=option;
	if(is_err==true){
	tmp+=" -x 1 -e 3 -y 2 &";
	for (int i=0;i<fData.size();i++){
	fData[i].Yerr=sqrt(fData[i].Y);
	}
	}
	else tmp+=" -x 1 -y 2 -l &";
	for (int i=0;i<fData.size();i++){
	fout<<fData[i].X<<" "<<fData[i].Y<<" "<<fData[i].Yerr<<std::endl;
}
	fout.close();
	Drawable::checker=true;
	system(tmp.c_str());
	}
	
	else{
	std::cout<<"Error (1) File already used\n";
}
}
int Drawable::GetN(){
	return fData.size();
}
bool Drawable::check=false;
Drawable::~Drawable(){ //Destructor kills process and deletes excess data
	if(check==false){
	std::cin.ignore();
	std::string tmp;
	std::getline(std::cin,tmp); //After 2 enter ends program
	check=true;
	}
	std::string tmp1="rm ";
	tmp1+=filename;
	system(tmp1.c_str());
	tmp1="pkill -f ";
	tmp1+=fName;
	system(tmp1.c_str());
}
