




//这是老师上个星期布置的作业，是没有使用类的继承与抽象类知识的作业
//在对此文件进行测试时请将MyLink文件（包括cpp与h文件）从本项目中排除





#include <iostream>
#include <string>
using namespace std;
#define NULL 0
enum EnumScoreType_Tag
{
	CHINESE,
	ENGISH,
	MATH,
	C_PLUS_PLUS,
	JAVA_SCORE,
	AVERAGE
};
typedef enum EnumScoreType_Tag EnumScoreType; 
struct Student
{
	char cName[10];
	char cID[20];
	float nScores[6];
	struct Student * next;
	float GetAverage()
	{
		return  (nScores[0]+ nScores[1]+ nScores[2]+nScores[3]+ nScores[4])/5;
	}
	void OutPut4Screen()
	{
		cout<<cName<<"  "<<cID<<" "<<nScores[0]<<" "<< nScores[1]<<" "<< nScores[2]<<" "<<nScores[3]<<" "<< nScores[4]<<endl;
	}
};
typedef struct Student CStudent;

class CMyLinkList
{
public:
	CMyLinkList();
	CMyLinkList(const CMyLinkList & aList);
	~CMyLinkList();
	bool BuildLinkFromFile(const char * pFileName);
public:
	void InsertStu();
	void DeleteStu(char * pName);
	void FindStudentByName(char * pName);
	void FindStudentByID(char * pName);
	void GetAverageStore();
	void SortByScore(EnumScoreType enumScoreType,bool bAscend);
	void OutPut2File(const char * pOutFileName);	
	void OutPut2Screen();
private:
	CStudent * new_student();
	void print_a_student(CStudent*ptemp);
	void swap(CStudent*pt, CStudent*pnt, CStudent*pbt, CStudent*pbnt);
private:
	CStudent * m_pHeader;
};