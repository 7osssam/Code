
#define nop()  __asm__ __volatile__ ("nop" ::)
#define NOP()  __asm__ __volatile__ ("nop" ::)
#define _NOP()  __asm__ __volatile__ ("nop" ::)

#define CLI() cli()
#define SEI() sei()
#define BIT(x)	(1 << (x))

typedef unsigned char		byte;
typedef unsigned char		u8;
typedef signed int		s16;
typedef unsigned int		u16;
typedef signed long		s32;
typedef unsigned long		u32;
typedef signed long long	s64;
typedef unsigned long long 	u64;

#define sbi(port, bit) 	(port |= (1<<bit))
#define cbi(port, bit) 	(port &= (~(1<<bit)))
#define inp(port, bit) 		(port & (1<<bit))
// bit ¸ÅÅ©·Î
#define SetBit(x,y)  (x|=(1<<y))
#define ClrBit(x,y)  (x&=~(1<<y))
#define ToggleBit(x,y) (x^=(1<<y))
#define FlipBit(x,y) (x^=(1<<y)) // Same as ToggleBit.
#define TestBit(x,y) (x&(1<<y))

// bit ¸ÅÅ©·Î
#define SETBIT(x,y)  (x|=(1<<y))
#define CLEARBIT(x,y)  (x&=~(1<<y))
#define TOGGLEBIT(x,y) (x^=(1<<y))
#define FLIPBIT(x,y) (x^=(1<<y)) // Same as ToggleBit.
#define TESTBIT(x,y) (x&(1<<y))

extern unsigned int INT0_DataView;
extern unsigned int INT1_DataView;
extern unsigned int Uart1_DataView;