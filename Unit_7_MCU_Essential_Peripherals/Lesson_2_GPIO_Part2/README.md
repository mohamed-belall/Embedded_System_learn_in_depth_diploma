# Write LCD Driver, Keypad Driver, and atmega32 to make calculator

| Pin Number | Pin Name | Description |
| --- | --- | --- |
| 1 | VSS | Ground |
| 2 | VCC | +5 Volts |
| 3 | VEE | Contrast Control (0 volts: High contrast) |
| 4 | RS | Register Select  (0: Command Register) (1: Data Register) |
| 5 | RW | Read / Write  (0: Write)  (1: Read) |
| 6 | E | Enable (High-Low pulse) |
| 7-14 | DO-D7 | Data pins |
| 15 | LED+ | +5 volts |
| 16 | LED- | Ground |

| HEX code | Command to LCD | Execution Time |
| --- | --- | --- |
| 0x01 | Clear the display screen | 1.64ms |
| 0x06 | Shift the cursor right ( e.g. data gets writtenin an incrementing order , left to right ) | 40 us |
| OXOC | Display on , cursor off | 40 us |
| OXOE | Display on , cursor blinking | 40 us |
| 0x80 | Force the cursor to the beginning of the 1stline | 40 us |
| 0xC0 | Force the cursor to the beginning of the 2ndline | 40 us |
| 0x10 | Shift cursor position to the left | 40 us |

| 0x14 | Shift cursor position to the right | 40 us |
| --- | --- | --- |
| 0x18 | Shift entire display to the left | 40 us |
| Ox1C | Shift entire display to the right | 40 us |
| 0x38 | 2 lines , 5x8 matrix , 8 - bit mode | 40 us |
| 0x28 | 2 lines , 5x8 matrix , 4 - bit mode | 40 us |
| 0x30 | 1 line , 8 - bit mode | 40 us |
| 0x20 | 1 line , 4 - bit mode | 40 us |








