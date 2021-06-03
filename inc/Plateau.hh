#pragma once

#include "Cuboid.hh"


class Plateau: public Cuboid{


    public:

        virtual const char* Type() const override {return "Plateau";};
};