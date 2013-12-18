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

void AES::genRoundKeys()
{
    roundKey[0] = key;

    for (int i = 1; i < 11; i++)
    {
        uint8_t * last = roundKey[i-1];

        roundKey[i] = new uint8_t[16];

        roundKey[i][0] = last[0] ^ sBox(last[13]) ^ Rcon(i);
        roundKey[i][1] = last[1] ^ sBox(last[14]);
        roundKey[i][2] = last[2] ^ sBox(last[15]);
        roundKey[i][3] = last[3] ^ sBox(last[12]);

        for (int b = 4; b < 16; b++)
        {
            roundKey[i][b] = last[b] ^ roundKey[i][b-4];
        }
    }
}

void AES::initRoundKeys()
{
    for (int i = 0; i < 11; i++)
        roundKey[i] = new uint8_t[16];
}
