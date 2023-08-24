#include "fileparser.h"
#include <fstream>

std::vector<BenchmarkData> FileParser::parse(const std::vector<std::pair<OCTPConfigurations, std::string>> filepaths) {
    std::vector<BenchmarkData> data;
    for (auto p : filepaths) {
        data.push_back(readAndParseFile(p.first, p.second));
    }
    return data;
}

BenchmarkData FileParser::readAndParseFile(OCTPConfigurations simconfig, std::string file) {
    // open file
    std::ifstream ifs(file, std::ifstream::in);
    if(!ifs.is_open() || ifs.fail()) {
        throw std::runtime_error("Failed to open text input file.");        
    }

    // read
    std::vector<std::string> lines;
    std::string l;
    while (std::getline(ifs, l)) {
        lines.push_back(l);
    }

    // parse
    BenchmarkData data;
    data.config = simconfig;
    data.particles = std::stoi(lines[0]);
    data.time_steps = std::stoi(lines[1]);
    data.memory = getMemoryInGB(lines[2]);
    data.runtime = getRuntimeInSeconds(lines[3]);
    data.loop_time = getLoopTimeInSeconds(lines[4]);
    data.mpi_pair = getMpiPercentage(lines[8]);
    data.mpi_bond = getMpiPercentage(lines[9]);
    data.mpi_neigh = getMpiPercentage(lines[10]);
    data.mpi_comm = getMpiPercentage(lines[11]);
    data.mpi_output = getMpiPercentage(lines[12]);
    data.mpi_modify = getMpiPercentage(lines[13]);
    data.mpi_other = getMpiPercentage(lines[14]);
    
    return data;
}

float FileParser::getMemoryInGB(std::string line) {
    //Memory Utilized: 2.51 GB (estimated maximum)
    std::size_t pos = line.find_first_of(" ", 17);
    std::string mem = line.substr(17, pos-17);
    if (line.find("GB", 17) != std::string::npos) {
        return std::stof(mem);
    }
    else if (line.find("MB", 17) != std::string::npos) {
        return std::stof(mem)*0.001;
    }
    else if (line.find("KB", 17) != std::string::npos) {
        return std::stof(mem)*0.000001;
    }
    else { // bytes
        return std::stof(mem)*0.000000001;
    }
}

unsigned int FileParser::getRuntimeInSeconds(std::string line) {
    //Job Wall-clock time: 00:00:47
    std::size_t pos = line.find_first_of(":", 21);
    std::string hrs = line.substr(21, pos-21);
    std::size_t pos2 = line.find_first_of(":", pos+1);
    std::string mins = line.substr(pos+1, pos2-pos-1);
    std::string secs = line.substr(pos2+1);
    return convertToSeconds(std::stoi(hrs),std::stoi(mins),std::stoi(secs));
}

float FileParser::getLoopTimeInSeconds(std::string line) {
    //Loop time of 19.9964 on 16 procs for 100000 steps with 512 atoms
    std::size_t pos = line.find_first_of(" ", 13);
    std::string lt = line.substr(13, pos-13);
    return std::stof(lt); 
}

float FileParser::getMpiPercentage(std::string line) {
    //Pair    | 6.2981     | 7.658      | 8.6449     |  23.5 | 38.30
    std::size_t pos = line.find_last_of(" ");
    return std::stof(line.substr(pos+1));
}