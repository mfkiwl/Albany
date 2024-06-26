#!/bin/bash

if [ "$1" == "" ]; then
  echo "Argument 1 (case num) not provided!" 
  exit 0
fi

build=$1

if [ $build = "regular" ]; then
  name="albany"
fi
if [ $build = "no-epetra" ]; then
  name="albanyT"
fi
if [ $build = "fpe" ]; then
  name="albanyFPE"
fi
if [ $build = "openmp" ]; then
  name="albanyOpenmp"
fi
if [ $build = "cali" ]; then
  name="cismAlbany"
fi

sed -e "/CDASH-ALBANY-FILE.TXT/r /nightlyCDash/cdash-$name-frag.txt" -e "/CDASH-ALBANY-FILE.TXT/d" "/nightlyCDash/ctest_nightly_"$name"_tmp.cmake" >& /nightlyCDash/ctest_nightly_$name.cmake
