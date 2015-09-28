



//这是老师上个星期布置的作业，是没有使用类的继承与抽象类知识的作业
//在对此文件进行测试时请将MyLink文件（包括cpp与h文件）从本项目中排除





#include <fstream>
using namespace std;
#include "mylinklist.h"

CMyLinkList::CMyLinkList(){
	m_pHeader = new CStudent();
	m_pHeader->next = NULL;
}

CMyLinkList::CMyLinkList(const CMyLinkList & aList){
	m_pHeader = new CStudent();
	m_pHeader->next = NULL;
	CStudent*pother = aList.m_pHeader;
	CStudent*ptemp = this->m_pHeader;
	while (pother->next != NULL){
		ptemp->next = new CStudent;
		ptemp = ptemp->next;
		pother = pother->next;
		strcpy_s(ptemp->cID, pother->cID);
		strcpy_s(ptemp->cName, pother->cName);
		for (int i = 0; i < 6; i++){
			ptemp->nScores[i] = pother->nScores[i];
		}
	}
}

CMyLinkList::~CMyLinkList(){
	CStudent*ptemp = m_pHeader;
	CStudent*pttemp;
	while (ptemp->next != NULL){
		pttemp = ptemp->next;
		delete ptemp;
	}
	delete ptemp;
}

bool CMyLinkList::BuildLinkFromFile(const char * pFileName){
	ifstream myIn;
	myIn.open(pFileName);
	if(!myIn.is_open()) return false;
	char cTemp[256] = "fdfdfd";
	myIn.getline(cTemp,255);
	CStudent * pTmp = this->m_pHeader;
	while(!myIn.eof())
	{
		 pTmp->next = new CStudent();
		 pTmp = pTmp->next;
		 pTmp->next = NULL;
		 myIn>>pTmp->cID>>pTmp->cName>>cTemp;
		// float  x1,x2,x3,x4,x5;
		// myIn>>x1>>x2>>x3>>x4>>x5;
		 int nCountScore= sizeof(pTmp->nScores)/sizeof(float)-1;
		 for(int i = 0; i < nCountScore ;i++){
			 myIn>>pTmp->nScores[i];
		 }
		 pTmp->nScores[5] = pTmp->GetAverage();
		 pTmp->OutPut4Screen();
	}	
}
//done;
void CMyLinkList::InsertStu(){
	CStudent*pTemp=new_student();
	pTemp->next = m_pHeader->next;
	m_pHeader->next = pTemp;
	//可进行输出测试
}
//done
void CMyLinkList::DeleteStu(char * pName){
	CStudent*pTemp = m_pHeader;
	CStudent*pBefore = pTemp;
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
void CMyLinkList::FindStudentByName(char * pName){
	CStudent*pTemp = m_pHeader;
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
void CMyLinkList::FindStudentByID(char * pName){
	CStudent*pTemp = m_pHeader;
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
void CMyLinkList::GetAverageStore(){
	CStudent * ptemp = m_pHeader;
	long long sum[5]{0};
	int number_of_student = 0;
	while (ptemp->next != NULL){
		ptemp = ptemp->next;
		number_of_student++;
	}
	ptemp = m_pHeader->next;
	for (int k = 0; k < 5; k++){
		for (int i = 0; i < number_of_student; i++){
			sum[k] += ptemp->nScores[k];
			ptemp = ptemp->next;
		}
		ptemp = m_pHeader->next;
	}
	cout << "本届学生各科平均成绩为：";
	for (int i = 0; i < 5; i++){
		cout << sum[i] / number_of_student<<"\t";
	}
	cout << endl;
}
//done
void CMyLinkList::SortByScore(EnumScoreType enumScoreType,bool bAscend){
	CStudent*ptemp = m_pHeader;
	CStudent*pnext_temp = ptemp->next->next;
	CStudent*pbefore_temp = m_pHeader;
	CStudent*pbefore_next_temp = ptemp->next;
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
void CMyLinkList::OutPut2File(const char * pOutFileName){
	ofstream out;
	CStudent*ptemp=m_pHeader->next;
	out.open(pOutFileName,ios::out);
	if( ! out.is_open() ) return ;
	out << "学 号\t姓 名\t所在院系\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5"<<endl;
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
//done
void CMyLinkList::OutPut2Screen(){
	ofstream out;
	CStudent*ptemp = m_pHeader;
	out.open("排序表.html", ios::out);
	if (!out.is_open()) return;
	out << "<html>" << endl<<"<head>"<<endl;
	out << "<title>成绩汇总排序表</title>" << endl;
	out << "</head>" << endl << "<body>" << endl;
	out << "<table border = 2>" << endl;
	while (ptemp->next != 0){
		ptemp = ptemp->next;
		out << "<tr> <td>" << ptemp->cID << "</td><td>" << ptemp->cName;
		for (int i = 0; i < 5; i++){
			out << "</td><td>" << ptemp->nScores[i];
		}
		out << "</td>  </tr>" << endl;
	}
	out << "</body>" << endl << "</html>";
	out.close();
}
//done
CStudent* CMyLinkList::new_student(){
	CStudent*ptemp = new CStudent;
	cout << "请输入学生姓名：" << endl;
	cin >> ptemp->cName;
	cout << "请输入学生ID：" << endl;
	cin >> ptemp->cID;
	for (int i = 0; i <= 4; i++){
		cout << "请输入第" << i << "门成绩：" << endl;
		cin >> ptemp->nScores[i];
	}
	return ptemp;
}
//done
void CMyLinkList::print_a_student(CStudent*ptemp){
	cout << ptemp->cID << "\t" << ptemp->cName << "\t";
	for (int i = 0; i < 5; i++){
		cout << ptemp->nScores[i]<<"\t";
	}
	cout << endl;
}
//done
void CMyLinkList::swap(CStudent*pt, CStudent*pnt, CStudent*pbt, CStudent*pbnt){
	CStudent*temp;
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
