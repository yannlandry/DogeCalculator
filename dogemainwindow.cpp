#include "dogemainwindow.h"
#include "dogedigitalbutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>

#include <QLineEdit>

DogeMainWindow::DogeMainWindow(QWidget *parent) :
	QWidget(parent)
{
	display = new DogeDisplay;
	engine = new DogeEngine(display);

	setLayout(new QVBoxLayout);
	layout()->setContentsMargins(0, 0, 0, 0);

	setWindowIcon(QIcon(QPixmap("doge.png")));

	initAboutDialog();

	initMenu();
	layout()->addWidget(menuBar);

	initControlZone();
	layout()->addWidget(controlZone);
}

void DogeMainWindow::initMenu()
{
	menuBar = new QMenuBar;

	// Menu "actions"
	actionsMenu = new QMenu("&actions");
		QAction* clearAction = actionsMenu->addAction("&clear");
		connect(clearAction, SIGNAL(triggered()), this, SLOT(cClick()));
		QAction* quitAction = actionsMenu->addAction("&quit");
		quitAction->setShortcut(QKeySequence("Ctrl+Q"));
		connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
	menuBar->addMenu(actionsMenu);

	// Menu "wat"
	watMenu = new QMenu("&wat");
		QAction* aboutAction = watMenu->addAction("such &programmers");
		connect(aboutAction, SIGNAL(triggered()), aboutDialog, SLOT(exec()));
		QAction* aboutQtAction = watMenu->addAction("wow &qt");
		connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
	menuBar->addMenu(watMenu);
}

void DogeMainWindow::initControlZone()
{
	controlZone = new QWidget;

	QGridLayout* controlZoneLayout = new QGridLayout;
	controlZone->setLayout(controlZoneLayout);

	controlZoneLayout->addWidget(display, 0, 0, 1, 5);

	controlZoneLayout->addWidget(new DogeDigitalButton('7', engine), 1, 0);
	controlZoneLayout->addWidget(new DogeDigitalButton('8', engine), 1, 1);
	controlZoneLayout->addWidget(new DogeDigitalButton('9', engine), 1, 2);
	controlZoneLayout->addWidget(new DogeDigitalButton('4', engine), 2, 0);
	controlZoneLayout->addWidget(new DogeDigitalButton('5', engine), 2, 1);
	controlZoneLayout->addWidget(new DogeDigitalButton('6', engine), 2, 2);
	controlZoneLayout->addWidget(new DogeDigitalButton('1', engine), 3, 0);
	controlZoneLayout->addWidget(new DogeDigitalButton('2', engine), 3, 1);
	controlZoneLayout->addWidget(new DogeDigitalButton('3', engine), 3, 2);
	controlZoneLayout->addWidget(new DogeDigitalButton('0', engine), 4, 0, 1, 2);
	controlZoneLayout->addWidget(new DogeDigitalButton('.', engine), 4, 2);

	DogeButton* plusButton = new DogeButton("+");
	plusButton->setShortcut(QKeySequence(Qt::Key_Plus));
	plusButton->setToolTip("much");
	connect(plusButton, SIGNAL(clicked()), this, SLOT(plusClick()));
	controlZoneLayout->addWidget(plusButton, 4, 3);

	DogeButton* minusButton = new DogeButton("-");
	minusButton->setShortcut(QKeySequence("-"));
	minusButton->setToolTip("less");
	connect(minusButton, SIGNAL(clicked()), this, SLOT(minusClick()));
	controlZoneLayout->addWidget(minusButton, 3, 3);

	QChar special(215);
	DogeButton* timesButton = new DogeButton(special);
	timesButton->setShortcut(QKeySequence("*"));
	timesButton->setToolTip("many");
	connect(timesButton, SIGNAL(clicked()), this, SLOT(timesClick()));
	controlZoneLayout->addWidget(timesButton, 2, 3);

	special = 247;
	DogeButton* divideButton = new DogeButton(special);
	divideButton->setShortcut(QKeySequence("/"));
	divideButton->setToolTip("split");
	connect(divideButton, SIGNAL(clicked()), this, SLOT(divideClick()));
	controlZoneLayout->addWidget(divideButton, 1, 3);

	special = 8592;
	DogeButton* backspaceButton = new DogeButton(special);
	backspaceButton->setShortcut(QKeySequence(Qt::Key_Backspace));
	connect(backspaceButton, SIGNAL(clicked()), this, SLOT(backspaceClick()));
	controlZoneLayout->addWidget(backspaceButton, 1, 4);

	DogeButton* ceButton = new DogeButton("CE");
	ceButton->setShortcut(QKeySequence("Ctrl+E"));
	connect(ceButton, SIGNAL(clicked()), this, SLOT(ceClick()));
	controlZoneLayout->addWidget(ceButton, 2, 4);

	DogeButton* cButton = new DogeButton("C");
	cButton->setShortcut(QKeySequence("Ctrl+D"));
	connect(cButton, SIGNAL(clicked()), this, SLOT(cClick()));
	controlZoneLayout->addWidget(cButton, 3, 4);

	DogeButton* equalsButton = new DogeButton("=");
	equalsButton->setShortcut(QKeySequence(Qt::Key_Enter));
	connect(equalsButton, SIGNAL(clicked()), this, SLOT(equalsClick()));
	controlZoneLayout->addWidget(equalsButton, 4, 4);

	// Insert image into button
	QPixmap doge("doge.png");
	QLabel* dogeButton = new QLabel(equalsButton);
	dogeButton->setPixmap(doge.scaledToWidth(44));

	equalsButton->setLayout(new QHBoxLayout);
	equalsButton->layout()->setAlignment(Qt::AlignCenter);
	equalsButton->layout()->addWidget(dogeButton);
}

