#include "dogebutton.h"

DogeButton::DogeButton(QString buttonText) :
	QPushButton(0)
{
	setText(buttonText);

	QFont displayFont("Purisa", 26);
	setFont(displayFont);
}
