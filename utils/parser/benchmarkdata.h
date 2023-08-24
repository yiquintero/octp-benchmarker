#pragma once
#include <string>

enum class OCTPConfigurations {none, all, rdf, sdo, tc, visc};

struct BenchmarkData {
    OCTPConfigurations config;  // octp plugin usage
    unsigned int particles;     // number of particles in simulation
    unsigned int time_steps;    // number of simulation time steps
    float memory;               // in GB
    unsigned int runtime;       // in seconds
    float loop_time;            // in seconds
    float mpi_pair;             // % spend on non-bonded force computations
    float mpi_bond;             // % spend on bonded interactions: bonds, angles, dihedrals, impropers
    float mpi_neigh;            // % spend on neighbor list construction
    float mpi_comm;             // % spend on inter-processor communication of atoms and their properties
    float mpi_output;           // % spend on output of thermodynamic info and dump files
    float mpi_modify;           // % spend on fixes and computes invoked by fixes
    float mpi_other;            // % spend on all the remaining time


    std::string getOCTPConfigurationStr(OCTPConfigurations config) {
        switch(config) {
            case OCTPConfigurations::none:
                return "none";
            case OCTPConfigurations::all:
                return "all";
            case OCTPConfigurations::rdf:
                return "rdf";
            case OCTPConfigurations::sdo:
                return "sdo";
            case OCTPConfigurations::tc:
                return "tc";
            case OCTPConfigurations::visc:
                return "visc";
            default:
                return "";
        }
    }

    std::string getStr() {
        std::string str = getOCTPConfigurationStr(config) + ",";
        str.append(std::to_string(particles) + ",");
        str.append(std::to_string(time_steps) + ",");
        str.append(std::to_string(memory) + ",");
        str.append(std::to_string(runtime) + ",");
        str.append(std::to_string(loop_time) + ",");
        str.append(std::to_string(mpi_pair) + ",");
        str.append(std::to_string(mpi_bond) + ",");
        str.append(std::to_string(mpi_neigh) + ",");
        str.append(std::to_string(mpi_comm) + ",");
        str.append(std::to_string(mpi_output) + ",");
        str.append(std::to_string(mpi_modify) + ",");
        str.append(std::to_string(mpi_other));
        return str;
    }
};