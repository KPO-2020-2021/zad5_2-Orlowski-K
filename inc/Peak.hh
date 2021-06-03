#pragma once

#include "Cuboid.hh"
#include <fstream>


class Peak: public Cuboid{
    private:

        // static unsigned int number_of_peaks;

    public:

        Peak();

        ~Peak();

        Peak(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle);

        virtual const std::string ObjectType() const override {return "Peak";};

        unsigned int TakeNumber() const;

        bool Count_Save_GlobalCoor();
};
