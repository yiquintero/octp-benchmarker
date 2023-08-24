#include "filewriter.h"
#include <fstream>

void FileWriter::write(const std::string file, const std::vector<BenchmarkData> data) {
    // open file
    std::ofstream ofs(file, std::ifstream::out);
    if(!ofs.is_open() || ofs.fail()) {
        throw std::runtime_error("Failed to open text output file.");        
    }

    // write header 
    std::string header = "config,particles,timesteps,memory,runtime,looptime,";
    header.append("mpi_pair,mpi_bond,mpi_neigh,mpi_comm,mpi_output,mpi_modify,mpi_other\n");
    ofs.write(header.data(), header.size());

    // write benchmark data
    std::string lines;
    for (auto entry : data) {
        lines.append(entry.getStr());
        lines.append("\n");
    }
    lines.pop_back(); //remove last new character line
    ofs.write(lines.data(), lines.size());

    // close file
    ofs.close();
}