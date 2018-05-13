#include "ResourceManager.h"

#include <fstream>
#include <iostream>

using namespace std;

ResourceManager::ResourceManager() {
    ifstream compressedResources("resources/A.bin", ios::binary);
    int numResources;
    if (!compressedResources) {
        cerr << "Invalid open!" << endl;
        exit(1);
    }
    compressedResources >> numResources;
    for (int i = 0; i < numResources; i++) {
        string resourceName;
        unsigned int size;
        char bar;
        compressedResources >> resourceName >> size >> bar;
        if (bar != '|') {
            cerr << "ERROR!!!" << endl;
        }
        cout << "Loading resource: " << resourceName << " of size: " << size << endl;
        internalResourceMap[resourceName] = vector<unsigned char>(size);
        compressedResources.read(reinterpret_cast<char *>(internalResourceMap[resourceName].data()), size);
    }
}

ResourceManager::~ResourceManager() {
    for (auto ptr : texturePool) {
        free(ptr);
    }
}

void ResourceManager::loadResourceIntoImage(sf::Image &image, string resourceName) {
    vector<unsigned char> &data = internalResourceMap[resourceName];
    image.loadFromMemory(data.data(), data.size());
}

void ResourceManager::loadResourceIntoTexture(sf::Texture &texture, string resourceName) {
    vector<unsigned char> &data = internalResourceMap[resourceName];
    texture.loadFromMemory(data.data(), data.size());
}

unsigned char *ResourceManager::getResourceAddress(std::string resourceName) {
    return internalResourceMap[resourceName].data();
}

size_t ResourceManager::getResourceSize(string resourceName) {
    return internalResourceMap[resourceName].size();
}

sf::Sprite ResourceManager::getSpriteFromResourceName(const std::string resourceName) {
    auto *texture = new sf::Texture;
    loadResourceIntoTexture(*texture, resourceName);
    texturePool.push_back(texture);
    return sf::Sprite(*texture);
}

sf::Font ResourceManager::getFontFromResourceName(const std::string resourceName) {
    sf::Font font;
    vector<unsigned char> &data = internalResourceMap[resourceName];
    font.loadFromMemory(data.data(), data.size());
    return font;
}

