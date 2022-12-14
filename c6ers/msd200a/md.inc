;************************************************************************
;
;       HARDWARE.INC
;
;       This file defines the hardware specific equates to be used in
;               the mouse driver.
;

IOdelay macro
         jmp       $+2
         jmp       $+2
endm

address macro StartAddr, EndAddr
        add   dx,StartAddr-EndAddr
endm

DelayIn   macro dest,src
          IOdelay
          in dest,src
endm

DelayOut  macro dest,src
          IOdelay
          out dest,src
endm

;
; This makes debugging much, much easier !!
;

IFDEF DEBUG

; Label Names.

PUBLIC  serial_next_port,  rsm_waitloop,           cfmm_retry
PUBLIC  inport_not_found,  rsm_waitover,           cfmm_failure
PUBLIC  tfs_determine_int, rsm_lookforM,           cfmm_signature_sent
PUBLIC  cfas_clean_up,     rsm_gotchar,            cfmm_cleanup
PUBLIC  r8cb_got_data,     rsm_leave,              cfmm_disable_aux
PUBLIC  r8cb_leave,        gmd_loop,               cfas_is_wait_over
PUBLIC  w8cb_leave,        tfp_no_mouse,           rpm_retry
PUBLIC  wib_success,       tfp_leave,              rpm_failure
PUBLIC  mioff_leave,       cfas_read_test_results, finished_mouse
PUBLIC  cmd_leave,         cfas_no_support,        cfmm_leave
PUBLIC  stmatd_leave,      cfas_reenable_kbd,      All_is_well
PUBLIC  gmd_buffer_empty,  cfas_leave,             possible_inport
PUBLIC  gmd_got_aux_data,  r8cb_loop,              inport_check
PUBLIC  rpm_leave,         r8cb_leave2,            bus_not_found
PUBLIC  inport_try_again,  wib_wait,               tfs_error_leave
PUBLIC  inport_found,      wib_check_output,       wcr_loop
PUBLIC  look_for_bus,      wib_failure,            wcr_success
PUBLIC  look_for_serial,   wib_check_aux_data,     mioff_cleanup
PUBLIC  serial_try_again,  wib_leave,              mioff_reenable_kbd
PUBLIC  serial_test_port,  serial_not_found,       serial_found
PUBLIC  logiTech_failure,  lt_waitloop,            lt_waitloop2
PUBLIC  lt_waitloop3,      lt_cont,                lt_found
PUBLIC  look_for_PS2

; Function Names.

PUBLIC  setup_for_detect,    RestoreCOMSetting,      WriteControlRegister  
PUBLIC  TestForInport,       SetupForWait,           WriteInputBuffer      
PUBLIC  TestForBus,          IsWaitOver,             Write8042CommandByte   
PUBLIC  TestForSerial,       CheckForAuxSupport,     ResetPS2Mouse          
PUBLIC  TestForPS2,          MouseIntOff,            SendToMouse 
PUBLIC  SaveCOMSetting,      CheckForMSMouse,        SendToMouseAndTestData
PUBLIC  SetupCOMForMouse,    WriteControlRegister,   GetMouseData           
PUBLIC  ResetSerialMouse,    Read8042CommandByte,    CheckMouseData         
PUBLIC  CheckForLogitechPS2, TestForLogitechSerial,  setupForLogitechSerial

; Global Variable Names.

PUBLIC  LATLSBSave,   LCRSave,  IERSave,        fSingle8259  
PUBLIC  LATMSBSave,   MCRSave,  SemaphoreWord,  COM_3_4_ADDRS
   
ENDIF   ;DEBUG

TRUE           EQU    0ffh
FALSE          EQU    0

LW_ClockTickCount EQU    46Ch
HW_ClockTickCount EQU    46Eh

;************************************************************************
;               I N P O R T     D E F I N I T I O N S                   *
;************************************************************************

INP_ADDR        EQU     0               ; Inport addr register offset.
INP_DATA        EQU     1               ; Inport data register offset.
INP_ID          EQU     2               ; Inport ID register offset.
INP_TEST        EQU     3               ; Inport test register offset.

INPORT_ID       EQU     0DEh            ; InPort ID byte.

INP_STATUS_REG  EQU     0               ; Status register number.
INP_DATA1_REG   EQU     1               ; Internal data register 1.
INP_DATA2_REG   EQU     2               ; Internal data register 2.
INP_MODE_REG    EQU     7               ; Mode register number.

