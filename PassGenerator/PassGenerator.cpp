#include <iostream>
#include <vector>

//Strong Password Generator
int number(std::vector<int>& blacklist) {
    int tmp = rand() % 75; //Pseudorandom number
    for (int i = 0; i < blacklist.size(); i++) {
    if (tmp == blacklist[i]) //Check
    return number(blacklist); //Recursively returns until correct character
}
    blacklist.push_back(tmp); //Adds new generated character into blacklist so character does not repeats
    return tmp;
}
void generator(int len){
std::vector<int>blacklist{10,11,12,14,43,44,45,46,47,47}; //List of blacklisted characters
std::string password;    
    for(int i=0;i<len;i++){
    password+=char(48+number(blacklist));
}
std::cout<<password;
}
int main(int argc,char** argv){
if(argc!=2){
std::cerr<<"Invalid input, usage: "<<argv[0]<<" number(4_66) \n";return 1;
}

srand(time(0));
int length=atof(argv[1]);

if(length<4){
std::cout<<"Password is too short ! ";    
return 0;
}

else if(length>66){ //Max length of my implementation
std::cout<<"Password is too large ! ";
return 0;
}

std::cout<<"Your generated password is: ";
generator(length);

return 0;
}       
