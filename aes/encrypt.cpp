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
#include <iostream>

void AES::encrypt()
{
    round = 0;

    keyAdd();
    round++;

    for (; round < 10; round++)
        runRound();

    subBytes();
    shiftRows();
    keyAdd();

    printData();
}

void AES::verboseEncryptNoReset()
{
    if (round == 0)
    {
        std::cout << "Round " << round << " plaintext:" << std::endl;
        printData();

        keyAdd();

        std::cout << std::endl << "Round " << round << " keyAdd:" << std::endl;
        printData();

        round++;
    }

    for (; round < 10; round++)
    {
        std::cout << std::endl << "Round " << round << " plaintext:" << std::endl;
        printData();
        subBytes();
        std::cout << std::endl << "Round " << round << " subBytes:" << std::endl;
        printData();
        shiftRows();
        std::cout << std::endl << "Round " << round << " shiftRows:" << std::endl;
        printData();
        mixColumns();
        std::cout << std::endl << "Round " << round << " mixColumns:" << std::endl;
        printData();
        keyAdd();
        std::cout << std::endl << "Round " << round << " keyAdd:" << std::endl;
        printData();
    }

    subBytes();
    std::cout << std::endl << "Round " << round << " subBytes:" << std::endl;
    printData();
    shiftRows();
    std::cout << std::endl << "Round " << round << " shiftRows:" << std::endl;
    printData();
    keyAdd();
    std::cout << std::endl << "Round " << round << " keyAdd / ciphertext:" << std::endl;
    printData();
}

void AES::verboseEncrypt()
{
    round = 0;
    verboseEncryptNoReset();
}
