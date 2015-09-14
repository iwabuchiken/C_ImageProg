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
//#define BMP_H_
#include  "bmp.h"
#endif

#ifndef MAIN_H_
#define MAIN_H_
#include "main.h"
#endif

///////////////////////////////
//
// protos
//
 ///////////////////////////////
void s_5__1_ColorHisto(int argc, char* argv[]);

///////////////////////////////
//
// functions
//
 ///////////////////////////////
void s_5__1_ColorHisto(int argc, char* argv[]) {

	img *tmp1,*tmp2, *tmp3;
//	img *tmp1,*tmp2;

	// malloc
	tmp1=(img *)malloc(sizeof(img));
	tmp2=(img *)malloc(sizeof(img));
	tmp3=(img *)malloc(sizeof(img));

	///////////////////////////////
	//
	// image files
	//
	 ///////////////////////////////
	char filename[] = "C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\dog.bmp";
//	char filename[] = "dog.bmp";

	ReadBmp(filename,tmp1);

	printf("[%s:%d] ReadBmp => done: %s\n", basename(__FILE__, '\\'), __LINE__, filename);

	///////////////////////////////
	//
	// build: histgram
	//
	 ///////////////////////////////
	int histo[256];

//	int num = Histo(histo, tmp1);
	Histo(histo, tmp1);

	///////////////////////////////
	//
	// report
	//
	 ///////////////////////////////
	int i;

	for (i = 100; i < 120; ++i) {
//	for (i = 0; i < 10; ++i) {

		printf("[%s:%d] histo[%d] => %d\n", basename(__FILE__, '\\'), __LINE__, i, histo[i]);

	}

//	///////////////////////////////
//	//
//	// VMirror
//	//
//	 ///////////////////////////////
//	VMirror(tmp2,tmp1);
//	VMirror(tmp3,tmp1);
//
//	char dst[100];
//
//	char time_Label[20];
//
//	sprintf(time_Label, "%s", get_Time_Label__Now());
//
//	sprintf(dst,
//				"C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\%s_%s_VMirror.bmp",
//				"s-4", time_Label);

//	WriteBmp(dst,tmp2);
//	PrintBmpInfo(filename);
//	PrintBmpInfo("rotate90.bmp");

	///////////////////////////////
	//
	// free
	//
	 ///////////////////////////////
	free(tmp1);
	free(tmp2);
	free(tmp3);


	printf("[%s:%d] s_5__1_ColorHisto => done\n", basename(__FILE__, '\\'), __LINE__);

}//s_5__1_ColorHisto

int main(int argc, char *argv[]) {

	s_5__1_ColorHisto(argc, argv);

	printf("[%s:%d] main => done\n", basename(__FILE__, '\\'), __LINE__);

	return 0;
}

