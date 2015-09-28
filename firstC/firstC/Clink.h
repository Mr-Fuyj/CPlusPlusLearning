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
	//��ĳ��ѧ�����뵽������
	void InsertStu(CStudent * pHeader, CStudent* aNewStu);
	//�Ӹ������ִ�������Ѱ��ĳ��ѧ��
	void FindStudentByName(CStudent*pHeader, char * pName);
	//�Ӹ���ID��������Ѱ��ĳ��ѧ��
	void FindStudentByID(CStudent*pHeader, char * id);
	//��ƽ���ɼ�
	double GetAverageStore(CStudent * pHeader);
	//������������
	void SortByName(CStudent * pHeader, bool bAscend);
	//����ID����
	void SortByID(CStudent * pHeader, bool bAscend);
	//���ݳɼ�����
	void SortByScore(CStudent * pHeader, EnumScoreType enumScoreType, bool bAscend);
	void cstudent();
public:
	Clink();
	virtual ~Clink();
};

