#pragma once
#include "types.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <endian.h>

using namespace std;

struct BlockContext
{

};

// Gota-IO file.
struct GFile
{
private:
    static u32 systemEndian;
    FILE* handle;
    string fileName;
    bool isMem;
    vector<u8> buff;
    bool swapEndian;
    void Init(); // TODO!!!
    size_t fileSize;

public:
    u64 position;

    // Constructors.
    GFile();
    GFile(char* fileName);

    // Other functions.
    void SetEndian(bool big);
    void Close();
    u64 Size();
    void ToMem();
    void ToFile(char* fileName);
    void DumpData(void* dest);
    void DumpData(char* fileName);
    void Align(size_t size);
    void Clear();
    
    // Static functions.
    static bool FileExists(char* fileName);
    static void CreateFile(char* fileName);

    // Reading functions.
    size_t Read(void* dest, size_t size); // TODO!!!
    s8 ReadS8();
    u8 ReadU8();
    s16 ReadS16();
    u16 ReadU16();
    s24 ReadS24(); // TODO!!!
    u24 ReadU24(); // TODO!!!
    s32 ReadS32();
    u32 ReadU32();
    s64 ReadS64();
    u64 ReadU64();
    f32 ReadF32();
    f64 ReadF64();
    string ReadStr();

    // Writing functions.
    void Write(void* src, size_t size); // TODO!!!
    void Write(s8 val);
    void Write(u8 val);
    void Write(s16 val);
    void Write(u16 val);
    void Write(s24 val); // TODO!!!
    void Write(u24 val); // TODO!!!
    void Write(s32 val);
    void Write(u32 val);
    void Write(s64 val);
    void Write(u64 val);
    void Write(f32 val);
    void Write(f64 val);
    void Write(string val);

};