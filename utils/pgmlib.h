/* �K���摜(pgm�`��)�p���C�u���� pgmlib.h */
#include<stdlib.h>
#include<string.h>

/* �萔�錾 */
#define MAX_IMAGESIZE       1280 /* �z�肷��c�E���̍ő��f�� */
#define MAX_BRIGHTNESS       255 /* �z�肷��ő�K���l */
#define GRAYLEVEL            256 /* �z�肷��K����(=�ő�K���l+1) */
#define MAX_FILENAME         256 /* �z�肷��t�@�C�����̍ő咷 */
#define MAX_BUFFERSIZE       256 /* ���p����o�b�t�@�ő咷 */
#define MAX_NUM_OF_IMAGES      5 /* ���p����摜�̖��� */

/* ���ϐ��̐錾 */
/* �摜�f�[�^ image[n][x][y] */
unsigned char image[MAX_NUM_OF_IMAGES][MAX_IMAGESIZE][MAX_IMAGESIZE];
/* image[n] �̉����E�c�� */
int width[MAX_NUM_OF_IMAGES], height[MAX_NUM_OF_IMAGES];

/* �֐��̃v���g�^�C�v�錾 */
/* �K���摜����͂���֐� */
void load_image( int n, char name[] );
  /* n:�摜�ԍ��Cname[]:�t�@�C�����i""�̂Ƃ��̓L�[�{�[�h���́j*/
/* �K���摜���o�͂���֐�*/
void save_image( int n, char name[] );
  /* n:�摜�ԍ��Cname[]:�t�@�C�����i""�̂Ƃ��̓L�[�{�[�h���́j*/
/* �K���摜���R�s�[����֐�*/
void copy_image( int n1, int n2 );
  /* �摜No.n1 �� �摜No.n2�ɃR�s�[���� */
/* �K���摜������������֐�*/
void init_image( int n, unsigned char value );
  /* �摜No.n�̑S��f�̊K���l�������I��value(0�`255)�ɂ��� */

/* �K���摜����͂���֐� */
void load_image( int n, char name[] )
/* n:画像番号，name[]:ファイル名（""のときはキーボード入力）*/
/* 横幅，縦幅はそれぞれ width[n], height[n] に代入する */
{
    char file_name[MAX_FILENAME]; /* ファイル名用の文字配列 */
    char buffer[MAX_BUFFERSIZE];  /* データ読み込み用作業変数 */
    FILE *fp; /* ファイルポインタ */
    int max_gray; /* 最大階調値 */
    int x, y; /* ループ変数 */

    /* 入力ファイルのオープン */
    if ( name[0] == '\0' ){
        printf("input file name (*.pgm) : ");
//        printf("入力ファイル名 (*.pgm) : ");
        scanf("%s",file_name);
    } else strcpy( file_name, name );
    if ( (fp = fopen( file_name, "rb" ))==NULL ){

        printf("file doesN8t exit.\n");
//        printf("その名前のファイルは存在しません．\n");

        exit(1);
    }
    /* ファイルタイプ(=P5)の確認 */
    fgets( buffer, MAX_BUFFERSIZE, fp );
    if ( buffer[0] != 'P' || buffer[1] != '5' ){
        printf("ファイルのフォーマットが P5 とは異なります．\n");
        exit(1);
    }
    /* width[n], height[n] の代入（#から始まるコメントは読み飛ばす） */
    width[n] = 0;    height[n] = 0;
    while ( width[n] == 0 || height[n] == 0 ){
        fgets( buffer, MAX_BUFFERSIZE, fp );
        if ( buffer[0] != '#' )
            sscanf( buffer, "%d %d", &width[n], &height[n] );
    }
    /* max_gray の代入（#から始まるコメントは読み飛ばす） */
    max_gray = 0;
    while ( max_gray == 0 ){
        fgets( buffer, MAX_BUFFERSIZE, fp );
        if ( buffer[0] != '#' )
            sscanf( buffer, "%d", &max_gray );
    }
    /* パラメータの画面への表示 */
    printf("pixels, horizon = %d, pixels, verti = %d\n", width[n], height[n] );
//    printf("横の画素数 = %d, 縦の画素数 = %d\n", width[n], height[n] );

    printf("max brightness = %d\n",max_gray);
//    printf("最大階調値 = %d\n",max_gray);

    if ( width[n] > MAX_IMAGESIZE || height[n] > MAX_IMAGESIZE ){

        printf("expected size %d x %d => excessive\n",
//        printf("想定値 %d x %d を超えています．\n",
            MAX_IMAGESIZE, MAX_IMAGESIZE);

        printf("use smaller files\n");
//        printf("もう少し小さな画像を使って下さい．\n");
        exit(1);
    }
    if ( max_gray != MAX_BRIGHTNESS ){
        printf("最大階調値が不適切です．\n");  exit(1);
    }
    /* 画像データを読み込んで画像用配列に代入する */
    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++)
            image[n][x][y] = (unsigned char)fgetc( fp );
    fclose(fp);
    printf("画像は正常に読み込まれました．\n");
}

