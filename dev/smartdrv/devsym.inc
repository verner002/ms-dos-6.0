;
;	Microsoft Confidential
;	Copyright (C) Microsoft Corporation 1991
;	All Rights Reserved.
;

;**	DevSym.inc - Device Symbols
;
; 	Revision History: 
;
;	M018 - defined bit 11 of DOS34_FLAG. See M041 in dos.tag for 
;	       explanation.
;


;	THE DEVICE TABLE LIST HAS THE FORM:

SYSDEV	       STRUC
SDEVNEXT       DD    ?		    ;POINTER TO NEXT DEVICE HEADER
SDEVATT        DW    ?		    ;ATTRIBUTES OF THE DEVICE
SDEVSTRAT      DW    ?		    ;STRATEGY ENTRY POINT
SDEVINT        DW    ?		    ;INTERRUPT ENTRY POINT
SDEVNAME       DB    '        '	    ;NAME OF DEVICE (ONLY FIRST BYTE USED FOR BLOCK)
SYSDEV	       ENDS

;
; ATTRIBUTE BIT MASKS
;
; CHARACTER DEVICES:
;
; BIT 15 -> MUST BE 1
;     14 -> 1 IF THE DEVICE UNDERSTANDS IOCTL CONTROL STRINGS
;     13 -> 1 IF THE DEVICE SUPPORTS OUTPUT-UNTIL-BUSY
;     12 -> UNUSED
;     11 -> 1 IF THE DEVICE UNDERSTANDS OPEN/CLOSE
;     10 -> MUST BE 0
;      9 -> MUST BE 0
;      8 -> UNUSED - Must be 0 to support current versions of Mace Utilities
;      7 -> SUPPORTS DEVICE QUERY
;      6 -> UNUSED
;      5 -> UNUSED
;      4 -> 1 IF DEVICE IS RECIPIENT OF INT 29H
;      3 -> 1 IF DEVICE IS CLOCK DEVICE
;      2 -> 1 IF DEVICE IS NULL DEVICE
;      1 -> 1 IF DEVICE IS CONSOLE OUTPUT
;      0 -> 1 IF DEVICE IS CONSOLE INPUT
;
; BLOCK DEVICES:
;
; BIT 15 -> MUST BE 0
;     14 -> 1 IF THE DEVICE UNDERSTANDS IOCTL CONTROL STRINGS
;     13 -> 1 IF THE DEVICE DETERMINES MEDIA BY EXAMINING THE FAT ID BYTE.
;	    THIS REQUIRES THE FIRST SECTOR OF THE FAT TO *ALWAYS* RESIDE IN
;	    THE SAME PLACE.
;     12 -> UNUSED
;     11 -> 1 IF THE DEVICE UNDERSTANDS OPEN/CLOSE/REMOVABLE MEDIA
;     10 -> MUST BE 0
;      9 -> MUST BE 0
;      8 -> UNUSED - Must be 0 to support current versionso of Mace Utilities
;      7 -> SUPPORTS DEVICE QUERY
;      6 -> IF DEVICE HAS SUPPORT FOR GETMAP/SETMAP OF LOGICAL DRIVES.
;	    IF THE DEVICE UNDERSTANDS GENERIC IOCTL FUNCTION CALLS.
;      5 -> UNUSED
;      4 -> UNUSED
;      3 -> UNUSED
;      2 -> UNUSED
;      1 -> UNUSED
;      0 -> UNUSED
;

DEVTYP	       EQU   8000H	    ; BIT 15 - 1  IF CHAR, 0 IF BLOCK
CHARDEV        EQU   8000H
DEVIOCTL       EQU   4000H	    ; BIT 14 - CONTROL MODE BIT
ISFATBYDEV     EQU   2000H	    ; BIT 13 - DEVICE USES FAT ID BYTES,
				    ;  COMP MEDIA.
OUTTILBUSY     EQU   2000H	    ; OUTPUT UNTIL BUSY IS ENABLED
ISNET	       EQU   1000H	    ; BIT 12 - 1 IF A NET DEVICE, 0 IF
				    ;  NOT.  CURRENTLY BLOCK ONLY.
DEVOPCL        EQU   0800H	    ; BIT 11 - 1 IF THIS DEVICE HAS
				    ;  OPEN,CLOSE AND REMOVABLE MEDIA
				    ;  ENTRY POINTS, 0 IF NOT

