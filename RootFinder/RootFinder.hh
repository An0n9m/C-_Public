#ifndef _ROOTFINDER_H_
#define _ROOTFINDER_H_
class RootFinder{
	int counter;
	double (*func)(double);
public:
	RootFinder(double(*f)(double));
	double GetRoot1(double low,double high,double precision=0.0001);
	double GetRoot2(double low,double high,double precision=0.0001);
	double GetRoot3(double low,double high,double precision=0.0001);
	double GetRoot3FromStart(double start,double precision);
	double GetRoot(double low,double high,double precision);
	int GetCounter(){return counter;}
};	
#endif
