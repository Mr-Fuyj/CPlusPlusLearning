#include "about_qdebug.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	about_qdebug w;
	w.show();
	return a.exec();
}
