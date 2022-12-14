fmemFixed	equ	1
fmemNear	equ	2
cbNearMemServiceMax	equ	64
indtNil		equ	0
indtKeyboard	equ	1
indtCharacterScreen	equ	2
indtGraphicScreen	equ	3
indtCharacterPrinter	equ	4
indtGraphicPrinter	equ	5
indtSystem	equ	6

indtIndv	equ	[byte ptr 00000h]
fillerIndv	equ	[byte ptr 00001h]
rglpfnIndv	equ	[word ptr 00002h]
cpfnNeedMinIndv	equ	[word ptr 00004h]
cpfnNeedMacIndv	equ	[word ptr 00006h]
psLoadedIndv	equ	[word ptr 00008h]
cpfnLoadedIndv	equ	[word ptr 0000Ah]
cbIndvMin	equ	0000Ch

rgchMagicIndh	equ	[dword ptr 00000h]
LO_rgchMagicIndh	equ	[word ptr 00000h]
HI_rgchMagicIndh	equ	[word ptr 00002h]
dlfaTableIndh	equ	[dword ptr 00004h]
LO_dlfaTableIndh	equ	[word ptr 00004h]
HI_dlfaTableIndh	equ	[word ptr 00006h]
cbIndhMin	equ	00008h

indtInds	equ	[byte ptr 00000h]
floadInds	equ	[byte ptr 00001h]
cbCodeInds	equ	[word ptr 00002h]
dlfaCodeInds	equ	[dword ptr 00004h]
LO_dlfaCodeInds	equ	[word ptr 00004h]
HI_dlfaCodeInds	equ	[word ptr 00006h]
cbIndsMin	equ	00008h

rgchMagicIndt	equ	[dword ptr 00000h]
LO_rgchMagicIndt	equ	[word ptr 00000h]
HI_rgchMagicIndt	equ	[word ptr 00002h]
cindsIndt	equ	[word ptr 00004h]
rgindsIndt	equ	[00006h]
cbIndtMin	equ	0000Eh
floadFixed	equ	1
floadRealMode	equ	00010h
floadProtMode	equ	00020h
floadAnyMode	equ	(floadRealMode or floadProtMode)
floadStandard	equ	00080h

