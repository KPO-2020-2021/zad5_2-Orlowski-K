#pragma once

#include "Cuboid.hh"


class Peak: public Cuboid{


    public:

        virtual const char* Type() const override {return "Peak";};
};