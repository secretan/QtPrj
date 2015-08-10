
#line 1 "..\src\bulkloop.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 #pragma NOIV 
 
  
#line 1 "../inc\fx2.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern int start_7_seg_display;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
 
 
 
 
 


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
 
 
 

 
 

 
 
 
 
 
 
 typedef unsigned char   BYTE;
 typedef unsigned short   WORD;
 typedef unsigned long   DWORD;
 typedef bit            BOOL;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef struct
 {
 BYTE   length;
 BYTE   type;
 }DSCR;
 
 typedef struct             
 {
 BYTE   length;          
 BYTE   type;          
 BYTE   spec_ver_minor;    
 BYTE   spec_ver_major;    
 BYTE   dev_class;       
 BYTE   sub_class;       
 BYTE   protocol;       
 BYTE   max_packet;       
 WORD   vendor_id;       
 WORD   product_id;       
 WORD   version_id;       
 BYTE   mfg_str;       
 BYTE   prod_str;       
 BYTE   serialnum_str;    
 BYTE   configs;       
 }DEVICEDSCR;
 
 typedef struct             
 {
 BYTE   length;          
 BYTE   type;          
 BYTE   spec_ver_minor;    
 BYTE   spec_ver_major;    
 BYTE   dev_class;       
 BYTE   sub_class;       
 BYTE   protocol;       
 BYTE   max_packet;       
 BYTE   configs;       
 BYTE  reserved0;
 }DEVICEQUALDSCR;
 
 typedef struct
 {
 BYTE   length;          
 BYTE   type;          
 WORD   config_len;       
 BYTE   interfaces;       
 BYTE   index;          
 BYTE   config_str;       
 BYTE   attrib;          
 BYTE   power;          
 }CONFIGDSCR;
 
 typedef struct
 {
 BYTE   length;          
 BYTE   type;          
 BYTE   index;          
 BYTE   alt_setting;    
 BYTE   ep_cnt;          
 BYTE   class;          
 BYTE   sub_class;       
 BYTE   protocol;       
 BYTE   interface_str;    
 }INTRFCDSCR;
 
 typedef struct
 {
 BYTE   length;          
 BYTE   type;          
 BYTE   addr;          
 BYTE   ep_type;       
 BYTE   mp_L;          
 BYTE   mp_H;
 BYTE   interval;       
 }ENDPNTDSCR;
 
 typedef struct
 {
 BYTE   length;          
 BYTE   type;          
 }STRINGDSCR;
 
 typedef struct
 {
 BYTE   cntrl;          
 BYTE   bytes;          
 }EPIOC;
 
 typedef struct 
 {
 BYTE   length;
 BYTE   *dat;
 BYTE   count;
 BYTE   status;
 }I2CPCKT;
 
 
 
 
 extern code BYTE   USB_AutoVector;
 
 extern WORD   pDeviceDscr;
 extern WORD   pDeviceQualDscr;
 extern WORD	  pHighSpeedConfigDscr;
 extern WORD	  pFullSpeedConfigDscr;	
 extern WORD   pConfigDscr;
 extern WORD   pOtherConfigDscr;
 extern WORD   pStringDscr;
 
 extern code DEVICEDSCR        DeviceDscr;
 extern code DEVICEQUALDSCR    DeviceQualDscr;
 extern code CONFIGDSCR        HighSpeedConfigDscr;
 extern code CONFIGDSCR        FullSpeedConfigDscr;
 extern code STRINGDSCR        StringDscr;
 extern code DSCR              UserDscr;
 
 extern I2CPCKT   I2CPckt;
 
 
 
 
 
 extern void EZUSB_Renum(void);
 extern void EZUSB_Discon(BOOL renum);
 
 extern void EZUSB_Susp(void);
 extern void EZUSB_Resume(void);
 
 extern void EZUSB_Delay1ms(void);
 extern void EZUSB_Delay(WORD ms);
 
 extern CONFIGDSCR xdata*   EZUSB_GetConfigDscr(BYTE ConfigIdx);
 extern INTRFCDSCR xdata*   EZUSB_GetIntrfcDscr(BYTE ConfigIdx, BYTE IntrfcIdx, BYTE AltSetting);
 extern STRINGDSCR xdata*   EZUSB_GetStringDscr(BYTE StrIdx);
 extern DSCR xdata*      EZUSB_GetDscr(BYTE index, DSCR* dscr, BYTE type);
 
 extern void EZUSB_InitI2C(void);
 extern BOOL EZUSB_WriteI2C_(BYTE addr, BYTE length, BYTE xdata *dat);
 extern BOOL EZUSB_ReadI2C_(BYTE addr, BYTE length, BYTE xdata *dat);
 extern BOOL EZUSB_WriteI2C(BYTE addr, BYTE length, BYTE xdata *dat);
 extern BOOL EZUSB_ReadI2C(BYTE addr, BYTE length, BYTE xdata *dat);
 extern void EZUSB_WaitForEEPROMWrite(BYTE addr);
 
 extern void modify_endpoint_stall(BYTE epid, BYTE stall);
 
 
