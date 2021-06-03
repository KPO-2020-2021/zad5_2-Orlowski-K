#pragma once

#include <memory>

class SceneObject{

    public :
        
        virtual const std::string ObjectType() const {return "SceneObject";};
    
        virtual const std::string& TakeFilename_FinalSolid() const = 0;

};
