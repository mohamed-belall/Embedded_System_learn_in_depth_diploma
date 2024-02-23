# Switching Between Stack Pointers

## Lab Overview
1. Create Boundaries for Main Stack Pointer(MSP) and Process Stack Pointer(PSP) for Task A and Task B.
2. Task Scheduling based on EXTI
3. Tasks Will Run in the user access level and the scheduler runs in the privileged access level.

---

 **` Layout Design `**
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/5_Stack_memory/6.png)
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/5_Stack_memory/7.png)
---
## **Analysis**
1. Set Boundaries 
```c
	// Main Stack Pointer
	_S_MSP = (u32) &_estack ;
	_E_MSP = _S_MSP - MAIN_STACK_SIZE ; // Decrement because ARM-Cortex has Full-Descending stack model

	// Process Stack of Task A
	_S_PSP_TASKA = _E_MSP - 8 ; // Add 2 Word as safety between stacks
	_E_PSP_TASKA = _S_PSP_TASKA - TASKA_SIZE ;

	// Process Stack of Task B
	_S_PSP_TASKB = _E_PSP_TASKA - 8 ; // Add 2 Word as safety between stacks
	_E_PSP_TASKB = _S_PSP_TASKB - TASKB_SIZE ;
```
2. When Task is Ready start making   
2.1 Set The PSP value by the start of the task stack 
    ```c
    #define SET_PSP(ADDRESS) __asm("MOV r0,%0 \n\t MSR PSP , r0 " : : "r"(ADDRESS))
    SET_PSP(_S_PSP_TASKA);  
    ```
    2.2 Change the working stack area (MSP) to the process stack area (PSP of TaskA)
    ```c
    (void)PSRC_voidSetUsageStackPointer(PSRC_PSP , 0);
    ```
    2.3 Switch from the Privileged Level to Unprivileged level access to make task working on unprivileged access
    ```c
    (void)PSRC_voidSetAccessLevel(PSRC_UNPRIVILEGED_ACCESS, 0) ;
    ```
3. After finishing the execution of the task   
    3.1 Switch from unprivileged access level to privileged access level by generating SVC interrupt
    ```c
    #define OS_GENERATE_EXC()   __asm("SVC #0x3");
    OS_GENERATE_EXC();
    ```
    3.2 Set the SP to MSP 
    ```c
    (void)PSRC_voidSetUsageStackPointer(PSRC_MSP , 0);
    ```

    

![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/5_Stack_memory/1.png)
---


![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/5_Stack_memory/2.png)
---


![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/5_Stack_memory/3.png)
---



![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/5_Stack_memory/4.png)
---

![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/5_Stack_memory/5.png)
---



