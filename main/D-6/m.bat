@echo off

REM REF http://stackoverflow.com/questions/69068/long-commands-split-over-multiple-lines-in-vista-dos-batch-bat-file answered Sep 16 '08 at 3:06

echo make -f C:\WORKS\WS\Eclipse_Luna\C_ImageProg\main\s-4\main UTILS_DIR=C:\WORKS\WS\Eclipse_Luna\C_ImageProg\utils C_FILES=utils.c OTHER_C_FILES="bmp.c"
echo	.
echo	.	
		
make -f C:\WORKS\WS\Eclipse_Luna\C_ImageProg\main\s-4\makefile ^
		C_SRCS_TRUNK=main ^
		ROOT_DIR=C:\WORKS\WS\Eclipse_Luna\C_ImageProg\main\s-4 ^
		UTILS_DIR=C:\WORKS\WS\Eclipse_Luna\C_ImageProg\utils ^
		C_FILES=utils.c ^
		OTHER_C_FILES="bmp.c"