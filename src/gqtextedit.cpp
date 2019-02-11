/**
 *                         gqtextedit.cpp  -  description
 *                            -------------------
 *   begin                : dim sep 19 2004
 *   copyright            : (C) 2004 by Javier Fernando Vargas G
 *   email                : fernandovargas@cable.net.co
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

#include "gqtextedit.h"
#include "pikloops-drag.xpm"

#include <qdragobject.h>
#include <qpixmap.h>

#include <iostream>
using namespace std ;


GQTextEdit::GQTextEdit(QWidget *parent, const char *name ) : QTextEdit(parent,name)
{
}

GQTextEdit::~GQTextEdit()
{
}

/** No descriptions */
void GQTextEdit::contentsMousePressEvent(QMouseEvent *)
{
  QDragObject *d = new QTextDrag(text(),this) ;
  d->setPixmap(QPixmap(pikloops_drag_xpm ), QPoint(-10,-10) ) ;
  d->dragCopy() ;
}
