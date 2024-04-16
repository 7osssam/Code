#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Var, BitNo)	   ((Var) |= (1u << (BitNo)))
#define CLEAR_BIT(Var, BitNo)  ((Var) &= ~(1u << (BitNo)))
#define TOGGLE_BIT(Var, BitNo) ((Var) ^= (1u << (BitNo)))

#endif