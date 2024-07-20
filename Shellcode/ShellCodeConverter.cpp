#include <iostream>
#include <cstring>

void rawToShell(std::string raw, bool littleEndian){
std::string out;
for(int i=0;i<raw.length();i++){ //Removing empty space
if(raw[i]==' '){
raw.erase(raw.begin()+i);
i--;
}
}

for(int i=0;i<(raw.length()/2);i++){ //Adding '\x' padding
out+=char(int(92));
out+='x';
out+=raw[2*i];
out+=raw[(2*i)+1];
}

if(!littleEndian)std::cout<<"\nOutput: "<<out<<"\n"<<"Shellcode Length: "<<out.length(); //Big endian output
else if(littleEndian){
std::cout<<"\nOutput: ";
for(int i=out.length()-1;i>-1;i-=4)std::cout<<out[i-3]<<out[i-2]<<out[i-1]<<out[i]; //Little endian output
std::cout<<"\nShellcode Length: "<<out.length(); 
}
}

void shellToRaw(std::string shell, bool littleEndian){
for(int i=0;i<shell.length();i++){
if(shell[i]=='\\'||shell[i]=='x'||shell[i]==' '){ //Removing padding and empty space
shell.erase(shell.begin()+i);
i--;
}
}

for(int i=0;i<shell.length();i+=2){ //Adding empty space between bytes
shell.insert(shell.begin()+i,' ');
i++;
}

if(!littleEndian)std::cout<<"\nOutput: "<<shell<<"\n"<<"Rawcode Length: "<<shell.length()-(shell.length()/3); //Big endian output
else if(littleEndian){
std::cout<<"\nOutput: ";
for(int i=shell.length()-1;i>-1;i-=3)std::cout<<shell[i-2]<<shell[i-1]<<shell[i]; //little endian output
std::cout<<"\nRawcode Length: "<<shell.length()-(shell.length()/3);
}
}

int main(int argc,char** argv){

bool littleEndian=false; //Init
std::string in;
char choice;

if(argc<2||strlen(argv[1])!=2){ //Error checking
std::cerr<<"Invalid input, usage: "<<argv[0]<<" (-s raw to shellcode -r shellcode to raw) "<<" -l (little endian optional) default: big endian \n";
return 1;
}

else if(argc==2){
choice=argv[1][1];
}

else if(argc==3){
choice=argv[1][1];
littleEndian=true;
}

else {
std::cerr<<"Too many arguments! \n";
return 2;
}

std::cout<<"Data: ";
std::getline(std::cin,in); //Using C++ cin and string so getline is safe

if(choice=='s')rawToShell(in,littleEndian); //Checking
else if(choice=='r')shellToRaw(in,littleEndian);
else { //Error checking
std::cerr<<"Wrong option!\n";
return 3;
}

std::cout<<"\nKeep Hacking :)\n";

return 0; //Written by An0n9m
}
