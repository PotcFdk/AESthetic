/**
Copyright 2013 PotcFdk

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**/

#include <aes.hpp>

uint8_t mul (uint16_t num, uint8_t mul)
{
        uint8_t o = 0;

        for (int i = 0; i < 8; i++)
        {
            if (mul & (1 << i))
                o ^= num;
            num <<= 1;
            if (num & 0x100)
            { // reduce it
                num ^= 0b11011;
            }
        }

        return o;
}

void AES::mixColumnsInv()
{
    uint16_t res;
    uint8_t a,b,c,d;

    for (int i = 0; i < 4; i++)
    {
        a = data[0+i*4], b = data[1+i*4], c = data[2+i*4], d = data[3+i*4];

        res = mul(a, 0xE) ^ mul(b, 0xB) ^ mul(c, 0xD) ^ mul(d, 0x9);
        if (res & mag)
            res ^= reduce;
        data[0+i*4] = res;

        res = mul(a, 0x9) ^ mul(b, 0xE) ^ mul(c, 0xB) ^ mul(d, 0xD);
        if (res & mag)
            res ^= reduce;
        data[1+i*4] = res;

        res = mul(a, 0xD) ^ mul(b, 0x9) ^ mul(c, 0xE) ^ mul(d, 0xB);
        if (res & mag)
            res ^= reduce;
        data[2+i*4] = res;

        res = mul(a, 0xB) ^ mul(b, 0xD) ^ mul(c, 0x9) ^ mul(d, 0xE);
        if (res & mag)
            res ^= reduce;
        data[3+i*4] = res;
    }
}
