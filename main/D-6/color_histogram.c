/* color_histogram.c  ���̃v���O�����̖��O */
#include<stdio.h>

//#include"ppmlib.h"
#ifndef PPMLIB_H_
#define PPMLIB_H_
//#include "include/pgmlib.h.orig"
#include "include/ppmlib.h"
#endif


long int hist[256][3]; /* �q�X�g�O�����p�z�� */
void make_histogram_image( int n1, int n2, int h );

int main(void)
{
    load_color_image( 0, "" );  /* �t�@�C�� �� �摜No.0 */
    /* �q�X�g�O�����̉摜������ĉ摜No.1�ɕۑ� */
    make_histogram_image( 0, 1, 256 );
    printf("�J���[�q�X�g�O�����̉摜��ۑ����܂�\n");
    save_color_image( 1, "" );  /* �摜No.1 �� �t�@�C�� */
    return 0;
}

void make_histogram_image( int n1, int n2, int h )
/* �摜No.n1�̃J���[�q�X�g�O�������摜��(��256�~�ch��f) */
/* ���ĉ摜No.n2�ɋL�^���� */
{
    int i,j,x,y;  /* ����ϐ� */
    long int max; /* �ő�p�x */
    int takasa;   /* �e�K���l�̕p�x�̍��� */

    /* �q�X�g�O�����̏����� */
    for(i=0;i<256;i++) for(j=0;j<3;j++) hist[i][j] = 0;
    /* �摜�����X�^�X�L�������ăO���t����� */
    for(y=0;y<height[n1];y++)
        for(x=0;x<width[n1];x++)
            for(j=0;j<3;j++)
                hist[ image[n1][x][y][j] ][j]++; /* �ݐς��P���� */
    /* �摜�̏c�E���̒l�̓��͂Ə����� */
    width[n2]=256;  height[n2]=h;  init_color_image( n2, 0, 0, 0 );
    /* �q�X�g�O�����̍ő�p�xmax�����߂� */
    max=0;
    for(i=0;i<256;i++)
        for(j=0;j<3;j++)
            if ( hist[i][j] > max ) max = hist[i][j];
    /* �c����h��f�ɐ��K�����Ȃ���摜�ɒl���� */
    for(i=0;i<3;i++)
        for(x=0;x<width[n2];x++){
            takasa = (int)( h / (double)max * hist[x][i] );
            if ( takasa > h ) takasa = h;
            for(y=0;y<h;y++)
                if ( y < takasa ) image[n2][x][h-1-y][i] = 255;
        }
}
