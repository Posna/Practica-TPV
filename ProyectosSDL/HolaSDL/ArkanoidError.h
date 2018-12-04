#pragma once
#include<exception>
#include<stdexcept>

using namespace std;
class ArkanoidError:public logic_error
{
public:
	//virtual const char* what() { return "Error: ";}
	ArkanoidError(const string& m) : logic_error(m) {};
	
};