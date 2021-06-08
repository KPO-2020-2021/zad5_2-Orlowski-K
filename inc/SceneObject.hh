#pragma once

#include <memory>
#include "Vector3D.hh"
class SceneObject{

    public :
        
        virtual const std::string ObjectType() const {return "SceneObject";};
    
        virtual const std::string& TakeFilename_FinalSolid() const = 0;

        virtual const Vector3D& Take() const = 0;

};
