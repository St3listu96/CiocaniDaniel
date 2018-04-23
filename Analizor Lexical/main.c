#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define SAFEALLOC(var,Type) if((var=(Type*)malloc(sizeof(Type)))==NULL)err("Memorie insuficienta");

char *caracter;
int line=1;
enum{COMMA,SEMICOLON,LPAR,RPAR,LBRACKET,RBRACKET,LACC,RACC,ADD,SUB,MUL,DIV,DOT,AND,OR,NOT,NOTEQ,ASSIGN,EQUAL,LESS,LESSEQ,GREATER,GREATEREQ,CT_INT,CT_REAL,CT_STRING,CT_CHAR,END,BREAK,CHAR,DOUBLE,ELSE,FOR,IF,INT,RETURN,STRUCT,VOID,WHILE,ID};

typedef struct _Token{
	int code;
	union{
		char *text;
		long int i;
		double r;
	};
    	int line;
	struct _Token *next;
}Token;

Token *tokens=NULL;
Token *lastToken=NULL;

Token *addToken(int code,int line){
	Token *tk;
	SAFEALLOC(tk,Token)
	tk->code = code;
	tk->line = line;
	tk->next = NULL;
	if(lastToken){
		lastToken->next=tk;
	}
	else{
		tokens=tk;
	}
	lastToken=tk;
	return tk;
}

void err(const char *text,...){
	va_list va;
	va_start(va,text);
	fprintf(stderr,"Eroare: ");
	vfprintf(stderr,text,va);
	fputc('\n',stderr);
	va_end(va);
	exit(-1);
}

void listeazaAtomii(){
	Token *tk;
	for (tk = tokens; tk != NULL; tk = tk->next)
	{
	    switch(tk->code){

        case ID: printf("Line %d:\t\t\tID: %s\n",tk->line,tk->text);
                 break;
        case BREAK: printf("Line %d:\t\t\tID: BREAK\n",tk->line);
                 break;
        case CHAR: printf("Line %d:\t\t\tID: CHAR\n",tk->line);
                 break;
        case DOUBLE: printf("Line %d:\t\t\tID: DOUBLE\n",tk->line);
                 break;
        case ELSE: printf("Line %d:\t\t\tID: ELSE\n",tk->line);
                 break;
        case FOR: printf("Line %d:\t\t\tID: FOR\n",tk->line);
                 break;
        case IF: printf("Line %d:\t\t\tID: IF\n",tk->line);
                 break;
        case INT: printf("Line %d:\t\t\tID: INT\n",tk->line);
                 break;
        case RETURN: printf("Line %d:\t\t\tID: RETURN\n",tk->line);
                 break;
        case STRUCT: printf("Line %d:\t\t\tID: STRUCT\n",tk->line);
                 break;
        case VOID: printf("Line %d:\t\t\tID: VOID\n",tk->line);
                 break;
        case WHILE: printf("Line %d:\t\t\tID: WHILE\n",tk->line);
                 break;
        case COMMA: printf("Line %d:\t\t\tCOMMA\n",tk->line);
                    break;
        case SEMICOLON: printf("Line %d:\t\t\tSEMICOLON\n",tk->line);
                    break;
        case LPAR: printf("Line %d:\t\t\tLPAR\n",tk->line);
                    break;
        case RPAR: printf("Line %d:\t\t\tRPAR\n",tk->line);
                    break;
        case LBRACKET: printf("Line %d:\t\t\tLBRACKET\n",tk->line);
                    break;
        case RBRACKET: printf("Line %d:\t\t\tRBRACKET\n",tk->line);
                    break;
        case LACC: printf("Line %d:\t\t\tLACC\n",tk->line);
                    break;
        case RACC: printf("Line %d:\t\t\tRACC\n",tk->line);
                    break;
        case ADD: printf("Line %d:\t\t\tADD\n",tk->line);
                    break;
        case SUB: printf("Line %d:\t\t\tSUB\n",tk->line);
                    break;
        case MUL: printf("Line %d:\t\t\tMUL\n",tk->line);
                    break;
        case DIV: printf("Line %d:\t\t\tDIV\n",tk->line);
                    break;
        case DOT: printf("Line %d:\t\t\tDOT\n",tk->line);
                    break;
        case AND: printf("Line %d:\t\t\tAND\n",tk->line);
                    break;
        case OR: printf("Line %d:\t\t\tOR\n",tk->line);
                    break;
        case NOT: printf("Line %d:\t\t\tNOT\n",tk->line);
                    break;
        case ASSIGN: printf("Line %d:\t\t\tASSIGN\n",tk->line);
                    break;
        case EQUAL: printf("Line %d:\t\t\tEQUAL\n",tk->line);
                    break;
        case NOTEQ: printf("Line %d:\t\t\tNOTEQ\n",tk->line);
                    break;
        case LESS: printf("Line %d:\t\t\tLESS\n",tk->line);
                    break;
        case LESSEQ: printf("Line %d:\t\t\tLESSEQ\n",tk->line);
                    break;
        case GREATER: printf("Line %d:\t\t\tGREATER\n",tk->line);
                    break;
        case GREATEREQ: printf("Line %d:\t\t\tGREATEREQ\n",tk->line);
                    break;
        case CT_INT: printf("Line %d:\t\t\tCT_INT:%d\n",tk->line,tk->i);
                    break;
        case CT_REAL: printf("Line %d:\t\t\tCT_INT:%f\n",tk->line,tk->r);
                    break;
        case CT_STRING: printf("Line %d:\t\t\tCT_STRING:%s\n",tk->line,tk->text);
                    break;
        case CT_CHAR: printf("Line %d:\t\t\tCT_CHAR:%s\n",tk->line,tk->text);
                    break;
        case END: printf("Line %d:\t\t\tID: END\n",tk->line);
                    break;
	    }
	}
}

