#ifndef FUMAROOS_PET_HPP
#define FUMAROOS_PET_HPP

#include "PetSpecies.hpp"
#include <string>

namespace Fumaroos {

    class Pet {
    public:
        Pet(SPECIES sp, std::string nm);

        ~Pet();

        int getHappiness() const;

        int getAnger() const;

        int getIntelligence() const;

        void setHappiness(int level);

        void setAnger(int level);

        void setIntelligence(int level);


    private:
        struct petStats {
            int happiness, anger, intelligence;
        } petStats;
        std::string name;
        SPECIES species;

    };
}

#endif //FUMAROOS_PET_HPP
