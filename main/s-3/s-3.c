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
void s_3__1(void);

///////////////////////////////
//
// functions
//
 ///////////////////////////////
void s_3__1(void) {

	img *tmp1,*tmp2;

	// malloc
	tmp1=(img *)malloc(sizeof(img));
	tmp2=(img *)malloc(sizeof(img));

	printf("[%s:%d] img instances => malloc-ed\n", basename(__FILE__, '\\'), __LINE__);

	///////////////////////////////
	//
	// image files
	//
	 ///////////////////////////////
	char filename[] = "C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-3\\dog.bmp";
//	char filename[] = "dog.bmp";

	ReadBmp(filename,tmp1);

	printf("[%s:%d] ReadBmp => done: %s\n", basename(__FILE__, '\\'), __LINE__, filename);

	///////////////////////////////
	//
	// mirror
	//
	 ///////////////////////////////
	VMirror(tmp2,tmp1);
	WriteBmp("vmirror.bmp",tmp2);
	PrintBmpInfo("vmirror.bmp");


	///////////////////////////////
	//
	// free
	//
	 ///////////////////////////////
	free(tmp1);
	free(tmp2);

	printf("[%s:%d] img instances => freed\n", basename(__FILE__, '\\'), __LINE__);


	printf("[%s:%d] done\n", basename(__FILE__, '\\'), __LINE__);

}

int main(int argc, char *argv[])
//int main(void)
{

	s_3__1();
//	D_1_s_2_s2_split();
//	D_1_s_2_strchr();
//	D_1_s_1_strtok();
//	D_1_s_1_first();

	return 0;
}