/* �K���摜���o�͂���֐�*/
void save_image( int n, char name[] )
/* n:�摜�ԍ��Cname[]:�t�@�C�����i""�̂Ƃ��̓L�[�{�[�h���́j*/
/* �摜�̉����C�c���͂��ꂼ�� width[n], height[n] �ɑ������Ă�����̂Ƃ��� */
{
    char file_name[MAX_FILENAME]; /* �t�@�C�����p�̕����z�� */
    FILE *fp; /* �t�@�C���|�C���^ */
    int x, y; /* ���[�v�ϐ� */

    /* �o�̓t�@�C���̃I�[�v�� */
    if ( name[0] == '\0' ){
        printf("output file name (*.pgm) : ");
//        printf("�o�̓t�@�C���� (*.pgm) : ");
        scanf("%s",file_name);
    } else strcpy( file_name, name );
    if ( (fp = fopen(file_name, "wb"))==NULL ){

    	//debug
    	printf("[%s:%d] error\n", basename(__FILE__, '\\'), __LINE__);


        printf("can't open the file\n");
//        printf("�t�@�C�����I�[�v���ł��܂���D\n");

        exit(1);
    }
    /* �t�@�C�����ʎq "P5" ��擪�ɏo�͂��� */
    fputs( "P5\n", fp );
    /* # �Ŏn�܂�R�����g�s�i�ȗ��\�j */
    fputs( "# Created by Image Processing\n", fp );
    /* �摜�̉����C�c���̏o�� */
    fprintf( fp, "%d %d\n", width[n], height[n] );
    /* �ő�K���l�̏o�� */
    fprintf( fp, "%d\n", MAX_BRIGHTNESS );
    /* �摜�f�[�^�̏o�� */
    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++)
            fputc( image[n][x][y], fp );
    fclose(fp);
    printf("�摜�͐���ɏo�͂���܂����D\n");
}

/* �K���摜���R�s�[����֐�*/
void copy_image( int n1, int n2 )
/* �摜No.n1���摜No.n2�ɃR�s�[���� */
{
    int x, y; /* ���[�v�ϐ� */

    /* �����C�c���̑�� */
    width[n2] = width[n1];    height[n2] = height[n1];
    /* �K���f�[�^�̃R�s�[ */
    for(y=0;y<height[n1];y++)
        for(x=0;x<width[n1];x++)
            image[n2][x][y] = image[n1][x][y];
}

/* �K���摜������������֐�*/
void init_image( int n, unsigned char value )
/* �摜No.n�̑S��f�̊K���l�������I��value(0�`255)�ɂ��� */
{
    int x, y; /* ���[�v�ϐ� */

    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++)
            image[n][x][y] = value;
}