#line 151 "..\src\bulkloop.c" /0
 
  
#line 1 "../inc\fx2regs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 35 "../inc\fx2regs.h" /1
  
  
 
#line 38 "../inc\fx2regs.h" /0
 
 
 
 
  extern xdata volatile BYTE GPIF_WAVE_DATA    ; 
  extern xdata volatile BYTE RES_WAVEDATA_END  ; 
 
 
 
  extern xdata volatile BYTE CPUCS             ; 
  extern xdata volatile BYTE IFCONFIG          ; 
  extern xdata volatile BYTE PINFLAGSAB        ; 
  extern xdata volatile BYTE PINFLAGSCD        ; 
  extern xdata volatile BYTE FIFORESET         ; 
  extern xdata volatile BYTE BREAKPT           ; 
  extern xdata volatile BYTE BPADDRH           ; 
  extern xdata volatile BYTE BPADDRL           ; 
  extern xdata volatile BYTE UART230           ; 
  extern xdata volatile BYTE FIFOPINPOLAR      ; 
  extern xdata volatile BYTE REVID             ; 
  extern xdata volatile BYTE REVCTL            ; 
 
 
 
  extern xdata volatile BYTE EP1OUTCFG         ; 
  extern xdata volatile BYTE EP1INCFG          ; 
  extern xdata volatile BYTE EP2CFG            ; 
  extern xdata volatile BYTE EP4CFG            ; 
  extern xdata volatile BYTE EP6CFG            ; 
  extern xdata volatile BYTE EP8CFG            ; 
  extern xdata volatile BYTE EP2FIFOCFG        ; 
  extern xdata volatile BYTE EP4FIFOCFG        ; 
  extern xdata volatile BYTE EP6FIFOCFG        ; 
  extern xdata volatile BYTE EP8FIFOCFG        ; 
  extern xdata volatile BYTE EP2AUTOINLENH     ; 
  extern xdata volatile BYTE EP2AUTOINLENL     ; 
  extern xdata volatile BYTE EP4AUTOINLENH     ; 
  extern xdata volatile BYTE EP4AUTOINLENL     ; 
  extern xdata volatile BYTE EP6AUTOINLENH     ; 
  extern xdata volatile BYTE EP6AUTOINLENL     ; 
  extern xdata volatile BYTE EP8AUTOINLENH     ; 
  extern xdata volatile BYTE EP8AUTOINLENL     ; 
  extern xdata volatile BYTE EP2FIFOPFH        ; 
  extern xdata volatile BYTE EP2FIFOPFL        ; 
  extern xdata volatile BYTE EP4FIFOPFH        ; 
  extern xdata volatile BYTE EP4FIFOPFL        ; 
  extern xdata volatile BYTE EP6FIFOPFH        ; 
  extern xdata volatile BYTE EP6FIFOPFL        ; 
  extern xdata volatile BYTE EP8FIFOPFH        ; 
  extern xdata volatile BYTE EP8FIFOPFL        ; 
  extern xdata volatile BYTE EP2ISOINPKTS      ; 
  extern xdata volatile BYTE EP4ISOINPKTS      ; 
  extern xdata volatile BYTE EP6ISOINPKTS      ; 
  extern xdata volatile BYTE EP8ISOINPKTS      ; 
  extern xdata volatile BYTE INPKTEND          ; 
  extern xdata volatile BYTE OUTPKTEND         ; 
 
 
 
  extern xdata volatile BYTE EP2FIFOIE         ; 
  extern xdata volatile BYTE EP2FIFOIRQ        ; 
  extern xdata volatile BYTE EP4FIFOIE         ; 
  extern xdata volatile BYTE EP4FIFOIRQ        ; 
  extern xdata volatile BYTE EP6FIFOIE         ; 
  extern xdata volatile BYTE EP6FIFOIRQ        ; 
  extern xdata volatile BYTE EP8FIFOIE         ; 
  extern xdata volatile BYTE EP8FIFOIRQ        ; 
  extern xdata volatile BYTE IBNIE             ; 
  extern xdata volatile BYTE IBNIRQ            ; 
  extern xdata volatile BYTE NAKIE             ; 
  extern xdata volatile BYTE NAKIRQ            ; 
  extern xdata volatile BYTE USBIE             ; 
  extern xdata volatile BYTE USBIRQ            ; 
  extern xdata volatile BYTE EPIE              ; 
  extern xdata volatile BYTE EPIRQ             ; 
  extern xdata volatile BYTE GPIFIE            ; 
  extern xdata volatile BYTE GPIFIRQ           ; 
  extern xdata volatile BYTE USBERRIE          ; 
  extern xdata volatile BYTE USBERRIRQ         ; 
  extern xdata volatile BYTE ERRCNTLIM         ; 
  extern xdata volatile BYTE CLRERRCNT         ; 
  extern xdata volatile BYTE INT2IVEC          ; 
  extern xdata volatile BYTE INT4IVEC          ; 
  extern xdata volatile BYTE INTSETUP          ; 
 
 
 
  extern xdata volatile BYTE PORTACFG          ; 
  extern xdata volatile BYTE PORTCCFG          ; 
  extern xdata volatile BYTE PORTECFG          ; 
  extern xdata volatile BYTE I2CS              ; 
  extern xdata volatile BYTE I2DAT             ; 
  extern xdata volatile BYTE I2CTL             ; 
  extern xdata volatile BYTE XAUTODAT1         ; 
  extern xdata volatile BYTE XAUTODAT2         ; 
 
 
 
 
 
 
  extern xdata volatile BYTE USBCS             ; 
  extern xdata volatile BYTE SUSPEND           ; 
  extern xdata volatile BYTE WAKEUPCS          ; 
  extern xdata volatile BYTE TOGCTL            ; 
  extern xdata volatile BYTE USBFRAMEH         ; 
  extern xdata volatile BYTE USBFRAMEL         ; 
  extern xdata volatile BYTE MICROFRAME        ; 
  extern xdata volatile BYTE FNADDR            ; 
 
 
 
  extern xdata volatile BYTE EP0BCH            ; 
  extern xdata volatile BYTE EP0BCL            ; 
  extern xdata volatile BYTE EP1OUTBC          ; 
  extern xdata volatile BYTE EP1INBC           ; 
  extern xdata volatile BYTE EP2BCH            ; 
  extern xdata volatile BYTE EP2BCL            ; 
  extern xdata volatile BYTE EP4BCH            ; 
  extern xdata volatile BYTE EP4BCL            ; 
  extern xdata volatile BYTE EP6BCH            ; 
  extern xdata volatile BYTE EP6BCL            ; 
  extern xdata volatile BYTE EP8BCH            ; 
  extern xdata volatile BYTE EP8BCL            ; 
  extern xdata volatile BYTE EP0CS             ; 
  extern xdata volatile BYTE EP1OUTCS          ; 
  extern xdata volatile BYTE EP1INCS           ; 
  extern xdata volatile BYTE EP2CS             ; 
  extern xdata volatile BYTE EP4CS             ; 
  extern xdata volatile BYTE EP6CS             ; 
  extern xdata volatile BYTE EP8CS             ; 
  extern xdata volatile BYTE EP2FIFOFLGS       ; 
  extern xdata volatile BYTE EP4FIFOFLGS       ; 
  extern xdata volatile BYTE EP6FIFOFLGS       ; 
  extern xdata volatile BYTE EP8FIFOFLGS       ; 
  extern xdata volatile BYTE EP2FIFOBCH        ; 
  extern xdata volatile BYTE EP2FIFOBCL        ; 
  extern xdata volatile BYTE EP4FIFOBCH        ; 
  extern xdata volatile BYTE EP4FIFOBCL        ; 
  extern xdata volatile BYTE EP6FIFOBCH        ; 
  extern xdata volatile BYTE EP6FIFOBCL        ; 
  extern xdata volatile BYTE EP8FIFOBCH        ; 
  extern xdata volatile BYTE EP8FIFOBCL        ; 
  extern xdata volatile BYTE SUDPTRH           ; 
  extern xdata volatile BYTE SUDPTRL           ; 
  extern xdata volatile BYTE SUDPTRCTL         ; 
  extern xdata volatile BYTE SETUPDAT[8]       ; 
 
 
 
  extern xdata volatile BYTE GPIFWFSELECT      ; 
  extern xdata volatile BYTE GPIFIDLECS        ; 
  extern xdata volatile BYTE GPIFIDLECTL       ; 
  extern xdata volatile BYTE GPIFCTLCFG        ; 
  extern xdata volatile BYTE GPIFADRH          ; 
  extern xdata volatile BYTE GPIFADRL          ; 
 
  extern xdata volatile BYTE GPIFTCB3          ; 
  extern xdata volatile BYTE GPIFTCB2          ; 
  extern xdata volatile BYTE GPIFTCB1          ; 
  extern xdata volatile BYTE GPIFTCB0          ; 
 
 
 
 
 
 
 
 
 
 
  extern xdata volatile BYTE EP2GPIFFLGSEL     ; 
  extern xdata volatile BYTE EP2GPIFPFSTOP     ; 
  extern xdata volatile BYTE EP2GPIFTRIG       ; 
  extern xdata volatile BYTE EP4GPIFFLGSEL     ; 
  extern xdata volatile BYTE EP4GPIFPFSTOP     ; 
  extern xdata volatile BYTE EP4GPIFTRIG       ; 
  extern xdata volatile BYTE EP6GPIFFLGSEL     ; 
  extern xdata volatile BYTE EP6GPIFPFSTOP     ; 
  extern xdata volatile BYTE EP6GPIFTRIG       ; 
  extern xdata volatile BYTE EP8GPIFFLGSEL     ; 
  extern xdata volatile BYTE EP8GPIFPFSTOP     ; 
  extern xdata volatile BYTE EP8GPIFTRIG       ; 
  extern xdata volatile BYTE XGPIFSGLDATH      ; 
  extern xdata volatile BYTE XGPIFSGLDATLX     ; 
  extern xdata volatile BYTE XGPIFSGLDATLNOX   ; 
  extern xdata volatile BYTE GPIFREADYCFG      ; 
  extern xdata volatile BYTE GPIFREADYSTAT     ; 
  extern xdata volatile BYTE GPIFABORT         ; 
 
 
 
  extern xdata volatile BYTE FLOWSTATE         ; 
  extern xdata volatile BYTE FLOWLOGIC         ; 
  extern xdata volatile BYTE FLOWEQ0CTL        ; 
  extern xdata volatile BYTE FLOWEQ1CTL        ; 
  extern xdata volatile BYTE FLOWHOLDOFF       ; 
  extern xdata volatile BYTE FLOWSTB           ; 
  extern xdata volatile BYTE FLOWSTBEDGE       ; 
  extern xdata volatile BYTE FLOWSTBHPERIOD    ; 
  extern xdata volatile BYTE GPIFHOLDAMOUNT    ; 
  extern xdata volatile BYTE UDMACRCH          ; 
  extern xdata volatile BYTE UDMACRCL          ; 
  extern xdata volatile BYTE UDMACRCQUAL       ; 
 
 
 
 
 
 
  extern xdata volatile BYTE DBUG              ; 
  extern xdata volatile BYTE TESTCFG           ; 
  extern xdata volatile BYTE USBTEST           ; 
  extern xdata volatile BYTE CT1               ; 
  extern xdata volatile BYTE CT2               ; 
  extern xdata volatile BYTE CT3               ; 
  extern xdata volatile BYTE CT4               ; 
 
 
 
  extern xdata volatile BYTE EP0BUF[64]        ; 
  extern xdata volatile BYTE EP1OUTBUF[64]     ; 
  extern xdata volatile BYTE EP1INBUF[64]      ; 
  extern xdata volatile BYTE EP2FIFOBUF[1024]  ; 
  extern xdata volatile BYTE EP4FIFOBUF[1024]  ; 
  extern xdata volatile BYTE EP6FIFOBUF[1024]  ; 
  extern xdata volatile BYTE EP8FIFOBUF[1024]  ; 
 
 
 
  extern xdata volatile BYTE ECCCFG            ; 
  extern xdata volatile BYTE ECCRESET          ; 
  extern xdata volatile BYTE ECC1B0            ; 
  extern xdata volatile BYTE ECC1B1            ; 
  extern xdata volatile BYTE ECC1B2            ; 
  extern xdata volatile BYTE ECC2B0            ; 
  extern xdata volatile BYTE ECC2B1            ; 
  extern xdata volatile BYTE ECC2B2            ; 
 
 
  extern xdata volatile BYTE GPCR2             ; 
 
 
 
 






 
 
 sfr IOA     = 0x80;
 
 sbit PA0    = 0x80 + 0;
 sbit PA1    = 0x80 + 1;
 sbit PA2    = 0x80 + 2;
 sbit PA3    = 0x80 + 3;
 
 sbit PA4    = 0x80 + 4;
 sbit PA5    = 0x80 + 5;
 sbit PA6    = 0x80 + 6;
 sbit PA7    = 0x80 + 7;
 sfr SP      = 0x81;
 sfr DPL     = 0x82;
 sfr DPH     = 0x83;
 sfr DPL1    = 0x84;
 sfr DPH1    = 0x85;
 sfr DPS     = 0x86;
 
 
 sfr PCON    = 0x87;
 
 
 
 
 
 
 sfr TCON    = 0x88;
 
 sbit IT0    = 0x88+0;
 sbit IE0    = 0x88+1;
 sbit IT1    = 0x88+2;
 sbit IE1    = 0x88+3;
 sbit TR0    = 0x88+4;
 sbit TF0    = 0x88+5;
 sbit TR1    = 0x88+6;
 sbit TF1    = 0x88+7;
 sfr TMOD    = 0x89;
 
 
 
 
 
 
 
 
 
 sfr TL0     = 0x8A;
 sfr TL1     = 0x8B;
 sfr TH0     = 0x8C;
 sfr TH1     = 0x8D;
 sfr CKCON   = 0x8E;
 
 
 
 
 
 
 
 sfr SPC_FNC = 0x8F;  
 
 
 sfr IOB     = 0x90;
 
 sbit PB0    = 0x90 + 0;
 sbit PB1    = 0x90 + 1;
 sbit PB2    = 0x90 + 2;
 sbit PB3    = 0x90 + 3;
 
 sbit PB4    = 0x90 + 4;
 sbit PB5    = 0x90 + 5;
 sbit PB6    = 0x90 + 6;
 sbit PB7    = 0x90 + 7;
 sfr EXIF    = 0x91;  
 
 
 
 
 
 sfr MPAGE  = 0x92;
 sfr SCON0  = 0x98;
 
 sbit RI    = 0x98+0;
 sbit TI    = 0x98+1;
 sbit RB8   = 0x98+2;
 sbit TB8   = 0x98+3;
 sbit REN   = 0x98+4;
 sbit SM2   = 0x98+5;
 sbit SM1   = 0x98+6;
 sbit SM0   = 0x98+7;
 sfr SBUF0  = 0x99;
 
 
 
 
 
 
 
 sfr AUTOPTRH1     = 0x9A; 
 sfr AUTOPTRL1     = 0x9B; 
 sfr AUTOPTRH2     = 0x9D;
 sfr AUTOPTRL2     = 0x9E; 
 
 sfr IOC        = 0xA0;
 
 sbit PC0    = 0xA0 + 0;
 sbit PC1    = 0xA0 + 1;
 sbit PC2    = 0xA0 + 2;
 sbit PC3    = 0xA0 + 3;
 
 sbit PC4    = 0xA0 + 4;
 sbit PC5    = 0xA0 + 5;
 sbit PC6    = 0xA0 + 6;
 sbit PC7    = 0xA0 + 7;
 sfr INT2CLR    = 0xA1;
 sfr INT4CLR    = 0xA2;
 
 sfr IE     = 0xA8;
 
 sbit EX0   = 0xA8+0;
 sbit ET0   = 0xA8+1;
 sbit EX1   = 0xA8+2;
 sbit ET1   = 0xA8+3;
 sbit ES0   = 0xA8+4;
 sbit ET2   = 0xA8+5;
 sbit ES1   = 0xA8+6;
 sbit EA    = 0xA8+7;
 
 sfr EP2468STAT     = 0xAA;
 
 
 
 
 
 
 
 
 
 
 sfr EP24FIFOFLGS   = 0xAB;
 sfr EP68FIFOFLGS   = 0xAC;
 sfr AUTOPTRSETUP  = 0xAF;
 
 
 
 
 
 sfr IOD     = 0xB0;
 
 sbit PD0    = 0xB0 + 0;
 sbit PD1    = 0xB0 + 1;
 sbit PD2    = 0xB0 + 2;
 sbit PD3    = 0xB0 + 3;
 
 sbit PD4    = 0xB0 + 4;
 sbit PD5    = 0xB0 + 5;
 sbit PD6    = 0xB0 + 6;
 sbit PD7    = 0xB0 + 7;
 sfr IOE     = 0xB1;
 sfr OEA     = 0xB2;
 sfr OEB     = 0xB3;
 sfr OEC     = 0xB4;
 sfr OED     = 0xB5;
 sfr OEE     = 0xB6;
 
 sfr IP     = 0xB8;
 
 sbit PX0   = 0xB8+0;
 sbit PT0   = 0xB8+1;
 sbit PX1   = 0xB8+2;
 sbit PT1   = 0xB8+3;
 sbit PS0   = 0xB8+4;
 sbit PT2   = 0xB8+5;
 sbit PS1   = 0xB8+6;
 
 sfr EP01STAT    = 0xBA;
 sfr GPIFTRIG    = 0xBB;
 
 sfr GPIFSGLDATH     = 0xBD;
 sfr GPIFSGLDATLX    = 0xBE;
 sfr GPIFSGLDATLNOX  = 0xBF;
 
 sfr SCON1  = 0xC0;
 
 sbit RI1   = 0xC0+0;
 sbit TI1   = 0xC0+1;
 sbit RB81  = 0xC0+2;
 sbit TB81  = 0xC0+3;
 sbit REN1  = 0xC0+4;
 sbit SM21  = 0xC0+5;
 sbit SM11  = 0xC0+6;
 sbit SM01  = 0xC0+7;
 sfr SBUF1  = 0xC1;
 sfr T2CON  = 0xC8;
 
 sbit CP_RL2 = 0xC8+0;
 sbit C_T2  = 0xC8+1;
 sbit TR2   = 0xC8+2;
 sbit EXEN2 = 0xC8+3;
 sbit TCLK  = 0xC8+4;
 sbit RCLK  = 0xC8+5;
 sbit EXF2  = 0xC8+6;
 sbit TF2   = 0xC8+7;
 sfr RCAP2L = 0xCA;
 sfr RCAP2H = 0xCB;
 sfr TL2    = 0xCC;
 sfr TH2    = 0xCD;
 sfr PSW    = 0xD0;
 
 sbit P     = 0xD0+0;
 sbit FL    = 0xD0+1;
 sbit OV    = 0xD0+2;
 sbit RS0   = 0xD0+3;
 sbit RS1   = 0xD0+4;
 sbit F0    = 0xD0+5;
 sbit AC    = 0xD0+6;
 sbit CY    = 0xD0+7;
 sfr EICON  = 0xD8;  
 
 sbit INT6  = 0xD8+3;
 sbit RESI  = 0xD8+4;
 sbit ERESI = 0xD8+5;
 sbit SMOD1 = 0xD8+7;
 sfr ACC    = 0xE0;
 sfr EIE    = 0xE8;  
 
 sbit EUSB    = 0xE8+0;
 sbit EI2C    = 0xE8+1;
 sbit EIEX4   = 0xE8+2;
 sbit EIEX5   = 0xE8+3;
 sbit EIEX6   = 0xE8+4;
 sfr B      = 0xF0;
 sfr EIP    = 0xF8;  
 
 sbit PUSB    = 0xF8+0;
 sbit PI2C    = 0xF8+1;
 sbit EIPX4   = 0xF8+2;
 sbit EIPX5   = 0xF8+3;
 sbit EIPX6   = 0xF8+4;
 


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
#line 152 "..\src\bulkloop.c" /0
 
  
#line 1 "../inc\syncdly.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "D:\Keil_v5\C51\inc\intrins.h" /0






 
 
 
 
 
 #pragma SAVE
 
 
