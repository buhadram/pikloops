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

#include "pikloops.h"

#include <kmenubar.h>
#include <kapp.h>
#include <kstdaction.h>
#include <kaction.h>
#include <kiconloader.h>
#include <ktoolbar.h>

#include <qlabel.h>
#include <mainwidgetpl.h>

#include <kmainwindow.h>
#include <klocale.h>

PiKLoops::PiKLoops()
        : KMainWindow( 0, "PikLoops" )
{


    // set the shell's ui resource file
    //setXMLFile("pikloopsui.rc");

    clientarea = new MainWidgetPL(this);

    setCentralWidget(clientarea);

    KStdAction::quit(kapp, SLOT(closeAllWindows()), actionCollection());
    KStdAction::copy(this, SLOT(slotCopy()), actionCollection());

    new KAction (i18n("Ca&lculate"), QIconSet(BarIcon("kcalc")),CTRL+Key_L, this,
                      SLOT(slotCalculate()), actionCollection(), "calculate");

    createGUI("pikloopsui.rc");
    setAutoSaveSettings() ;

}

PiKLoops::~PiKLoops()
{
}



/*!
    \fn PiKLoops::slotCopy()
 */
void PiKLoops::slotCopy()
{
    clientarea->copyCode();
}


/*!
    \fn PiKLoops::slotCalculate()
 */
void PiKLoops::slotCalculate()
{
    clientarea->refreshWidget();
}

#include "pikloops.moc"
