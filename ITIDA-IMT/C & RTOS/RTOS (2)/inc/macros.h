/*
 * macros.h
 *
 * Created: 4/09/2021 4:24:31 PM
 *  Author: kamar salah
 */

#ifndef MACROS_H_
#define MACROS_H_

#define REGISTER_SIZE		8

#define SET_BIT(reg, bit)	reg |= (1 << bit)
#define CLEAR_BIT(reg, bit) reg &= (~(1 << bit))
#define TOG_BIT(reg, bit)	reg ^= (1 << bit)
#define READ_BIT(reg, bit)	((reg & (1 << bit)) >> bit)
#define ROR(reg, num)		reg = (reg << (REGISTER_SIZE - num)) | (reg >> (num))
#define ROL(reg, num)		reg = (reg >> (REGISTER_SIZE - num)) | (reg << (num))

#endif /* MACROS_H_ */