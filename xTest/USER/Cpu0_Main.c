#include "common.h"
#include "Bsp.h"

#pragma section all "cpu0_dsram"

int core0_main (void)
{
    get_clk(); //��ȡʱ��Ƶ��  ��ر���
    //�û��ڴ˴����ø��ֳ�ʼ��������

    //�ȴ����к��ĳ�ʼ�����
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();
    while (TRUE)
    {
        //�û��ڴ˴���д����
    }
}

#pragma section all restore

