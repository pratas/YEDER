#!/bin/bash
#
GET_FALCON=1;
GET_GULL=1;
GET_GOOSE=1;
GET_KESTREL=1;
GET_BOWTIE=1;
#
#==============================================================================
# GET FALCON
#
if [[ "$GET_FALCON" -eq "1" ]]; then
  rm -fr falcon FALCON FALCON-* *.pl
  git clone https://github.com/pratas/falcon.git
  cd falcon/src/
  cmake .
  make
  cp FALCON ../../../bins/
  cp FALCON-FILTER ../../../bins/
  cp FALCON-EYE ../../../bins/
  cd ../../
fi
#==============================================================================
# GET GULL
#
if [[ "$GET_GULL" -eq "1" ]]; then
  rm -fr GULL/ GULL-map GULL-visual
  git clone https://github.com/pratas/GULL.git
  cd GULL/src/
  cmake .
  make
  cp GULL-map ../../../bins/
  cp GULL-visual ../../../bins/
  cd ../../
fi
#==============================================================================
# GET GOOSE
#
if [[ "$GET_GOOSE" -eq "1" ]]; then
  rm -fr goose/ goose-*
  git clone https://github.com/pratas/goose.git
  cd goose/src/
  make
  cp goose-* ../../../bins/
  cd ../../
fi
#==============================================================================
# GET KESTREL
#
if [[ "$GET_KESTREL" -eq "1" ]]; then
  rm -rf kestrel/ KESTREL
  git clone https://github.com/pratas/kestrel.git
  cd kestrel/src/
  cmake .
  make
  cp KESTREL ../../../bins/
  cd ../../
fi
#==============================================================================
# GET BOWTIE
#
if [[ "$GET_BOWTIE" -eq "1" ]]; then
  sudo apt-get install libtbb-dev
  rm -fr bowtie/
  git clone https://github.com/BenLangmead/bowtie.git
  cd bowtie/
  make
  cp bowtie ../../bins/
  cp bowtie-build ../../bins/
  cd ../
fi
#==============================================================================
