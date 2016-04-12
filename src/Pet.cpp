#include "Pet.hpp"

namespace Fumaroos {
    Pet::Pet(SPECIES sp, std::string nm){
        species = sp;
        name = nm;
    };

    int Pet::getHappiness() const {
        return petStats.happiness;
    }

    int Pet::getAnger() const {
        return petStats.anger;
    }

    int Pet::getIntelligence() const {
        return petStats.intelligence;
    }

    void Pet::setHappiness(int level) {

    }

    void Pet::setAnger(int level) {

    }

    void Pet::setIntelligence(int level) {

    }


};


