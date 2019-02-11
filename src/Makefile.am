####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = pikloops

## INCLUDES were found outside kdevelop specific part

pikloops_SOURCES = gqtextedit.cpp pikloops.cpp pikdelay.cpp mainwidgetpl.cpp main.cpp 
pikloops_LDADD   =  $(LIB_KFILE) $(LIB_KDEUI) $(LIB_KDECORE) $(LIB_QT) $(LIBSOCKET)


EXTRA_DIST = pikloops.desktop main.cpp mainwidgetpl.cpp mainwidgetpl.h pikdelay.cpp pikdelay.h pikloops.cpp pikloops.h pikloopsui.rc gqtextedit.h gqtextedit.cpp hi16-app-pikloops.png hi32-app-pikloops.png pikloops22.xpm pikloops-drag.xpm 

install-data-local:
	$(mkinstalldirs) $(kde_appsdir)/Applications/
	$(INSTALL_DATA) $(srcdir)/pikloops.desktop $(kde_appsdir)/Applications/pikloops.desktop
	$(mkinstalldirs) $(kde_datadir)/pikloops/
	$(INSTALL_DATA) $(srcdir)/pikloopsui.rc $(kde_datadir)/pikloops/pikloopsui.rc
	$(mkinstalldirs) $(kde_icondir)/crystalsvg/16x16/apps/
	$(INSTALL_DATA) $(srcdir)/hi16-app-pikloops.png $(kde_icondir)/crystalsvg/16x16/apps/pikloops.png
	$(mkinstalldirs) $(kde_icondir)/crystalsvg/32x32/apps/
	$(INSTALL_DATA) $(srcdir)/hi32-app-pikloops.png $(kde_icondir)/crystalsvg/32x32/apps/pikloops.png

uninstall-local:
	-rm -f $(kde_appsdir)/Applications/pikloops.desktop
	-rm -f $(kde_datadir)/pikloops/pikloopsui.rc
	-rm -f $(kde_icondir)/crystalsvg/16x16/apps/pikloops.png
	-rm -f $(kde_icondir)/crystalsvg/32x32/apps/pikloops.png

####### kdevelop will overwrite this part!!! (end)############
# These paths are KDE specific. Use them:
# kde_appsdir         Where your application's menu entry (.desktop) should go to.
# kde_icondir         Where your icon should go to - better use KDE_ICON.
# kde_sounddir        Where your sounds should go to.
# kde_htmldir         Where your docs should go to. (contains lang subdirs)
# kde_datadir         Where you install application data. (Use a subdir)
# kde_locale          Where translation files should go to. (contains lang subdirs)
# kde_cgidir          Where cgi-bin executables should go to.
# kde_confdir         Where config files should go to (system-wide ones with default values).
# kde_mimedir         Where mimetypes .desktop files should go to.
# kde_servicesdir     Where services .desktop files should go to.
# kde_servicetypesdir Where servicetypes .desktop files should go to.
# kde_toolbardir      Where general toolbar icons should go to (deprecated, use KDE_ICON).
# kde_wallpaperdir    Where general wallpapers should go to.
# kde_templatesdir    Where templates for the "New" menu (Konqueror/KDesktop) should go to.
# kde_bindir          Where executables should go to. Use bin_PROGRAMS or bin_SCRIPTS.
# kde_libdir          Where shared libraries should go to. Use lib_LTLIBRARIES.
# kde_moduledir       Where modules (e.g. parts) should go to. Use kde_module_LTLIBRARIES.
# kde_styledir        Where Qt/KDE widget styles should go to (new in KDE 3).
# kde_designerdir     Where Qt Designer plugins should go to (new in KDE 3).

# set the include path for X, qt and KDE
INCLUDES= $(all_includes)

METASOURCES = AUTO

# the library search path. 
pikloops_LDFLAGS = $(all_libraries) $(KDE_RPATH)

rcdir = $(kde_datadir)/pikloops
rc_DATA = pikloopsui.rc

messages: rc.cpp
	LIST=`find . -name \*.h -o -name \*.hh -o -name \*.H -o -name \*.hxx -o -name \*.hpp -o -name \*.cpp -o -name \*.cc -o -name \*.cxx -o -name \*.ecpp -o -name \*.C`; \
	if test -n "$$LIST"; then \
	 $(XGETTEXT) $$LIST -o $(podir)/pikloops.pot; \
	fi

