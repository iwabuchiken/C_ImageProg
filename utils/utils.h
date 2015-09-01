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

char* basename(char*, const char);

char** tokenize(char *, const char *);

#endif /* UTILS_H_ */

