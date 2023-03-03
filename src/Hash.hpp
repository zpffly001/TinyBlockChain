#ifndef _HASH_H_
#define _HASH_H_
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include <openssl/sha.h>
#include <openssl/ripemd.h>
using namespace std;

/* Hash the incoming string */
string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;
    for (int i = 0; i < SHA224_DIGEST_LENGTH; i++)
    {
        /* Output the hash array in hexadecimal, with every 2 characters as a unit,
            and fill in 0 if not enough */
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}


#endif