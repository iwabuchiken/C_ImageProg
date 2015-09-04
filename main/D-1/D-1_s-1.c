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

void D_1_s_2_s3_basename(void);
void D_1_s_2_s2_split(void);
void D_1_s_2_strchr(void);

void D_1_s_1_first(void);
void D_1_s_1_strtok(void);

//char** tokenize(char *, const char *);
//void tokenize(char *, const char *);

///////////////////////////////
//
// functions
//
 ///////////////////////////////
void D_1_s_2_s3_basename() {

//	char full_path[] = "The following example shows the usage of strcpy() function";
	char full_path[] = __FILE__;

	const char path_delimiter = '\\';

	char *bname = basename(full_path, path_delimiter);

	printf("[%s:%d] full path => %s\n", __FILE__, __LINE__, full_path);

	printf("[%s:%d] base name => %s\n", __FILE__, __LINE__, bname);

	printf("[%s:%d] done\n", basename(__FILE__, '\\'), __LINE__);


}//D_1_s_2_s3_basename

void D_1_s_2_s2_split(void) {

	char str[] = __FILE__;
//	char str[] = "You\\can\\use";
//	char str[] = "You\\can\\use\\the\\strtok()\\function\\to\\split\\a\\string\\(and\\specify\\the\\delimiter\\to\\use)";
//	char months[] = "You can use the strtok() function to split a string (and specify the delimiter to use)";
//	char months[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";

	char *tmp = malloc((sizeof(char) * (strlen(str) + 1)));
	strcpy(tmp, str);

	char** tokens;

	char delim_char = '\\';
//	char delim_char = ' ';

	int num;

	printf("str=[%s] (%d)\n\n", str, strlen(str));

	tokens = str_split_V3(tmp, delim_char, &num);
//	tokens = str_split_V3(str, delim_char, &num);

	printf("[%s:%d] tokens = %s / num = %d\n", __FILE__, __LINE__, tokens[0], num);
//	printf("[%s:%d] tokens = %s\n", __FILE__, __LINE__, tokens);


	int offset = 0;

	while(*(tokens + offset) != NULL) {
//	while(*tokens != NULL) {
//	while(tokens != NULL) {

		printf("[%s:%d] tokens => %s\n", __FILE__, __LINE__, *(tokens + offset));
//		printf("[%s:%d] tokens => %s\n", __FILE__, __LINE__, *tokens);

		offset ++;

//		tokens ++;

	}

	///////////////////////////////
	//
	// for loop
	//
	 ///////////////////////////////
	int i;

//	printf("[%s:%d] tokens[0] => %s\n", __FILE__, __LINE__, tokens[0]);
//	printf("[%s:%d] tokens[1] => %s\n", __FILE__, __LINE__, tokens[1]);
//	printf("[%s:%d] tokens[1] => %s\n", __FILE__, __LINE__, *tokens[1]);	//=> stops
//	printf("[%s:%d] tokens[1] => %s\n", __FILE__, __LINE__, tokens[1]);


	for (i = 0; i < num; ++i) {

//		printf("[%s:%d] tokens[%d] => %s\n", __FILE__, __LINE__, i, *(tokens[i]));
		printf("[%s:%d] tokens[%d] => %s\n", __FILE__, __LINE__, i, tokens[i]);


	}

	printf("[%s:%d] (after) str => %s\n", __FILE__, __LINE__, str);

	///////////////////////////////
	//9
	// strcpy
	//
	 ///////////////////////////////
//	char *tmp = malloc((sizeof(char) * (strlen(str) - 1)));
//	char *tmp = malloc((sizeof(char) * (strlen(str))));
//	char *tmp = malloc((sizeof(char) * (strlen(str) + 1)));
//
//	strcpy(tmp, str);
//
//	printf("[%s:%d] tmp = [%s] (%d)\n", __FILE__, __LINE__, tmp, strlen(tmp));
//
//	printf("[%s:%d] strlen(str) => %d\n", __FILE__, __LINE__, strlen(str));


}//D_1_s_2_s2_split

void D_1_s_2_strchr() {

	const char str[] = "ab.cd.";
//	const char str[] = "http://www.tutorialspoint.com";
	const char ch = '.';
	char *ret;

	ret = strchr(str, ch);

	printf("[%s:%d] str = %s / ch = %c / ret = %s\n", __FILE__, __LINE__, str, ch, ret);

	ret ++;

	ret = strchr(ret, ch);

	printf("[%s:%d] str = %s / ch = %c / ret = %s\n", __FILE__, __LINE__, str, ch, ret);

	///////////////////////////////
	//
	//
	//
	 ///////////////////////////////
	ret = strchr(str, ch);

	int count = 0;

	while(ret != NULL) {

		count ++;

		// validate length
		if (ret + 1 > str + strlen(str) - 1) {

			printf("[%s:%d] yes: ret + 1 > str + strlen(str) - 1\n", __FILE__, __LINE__);

			break;

		} else {

			printf("[%s:%d] no: ret => %s\n", __FILE__, __LINE__, ret);

		}

		ret ++;

		ret = strchr(ret, ch);

	}

	printf("[%s:%d] count => %d\n", __FILE__, __LINE__, count);


//	printf("String after |%c| is - |%s|\n", ch, ret);

//	return(0);

}//D_1_s_2_strchr

int main(int argc, char *argv[])
//int main(void)
{

	D_1_s_2_s3_basename();
//	D_1_s_2_s2_split();
//	D_1_s_2_strchr();
//	D_1_s_1_strtok();
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
