#ifndef STDIO_H_
#define STDIO_H_
#include <stdio.h>
#endif

#ifndef STDLIB_H_
#define STDLIB_H_
#include <stdlib.h>
#endif

//#include "wave.h"

#ifndef UTILS_H_
#include "../../utils/utils.h"
#endif

void D_1_s_1_first(void);
void D_1_s_1_strtok(void);
//char** tokenize(char *, const char *);
//void tokenize(char *, const char *);

int main(int argc, char *argv[])
//int main(void)
{

	D_1_s_1_strtok();
//	D_1_s_1_first();

	return 0;
}

void D_1_s_1_first() {

	char time_label[30];

	///////////////////////////////
	//
	// split string
	//
	 ///////////////////////////////
//	http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
//	char months[] = "You";
	char months[] = "You\\can\\use\\the\\strtok()\\function\\to\\split\\a\\string\\(and\\specify\\the\\delimiter\\to\\use)";
//	char months[] = "You can use the strtok() function to split a string (and specify the delimiter to use)";
//	char months[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
	char** tokens;

	char delim_char = '\\';
//	char delim_char = ' ';

	int num;

	printf("months=[%s]\n\n", months);

	tokens = str_split_V2(months, delim_char, &num);
//	tokens = str_split_V2(months, ',', &num);
//	tokens = str_split(months, ',');

	printf("[%s:%d] month[0] => %s (num = %d)\n", __FILE__, __LINE__, tokens[0], num);

//	printf("[%s:%d] basename => %s\n", __FILE__, __LINE__, basename(__FILE__, '\\'));


	///////////////////////////////
	//
	// time label
	//
	 ///////////////////////////////
	get_Time_Label(time_label);

	printf("[%s:%d] done: %s\n", __FILE__, __LINE__, time_label);


}

void D_1_s_1_strtok() {

	char str[] = "Our polish postfix calculate function will be mindlessly simplest";
	char str2[] = "Our polish postfix calculate function will be mindlessly simplest";
//	char str[] = "Our polish postfix calculate function will be mindlessly simple";
//	char str[] = "You can use the strtok() function to split a string (and specify the delimiter to use)";

	const char s[2] = " ";

	printf("[%s:%d] str => %s\n", __FILE__, __LINE__, str);


	tokenize(str, s);

	printf("[%s:%d] str is now => %s\n", __FILE__, __LINE__, str);

	tokenize(str2, s);
//	tokenize(str, s);
//	tokenize(str, s);

//	char *token;
//
//	token = strtok(str, s);
//
//	printf("[%s:%d] str => %s\n", __FILE__, __LINE__, str);
//
//	printf("[%s:%d] token => %s\n", __FILE__, __LINE__, token);
//
//	while ( token != NULL ) {
//	      printf( "%s\n", token );
//	      token = strtok( NULL, " " );
//   }

}

//char** tokenize(char *str, const char *delim) {
////void tokenize(char *str, const char *delim) {
//
//	char *token;
//
//
//
//	token = strtok(str, delim);
//
//	printf("[%s:%d] str => %s\n", __FILE__, __LINE__, str);
//
//	printf("[%s:%d] token => %s\n", __FILE__, __LINE__, token);
//
//	while ( token != NULL ) {
//	      printf( "%s\n", token );
//	      token = strtok( NULL, delim );
////	      token = strtok( NULL, " " );
//	}
//
//}
