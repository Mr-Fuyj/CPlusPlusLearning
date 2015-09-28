



//������ʦ�ϸ����ڲ��õ���ҵ����û��ʹ����ļ̳��������֪ʶ����ҵ
//�ڶԴ��ļ����в���ʱ�뽫MyLink�ļ�������cpp��h�ļ����ӱ���Ŀ���ų�





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
	//�ɽ����������
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
			cout << "ɾ���ɹ���" << endl;
			//�˴��ɽ���������ԣ�
			break;
		}
		pBefore = pBefore->next;
	}
	if (pTemp != 0){
		cout << "���޴���!" << endl;
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
		cout << "���޴��ˣ�" << endl;
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
		cout << "���޴��ˣ�" << endl;
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
	cout << "����ѧ������ƽ���ɼ�Ϊ��";
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
	//bAscend==1,��������
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
	//bAscend==0,��������
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
	out << "ѧ ��\t�� ��\t����Ժϵ\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ɼ�5"<<endl;
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
//done
void CMyLinkList::OutPut2Screen(){
	ofstream out;
	CStudent*ptemp = m_pHeader;
	out.open("�����.html", ios::out);
	if (!out.is_open()) return;
	out << "<html>" << endl<<"<head>"<<endl;
	out << "<title>�ɼ����������</title>" << endl;
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
	cout << "������ѧ��������" << endl;
	cin >> ptemp->cName;
	cout << "������ѧ��ID��" << endl;
	cin >> ptemp->cID;
	for (int i = 0; i <= 4; i++){
		cout << "�������" << i << "�ųɼ���" << endl;
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
