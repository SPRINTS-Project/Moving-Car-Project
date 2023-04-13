#ifndef _DIO_H_
#define _DIO_H_

#include "DIO_Config.h"

#define DIO_MAX_PINS	32
#define DIO_MAX_PORTS	4

// DIO Errors Enum
typedef uint8_t DIO_Errors;		

#define DIO_E_OK				((DIO_Errors)0x00)
#define DIO_InvalidPin			((DIO_Errors)0x01)
#define DIO_InvalidPort			((DIO_Errors)0x02)


// DIO Level type ENUM
typedef uint8_t Dio_LevelType;

#define STD_LOW					((Dio_LevelType)0x00)
#define STD_HIGH				((Dio_LevelType)0x01)


// DIO DIR type ENUM
typedef uint8_t Dio_DIRType;

#define STD_INPUT					((Dio_LevelType)0x00)
#define STD_OUTPUT					((Dio_LevelType)0x01)


DIO_Errors Dio_ChannelSetDIR(Dio_ChannelType ChannelId, Dio_DIRType dir);

//void Dio_Init(void);
DIO_Errors Dio_ReadChannel(Dio_ChannelType ChannelId ,Dio_LevelType* level);
DIO_Errors Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType level);




#endif /* DIO_H */