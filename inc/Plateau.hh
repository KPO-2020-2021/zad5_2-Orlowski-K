#pragma once

#include "Cuboid.hh"
#include <fstream>


class Plateau: public Cuboid{


    public:
        Plateau();

        ~Plateau();

        Plateau(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle);

        bool Count_Save_GlobalCoor();

        virtual const std::string ObjectType() const override {return "Plateau";};
};