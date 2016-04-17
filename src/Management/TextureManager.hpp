#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <cpp3ds/Graphics.hpp>
#include "../States/StateIdentifiers.hpp"
#include <string>
#include <map>

namespace Fumaroos {

// taken from: https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-3-textures-and-animations/125
    class TextureManager {
    private:
        /* Array of textures used */
        // first is group, then map with all groups elements <filename, texture>
        std::map<States::ID, std::map<std::string, cpp3ds::Texture>> textures;

    public:
        /* Add a texture from a file */
        void loadTexture(const States::ID &group, const std::string &name, const std::string &filename);

        void unloadTextures(const States::ID &group);

        /* Translate an id into a reference */
        cpp3ds::Texture &getRef(const States::ID &group, const std::string &texture);

        /* Constructor */
        TextureManager() {
        }

    };
}
#endif /* TEXTUREMANAGER_HPP */
