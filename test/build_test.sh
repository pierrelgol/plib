#!/bin/bash
make 
cd ./build/
cc -Wall -Wextra -Werror test.c libplibtest.a libplib.a 
./a.out
rm -f a.out