INP_RESET       EQU     10000000b       ; Value to reset InPort.

HZ0INTR0        EQU     00000000b       ; Value to select 0 Hz, INTR=0
HZ0INTR1        EQU     00000110b       ; Value to select 0 Hz, INTR=1
HZ30            EQU     00000001b       ; Value to select 30 Hz.
DATA_INT_ENAB   EQU     00001000b       ; Data int enable bit.
TIMER_INT_ENAB  EQU     00010000b       ; Timer int enable bit.
HOLD_BIT        EQU     00100000b       ; Hold bit.

BUTTON_1_BIT    EQU     00000100b       ; Bit indicating button 1.
BUTTON_3_BIT    EQU     00000001b       ; Bit indicating button 3.
MOVEMENT_BIT    EQU     01000000b       ; Bit indicating movement.

INPORT_FIRST_PORT EQU   23Ch            ; Address of primary InPort.
INPORT_LAST_PORT EQU    238h            ; Address of secondary InPort.

MACH20_IRQ      EQU     0Ch             ; IRQ used for Mach 20 InPort
                                        ; under Mach 20 OS/2.

;****************************************************************
;               B U S   D E F I N I T I O N S                   *
;****************************************************************
; Since the Adaptor for the bus mouse is based on an 8255A, we have to
;       program the 8255A properly in order to function. We need to select:
;
;       Mode 0 (for all ports).
;       Port A (input - this allows us to read information from the ALPS
;               chip and from the buttons)
;       Port B (output - this allows us to write a value there and then
;               read it back in. It is not connected to anything)
;       Port C, upper half (output - this allows us to send control
;               information to the ALPS chip)
;       Port C, lower half (input - this allows us to poll the current states
;               of IRQs 2, 3, 4, and 5)
;
; The value that does this is
;
;       10010001
;       ||||||||-----   Port C Lower is input
;       |||||||------   Port B is output
;       ||||||-------   Mode 0 for Group B (Port B and lower half of Port C)
;       |||||--------   Port C Upper is output
;       ||||---------   Port A is input
;       |------------   Mode 0 for Group A (Port A and upper half of Port C)
;       -------------   Mode set control word
;

BUS_MOUSE_BASE  EQU     023Ch           ; Base I/O addr of bus mouse.

BUS_DATA        EQU     BUS_MOUSE_BASE  ; Port where mouse data is read from.
BUS_SIG         EQU     BUS_MOUSE_BASE + 1 ; Port unused for mouse, used for de-
                                        ; termining existence of bus adaptor.
BUS_CONTROL     EQU     BUS_MOUSE_BASE + 2 ; Port used to control adaptor.
BUS_INIT        EQU     BUS_MOUSE_BASE + 3 ; Port used to init bus adaptor.

BUS_INIT_VALUE  EQU     10010001b       ; Value used to init bus adaptor.

LOW_X           EQU     090h            ; Cmd to read low 4 bits of delta X
HI_X            EQU     0B0h            ; Cmd to read high 2 bits of delta X
LOW_Y           EQU     0D0h            ; Cmd to read low 4 bits of delta Y
HI_Y            EQU     0F0h            ; Cmd to read high 2 bits of delta Y

;************************************************************************
;               S E R I A L     D E F I N I T I O N S                   *
;************************************************************************

SERIAL_PACKETSIZE       EQU     3       ; Bytes in a packet of data.

SYNC_BIT                EQU     40H     ; Bit 6 is the sync bit

;
; These are the offsets within the COM chip of the various registers.
;

TXB             EQU     0               ; Transmit buffer
RXB             EQU     0               ; Receive buffer
LATLSB          EQU     0               ; Divisor latch, LSB
LATMSB          EQU     1               ; Divisor latch, MSB
IER             EQU     1               ; Interrupt enable register
IIR             EQU     2               ; Interrupt identification register
LCR             EQU     3               ; Line control register
MCR             EQU     4               ; Modem control register
LSR             EQU     5               ; Line status register
MSR             EQU     6               ; Modem status register

;
; These give the number of milliseconds to wait while waiting for the serial
;       mouse to reset itself. We will first use the value given by SHORTDELAY
;       and if that fails, we will then use the value given by LONGDELAY.
;

