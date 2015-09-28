#ifndef ABOUT_QDEBUG_H
#define ABOUT_QDEBUG_H

#include <QtWidgets/QMainWindow>
#include "ui_about_qdebug.h"

class about_qdebug : public QMainWindow
{
	Q_OBJECT

public:
	about_qdebug(QWidget *parent = 0);
	~about_qdebug();

private:
	Ui::about_qdebugClass ui;
};

#endif // ABOUT_QDEBUG_H
