#@copyright : mohamedBelal
CC			 =arm-none-eabi-
CFLAGS		 = -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS		 =-I .
SRC 		 = $(wildcard *.c)
OBJ 		 = $(SRC:.c=.o)
As 			 = $(wildcard *.s)
AsOBJ 		 = $(As:.s=.o)
project_Name = learn-in-depth_cortex_m3

all: $(project_Name).bin
	@echo " ================== Build Is Done ================== "

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c -std=c99 $(INCS) $(CFLAGS) $< -o $@ 


$(project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map


$(project_Name).bin: $(project_Name).elf
	$(CC)objcopy.exe -O binary $< $@


clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin