#include "dogeengine.h"
#include <QMessageBox>
#include <QWidget>
#include <QTextStream>

DogeEngine::DogeEngine(DogeDisplay* newDisplay) :
	display(newDisplay)
{
	c();
	updateDisplay();
}

DogeDisplay* DogeEngine::getDisplay()
{
	return display;
}

void DogeEngine::setDisplay(DogeDisplay* newDisplay)
{
	display = newDisplay;
}

void DogeEngine::updateDisplay(QString send)
{
	display->updateText(send.isEmpty() ? currentInput : send);
}

void DogeEngine::updateDisplay(float send)
{
	QString strSend;
	QTextStream converter(&strSend);
	converter << accumulator;
	updateDisplay(strSend);
}

void DogeEngine::clearDisplay()
{
	display->updateText("");
}

void DogeEngine::clearCurrentInput()
{
	currentInput.clear();
	hasPoint = false;
}

void DogeEngine::pushOperation()
{
	if(!currentInput.isEmpty()) {
		QTextStream converter(&currentInput);
		double currentNumericInput;
		converter >> currentNumericInput;

		if(currentOperator == PLUS)
			accumulator+= currentNumericInput;
		else if(currentOperator == MINUS)
			accumulator-= currentNumericInput;
		else if(currentOperator == TIMES)
			accumulator*= currentNumericInput;
		else if(currentNumericInput != 0) // Avoid division by zero
			accumulator/= currentNumericInput;
	}

	clearCurrentInput();
	updateDisplay(accumulator);
}

void DogeEngine::reset()
{
	accumulator = 0;
	currentInput = "";
	hasPoint = false;
	currentOperator = PLUS;
}

void DogeEngine::digit(QChar command)
{
	if(currentInput.length() >= 16) return;
	else if(command == '0' && currentInput.isEmpty()) return;
	else if(command == '.') {
		if(hasPoint) return;
		else hasPoint = true;
		if(currentInput.length() == 0)
			currentInput.append('0');
	}

	currentInput+= command;
	updateDisplay();
}

void DogeEngine::c() // c = reset + clear display
{
	reset();
	clearDisplay();
}

void DogeEngine::ce()
{
	clearCurrentInput();
	clearDisplay();
}

void DogeEngine::backspace()
{
	if(!currentInput.isEmpty()) {
		if(currentInput.at(currentInput.length() - 1) == '.')
			hasPoint = false;
		currentInput.remove(currentInput.length() - 1, 1);
		updateDisplay();
	}
	if(currentInput == "0")
		clearCurrentInput();
}

void DogeEngine::equals()
{
	pushOperation();
	reset();
}

void DogeEngine::plus()
{
	pushOperation();
	currentOperator = PLUS;
}

void DogeEngine::minus()
{
	pushOperation();
	currentOperator = MINUS;
}

void DogeEngine::times()
{
	pushOperation();
	currentOperator = TIMES;
}

void DogeEngine::divide()
{
	pushOperation();
	currentOperator = DIVIDE;
}
