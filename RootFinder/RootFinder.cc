#include "RootFinder.hh"

RootFinder::RootFinder(double (*f)(double)){ //Constructor
func=f;
}
double RootFinder::GetRoot1(double low,double high,double precision) { //Method 1: Bisection
        double result,mid;
	RootFinder::counter=0;
        while (true) {
	RootFinder::counter++;
	mid = (low + high) / 2;
	if(func(mid)+precision>0&&func(mid)-precision<0)break;
	else if(func(low)*func(mid)<0)high=mid;
	else if(func(mid)*func(high)<0)low=mid;
        }
        result=(high+low)/2;
    return  result;
}
double RootFinder::GetRoot2(double low,double high,double precision){ //Method 2: False Position
	RootFinder::counter=0;
	double l=low-high;
	double k=func(low) * l / (func(low) - func(high));
    	double a=low-k;
    	double b=high-k;
    	double c,y;
	while(true){
        c=a-(func(a)*(b-a))/(func(b)-func(a));
        a=b;
        b=c;
        counter++;
        y=func(c);
        if(y<0)y*=-1;
        if(y<=precision)break;
    	}
    return c;	
}
double RootFinder::GetRoot3(double low,double high,double precision){ //Method 3: Secant
	RootFinder::counter=0;
	double c=(low+high)/2;
	double y,l,k,deltaX=0.0001;
	while(true){
	k=(func(c+deltaX)-func(c))/deltaX;
	l=func(c)-(k*c);
	c=-(l/k);
	y=func(c);
	if(y<0)y*=-1;
	if(y<=precision)break;
	counter++;
	}
    return c;
}
double RootFinder::GetRoot3FromStart(double start,double precision){ //Method 3 with different arguments
	double y,l,k,deltaX=0.0001,c=start;
	while(true){
	k=(func(c+deltaX)-func(c))/deltaX;
	l=func(c)-(k*c);
	c=-(l/k);
	y=func(c);
	if(y<0)y*=-1;
	if(y<=precision)break;
	counter++;
	}
    return c;
}
double RootFinder::GetRoot(double low,double high,double precision){ //Fastest method combining both methods
       	double start=GetRoot1(low,high,0.1);
	double result=GetRoot3FromStart(start,precision);
    return result;
}
