
#ifndef OUTTOFILE_H
#define OUTTOFILE_H
#pragma once
#include "MyOut.h"
template<class TemplateClass>
class OutToFile :public MyOut<TemplateClass>
{
public:
	OutToFile(TemplateClass*p, char*file);
	~OutToFile();
	void out_put(TemplateClass*p, char*file);
};
#endif //OUTTOFILE_H
