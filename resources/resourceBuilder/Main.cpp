#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void usage() {
    cout << "Usage: resourceBuilder [outputFile] [files...]" << endl;
    cout << "Takes an output file and a list of files and compiles all the given files into the one output file."
         << endl;
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) usage();
    ofstream outputFile(argv[1], ios::binary);

    outputFile << argc - 2 << " ";

    for (int i = 2; i < argc; i++) {
        string resource(argv[i]);
        ifstream file(resource, ios::binary);
//        vector<uint8_t> buffer;
//        uint8_t byte;
//        while (file >> byte) {
//            buffer.push_back(byte);
//        }


        // get pointer to associated buffer object
        std::filebuf *pbuf = file.rdbuf();

        // get file size using buffer's members
        std::size_t size = pbuf->pubseekoff(0, file.end, file.in);
        pbuf->pubseekpos(0, file.in);
        cout << "Writing file " << resource << " size " << size << endl;
        outputFile << resource << " " << size << '|';
        outputFile << pbuf;
        // outputFile.write(reinterpret_cast<const char *>(buffer.data()), buffer.size());
    }
    cout << "Done writing to " << argv[1] << endl;
    return 0;
}