Name:		pikloops
Version:	0.2.5
Release:	1%{?dist}
Summary:	Code generator for PIC delays
Summary(fr):	Générateur de code de temporisation pour PIC

Group:		Development/Tools
License:	GPLv2+
Url:		http://pikloops.sf.net/
Source:		http://downloads.sf.net/%{name}/%{name}-%{version}.tar.bz2
BuildRoot: 	%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:	desktop-file-utils, gettext, kdelibs-devel

%description
PiKLoop generate for you code to create delays for Microchip PIC
microcontrollers. It is an useful companion for Pikdev or Piklab IDE.

%description -l fr
PiKLoop génère pour vous du code pour créer des temporisations pour les
microcontrôleurs PIC de Microchip. C'est un compagnon utile aux environnements
de développement Pikdev ou Piklab.

%prep
%setup -q

%build

%configure --disable-rpath
%{__make} %{?_smp_mflags}


%install
%{__rm} -rf %{buildroot}
%{__make} DESTDIR=%{buildroot} install
%{__rm} -f %{buildroot}%{_datadir}/applnk/Applications/%{name}.desktop

desktop-file-install --vendor=fedora \
  --remove-category "Education" \
  --dir %{buildroot}%{_datadir}/applications \
  --delete-original \
  src/%{name}.desktop

# Fix absolute symlink
%{__rm} -f %{buildroot}%{_docdir}/HTML/*/%{name}/common
BKP_PWD=`pwd`
cd %{buildroot}%{_docdir}/HTML/en/%{name}/
ln -s ../common .
for lang_dir in fr
do
  cd %{buildroot}%{_docdir}/HTML/$lang_dir/%{name}/
  ln -s ../docs/common common
done
cd $BKP_PWD

%find_lang %{name}

%clean
%{__rm} -rf %{buildroot}

%post
touch --no-create %{_datadir}/icons/crystalsvg || :
if [ -x %{_bindir}/gtk-update-icon-cache ]
then
  %{_bindir}/gtk-update-icon-cache --quiet %{_datadir}/icons/hicolor || :
fi

%postun
touch --no-create %{_datadir}/icons/crystalsvg || :
if [ -x %{_bindir}/gtk-update-icon-cache ]
then
  %{_bindir}/gtk-update-icon-cache --quiet %{_datadir}/icons/hicolor || :
fi

%files -f %{name}.lang
%defattr(-, root, root)
%doc AUTHORS COPYING
%{_bindir}/*
%{_datadir}/applications/fedora-%{name}.desktop
%{_datadir}/apps/%{name}/
%{_datadir}/doc/HTML/*/%{name}/
%{_datadir}/icons/crystalsvg/*/apps/%{name}.png

%changelog
* Wed Oct 17 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.5-1
  - New upstream version

* Wed Sep 28 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.4-1
  - New upstream version

* Sun Sep 02 2007 Chitlesh Goorah <chitlesh[AT]fedoraproject[DOT]org> - 0.2.3-3
  - Fix desktop file

* Tue Aug 21 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.3-2
  - Licence tag clarification

* Thu Jul 26 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.3-1
  - New upstream version

* Thu Jul 12 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.2-5
  - Fix potential EVR problem

* Thu Jul 12 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.2-4
  - Test if gtk-update-icon-cache exists before running it

* Wed Jul 11 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.2-3
  - Add BR gettext

* Sat Jul  7 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.2-2
  - New upstream: new url and source url

* Wed Apr 25 2007  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.2-1
  - New upstream version
  - SOURCE1 no more needed

* Fri Sep 29 2006  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.1-6
  - Remove useless update-desktop-database

* Fri Sep 29 2006  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.1-5
  - Update %%{SOURCE1} to add Application category

* Fri Sep 29 2006  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.1-4
  - Update %%{SOURCE1} which don't contain "OnlyShowIn=KDE;" any more

* Thu Sep 28 2006  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.1-3
  - Add dist tag

* Thu Sep 28 2006  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.1-2
  - Don't make install-strip

* Wed Sep 27 2006  Alain Portal <aportal[AT]univ-montp2[DOT]fr> 0.2.1-1
  - Initial Fedora package
