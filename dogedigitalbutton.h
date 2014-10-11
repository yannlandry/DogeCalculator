#ifndef DOGEDIGITALBUTTON_H
#define DOGEDIGITALBUTTON_H

#include "dogebutton.h"
#include "dogeengine.h"

class DogeDigitalButton : public DogeButton
{
	Q_OBJECT

private:
	DogeEngine* engine;

public:
	DogeDigitalButton(QChar, DogeEngine*);

	DogeEngine* getEngine();
	void setEngine(DogeEngine*);

signals:

public slots:
	void onClick();
};

#endif // DOGEDIGITALBUTTON_H
