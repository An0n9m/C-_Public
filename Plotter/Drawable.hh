#ifndef _DRAWABLE_HH_
#define _DRAWABLE_HH_
#include <vector>
#include <string>
struct Point{ //Point coordinates 
double X;
double Y;
double Yerr;
};

class Drawable{ 
public:
        Drawable(const char* name);
        void Print();
	int GetN();
	virtual void Draw(bool is_err=false);
	~Drawable();
protected:
	std::string option="";
	std::string fName;
	std::string filename;
	std::vector<Point>fData;
	bool checker=false;
	static bool check;
};
#endif
