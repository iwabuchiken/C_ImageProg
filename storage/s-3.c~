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
void s_3__4(int, char **);
void s_3__1(void);
void s_3__3_Join(void);

///////////////////////////////
//
// functions
//
 ///////////////////////////////
void s_3__3_Join() {

//	char tokens[][10] = {
//
//			"abc",
//			"defgh",
//			"ijklmn"
//	};

	int numOf_Tokens = 4;

	char *tokens[4];
//	char *tokens[3];

	tokens[0] = malloc(sizeof(char) * 10);
	tokens[1] = malloc(sizeof(char) * 10);
	tokens[2] = malloc(sizeof(char) * 10);
	tokens[3] = malloc(sizeof(char) * 10);

	strcpy(tokens[0], "abc");
	strcpy(tokens[1], "defgh");
	strcpy(tokens[2], "ijklmno");
	strcpy(tokens[3], "pqr");

	char joint = ' ';
//	char joint = '_';
	char* str_Joint = "***";
//	char* str_Joint = "_";
//	char* str_Joint = "";

	printf("[%s:%d] strlen(str_Joint) = %d\n", basename(__FILE__, '\\'), __LINE__, strlen(str_Joint));


//	(char** tokens, const int numOf_Tokens, const char joint)
	char* str_Jointed = join(tokens, numOf_Tokens, str_Joint);
//	char* str_Jointed = join(tokens, numOf_Tokens, joint);

	printf("[%s:%d] str_Jointed => %s\n", basename(__FILE__, '\\'), __LINE__, str_Jointed);


	printf("[%s:%d] s_3__3_Join => done\n", basename(__FILE__, '\\'), __LINE__);


}//s_3__3_Join


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

void s_3__4(int argc, char *argv[]) {

	img *tmp1,*tmp2;

	// malloc
	tmp1=(img *)malloc(sizeof(img));
	tmp2=(img *)malloc(sizeof(img));

	printf("[%s:%d] img instances => malloc-ed\n", basename(__FILE__, '\\'), __LINE__);

	printf("[%s:%d] argv[0] = %s\n", basename(__FILE__, '\\'), __LINE__, argv[0]);



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
//	VMirror(tmp2,tmp1);
	int rot_num;

	if (argc < 2) {

		rot_num = 1;

	} else {

		rot_num = argc;

	}

	char time_label[20];

	printf("[%s:%d] time => %s\n",
					basename(__FILE__, '\\'),
					__LINE__,
					get_Time_Label__Now());
//					get_Time_Label(time_label));


	Rotate90(rot_num, tmp2,tmp1);

	char dst[50];

	sprintf(dst, "%s_%s.bmp", "rotate_90", get_Time_Label__Now());

	WriteBmp(dst,tmp2);
//	WriteBmp("rotate_90.bmp",tmp2);
	PrintBmpInfo(filename);
//	PrintBmpInfo("rotate90.bmp");


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

	s_3__4(argc, argv);
//	s_3__3_Join();
//	s_3__1();
//	D_1_s_1_strtok();
//	D_1_s_1_first();

	return 0;
}