SHORTDELAY      EQU     6        ; 350  msecs  = 350/55.5  = 6  clock ticks.
LONGDELAY       EQU     18       ; 1000 msecs  = 1000/55.5 = 18 clock ticks.

;
; These are the values that are written into the divisor latch for the
;       various baud rates. They are obtained by dividing the clock rate
;       (1.8432 MHz) by 16x the desired baud rate.
;

DIV_50          EQU     900h
DIV_75          EQU     600h
DIV_110         EQU     417h
DIV_150         EQU     300h
DIV_300         EQU     180h
DIV_600         EQU     0C0h
DIV_1200        EQU     060h
DIV_1800        EQU     040h
DIV_2000        EQU     03Ah
DIV_2400        EQU     030h
DIV_3600        EQU     020h
DIV_4800        EQU     018h
DIV_7200        EQU     010h
DIV_9600        EQU     00Ch

;
;** Interrupt enable masks
;

IE_RX           EQU     00000001b       ; read data available
IE_TX           EQU     00000010b       ; transmit buffer empty
IE_LX           EQU     00000100b       ; line status change
IE_MX           EQU     00001000b       ; modem status change

;
;** Line control masks
;

LC_BMASK        EQU     00000011b       ; data bits mask
LC_BITS5        EQU     00000000b       ; 5 data bits
LC_BITS6        EQU     00000001b       ; 6 data bits
LC_BITS7        EQU     00000010b       ; 7 data bits
LC_BITS8        EQU     00000011b       ; 8 data bits

LC_SMASK        EQU     00000100b       ; stop bits mask
LC_STOP1        EQU     00000000b       ; 1 stop bit
LC_STOP2        EQU     00000100b       ; 2 stop bits (1.5 if 5 data bits)

LC_PMASK        EQU     00111000b       ; parity mask
LC_PNONE        EQU     00000000b       ; none parity
LC_PODD         EQU     00001000b       ; odd parity
LC_PEVEN        EQU     00011000b       ; even parity
LC_PMARK        EQU     00101000b       ; mark parity
LC_PSPACE       EQU     00111000b       ; space parity

LC_BREAK        EQU     01000000b       ; transmit break
LC_DLAB         EQU     10000000b       ; divisor latch access bit
LC_MASK         EQU     01111111b       ; documented line control register bits

;
;** Modem control register masks
;

MC_DTR          EQU     00000001b       ; data terminal ready
MC_RTS          EQU     00000010b       ; request to send
MC_OUT1         EQU     00000100b       ; output 1
MC_OUT2         EQU     00001000b       ; output 2
MC_LOOP         EQU     00010000b       ; loopback mode

;
;** Line status register masks
;

LS_DR           EQU     00000001b       ; data ready
LS_OERR         EQU     00000010b       ; overrun error
LS_PERR         EQU     00000100b       ; parity error
LS_FERR         EQU     00001000b       ; framing error
LS_BI           EQU     00010000b       ; break interrupt
LS_THRE         EQU     00100000b       ; TX holding register empty
LS_TSRE         EQU     01000000b       ; TX shift register empty

;
;** Modem status register definitions:
;

MS_DCTS         EQU     00000001b       ; delta clear to send
MS_DDSR         EQU     00000010b       ; delta data set ready
MS_TERI         EQU     00000100b       ; trailing edge of ring indicator
MS_DDCD         EQU     00001000b       ; delta receiver line signal detect
MS_CTS          EQU     00010000b       ; clear to send
MS_DSR          EQU     00100000b       ; data set ready
MS_RI           EQU     01000000b       ; ring indicator
MS_DCD          EQU     10000000b       ; receiver line signal detect

;************************************************************************
;               8 2 5 9 A  D E F I N I T I O N S                        *
;************************************************************************

MASTER_MASK_ADDR EQU     021h            ; Master's mask register addr.
SLAVE_MASK_ADDR  EQU     0A1h            ; Slave's mask register addr.
IRQS_PER_8259    EQU     8               ; # IRQs on each 8259A.
SELECT_IRR       EQU     0Ah             ; Selects int request register.
SELECT_ISR       EQU     0Bh             ; Selects in service register.

;****************************************************************
;               P S / 2   D E F I N I T I O N S                 *
;****************************************************************

