// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x35;
        pchMessageStart[1] = 0x2c;
        pchMessageStart[2] = 0x46;
        pchMessageStart[3] = 0x51;
        vAlertPubKey = ParseHex("");
        nDefaultPort = 21526;
        nRPCPort = 21527;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //CBlock(hash=00000bf441989ba2b71f9992c0642228658a3f97e546aba2870ec7ff814a8d8a, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=cecd5c1dcb22404370c79d2c99283964bde791b9e957726b284894656f27a998, nTime=1515288903, nBits=1e0fffff, nNonce=1212410, vtx=1, vchBlockSig=)
        //Coinbase(hash=cecd5c1dcb22404370c79d2c99283964bde791b9e957726b284894656f27a998, nTime=1515288903, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a2b30372f30312f32303138204152544158204c61756e63682066726f6d20696d706c656d656e746174696f6e)
        //CTxOut(empty)

        //vMerkleTree:  cecd5c1dcb22404370c79d2c99283964bde791b9e957726b284894656f27a998

        //mainnet.genesis.GetHash(): 00000bf441989ba2b71f9992c0642228658a3f97e546aba2870ec7ff814a8d8a
        //mainnet.genesis.hashMerkleRoot: cecd5c1dcb22404370c79d2c99283964bde791b9e957726b284894656f27a998
        //mainnet.genesis.nTime: 1515288903
        //mainnet.genesis.nNonce: 1212410


        const char* pszTimestamp = "07/01/2018 ARTAX Launch from implementation";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1515288903, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1515288903;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 1212410; 

        hashGenesisBlock = genesis.GetHash(); 
   	//	  printf("genesis.GetHash = %s\n", genesis.GetHash().ToString().c_str());
        // printf("genesis.hashMerkleRoot = %s\n", genesis.hashMerkleRoot.ToString().c_str());

        assert(hashGenesisBlock == uint256("0x00000bf441989ba2b71f9992c0642228658a3f97e546aba2870ec7ff814a8d8a"));
        assert(genesis.hashMerkleRoot == uint256("0xcecd5c1dcb22404370c79d2c99283964bde791b9e957726b284894656f27a998"));

    
        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("artax.online", "159.203.161.244"));
        vSeeds.push_back(CDNSSeedData("pool.artax.online", "198.199.124.131"));
        vSeeds.push_back(CDNSSeedData("electrum.artax.online", "138.68.174.82"));
        vSeeds.push_back(CDNSSeedData("seed1.artax.live", "147.135.130.119"));
        vSeeds.push_back(CDNSSeedData("seed2.artax.live", "seed3.artax.live"));
        vSeeds.push_back(CDNSSeedData("seed4.artax.live", "seed5.artax.live"));
        vSeeds.push_back(CDNSSeedData("electrum2.artax.online", "artaxlive.ddns.net"));
		

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,23);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,18);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,151);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 525600; // 2 years
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x1d;
        pchMessageStart[1] = 0x12;
        pchMessageStart[2] = 0x45;
        pchMessageStart[3] = 0x3a;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("");
        nDefaultPort = 121526;
        nRPCPort = 121527;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = 1515288903;
        genesis.nNonce = 1212410;
		
        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,23);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,18);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1,151);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
