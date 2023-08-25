# LAB 1
## Toggle PortA pin 13 & enable IOPORTA clock:

### REGISTER

| `APB2 peripheral clock enable register ` | RCC_APB2ENR |
| --- | --- |
| `Address offset` | 0x18 | 


### BITS

|  |  | |  |
| --- | --- | --- | --- |
| `IO port A clock enable` | IOPAEN | 2 | RCC_APB2ENR |


![LAB 1](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_6_Micro-controller%20Arch/Lesson3_MCU_Clocks/U6L3_LAB_1_KEIL.png)

---

# LAB 2
## Configure Board to run with the Following rates:

1. APB1 Bus frequency 4MHZ
2. APB2 Bus frequency 2MHZ
3. AHB frequency 8 MHZ
4. sysClk 8 MHZ
5. Use only internal HSI RC

### REGISTER
| `Clock configuration register` | RCC_CFGR |
| --- | --- |
| `Address offset` | 0x04 

| `APB2 peripheral clock enable register ` | RCC_APB2ENR |
| --- | --- |
| `Address offset` | 0x18 | 


### BITS

| `APB1 PRESCALER` | PPRE1 | 8 ⇒ 10 | RCC_CFGR |
| --- | --- | --- | --- |
| `APB2 PRESCALER` | PPRE2 | 11 ⇒ 13 | RCC_CFGR |
| `IO port A clock enable` | IOPAEN | 2 | RCC_APB2ENR |

![LAB 2](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_6_Micro-controller%20Arch/Lesson3_MCU_Clocks/U6L3_LAB_2_KEIL.png)


---

# LAB 3
## Configure Board to run with the Following rates:

1. APB1 Bus frequency 16MHZ
2. APB2 Bus frequency 8MHZ
3. AHB frequency 32 MHZ
4. sysClk 32 MHZ
5. Use only internal HSI RC

### REGISTER
| `Clock configuration register` | RCC_CFGR |
| --- | --- |
| `Address offset` | 0x04 

| `APB2 peripheral clock enable register ` | RCC_APB2ENR |
| --- | --- |
| `Address offset` | 0x18 | 

| `Clock control register ` | RCC_CR |
| --- | --- |
| `Address offset` | 0x00 | 


### BITS

| `APB1 PRESCALER` | PPRE1 | 8 ⇒ 10 | RCC_CFGR |
| --- | --- | --- | --- |
| `APB2 PRESCALER` | PPRE2 | 11 ⇒ 13 | RCC_CFGR |
| `System clock switch` | SW | 0 ⇒ 1 | RCC_CFGR |
| `PLL multiplication factor` | PLLMUL | 18 ⇒ 21 | RCC_CFGR |
| `PLL enable` | PLLON | 24 | RCC_CR |
| `IO port A clock enable` | IOPAEN | 2 | RCC_APB2ENR |

![LAB 3](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_6_Micro-controller%20Arch/Lesson3_MCU_Clocks/U6L3_LAB_3_KEIL.png)