char *creeazaString(const char *start, int lungime){
	int i;
	char *text, *aux;
	char c;
	int poz = 0;
	text = (char *)malloc(lungime * sizeof(char));
	if (text == NULL)
		err(text, "");
	for (i = 0; i < lungime; i++)
		*(text + i) = *(start + i);
	*(text + lungime) = '\0';
	aux = text;
	c = *aux;
	while (c != '\0')
	{
		if (c == '\\')
		{
			aux++;
			poz++;
			c = *(aux);
			if (c == 'n')
			{
				*(text + poz - 1) = '\n';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == 't')
			{
				*(text + poz - 1) = '\t';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == 'r')
			{
				*(text + poz - 1) = '\r';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == '0')
			{
				*(text + poz - 1) = '\0';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == 'a')
			{
				*(text + poz - 1) = '\a';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == 'b')
			{
				*(text + poz - 1) = '\b';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == 'f')
			{
				*(text + poz - 1) = '\f';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == 'r')
			{
				*(text + poz - 1) = '\r';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == '\\')
			{
				*(text + poz - 1) = '\\';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == '\?')
			{
				*(text + poz - 1) = '\?';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
			else if (c == '\"')
			{
				*(text + poz - 1) = '\"';
				strcpy(aux, aux + 1);
				aux--;
				poz--;
			}
		}
		aux++;
		c = *(aux);
		poz++;
	}
	return text;

}

int getNextToken(){
	int stare=0;
	int baza=0;
	int lungimeCuvant;
	char ch;
	const char *startCh;
	Token *tk;
	while(1){
		ch=*caracter;
		printf("%c(%d) #%d\n",ch,ch,stare);
		switch(stare){
			case 0: if(ch==','){
					caracter++;
					stare=1;
				}
				else if(ch==';'){
					caracter++;
					stare=2;
				}
				else if(ch=='('){
					caracter++;
					stare=3;
				}
				else if(ch==')'){
					caracter++;
					stare=4;
				}
				else if(ch=='['){
					caracter++;
					stare=5;
				}
				else if(ch==']'){
					caracter++;
					stare=6;
				}
				else if(ch=='{'){
					caracter++;
					stare=7;
				}
				else if(ch=='}'){
					caracter++;
					stare=8;
				}
				else if(ch=='+'){
					caracter++;
					stare=9;
				}
				else if(ch=='-'){
					caracter++;
					stare=10;
				}
				else if(ch=='*'){
					caracter++;
					stare=11;
				}
				else if(ch=='.'){
					caracter++;
					stare=12;
				}
				else if(ch=='&'){
					caracter++;
					stare=13;
				}
				else if(ch=='|'){
					caracter++;
					stare=15;
				}
				else if(ch=='!'){
					caracter++;
					stare=17;
				}
				else if(ch=='='){
					caracter++;
					stare=20;
				}
				else if(ch=='<'){
					caracter++;
					stare=23;
				}
				else if(ch=='>'){
					caracter++;
					stare=26;
				}
				else if(isalpha(ch)||ch=='_'){
					startCh=caracter;
					caracter++;
					stare=29;
				}
				else if(ch=='\n'){
					caracter++;
					line++;
				}
				else if(ch==0){
					addToken(END,line);
					return END;
				}
				else if(ch==' '||ch=='\r'||ch=='\t'){
					caracter++;
				}
				else if(ch>='1'&&ch<='9'){
                    baza=10;
                    startCh=caracter;
					caracter++;
					stare=31;
				}
				else if(ch=='0'){
				    startCh=caracter;
					caracter++;
					stare=32;
				}
				else if(ch=='"'){
					startCh=caracter;
                    caracter++;
                    stare=45;
				}
				else if(ch=='\''){
                    startCh=caracter;
                    caracter++;
                    stare=49;
				}
				else if(ch=='/'){
                    caracter++;
                    stare=53;
				}
				break;
			case 1:	addToken(COMMA,line);
				return COMMA;
				break;
			case 2: addToken(SEMICOLON,line);
				return SEMICOLON;
				break;
			case 3:	addToken(LPAR,line);
				return LPAR;
				break;
			case 4:	addToken(RPAR,line);
				return RPAR;
				break;
			case 5:	addToken(LBRACKET,line);
				return LBRACKET;
				break;
			case 6:	addToken(RBRACKET,line);
				return RBRACKET;
				break;
			case 7:	addToken(LACC,line);
				return LACC;
				break;
			case 8:	addToken(RACC,line);
				return RACC;
				break;
			case 9:	addToken(ADD,line);
				return ADD;
				break;
			case 10:addToken(SUB,line);
				return SUB;
				break;
			case 11:addToken(MUL,line);
				return MUL;
				break;
			case 12:addToken(DOT,line);
				return DOT;
				break;
			case 13: if(ch=='&'){
					stare=14;
					caracter++;
				}
				break;
			case 14:addToken(AND,line);
				return AND;
				break;
			case 15: if(ch=='|'){
					caracter++;
					stare=16;
				}
				break;
			case 16:addToken(OR,line);
				return OR;
				break;
			case 17: if(ch=='='){
					caracter++;
					stare=19;
				}
				else{
					stare=18;
				}
				break;
			case 18:addToken(NOT,line);
				return NOT;
				break;
			case 19:addToken(NOTEQ,line);
				return NOTEQ;
				break;
			case 20: if(ch=='='){
					caracter++;
					stare=22;
				}
				else{
					stare=21;
				}
				break;
			case 21:addToken(ASSIGN,line);
				return ASSIGN;
				break;
			case 22:addToken(EQUAL,line);
				return EQUAL;
				break;
			case 23: if(ch=='='){
					caracter++;
					stare=25;
				}
				else{
					stare=24;
				}
				break;
			case 24:addToken(LESS,line);
				return LESS;
				break;
			case 25:addToken(LESSEQ,line);
				return LESSEQ;
				break;
			case 26: if(ch=='='){
					caracter++;
					stare=28;
				}
				else{
					stare=27;
				}
				break;
			case 27:addToken(GREATER,line);
				return GREATER;
				break;
			case 28:addToken(GREATEREQ,line);
				return GREATEREQ;
				break;
			case 29: if(isalnum(ch)||ch=='_'){
						caracter++;
						stare=29;
					}
					else{
					stare=30;
					}
				break;
			case 30:
 					lungimeCuvant=caracter-startCh;
					if(lungimeCuvant==5 && !memcmp(startCh,"break",5))
						tk=addToken(BREAK,line);
					else if(lungimeCuvant==4 && !memcmp(startCh,"char",4))
						tk=addToken(CHAR,line);
					else if(lungimeCuvant==6 && !memcmp(startCh,"double",6))
						tk=addToken(DOUBLE,line);
					else if(lungimeCuvant==4 && !memcmp(startCh,"else",4))
						tk=addToken(ELSE,line);
					else if(lungimeCuvant==3 && !memcmp(startCh,"for",3))
						tk=addToken(FOR,line);
					else if(lungimeCuvant==2 && !memcmp(startCh,"if",2))
						tk=addToken(IF,line);
					else if(lungimeCuvant==3 && !memcmp(startCh,"int",3))
						tk=addToken(INT,line);
					else if(lungimeCuvant==6 && !memcmp(startCh,"return",6))
						tk=addToken(RETURN,line);
					else if(lungimeCuvant==6 && !memcmp(startCh,"struct",6))
						tk=addToken(STRUCT,line);
					else if(lungimeCuvant==4 && !memcmp(startCh,"void",4))
						tk=addToken(VOID,line);
					else if(lungimeCuvant==5 && !memcmp(startCh,"while",5))
						tk=addToken(WHILE,line);
					else{
						tk=addToken(ID,line);
						tk->text = creeazaString(startCh,lungimeCuvant);
					}
					return tk->code;
					break;
			case 31 : if(isdigit(ch)){
						caracter++;
						stare=31;
					}
					else if(ch=='.'){
						caracter++;
						stare=39;
					}
					else if(ch=='e' || ch=='E'){
						caracter++;
						stare=41;
					}
					else{
						stare=36;
					}
					break;
			case 32: if(ch=='x'){
						caracter++;
						stare=34;
					}
					else{
						stare=33;
					}
					break;
			case 33: baza = 8;
                    if(ch>='0'&&ch<='7'){
						caracter++;
						stare=33;
					}
					else if(ch=='8' || ch=='9'){
						caracter++;
						stare=37;
					}
					else if(ch=='.'){
						caracter++;
						stare=39;
					}
					else if(ch=='e' || ch=='E'){
						caracter++;
						stare=41;
					}
					else{
						stare=36;
					}
					break;

			case 34: baza=16;
                    if(isdigit(ch) || (ch>='a' && ch <='f') || (ch>='A' && ch <= 'F')){
						caracter++;
						stare=35;
					}
					break;

			case 35: if(isdigit(ch) || (ch>='a' && ch <='f') || (ch>='A' && ch <= 'F')){
						caracter++;
						stare=35;
					}
					else{
						stare=36;
					}
					break;

			case 36:
                    lungimeCuvant=caracter-startCh;
                    tk = addToken(CT_INT,line);
                    tk->i=strtol(creeazaString(startCh,lungimeCuvant),NULL,baza);
					return CT_INT;
					break;

			case 37: if(isdigit(ch)){
						caracter++;
						stare=37;
					}
					else if(ch=='.'){
						caracter++;
						stare=39;
					}
					else if(ch=='e' || ch =='E'){
						caracter++;
						stare=41;
					}
					break;

			case 39: if(isdigit(ch)){
						caracter++;
						stare=40;
					}
					break;

			case 40: if(isdigit(ch)){
						caracter++;
						stare=40;
					}
					else if(ch=='e' || ch=='E'){
						caracter++;
						stare=41;
					}
					else{
                        stare=44;
					}
					break;

			case 41: if(ch=='+' || ch=='-'){
						caracter++;
						stare=42;
					}
					else{
						stare=42;
					}
					break;

			case 42: if(isdigit(ch)){
						caracter++;
						stare=43;
					}
					break;

			case 43: if(isdigit(ch)){
						caracter++;
						stare=43;
					}
					else{
						stare=44;
					}
					break;

			case 44: lungimeCuvant = caracter - startCh;
                     tk = addToken(CT_REAL,line);
                     tk->r=strtod(creeazaString(startCh,lungimeCuvant),NULL);
					return CT_REAL;
					break;

            case 45: if(ch=='\\'){
                        caracter++;
                        stare=46;
                    }
                    else if(ch=='"'){
                        caracter++;
                        stare=48;
                    }
                    else{
                        caracter++;
                        stare=47;
                    }
                    break;

            case 46: if(ch=='a' || ch=='b' || ch=='f' || ch=='n' || ch=='r' || ch=='t' || ch=='v' || ch=='\'' || ch=='\\' || ch=='"' || ch=='?' || ch=='\0'){
                        caracter++;
                        stare=47;
                    }
                    break;

            case 47: if(ch=='"'){
                        caracter++;
                        stare=48;
                    }
                    else{
                        stare=45;
                    }
                    break;

            case 48: lungimeCuvant = caracter-startCh;
                    tk=addToken(CT_STRING,line);
                    tk->text=creeazaString(startCh,lungimeCuvant);
                    return CT_STRING;
                    break;

            case 49: if(ch=='\\'){
                        caracter++;
                        stare=50;
                    }
                    else{
                        caracter++;
                        stare=51;
                    }
                    break;

            case 50: if(ch=='a' || ch=='b' || ch=='f' || ch=='n' || ch=='r' || ch=='t' || ch=='v' || ch=='\'' || ch=='\"' || ch=='\\' || ch=='?' || ch=='\0'){
                        caracter++;
                        stare=51;
                    }
                    break;

            case 51: if(ch=='\''){
                        caracter++;
                        stare=52;
                    }
                    break;

            case 52: lungimeCuvant = caracter-startCh;
                     tk=addToken(CT_CHAR,line);
                     tk->text = creeazaString(startCh,lungimeCuvant);
                     return CT_CHAR;
                     break;

            case 53: if(ch=='*'){
                        caracter++;
                        stare=55;
                    }
                    else if(ch=='/'){
                        caracter++;
                        stare=57;
                    }
                    else{
                        stare=54;
                    }
                    break;
            case 54: addToken(DIV,line);
                    return DIV;
                    break;
            case 55: if(ch!='*'){
                        if(ch=='\n')
                            line++;
                        caracter++;
                    }
                    else if(ch=='*'){
                        caracter++;
                        stare=56;
                    }
                    break;
            case 56: if(ch=='*'){
                        caracter++;
                    }
                    else if(ch!='*' && ch!='/'){
                        caracter++;
                        stare=55;
                    }
                    else if(ch=='/'){
                        caracter++;
                        stare=0;
                    }
                    break;
            case 57: if(ch!='\n' && ch!='\r' && ch!='\0'){
                        caracter++;
                    }
                    else{
                        stare=0;
                    }
			break;
		default: printf("Stare inexistenta.\n");
                    	exit(1);
			break;
		}
	}
}
int main(){
	char buffer[300001];
	int n;
	FILE *fisier;
	fisier = fopen("8.c","r");
	if(!fisier){
		printf("Eroare deschidere fisier.\n");
		exit(1);
	}
	n = fread(buffer,1,300000,fisier);
	fclose(fisier);
	buffer[n]='\0';
	caracter=buffer;
	while(getNextToken()!=END){
	}
        printf("\n\n");
    	listeazaAtomii();
	return 0;
}
