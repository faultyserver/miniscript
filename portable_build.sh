#!/bin/bash
CC=$1

TARGET=$2

LINUX_FLAGS=-lfl
OSX_FLAGS=-ll

echo ">> Trying OS X build ( -ll )";
echo $CC -o $TARGET parser.tab.cc lex.yy.c $OSX_FLAGS
if $CC -o $TARGET parser.tab.cc lex.yy.c $OSX_FLAGS > /dev/null 2>&1; then
  echo ">> OS X build succeeded"
else
  echo ">> OS X build failed"
  echo ">> Trying Linux build ( -lfl )";
  echo $CC -o $TARGET parser.tab.cc lex.yy.c $LINUX_FLAGS
  if $CC -o $TARGET parser.tab.cc lex.yy.c $LINUX_FLAGS > /dev/null 2>&1; then
    echo ">> Linux build succeeded"
  else
    echo ">> Linux build failed"
  fi
fi
