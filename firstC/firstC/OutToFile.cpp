
#include "OutToFile.h"
#include <fstream>
template<class TemplateClass>
OutToFile<TemplateClass>::OutToFile<TemplateClass>(TemplateClass*p, char*file) : MyOut(p, file)
{
}

template<class TemplateClass>
OutToFile<TemplateClass>::~OutToFile<TemplateClass>()
{
}
template<class TemplateClass>
void OutToFile<TemplateClass>::out_put(TemplateClass*p, char*file){
	ofstream out;
	TemplateClass*ptemp = this->m_pHeader->next;
	out.open(file, ios::out);
	if (!out.is_open()) return;
	out << "学 号\t姓 名\t所在院系\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5" << endl;
	while (ptemp->next != NULL){
		out << ptemp->cID << "\t" << ptemp->cName << "\t";
		out << "国际软件学院" << "\t";
		for (int i = 0; i < 5; i++){
			out << ptemp->nScores[i] << "\t";
		}
		ptemp = ptemp->next;
		out << endl;
	}
	out.close();
}
