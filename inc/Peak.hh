#pragma once

#include "Cuboid.hh"
#include <fstream>


class Peak: public Cuboid{
    private:

    public:
        /*!
        *   \brief Konstruktor bezparametryczny
        */
        Peak();
        /*!
        *   \brief Destruktor
        */
        ~Peak();
        /*!
        *   \brief Konstruktor parametryczny
        */
        Peak(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle);
        /*!
        *   \brief Metoda wirtualna odpowiadajaca za zwracanie typu klasy
        */
        virtual const std::string ObjectType() const override {return "Gora z ostrym szczytem";};
        /*!
        *   \brief Metoda znieksztalcajaca prostopadloscian i zapisujaca dane do pliku
        */
        bool Count_Save_GlobalCoor();
};
