#pragma once
#include "ArkanoidError.h"

class FileFormatError : public ArkanoidError
{
	string formatoCorrecto;
public:
	FileFormatError(const string& m) : ArkanoidError("Error de formato de entrada. Su formato era: " + m + " y deberia de ser: " + formatoCorrecto) {}
};
