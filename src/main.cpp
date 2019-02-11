/**
 *   Copyright (C) 2004 - JAVIER FERNANDO VARGAS G <fernandovargas@cable.net.co>
 *                 2007 - Alain Portal <alain DOT portal AT univ-montp2 DOT fr>
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
#include "../config.h"
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocale.h>


static const char description[] = I18N_NOOP("Pic Delay Calculator");
static const char version[] = VERSION;
static KCmdLineOptions options[] =
{
//    { "+[URL]", I18N_NOOP( "Document to open." ), 0 },
    KCmdLineLastOption
};

int main(int argc, char **argv)
{
    KAboutData about("pikloops",
		     I18N_NOOP("PikLoops"),
		     version,
		     description,
                     KAboutData::License_GPL,
		     "(C) 2007 Alain Portal\n(C) 2004 JAVIER FERNANDO VARGAS G",
		     0,
		     "http://pikloops.sf.net",
		     "dionysos-sf@users.sourceforge.net");
    about.addAuthor("Alain Portal",
		    I18N_NOOP("Author and maintainer"),
		    "alain.portal@univ-montp2.fr" );
    about.addAuthor("Javier Fernando Vargas G",
		    I18N_NOOP("Original author of PikLoops"),
		    "fernandovargas@cable.net.co" );
    about.addCredit("William J. Boucher",
		    i18n("Author of the original PicLoops for Windows.\nHis Calculations Formulas made it possible."),
		    "boucher@mnsi.net",
		    "http://www.mnsi.net/~boucher/emporium.htm");
	
    KCmdLineArgs::init(argc, argv, &about);
    KCmdLineArgs::addCmdLineOptions( options );
    KApplication app;
	//app.setIcon(QIconSet(DesktopIcon("kcmprocessor")));
	
    PiKLoops *mainWin = 0;

    if (app.isRestored()) {
        RESTORE(PiKLoops);
    }
    else {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();

        /// @todo do something with the command line args here

        mainWin = new PiKLoops();

        app.setMainWidget( mainWin );

        mainWin->show();

        args->clear();
    }

    // mainWin has WDestructiveClose flag by default, so it will delete itself.
    return app.exec();
}

