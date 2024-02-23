# Switching Between Stack Pointers

### Lab Overview
1. Define boundaries for Main Stack Pointer (MSP) and Process Stack Pointer (PSP) for Task A and Task B.
2. Implement task scheduling based on EXTI.
3. Ensure that tasks run in the user access level and the scheduler runs in the privileged access level.

---
   



 **`Layout Design`**
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/3_cortexM_Reset_Sequence/1.png)
---

**`change to unprivileged`**
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/3_cortexM_Reset_Sequence/2.png)
---

**`Change to privileged again but it doesn't change `**
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/3_cortexM_Reset_Sequence/3.png)
---

**` In handler mode we can change to privileged again `**
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/3_cortexM_Reset_Sequence/6.png)
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/3_cortexM_Reset_Sequence/drawio.png)
---







<br><br>

**` If we switch to unprivileged before enabling NVIC controller`**
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/3_cortexM_Reset_Sequence/4.png)
**` it will make hard fault`**
![](https://github.com/mohamed-belall/Embedded_System_learn_in_depth_diploma/blob/master/Unit_14_ARM/3_cortexM_Reset_Sequence/5.png)