PS2_IRQ         EQU     0Ch             ; Always IRQ 12 for PS/2 mouse.
PS2_IRQ_MASK    EQU     00010000b       ; Bit mask for IRQ 12.
PS2_PACKETSIZE  EQU     3               ; Bytes in a packet of data.

DX_SIGN         EQU     00010000b       ; Bit 4 is dx sign bit in status byte
DY_SIGN         EQU     00100000b       ; Bit 5 is dy sign bit in status byte

PS2_25PPI       EQU     0               ; Value to set resolution to 25 ppi.
PS2_50PPI       EQU     1               ; Value to set resolution to 50 ppi.
PS2_100PPI      EQU     2               ; Value to set resolution to 100 ppi.
PS2_200PPI      EQU     3               ; Value to set resolution to 200 ppi.


MCMD_RESET      EQU     0FFh            ; Reset mouse command
MCMD_RESEND     EQU     0FEh            ; Resend data to mouse
MCMD_DIAG_ERR   EQU     0FCh            ; Error on mouse diagnostics
MCMD_ACK        EQU     0FAh            ; Acknowledge
MCMD_DEFAULT    EQU     0F6h
MCMD_DISABLE    EQU     0F5h            ; Disable Mouse command
MCMD_ENABLE     EQU     0F4h            ; Enable Mouse command
MCMD_RATE       EQU     0F3h            ; Set sampling rate
MCMD_READ_TYPE  EQU     0F2h            ; Read device type
MCMD_REMOTE     EQU     0F0h            ; Set remote mode
MCMD_ECHO       EQU     0EEh            ; Set wrap mode
MCMD_KILL_ECHO  EQU     0ECh            ; reset wrap mode
MCMD_READDATA   EQU     0EBh            ; Read mouse data
MCMD_STREAM     EQU     0EAh            ; Set stream mode
MCMD_STATUS     EQU     0E9h            ; Status Request
MCMD_RESOLUTION EQU     0E8h            ; Set Resolution
MCMD_SCALE_2_1  EQU     0E7h            ; Set scaling 2 to 1
MCMD_SCALE_1_1  EQU     0E6h            ; Set scaling 1 to 1
MCMD_DIAG_OK    EQU     0AAh            ; Diagnostics ok
MCMD_DIAG_ID    EQU     000h            ; Diagnostic ID number

;
; The following codes are specific to the Microsoft PS/2 mouse
;

MCMD_MS_VERS    EQU     052h            ; Read current firmware version number
MCMD_MS_INPORT  EQU     056h            ; Read raw InPort data
MCDM_MS_DIAG    EQU     059h            ; enter MS diagnostices mode
MCMD_MS_READRAM EQU     05Bh            ; read ram byte

;****************************************************************
;               8 0 4 2  D E F I N I T I O N S                  *
;****************************************************************

;
; 8042 port definitions.
;

DATA_8042       EQU     60h             ; Port where data is sent to/from 8042.
CONTROL_8042    EQU     64h             ; Port where commands are sent to 8042.
STATUS_8042     EQU     64h             ; Port where status is read from 8042.
CRT_DATA_SEG	EQU	40H     	; ROM BIOS CRT Data Segment Address

;
; Status register bit definitions.
;

O_FULL          EQU     01h             ; 8042's output buffer is full.
I_FULL          EQU     02h             ; 8042's input buffer is full.
A_FULL          EQU     20h             ; 8042's aux output buffer is full.

;
; Command byte bit definitions.
;

AUX_DISABLED    EQU     20h             ; Auxiliary interface is disabled.
AUX_INT_ENABLE  EQU     02h             ; Auxiliary interrupts are enabled.

;
; 8042 commands.
;

CMD8042_READ_CMD EQU    020h            ; Read command byte.
CMD8042_WRITE_CMD EQU   060h            ; Write command byte.
CMD8042_DISABLE_AUX EQU 0A7h            ; Disable auxiliary interface.
CMD8042_ENABLE_AUX EQU  0A8h            ; Enable auxiliary interface.
CMD8042_TEST_AUX EQU    0A9h            ; Test auxiliary interface.
CMD8042_DISABLE_KBD EQU 0ADh            ; Disable keyboard.
CMD8042_ENABLE_KBD EQU  0AEh            ; Enable keyboard.
CMD8042_WRITE_AUX EQU   0D4h            ; Send data to auxiliary device.

