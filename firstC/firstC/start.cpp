//#include"ch.h"
//#include"example_of_section 2.h"
//#include"example_of_section 3.h"
//#include"example_of_section 6.h"
//#include"Clink.h"
//#include"mylinklist.h"
#include"MyLink2.h"
#include"OutToFile.h"
#include"OutToScreen.h"
#include"OutTOHTML.h"


#include"MyLink2.cpp"
#include"OutToFile.cpp"
#include"OutToScreen.cpp"
#include"OutTOHTML.cpp"
#include"MyOut.cpp"
void main(){
	CMyLinkList <CStudent> list;
	char file_name[30];
	int choose;
	cout << "请输入文件目录：";
	cin >> file_name;
	list.BuildLinkFromFile(file_name);
	while (1){
		cout << "请在以下功能中选择：" << endl;
		cout << "1.加入学生；\n2.删除学生；\n3.按名字查找学生；\n4.按ID查找学生；\n5.获取平均分；";
		cout<<"\n6.按成绩排列；\n7.打印成绩表；\n8.打印至网页；\n9.打印至屏幕；\n10.合并成绩表；\n11.退出程序。";
		cin >> choose;
		switch (choose) {
		case 1:{
				   list.InsertStu();
				   break;
			}
		case 2:{
				   char name[30];
				   cout << "请输入学生名字：" << endl;
				   cin >> name;
				   list.DeleteStu(name);
				   break;
		}
		case 3:{
				   char name[30];
				   cout << "请输入学生名字：" << endl;
				   cin >> name;
				   list.FindStudentByName(name);
				   break;
		}
		case 4:{
				   char ID[30];
				   cout << "请输入学生名字：" << endl;
				   cin >> ID;
				   list.FindStudentByID(ID);
				   break;
		}
		case 5:{
				   list.GetAverageStore();
				   break;
		}
		case 6:{
				   EnumScoreType subject;
				   int num;
				   bool order;
				   cout << "请输入科目代码：" << endl;
				   cout << "1.语文；\n2.英语；\n3.数学；\n4.c++；\n5.Java；\n6.平均值；\n" << endl;
				   cin >> num;
				   cout << "请输入排列方式：" << endl;
				   cout << "0.倒序排列\n1.正序排列\n";
				   cin >> order;
				   switch (num-1)
				   {
				   case 0:subject = CHINESE; break;
				   case 1:subject = ENGISH; break;
				   case 2:subject = MATH; break;
				   case 3:subject = C_PLUS_PLUS; break;
				   case 4:subject = JAVA_SCORE; break;
				   case 5:subject = AVERAGE; break;
				   default:
					   break;
				   }
				   list.SortByScore(subject,order);
				   break;
		}
		case 7:{
				   char file_name[30];
				   cout << "请输入欲输入到的文件名：" << endl;
				   cin >> file_name;
				   MyOut<CStudent>*p = new OutToFile<CStudent>(list.m_pHeader, file_name);
				   list.OutPut(p);
				   break;
		}
		case 8:{
				   char*pt = "a";
				   MyOut<CStudent>*p = new OutTOHTML<CStudent>(list.m_pHeader, pt);
				   list.OutPut(p);
				   break;
		}case 9:{
				   char*pt = "a";
				   MyOut<CStudent>*p = new OutToScreen<CStudent>(list.m_pHeader, pt);
				   list.OutPut(p);
				   break;
		}
		case 10:{
					char cFile[100];
					cout << "请输入另一个成绩表的路径：" << endl;
					cin >> cFile;
					CMyLinkList<CStudent> *p = new CMyLinkList<CStudent>;
					p->BuildLinkFromFile(cFile);
					list = list + *p;
					break;
		}
		default:{
		}
		}
	}






//	//p1_1();
//	//p1_2();
//	//p1_3();
//	//p1_4();
//	//p1_5();
//	//hw1_1();
//	//hw1_2();
//	//hw1_3();
//	//hw1_4();
//	//hw1_5();
//	//hw1_6();
//	//hw1_7();
//	//hw1_8();
//	//hw1_9();
//	//hw1_10();
//	//hw1_11();
//	//hw1_12();
//	//hw1_13();
//	//calendar();
//	compare_test();
	//cstudent();
	//eg2_1();
	//eg2_2();
	//eg2_3();
	//eg2_4();
	//eg2_5();
	//eg2_6();
	//eg2_7();
	//eg2_8();
	//eg2_9();
	//eg2_10();
	//eg2_11();
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	////test_5();
	//eg6_1();
	//eg6_2();
	//eg6_5();
	//eg6_7_1();
	//eg6_7_2;
	//eg6_7_3();
	//eg6_8();
	//eg6_9();
	//eg6_10();
	//eg6_11();
	//Clink a;
	//a.cstudent();
}