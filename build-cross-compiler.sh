#!/bin/bash

echo Is is recommended to have have the newest dev version of these files: GNU GMP, GNU MPFR, ISL, ClooG, GNU MPC, GNU Texinfo. It will still be possible to compile without these packages.
read -p "Do you want to continue?" -n 1 -r
if [[ ! $REPLY =~ ^[Yy]$ ]]
then
	exit 1
fi

export PREFIX="$HOME/dev/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

echo The compiler will be installed in $PREFIX.
read -p "Do you want to install to this directory?" -n 1 -r
if [[ ! $REPLY =~ ^[Yy]$ ]]
then
	exit 1
fi

mkdir -p $HOME/dev/cross
mkdir -p $HOME/dev/src
cd $HOME/dev/src

wget "ftp://ftp.gnu.org/gnu/binutils/binutils-2.25.1.tar.bz2"
wget "ftp://ftp.gnu.org/gnu/gcc/gcc-5.2.0/gcc-5.2.0.tar.bz2"

tar -xvf binutils-2.25.1.tar.bz2
tar -xvf gcc-5.2.0.tar.bz2

mkdir -p build-binutils
cd build-binutils
../binutils-2.25.1/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

cd $HOME/dev/src
which -- $TARGET-as || echo $TARGET-as is not in the PATH
mkdir build-gcc
cd build-gcc
../gcc-5.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
