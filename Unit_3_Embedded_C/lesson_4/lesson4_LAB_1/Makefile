#@copyright : mohamedBelal
CC			 =arm-none-eabi-
CFLAGS		 = -mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS		 =-I .
SRC 		 = $(wildcard *.c)
OBJ 		 = $(SRC:.c=.o)
As 			 = $(wildcard *.s)
AsOBJ 		 = $(As:.s=.o)
project_Name = u3_lab4_cortexM4

all: $(project_Name).bin
	@echo " ================== Build Is Done ================== "

# startup.o: startup.s
# 	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe -c -std=c99 $(INCS) $(CFLAGS) $< -o $@ 


$(project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map
	cp $(project_Name).elf $(project_Name).axf

$(project_Name).bin: $(project_Name).elf
	$(CC)objcopy.exe -O binary $< $@


clean_all:
	rm *.o *.elf *.bin *.axf

clean:
	rm *.elf *.bin