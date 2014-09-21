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
#include <sstream>
#include <iomanip>

std::string hex(unsigned char inchar)
{
  std::ostringstream oss (std::ostringstream::out);
  oss << std::setw(2) << std::setfill('0') << std::hex << (int)(inchar);
  return oss.str();
}

///

void AES::print(uint8_t byte)
{
    std::cout << hex(byte);
}

void AES::printLine(uint8_t * bytes)
{
    for (int i = 0; i < 16; i++)
        std::cout << hex(bytes[i]) << ' ';
}

void AES::printBox(uint8_t * bytes)
{
    for (int i = 0; i < 4; i++)
        std::cout << hex(bytes[i]) << ' ' << hex(bytes[i+4]) << ' '
                << hex(bytes[i+8]) << ' ' << hex(bytes[i+12]) << std::endl;
}

void AES::print(uint8_t * bytes)
{
    printBox(bytes);
}

void AES::printData()
{
    print(data);
}

void AES::printKey()
{
    print(key);
}

void AES::printRoundKey(int round)
{
    print(roundKey[round]);
}