sdGlisInos	equ	[word ptr 00000h]
sdLoisInos	equ	[word ptr 00002h]
cpfnInos	equ	[word ptr 00004h]
lpfnDosGetVersionInos	equ	[dword ptr 00006h]
OFF_lpfnDosGetVersionInos	equ	[word ptr 00006h]
SEG_lpfnDosGetVersionInos	equ	[word ptr 00008h]
lpfnDosGetEnvInos	equ	[dword ptr 0000Ah]
OFF_lpfnDosGetEnvInos	equ	[word ptr 0000Ah]
SEG_lpfnDosGetEnvInos	equ	[word ptr 0000Ch]
lpfnDosDevConfigInos	equ	[dword ptr 0000Eh]
OFF_lpfnDosDevConfigInos	equ	[word ptr 0000Eh]
SEG_lpfnDosDevConfigInos	equ	[word ptr 00010h]
lpfnDosGetCtryInfoInos	equ	[dword ptr 00012h]
OFF_lpfnDosGetCtryInfoInos	equ	[word ptr 00012h]
SEG_lpfnDosGetCtryInfoInos	equ	[word ptr 00014h]
lpfnDosGetDBCSEvInos	equ	[dword ptr 00016h]
OFF_lpfnDosGetDBCSEvInos	equ	[word ptr 00016h]
SEG_lpfnDosGetDBCSEvInos	equ	[word ptr 00018h]
lpfnDosGetInfoSegInos	equ	[dword ptr 0001Ah]
OFF_lpfnDosGetInfoSegInos	equ	[word ptr 0001Ah]
SEG_lpfnDosGetInfoSegInos	equ	[word ptr 0001Ch]
lpfnDosDevIOCtlInos	equ	[dword ptr 0001Eh]
OFF_lpfnDosDevIOCtlInos	equ	[word ptr 0001Eh]
SEG_lpfnDosDevIOCtlInos	equ	[word ptr 00020h]
lpfnDosPortAccessInos	equ	[dword ptr 00022h]
OFF_lpfnDosPortAccessInos	equ	[word ptr 00022h]
SEG_lpfnDosPortAccessInos	equ	[word ptr 00024h]
lpfnDosGetModHandleInos	equ	[dword ptr 00026h]
OFF_lpfnDosGetModHandleInos	equ	[word ptr 00026h]
SEG_lpfnDosGetModHandleInos	equ	[word ptr 00028h]
lpfnDosLoadModuleInos	equ	[dword ptr 0002Ah]
OFF_lpfnDosLoadModuleInos	equ	[word ptr 0002Ah]
SEG_lpfnDosLoadModuleInos	equ	[word ptr 0002Ch]
lpfnDosGetProcAddrInos	equ	[dword ptr 0002Eh]
OFF_lpfnDosGetProcAddrInos	equ	[word ptr 0002Eh]
SEG_lpfnDosGetProcAddrInos	equ	[word ptr 00030h]
lpfnDosCreateThreadInos	equ	[dword ptr 00032h]
OFF_lpfnDosCreateThreadInos	equ	[word ptr 00032h]
SEG_lpfnDosCreateThreadInos	equ	[word ptr 00034h]
lpfnDosSetPrtyInos	equ	[dword ptr 00036h]
OFF_lpfnDosSetPrtyInos	equ	[word ptr 00036h]
SEG_lpfnDosSetPrtyInos	equ	[word ptr 00038h]
lpfnDosExitInos	equ	[dword ptr 0003Ah]
OFF_lpfnDosExitInos	equ	[word ptr 0003Ah]
SEG_lpfnDosExitInos	equ	[word ptr 0003Ch]
lpfnDosOpenInos	equ	[dword ptr 0003Eh]
OFF_lpfnDosOpenInos	equ	[word ptr 0003Eh]
SEG_lpfnDosOpenInos	equ	[word ptr 00040h]
lpfnDosCloseInos	equ	[dword ptr 00042h]
OFF_lpfnDosCloseInos	equ	[word ptr 00042h]
SEG_lpfnDosCloseInos	equ	[word ptr 00044h]
lpfnDosReadInos	equ	[dword ptr 00046h]
OFF_lpfnDosReadInos	equ	[word ptr 00046h]
SEG_lpfnDosReadInos	equ	[word ptr 00048h]
lpfnDosWriteInos	equ	[dword ptr 0004Ah]
OFF_lpfnDosWriteInos	equ	[word ptr 0004Ah]
SEG_lpfnDosWriteInos	equ	[word ptr 0004Ch]
lpfnDosMonOpenInos	equ	[dword ptr 0004Eh]
OFF_lpfnDosMonOpenInos	equ	[word ptr 0004Eh]
SEG_lpfnDosMonOpenInos	equ	[word ptr 00050h]
lpfnDosMonCloseInos	equ	[dword ptr 00052h]
OFF_lpfnDosMonCloseInos	equ	[word ptr 00052h]
SEG_lpfnDosMonCloseInos	equ	[word ptr 00054h]
lpfnDosMonRegInos	equ	[dword ptr 00056h]
OFF_lpfnDosMonRegInos	equ	[word ptr 00056h]
SEG_lpfnDosMonRegInos	equ	[word ptr 00058h]
lpfnDosMonReadInos	equ	[dword ptr 0005Ah]
OFF_lpfnDosMonReadInos	equ	[word ptr 0005Ah]
SEG_lpfnDosMonReadInos	equ	[word ptr 0005Ch]
lpfnDosMonWriteInos	equ	[dword ptr 0005Eh]
OFF_lpfnDosMonWriteInos	equ	[word ptr 0005Eh]
SEG_lpfnDosMonWriteInos	equ	[word ptr 00060h]
lpfnDosAllocSegInos	equ	[dword ptr 00062h]
OFF_lpfnDosAllocSegInos	equ	[word ptr 00062h]
SEG_lpfnDosAllocSegInos	equ	[word ptr 00064h]
lpfnDosReAllocSegInos	equ	[dword ptr 00066h]
OFF_lpfnDosReAllocSegInos	equ	[word ptr 00066h]
SEG_lpfnDosReAllocSegInos	equ	[word ptr 00068h]
lpfnDosFreeSegInos	equ	[dword ptr 0006Ah]
OFF_lpfnDosFreeSegInos	equ	[word ptr 0006Ah]
SEG_lpfnDosFreeSegInos	equ	[word ptr 0006Ch]
lpfnVioGetBufInos	equ	[dword ptr 0006Eh]
OFF_lpfnVioGetBufInos	equ	[word ptr 0006Eh]
SEG_lpfnVioGetBufInos	equ	[word ptr 00070h]
lpfnVioShowBufInos	equ	[dword ptr 00072h]
OFF_lpfnVioShowBufInos	equ	[word ptr 00072h]
SEG_lpfnVioShowBufInos	equ	[word ptr 00074h]
lpfnVioGetConfigInos	equ	[dword ptr 00076h]
OFF_lpfnVioGetConfigInos	equ	[word ptr 00076h]
SEG_lpfnVioGetConfigInos	equ	[word ptr 00078h]
lpfnVioGetModeInos	equ	[dword ptr 0007Ah]
OFF_lpfnVioGetModeInos	equ	[word ptr 0007Ah]
SEG_lpfnVioGetModeInos	equ	[word ptr 0007Ch]
lpfnVioSetModeInos	equ	[dword ptr 0007Eh]
OFF_lpfnVioSetModeInos	equ	[word ptr 0007Eh]
SEG_lpfnVioSetModeInos	equ	[word ptr 00080h]
lpfnVioGetStateInos	equ	[dword ptr 00082h]
OFF_lpfnVioGetStateInos	equ	[word ptr 00082h]
SEG_lpfnVioGetStateInos	equ	[word ptr 00084h]
lpfnVioSetStateInos	equ	[dword ptr 00086h]
OFF_lpfnVioSetStateInos	equ	[word ptr 00086h]
SEG_lpfnVioSetStateInos	equ	[word ptr 00088h]
lpfnVioGetCurTypeInos	equ	[dword ptr 0008Ah]
OFF_lpfnVioGetCurTypeInos	equ	[word ptr 0008Ah]
SEG_lpfnVioGetCurTypeInos	equ	[word ptr 0008Ch]
lpfnVioSetCurTypeInos	equ	[dword ptr 0008Eh]
OFF_lpfnVioSetCurTypeInos	equ	[word ptr 0008Eh]
SEG_lpfnVioSetCurTypeInos	equ	[word ptr 00090h]
lpfnVioGetCurPosInos	equ	[dword ptr 00092h]
OFF_lpfnVioGetCurPosInos	equ	[word ptr 00092h]
SEG_lpfnVioGetCurPosInos	equ	[word ptr 00094h]
lpfnVioSetCurPosInos	equ	[dword ptr 00096h]
OFF_lpfnVioSetCurPosInos	equ	[word ptr 00096h]
SEG_lpfnVioSetCurPosInos	equ	[word ptr 00098h]
lpfnVioGetFontInos	equ	[dword ptr 0009Ah]
OFF_lpfnVioGetFontInos	equ	[word ptr 0009Ah]
SEG_lpfnVioGetFontInos	equ	[word ptr 0009Ch]
lpfnVioSetFontInos	equ	[dword ptr 0009Eh]
OFF_lpfnVioSetFontInos	equ	[word ptr 0009Eh]
SEG_lpfnVioSetFontInos	equ	[word ptr 000A0h]
lpfnVioGetCPInos	equ	[dword ptr 000A2h]
OFF_lpfnVioGetCPInos	equ	[word ptr 000A2h]
SEG_lpfnVioGetCPInos	equ	[word ptr 000A4h]
lpfnVioSetCPInos	equ	[dword ptr 000A6h]
OFF_lpfnVioSetCPInos	equ	[word ptr 000A6h]
SEG_lpfnVioSetCPInos	equ	[word ptr 000A8h]
lpfnVioScrollUpInos	equ	[dword ptr 000AAh]
OFF_lpfnVioScrollUpInos	equ	[word ptr 000AAh]
SEG_lpfnVioScrollUpInos	equ	[word ptr 000ACh]
lpfnKbdOpenInos	equ	[dword ptr 000AEh]
OFF_lpfnKbdOpenInos	equ	[word ptr 000AEh]
SEG_lpfnKbdOpenInos	equ	[word ptr 000B0h]
lpfnKbdCloseInos	equ	[dword ptr 000B2h]
OFF_lpfnKbdCloseInos	equ	[word ptr 000B2h]
SEG_lpfnKbdCloseInos	equ	[word ptr 000B4h]
lpfnKbdCharInInos	equ	[dword ptr 000B6h]
OFF_lpfnKbdCharInInos	equ	[word ptr 000B6h]
SEG_lpfnKbdCharInInos	equ	[word ptr 000B8h]
lpfnKbdGetStatusInos	equ	[dword ptr 000BAh]
OFF_lpfnKbdGetStatusInos	equ	[word ptr 000BAh]
SEG_lpfnKbdGetStatusInos	equ	[word ptr 000BCh]
lpfnKbdSetStatusInos	equ	[dword ptr 000BEh]
OFF_lpfnKbdSetStatusInos	equ	[word ptr 000BEh]
SEG_lpfnKbdSetStatusInos	equ	[word ptr 000C0h]
lpfnDosBeepInos	equ	[dword ptr 000C2h]
OFF_lpfnDosBeepInos	equ	[word ptr 000C2h]
SEG_lpfnDosBeepInos	equ	[word ptr 000C4h]
lpfnVioGetPhysBufInos	equ	[dword ptr 000C6h]
OFF_lpfnVioGetPhysBufInos	equ	[word ptr 000C6h]
SEG_lpfnVioGetPhysBufInos	equ	[word ptr 000C8h]
lpfnCwBeginIOInos	equ	[dword ptr 000CAh]
OFF_lpfnCwBeginIOInos	equ	[word ptr 000CAh]
SEG_lpfnCwBeginIOInos	equ	[word ptr 000CCh]
lpfnCwEndIOInos	equ	[dword ptr 000CEh]
OFF_lpfnCwEndIOInos	equ	[word ptr 000CEh]
SEG_lpfnCwEndIOInos	equ	[word ptr 000D0h]
cbInosMin	equ	000D2h

cpfnIncs	equ	[word ptr 00000h]
cbIncsMin	equ	00002h

lpwDataInsh	equ	[dword ptr 00000h]
LO_lpwDataInsh	equ	[word ptr 00000h]
HI_lpwDataInsh	equ	[word ptr 00002h]
pinosInsh	equ	[word ptr 00004h]
pincsInsh	equ	[word ptr 00006h]
cpfnInsh	equ	[word ptr 00008h]
cbInshMin	equ	0000Ah
