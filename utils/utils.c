/*
 * utils.h
 *
 *  Created on: 2015/08/22
 *      Author: kbuchi
 */

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
