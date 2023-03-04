#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "Hash.hpp"

using namespace std;

/**
 * Print hexadecimal form of string
*/
void printHex(const char *label, const uint8_t *v, size_t len)
{
    size_t i;

    printf("%s: ", label);
    for (i = 0; i < len; i++)
    {
        printf("%02x", v[i]);
    }
    printf("\n");
}

/**
 * Get merkel root
*/
string getMerkleRoot(const vector<string> &merkle)
{
    printf("\nFinding Merkle Root.... \n");
    if (merkle.empty())
    {
        return "";
    }else if (merkle.size() == 1)
    {
        return sha256(merkle[0]);
    }
    
    vector<string> new_merkle = merkle;

    while (new_merkle.size() > 1)
    {
        if(new_merkle.size() % 2 == 1)
        {
            new_merkle.push_back(merkle.back());
        }
        vector<string> result;

        for (int i = 0; i < new_merkle.size(); i+=2)
        {
            string var1 = sha256(new_merkle[i]);
            string var2 = sha256(new_merkle[i + 1]);
            string hash = sha256(var1 + var2);
            result.push_back(hash);
        }
        new_merkle = result;
    }
    return new_merkle[0];
}

pair<string, string> findHash(int index, string prevHash, vector<string> &merkle)
{
    string header = to_string(index) + prevHash + getMerkleRoot(merkle);
    unsigned int nonce;
    for (nonce = 0; nonce < 100000; nonce++)
    {
        string blockHash = sha256(header + to_string(nonce));
        /* TODO 这是挖矿？Hash的前两个字符是"00"才符合？ */
        if (blockHash.substr(0, 2) == "00")
        {
            /* 这是正确的矿的hash地址 */
            return make_pair(blockHash, to_string(nonce));
            break;
        }
    }
    return make_pair("fail", "fail");
}

#endif