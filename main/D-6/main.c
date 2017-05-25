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

//#ifndef BMP_H_
////#define BMP_H_
//#include  "bmp.h~"
//#endif

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

//#ifndef MAIN_H_
//#define MAIN_H_
//#include "main.h~"
//#endif

#ifndef UTILS_H_
#include "include/utils.h"
//#include "utils.h"
#endif

//#ifndef PGMLIB_H_
//#define PGMLIB_H_
////#include "include/pgmlib.h.orig"
//#include "include/pgmlib.h"
//#endif

#ifndef PPMLIB_H_
#define PPMLIB_H_
//#include "include/pgmlib.h.orig"
#include "include/ppmlib.h"
#endif

void reverse_color( int n );
void make_col_image( int n, int work );

void make_col_image( int n, int work )
/* 画像No.nを色分解して保存する */
{
    int i,x,y,col;
    char iro[3][10]={"Red","Green","Blue"};

    for(i=0;i<3;i++){
        copy_color_image( n, work );
        for(y=0;y<height[n];y++)
            for(x=0;x<width[n];x++)
                for(col=0;col<3;col++)
                    if (col!=i) image[work][x][y][col]=0;
        printf("save %s elements in the image\n",iro[i]);
//        printf("%s成分の画像を保存します\n",iro[i]);
        save_color_image( work, "" );
    }
}

void make_col_image_Omit_One( int n, int work )
/* 画像No.nを色分解して保存する */
{
    int i,x,y,col;
    char iro[3][10]={"Red","Green","Blue"};

    for(i=0;i<3;i++){
        copy_color_image( n, work );
        for(y=0;y<height[n];y++)
            for(x=0;x<width[n];x++)
                for(col=0;col<3;col++)
                    if (col ==i) image[work][x][y][col]=0;
//                    if (col!=i) image[work][x][y][col]=0;
        printf("save except %s elements in the image\n",iro[i]);
//        printf("%s成分の画像を保存します\n",iro[i]);
        save_color_image( work, "" );
    }

}//void make_col_image_Omit_One( int n, int work )

void reverse_color( int n )
/* 画像No.nのカラー画像の色を反転させる */
{
    int x,y,col;

    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++)
            for(col=0;col<3;col++)
                image[n][x][y][col] = 255 - image[n][x][y][col];
}

int main(int argc, char *argv[]) {

	/********************************************************
	 *
	 * operations
	 *
	*********************************************************/
    load_color_image( 0, "" );   /* ファイル → 画像No.0 */

//    reverse_color( 0 );        /* カラー画像をネガにする */
    make_col_image_Omit_One( 0, 1 );
//    make_col_image( 0, 1 );

    save_color_image( 0, "" );   /* 画像No.0 → ファイル */
//    return 0;



	///////////////////////
	// closing messages
	///////////////////////
//	printf("[%s:%d] processing...\n", __FILE__, __LINE__);

	printf("[%s:%d] yes, done\n", basename(__FILE__, '\\'), __LINE__);
//	printf("[%s:%d] done\n", __FILE__, __LINE__);


	return 0;

}

