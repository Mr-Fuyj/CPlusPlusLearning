#pragma once
#include<string>
#include<iostream>
using namespace std;

struct CStudent
{
	char Name[10];
	char ID[20];
	int nScore[3];
	struct CStudent * Next;
};
enum EnumScoreType_Tag{
	CHINESE,
	ENGLISH,
	MATH,
}c, e, m;
typedef enum EnumScoreType_Tag EnumScoreType;
class Clink
{
public:
	void InitializeStruct(CStudent * pHeader);
	void OutPutStudent(CStudent * pHeader);
	void output_a_student(CStudent*pHeader);
	struct CStudent* name_a_student();
	void DeleteStu(CStudent * pHeader, char * pName);
	//将某个学生插入到链表中
	void InsertStu(CStudent * pHeader, CStudent* aNewStu);
	//从根据名字从链表中寻找某个学生
	void FindStudentByName(CStudent*pHeader, char * pName);
	//从根据ID从链表中寻找某个学生
	void FindStudentByID(CStudent*pHeader, char * id);
	//求平均成绩
	double GetAverageStore(CStudent * pHeader);
	//根据名字排序
	void SortByName(CStudent * pHeader, bool bAscend);
	//根据ID排序
	void SortByID(CStudent * pHeader, bool bAscend);
	//根据成绩排序
	void SortByScore(CStudent * pHeader, EnumScoreType enumScoreType, bool bAscend);
	void cstudent();
public:
	Clink();
	virtual ~Clink();
};

