#******************************************************************************
#
#   (C) Copyright MICROSOFT Corp. 1990-1991
#
#   MAKEFILE FOR VPD
#
#==============================================================================

#ROOT	= ..\..\..\..
#TOOLS	= $(ROOT)\newtools\bin
INC	= .
AFLAGS	= -Mx -t $(MAKEFLAG) -p
ASM	= masm5
LINK	= link386
LFLAGS	= /NOI /NOD /MAP /NOPACKCODE


#DOCFILE = VXDDOC.TXT

DEVICE	    = LoadHi
VERSION     = 1.0
STUB	    = EMM386.EXE
EXECUTABLE  = EMM386NW.exe

BLDALL=FALSE

include makeflag.mk
#include ..\..\win386.mk

.SUFFIXES:
.SUFFIXES: .obj .lst .exe .asm

.asm.obj:
        $(ASM) -I$(INC) $(AFLAGS) $*.ASM;

.asm.lst:
        $(ASM) -L -I$(INC) $(AFLAGS) $*.ASM;

OBJS  = instinit.obj instswap.obj loadhi.obj umb.obj

#***************************************************************************
#	T A R G E T S
#****************************************************************************
all:emm386nw.exe


#******************************************************************************
#		 DO NOT MODIFY THE MAKEFILE BEYOND THIS LINE
#******************************************************************************

# Dependencies follow
instinit.obj instinit.lst: instinit.asm instance.inc debug.inc \
	 opttest.inc vmm.inc

instswap.obj instswap.lst: instswap.asm opttest.inc instance.inc \
	 debug.inc vmm.inc

loadhi.obj loadhi.lst: loadhi.asm vdd2.inc instance.inc v86mmgr.inc \
	 debug.inc dosmgr.inc vmm.inc 

umb.obj umb.lst: umb.asm vmm.inc

allobjs: $(OBJS) 

EMM386NW.exe: LoadHi.def EMM386.EXE $(OBJS)
        $(LINK) @<<
instinit.obj+instswap.obj+loadhi.obj+umb.obj
..\EMM386NW.exe $(LFLAGS)
LoadHi.map

LoadHi.def
<<
        addhdr ..\EMM386NW.exe
