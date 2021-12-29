#include "common.h"
#include "Bsp.h"

#pragma section all "cpu0_dsram"

int core0_main (void)
{
    get_clk(); //获取时钟频率  务必保留
    //用户在此处调用各种初始化函数等

    //等待所有核心初始化完毕
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();
    while (TRUE)
    {
        //用户在此处编写代码
    }
}

#pragma section all restore

