#!/bin/sh
if [[ $(whereis svn2cl) == "svn2cl:" ]]
then
  echo "SCRIPT WARNING!"
  echo "svn2cl isn't installed on your machine, so, you can't use this script."
  echo "If you want to use this script, install svn2cl."
  echo "You can find it at: http://ch.tudelft.nl/~arthur/svn2cl/"
  echo "but a package probably exist for your distribution."
  echo "ChangeLog isn't changed."
  exit 1
fi

svn2cl --authors=./authors.xml
