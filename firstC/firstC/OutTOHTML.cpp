
#include "OutTOHTML.h"
#include<fstream>
template<class TemplateClass>
OutTOHTML<TemplateClass>::OutTOHTML(TemplateClass*p, char*file) :MyOut(p, file)
{
}

template<class TemplateClass>
OutTOHTML<TemplateClass>::~OutTOHTML()
{
}
template<class TemplateClass>
void OutTOHTML<TemplateClass>::out_put(TemplateClass*p, char*file){
	ofstream out;
	TemplateClass*ptemp = m_pHeader;
	out.open("排序表.html", ios::out);
	if (!out.is_open()) return;
	out << "<html>" << endl << "<head>" << endl;
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
