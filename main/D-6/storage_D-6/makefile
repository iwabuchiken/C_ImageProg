ROOT_DIR	:= C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\main\D-6
PROJECT_DIR	:= C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg
UTILS_DIR	:= C:\WORKS_2\WS\Eclipse_Luna\C_ImageProg\utils

C_SRCS_TRUNK	:= main
C_SRCS := $(C_SRCS_TRUNK).c
#C_SRCS := ex1_1.c

C_FILES	:=

OTHER_C_FILES	:= bmp.c

#UTILS_DIR	:=

C_OBJ := $(C_SRCS_TRUNK).o
#C_OBJ := ex1_1.o

C_EXE := $(C_SRCS_TRUNK).exe
#C_EXE := ex1_1.exe

INC:=	-I.

RM	:= del

CC	:= gcc

VAR	:= ffffff

#######################################
#######################################

all: $(C_EXE)

#$(C_EXE): clean
$(C_EXE):

	$(CC)  $(ROOT_DIR)\$(C_SRCS) -o $(ROOT_DIR)\$(C_EXE) -I$(UTILS_DIR)
#	$(CC)  $(ROOT_DIR)\$(C_SRCS) $(UTILS_DIR)\$(C_FILES) $(ROOT_DIR)\$(OTHER_C_FILES) -o $(ROOT_DIR)\$(C_EXE)
#	$(CC)  $(C_SRCS) -o $(C_EXE)

#	echo yes

#clean:
	
#	$(RM) $(ROOT_DIR)\$(C_EXE)
	
test:

	echo $(VAR)
