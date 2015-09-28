




//这是老师本星期布置的作业，是使用类的继承与抽象类知识的作业
//在对此文件进行测试时请将mylinklist文件（包括cpp与h文件）从本项目中排除


//之前因为没有理解意思误删了原来打印至网页与文件的代码，现已恢复，只需看MyLink2即可，不需再看mylinklist文件。
//之前没有理解意思，把打印至屏幕理解成了打印至网页，现已调整。




#ifndef MYLINK2_H
#define MYLINK2_H
#pragma once
#include <iostream>
#include <string>
#include"MyOut.h"
template<class TemplateClass>
class MyOut;
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
class CStudent
{
public:
	char cName[10];
	char cID[20];
	float nScores[6];
	CStudent * next;
	float GetAverage()
	{
		return  (nScores[0] + nScores[1] + nScores[2] + nScores[3] + nScores[4]) / 5;
	}
	void OutPut4Screen()
	{
		cout << cName << "  " << cID << " " << nScores[0] << " " << nScores[1] << " " << nScores[2] << " " << nScores[3] << " " << nScores[4] << endl;
	}
};
//typedef struct Student CStudent;
template<class TemplateClass>
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
	void SortByScore(EnumScoreType enumScoreType, bool bAscend);
	void OutPut2File(const char * pOutFileName);
	void OutPut2HTML();
	void OutPut(MyOut<TemplateClass>*p);
	CMyLinkList& operator+(CMyLinkList&list);
	CMyLinkList& operator=(CMyLinkList&list);
private:
	TemplateClass * new_student();
	void print_a_student(TemplateClass*ptemp);
	void swap(TemplateClass*pt, TemplateClass*pnt, TemplateClass*pbt, TemplateClass*pbnt);
public:
	CStudent * m_pHeader;
};
#endif// MYLINK2_H