#line 15 "D:\Keil_v5\C51\inc\intrins.h" /1
 
 
 
#line 18 "D:\Keil_v5\C51\inc\intrins.h" /0
 
 extern void          _nop_     (void);
 extern bit           _testbit_ (bit);
 extern unsigned char _cror_    (unsigned char, unsigned char);
 extern unsigned int  _iror_    (unsigned int,  unsigned char);
 extern unsigned long _lror_    (unsigned long, unsigned char);
 extern unsigned char _crol_    (unsigned char, unsigned char);
 extern unsigned int  _irol_    (unsigned int,  unsigned char);
 extern unsigned long _lrol_    (unsigned long, unsigned char);
 extern unsigned char _chkfloat_(float);
 
#line 29 "D:\Keil_v5\C51\inc\intrins.h" /1
 
 
 
#line 32 "D:\Keil_v5\C51\inc\intrins.h" /0
 
 extern void          _push_    (unsigned char _sfr);
 extern void          _pop_     (unsigned char _sfr);
 
 
 #pragma RESTORE
 
 
 
#line 37 "../inc\syncdly.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 67 "../inc\syncdly.h" /1
 
 
#line 69 "../inc\syncdly.h" /0
 
 
#line 71 "../inc\syncdly.h" /1
 
 
#line 73 "../inc\syncdly.h" /0
 
 
#line 75 "../inc\syncdly.h" /1
 
 
 
 
 
 
#line 81 "../inc\syncdly.h" /0
 
 
 
 
 
