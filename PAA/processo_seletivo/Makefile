#!/bin/bash
main: 
	gcc main.c -o app; \
	#for file in ./testdata/*.in;  do cat $$file |(./app > "$${file%.*}"'_my_resout'.out) | (git diff "$${file%.*}".out "$${file%.*}"'_my_resout'.out); done;	
	cat ./testdata/4.in |time  ./app>debug4.txt
	cat ./testdata/5.in |time  ./app>debug5.txt	