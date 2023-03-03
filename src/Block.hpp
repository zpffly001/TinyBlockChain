#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "json.hh"
using json = nlohmann::json;
using namespace std;

class Block
{
    public:
        Block(int index, string prevHas, string hash, string nonce, vector<string> data);
        string getPreviousHash(void);
        string getHash(void);
        int getIndex(void);
        vector<string> getData(void);

        void toString(void);
        json toJSON(void);
    private:
        int index;
        string previousHash;
        string blockHash;
        string nonce;
        vector<string> data;
};

#endif