#pragma once

#include "Cuboid.hh"
#include <fstream>


class Plateau: public Cuboid{


    public:
        /*!
        *   \brief Konstruktor bezparametryczny
        */
        Plateau();
        /*!
        *   \brief Destruktor
        */
        ~Plateau();
        /*!
        *   \brief Konstruktor parametryczny
        */
        Plateau(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle);
        /*!
        *   \brief Metoda znieksztalcajaca prostopadloscian i zapisujaca dane do pliku
        */
        bool Count_Save_GlobalCoor();
        /*!
        *   \brief Metoda wirtualna odpowiadajaca za zwracanie typu klasy
        */
        virtual const std::string ObjectType() const override {return "Plaskowyz";};
};