/*
 * 	file: C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\main\D-6\main.c
 * 	date: 2017/03/10 18:32:51
 *
 * 	<usage>
pushd C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\main\D-6\
gcc main.c
a.exe

C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\Default\C_ImageProg.exe

C:\mingw-w64\x86_64-6.2.0-posix-seh-rt_v5-rev1\mingw64\bin

 *
 */

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

#ifndef PGMLIB_H_
#include "../../utils/pgmlib.h"
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
//void s_5__1_ColorHisto(int argc, char* argv[]);

///////////////////////////////
//
// functions
//
 ///////////////////////////////
//void s_5__1_ColorHisto(int argc, char* argv[]) {
//
//	img *tmp1,*tmp2, *tmp3;
////	img *tmp1,*tmp2;
//
//	// malloc
//	tmp1=(img *)malloc(sizeof(img));
//	tmp2=(img *)malloc(sizeof(img));
//	tmp3=(img *)malloc(sizeof(img));
//
//	///////////////////////////////
//	//
//	// image files
//	//
//	 ///////////////////////////////
//	char filename[] = "C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\dog.bmp";
////	char filename[] = "dog.bmp";
//
//	ReadBmp(filename,tmp1);
//
//	printf("[%s:%d] ReadBmp => done: %s\n", basename(__FILE__, '\\'), __LINE__, filename);
//
//	///////////////////////////////
//	//
//	// build: histgram
//	//
//	 ///////////////////////////////
//	int histo[256];
//
////	int num = Histo(histo, tmp1);
//	Histo(histo, tmp1);
//
//	///////////////////////////////
//	//
//	// report
//	//
//	 ///////////////////////////////
//	int i;
//
//	for (i = 100; i < 120; ++i) {
////	for (i = 0; i < 10; ++i) {
//
//		printf("[%s:%d] histo[%d] => %d\n", basename(__FILE__, '\\'), __LINE__, i, histo[i]);
//
//	}
//
////	///////////////////////////////
////	//
////	// VMirror
////	//
////	 ///////////////////////////////
////	VMirror(tmp2,tmp1);
////	VMirror(tmp3,tmp1);
////
////	char dst[100];
////
////	char time_Label[20];
////
////	sprintf(time_Label, "%s", get_Time_Label__Now());
////
////	sprintf(dst,
////				"C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\%s_%s_VMirror.bmp",
////				"s-4", time_Label);
//
////	WriteBmp(dst,tmp2);
////	PrintBmpInfo(filename);
////	PrintBmpInfo("rotate90.bmp");
//
//	///////////////////////////////
//	//
//	// free
//	//
//	 ///////////////////////////////
//	free(tmp1);
//	free(tmp2);
//	free(tmp3);
//
//
//	printf("[%s:%d] s_5__1_ColorHisto => done\n", basename(__FILE__, '\\'), __LINE__);
//
//}//s_5__1_ColorHisto

void s_1_1_copyimage() {

	//debug
	int i;

	///////////////////////

	// p.6
	// C:\WORKS_2\WS\Eclipse_Luna\prog978-4-7856-3179-6 (nagao)\chap01

	///////////////////////
	printf("[%s:%d] starting... ==> s_1_1_copyimage\n", __FILE__, __LINE__);

	putchar('\n');



    load_image( 0, "" ); /* �摜No.0�Ƀt�@�C������摜��ǂݍ��� */

    //debug
    for (i = 0; i < 10; ++i) {

    	printf("[%s:%d] image[0][0][%d] => %d\n", __FILE__, __LINE__,
    			i,
    			image[0][0][i]);

	}
//    printf("[%s:%d] image[0][0][0] => %d\n", __FILE__, __LINE__, image[0][0][0]);


    save_image( 0, "" ); /* �摜No.0�̉摜���t�@�C���ɏo�͂���   */

}//void s_1_1_copyimage

int main(int argc, char *argv[]) {

//	s_5__1_ColorHisto(argc, argv);

//	printf("[%s:%d] main => done\n", basename(__FILE__, '\\'), __LINE__);

	///////////////////////

	// operations

	///////////////////////
	s_1_1_copyimage();



	///////////////////////

	// closing messages

	///////////////////////
	printf("[%s:%d] processing...\n", __FILE__, __LINE__);

	printf("[%s:%d] yes, done\n", basename(__FILE__, '\\'), __LINE__);



	return 0;
}

