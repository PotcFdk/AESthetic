/**
Copyright 2013 - 2014 PotcFdk

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

void AES::mixColumns()
{
    uint16_t res;
    uint8_t a,b,c,d;

    for (int i = 0; i < 4; i++)
    {
        a = data[0+i*4], b = data[1+i*4], c = data[2+i*4], d = data[3+i*4];

        res = (a << 1) ^ ((b << 1) ^ b) ^ c ^ d;
        if (res & mag)
            res ^= reduce;
        data[0+i*4] = res;

        res = a ^ (b << 1) ^ ((c << 1) ^ c) ^ d;
        if (res & mag)
            res ^= reduce;
        data[1+i*4] = res;

        res = a ^ b ^ (c << 1) ^ ((d << 1) ^ d);
        if (res & mag)
            res ^= reduce;
        data[2+i*4] = res;

        res = ((a << 1) ^ a) ^ b ^ c ^ (d << 1);
        if (res & mag)
            res ^= reduce;
        data[3+i*4] = res;
    }
}
