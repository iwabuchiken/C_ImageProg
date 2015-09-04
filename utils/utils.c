/*
 * utils.h
 *
 *  Created on: 2015/08/22
 *      Author: kbuchi
 */
#ifndef STDIO_H_
#define STDIO_H_
#include <stdio.h>
#endif

#ifndef STDLIB_H_
#define STDLIB_H_
#include <stdlib.h>
#endif

#ifndef UTILS_H_
#include "utils.h"
#endif

char* get_Time_Label(char* time_label) {

//	char time_label[30];

	sprintf(time_label, "%s", "2015-08");

	return time_label;

}

//REF http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c answered Feb 9 '12 at 12:09
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

///////////////////////////////
//
// @return
//	=> number of tokens
//
///////////////////////////////
char** str_split_V2(char* a_str, const char a_delim, int* num) {
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    printf("[%s:%d] count => done (count = %d)\n", __FILE__, __LINE__, count);

    ///////////////////////////////
	//
	// set num
	//
	 ///////////////////////////////
	*num = count - 1;

    result = malloc(sizeof(char*) * count);

    printf("[%s:%d] malloc => done\n", __FILE__, __LINE__);

    printf("[%s:%d] a_str = %s / delim = %c\n", __FILE__, __LINE__, a_str, a_delim);
//    printf("[%s:%d] a_str = %s / delim = %c\n", __FILE__, __LINE__, a_str, delim);


    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        printf("[%s:%d] strtok => 1st\n", __FILE__, __LINE__);


        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    printf("[%s:%d] result => set\n", __FILE__, __LINE__);


    return result;
}

///////////////////////////////
//
// @return
//	=> number of tokens
//
///////////////////////////////
char** str_split_V3(char* a_str, const char a_delim, int* num) {
    char** result    = 0;
    size_t count     = 0;

    printf("[%s:%d] a_str => %d\n", __FILE__, __LINE__, strlen(a_str));

//    char *a_str_dup = malloc((sizeof(char) * (strlen(a_str) + 2)));
////    char *a_str_dup = malloc((sizeof(char) * (strlen(a_str) + 1)));
//
//    strcpy(a_str_dup, a_str);
//
//    printf("[%s:%d] a_str_dup = %s\n", __FILE__, __LINE__, a_str_dup);
//
//
//    char* tmp        = a_str_dup;
    char* tmp        = a_str;

    printf("[%s:%d] tmp => %s\n", __FILE__, __LINE__, tmp);


    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    printf("[%s:%d] count => done (count = %d)\n", __FILE__, __LINE__, count);

    ///////////////////////////////
	//
	// set num
	//
	 ///////////////////////////////
	*num = count - 1;

    result = malloc(sizeof(char*) * count);

    printf("[%s:%d] malloc => done\n", __FILE__, __LINE__);

    printf("[%s:%d] a_str = %s / delim = %c\n", __FILE__, __LINE__, a_str, a_delim);
//    printf("[%s:%d] a_str = %s / delim = %c\n", __FILE__, __LINE__, a_str, delim);


    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        printf("[%s:%d] strtok => 1st\n", __FILE__, __LINE__);


        while (token)
        {
        	printf("[%s:%d] assert(idx < count)\n", __FILE__, __LINE__);

            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }

        printf("[%s:%d] assert(idx == count - 1)\n", __FILE__, __LINE__);

        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    printf("[%s:%d] result => set\n", __FILE__, __LINE__);


    return result;
}

char* basename(char* full_path, const char path_delimiter) {

	char** tokens;

	char delim_char = '\\';

	int num;

	printf("[%s:%d] delim_char = %c\n", __FILE__, __LINE__, delim_char);


	// split
//	tokens = str_split_V2(full_path, delim_char, num);
	tokens = str_split_V2(full_path, delim_char, &num);

	printf("[%s:%d] split done => %s (num = %d)\n", __FILE__, __LINE__, full_path, num);
//	printf("[%s:%d] split done => %s (num = %d)\n", __FILE__, __LINE__, full_path, *num);


	// get the last token
	if (num <= 1) {

		printf("[%s:%d] num <= 1: tokens[0] = %s\n", __FILE__, __LINE__, tokens[0]);

		return tokens[0];

//		return tokens[0];

	} else {

		printf("[%s:%d] num > 1: tokens[0] = %s\n", __FILE__, __LINE__, tokens[0]);

		return tokens[0];

//		int i;
//
//		for (i = 0; i < num - 2; ++i) {
//
//			free(*(tokens + i));
//
//		}
//
//		return tokens[i];

	}

}

