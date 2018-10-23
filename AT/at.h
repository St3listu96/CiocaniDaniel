#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 100
#define STR_SIZE 30
#define true 1
#define false 0

typedef int bool;

typedef enum{
	STATUS_OK,
	STATUS_ERROR
}STATE_MACHINE;

typedef struct{
	char data[MAX_LINE][STR_SIZE];
	bool ok;
	int line;
}AT;

extern AT atdata;
STATE_MACHINE at_parse(char ch);
