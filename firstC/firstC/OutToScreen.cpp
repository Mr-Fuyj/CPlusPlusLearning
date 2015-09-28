
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
	cout << "学 号\t姓 名\t所在院系\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5" << endl;
	while (ptemp != NULL){
		cout << ptemp->cID << "\t" << ptemp->cName << "\t";
		cout << "国际软件学院" << "\t";
		for (int i = 0; i < 5; i++){
			cout << ptemp->nScores[i] << "\t";
		}
		ptemp = ptemp->next;
		cout << endl;
	}
}
