#include "dogedigitalbutton.h"

DogeDigitalButton::DogeDigitalButton(QChar buttonLabel, DogeEngine* newEngine) :
	DogeButton(buttonLabel)
{
	engine = newEngine;
	connect(this, SIGNAL(clicked()), this, SLOT(onClick()));

	QString shortcut("Ctrl+");
	shortcut.append(buttonLabel);
	setShortcut(QKeySequence(buttonLabel));
}

void DogeDigitalButton::onClick()
{
	engine->digit(text().at(0));
}

DogeEngine* DogeDigitalButton::getEngine()
{
	return engine;
}

void DogeDigitalButton::setEngine(DogeEngine* newEngine)
{
	engine = newEngine;
}
