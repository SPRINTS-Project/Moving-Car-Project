#ifndef _DIO_CONFIG_H_
#define _DIO_CONFIG_H_

#include <stdint.h>


// DIO channel type ENUM
typedef uint8_t Dio_ChannelType;

#define DIO_PORTA_Channel0		((Dio_ChannelType)0)
#define DIO_PORTA_Channel1		((Dio_ChannelType)1)
#define DIO_PORTA_Channel2		((Dio_ChannelType)2)
#define DIO_PORTA_Channel3		((Dio_ChannelType)3)
#define DIO_PORTA_Channel4		((Dio_ChannelType)4)
#define DIO_PORTA_Channel5		((Dio_ChannelType)5)
#define DIO_PORTA_Channel6		((Dio_ChannelType)6)
#define DIO_PORTA_Channel7		((Dio_ChannelType)7)

#define DIO_PORTB_Channel0		((Dio_ChannelType)8)
#define DIO_PORTB_Channel1		((Dio_ChannelType)9)
#define DIO_PORTB_Channel2		((Dio_ChannelType)10)
#define DIO_PORTB_Channel3		((Dio_ChannelType)11)
#define DIO_PORTB_Channel4		((Dio_ChannelType)12)
#define DIO_PORTB_Channel5		((Dio_ChannelType)13)
#define DIO_PORTB_Channel6		((Dio_ChannelType)14)
#define DIO_PORTB_Channel7		((Dio_ChannelType)15)

#define DIO_PORTC_Channel0		((Dio_ChannelType)16)
#define DIO_PORTC_Channel1		((Dio_ChannelType)17)
#define DIO_PORTC_Channel2		((Dio_ChannelType)18)
#define DIO_PORTC_Channel3		((Dio_ChannelType)19)
#define DIO_PORTC_Channel4		((Dio_ChannelType)20)
#define DIO_PORTC_Channel5		((Dio_ChannelType)21)
#define DIO_PORTC_Channel6		((Dio_ChannelType)22)
#define DIO_PORTC_Channel7		((Dio_ChannelType)23)

#define DIO_PORTD_Channel0		((Dio_ChannelType)24)
#define DIO_PORTD_Channel1		((Dio_ChannelType)25)
#define DIO_PORTD_Channel2		((Dio_ChannelType)26)
#define DIO_PORTD_Channel3		((Dio_ChannelType)27)
#define DIO_PORTD_Channel4		((Dio_ChannelType)28)
#define DIO_PORTD_Channel5		((Dio_ChannelType)29)
#define DIO_PORTD_Channel6		((Dio_ChannelType)30)
#define DIO_PORTD_Channel7		((Dio_ChannelType)31)




// DIO port type ENUM
typedef uint8_t Dio_PortType;

#define PortA			(Dio_PortType(0x00))
#define PortB			(Dio_PortType(0x01))
#define PortC			(Dio_PortType(0x02))
#define PortD			(Dio_PortType(0x03))



#endif /* DIO_CONFIG_H */