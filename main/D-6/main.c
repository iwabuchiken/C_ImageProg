/*
 * 	file: C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\main\D-6\main.c
 * 	date: 2017/03/10 18:32:51
 *
 * 	<usage>
pushd C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\main\D-6\
gcc main.c
a.exe

pushd C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg
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
#include  "bmp.h~"
#endif

#ifndef TIME_H_
#define TIME_H_
#include <time.h>
#endif

//#ifndef CTYPE_H_
//#define CTYPE_H_
//#include <ctype.h>
//#endif

#ifndef MAIN_H_
#define MAIN_H_
#include "main.h"
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

/* 画像 No.n を shift だけ明るくする */
void brighten( int n, int shift );

void s_2_1_brighten( int n, int shift );

void s_3_1_brighten( int n, int shift );


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

/*
 * s_3_1_brighten( int n, int shift )
 *
 * <usage> 2017/03/14 17:01:18
 * generate random integers
 * - create a text file
 * - edit the stings
 * 		- "\r\n"	=> "\t"
 * 		- "\*"	=> "\r\n"
 * 		- "^\t\t"	=> ""
 * 		- "\t$"	=> ""
 * 		- C/P	=> to a spreadsheet
 *
 */

void s_4_1_gets() {

	//ref http://www1.cts.ne.jp/~clab/hsample/IO/IO16.html
    char name[21];

//    printf("your name?:\t");
////    printf("お名前を入力して下さい\t");
//    gets(name);
//    printf("\nyour name is: '%s'\n", name);
////    printf("\nあなたのお名前は %s です。\n", name);

    /****************************
	 *
	 * number
	 *
	 *****************************/
    printf("number?:\t");
//    printf("お名前を入力して下さい\t");
    gets(name);
    printf("\nthe number is: '%s'\n", name);

    //ref http://hitorilife.com/atoi.php
    printf("\nthe number is (atoi): '%d'\n", atoi(name));

    printf("\nthe twice is (atoi): '%d'\n", atoi(name) * 2);

    printf("\nname[0] %%c => '%c'\n", name[0]);
    printf("\n(char)name[0] %%d => '%d'\n", (char)name[0]);
    printf("\nname[0] - '0' %%d => '%d'\n", name[0] - '0');

    printf("\nis_numeric(name[0] - '0') %%d => '%d'\n", is_numeric(name));
//    printf("\nis_numeric(name[0] - '0') %%d => '%d'\n", is_numeric(name[0] - '0'));

//    printf("\ntis_numeric => '%d'\n", name);	//=> "expects argument of type 'int', but argument 2 has type 'char *'"
//    printf("\ntis_numeric => '%d'\n", name[0]);	//=> '52'
//    printf("\ntis_numeric => '%d'\n", is_numeric(name[0]));



}//void s_4_1_gets()

