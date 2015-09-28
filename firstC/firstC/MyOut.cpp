

#include "MyOut.h"
#include<cstring>
template<class TemplateClass>
MyOut<TemplateClass>::MyOut(TemplateClass* p, char*file){
	m_pHeader = p;
	strcpy_s(file_name, file);
}
template<class TemplateClass>
MyOut<TemplateClass>::~MyOut(){
}
