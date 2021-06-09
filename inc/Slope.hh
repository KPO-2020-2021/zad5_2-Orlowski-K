#pragma once

#include "Cuboid.hh"
#include <fstream>

class Slope: public Cuboid{


    public:
        /*!
        *   \brief Konstruktor bezparametryczny
        */
        Slope();
        /*!
        *   \brief Destruktor
        */
        ~Slope();
        /*!
        *   \brief Konstruktor parametryczny
        */
        Slope(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle);
        /*!
        *   \brief Metoda znieksztalcajaca prostopadloscian i zapisujaca dane do pliku
        */
        bool Count_Save_GlobalCoor();
        /*!
        *   \brief Metoda wirtualna zwracajaca typ klasy
        */
        virtual const std::string ObjectType() const override {return "Gora z dluga grania";};
};