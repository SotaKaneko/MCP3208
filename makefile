default_header='/usr/local/include'

main.o : main.c ReadWrite_MCP3208.c define.h
	gcc -I $(default_header) -I . -lwiringPi -lm -o main.o main.c
