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

using namespace std;

int main()
{
    AES * aes = new AES();

    uint8_t in [] = {0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0
                    };

    uint8_t key [] = {0xde, 0xca, 0xde, 0xca,
                      0xad, 0xfe, 0xad, 0xfe,
                      0xbe, 0xba, 0xbe, 0xba,
                      0xef, 0xbe, 0xef, 0xbe
                     };

    aes->setData(in);
    aes->setKey(key);

    //aes->encrypt(); // Shows ciphertext only.
    aes->verboseEncrypt(); // Shows all encryption steps.

    return 0;
}
