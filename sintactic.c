#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *caracter;
enum{COMMA,SEMICOLON,LPAR,RPAR,LBRACKET,RBRACKET,LACC,RACC,ADD,SUB,MUL,DIV,DOT,AND,OR,NOT,NOTEQ,ASSIGN,EQUAL,LESS,LESSEQ,GREATER,GREATEREQ,CT_INT,CT_REAL,CT_STRING,CT_CHAR,END,BREAK,CHAR,DOUBLE,ELSE,FOR,IF,INT,RETURN,STRUCT,VOID,WHILE,ID};

typedef struct _Token{
	int code;
	union{
		char *text;
		long int i;
		double r;
	};
	
	struct _Token *next;
}Token;

Token *tokens=NULL;
Token *lastToken=NULL;
Token *crtTk=NULL;
Token *consumedTk=NULL;



int consume(int cod){
	if(crtTk->code == cod){
		consumedTk = crtTk;
		crtTk = crtTk->next;
		return 1;
	}	
	else{
		return 0;
	}
}

int typeBase(){
	if(consume(INT))
		return 1;
	else if(consume(DOUBLE))
		return 1;
	else if(consume(CHAR))
		return 1;
	else if(consume(STRUCT)){
		if(consume(ID)){
			return 1;
		}
	}
	return 0;
}

int declStruct(){
	Token* initToken = crtTk;
	if(consume(STRUCT)){
		
		if(consume(ID)){
			if(consume(LACC)){
				while(1){
					if(declVar()){
				
				}
				else
				 break;
				}
				if(consume(RACC)){
					if(consume(SEMICOLON)){
						return 1;
					}	
				}
			}
		}
	}
	crtTk=initToken;
	return 0;
}

int unit(){
	while(1){
		if(declStruct()){
			continue;
		}
		if(declFunc()){
			continue;
		}
		if(declVar()){
			continue;
		}
		else
			break;
	}

	if(consume(END)){
		return 1;
	}

	return 0;
}

int stm(){
	if(stmCompound()){

	}
	else if(consume(IF)){
		if(consume(LPAR)){
			if(expr()){	
				if(consume(RPAR)){
					if(stm()){
						if(consume(ELSE)){
							if(stm()){

							}
							//else tkerr(crtTk,"Lipseste instructiunea lui ELSE");
						}
					return 1;
					}
				}
			}
		}		
	}
}

int main(){





}
