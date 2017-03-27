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

//ref http://www.ncad.co.jp/~komata/c-kouza14.htm
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
void rotate_image( int n1, int n2 );

void brighten( int n, int shift );

void lr_reverse( int n1, int n2 );

///////////////////////////////
//
// functions
// xxxx
//
///////////////////////////////

void s_11_1_1_rotate_images_multiple_times__V2() {

	char* time_label = get_Time_Label__Now();

	char fname_dst[40];

	char* dpath_dst = "images\\11_1";

	// dir path, time label,serial num, degrees
	char* fname_dst_skeleton = "%s\\s_11_1_1.i=lena.rotate-multiple.%s.(%d).%d-degrees.pgm";

	int image_num = 0;
//	int image_num_rotated = 1;

	char* file_name = "lena512.pgm";

	/****************************
	 *
	 * validate: directory
	 *
	 *****************************/
	//ref http://stackoverflow.com/questions/12510874/how-can-i-check-if-a-directory-exists answered Sep 20 '12 at 10:38
	//ref http://www.ncad.co.jp/~komata/c-kouza14.htm
	DIR* dir = opendir(dpath_dst);

	if (dir)
	{
	    /* Directory exists. */
	    closedir(dir);

	    //ref error number http://qiita.com/docokano/items/be0dec6243fc5a99006d
	    printf("[%s:%d] dir exists => '%s'; errno => %d\n",
	    		basename(__FILE__, '\\'), __LINE__,

				dpath_dst,
				errno);

	}

	else if (ENOENT == errno)

	{
	    /* Directory does not exist. */
		printf("[%s:%d] dir not exist; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		// create a dir
		int res = mkdir(dpath_dst);

		printf("[%s:%d] mkdir() result => %d\n", basename(__FILE__, '\\'), __LINE__, res);

		// result
		if (res == 0) {

			printf("[%s:%d] dir created => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

		} else {

			printf("[%s:%d] can't create dir! => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

			return;

		}

//		return;

	}
	else
	{
	    /* opendir() failed for some other reason. */
		printf("[%s:%d] unknown result; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		return;

	}

	/****************************
	 *
	 * load image
	 *
	 *****************************/
	load_image( image_num, file_name );

	/****************************
	 *
	 * rotate
	 *
	 *****************************/
	/****************************
	 *
	 * rotate
	 *
	 *****************************/
	int image_num_current = image_num;

	int image_num_final = image_num_current + 1;

//	int i;			// index for "for" loop


	image_num_current = 0;
	image_num_final = image_num_current + 1;
//	image_num_final = image_num_current + 1;

	// rotate
	rotate_image( image_num_current, image_num_final );

	//debug
	printf("[%s:%d] current = %d / final = %d\n",
			basename(__FILE__, '\\'), __LINE__,
			image_num_current, image_num_final);

	/****************************
	 *
	 * save image
	 *
	 *****************************/
	// "%s\\s_11_1_1.i=lena.rotate-multiple.%s.(%d).%d-degrees.pgm";
	sprintf(fname_dst,

				fname_dst_skeleton,
				dpath_dst,
				time_label,
				image_num_final,
				90 * image_num_final
	);

//	save_image( image_num_final, fname_dst );

	//report
	printf("[%s:%d] image saved => \"%s\"\n", basename(__FILE__, '\\'), __LINE__, fname_dst);

//	for (i = 0; i < 3; ++i) {
////	for (i = 1; i < 4; ++i) {
//
//		// assign numbers
//		image_num_current = i;
//		image_num_final = image_num_current + 1;
//
//		//debug
//		printf("[%s:%d] current = %d / final = %d\n",
//				basename(__FILE__, '\\'), __LINE__,
//				image_num_current, image_num_final);
//
////		image_num_final = image_num_current + 1;
////		image_num_final = image_num_current + i;
//
////		rotate_image( image_num_current, image_num_final );
//
////		// current --> update
////		image_num_current = image_num_final;
////
////		// final --> increment
////		image_num_final ++;
////
////		//debug
////		printf("[%s:%d] now, current = %d / final = %d\n",
////				basename(__FILE__, '\\'), __LINE__,
////				image_num_current, image_num_final);
//
//		/****************************
//		 *
//		 * save image
//		 *
//		 *****************************/
//		// "%s\\s_11_1_1.i=lena.rotate-multiple.%s.(%d).%d-degrees.pgm";
//		sprintf(fname_dst,
//
//					fname_dst_skeleton,
//					dpath_dst,
//					time_label,
//					i,
//					90 * i
//		);
//
//		save_image( image_num_final, fname_dst );
//
//		//report
//		printf("[%s:%d] image saved => \"%s\"\n", basename(__FILE__, '\\'), __LINE__, fname_dst);
//
//	}//for (i = 0; i < 3; ++i)

//	rotate_image( image_num, image_num_rotated );

	printf("[%s:%d] rotation => done\n", basename(__FILE__, '\\'), __LINE__);




}//void s_11_1_1_rotate_images_multiple_times__V2

void s_11_1_1_rotate_images_multiple_times() {

	char* time_label = get_Time_Label__Now();

	char fname_dst[40];

	char* dpath_dst = "images\\11_1";

	// dir path, time label,serial num, degrees
	char* fname_dst_skeleton = "%s\\s_11_1_1.i=lena.rotate-multiple.%s.(%d).%d-degrees.pgm";

	int image_num = 0;
//	int image_num_rotated = 1;

	char* file_name = "lena512.pgm";

	/****************************
	 *
	 * validate: directory
	 *
	 *****************************/
	//ref http://stackoverflow.com/questions/12510874/how-can-i-check-if-a-directory-exists answered Sep 20 '12 at 10:38
	//ref http://www.ncad.co.jp/~komata/c-kouza14.htm
	DIR* dir = opendir(dpath_dst);

	if (dir)
	{
	    /* Directory exists. */
	    closedir(dir);

	    //ref error number http://qiita.com/docokano/items/be0dec6243fc5a99006d
	    printf("[%s:%d] dir exists => '%s'; errno => %d\n",
	    		basename(__FILE__, '\\'), __LINE__,

				dpath_dst,
				errno);

	}

	else if (ENOENT == errno)

	{
	    /* Directory does not exist. */
		printf("[%s:%d] dir not exist; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		// create a dir
		int res = mkdir(dpath_dst);

		printf("[%s:%d] mkdir() result => %d\n", basename(__FILE__, '\\'), __LINE__, res);

		// result
		if (res == 0) {

			printf("[%s:%d] dir created => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

		} else {

			printf("[%s:%d] can't create dir! => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

			return;

		}

//		return;

	}
	else
	{
	    /* opendir() failed for some other reason. */
		printf("[%s:%d] unknown result; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		return;

	}

	/****************************
	 *
	 * load image
	 *
	 *****************************/
	load_image( image_num, file_name );

	/****************************
	 *
	 * rotate
	 *
	 *****************************/
	/****************************
	 *
	 * rotate
	 *
	 *****************************/
	int image_num_current = image_num;

	int image_num_final = image_num_current + 1;

	int i;			// index for "for" loop

	for (i = 0; i < 3; ++i) {
//	for (i = 1; i < 4; ++i) {

		// assign numbers
		image_num_current = i;
		image_num_final = image_num_current + 1;

		//debug
		printf("[%s:%d] current = %d / final = %d\n",
				basename(__FILE__, '\\'), __LINE__,
				image_num_current, image_num_final);

//		image_num_final = image_num_current + 1;
//		image_num_final = image_num_current + i;

//		rotate_image( image_num_current, image_num_final );

//		// current --> update
//		image_num_current = image_num_final;
//
//		// final --> increment
//		image_num_final ++;
//
//		//debug
//		printf("[%s:%d] now, current = %d / final = %d\n",
//				basename(__FILE__, '\\'), __LINE__,
//				image_num_current, image_num_final);

		/****************************
		 *
		 * save image
		 *
		 *****************************/
		// "%s\\s_11_1_1.i=lena.rotate-multiple.%s.(%d).%d-degrees.pgm";
		sprintf(fname_dst,

					fname_dst_skeleton,
					dpath_dst,
					time_label,
					i,
					90 * i
		);

		save_image( image_num_final, fname_dst );

		//report
		printf("[%s:%d] image saved => \"%s\"\n", basename(__FILE__, '\\'), __LINE__, fname_dst);

	}//for (i = 0; i < 3; ++i)

//	rotate_image( image_num, image_num_rotated );

	printf("[%s:%d] rotation => done\n", basename(__FILE__, '\\'), __LINE__);




}//s_11_1_1_rotate_images_multiple_times

void s_10_1_1_rotate_images() {

	char* time_label = get_Time_Label__Now();

	char fname_dst[40];

	char* dpath_dst = "images\\10_1";

	// dir path, time label,serial num, left/right, brightness
	char* fname_dst_skeleton = "%s\\s_10_1_1.i=lena.rotate.%s.pgm";

	int image_num = 0;
	int image_num_rotated = 1;

	char* file_name = "lena512.pgm";

	/****************************
	 *
	 * validate: directory
	 *
	 *****************************/
	//ref http://stackoverflow.com/questions/12510874/how-can-i-check-if-a-directory-exists answered Sep 20 '12 at 10:38
	//ref http://www.ncad.co.jp/~komata/c-kouza14.htm
	DIR* dir = opendir(dpath_dst);

	if (dir)
	{
	    /* Directory exists. */
	    closedir(dir);

	    //ref error number http://qiita.com/docokano/items/be0dec6243fc5a99006d
	    printf("[%s:%d] dir exists => '%s'; errno => %d\n",
	    		basename(__FILE__, '\\'), __LINE__,

				dpath_dst,
				errno);

	}

	else if (ENOENT == errno)

	{
	    /* Directory does not exist. */
		printf("[%s:%d] dir not exist; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		// create a dir
		int res = mkdir(dpath_dst);

		printf("[%s:%d] mkdir() result => %d\n", basename(__FILE__, '\\'), __LINE__, res);

		// result
		if (res == 0) {

			printf("[%s:%d] dir created => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

		} else {

			printf("[%s:%d] can't create dir! => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

			return;

		}

//		return;

	}
	else
	{
	    /* opendir() failed for some other reason. */
		printf("[%s:%d] unknown result; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		return;

	}

	/****************************
	 *
	 * load image
	 *
	 *****************************/
	load_image( image_num, file_name );


	/****************************
	 *
	 * rotate
	 *
	 *****************************/
	rotate_image( image_num, image_num_rotated );

	printf("[%s:%d] rotation => done\n", basename(__FILE__, '\\'), __LINE__);

	/****************************
	 *
	 * save image
	 *
	 *****************************/
	sprintf(fname_dst,

				fname_dst_skeleton,
				dpath_dst,
				time_label
	);

	save_image( image_num_rotated, fname_dst );

	//report
	printf("[%s:%d] image saved => \"%s\"\n", basename(__FILE__, '\\'), __LINE__, fname_dst);


}//void s_10_1_1_rotate_images()

void s_9_1_1_left_right_multiple_images() {

	/****************************
	 *
	 * prep
	 *
	 *****************************/
	int numof_pairs = 50;
//	int numof_pairs = 25;

	int i;	// for loop

	char* time_label = get_Time_Label__Now();

	char fname_dst[40];

	char* dpath_dst = "images\\9_1";

	// dir path, time label,serial num, left/right, brightness
	char* fname_dst_skeleton = "%s\\s_9_1_1.i=lena.left-right-reverse.%s.(%d).%s.%d.pgm";

	int image_num = 0;
	int image_num_reversed = 1;

	char* file_name = "lena512.pgm";

	/****************************
	 *
	 * validate: directory
	 *
	 *****************************/
	//ref http://stackoverflow.com/questions/9314586/c-faster-way-to-check-if-a-directory-exists answered Feb 16 '12 at 16:04
	//ref http://www.loose-info.com/main/memolist/c/lib_sys_stat_mkdir.html
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
	//ref http://www.ncad.co.jp/~komata/c-kouza14.htm
	DIR* dir = opendir(dpath_dst);

	if (dir)
	{
	    /* Directory exists. */
	    closedir(dir);

	    //ref error number http://qiita.com/docokano/items/be0dec6243fc5a99006d
	    printf("[%s:%d] dir exists => '%s'; errno => %d\n",
	    		basename(__FILE__, '\\'), __LINE__,

				dpath_dst,
				errno);

//	    return;

	}

	else if (ENOENT == errno)

	{
	    /* Directory does not exist. */
		printf("[%s:%d] dir not exist; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		// create a dir
		int res = mkdir(dpath_dst);

		printf("[%s:%d] mkdir() result => %d\n", basename(__FILE__, '\\'), __LINE__, res);

		// result
		if (res == 0) {

			printf("[%s:%d] dir created => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

		} else {

			printf("[%s:%d] can't create dir! => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

			return;

		}

//		return;

	}
	else
	{
	    /* opendir() failed for some other reason. */
		printf("[%s:%d] unknown result; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		return;

	}

	/********************************************************
	 *
	 * generate images
	 *
	*********************************************************/
	int rnd_num;
	int plus_minus;

	int rnd_start	= 1;
	int rnd_end		= 40;
//	int rnd_end		= 20;
//	int rnd_end		= 10;

	int image_shift = 0;

	int unit = 5;		// (1 unit) * (random integer) --> changes in brightness
//	int unit = 10;		// (1 unit) * (random integer) --> changes in brightness

	for (i = 0; i < numof_pairs * 2; i = i + 2) {
//	for (i = 0; i < numof_pairs; ++i) {

		/****************************
		 *
		 * load image
		 *
		 *****************************/
		load_image( image_num, file_name );

		/****************************
		 *
		 * non-reverse image
		 *
		 *****************************/
		rnd_num = get_random_integer(rnd_start, rnd_end, time(NULL));

		plus_minus = get_random_integer(1, 2, time(NULL));

    	// convert
    	if (plus_minus == 1) {

    		plus_minus = 1;

		} else {

			plus_minus = -1;

		}

    	image_shift = unit * rnd_num * plus_minus;

		// file name
	//	"%s\\s_9_1_1.i=lena.left-right-reverse.%s.(%d).%s.%d.pgm";
	//	dir path, time label,serial num, left/right, brightness
		sprintf(fname_dst,
					fname_dst_skeleton,
					dpath_dst,
					time_label,
					(i + 1),
					"orig",
					image_shift
		);

		//debug
		printf("[%s:%d] fname_dst => \"%s\"\n", basename(__FILE__, '\\'), __LINE__, fname_dst);

		// brighten up/down
		brighten( image_num, image_shift);

		// output image
		save_image( image_num, fname_dst );

		/****************************
		 *
		 * reverse image
		 *
		 *****************************/
		lr_reverse( image_num, image_num_reversed );

		// dst file name
		rnd_num = get_random_integer(rnd_start, rnd_end, time(NULL));

		plus_minus = get_random_integer(1, 2, time(NULL));

    	// convert
    	if (plus_minus == 1) {

    		plus_minus = 1;

		} else {

			plus_minus = -1;

		}

    	image_shift = unit * rnd_num * plus_minus;

		// file name
	//	"%s\\s_9_1_1.i=lena.left-right-reverse.%s.(%d).%s.%d.pgm";
	//	dir path, time label,serial num, left/right, brightness
		sprintf(fname_dst,
					fname_dst_skeleton,
					dpath_dst,
					time_label,
					(i + 2),
					"reverse",
					image_shift
		);

		//debug
		printf("[%s:%d] fname_dst => \"%s\"\n", basename(__FILE__, '\\'), __LINE__, fname_dst);

		// output image
		save_image( image_num_reversed, fname_dst );


	}//for (i = 0; i < numof_pairs; ++i)




}//s_9_1_1_left_right_multiple_images



void s_8_1_1_left_right() {

	/****************************
	 *
	 * prep
	 *
	 *****************************/
	char* time_label = get_Time_Label__Now();

	char fname_dst[40];

//	char* dpath_dst = "8_1";
	char* dpath_dst = "images\\8_1";

	char* fname_dst_skeleton = "%s\\s_8_1_1.i=lena.left-right-reverse.%s.pgm";
//	char* fname_dst_skeleton = "images\\%s\\s_8_1_1.i=lena.left-right-reverse.%s.pgm";
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
	//ref http://www.loose-info.com/main/memolist/c/lib_sys_stat_mkdir.html
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
	//ref http://www.ncad.co.jp/~komata/c-kouza14.htm
	DIR* dir = opendir(dpath_dst);

	if (dir)
	{
	    /* Directory exists. */
	    closedir(dir);

	    //ref error number http://qiita.com/docokano/items/be0dec6243fc5a99006d
	    printf("[%s:%d] dir exists => '%s'; errno => %d\n",
	    		basename(__FILE__, '\\'), __LINE__,

				dpath_dst,
				errno);

//	    return;

	}

	else if (ENOENT == errno)

	{
	    /* Directory does not exist. */
		printf("[%s:%d] dir not exist; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		// create a dir
		int res = mkdir(dpath_dst);

		printf("[%s:%d] mkdir() result => %d\n", basename(__FILE__, '\\'), __LINE__, res);

		// result
		if (res == 0) {

			printf("[%s:%d] dir created => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

		} else {

			printf("[%s:%d] can't create dir! => '%s'\n", basename(__FILE__, '\\'), __LINE__, dpath_dst);

			return;

		}

//		return;

	}
	else
	{
	    /* opendir() failed for some other reason. */
		printf("[%s:%d] unknown result; errno => %d\n", basename(__FILE__, '\\'), __LINE__, errno);

		return;

	}


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

	printf("[%s:%d] image saved => \"%s\"\n", basename(__FILE__, '\\'), __LINE__, fname_dst);
//	printf("[%s:%d] image saved => '%s'\n", basename(__FILE__, '\\'), __LINE__, fname_dst);


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

void rotate_image( int n1, int n2 )
/* �摜 No.n1 ��90�x��]�����ĉ摜 No.n2 �� */
{
    int x,y;

    width[n2]=height[n1];  height[n2]=width[n1];
    /* ���E���] */
    for(y=0;y<height[n1];y++){
        for(x=0;x<width[n1];x++){
            image[n2][y][height[n2]-x] = image[n1][x][y];
        }
    }
}

int main(int argc, char *argv[]) {

	/****************************
	 *
	 * prep
	 *
	 *****************************/
	srand((unsigned)time(NULL));

	///////////////////////

	// operations

	///////////////////////
	s_11_1_1_rotate_images_multiple_times__V2();

//	s_11_1_1_rotate_images_multiple_times();

//	s_10_1_1_rotate_images();

//	s_9_1_1_left_right_multiple_images();

//	s_8_1_1_left_right();


	///////////////////////

	// closing messages

	///////////////////////
//	printf("[%s:%d] processing...\n", __FILE__, __LINE__);

	printf("[%s:%d] yes, done\n", basename(__FILE__, '\\'), __LINE__);



	return 0;
}

