#pragma once

#include "Cuboid.hh"

class Slope: public Cuboid{


    public:

        virtual const char* Type() const override {return "Slope";};
};