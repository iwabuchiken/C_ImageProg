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

	img *tmp1,*tmp2, *tmp3;
//	img *tmp1,*tmp2;

	// malloc
	tmp1=(img *)malloc(sizeof(img));
	tmp2=(img *)malloc(sizeof(img));
	tmp3=(img *)malloc(sizeof(img));

//	printf("[%s:%d] img instances => malloc-ed\n", basename(__FILE__, '\\'), __LINE__);

//	printf("[%s:%d] argv[0] = %s\n", basename(__FILE__, '\\'), __LINE__, argv[0]);



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
	// VMirror
	//
	 ///////////////////////////////
	VMirror(tmp2,tmp1);
	VMirror(tmp3,tmp1);

	char dst[100];

	char time_Label[20];

	sprintf(time_Label, "%s", get_Time_Label__Now());

	sprintf(dst,
				"C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\%s_%s_VMirror.bmp",
				"s-4", time_Label);

	WriteBmp(dst,tmp2);
//	PrintBmpInfo(filename);
//	PrintBmpInfo("rotate90.bmp");

	/****************************
	 * draw line
	 *****************************/
//	enum Col col;
//
//	if (argc > 1) {
//
//
//
//	} else {
//
//	}

	enum Col col = GREEN;
//	enum Col col = BLUE;
	int result = DrawBand(tmp3, tmp2, col);
//	int result = DrawBand(tmp3, tmp2);

	sprintf(dst,
			"C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\%s_%s__line.bmp",
			"s-4", time_Label);

	WriteBmp(dst,tmp3);
//	WriteBmp(dst,tmp2);

	printf("[%s:%d] DrawBand => result = %d\n", basename(__FILE__, '\\'), __LINE__, result);

//	///////////////////////////////
//	//
//	// rotate
//	//
//	 ///////////////////////////////
//	int rot_num;
//
//	if (argc < 2) {
//
//		rot_num = 1;
//
//	} else {
//
//		rot_num = argc;
//
//	}

//	Rotate90(rot_num, tmp2,tmp1);
//
//	Rotate90(rot_num, tmp3,tmp1);
//
//	char dst[100];
////	char dst[50];
//
//	char time_Label[20];
//
//	sprintf(time_Label, "%s", get_Time_Label__Now());
//
//	sprintf(dst,
//				"C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\%s_%s_Rotate.bmp",
////				"C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\%s_%s.bmp",
//				"rotate_90", time_Label);
////				"rotate_90", get_Time_Label__Now());
//
//	WriteBmp(dst,tmp2);
////	WriteBmp("rotate_90.bmp",tmp2);
//	PrintBmpInfo(filename);
////	PrintBmpInfo("rotate90.bmp");
//
//	///////////////////////////////
//	//
//	// VMirror
//	//
//	 ///////////////////////////////
//	VMirror(tmp3,tmp2);
//
//	sprintf(dst,
//			"C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\%s_%s__VMirror.bmp",
//			"rotate_90", time_Label);
//
////	int result = DrawBand(tmp2);
//
//	WriteBmp(dst,tmp3);
//
//	printf("[%s:%d] VMirror => done\n", basename(__FILE__, '\\'), __LINE__);
//
//	///////////////////////////////
//	//
//	// draw line
//	//
//	 ///////////////////////////////
//	sprintf(dst,
//			"C:\\WORKS\\WS\\Eclipse_Luna\\C_ImageProg\\main\\s-4\\%s_%s__line.bmp",
//			"rotate_90", time_Label);
//
//	int result = DrawBand(tmp2);
//
//	WriteBmp(dst,tmp2);
//
//	printf("[%s:%d] DrawBand => result = %d\n", basename(__FILE__, '\\'), __LINE__, result);


	///////////////////////////////
	//
	// free
	//
	 ///////////////////////////////
	free(tmp1);
	free(tmp2);
	free(tmp3);


	printf("[%s:%d] s_4__1_DrawLine => done\n", basename(__FILE__, '\\'), __LINE__);

}//s_4__1_DrawLine

int main(int argc, char *argv[]) {

	s_4__1_DrawLine(argc, argv);

	printf("[%s:%d] main => done\n", basename(__FILE__, '\\'), __LINE__);

	return 0;
}

