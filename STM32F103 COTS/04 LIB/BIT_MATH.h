/********************************************************************************************
* @Author: Mohammed Abdelalim
* @Version:
* @Date: 10-11-2020
*********************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NUM)		(REG |=  (1<<BIT_NUM))
#define CLEAR_BIT(REG,BIT_NUM)		(REG &= ~(1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM)		((REG>>BIT_NUM) & 1)

#endif 
