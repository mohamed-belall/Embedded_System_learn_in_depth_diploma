# LAB 2 interrupt controller ATMEGA32



| INT0 | any change (rising or falling) |
| --- | --- |
| INT1 | rising edge |
| INT2 | falling edge |

# 1. Enable global interrupt

| REGISTER | BIT |
| --- | --- |
| SREG | Write 1 to bit 7 |

# 2. General interrupt control register

| REGISTER | offset |
| --- | --- |
| GICR | 0x3B |

### Write 1 to enable external interrupt request

| INT0 | BIT (6) |
| --- | --- |
| INT1 | BIT (7) |
| INT2 | BIT (5) |

# 3. MCUCR - MCU control register

### INT0 ⇒ any change (rising or falling)

| ISC01 | ISC00 |
| --- | --- |
| 0 | 1 |

### INT1 ⇒ rising edge

| ISC11 | ISC10 |
| --- | --- |
| 1 | 1 |

### INT2 ⇒ falling edge

| ISC2 | BIT |
| --- | --- |
| 1 | 6 |

![simulation0](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/assets/77551534/f7c05a81-9f1f-4e3d-af70-31929fc71ba7)

---









