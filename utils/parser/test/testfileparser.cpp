#include <gtest/gtest.h>
#include "benchmarkdata.h"
#include "fileparser.h"

class TestFileParser : public testing::Test 
{
protected:

    TestFileParser() {
        testdata.push_back({OCTPConfigurations::none, "../testdata/none_512_100K_0.txt"});
        testdata.push_back({OCTPConfigurations::all, "../testdata/all_512_500K_0.txt"});
    }

    ~TestFileParser() {}

    std::vector<std::pair<OCTPConfigurations, std::string>> testdata;

};

TEST_F(TestFileParser, ExceptionThrownForNonExistentInputFile) {
    FileParser p;
    EXPECT_THROW(p.parse({{OCTPConfigurations::sdo, "fakeinputfile.txt"}}), std::runtime_error);
}

TEST_F(TestFileParser, ReadingAndParsingDoesNotThrowException) {
    FileParser p;
    EXPECT_NO_THROW(p.parse({testdata[0]}));
}

TEST_F(TestFileParser, OCTPConfigurationIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_EQ(b[0].config, OCTPConfigurations::none);
    EXPECT_EQ(b[1].config, OCTPConfigurations::all);
}

TEST_F(TestFileParser, NumberOfParticlesIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_EQ(b[0].particles, 512);
    EXPECT_EQ(b[1].particles, 512);
}

TEST_F(TestFileParser, NumberOfTimeStepsIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_EQ(b[0].time_steps, 100000);
    EXPECT_EQ(b[1].time_steps, 500000);
}

TEST_F(TestFileParser, MemoryIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].memory, 1.98);
    EXPECT_FLOAT_EQ(b[1].memory, 2.84);
}

TEST_F(TestFileParser, RuntimeIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_EQ(b[0].runtime, 22);
    EXPECT_EQ(b[1].runtime, 115);
}

TEST_F(TestFileParser, LoopTimeIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].loop_time, 14.64);
    EXPECT_FLOAT_EQ(b[1].loop_time, 108.46);
}

TEST_F(TestFileParser, MPIPairIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].mpi_pair, 37.04);
    EXPECT_FLOAT_EQ(b[1].mpi_pair, 34.05);
}

TEST_F(TestFileParser, MPIBondIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].mpi_bond, 0.02);
    EXPECT_FLOAT_EQ(b[1].mpi_bond, 0.02);
}

TEST_F(TestFileParser, MPINeighIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].mpi_neigh, 0.90);
    EXPECT_FLOAT_EQ(b[1].mpi_neigh, 0.68);
}

TEST_F(TestFileParser, MPICommIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].mpi_comm, 53.86);
    EXPECT_FLOAT_EQ(b[1].mpi_comm, 43.42);
}

TEST_F(TestFileParser, MPIOutputIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].mpi_output, 0);
    EXPECT_FLOAT_EQ(b[1].mpi_output, 0.83);
}

TEST_F(TestFileParser, MPIModifyIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].mpi_modify, 6.03);
    EXPECT_FLOAT_EQ(b[1].mpi_modify, 19.46);
}

TEST_F(TestFileParser, MPIOtherIsRetrievedCorrectly) {
    FileParser p;
    auto b = p.parse(testdata);
    EXPECT_FLOAT_EQ(b[0].mpi_other, 2.14);
    EXPECT_FLOAT_EQ(b[1].mpi_other, 1.54);
}