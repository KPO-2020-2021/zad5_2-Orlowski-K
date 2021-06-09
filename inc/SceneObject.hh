#pragma once

#include <memory>
#include "Vector3D.hh"
class SceneObject{

    public :
        /*!
        *   \brief Metoda wirtualna zwracajaca typ klasy
        */
        virtual const std::string ObjectType() const {return "SceneObject";};
        /*!
        *   \brief Metoda wirtualna zwracajaca sciezke do pliku z docelowa bryla
        */
        virtual const std::string& TakeFilename_FinalSolid() const = 0;
        /*!
        *   \brief Metoda wirtualna zwracajaca wektor polozenia
        */
        virtual const Vector3D& Take() const = 0;

};
