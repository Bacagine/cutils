#!/bin/bash
# 
# install.sh: Script to install libcutils
# 
# Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# Date: 22/09/2023

# Checking if user is root
if [[ $EUID -ne 0 ]]; then
  # Checking if the terminal suport colored text
  if test -n $(tput colors) && test $(tput colors) -ge 8; then
    printf "\033[1;31mE:\033[m This script must be run as root\n"
  fi
  
  printf "E: This script must be run as root\n"

  exit 1
fi

printf "\n#######################\n"
printf "# Installing libcutils #\n"
printf "#######################\n"

gzip ./man/cutils.1
#gzip ./doc/*
gzip ./ChangeLog
gzip ./LICENSE
gzip ./AUTHORS
gzip ./NEWS
gzip ./README
gzip ./INSTALL

# Creating the documentation directory
mkdir -pv /usr/share/doc/libcutils

# Install the binary of software and yout autocomplete script
cp -rvf ./lib/libcutils.so /usr/lib

# Installing the documentation
cp -rvf ./man/cutils.1.gz /usr/share/man/man1
cp -rvf ./doc/* /usr/share/doc/libcutils
cp -rvf ./LICENSE.gz /usr/share/doc/libcutils
cp -rvf ./AUTHORS.gz /usr/share/doc/libcutils
cp -rvf ./NEWS.gz /usr/share/doc/libcutils
cp -rvf ./README.gz /usr/share/doc/libcutils

printf "libcutils was installed successfuly!"

