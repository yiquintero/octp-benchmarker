#include "benchmarkdata.h"
#include "fileparser.h"
#include "filewriter.h"


int main ()
{
    std::vector<std::string> cases{"../data/octp_all", "../data/octp_none", "../data/octp_rdf", "../data/octp_selfdiffusion_onsager", "../data/octp_tc", "../data/octp_viscosity"};
    std::vector<std::string> particles{"512"};
    std::vector<std::string> timesteps{"100K", "500K"};
    //std::vector<std::string> runs{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::vector<std::string> runs{"0"};
    std::vector<std::pair<OCTPConfigurations, std::string>> files;

    std::vector<OCTPConfigurations> configs{OCTPConfigurations::all, OCTPConfigurations::none, OCTPConfigurations::rdf,
        OCTPConfigurations::sdo, OCTPConfigurations::tc, OCTPConfigurations::visc}; // must match order of cases
    unsigned int i = 0;

    for (auto c : cases) {
        for (auto np : particles) {
            for (auto ts : timesteps) {
                for (auto run : runs) {
                    files.push_back({configs[i], {c + "/" + np + "_" + ts + "_" + run + ".txt"}});
                }
            }
        }
        i++;
    }

    FileParser parser;
    auto data = parser.parse(files);

    FileWriter writer;
    writer.write("octpbenchmarkdata.csv", data);

    return 0;

}