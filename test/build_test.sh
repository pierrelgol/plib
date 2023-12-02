#!/bin/bash
make 
cd ./build/
cc -Wall -Wextra -Werror test.c libplib.a libplibtest.a
./a.out
rm -f a.out
