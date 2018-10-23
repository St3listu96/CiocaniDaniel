#include <stdio.h>
#include <stdlib.h>
#include "at.h"
#define CR 13
#define LF 10

STATE_MACHINE at_parse(char ch){
	static int state = 0;
	switch (state){
		case 0:
			if (ch == 0x0D){
				state = 1;
			}
			else{
				printf("Missing CR\n");
				exit(1);
			}
			break;

		case 1:
			if (ch == LF){
				state = 2;
			}
			else{
				printf("Missing CR\n");
				exit(1);
			}
			break;
		case 2:
			if (ch == 'O'){
				state = 3;
			}
			else if (ch == 'E'){
				state = 7;
			}
			else if (ch == '+'){
				state = 14;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 3:
			if (ch == 'K'){
				state = 4;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 4:
			if (ch == CR){
				state = 5;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 5:
			if (ch == LF){
				return STATUS_OK;
			}
			break;
		case 7:
			if (ch == 'R'){
				state = 8;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 8:
			if (ch == 'R'){
				state = 9;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 9:
			if (ch == 'O'){
				state = 10;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 10:
			if (ch == 'R'){
				state = 11;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 11:
			if (ch == CR){
				state = 12;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 12:
			if (ch == LF){
				return STATUS_ERROR;
			}
			break;
		case 14:
			if (ch != CR){
				state = 14;
			}
			else if(ch == CR){
				state = 15;
			}
			break;
		case 15:
			if (ch == LF){
				state = 16;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 16:
			if (ch == CR){
				state = 17;
			}
			else if (ch == '+'){
				state = 14;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 17:
			if (ch == LF){
				state = 18;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 18:
			if (ch == 'O'){
				state = 19;
			}
			else if (ch == 'E'){
				state = 23;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 19:
			if (ch == 'K'){
				state = 4;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
		case 23:
			if (ch == 'R'){
				state = 8;
			}
			else{
				printf("Eroare\n");
				exit(1);
			}
			break;
	}
}