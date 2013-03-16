#!/bin/sh
#
# script to build lm32 GCC toolchain
#
TOPDIR=`pwd`

mkdir $TOPDIR/tarballs
cd $TOPDIR/tarballs

RTEMS_VERSION=4.11
RTEMS_PREFIX=/opt/rtems-$RTEMS_VERSION
RTEMS_SOURCES_URL=http://www.rtems.org/ftp/pub/rtems/SOURCES/$RTEMS_VERSION
WGET=curl
BINUTILS_VERSION=2.21
GCC_CORE_VERSION=4.5.3
NEWLIB_VERSION=1.19.0
GDB_VERSION=7.4.1
GMP_VERSION=4.3.2
MPC_VERSION=0.8.1
MPFR_VERSION=2.4.2

BINUTILS=binutils-$BINUTILS_VERSION.tar.bz2
GCC_CORE=gcc-core-$GCC_CORE_VERSION.tar.bz2
NEWLIB=newlib-$NEWLIB_VERSION.tar.gz
GDB=gdb-$GDB_VERSION.tar.bz2
GMP=gmp-$GMP_VERSION.tar.bz2
MPC=mpc-$MPC_VERSION.tar.gz
MPFR=mpfr-$MPFR_VERSION.tar.bz2
BINUTILS_PATCH=binutils-$BINUTILS_VERSION-rtems$RTEMS_VERSION-20110107.diff
GCC_CORE_PATCH=gcc-core-$GCC_CORE_VERSION-rtems$RTEMS_VERSION-20110905.diff
NEWLIB_PATCH=newlib-$NEWLIB_VERSION-rtems$RTEMS_VERSION-20111006.diff
GDB_PATCH=gdb-$GDB_VERSION-rtems$RTEMS_VERSION-20120706.diff

echo "Download $BINUTILS"
$WGET $RTEMS_SOURCES_URL/$BINUTILS -o $BINUTILS
echo "Download $NEWLIB"
$WGET $RTEMS_SOURCES_URL/$NEWLIB -o $NEWLIB 
echo "Download $GCC_CORE"
$WGET $RTEMS_SOURCES_URL/$GCC_CORE -o $GCC_CORE 
echo "Download $GDB"
$WGET $RTEMS_SOURCES_URL/$GDB -o $GDB 
echo "Download $MPC"
$WGET $RTEMS_SOURCES_URL/$MPC -o $MPC 
echo "Download $MPFR"
$WGET $RTEMS_SOURCES_URL/$MPFR -o $MPFR 
echo "Download $GMP"
$WGET $RTEMS_SOURCES_URL/$GMP -o $GMP 
echo "Download $BINUTILS_PATCH"
$WGET $RTEMS_SOURCES_URL/$BINUTILS_PATCH -o $BINUTILS_PATCH
echo "Download $GCC_CORE_PATCH"
$WGET $RTEMS_SOURCES_URL/$GCC_CORE_PATCH -o $GCC_CORE_PATCH
echo "Download $NEWLIB_PATCH"
$WGET $RTEMS_SOURCES_URL/$NEWLIB_PATCH -o $NEWLIB_PATCH

echo "Extract archives to $TOPDIR/src folder"
mkdir $TOPDIR/src
cd $TOPDIR/src
tar xzvf ../tarballs/$NEWLIB
tar xjvf ../tarballs/$GDB
tar xjvf ../tarballs/$BINUTILS
tar xzvf ../tarballs/$MPC
tar xjvf ../tarballs/$MPFR
tar xjvf ../tarballs/$GMP
tar xjvf ../tarballs/$GCC_CORE
echo "Apply patches"
cd $TOPDIR/src/binutils-$BINUTILS_VERSION
cat $TOPDIR/src/$BINUTILS_PATCH | patch -p1 --dry-run
cat $TOPDIR/src/$BINUTILS_PATCH | patch -p1

cd $TOPDIR/src/gcc-$GCC_CORE_VERSION
cat $TOPDIR/src/$GCC_CORE_PATCH | patch -p1 --dry-run
cat $TOPDIR/src/$GCC_CORE_PATCH | patch -p1

cd $TOPDIR/src/newlib-$NEWLIB_VERSION
cat $TOPDIR/src/$NEWLIB_PATCH | patch -p1 --dry-run
cat $TOPDIR/src/$NEWLIB_PATCH | patch -p1

cd $TOPDIR/src/gcc-4.5.3
echo "Clean and link"
rm -rf bfd binutils gas gold gprof opcodes newlib libgloss gdb mpc mpfr gmp
ln -s ../binutils-2.21/bfd bfd
ln -s ../binutils-2.21/binutils binutils
ln -s ../binutils-2.21/gas gas
ln -s ../binutils-2.21/gold gold
ln -s ../binutils-2.21/gprof gprof
ln -s ../binutils-2.21/opcodes opcodes
ln -s ../binutils-2.21/ld ld

ln -s ../newlib-1.19.0/newlib newlib
ln -s ../newlib-1.19.0/libgloss libgloss

ln -s ../gdb-7.4.1 gdb
ln -s ../mpc-0.8.1 mpc
ln -s ../mpfr-2.4.2 mpfr
ln -s ../gmp-4.3.2 gmp

echo "Build"
mkdir $TOPDIR/build
cd $TOPDIR/build

../src/gcc-4.5.3/configure  --prefix=/opt/rtems-4.11 --with-gnu-as --with-newlib --enable-threads --enable-languages=c --target=lm32-rtems4.11 --disable-libssp --disable-libgcc
echo "make"
make
echo "make install"
make install
