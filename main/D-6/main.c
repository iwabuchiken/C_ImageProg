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

file name: lena512.pgm

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

int get_lowest_brightness(int image_num, char* file_name);


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

void s_5_1_3_brighten_down() {

	/****************************
	 *
	 * get the diff: lowest to 255
	 *
	 *****************************/
//	int image_num = 0;
//
//	char* file_name = "lena512.pgm";
//
//	int bright_lowest = get_lowest_brightness(image_num, file_name);
//
//	int max_bright = 255;
//
//	int diff = max_bright - bright_lowest;
//
//	printf("[%s:%d] lowest => %d / diff => %d\n",
//			basename(__FILE__, '\\'), __LINE__, bright_lowest, diff);

	/****************************
	 *
	 * prep: number of files needed
	 *
	 *****************************/
    int bright_tick = 1;
//    int bright_tick = 10;

    char fname_dst[40];

    //debug
    int diff = 25;
    diff = 25;

    int numof_images = diff / bright_tick;

	int image_shift = 0;

	char* time_label = get_Time_Label__Now();

//	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten.+%d.pgm",
//
//			time_label, image_shift);

	printf("[%s:%d] images needed: tick = %d / files = %d\n",
			basename(__FILE__, '\\'), __LINE__, bright_tick, numof_images);

	/****************************
	 *
	 * load image
	 *
	 *****************************/
	int image_num = 0;

	char* file_name = "lena512.pgm";

    load_image( image_num, file_name ); /* �ｿｽ鞫廸o.0�ｿｽﾉフ�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ鞫懶ｿｽ�ｿｽﾇみ搾ｿｽ�ｿｽ�ｿｽ */

	/****************************
	 *
	 * auto-generate
	 *
	 * 	==> see: void s_4_1_3_brighten_auto_generate()
	 *
	 *****************************/
	int i;

    for (i = 1; i < numof_images + 1; ++i) {

    	image_shift = bright_tick * i * (-1);

    	brighten( image_num, image_shift);

    	// file name
//    	sprintf(fname_dst, "images\\s_4_1_3.brighten.+%d.%s.pgm",
//    	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten.minus.+%d.pgm",
    	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten.minus.reverse.%d.pgm",
//    	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten_minus.%d.pgm",
//    	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten_minus-%d.pgm",
//    	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten.minus-%d.pgm",
//    	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten.%d.pgm",
//    	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten.+%d.pgm",

    				time_label, numof_images + 1 - abs(image_shift));
//    				time_label, image_shift);

    	printf("[%s:%d] file name => '%s'\n", basename(__FILE__, '\\'), __LINE__, fname_dst);

        save_image( image_num, fname_dst ); /* �ｿｽ鞫廸o.0�ｿｽﾌ画像�ｿｽ�ｿｽ�ｿｽt�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽﾉ出�ｿｽﾍゑｿｽ�ｿｽ�ｿｽ   */

	}//for (i = 0; i < numof_images; ++i)

}//void s_5_1_3_brighten_down

