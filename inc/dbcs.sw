;
;	Microsoft Confidential
;	Copyright (C) Microsoft Corporation 1991
;	All Rights Reserved.
;

;***********************************************************************;
;									;
;	To build DBCS version, Define DBCS by using MASM option via	;
;	Dos environment.						;
;									;
;	ex.		set MASM=-DDBCS					;
;									;
;***********************************************************************;

if1
	ifdef DBCS
%OUT    DBCS Version Build Switch ON
	endif
endif
