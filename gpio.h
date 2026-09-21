#ifndef __GPIO_H
#define __GPIO_H

#include "stm32f10x.h"

/* ================= GPIO????? ================= */
#define GPIOA_BASE   (APB2PERIPH_BASE + 0x0800)  // GPIOA ???
#define GPIOB_BASE   (APB2PERIPH_BASE + 0x0C00)  // GPIOB ???
#define GPIOC_BASE   (APB2PERIPH_BASE + 0x1000)  // GPIOC ???

/* ================= GPIO????? ================= */
/* PA0?PB5 ???8???,? CRL ?? */
#define GPIOA_CRL   (*(volatile unsigned int *)(GPIOA_BASE + 0x00)) // ????????
#define GPIOA_BSRR  (*(volatile unsigned int *)(GPIOA_BASE + 0x10)) // ?????/?????
#define GPIOA_BRR   (*(volatile unsigned int *)(GPIOA_BASE + 0x14)) // ????????

#define GPIOB_CRL   (*(volatile unsigned int *)(GPIOB_BASE + 0x00))
#define GPIOB_BSRR  (*(volatile unsigned int *)(GPIOB_BASE + 0x10))
#define GPIOB_BRR   (*(volatile unsigned int *)(GPIOB_BASE + 0x14))

/* PC13 ???8???,? CRH ?? */
#define GPIOC_CRH   (*(volatile unsigned int *)(GPIOC_BASE + 0x04)) // ????????
#define GPIOC_BSRR  (*(volatile unsigned int *)(GPIOC_BASE + 0x10))
#define GPIOC_BRR   (*(volatile unsigned int *)(GPIOC_BASE + 0x14))

/* ================= RCC????? ================= */
/* RCC_APB2ENR ???? GPIOA?GPIOB?GPIOC ??? */
#define RCC_APB2ENR (*(volatile unsigned int *)(APB2PERIPH_BASE + 0x1000 + 0x18))

#endif