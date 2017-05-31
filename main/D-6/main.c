/*
 * 	file: C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\main\D-6\main.c
 * 	date: 2017/03/10 18:32:51
 * 	update: 2017/03/22 16:20:24
 *
 * 	<usage>
pushd C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\main\D-6\
gcc main.c -o main.exe
main.exe
a.exe

gcc color_histogram.c -o color_histogram.exe


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

long int hist[256][3]; /* ヒストグラム用配列 */

/********************************************************
 *
 * protos
 *
*********************************************************/
void reverse_color( int n );
void make_col_image( int n, int work );
void make_histogram_image( int n1, int n2, int h );

/********************************************************
 *
 * functions
 *
*********************************************************/


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

    make_histogram_image( 0, 1, 256 );

//
////    reverse_color( 0 );        /* カラー画像をネガにする */
//    make_col_image_Omit_One( 0, 1 );
////    make_col_image( 0, 1 );
//
    save_color_image( 1, "" );   /* 画像No.0 → ファイル */
//    save_color_image( 0, "" );   /* 画像No.0 → ファイル */
////    return 0;



	///////////////////////
	// closing messages
	///////////////////////
//	printf("[%s:%d] processing...\n", __FILE__, __LINE__);

	printf("[%s:%d] yes, done\n", basename(__FILE__, '\\'), __LINE__);
//	printf("[%s:%d] done\n", __FILE__, __LINE__);


	return 0;

}

void make_histogram_image( int n1, int n2, int h )
/* 画像No.n1のカラーヒストグラムを画像化(横256×縦h画素) */
/* して画像No.n2に記録する */
{
    int i,j,x,y;  /* 制御変数 */
    long int max; /* 最大頻度 */
    int takasa;   /* 各階調値の頻度の高さ */

    /* ヒストグラムの初期化 */
    for(i=0;i<256;i++) for(j=0;j<3;j++) hist[i][j] = 0;
    /* 画像をラスタスキャンしてグラフを作る */
    for(y=0;y<height[n1];y++)
        for(x=0;x<width[n1];x++)
            for(j=0;j<3;j++)
                hist[ image[n1][x][y][j] ][j]++; /* 累積を１増加 */
    /* 画像の縦・横の値の入力と初期化 */
    width[n2]=256;  height[n2]=h;  init_color_image( n2, 0, 0, 0 );
    /* ヒストグラムの最大頻度maxを求める */
    max=0;
    for(i=0;i<256;i++)
        for(j=0;j<3;j++)
            if ( hist[i][j] > max ) max = hist[i][j];
    /* 縦幅をh画素に正規化しながら画像に値を代入 */
    for(i=0;i<3;i++)
        for(x=0;x<width[n2];x++){
            takasa = (int)( h / (double)max * hist[x][i] );
            if ( takasa > h ) takasa = h;
            for(y=0;y<h;y++)
                if ( y < takasa ) image[n2][x][h-1-y][i] = 255;
        }

    //debug
    printf("[%s:%d] make_histogram_image => done\n", __FILE__, __LINE__);



}
