




//������ʦ�ϸ����ڲ��õ���ҵ����û��ʹ����ļ̳��������֪ʶ����ҵ
//�ڶԴ��ļ����в���ʱ�뽫MyLink�ļ�������cpp��h�ļ����ӱ���Ŀ���ų�





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