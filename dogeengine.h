#ifndef DOGEENGINE_H
#define DOGEENGINE_H

#include "dogedisplay.h"

class DogeEngine
{
private:
	DogeDisplay* display;

	double accumulator;
	QString currentInput;
	bool hasPoint;
	enum operators { PLUS, MINUS, TIMES, DIVIDE } currentOperator;

	void updateDisplay(QString send = "");
	void updateDisplay(float);
	void clearDisplay();
	void clearCurrentInput();
	void pushOperation();
	void reset();

public:
	DogeEngine(DogeDisplay*);

	DogeDisplay* getDisplay();
	void setDisplay(DogeDisplay*);

	void digit(QChar);
	void c();
	void ce();
	void backspace();
	void equals();
	void plus();
	void minus();
	void times();
	void divide();
};

#endif // DOGEENGINE_H
