#ifndef DOGEDISPLAY_H
#define DOGEDISPLAY_H

#include <QLineEdit>

class DogeDisplay : public QLineEdit
{
	Q_OBJECT
public:
	explicit DogeDisplay(QWidget *parent = 0);
	void updateText(QString);

signals:

public slots:

};

#endif // DOGEDISPLAY_H
