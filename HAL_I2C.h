/*
 * HAL_I2C.h
 *
 *  Created on: Mar 14, 2016
 *      Author: daniel
 */

#ifndef HAL_I2C_H_
#define HAL_I2C_H_

void Init_I2C_GPIO(void);
void I2C_init(void);
int I2C_read16(unsigned char);
void I2C_write16(unsigned char pointer, unsigned int writeByte);
void I2C_setslave(unsigned int slaveAdr);

#endif /* HAL_I2C_H_ */
