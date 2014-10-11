#ifndef DOGEMAINWINDOW_H
#define DOGEMAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include "dogeengine.h"
#include "dogedisplay.h"

class DogeMainWindow : public QWidget
{
	Q_OBJECT

private:
	DogeEngine* engine;
	DogeDisplay* display;

	QMenuBar* menuBar;
	QMenu* actionsMenu;
	QMenu* watMenu;

	QWidget* controlZone;

	QDialog* aboutDialog;

	void initMenu();
	void initControlZone();
	void initAboutDialog();

public:
	explicit DogeMainWindow(QWidget *parent = 0);

public slots:
	void equalsClick();
	void plusClick();
	void minusClick();
	void timesClick();
	void divideClick();
	void cClick();
	void ceClick();
	void backspaceClick();
};

#endif // DOGEMAINWINDOW_H
