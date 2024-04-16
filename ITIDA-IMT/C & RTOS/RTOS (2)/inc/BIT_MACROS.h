/***********************************************************************************************
 * File name: BIT_MACROS.h
 *
 * Creator: Hossam Mohamed
 *
 * Description: This file contains some useful macros that can be used in any project
 *
 ************************************************************************************************/

#ifndef BIT_MATH_H /*header guard*/
#define BIT_MATH_H

/* Set a bit to 1 */
#define SET_BIT(reg, bit) 				((reg) |= (1U << (bit)))

/* Clear a bit to 0 */
#define CLEAR_BIT(reg, bit) 			((reg) &= ~(1U << (bit)))

/* Toggle a bit to 0 or 1 */
#define TOGGLE_BIT(reg, bit) 			((reg) ^= (1U << (bit)))

/* Check if a bit is set to 1 or 0 (returns 1 if 1, 0 if 0) */
#define READ_BIT(reg, bit)				(((reg) >> (bit)) & 1U)

/* Check if a bit is set to 1 */
#define IS_BIT_SET(reg, bit) 			((reg) & (1U << (bit)))

/* Check if a bit is cleared to 0 */
#define IS_BIT_CLEAR(reg, bit) 			(!((reg) & (1U << (bit))))

/* clear a specific bit and set it with a value 0 or 1 */
#define WRITE_BIT(reg, bit, value)  	((reg) = ((reg & ~(1U << (bit))) | ((value) << (bit))))

/* Set multiple bits based on mask */
#define SET_MASK(reg, mask) 			((reg) |= (mask))

/* Clear multiple bits based on mask */
#define CLEAR_MASK(reg, mask) 			((reg) &= ~(mask))

/* Toggle multiple bits based on mask */
#define TOGGLE_MASK(reg, mask) 			((reg) ^= (mask))

/* Check if a bit is set to 1 and clear it */
#define TEST_AND_CLEAR_BIT(reg, bit) 	(((reg) >> (bit)) & 1U) && CLEAR_BIT(reg, bit)

/* Check if a bit is cleared to 0 and set it */
#define TEST_AND_SET_BIT(reg, bit) 		(!((reg) >> (bit)) & 1U) && SET_BIT(reg, bit)

/* Rotate right the register value with a specific number of rotates */
#define ROR(reg, num) 					((reg) = ((reg >> (num)) | (reg << (8U - (num)))))

/* Rotate left the register value with a specific number of rotates */
#define ROL(reg, num) 					((reg) = ((reg << (num)) | (reg >> (8U - (num)))))

/* Set a bit to 1 */
#define BIT(x) 							(1U << (x))

#endif // BIT_MATH_H