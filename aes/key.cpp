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

void AES::setKey(uint8_t * bytes)
{
    for (int i = 0; i < 16; i++)
        key[i] = bytes[i];

    genRoundKeys();
}

void AES::setRoundKey(int round, uint8_t * bytes)
{
    for (int i = 0; i < 16; i++)
        roundKey[round][i] = bytes[i];
}
