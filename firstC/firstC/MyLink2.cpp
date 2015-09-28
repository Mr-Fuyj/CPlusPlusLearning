




//这是老师本星期布置的作业，是使用类的继承与抽象类知识的作业
//在对此文件进行测试时请将mylinklist文件（包括cpp与h文件）从本项目中排除


//之前因为没有理解意思误删了原来打印至网页与文件的代码，现已恢复，只需看MyLink2即可，不需再看mylinklist文件。
//之前没有理解意思，把打印至屏幕理解成了打印至网页，现已调整。







#include "MyLink2.h"
#include <fstream>
using namespace std;
template<class TemplateClass>
CMyLinkList<TemplateClass>::CMyLinkList(){
	m_pHeader = new TemplateClass();
	m_pHeader->next = NULL;
}
template<class TemplateClass>
CMyLinkList<TemplateClass>::CMyLinkList(const CMyLinkList & aList){
	m_pHeader = new TemplateClass();
	m_pHeader->next = NULL;
	TemplateClass*pother = aList.m_pHeader;
	TemplateClass*ptemp = this->m_pHeader;
	while (pother->next != NULL){
		ptemp->next = new TemplateClass;
		ptemp = ptemp->next;
		pother = pother->next;
		strcpy_s(ptemp->cID, pother->cID);
		strcpy_s(ptemp->cName, pother->cName);
		for (int i = 0; i < 6; i++){
			ptemp->nScores[i] = pother->nScores[i];
		}
	}
	ptemp->next = NULL;
}
template<class TemplateClass>
CMyLinkList<TemplateClass>::~CMyLinkList(){
	TemplateClass*ptemp = m_pHeader;
	TemplateClass*pttemp;
	while (ptemp->next != NULL){
		pttemp = ptemp->next;
		delete ptemp;
	}
	delete ptemp;
}
template<class TemplateClass>
bool CMyLinkList<TemplateClass>::BuildLinkFromFile(const char * pFileName){
	ifstream myIn;
	myIn.open(pFileName);
	if (!myIn.is_open()) return false;
	char cTemp[256] = "fdfdfd";
	myIn.getline(cTemp, 255);
	TemplateClass * pTmp = this->m_pHeader;
	while (!myIn.eof())
	{
		pTmp->next = new TemplateClass();
		pTmp = pTmp->next;
		pTmp->next = NULL;
		myIn >> pTmp->cID >> pTmp->cName >> cTemp;
		// float  x1,x2,x3,x4,x5;
		// myIn>>x1>>x2>>x3>>x4>>x5;
		int nCountScore = sizeof(pTmp->nScores) / sizeof(float)-1;
		for (int i = 0; i < nCountScore; i++){
			myIn >> pTmp->nScores[i];
		}
		pTmp->nScores[nCountScore] = pTmp->GetAverage();
		pTmp->OutPut4Screen();
	}
}
//done;
template<class TemplateClass>
void CMyLinkList<TemplateClass>::InsertStu(){
	TemplateClass*pTemp = new_student();
	pTemp->next = m_pHeader->next;
	m_pHeader->next = pTemp;
	//可进行输出测试
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::DeleteStu(char * pName){
	TemplateClass*pTemp = m_pHeader;
	TemplateClass*pBefore = pTemp;
	while (pTemp->next != NULL){
		pTemp = pTemp->next;
		if (strcmp(pName, pTemp->cName) == 0){
			pBefore->next = pTemp->next;
			delete pTemp;
			pTemp = 0;
			cout << "删除成功！" << endl;
			//此处可进行输出测试；
			break;
		}
		pBefore = pBefore->next;
	}
	if (pTemp != 0){
		cout << "查无此人!" << endl;
	}
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::FindStudentByName(char * pName){
	TemplateClass*pTemp = m_pHeader;
	while (pTemp->next != 0){
		pTemp = pTemp->next;
		if (strcmp(pTemp->cName, pName) == 0){
			print_a_student(pTemp);
			pTemp = 0;
			break;
		}
	}
	if (pTemp != 0){
		cout << "查无此人！" << endl;
	}
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::FindStudentByID(char * pName){
	TemplateClass*pTemp = m_pHeader;
	while (pTemp->next != 0){
		pTemp = pTemp->next;
		if (strcmp(pTemp->cID, pName) == 0){
			print_a_student(pTemp);
			pTemp = 0;
			break;
		}
	}
	if (pTemp != 0){
		cout << "查无此人！" << endl;
	}
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::GetAverageStore(){
	TemplateClass * ptemp = m_pHeader;
	const int nCountScore = sizeof(ptemp->nScores) / sizeof(float)-1;
	long long sum[nCountScore]{0};
	int number_of_student = 0;
	while (ptemp->next != NULL){
		ptemp = ptemp->next;
		number_of_student++;
	}
	ptemp = m_pHeader->next;
	for (int k = 0; k < nCountScore; k++){
		for (int i = 0; i < number_of_student; i++){
			sum[k] += ptemp->nScores[k];
			ptemp = ptemp->next;
		}
		ptemp = m_pHeader->next;
	}
	cout << "本届学生各科平均成绩为：";
	for (int i = 0; i < nCountScore; i++){
		cout << sum[i] / number_of_student << "\t";
	}
	cout << endl;
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::SortByScore(EnumScoreType enumScoreType, bool bAscend){
	TemplateClass*ptemp = m_pHeader;
	TemplateClass*pnext_temp = ptemp->next->next;
	TemplateClass*pbefore_temp = m_pHeader;
	TemplateClass*pbefore_next_temp = ptemp->next;
	int number_of_student = 0;
	while (ptemp->next != NULL){
		ptemp = ptemp->next;
		number_of_student++;
	}
	ptemp = m_pHeader->next;
	//bAscend==1,正序排列
	if (bAscend){
		for (int i = 0; i < number_of_student - 1; i++){
			for (int k = 0; k < number_of_student - i - 1; k++){
				if (ptemp->nScores[enumScoreType] < pnext_temp->nScores[enumScoreType]){
					swap(ptemp, pnext_temp, pbefore_temp, pbefore_next_temp);
					if (ptemp == pbefore_next_temp){
						ptemp = pbefore_temp->next;
						pbefore_next_temp = ptemp;
						pnext_temp = pbefore_next_temp->next;
					}
					else{
						ptemp = pbefore_temp->next;
						pnext_temp = pbefore_next_temp->next;
					}
				}
				pbefore_next_temp = pbefore_next_temp->next;
				pnext_temp = pnext_temp->next;
			}
			pbefore_temp = ptemp;
			ptemp = ptemp->next;
			pbefore_next_temp = ptemp;
			pnext_temp = ptemp->next;
		}
	}
	//bAscend==0,倒序排列
	if (!bAscend){
		for (int i = 0; i < number_of_student - 1; i++){
			for (int k = 0; k < number_of_student - i - 1; k++){
				if (ptemp->nScores[enumScoreType] > pnext_temp->nScores[enumScoreType]){
					swap(ptemp, pnext_temp, pbefore_temp, pbefore_next_temp);
					if (ptemp == pbefore_next_temp){
						ptemp = pbefore_temp->next;
						pbefore_next_temp = ptemp;
						pnext_temp = pbefore_next_temp->next;
					}
					else{
						ptemp = pbefore_temp->next;
						pnext_temp = pbefore_next_temp->next;
					}
				}
				pbefore_next_temp = pbefore_next_temp->next;
				pnext_temp = pnext_temp->next;
			}
			pbefore_temp = ptemp;
			ptemp = ptemp->next;
			pbefore_next_temp = ptemp;
			pnext_temp = ptemp->next;
		}
	}
}
//done
template<class TemplateClass>
TemplateClass* CMyLinkList<TemplateClass>::new_student(){
	TemplateClass*ptemp = new TemplateClass;
	int nCountScore = sizeof(ptemp->nScores) / sizeof(float)-1;
	cout << "请输入学生姓名：" << endl;
	cin >> ptemp->cName;
	cout << "请输入学生ID：" << endl;
	cin >> ptemp->cID;
	for (int i = 0; i <= nCountScore; i++){
		cout << "请输入第" << i << "门成绩：" << endl;
		cin >> ptemp->nScores[i];
	}
	return ptemp;
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::print_a_student(TemplateClass*ptemp){
	cout << ptemp->cID << "\t" << ptemp->cName << "\t";
	int nCountScore = sizeof(ptemp->nScores) / sizeof(float)-1;
	for (int i = 0; i < nCountScore; i++){
		cout << ptemp->nScores[i] << "\t";
	}
	cout << endl;
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::swap(TemplateClass*pt, TemplateClass*pnt, TemplateClass*pbt, TemplateClass*pbnt){
	TemplateClass*temp;
	if (pt->next == pnt){
		pt->next = pnt->next;
		pnt->next = pt;
		pbt->next = pnt;
	}
	else{
		temp = pt->next;
		pt->next = pnt->next;
		pbt->next = pnt;
		pnt->next = temp;
		pbnt->next = pt;
	}
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::OutPut(MyOut<TemplateClass> *p){
	p->out_put(p->m_pHeader, p->file_name);
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::OutPut2File(const char * pOutFileName){
	ofstream out;
	TemplateClass*ptemp = m_pHeader->next;
	int nCountScore = sizeof(ptemp->nScores) / sizeof(float)-1;
	out.open(pOutFileName, ios::out);
	if (!out.is_open()) return;
	out << "学 号\t姓 名\t所在院系\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5" << endl;
	while (ptemp->next != NULL){
		out << ptemp->cID << "\t" << ptemp->cName << "\t";
		out << "国际软件学院" << "\t";
		for (int i = 0; i < nCountScore; i++){
			out << ptemp->nScores[i] << "\t";
		}
		ptemp = ptemp->next;
		out << endl;
	}
	out.close();
}
//done
template<class TemplateClass>
void CMyLinkList<TemplateClass>::OutPut2HTML(){
	ofstream out;
	TemplateClass*ptemp = m_pHeader;
	int nCountScore = sizeof(ptemp->nScores) / sizeof(float)-1;
	out.open("排序表.html", ios::out);
	if (!out.is_open()) return;
	out << "<html>" << endl << "<head>" << endl;
	out << "<title>成绩汇总排序表</title>" << endl;
	out << "</head>" << endl << "<body>" << endl;
	out << "<table border = 2>" << endl;
	while (ptemp->next != 0){
		ptemp = ptemp->next;
		out << "<tr> <td>" << ptemp->cID << "</td><td>" << ptemp->cName;
		for (int i = 0; i < nCountScore; i++){
			out << "</td><td>" << ptemp->nScores[i];
		}
		out << "</td>  </tr>" << endl;
	}
	out << "</body>" << endl << "</html>";
	out.close();
}
template<class TemplateClass>
CMyLinkList<TemplateClass> & CMyLinkList<TemplateClass>::operator+(CMyLinkList<TemplateClass>&list){
	CMyLinkList *pList= new CMyLinkList ;
	TemplateClass*pTemp = pList->m_pHeader;
	int nCountScore = sizeof(pTemp->nScores) / sizeof(float)-1;
	pTemp->next = NULL;
	TemplateClass*pother = this->m_pHeader;
	while (pother->next != NULL){
		pTemp->next = new TemplateClass;
		pTemp = pTemp->next;
		pother = pother->next;
		strcpy_s(pTemp->cID, pother->cID);
		strcpy_s(pTemp->cName, pother->cName);
		for (int i = 0; i < nCountScore+1; i++){
			pTemp->nScores[i] = pother->nScores[i];
		}
	}
	pTemp->next = NULL;
	pother = list.m_pHeader;
	while (pother->next != NULL){
		pTemp->next = new TemplateClass;
		pTemp = pTemp->next;
		pother = pother->next;
		strcpy_s(pTemp->cID, pother->cID);
		strcpy_s(pTemp->cName, pother->cName);
		for (int i = 0; i < nCountScore; i++){
			pTemp->nScores[i] = pother->nScores[i];
		}
	}
	pTemp->next = NULL;
	return (*pList);
}
template<class TemplateClass>
CMyLinkList<TemplateClass>& CMyLinkList<TemplateClass>::operator =(CMyLinkList<TemplateClass>&list){
	this->m_pHeader = new TemplateClass();
	this->m_pHeader->next = NULL;
	TemplateClass *pother = list.m_pHeader;
	TemplateClass *ptemp = this->m_pHeader;
	int nCountScore = sizeof(ptemp->nScores) / sizeof(float)-1;
	while (pother->next != NULL){
		ptemp->next = new TemplateClass;
		ptemp = ptemp->next;
		pother = pother->next;
		strcpy_s(ptemp->cID, pother->cID);
		strcpy_s(ptemp->cName, pother->cName);
		for (int i = 0; i < nCountScore+1; i++){
			ptemp->nScores[i] = pother->nScores[i];
		}
	}
	ptemp->next = NULL;
	return *this;
}
