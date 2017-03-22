/*
 * 	file: C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\main\D-6\main.c
 * 	date: 2017/03/10 18:32:51
 * 	update: 2017/03/22 16:20:24
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
//#define UTILS_H_
#include "../../utils/utils.h"
#endif

#ifndef PGMLIB_H_
//#define PGMLIB_H_
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

#ifndef ASSERT_H_
#define ASSERT_H_
#include <assert.h>
#endif

//ref http://stackoverflow.com/questions/9314586/c-faster-way-to-check-if-a-directory-exists answered Feb 16 '12 at 16:04
#ifndef ERRNO_H_
#define ERRNO_H_
#include <errno.h>
#endif

#ifndef SYSSTAT_H_
#define SYSSTAT_H_
#include <sys/stat.h>
#endif

#ifndef DIRENT_H_
#define DIRENT_H_
#include <dirent.h>
#endif

//#ifndef CTYPE_H_
//#define CTYPE_H_
//#include <ctype.h>
//#endif

#ifndef MAIN_H_
#define MAIN_H_
#include "main.h"
#endif

//#ifndef MAIN_H_
//#define MAIN_H_
//#include "main.h"
//#endif

///////////////////////////////
//
// protos
//
 ///////////////////////////////

void lr_reverse( int n1, int n2 );

///////////////////////////////
//
// functions
// xxxx
//
///////////////////////////////
void s_8_1_1_left_right() {

	/****************************
	 *
	 * prep
	 *
	 *****************************/
	char* time_label = get_Time_Label__Now();

	char fname_dst[40];

	char* dpath_dst = "8_1";
//	char* dpath_dst = "images\\8_1";

	char* fname_dst_skeleton = "images\\%s\\s_8_1_1.i=lena.left-right-reverse.%s.pgm";
//	char* fname_dst_skeleton = "images\\s_8_1_1.i=lena.left-right-reverse.%s.pgm";

	int image_num = 0;
	int image_num_reversed = 1;

	char* file_name = "lena512.pgm";

	/****************************
	 *
	 * validate: directory
	 *
	 *****************************/
	//ref http://stackoverflow.com/questions/9314586/c-faster-way-to-check-if-a-directory-exists answered Feb 16 '12 at 16:04
	//	if (mkdir(dpath_dst)) {
//
//		printf("[%s:%d] dir created => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);
//
//	} else {
//
//		printf("[%s:%d] can't create the directory => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);
//
//		return;
//
//	}

	//ref http://stackoverflow.com/questions/12510874/how-can-i-check-if-a-directory-exists answered Sep 20 '12 at 10:38
	DIR* dir = opendir("mydir");
aa


	/****************************
	 *
	 * load image
	 *
	 *****************************/
	// load image
	load_image( image_num, file_name );

	/****************************
	 *
	 * reverse
	 *
	 *****************************/
	lr_reverse( image_num, image_num_reversed );

	printf("[%s:%d] lr_reverse => done\n", basename(__FILE__, '\\'), __LINE__);


	// file name
	sprintf(fname_dst,
				fname_dst_skeleton,
				dpath_dst,
				time_label);

	// save image
	save_image(image_num_reversed, fname_dst);

	printf("[%s:%d] image saved => '%s'\n", basename(__FILE__, '\\'), __LINE__, fname_dst);


}//void s_8_1_1_left_right


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

void lr_reverse( int n1, int n2 )
/* �摜 No.n1 �����E���]�����ĉ摜 No.n2 �� */
{
    int x,y;

    width[n2]=width[n1];  height[n2]=height[n1];
    /* ���E���] */
    for(y=0;y<height[n1];y++)
        for(x=0;x<width[n1];x++)
            image[n2][x][y] = image[n1][width[n1]-1-x][y];
}

int main(int argc, char *argv[]) {

	///////////////////////

	// operations

	///////////////////////
	s_8_1_1_left_right();


	///////////////////////

	// closing messages

	///////////////////////
//	printf("[%s:%d] processing...\n", __FILE__, __LINE__);

	printf("[%s:%d] yes, done\n", basename(__FILE__, '\\'), __LINE__);



	return 0;
}