void s_5_1_1_lowest_brightness() {

	/****************************
	 *
	 * get the diff: lowest to 255
	 *
	 *****************************/
	int image_num = 0;
	char* file_name = "lena512.pgm";

	int bright_lowest = get_lowest_brightness(image_num, file_name);

	int max_bright = 255;

	int diff = max_bright - bright_lowest;

	printf("[%s:%d] lowest => %d / diff => %d\n",
			basename(__FILE__, '\\'), __LINE__, bright_lowest, diff);

	/****************************
	 *
	 * prep: number of files needed
	 *
	 *****************************/
    int bright_tick = 1;
//    int bright_tick = 10;

    char fname_dst[40];

    //debug
    diff = 25;

    int numof_images = diff / bright_tick;

	int image_shift = 0;

	char* time_label = get_Time_Label__Now();

//	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten.+%d.pgm",
//
//			time_label, image_shift);

	printf("[%s:%d] images needed: tick = %d / files = %d\n",
			basename(__FILE__, '\\'), __LINE__, bright_tick, numof_images);

	/****************************
	 *
	 * auto-generate
	 *
	 * 	==> see: void s_4_1_3_brighten_auto_generate()
	 *
	 *****************************/
	int i;

    for (i = 1; i < numof_images + 1; ++i) {

    	image_shift = bright_tick * i;

    	brighten( image_num, image_shift);

    	// file name
//    	sprintf(fname_dst, "images\\s_4_1_3.brighten.+%d.%s.pgm",
    	sprintf(fname_dst, "images\\s_5_1_1.%s.i=lena.brighten.+%d.pgm",

    				time_label, image_shift);

    	printf("[%s:%d] file name => '%s'\n", basename(__FILE__, '\\'), __LINE__, fname_dst);

        save_image( image_num, fname_dst ); /* �ｿｽ鞫廸o.0�ｿｽﾌ画像�ｿｽ�ｿｽ�ｿｽt�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽﾉ出�ｿｽﾍゑｿｽ�ｿｽ�ｿｽ   */

	}//for (i = 0; i < numof_images; ++i)

}//void s_5_1_1_lowest_brightness

int get_lowest_brightness(int image_num, char* file_name) {

	/****************************
	 *
	 * load image
	 *
	 *****************************/
	load_image( image_num, file_name );

	printf("[%s:%d] image loaded => %s (w = %d / h = %d)\n",
			basename(__FILE__, '\\'), __LINE__, file_name, width[0], height[0]);

	/****************************
	 *
	 * lowest brightness
	 *
	 *****************************/
	int x, y;
	int x_curr = 0, y_curr = 0;

	int n = image_num;

//	int counter = 0;
//	int limit = 20;

//	int bright_prev = 0;
	int bright_curr = image[image_num][x_curr][y_curr];
//	int bright_curr = image[image_num][0][0];

	//debug
	printf("[%s:%d] bright_curr = %d\n", basename(__FILE__, '\\'), __LINE__, bright_curr);

//	int flag_break = 0;

    for(y=0;y<height[n];y++) {

        for(x=0;x<width[n];x++) {

//            image[n][x][y] = (unsigned char)fgetc( fp );
//        	printf("[%s:%d] image[%d][%d][%d] = %d\n",
//        			basename(__FILE__, '\\'), __LINE__,
//					image_num, x, y, image[image_num][x][y]);

        	// calculate: brightness
//        	bright_prev = bright_curr;

        	/****************************
			 *
			 * if the current brightness is lower than the stored one
			 * 		=> set the current one to the stored
			 *
			 *****************************/
//        	if (bright_curr < image[image_num][x][y]) {
        	if (bright_curr > image[image_num][x][y]) {

				bright_curr = image[image_num][x][y];

				x_curr = x; y_curr = y;

			}

//        	//debug
//        	counter ++;
//
//            //debug
//        	if (counter > limit) {
//
//        		flag_break = 1;
//
//        		break;
//
//        	}

        }//for(x=0;x<width[n];x++)

//        //debug
//        if(flag_break == 1) {
//
//        	printf("[%s:%d] reached the limit of %d (x = %d / y = %d). break\n",
//        			basename(__FILE__, '\\'), __LINE__, counter, x, y);
//
//        	break;
//
//        }

    }//for(y=0;y<height[n];y++)

    //debug
    printf("[%s:%d] bright_curr is now => %d (at x = %d / y = %d)\n",
    		basename(__FILE__, '\\'), __LINE__, bright_curr, x_curr, y_curr);

	return bright_curr;
//	return 0;

}//get_lowest_brightness(int image_num, char* file_name)

/*
 * 	date: 2017/03/15 18:21:53
 *
 * <usage>
 * 	1. run the program
 * 	2. enter the file name => "lena512.pgm" (at the root directory)
 * 	3. then --> files will be auto generated
 *
 * <variables>
 * 	numof_images	number of pgm files to be generated
 *	bright_tick		the value by which the brightness changes
 */
