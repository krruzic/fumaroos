#include <cpp3ds/Graphics.hpp>
#include <map>
#include <string>

#include "TextureManager.hpp"

namespace Fumaroos {

    void TextureManager::loadTexture(const States::ID &group, const std::string &name, const std::string &filename) {
        /* Load the texture */
        cpp3ds::Texture tex;
        tex.loadFromFile(filename);

        /* Add it to the list of textures */
        this->textures[group].insert(std::make_pair(name, tex));
        return;
    }


    cpp3ds::Texture &TextureManager::getRef(const States::ID &group, const std::string &texture) {
        return textures.at(group).at(texture);
    }


    // unload unneeded textures, this is called automatically when a function is popped
    void TextureManager::unloadTextures(const States::ID &group) {
        if (textures.count(group)) {
            textures.find(group)->second.clear();
        }
    }
}