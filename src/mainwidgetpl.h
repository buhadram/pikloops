/**
 *   Copyright (C) 2004 by JAVIER FERNANDO VARGAS G
 *   fernandovargas@cable.net.co
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * */

#ifndef MAINWIDGETPL_H
#define MAINWIDGETPL_H

#include <qwidget.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qstring.h>
#include <qvbox.h>

#include "pikdelay.h"

class QComboBox;
class QLabel;
class KRestrictedLine;

/**
 * @author JAVIER FERNANDO VARGAS G & Alain GIBAUD
 *
 * */
class MainWidgetPL : public QVBox
{
Q_OBJECT
public:
    MainWidgetPL(QWidget *parent = 0, const char *name = 0);

    ~MainWidgetPL();
    void refreshWidget();

private:
    PiKDelay *loopValues;
    QComboBox *clock;
    QTextEdit *CodeText;
    QLabel *cycles;
    KRestrictedLine *delay;

    QString statusMessage;

protected:
    void setValues();

protected slots:
    void ClockChanged(const QString &);
    void TimeDelayChanged();

public slots:
    void copyCode();
};

#endif
