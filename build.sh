#! /bin/bash

g++  main.cpp

if [ $? != 0 ]
then
  echo "NG!";
  exit;
fi

./a.out
