#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void usage() {
    cout << "Usage: mapToBin [inFile] [outFile]" << endl;
    cout << "Takes a map file and compiles it into a simple binary based on it's contents." << endl;
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) usage();
    ofstream outputFile(argv[2], ios::binary);
    vector<unsigned char> bytesToWrite;

    // Reserve for Width and Height
    bytesToWrite.push_back(0);
    bytesToWrite.push_back(0);

    int width = 0;
    int height = 0;
    string resource(argv[1]);
    ifstream file(resource);
    string line;

    while (getline(file, line)) {
        istringstream stringStream(line);
        width = 0;
        unsigned int value;
        while (stringStream >> value) {
            bytesToWrite.push_back(value);
            width++;
        }
        height++;
    }
    bytesToWrite[0] = width;
    bytesToWrite[1] = height;
    outputFile.write(reinterpret_cast<const char *>(bytesToWrite.data()), bytesToWrite.size());
    cout << "Done writing to " << argv[2] << endl;
    return 0;
}