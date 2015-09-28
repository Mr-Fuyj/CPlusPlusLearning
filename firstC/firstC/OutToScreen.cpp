
#include "OutToScreen.h"
#include<iostream>
template<class TemplateClass>
OutToScreen<TemplateClass>::OutToScreen(TemplateClass*p, char*file) :MyOut<TemplateClass>(p, file)
{
}

template<class TemplateClass>
void OutToScreen<TemplateClass>::out_put(TemplateClass*p, char*file){
	using namespace std;
	TemplateClass*ptemp = this->m_pHeader->next;
	cout << "ѧ ��\t�� ��\t����Ժϵ\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ɼ�5" << endl;
	while (ptemp != NULL){
		cout << ptemp->cID << "\t" << ptemp->cName << "\t";
		cout << "�������ѧԺ" << "\t";
		for (int i = 0; i < 5; i++){
			cout << ptemp->nScores[i] << "\t";
		}
		ptemp = ptemp->next;
		cout << endl;
	}
}
