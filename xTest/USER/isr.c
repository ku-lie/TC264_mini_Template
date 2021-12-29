/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		isr
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		ADS v1.2.2
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/

#include "isr.h"

//PIT�жϺ���  ʾ��
IFX_INTERRUPT(cc60_pit_ch0_isr, 0, CCU6_0_CH0_ISR_PRIORITY)
{
    enableInterrupts(); //�����ж�Ƕ��
    PIT_CLEAR_FLAG(CCU6_0, PIT_CH0);
}

IFX_INTERRUPT(cc60_pit_ch1_isr, 0, CCU6_0_CH1_ISR_PRIORITY)
{
    enableInterrupts();  //�����ж�Ƕ��
    PIT_CLEAR_FLAG(CCU6_0, PIT_CH1);
}

IFX_INTERRUPT(eru_ch3_ch7_isr, 0, ERU_CH3_CH7_INT_PRIO)
{
    enableInterrupts(); //�����ж�Ƕ��
    if (GET_GPIO_FLAG(ERU_CH3_REQ6_P02_0)) //ͨ��3�ж�
    {
        CLEAR_GPIO_FLAG(ERU_CH3_REQ6_P02_0);
    }
    if (GET_GPIO_FLAG(ERU_CH7_REQ16_P15_1)) //ͨ��7�ж�
    {
        CLEAR_GPIO_FLAG(ERU_CH7_REQ16_P15_1);

    }
}

IFX_INTERRUPT(dma_ch5_isr, 0, ERU_DMA_INT_PRIO)
{
    enableInterrupts(); //�����ж�Ƕ��
}

//�����жϺ���  ʾ��
IFX_INTERRUPT(uart0_tx_isr, 0, UART0_TX_INT_PRIO)
{
    enableInterrupts();  //�����ж�Ƕ��
    IfxAsclin_Asc_isrTransmit(&uart0_handle);
}
IFX_INTERRUPT(uart0_rx_isr, 0, UART0_RX_INT_PRIO)
{
    enableInterrupts();  //�����ж�Ƕ��
    IfxAsclin_Asc_isrReceive(&uart0_handle);
}

//����1Ĭ�����ӵ�����ͷ���ô���
IFX_INTERRUPT(uart1_tx_isr, 0, UART1_TX_INT_PRIO)
{
    enableInterrupts();  //�����ж�Ƕ��
    IfxAsclin_Asc_isrTransmit(&uart1_handle);
}
IFX_INTERRUPT(uart1_rx_isr, 0, UART1_RX_INT_PRIO)
{
    enableInterrupts();  //�����ж�Ƕ��
    IfxAsclin_Asc_isrReceive(&uart1_handle);
}

