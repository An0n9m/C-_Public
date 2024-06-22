#include <iostream>
#include <cmath>
#include <vector>

float operation(float par1,char oper,float par2){
float out=1;
switch (oper)
{
case '+':out=par1+par2;    break;
case '-':out=par1-par2;    break;
case 'x':out=par1*par2;    break;
case '/':out=par1/par2;    break;
case '^':out=pow(par1,par2);break;
default:
break;
}
return out;
}
template <class oper>oper operation(oper op){
oper out=1;
for(oper i=1;i<=op;i++)out*=i;
return out;
}

int main(int argc,char** argv){
if(argc<3){ //Error Handling
std::cerr<<"Usage: "<<argv[0]<<" 3 ! x 2 + 5 ^ 2\n";
return 1;
}
int counter=0;
double tempo;
std::vector<float>param;
std::vector<char>op;
for(int i=1;i<=argc-1;i++){
if(*argv[i]=='x'||*argv[i]=='/'||*argv[i]=='^'||*argv[i]=='!'||*argv[i]=='+'||*argv[i]=='-')op.push_back(*argv[i]); //Checking And Pushing Operations
else param.push_back(atof(argv[i])); //Pushing Numbers
}
while(true){
switch(op[counter]){ //Privileged Operations (Removing Already Done Operations)
case 'x':tempo=operation(param[counter],op[counter],param[counter+1]);param[counter]=tempo;param.erase(param.begin()+(counter+1));op.erase(op.begin()+counter);counter--; 	break;
case '/':tempo=operation(param[counter],op[counter],param[counter+1]);param[counter]=tempo;param.erase(param.begin()+(counter+1));op.erase(op.begin()+counter);counter--;	break;
case '^':tempo=operation(param[counter],op[counter],param[counter+1]);param[counter]=tempo;param.erase(param.begin()+(counter+1));op.erase(op.begin()+counter);counter--;	break;
case '!':if (param[counter]<=21)tempo=operation<unsigned long>(param[counter]); //Using Template To Handle High Numbers In Case Of Factorials
	 else tempo=operation<double>(param[counter]);
	 param[counter]=tempo;op.erase(op.begin()+counter);counter--; 	break;
default:
break;
}
counter++;
if(counter==op.size()){
counter=0;
break;
}
}
while(op.size()!=0){
switch(op[counter]){ //Less Privileged Operations
case '+':tempo=operation(param[counter],op[counter],param[counter+1]);param[counter]=tempo;param.erase(param.begin()+(counter+1));op.erase(op.begin()+counter);counter--; 	break;
case '-':tempo=operation(param[counter],op[counter],param[counter+1]);param[counter]=tempo;param.erase(param.begin()+(counter+1));op.erase(op.begin()+counter);counter--; 	break;
default:
break;
}
counter++;
}
std::cout<<param[0]<<"\n";

return 0;
}
