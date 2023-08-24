#pragma once
#include "benchmarkdata.h"
#include <vector>


class FileWriter 
{
public:

    FileWriter() {};
    virtual ~FileWriter() {};

    void write(const std::string filepath, const std::vector<BenchmarkData> data);
};