EXTENTBIT      EQU   0400H	    ; BIT 10 - CURRENTLY 0 ON ALL DEVS
				    ;  THIS BIT IS RESERVED FOR FUTURE USE
				    ;  TO EXTEND THE DEVICE HEADER BEYOND
				    ;  ITS CURRENT FORM.

; NOTE BIT 9 IS CURRENTLY USED ON IBM SYSTEMS TO INDICATE "DRIVE IS SHARED".
;    SEE IOCTL FUNCTION 9. THIS USE IS NOT DOCUMENTED, IT IS USED BY SOME
;    OF THE UTILITIES WHICH ARE SUPPOSED TO FAIL ON SHARED DRIVES ON SERVER
;    MACHINES (FORMAT,CHKDSK,RECOVER,..).

; M017 IOQUERY	       EQU   0100H	    ;Bit 8 - Supports generic IOCtl query
IOQUERY	       EQU   080H	    ;Bit 7 - Supports generic IOCtl query M017


DEV320	       EQU   0040H	    ;BIT 6 - FOR BLOCK DEVICES, THIS
				    ;DEVICE SUPPORTS SET/GET MAP OF
				    ;LOGICAL DRIVES, AND SUPPORTS
				    ;GENERIC IOCTL CALLS.
				    ;FOR CHARACTER DEVICES, THIS
				    ;DEVICE SUPPORTS GENERIC IOCTL.
				    ;THIS IS A DOS 3.2 DEVICE DRIVER.
ISSPEC	       EQU   0010H	    ;BIT 4 - THIS DEVICE IS SPECIAL
ISCLOCK        EQU   0008H	    ;BIT 3 - THIS DEVICE IS THE CLOCK DEVICE.
ISNULL	       EQU   0004H	    ;BIT 2 - THIS DEVICE IS THE NULL DEVICE.
ISCOUT	       EQU   0002H	    ;BIT 1 - THIS DEVICE IS THE CONSOLE OUTPUT.
ISCIN	       EQU   0001H	    ;BIT 0 - THIS DEVICE IS THE CONSOLE INPUT.
EXTDRVR        EQU   0002H	    ;BIT 1 - BLOCK DEVICE EXTNDED DRIVER



;STATIC REQUEST HEADER
SRHEAD	       STRUC
REQLEN	       DB    ?		    ;LENGTH IN BYTES OF REQUEST BLOCK
REQUNIT        DB    ?		    ;DEVICE UNIT NUMBER
REQFUNC        DB    ?		    ;TYPE OF REQUEST
REQSTAT        DW    ?		    ;STATUS WORD
	       DB    8 DUP(?)	    ;RESERVED FOR QUEUE LINKS
SRHEAD	       ENDS

;STATUS WORD MASKS
STERR	       EQU   8000H	    ;BIT 15 - ERROR
STBUI	       EQU   0200H	    ;BIT 9 - BUISY
STDON	       EQU   0100H	    ;BIT 8 - DONE
STECODE        EQU   00FFH	    ;ERROR CODE
;						  2/12/KK
; Interim  character identifier 		  2/12/KK
Ddkey		EQU	0000010000000000B	; 2/12/KK

;FUNCTION CODES
DINITHL        EQU   26 	    ;SIZE OF INIT HEADER
DMEDHL	       EQU   15 	    ;SIZE OF MEDIA CHECK HEADER
DBPBHL	       EQU   22 	    ;SIZE OF GET BPB HEADER
DRDWRHL        EQU   22 	    ;SIZE OF RD/WR HEADER
DRDNDHL        EQU   14 	    ;SIZE OF NON DESTRUCTIVE READ HEADER
DSTATHL        EQU   13 	    ;SIZE OF STATUS HEADER
DFLSHL	       EQU   15 	    ;SIZE OF FLUSH HEADER

