#!/bin/bash
# 
# uninstall_windows.bat: Script to uninstall libcutils
# 
# Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# Date: 22/09/2023

if test -f /usr/lib/libcutils.dll; then
  printf "#########################\n"
  printf "# Uninstalling libcutils #\n"
  printf "#########################\n"

  # Creating the documentation directory
  rm -rv /usr/share/doc/libcutils

  # Install the binary of software and yout autocomplete script
  rm -rvf /usr/lib/libcutils.dll

  # Installing the documentation
  cp -rvf /usr/share/man/man1/libcutils.1.gz
  cp -rvf /usr/share/doc/libcutils

  printf "\nlibcutils was uninstalled successfuly!\n"
elif
  # Checking if the terminal suport colored text
  if [[ test -n $(tput colors) && test $(tput colors) -ge 8]]; then
    printf "\033[1;31mE:\033[m libcutils is not installed!\n"
  elif
    printf "E: libcutils is not installed!\n"
  fi

  printf "Nothing to do\n"

  exit 1
fi

