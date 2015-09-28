
#ifndef MYOUT_H
#define MYOUT_H
#pragma once
#include "MyLink2.h"
class TemplateClass;
template<class TemplateClass>
class MyOut
{
public:
	virtual void out_put(TemplateClass*p, char*file){};
	MyOut(TemplateClass*p, char*file);
	~MyOut();
	TemplateClass * m_pHeader;
	char file_name[100];
};
#endif// MYOUT_H