void s_4_1_3_brighten_auto_generate() {

	/********************************************************
	 *
	 * brighten
	 *
	*********************************************************/
	/****************************
	 *
	 * load image
	 *
	 *****************************/
    int image_num = 0;

    load_image( image_num, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾉフ�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ鞫懶ｿｽ�ｿｽﾇみ搾ｿｽ�ｿｽ�ｿｽ */

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
    int i;

    int numof_images = 20;

    char fname_dst[40];

//    int brightness_diff;

    int bright_tick = 1;
//    int bright_tick = 2;

	int image_shift = 0;

	char* time_label = get_Time_Label__Now();

	printf("[%s:%d] brightening...\n", basename(__FILE__, '\\'), __LINE__);

    for (i = 1; i < numof_images + 1; ++i) {

    	image_shift = bright_tick * i;
//    	brightness_diff = image_shift +  bright_tick * i;

    	brighten( image_num, image_shift);
//    	brighten( image_num, brightness_diff);
//    	brighten( image_num, image_shift * i);
    //	brighten( 0, 100);

    	// file name
//    	sprintf(fname_dst, "s_4_1_3.brighten.+%d.%s.pgm",
//    	sprintf(fname_dst, "images\\s_4_1_3.brighten.+%d.%s.pgm",
    	sprintf(fname_dst, "images\\s_4_1_3.%s.i=lena.brighten.+%d.pgm",

    			time_label, image_shift);
//    			image_shift * i, get_Time_Label__Now());

    	printf("[%s:%d] file name => '%s'\n", basename(__FILE__, '\\'), __LINE__, fname_dst);

        save_image( image_num, fname_dst ); /* �ｿｽ鞫廸o.0�ｿｽﾌ画像�ｿｽ�ｿｽ�ｿｽt�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽﾉ出�ｿｽﾍゑｿｽ�ｿｽ�ｿｽ   */
//        save_image( image_num, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾌ画像�ｿｽ�ｿｽ�ｿｽt�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽﾉ出�ｿｽﾍゑｿｽ�ｿｽ�ｿｽ   */

	}//for (i = 0; i < numof_images; ++i)


//	brighten( image_num, image_shift);
////	brighten( 0, 100);
//
//    save_image( 0, "" ); /* �ｿｽ鞫廸o.0�ｿｽﾌ画像�ｿｽ�ｿｽ�ｿｽt�ｿｽ@�ｿｽC�ｿｽ�ｿｽ�ｿｽﾉ出�ｿｽﾍゑｿｽ�ｿｽ�ｿｽ   */

}//void s_4_1_3_brighten_auto_generate

void s_4_1_2_brighten() {

	//ref http://www1.cts.ne.jp/~clab/hsample/IO/IO16.html
    char name[21];

    int result;

    /****************************
	 *
	 * number
	 *
	 *****************************/
    printf("number?:\t");
//    printf("お名前を入力して下さい\t");
    gets(name);
    printf("\nthe number is: '%s'\n", name);

    // validate
    result = is_numeric(name);

    if (result == 1) {

    	printf("[%s:%d] it's a number => '%s'\n", basename(__FILE__, '\\'), __LINE__, name);

	} else {

		printf("[%s:%d] it's not a number => '%s'\n", basename(__FILE__, '\\'), __LINE__, name);

		return;

	}

    /****************************
	 *
	 * brighten
	 *
	 *****************************/
    int image_num = 0;

	int image_shift = atoi(name);


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

}//void s_4_1_2_brighten


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

	s_5_1_3_brighten_down();
//	s_5_1_1_lowest_brightness();
//	s_4_1_3_brighten_auto_generate();
//	s_4_1_2_brighten();
//	s_4_1_gets();

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

void brighten_down( int n, int shift )
/* 画像 No.n を shift だけ明るくする */
{
    int x,y,brightness;

    for(y=0;y<height[n];y++)

        for(x=0;x<width[n];x++){

            brightness = image[n][x][y] - shift;
//            brightness = image[n][x][y] + shift;

            if ( brightness > 255 ) brightness = 255;

            if ( brightness < 0 ) brightness = 0;

            image[n][x][y] = brightness;

        }

}//void brighten_down( int n, int shift )
