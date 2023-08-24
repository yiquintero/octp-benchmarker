#pragma once
#include "benchmarkdata.h"
#include <string>
#include <vector>

class FileParser
{
public:

    FileParser() {};
    virtual ~FileParser() {};

    std::vector<BenchmarkData> parse(const std::vector<std::pair<OCTPConfigurations, std::string>> filepaths);

protected:

    BenchmarkData readAndParseFile(OCTPConfigurations simconfig, std::string file);

    float getMemoryInGB(std::string line);
    unsigned int getRuntimeInSeconds(std::string line);
    float getLoopTimeInSeconds(std::string line);
    float getMpiPercentage(std::string line);

    inline unsigned int convertToSeconds(unsigned int hrs, unsigned int mins, unsigned int secs) {
        return (hrs*60*60 + mins*60 + secs);
    }

};