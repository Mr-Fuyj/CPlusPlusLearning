
#ifndef OUTTOHTML_H
#define OUTTOHTML_H
#pragma once
#include "MyOut.h"
template<class TemplateClass>
class OutTOHTML :
	public MyOut<TemplateClass>
{
public:
	OutTOHTML(TemplateClass *p, char*file);
	void out_put(TemplateClass *p, char*file);
	~OutTOHTML();
};
#endif //OUTTOHTML_H
