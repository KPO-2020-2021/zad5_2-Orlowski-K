#pragma once

#include "Cuboid.hh"

class Slope: public Cuboid{


    public:

        virtual const std::string ObjectType() const override {return "Slope";};
};