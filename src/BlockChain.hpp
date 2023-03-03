#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "Hash.hpp"
#include "json.hh"
#include "Block.hpp"
using json = nlohmann::json;

class BlockChain
{
    public:
        BlockChain(int genesis = 1);
        Block getBlock(int index);
        int getNumOfBlocks(void);
        int addBlock(int index, string preHash, string hash, string nonce, vector<string> &merkle);
        string getLatestBlockHash(void);
        string toJSON(void);
        int replaceChain(json chain);
    private:
        /* vector that is the blockchain */
        vector<unique_ptr<Block>> blockchain;
};

#endif