#line 86 "../inc\syncdly.h" /1
  
 
#line 88 "../inc\syncdly.h" /0
 
 
#line 90 "../inc\syncdly.h" /1
  

 
#line 93 "../inc\syncdly.h" /0
 
 
 


 
 
 
#line 101 "../inc\syncdly.h" /1
  



 
#line 106 "../inc\syncdly.h" /0
 
 
#line 108 "../inc\syncdly.h" /1
  




 
#line 114 "../inc\syncdly.h" /0
 
 
#line 116 "../inc\syncdly.h" /1
  





 
#line 123 "../inc\syncdly.h" /0
 
 
#line 125 "../inc\syncdly.h" /1
  






 
#line 133 "../inc\syncdly.h" /0
 
 
#line 135 "../inc\syncdly.h" /1
  







 
#line 144 "../inc\syncdly.h" /0
 
 
#line 146 "../inc\syncdly.h" /1
  








 
#line 156 "../inc\syncdly.h" /0
 
 
#line 158 "../inc\syncdly.h" /1
  









 
#line 169 "../inc\syncdly.h" /0
 
 
#line 171 "../inc\syncdly.h" /1
  










 
#line 183 "../inc\syncdly.h" /0
 
 
#line 185 "../inc\syncdly.h" /1
  











 
#line 198 "../inc\syncdly.h" /0
 
 
#line 200 "../inc\syncdly.h" /1
  












 
#line 214 "../inc\syncdly.h" /0
 
 
#line 216 "../inc\syncdly.h" /1
  













 
#line 231 "../inc\syncdly.h" /0
 
 
#line 233 "../inc\syncdly.h" /1
  














 
#line 249 "../inc\syncdly.h" /0
 
 
#line 251 "../inc\syncdly.h" /1
  















 
#line 153 "..\src\bulkloop.c" /0
#line 153 "..\src\bulkloop.c" /0
 
 
 extern BOOL GotSUD;              
 extern BOOL Sleep;
 extern BOOL Rwuen;
 extern BOOL Selfpwr;
 
 BYTE Configuration;              
 BYTE AlternateSetting;           
 
 int start_7_seg_display = 0;   
 void EZUSB_INITI2C();
 
 
 
 
 
 
 
 
 
 
 xdata volatile BYTE D5OFF _at_ 0xB000;
 xdata volatile BYTE D4OFF _at_ 0xA000;
 xdata volatile BYTE D3OFF _at_ 0x9000;
 xdata volatile BYTE D2OFF _at_ 0x8000;
 xdata volatile BYTE D5ON  _at_ 0xB800;
 xdata volatile BYTE D4ON  _at_ 0xA800;
 xdata volatile BYTE D3ON  _at_ 0x9800;
 xdata volatile BYTE D2ON  _at_ 0x8800;
 
 int LEDCounter = 0;			 
 BYTE inblink = 0x00;		 
 BYTE outblink = 0x00;		 
 
 
 BYTE xdata Digit[] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x98, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e };
 
 
 
 
 
 
 void TD_Init(void)              
 {
 BYTE dum;					 
 CPUCS = ((CPUCS & ~(0x10 | 0x08)) | 0x10) ;	 
 
 
 
 dum = D2OFF;
 dum = D3OFF;
 dum = D4OFF;
 dum = D5OFF;
 
 
 
 
 
 
 
 
 
 
 EP2CFG = 0xA2;	 
  _nop_( ); _nop_( ); _nop_( );		 
 EP6CFG = 0xE2;	 
  _nop_( ); _nop_( ); _nop_( );                    
 
 
 
 EP2BCL = 0x80;  	 
  _nop_( ); _nop_( ); _nop_( );                    
 EP2BCL = 0x80;	 
  _nop_( ); _nop_( ); _nop_( );                    
 
 AUTOPTRSETUP |= 0x01;
 
 USBIE |= 0x02;				 
 EPIE = 0x40 | 0x10;	 
 }
 
 void TD_Poll(void)               
 {
 WORD i;
 WORD count;
 
 BYTE waiting_inpkts;
 
 
 if(start_7_seg_display)
 {
 
 waiting_inpkts = (EP6CS & 0xF0)>>4;
 EZUSB_WriteI2C(0x21, 0x01, &(Digit[waiting_inpkts]));
 EZUSB_WaitForEEPROMWrite(0x21);
 }
 
 
 
 
 
 
 
 
 if(!(EP2468STAT & 0x01))		 
 {
 if(!(EP2468STAT & 0x20))	 
 { 
  AUTOPTRH1 = (BYTE)(((WORD)(&EP2FIFOBUF) >> 8) & 0xff);
  AUTOPTRL1 = (BYTE)((WORD)(&EP2FIFOBUF) & 0xff);
 AUTOPTRH2 = (BYTE)(((WORD)(&EP6FIFOBUF) >> 8) & 0xff);
 AUTOPTRL2 = (BYTE)((WORD)(&EP6FIFOBUF) & 0xff);
 
 count = (EP2BCH << 8) + EP2BCL;
 
 
 for( i = 0; i < count; i++ )
 {
  XAUTODAT2 = XAUTODAT1;	 
 }
 EP6BCH = EP2BCH;		 
  _nop_( ); _nop_( ); _nop_( );  
 EP6BCL = EP2BCL;         
  _nop_( ); _nop_( ); _nop_( );                    
 EP2BCL = 0x80;           
 }
 }
 }
 
 BOOL TD_Suspend(void)           
 {
 return(1);
 }
 
 BOOL TD_Resume(void)           
 {
 return(1);
 }
 
 
 
 
 
 
 BOOL DR_GetDescriptor(void)
 {
 return(1);
 }
 
 BOOL DR_SetConfiguration(void)    
 {
 Configuration = SETUPDAT[2];
 
 
 EZUSB_INITI2C();				 
 start_7_seg_display = 1;
 
 
 return(1);             
 }
 
 BOOL DR_GetConfiguration(void)    
 {
 EP0BUF[0] = Configuration;
 EP0BCH = 0;
 EP0BCL = 1;
 return(1);             
 }
 
 BOOL DR_SetInterface(void)        
 {
 AlternateSetting = SETUPDAT[2];
 return(1);             
 }
 
 BOOL DR_GetInterface(void)        
 {
 EP0BUF[0] = AlternateSetting;
 EP0BCH = 0;
 EP0BCL = 1;
 return(1);             
 }
 
 BOOL DR_GetStatus(void)
 {
 return(1);
 }
 
 BOOL DR_ClearFeature(void)
 {
 return(1);
 }
 
 BOOL DR_SetFeature(void)
 {
 return(1);
 }
 
 BOOL DR_VendorCmnd(void)
 {
 return(1);
 }
 
 
 
 
 
 
 
 void ISR_Sudav(void) interrupt 0
 {
 GotSUD = 1;             
  EXIF &= ~0x10;
 USBIRQ = 0x01;          
 }
 
 
 void ISR_Sutok(void) interrupt 0
 {
  EXIF &= ~0x10;
 USBIRQ = 0x04;          
 }
 
 void ISR_Sof(void) interrupt 0
 {
 BYTE dum;
 BYTE Led_Flag = 0;
  EXIF &= ~0x10;
 USBIRQ = 0x02;          	 
 
 if(--inblink == 0)			 
 dum = D2OFF;
 if(--outblink == 0)	
 dum = D3OFF;
 
 
 
 
 
 LEDCounter++;
 if(LEDCounter > 1000)
 LEDCounter = 0;		 
 if(LEDCounter < 500)
 dum = D5OFF;
 else
 dum = D5ON;
 }
 
 void ISR_Ures(void) interrupt 0
 {
 
 pConfigDscr = pFullSpeedConfigDscr;
 ((CONFIGDSCR xdata *) pConfigDscr)->type = 0x02;
 pOtherConfigDscr = pHighSpeedConfigDscr;
 ((CONFIGDSCR xdata *) pOtherConfigDscr)->type = 0x07;
 
  EXIF &= ~0x10;
 USBIRQ = 0x10;          
 }
 
 void ISR_Susp(void) interrupt 0
 {
 Sleep = 1;
  EXIF &= ~0x10;
 USBIRQ = 0x08;
 }
 
 void ISR_Highspeed(void) interrupt 0
 {
 if ((USBCS & 0x80))
 {
 pConfigDscr = pHighSpeedConfigDscr;
 ((CONFIGDSCR xdata *) pConfigDscr)->type = 0x02;
 pOtherConfigDscr = pFullSpeedConfigDscr;
 ((CONFIGDSCR xdata *) pOtherConfigDscr)->type = 0x07;
 }
 
  EXIF &= ~0x10;
 USBIRQ = 0x20;
 }
 void ISR_Ep0ack(void) interrupt 0
 {
 }
 void ISR_Stub(void) interrupt 0
 {
 }
 void ISR_Ep0in(void) interrupt 0
 {
 }
 void ISR_Ep0out(void) interrupt 0
 {
 }
 void ISR_Ep1in(void) interrupt 0
 {
 }
 void ISR_Ep1out(void) interrupt 0
 {
 }
 void ISR_Ep2inout(void) interrupt 0
 {
 BYTE dum;   	
  EXIF &= ~0x10;
 EPIRQ = 0x10;          
 dum = D3ON;
 outblink = 200;
 }
 void ISR_Ep4inout(void) interrupt 0
 {
 }
 void ISR_Ep6inout(void) interrupt 0
 {
 BYTE dum;
  EXIF &= ~0x10;
 EPIRQ = 0x40;          
 dum = D2ON;
 inblink = 200;
 }
 void ISR_Ep8inout(void) interrupt 0
 {
 }
 void ISR_Ibn(void) interrupt 0
 {
 }
 void ISR_Ep0pingnak(void) interrupt 0
 {
 }
 void ISR_Ep1pingnak(void) interrupt 0
 {
 }
 void ISR_Ep2pingnak(void) interrupt 0
 {
 }
 void ISR_Ep4pingnak(void) interrupt 0
 {
 }
 void ISR_Ep6pingnak(void) interrupt 0
 {
 }
 void ISR_Ep8pingnak(void) interrupt 0
 {
 }
 void ISR_Errorlimit(void) interrupt 0
 {
 }
 void ISR_Ep2piderror(void) interrupt 0
 {
 }
 void ISR_Ep4piderror(void) interrupt 0
 {
 }
 void ISR_Ep6piderror(void) interrupt 0
 {
 }
 void ISR_Ep8piderror(void) interrupt 0
 {
 }
 void ISR_Ep2pflag(void) interrupt 0
 {
 }
 void ISR_Ep4pflag(void) interrupt 0
 {
 }
 void ISR_Ep6pflag(void) interrupt 0
 {
 }
 void ISR_Ep8pflag(void) interrupt 0
 {
 }
 void ISR_Ep2eflag(void) interrupt 0
 {
 }
 void ISR_Ep4eflag(void) interrupt 0
 {
 }
 void ISR_Ep6eflag(void) interrupt 0
 {
 }
 void ISR_Ep8eflag(void) interrupt 0
 {
 }
 void ISR_Ep2fflag(void) interrupt 0
 {
 }
 void ISR_Ep4fflag(void) interrupt 0
 {
 }
 void ISR_Ep6fflag(void) interrupt 0
 {
 }
 void ISR_Ep8fflag(void) interrupt 0
 {
 }
 void ISR_GpifComplete(void) interrupt 0
 {
 }
 void ISR_GpifWaveform(void) interrupt 0
 {
 }
