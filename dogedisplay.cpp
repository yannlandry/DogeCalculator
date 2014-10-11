#include "dogedisplay.h"

DogeDisplay::DogeDisplay(QWidget *parent) :
	QLineEdit(parent)
{
	setReadOnly(true);
	setAlignment(Qt::AlignRight);

	QFont displayFont("Purisa", 26);
	setFont(displayFont);
}

void DogeDisplay::updateText(QString update)
{
	setText(update.isEmpty() ? "0" : update);
}
