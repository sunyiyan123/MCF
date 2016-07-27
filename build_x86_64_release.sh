#!/bin/sh

set -e

prefix="$(pwd)/.release/mingw64"
mkdir -p "$prefix"

builddir="$(pwd)/.build_x86_64_release"
mkdir -p "$builddir"

build=x86_64-w64-mingw32

(cd MCFCRT &&
  mkdir -p m4
  autoreconf -i)

(cd "$builddir" &&
  CPPFLAGS='-DNDEBUG'	\
  CFLAGS='-O3 -ffunction-sections -fdata-sections'	\
  LDFLAGS='-Wl,-s,--gc-sections'	\
  ../MCFCRT/configure --build="$build" --host="$build" --prefix="$prefix" &&
  make -j7 &&
  make install)