DEVINIT        EQU   0		    ;INITIALIZATION
DEVMDCH        EQU   1		    ;MEDIA CHECK
DEVBPB	       EQU   2		    ;GET BPB
DEVRDIOCTL     EQU   3		    ;IOCTL READ
DEVRD	       EQU   4		    ;READ
DEVRDND        EQU   5		    ;NON DESTRUCTIVE READ NO WAIT (CHARACTER DEVS)
DEVIST	       EQU   6		    ;INPUT STATUS
DEVIFL	       EQU   7		    ;INPUT FLUSH
DEVWRT	       EQU   8		    ;WRITE
DEVWRTV        EQU   9		    ;WRITE WITH VERIFY
DEVOST	       EQU   10 	    ;OUTPUT STATUS
DEVOFL	       EQU   11 	    ;OUTPUT FLUSH
DEVWRIOCTL     EQU   12 	    ;IOCTL WRITE
DEVOPN	       EQU   13 	    ;DEVICE OPEN
DEVCLS	       EQU   14 	    ;DEVICE CLOSE
DOPCLHL        EQU   13 	    ;SIZE OF OPEN/CLOSE HEADER
DEVRMD	       EQU   15 	    ;REMOVABLE MEDIA
REMHL	       EQU   13 	    ;SIZE OF REMOVABLE MEDIA HEADER
GENIOCTL       EQU   19

; THE NEXT THREE ARE USED IN DOS 4.0
;		     20
;		     21
;		     22

DEVGETOWN      EQU   23 	    ;GET DEVICE OWNER
DEVSETOWN      EQU   24 	    ;SET DEVICE OWNER
IOCTL_QUERY    EQU   25		    ;Query generic ioctl support

OWNHL	       EQU   13 	    ;SIZE OF DEVICE OWNER HEADER

DEVOUT	       EQU   16 	    ; OUTPUT UNTIL BUSY.

DEVOUTL        EQU   DEVWRT	    ; LENGTH OF OUTPUT UNTIL BUSY

; ADDED FOR DOS 5.00
;


; GENERIC IOCTL REQUEST STRUCTURE
;	SEE THE DOS 4.0 DEVICE DRIVER SPEC FOR FURTHER ELABORATION.
;
IOCTL_REQ      STRUC
	       DB    (SIZE SRHEAD) DUP(?)
				    ; GENERIC IOCTL ADDITION.
MAJORFUNCTION  DB    ?		    ;FUNCTION CODE
MINORFUNCTION  DB    ?		    ;FUNCTION CATEGORY
REG_SI	       DW    ?
REG_DI	       DW    ?
GENERICIOCTL_PACKET DD ?	    ; POINTER TO DATA BUFFER
IOCTL_REQ      ENDS

;	DEFINITIONS FOR IOCTL_REQ.MINORFUNCTION
GEN_IOCTL_WRT_TRK   EQU   40H
GEN_IOCTL_RD_TRK    EQU   60H
GEN_IOCTL_FN_TST    EQU   20H	    ; USED TO DIFF. BET READS AND WRTS

;; 32-bit absolute read/write input list structure

ABS_32RW	 STRUC
SECTOR_RBA	 DD	 ?	    ; relative block address
ABS_RW_COUNT	 DW	 ?	    ; number of sectors to be transferred
BUFFER_ADDR	 DD	 ?	    ; data addrress
ABS_32RW	 ENDS

;; media ID info

MEDIA_ID_INFO	 STRUC
MEDIA_level	 DW	 0	    ; info level
MEDIA_Serial	 DD	 0	    ; serial #
MEDIA_Label	 DB	 11 dup (' ') ;volume label
MEDIA_System	 DB	 8  dup (' ') ;system type
MEDIA_ID_INFO	 ENDS

;; equates for DOS34_FLAG
;
; BUGBUG: why are bits 0,1,3 and 4 not defined.
;

FROM_DISK_RESET       EQU   000000000100b   ;from disk reset
Force_I24_Fail	      EQU   000000100000b   ;form IFS CALL BACK
Disable_EOF_I24       EQU   000001000000b   ;disable EOF int24 for input status
DBCS_VOLID	      EQU   000010000000b   ;indicate from volume id
DBCS_VOLID2	      EQU   000100000000b   ;indicate 8th char is DBCS
CTRL_BREAK_FLAG       EQU   001000000000b   ;indicate control break is input
SEARCH_FASTOPEN       EQU   010000000000b   ;set fastopen flag for search
EXEC_AWARE_REDIR      EQU   100000000000b   ;M018: this bit is set by a redir 
					    ;M018: that knows how to handle 
					    ;M018: open for exec

NO_FROM_DISK_RESET    EQU   NOT FROM_DISK_RESET	;not from disk reset
NO_Force_I24_Fail     EQU   NOT Force_I24_Fail	;not form IFS CALL BACK
NO_Disable_EOF_I24    EQU   NOT Disable_EOF_I24
