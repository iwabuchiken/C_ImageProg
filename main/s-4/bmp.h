/*****************************************************************************/
/*                                                                           */

/*     bmp.h: bmp �ե��������Υ饤�֥��Τ���Υإå��ե�����             */
/*                                                                           */
/*             Kazutoshi Ando (Shizuoka Univ.)                               */
/*                                                                           */
/*                  Ver. 2004.08.18                                          */
/*                  Ver. 2004.08.17                                          */
/*                  Ver. 2003.11.04                                          */
/*                                                                           */
/*****************************************************************************/

#ifndef BMP_H_
#define BMP_H_

#ifndef STDIO_H_
#define STDIO_H_
#include <stdio.h>
#endif

#ifndef STDLIB_H_
#define STDLIB_H_
#include <stdlib.h>
#endif

#ifndef STRING_H_
#define STRING_H_
#include <string.h>
#endif
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

#define HEADERSIZE   54               /* �إå��Υ����� 54 = 14 + 40         */
#define PALLETSIZE 1024               /* �ѥ�åȤΥ�����                    */
#define MAXWIDTH   1000               /* ��(pixel)�ξ��                     */
#define MAXHEIGHT  1000               /* �⤵(pixel) �ξ��                  */

/* x �� y �θ򴹤Τ���� �ޥ���ؿ� */
#define SWAP(x,y) {typeof(x) temp; temp=x; x=y; y=temp;}

unsigned char Bmp_headbuf[HEADERSIZE];/* �إå����Ǽ���뤿����ѿ�          */
unsigned char Bmp_Pallet[PALLETSIZE]; /* ���顼�ѥ�åȤ��Ǽ                */

char Bmp_type[2];                     /* �ե����륿���� "BM"                 */
unsigned long Bmp_size;               /* bmp�ե�����Υ����� (�Х���)        */
unsigned int Bmp_info_header_size; /* ����إå��Υ����� = 40             */
unsigned int Bmp_header_size;      /* �إå������� = 54*/
long Bmp_height;                      /* �⤵ (�ԥ�����)                     */
long Bmp_width;                       /* ��   (�ԥ�����)                     */
unsigned short Bmp_planes;          /* �ץ졼��� ��� 1                   */
unsigned short Bmp_color;          /* �� (�ӥå�)     24                  */
long Bmp_comp;                        /* ������ˡ         0                  */
long Bmp_image_size;                  /* ������ʬ�Υե����륵���� (�Х���)   */
long Bmp_xppm;                        /* ��ʿ������ (ppm)                    */
long Bmp_yppm;                        /* ��ľ������ (ppm)                    */

typedef struct {                      /* 1�ԥ����뤢����������ĤγƵ���     */
  unsigned char r;
  unsigned char g;
  unsigned char b;
} color;

typedef struct {
  long height;
  long width;
  color data[MAXHEIGHT][MAXWIDTH];
} img;

void ReadBmp(char *filename, img *imgp);
void WriteBmp(char *filename, img *tp);
void PrintBmpInfo(char *filename);
void HMirror(img *sp, img *tp);
void VMirror(img *sp, img *tp);
void Rotate90(int a, img *sp, img *tp);
void Shrink(int a, img *sp, img *tp);
void Mosaic(int a, img *sp, img *tp);
void Gray(img *sp, img *tp);
void Diminish(img *sp, img *tp, unsigned char x);


#endif	//#ifndef BMP_H_
