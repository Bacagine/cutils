#!/bin/bash
# 
# install_windowns.bat: Script to install libcutils
# 
# Written by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# Date: 23/09/2023

printf "\n#######################\n"
printf "# Installing libcutils #\n"
printf "#######################\n"

# Install the binary of software
cp -rvf ./lib/libcutils.dll /usr/lib

# Installing the documentation
cp -rvf ./man/cutils.1.gz /usr/share/man/man1
cp -rvf ./doc/* /usr/share/doc/libcutils
cp -rvf ./LICENSE.gz /usr/share/doc/libcutils
cp -rvf ./AUTHORS.gz /usr/share/doc/libcutils
cp -rvf ./NEWS.gz /usr/share/doc/libcutils
cp -rvf ./README.gz /usr/share/doc/libcutils

printf "libcutils was installed successfuly!"

