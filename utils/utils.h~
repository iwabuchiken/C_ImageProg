/*
 * utils.h
 *
 *  Created on: 2015/08/22
 *      Author: kbuchi
 */

#ifndef UTILS_H_
#define UTILS_H_

#ifndef STDIO_H_
#define STDIO_H_
#include <stdio.h>
#endif

#ifndef STDLIB_H_
#define STDLIB_H_
#include <stdlib.h>
#endif

#ifndef STRING_H_
#define STRING_H_
#include <string.h>
#endif

#ifndef ASSERT_H_
#define ASSERT_H_
#include <assert.h>
#endif

#ifndef CTYPE_H_
#define CTYPE_H_
#include <ctype.h>
#endif

char* get_Time_Label__Now(void);

char* get_Time_Label(char* time_label);
//char* get_Time_Label(char* time_label) {
//
////	char time_label[30];
//
//	sprintf(time_label, "%s", "2015-08");
//
//	return time_label;
//
//}

char** str_split(char*, const char);

char** str_split_V2(char*, const char, int*);

char** str_split_V3(char*, const char, int*);

char* basename(char*, const char);

char** tokenize(char *, const char *);

char* join(char**, const int, char*);
//char* join(char**, const int, const char);

int get_MaxVal_In_Array(int *array, int numOf_Array);

//int get_random_integer(int start, int end);
int get_random_integer(int start, int end, time_t seed);

/*
 * int is_numeric(char* string)
 *
 * @return
 * 		-1	a letter
 * 		-2	neither a letter nor a number
 * 		1	a number or '-'
 *
 */
int is_numeric(char* string);
//int is_numeric(char* string) {
//
//	char ch;
//
//	ch = string[0];
//
//	while(ch != EOF) {
//
//		if(isalpha(ch)) {
//
//			return -1;
//
//		} else if(isdigit(ch)) {
//
//			continue;
//
//		} else {
//
//			return -2;
//
//		}
//
//	}
//
//	return 1;
//
//}//is_numeric(char* string)

/****************************
 *
 * image manipulations
 *
 *****************************/
//void brighten( int n, int shift );
//
//void brighten_down( int n, int shift );
//
//void lr_reverse( int n1, int n2 );

#endif /* UTILS_H_ */

