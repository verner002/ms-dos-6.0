;/*
; *                      Microsoft Confidential
; *                      Copyright (C) Microsoft Corporation 1987 - 1991
; *                      All Rights Reserved.
; */
.XLIST



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;;                                             
;; MS-DOS 5.00 - NLS Support - KEYB Command
;;
;; File Name:  KEYBCPSD.INC
;; ----------
;;
;;
;; Description:
;; ------------
;;       External declarations and equates for procedures in file
;;       KEYBCPSD.ASM
;;
;; Change History:
;; ---------------
;;
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                                       ;;
        EXTRN    COPY_SD_AREA:NEAR     ;;
                                       ;;
        EXTRN    SD_DEST_PTR :BYTE     ;;
        EXTRN    SHARED_DATA :BYTE     ;;
                                       ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.LIST
