
/*
 * Copyright (c) 2013, BioDesign for the Real World, Robin Scheibler <fakufaku@gmail.com>,
 * Sachiko Hirosue <shirosue@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 *   Neither the name of the <ORGANIZATION> nor the names of its contributors may
 *   be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <math.h>
#include "Counter.h"

#define TIMER_LENGTH 1000
#define AVG_LEN 1
#define PBS 807200.0
#define led_on() digitalWrite(pinLed, HIGH);
#define led_off() digitalWrite(pinLed, LOW);
#define led_config() pinMode(pinLed, OUTPUT);

int pinLed = 11;
int pinCounter = 5;

HardwareCounter hwc(pinCounter, TIMER_LENGTH);

void setup()
{
  //led_config(); 
  Serial.begin(57600);
  Serial.println("Hello world.");
  pinMode(pinLed, OUTPUT);
  //analogWrite(pinLed, 50);
  led_on();
}

void loop()
{
  
  unsigned long count = 0;
  for (int i = 0 ; i < AVG_LEN ; i++)
  {
    hwc.start();
    while(!hwc.available())
      ;
    count += hwc.count();
  }
  count /= (float)AVG_LEN;
  
  Serial.println(-log10(count/PBS));
  
}
