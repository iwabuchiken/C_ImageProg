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

#ifndef BMP_H_
#include  "bmp.h"
#endif

///////////////////////////////
//
// protos
//
 ///////////////////////////////
void s_4__1_DrawLine(int argc, char* argv[]);

///////////////////////////////
//
// functions
//
 ///////////////////////////////
void s_4__1_DrawLine(int argc, char* argv[]) {



	printf("[%s:%d] argc = %d\n", basename(__FILE__, '\\'), __LINE__, argc);

}

int main(int argc, char *argv[]) {

	s_4__1_DrawLine(argc, argv);

	return 0;
}

