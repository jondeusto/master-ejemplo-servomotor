/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 500 
AnalogIn potenciometro(A0);
PwmOut servomotor(D5);

int calculaAncho(float d);

int main()
{
    servomotor.period_ms(20);  
    
    while (true)
    {
        float potValor=potenciometro.read();
        int anchoPulso=calculaAncho(potValor);
        servomotor.pulsewidth_us(anchoPulso);
        printf("%d\n",anchoPulso);
        ThisThread::sleep_for(10);

    }
}

int calculaAncho(float d){
    return d*1000+1000;
}