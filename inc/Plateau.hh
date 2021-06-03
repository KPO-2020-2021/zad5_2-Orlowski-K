#pragma once

#include "Cuboid.hh"


class Plateau: public Cuboid{


    public:

        virtual const std::string ObjectType() const override {return "Plateau";};
};