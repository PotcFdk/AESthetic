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

void AES::shiftRows()
{
    uint8_t tmp;

    // row 0 is left unchanged

    // row 1
    tmp = data[1];
    data[1] = data[5];
    data[5] = data[9];
    data[9] = data[13];
    data[13] = tmp;

    // row 2
    tmp = data[2];
    data[2] = data[10];
    data[10] = tmp;
    tmp = data[6];
    data[6] = data[14];
    data[14] = tmp;

    // row 3
    tmp = data[15];
    data[15] = data[11];
    data[11] = data[7];
    data[7] = data[3];
    data[3] = tmp;
}