char** tokenize(char *str, const char *delim) {
//void tokenize(char *str, const char *delim) {

	char *token;

	///////////////////////////////
	//
	// count: how many tokens
	//REF http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c answered Feb 9 '12 at 12:09
	//
	 ///////////////////////////////
    char* tmp        = str;
    char* last_comma = 0;
//    char delim[2];
//    delim[0] = a_delim;
//    delim[1] = 0;

    size_t count     = 0;

    printf("[%s:%d] tmp = %s(&tmp=%p)\n", __FILE__, __LINE__, tmp, &tmp);
    printf("[%s:%d] tmp = %%d=%d (%%p=%p)\n", __FILE__, __LINE__, tmp, tmp);
    printf("[%s:%d] str = %%d=%d (%%p=%p)\n", __FILE__, __LINE__, str, str);
    printf("[%s:%d] &str = %%d=%d (%%p=%p)\n", __FILE__, __LINE__, &str, &str);

    printf("[%s:%d] delim = '%s'\n", __FILE__, __LINE__, delim);
    printf("[%s:%d] delim[0] = '%c'\n", __FILE__, __LINE__, delim[0]);


    while (*tmp)
    {
//    	printf("[%s:%d] *tmp = '%c'\n", __FILE__, __LINE__, *tmp);
//    	printf("[%s:%d] *tmp = %s\n", __FILE__, __LINE__, *tmp);

        if (delim[0] == *tmp)
//        if (delim == *tmp)
//        if (a_delim == *tmp)
        {
        	printf("[%s:%d] delim[0] = '%c' / *tmp = '%c'\n",
        						__FILE__, __LINE__, delim[0], *tmp);
//        	printf("[%s:%d] delim = '%s' / *tmp = '%s'\n", __FILE__, __LINE__, delim, *tmp);

            count++;
            last_comma = tmp;

            printf("[%s:%d] last_comma = %s\n", __FILE__, __LINE__, last_comma);

        }
        tmp++;
    }

    printf("[%s:%d] count = %d\n", __FILE__, __LINE__, count);

    printf("[%s:%d] &last_comma => %p(%%d=%d)\n",
    					__FILE__, __LINE__, &last_comma, &last_comma);
    printf("[%s:%d] &str => %p(%%d=%d)\n", __FILE__, __LINE__, &str, &str);
    printf("[%s:%d] strlen(str) - 1 => %d\n", __FILE__, __LINE__, strlen(str) - 1);
//    printf("[%s:%d] str => %d\n", __FILE__, __LINE__, &str + strlen(str) - 1);

    printf("[%s:%d] str + strlen(str) - 1 => %s\n", __FILE__, __LINE__, str + strlen(str) - 1);
    printf("[%s:%d] str + strlen(str) - 2 => %s\n", __FILE__, __LINE__, str + strlen(str) - 2);
    printf("[%s:%d] last_comma - (str + strlen(str) - 1) => %%d=%d\n",
    					__FILE__, __LINE__, last_comma - (str + strlen(str) - 1));
//    printf("[%s:%d] &(str + strlen(str) - 1) => %p\n",
//    						__FILE__, __LINE__, (&str) + strlen(str) - 1));
//    						__FILE__, __LINE__, &str + strlen(str) - 1));
//    						__FILE__, __LINE__, &(str + strlen(str) - 1));



	token = strtok(str, delim);

	printf("[%s:%d] str => %s\n", __FILE__, __LINE__, str);

	printf("[%s:%d] token => %s\n", __FILE__, __LINE__, token);

	while ( token != NULL ) {
	      printf( "%s\n", token );
	      token = strtok( NULL, delim );
//	      token = strtok( NULL, " " );
	}

	return NULL;

}
