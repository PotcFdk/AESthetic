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

#include <stdint.h>

class AES
{
public:
    AES();
    AES(uint8_t *);

    void print(uint8_t);
    void print(uint8_t *);
    void printLine(uint8_t *);
    void printBox(uint8_t *);

    void printData();
    void printKey();
    void printRoundKey(int);

    void genRoundKeys();
    void initRoundKeys();

    void runRound();

    void encrypt();
    void verboseEncrypt();
    void verboseEncryptNoReset();

    void decrypt();
    void verboseDecrypt();
    void verboseDecryptNoReset();

    uint8_t * getData();

    void setData(uint8_t *);
    void setKey(uint8_t *);
    void setRoundKey(int, uint8_t *);
    void setRound(int);

    // Encryption

    void keyAdd();
    void subBytes();
    void shiftRows();
    void mixColumns();

    uint8_t sBox(uint8_t);
    uint8_t Rcon(uint8_t);

    // Decryption

    void keyAddInv();
    void subBytesInv();
    void shiftRowsInv();
    void mixColumnsInv();

    uint8_t sBoxInv(uint8_t);

private:
    int round = 0;
    uint8_t * data = new uint8_t[16];
    uint8_t * key  = new uint8_t[16];
    uint8_t ** roundKey = new uint8_t* [16];

    const uint16_t reduce = 0b100011011;
    const uint16_t mag = 0b100000000;
};
