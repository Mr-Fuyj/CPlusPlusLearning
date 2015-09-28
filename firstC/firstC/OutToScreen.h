#ifndef OUTTOSCREEN_H
#define OUTTOSCREEN_H
#pragma once
#include"MyOut.h"
template<class TemplateClass>
class OutToScreen :public MyOut<TemplateClass>
{
public:
	void out_put(TemplateClass*p,char*file);
	OutToScreen(TemplateClass*p,char*file);
	~OutToScreen();
};
#endif //OUTTOSCREEN_H