void s_3_1_brighten( int n, int shift ) {

	//debug
//	int i;

	///////////////////////

	// p.7
	// C:\WORKS_2\WS\Eclipse_Luna\prog978-4-7856-3179-6 (nagao)\chap01

	///////////////////////

	int image_shift = -50;
	int image_num = 0;

	printf("[%s:%d] starting... ==> s_3_1_brighten\n", __FILE__, __LINE__);

	putchar('\n');

    load_image( 0, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾉフ�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ鞫懶ｿｽ�ｿｽﾇみ搾ｿｽ�ｿｽ�ｿｽ */

//    //debug
//    for (i = 0; i < 10; ++i) {
//
//    	printf("[%s:%d] image[0][0][%d] => %d\n", __FILE__, __LINE__,
//    			i,
//    			image[0][0][i]);
//
//	}
//    printf("[%s:%d] image[0][0][0] => %d\n", __FILE__, __LINE__, image[0][0][0]);

    /****************************
	 *
	 * brighten
	 *
	 *****************************/
	printf("[%s:%d] brightening...\n", basename(__FILE__, '\\'), __LINE__);

	//debug
	int i;

	int max = 50;
//	int max = 5;

	for (i = 0; i < max; ++i) {

		image_shift = get_random_integer(1, 10, time(NULL));
//		image_shift = get_random_integer(1, 6);

		printf("[%s:%d] random => %d\n", basename(__FILE__, '\\'), __LINE__, image_shift);

	}
//	image_shift = get_random_integer(1, 6);

	//debug
	return;

	brighten( image_num, image_shift);
//	brighten( 0, 100);

    save_image( 0, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾌ画像�ｿｽ�ｿｽ�ｿｽt�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽﾉ出�ｿｽﾍゑｿｽ�ｿｽ�ｿｽ   */

}//s_3_1_brighten( int n, int shift )


void s_2_1_brighten( int n, int shift ) {

	//debug
//	int i;

	///////////////////////

	// p.7
	// C:\WORKS_2\WS\Eclipse_Luna\prog978-4-7856-3179-6 (nagao)\chap01

	///////////////////////

	int image_shift = -50;
	int image_num = 0;

	printf("[%s:%d] starting... ==> s_2_1_brighten\n", __FILE__, __LINE__);

	putchar('\n');



    load_image( 0, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾉフ�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ鞫懶ｿｽ�ｿｽﾇみ搾ｿｽ�ｿｽ�ｿｽ */

//    //debug
//    for (i = 0; i < 10; ++i) {
//
//    	printf("[%s:%d] image[0][0][%d] => %d\n", __FILE__, __LINE__,
//    			i,
//    			image[0][0][i]);
//
//	}
//    printf("[%s:%d] image[0][0][0] => %d\n", __FILE__, __LINE__, image[0][0][0]);

    /****************************
	 *
	 * brighten
	 *
	 *****************************/
	printf("[%s:%d] brightening...\n", basename(__FILE__, '\\'), __LINE__);

	brighten( image_num, image_shift);
//	brighten( 0, 100);

    save_image( 0, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾌ画像�ｿｽ�ｿｽ�ｿｽt�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽﾉ出�ｿｽﾍゑｿｽ�ｿｽ�ｿｽ   */

}//s_2_1_brighten( int n, int shift )

void s_1_1_copyimage() {

	//debug
	int i;

	///////////////////////

	// p.6
	// C:\WORKS_2\WS\Eclipse_Luna\prog978-4-7856-3179-6 (nagao)\chap01

	///////////////////////
	printf("[%s:%d] starting... ==> s_1_1_copyimage\n", __FILE__, __LINE__);

	putchar('\n');



    load_image( 0, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾉフ�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ鞫懶ｿｽ�ｿｽﾇみ搾ｿｽ�ｿｽ�ｿｽ */

    //debug
    for (i = 0; i < 10; ++i) {

    	printf("[%s:%d] image[0][0][%d] => %d\n", __FILE__, __LINE__,
    			i,
    			image[0][0][i]);

	}
//    printf("[%s:%d] image[0][0][0] => %d\n", __FILE__, __LINE__, image[0][0][0]);


    save_image( 0, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾌ画像�ｿｽ�ｿｽ�ｿｽt�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽﾉ出�ｿｽﾍゑｿｽ�ｿｽ�ｿｽ   */

}//void s_1_1_copyimage

int main(int argc, char *argv[]) {

//	s_5__1_ColorHisto(argc, argv);

//	printf("[%s:%d] main => done\n", basename(__FILE__, '\\'), __LINE__);

	///////////////////////

	// operations

	///////////////////////
//	int image_num = 0;
//	int brighten_shift = 100;

	srand((unsigned)time(NULL));

	s_4_1_gets();

//	s_3_1_brighten( image_num, brighten_shift );

//	s_2_1_brighten( image_num, brighten_shift );
//	s_1_1_copyimage();



	///////////////////////

	// closing messages

	///////////////////////
//	printf("[%s:%d] processing...\n", __FILE__, __LINE__);

	printf("[%s:%d] yes, done\n", basename(__FILE__, '\\'), __LINE__);



	return 0;
}

void brighten( int n, int shift )
/* 画像 No.n を shift だけ明るくする */
{
    int x,y,brightness;

    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++){
            brightness = image[n][x][y] + shift;

            if ( brightness > 255 ) brightness = 255;

            if ( brightness < 0 ) brightness = 0;

            image[n][x][y] = brightness;
        }
}
