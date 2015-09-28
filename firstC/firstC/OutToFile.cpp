
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
	out << "ѧ ��\t�� ��\t����Ժϵ\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ɼ�5" << endl;
	while (ptemp->next != NULL){
		out << ptemp->cID << "\t" << ptemp->cName << "\t";
		out << "�������ѧԺ" << "\t";
		for (int i = 0; i < 5; i++){
			out << ptemp->nScores[i] << "\t";
		}
		ptemp = ptemp->next;
		out << endl;
	}
	out.close();
}
