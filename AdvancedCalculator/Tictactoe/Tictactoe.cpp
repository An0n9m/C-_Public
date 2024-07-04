#include <iostream>
#include <iomanip>
#include <limits>

char checker(char (*matrix)[3],char* winner){ //Check and return winner symbol

     for(int i=0;i<3;i++){
     if(matrix[i][0]==matrix[i][1]&&matrix[i][1]==matrix[i][2]){
     *winner=matrix[i][0];  
     return *winner;
    }
    }

     for(int j=0;j<3;j++){
     if(matrix[0][j]==matrix[1][j]&&matrix[1][j]==matrix[2][j]){
     *winner=matrix[0][j];   
     return *winner; 
    }
    }

     if(matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2]) *winner=matrix[0][0];    
     
     if(matrix[0][2]=='X'&&matrix[1][1]=='X'&&matrix[2][0]=='X') *winner=matrix[0][2];    
    
     return *winner;
}

void print(char (*matrix)[3]){ //Matrix print function
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
    std::cout<<std::setw(2)<<matrix[i][j]<<std::setw(2);
}
    std::cout<<std::endl;
}   
}

int main(){
const int size = 3;
char matrix [size][size],symbol='*',prevSymbol='*',winner='*';
bool tie=false;
short row=0,col=0,counter=0;
for(int i=0;i<size;i++){ //Filling up matrix with default symbols
    for(int j=0;j<size;j++)matrix[i][j]='*';
}

std::cout<<"Enter row, column and symbol(0,x) example: 1 1 x \n";

print(matrix);

while(true){
if(counter==9 && winner=='*'){ //Checking Tie
std::cout<<std::setw(4)<<"TIE"<<std::setw(4)<<std::endl;
tie=true;
break;
}

std::cin>>row>>col>>symbol;

if(std::cin.fail()) {
std::cin.clear(); // Clear the error flag
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
std::cout << "Invalid input! Please enter row, column, and symbol correctly.\n";
print(matrix);
continue;
}

if(row>3||col>3||row<1||col<1){ //Check for boundaries
std::cout<<"Out of game boundaries  \n";
print(matrix);
continue;
}

if(symbol!='x'&&symbol!='0'){ //Symbol checking
std::cout<<"Wrong symbol! \n";
print(matrix);
continue;
}

if(matrix[row-1][col-1]!='*'){ //Checking used place
std::cout<<"There is already character! \n";
print(matrix);
continue;
}

if(symbol==prevSymbol){ //Correct ordering
std::cout<<"Wait to your opponent! \n";
print(matrix);
continue;
}
prevSymbol=symbol;

matrix[row-1][col-1]=symbol; //Filling matrix
print(matrix);   
if(counter>=5) { //For program optimization
   symbol=checker(matrix, &winner);
   if(symbol=='0'||symbol=='x') break;
}
counter++;
}

if(tie==false)std::cout<<"Winner is "<<winner<<" Congratulations! \n";

return 0;
}
