




//������ʦ�����ڲ��õ���ҵ����ʹ����ļ̳��������֪ʶ����ҵ
//�ڶԴ��ļ����в���ʱ�뽫mylinklist�ļ�������cpp��h�ļ����ӱ���Ŀ���ų�


//֮ǰ��Ϊû�������˼��ɾ��ԭ����ӡ����ҳ���ļ��Ĵ��룬���ѻָ���ֻ�迴MyLink2���ɣ������ٿ�mylinklist�ļ���
//֮ǰû�������˼���Ѵ�ӡ����Ļ�����˴�ӡ����ҳ�����ѵ�����




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