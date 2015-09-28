#include <iostream>
#include <string>
using namespace std;

struct Student
{
	char Name[10];
	char ID[20];
	int nScore[3];
	struct Student * Next;
};
typedef struct Student CStudent;

void InitializeStruct(CStudent * pHeader);
void OutPutStudent(CStudent * pHeader);
void output_a_student(CStudent*pHeader);//defined by myself;
CStudent* name_a_student();
#define NULL 0

//从链表中删除某个学生
void DeleteStu(CStudent * pHeader, char * pName){
	CStudent*pTemp = pHeader->Next;
	CStudent*pBefore = pHeader;
	while (pTemp != NULL){
		if (strcmp(pTemp->Name, pName) == 0){
			pBefore->Next = pTemp->Next;
			break;
		}
		else{
			pTemp = pTemp->Next;
			pBefore = pBefore->Next;
		}
	}
	delete pTemp;
}
//将某个学生插入到链表中
void InsertStu(CStudent * pHeader, CStudent* aNewStu){
	CStudent*p1 = new CStudent;
	*p1 = *aNewStu;
	CStudent*pTemp = pHeader->Next;
	pHeader->Next = p1;
	pHeader->Next->Next = pTemp;
}
//从根据名字从链表中寻找某个学生
void FindStudentByName(CStudent*pHeader,char * pName){
	CStudent*pTemp = pHeader->Next;
	while (pTemp != NULL){
		if (strcmp(pTemp->Name, pName) == 0){
			output_a_student(pTemp);
			break;
		}
		else{
			pTemp = pTemp->Next;
		}
	}
}
//从根据ID从链表中寻找某个学生
void FindStudentByID(CStudent*pHeader,char * id){
	CStudent*pTemp = pHeader->Next;
	while (pTemp != NULL){
		if (strcmp(pTemp->ID, id) == 0){
			output_a_student(pTemp);
			break;
		}
		else{
			pTemp = pTemp->Next;
		}
	}
}
//求平均成绩
double GetAverageStore(CStudent * pHeader){
	double average;
	average = pHeader->nScore[0] + pHeader->nScore[1] + pHeader->nScore[2];
	average /= 3;
	return average;
}
//根据名字排序
void SortByName(CStudent * pHeader, bool bAscend){
	int m=0;
	CStudent*pTemp = pHeader->Next;
	CStudent*pBtemp = pHeader;
	CStudent*pNext_temp = pTemp->Next;
	CStudent*pBnext_temp = pTemp;
	while (pTemp != NULL){
		pTemp = pTemp->Next;
		m++;
	}
	pTemp = pHeader->Next;
	//bAscend==true,正序排布；
	if (bAscend){
		for (int i = 1; i <= m - 1; i++){
			for (int k = 1; k <= m - i - 1; k++){
				if (strcmp(pTemp->Name, pNext_temp->Name) < 0){
					if (pBnext_temp == pTemp){
						CStudent*change = pNext_temp->Next;
						pBtemp->Next = pNext_temp;
						pNext_temp->Next = pTemp;
						pTemp->Next = change;
						pTemp = pBtemp->Next;
						pBnext_temp = pTemp;//pBnext_temp指向的仍是第一个元素，而非位置，因此用这个语句使其转变。
					}
					else{
						CStudent*pChange = pNext_temp->Next;
						pBnext_temp->Next = pTemp;
						pNext_temp->Next = pTemp->Next;
						pBtemp->Next = pNext_temp;
						pTemp->Next = pChange;
						pTemp = pBtemp->Next;//指向现在在那个位置的元素
					}
				}
				pBnext_temp = pBnext_temp->Next;
				pNext_temp = pBnext_temp->Next;
			}
			pTemp = pTemp->Next;
			pBtemp = pBtemp->Next;
			pNext_temp = pTemp->Next;
			pBnext_temp = pTemp;
		}
	}
	//bAscend==false,倒序排布；
	if (!bAscend){
		for (int i = 1; i <= m - 1; i++){
			for (int k = 1; k <= m - i - 1; k++){
				if (strcmp(pTemp->Name, pNext_temp->Name) > 0){
					if (pBnext_temp == pTemp){
						CStudent*change = pNext_temp->Next;
						pBtemp->Next = pNext_temp;
						pNext_temp->Next = pTemp;
						pTemp->Next = change;
						pTemp = pBtemp->Next;
						pBnext_temp = pTemp;//pBnext_temp指向的仍是第一个元素，而非位置，因此用这个语句使其转变。
					}
					else{
						CStudent*pChange = pNext_temp->Next;
						pBnext_temp->Next = pTemp;
						pNext_temp->Next = pTemp->Next;
						pBtemp->Next = pNext_temp;
						pTemp->Next = pChange;
						pTemp = pBtemp->Next;//指向现在在那个位置的元素
					}
				}
				pBnext_temp = pBnext_temp->Next;
				pNext_temp = pBnext_temp->Next;
			}
			pTemp = pTemp->Next;
			pBtemp = pBtemp->Next;
			pNext_temp = pTemp->Next;
			pBnext_temp = pTemp;
		}
	}
}
//根据ID排序
void SortByID(CStudent * pHeader, bool bAscend){
	int m = 0;
	CStudent*pTemp = pHeader->Next;
	CStudent*pBtemp = pHeader;
	CStudent*pNext_temp = pTemp->Next;
	CStudent*pBnext_temp = pTemp;
	while (pTemp != NULL){
		pTemp = pTemp->Next;
		m++;
	}
	pTemp = pHeader->Next;
	//bAscend == true, 正序排布；
	if (bAscend){
		for (int i = 1; i <= m-1; i++){
			for (int k = 1; k <= m -i-1; k++){
				if (strcmp(pTemp->ID, pNext_temp->ID) < 0){
					if (pBnext_temp == pTemp){
						CStudent*change = pNext_temp->Next;
						pBtemp->Next = pNext_temp;
						pNext_temp->Next = pTemp;
						pTemp->Next = change;
						pTemp = pBtemp->Next;
						pBnext_temp = pTemp;//pBnext_temp指向的仍是第一个元素，而非位置，因此用这个语句使其转变。
					}
					else{
						CStudent*pChange = pNext_temp->Next;
						pBnext_temp->Next = pTemp;
						pNext_temp->Next = pTemp->Next;
						pBtemp->Next = pNext_temp;
						pTemp->Next = pChange;
						pTemp = pBtemp->Next;//指向现在在那个位置的元素
					}
				}
				pBnext_temp = pBnext_temp->Next;
				pNext_temp = pBnext_temp->Next;
			}
			pTemp = pTemp->Next;
			pBtemp = pBtemp->Next;
			pNext_temp = pTemp->Next;
			pBnext_temp = pTemp;
		}
	}
	//bAscend==false,倒序排布；
	if (!bAscend){
		for (int i = 1; i <= m - 1; i++){
			for (int k = 1; k <= m - i - 1; k++){
				if (strcmp(pTemp->ID, pNext_temp->ID) > 0){
					if (pBnext_temp == pTemp){
						CStudent*change = pNext_temp->Next;
						pBtemp->Next = pNext_temp;
						pNext_temp->Next = pTemp;
						pTemp->Next = change;
						pTemp = pBtemp->Next;
						pBnext_temp = pTemp;//pBnext_temp指向的仍是第一个元素，而非位置，因此用这个语句使其转变。
					}
					else{
						CStudent*pChange = pNext_temp->Next;
						pBnext_temp->Next = pTemp;
						pNext_temp->Next = pTemp->Next;
						pBtemp->Next = pNext_temp;
						pTemp->Next = pChange;
						pTemp = pBtemp->Next;//指向现在在那个位置的元素
					}
				}
				pBnext_temp = pBnext_temp->Next;
				pNext_temp = pBnext_temp->Next;
			}
			pTemp = pTemp->Next;
			pBtemp = pBtemp->Next;
			pNext_temp = pTemp->Next;
			pBnext_temp = pTemp;
		}
	}
}
//根据成绩排序
void SortByScore(CStudent * pHeader, EnumScoreType enumScoreType, bool bAscend){
	int m = 0;
	CStudent*pTemp = pHeader->Next;
	CStudent*pBtemp = pHeader;
	CStudent*pNext_temp = pTemp->Next;
	CStudent*pBnext_temp = pTemp;
	while (pTemp != NULL){
		pTemp = pTemp->Next;
		m++;
	}
	pTemp = pHeader->Next;
	//bAscend==true,正序排布；
	if (bAscend){
		for (int i = 1; i <= m - 1; i++){
			for (int k = 1; k <= m - i - 1; k++){
				if (pTemp->nScore[enumScoreType]<pNext_temp->nScore[enumScoreType]){
					if (pBnext_temp == pTemp){
						CStudent*change = pNext_temp->Next;
						pBtemp->Next = pNext_temp;
						pNext_temp->Next = pTemp;
						pTemp->Next = change;
						pTemp = pBtemp->Next;
						pBnext_temp = pTemp;//pBnext_temp指向的仍是第一个元素，而非位置，因此用这个语句使其转变。
					}
					else{
						CStudent*pChange = pNext_temp->Next;
						pBnext_temp->Next = pTemp;
						pNext_temp->Next = pTemp->Next;
						pBtemp->Next = pNext_temp;
						pTemp->Next = pChange;
						pTemp = pBtemp->Next;//指向现在在那个位置的元素
					}
				}
				pBnext_temp = pBnext_temp->Next;
				pNext_temp = pBnext_temp->Next;
			}
			pTemp = pTemp->Next;
			pBtemp = pBtemp->Next;
			pNext_temp = pTemp->Next;
			pBnext_temp = pTemp;
		}
	}
	//bAscend==false,倒序排布；
	if (!bAscend){
		for (int i = 1; i <= m - 1; i++){
			for (int k = 1; k <= m - i - 1; k++){
				if (pTemp->nScore[enumScoreType]>pNext_temp->nScore[enumScoreType]){
					if (pBnext_temp == pTemp){
						CStudent*change = pNext_temp->Next;
						pBtemp->Next = pNext_temp;
						pNext_temp->Next = pTemp;
						pTemp->Next = change;
						pTemp = pBtemp->Next;
						pBnext_temp = pTemp;//pBnext_temp指向的仍是第一个元素，而非位置，因此用这个语句使其转变。
					}
					else{
						CStudent*pChange = pNext_temp->Next;
						pBnext_temp->Next = pTemp;
						pNext_temp->Next = pTemp->Next;
						pBtemp->Next = pNext_temp;
						pTemp->Next = pChange;
						pTemp = pBtemp->Next;//指向现在在那个位置的元素
					}
				}
				pBnext_temp = pBnext_temp->Next;
				pNext_temp = pBnext_temp->Next;
			}
			pTemp = pTemp->Next;
			pBtemp = pBtemp->Next;
			pNext_temp = pTemp->Next;
			pBnext_temp = pTemp;
		}
	}
}

