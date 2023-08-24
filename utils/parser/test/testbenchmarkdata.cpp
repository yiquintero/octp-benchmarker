#include <gtest/gtest.h>
#include "benchmarkdata.h"

class TestBenchmarkData : public testing::Test 
{
protected:

    TestBenchmarkData() {
        data.config = OCTPConfigurations::tc;
        data.particles = 1500;
        data.time_steps = 1000000;
        data.memory = 45.38;
        data.runtime = 96785;
        data.loop_time = 3487;
        data.mpi_pair = 36.55;
        data.mpi_bond = 14.25;
        data.mpi_neigh = 9.01;
        data.mpi_comm = 0.03;
        data.mpi_output = 0.0;
        data.mpi_modify = 21.47;
        data.mpi_other = 0.85;
    }
    ~TestBenchmarkData() {}

    BenchmarkData data;

};

TEST_F(TestBenchmarkData, CorrectOCTPConfigurationIsReturned) {
    BenchmarkData d1, d2 , d3, d4, d5, d6;
    d1.config = OCTPConfigurations::none;
    d2.config = OCTPConfigurations::all;
    d3.config = OCTPConfigurations::sdo;
    d4.config = OCTPConfigurations::rdf;
    d5.config = OCTPConfigurations::tc;
    d6.config = OCTPConfigurations::visc;

    EXPECT_EQ(d1.getOCTPConfigurationStr(d1.config), "none");
    EXPECT_EQ(d2.getOCTPConfigurationStr(d2.config), "all");
    EXPECT_EQ(d3.getOCTPConfigurationStr(d3.config), "sdo");   
    EXPECT_EQ(d4.getOCTPConfigurationStr(d4.config), "rdf");
    EXPECT_EQ(d5.getOCTPConfigurationStr(d5.config), "tc");
    EXPECT_EQ(d6.getOCTPConfigurationStr(d6.config), "visc");
}

TEST_F(TestBenchmarkData, CorrectStrForStructIsReturned) {
    std::string expected = "tc,1500,1000000,45.38,96785,3487,36.55,14.25,9.01,0.03,0.0,21.47,0.85";
    EXPECT_EQ(expected, data.getStr());
}