void DogeMainWindow::initAboutDialog()
{
	aboutDialog = new QDialog(this);
	aboutDialog->setLayout(new QVBoxLayout);
	aboutDialog->setWindowTitle("such programmers. wow.");

	QPixmap doge("doge.png");
	QLabel* dogeLabel = new QLabel(aboutDialog);
	dogeLabel->setPixmap(doge.scaledToWidth(200));

	QWidget* aboutDogeZone = new QWidget;
	aboutDogeZone->setLayout(new QHBoxLayout);
	aboutDogeZone->layout()->setAlignment(Qt::AlignCenter);
	aboutDogeZone->setContentsMargins(0, 0, 0, 0);
	aboutDogeZone->layout()->addWidget(dogeLabel);
	aboutDialog->layout()->addWidget(aboutDogeZone);

	QLabel* aboutText = new QLabel("DogeCalculator was ideated by Yann Landry<br />and Xavier Baudry. It was then developed by<br />Yann as a project to learn Qt.");
	aboutDialog->layout()->addWidget(aboutText);

	QWidget* aboutControlZone = new QWidget;
	aboutControlZone->setLayout(new QHBoxLayout);
	aboutControlZone->layout()->setAlignment(Qt::AlignRight);
	aboutControlZone->layout()->setContentsMargins(0, 0, 0, 0);

	QPushButton* aboutCloseButton = new QPushButton("OK");
	connect(aboutCloseButton, SIGNAL(clicked()), aboutDialog, SLOT(close()));

	aboutControlZone->layout()->addWidget(aboutCloseButton);
	aboutDialog->layout()->addWidget(aboutControlZone);
}

void DogeMainWindow::equalsClick()		{ engine->equals(); }
void DogeMainWindow::plusClick()		{ engine->plus(); }
void DogeMainWindow::minusClick()		{ engine->minus(); }
void DogeMainWindow::timesClick()		{ engine->times(); }
void DogeMainWindow::divideClick()		{ engine->divide(); }
void DogeMainWindow::cClick()			{ engine->c(); }
void DogeMainWindow::ceClick()			{ engine->ce(); }
void DogeMainWindow::backspaceClick()	{ engine->backspace(); }