void InitializeStruct(CStudent * pHeader)
{
	pHeader->Next = new CStudent;
	CStudent *pTemp = pHeader->Next;
	pTemp->Next = NULL;

	//Assign Value to Member
	strcpy_s(pTemp->Name, "张三");
	strcpy_s(pTemp->ID, "1234567");
	int nCount = sizeof(pTemp->nScore) / sizeof(int);
	for (int i = 0; i <nCount; i++)
	{
		pTemp->nScore[i] = i + 60;
	}

	pTemp->Next = new CStudent;
	pTemp = pTemp->Next;
	pTemp->Next = NULL;


	strcpy_s(pTemp->Name, "李四");
	strcpy_s(pTemp->ID, "6666666");
	nCount = sizeof(pTemp->nScore) / sizeof(int);
	for (int i = 0; i <nCount; i++)
	{
		pTemp->nScore[i] = i + 70;
	}

	pTemp->Next = new CStudent;
	pTemp = pTemp->Next;
	pTemp->Next = NULL;

	strcpy_s(pTemp->Name, "王二");
	strcpy_s(pTemp->ID, "7654321");
	nCount = sizeof(pTemp->nScore) / sizeof(int);
	for (int i = 0; i <nCount; i++)
	{
		pTemp->nScore[i] = i + 80;
	}


	pTemp->Next = new CStudent;
	pTemp = pTemp->Next;
	pTemp->Next = NULL;

	strcpy_s(pTemp->Name, "王五");
	strcpy_s(pTemp->ID, "654389");
	nCount = sizeof(pTemp->nScore) / sizeof(int);
	for (int i = 0; i <nCount; i++)
	{
		pTemp->nScore[i] = i + 90;
	}
}
void OutPutStudent(CStudent * pHeader){
	CStudent * pTemp = pHeader->Next;
	while (NULL != pTemp)
	{
		cout << pTemp->ID << "  " << pTemp->Name << "  ";
		int nCount = sizeof(pTemp->nScore) / sizeof(int);
		for (int i = 0; i <nCount; i++)
		{
			cout << pTemp->nScore[i] << "  ";
		}
		cout << endl;
		pTemp = pTemp->Next;
	}
}
void output_a_student(CStudent*pHeader){
	cout << pHeader->ID << "  " << pHeader->Name << "  ";
	for (int i = 0; i <3; i++){
		cout << pHeader->nScore[i] << "  ";
	}
}
CStudent* name_a_student(){
	char name[10];
	char id[20];
	int score[3];
	cout << "输入名字：" << endl;
	cin >> name;
	cout << "输入ID：" << endl;
	cin >> id;
	cout << "输入语文成绩：" << endl;
	cin >> score[0];
	cout << "输入英语成绩：" << endl;
	cin >> score[1];
	cout << "输入数学成绩：" << endl;
	cin >> score[2];
	CStudent *new_student=new CStudent;
	strcpy_s(new_student->Name , name);
	strcpy_s(new_student->ID, id);
	for (int i = 0; i <3; i++){
		new_student->nScore[i] = score[i];
	}
	return new_student;
}
void cstudent()
{
	CStudent * pStu = new CStudent;
	pStu->Next = NULL;
	InitializeStruct(pStu);
	OutPutStudent(pStu);
	int nchoose;
	while (true){
		cout << "请输入指令编码：" << endl;
		cout << "1,从链表中删除某个学生；" << endl;
		cout << "2,从链表中增加某个学生；" << endl;
		cout << "3,根据名字查找某个学生；" << endl;
		cout << "4,根据学号查找某个学生；" << endl;
		cout << "5,将学生按照姓名排列；" << endl;
		cout << "6,将学生按照学号排列；" << endl;
		cout << "7,将学生按照成绩排列；" << endl;
		cin >> nchoose;
		switch (nchoose){
		case 1:{
				   char name[20];
				   cout << "请输入姓名：" << endl;
				   cin >> name;
				   DeleteStu(pStu, name);
				   OutPutStudent(pStu);
				   break;
		}
		case 2:{
				   InsertStu(pStu, name_a_student());
				   OutPutStudent(pStu);
				   break;
		}
		case 3:{
				   char name[10];
				   cout << "输入学生名字：" << endl;
				   cin >> name;
				   FindStudentByName(pStu, name);
				   break;
		}
		case 4:{
				   char id[20];
				   cout << "输入学生ID：" << endl;
				   cin >> id;
				   FindStudentByID(pStu, id);
				   break;
		}
		case 5:{
				   bool b;
				   cout << "正序排列请输入1，倒序排列请输入0：" << endl;
				   cin >> b;
				   SortByName(pStu, b);
				   OutPutStudent(pStu);
				   break;
		}
		case 6:{
				   bool b;
				   cout << "正序排列请输入1，倒序排列请输入0：" << endl;
				   cin >> b;
				   SortByID(pStu, b);
				   OutPutStudent(pStu);
				   break;
		}
		case 7:{
				   int choose;
				   bool b;
				   cout << "正序排列请输入1，倒序排列请输入0：" << endl;
				   cin >> b;
				   cout << "请输入科目代号：1，语文；2，英语；3，数学：" << endl;
				   cin >> choose;
				   /*EnumScoreType  c, e, m;*/
				   switch (choose){
				   case 1:{
							  SortByScore(pStu, c, b);
							  break;
				   }
				   case 2:{
							  SortByScore(pStu, e, b);
							  break;
				   }
				   case 3:{
							  SortByScore(pStu, m, b);
							  break;
				   }
				   default:{
							   cout << "指令错误！" << endl;
				   }
				   }
				   OutPutStudent(pStu);
				   break;
		}
		default:{
					cout << "指令错误！" << endl;
		}
		}
	}
}