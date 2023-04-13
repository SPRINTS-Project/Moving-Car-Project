/*
 * EXT_INT.h
 *
 * Created: 4/6/2023 11:13:47 PM
 *  Author: engma
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_


#define EXT_INT_MAX_NUM		3


typedef uint8_t EXT_INT_ID_TYPE;
#define INT_0_ID			((EXT_INT_ID_TYPE)0x00)
#define INT_1_ID			((EXT_INT_ID_TYPE)0x01)
#define INT_2_ID			((EXT_INT_ID_TYPE)0x02)
							

typedef uint8_t EXT_INT_MODE_TYPE;

#define EXT_INT_FALLING_EDGE	((EXT_INT_MODE_TYPE)0x00)
#define EXT_INT_RISING_EDGE		((EXT_INT_MODE_TYPE)0x01)



typedef uint8_t EXT_INT_ERR_TYPE;

#define EXT_INT_ERR_OK				((EXT_INT_ERR_TYPE)0x00)
#define EXT_INT_ERR_OutOfRange		((EXT_INT_ERR_TYPE)0x01)



EXT_INT_ERR_TYPE eXT_INT_Enable(EXT_INT_ID_TYPE id , EXT_INT_MODE_TYPE mode);

#endif /* EXT_INT_H_ */