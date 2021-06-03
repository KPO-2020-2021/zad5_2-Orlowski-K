#include "Peak.hh"


//static unsigned int number_of_peaks = 0;

Peak::Peak():
    Cuboid(){
       // ++number_of_peaks;
}
/*
unsigned int Peak::TakeNumber() const{
    return number_of_peaks;
}
*/

Peak::~Peak(){
    //--number_of_peaks;
}

Peak::Peak(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle):
    Cuboid(File1,File2,V_scale,V,angle){
        //++number_of_peaks;
}



bool Peak::Count_Save_GlobalCoor(){
    Vector3D tmp;
    std::ifstream File_Template(this->TakeFilename_TemplateSolid());
    std::ofstream File_Final(this->TakeFilename_FinalSolid()); 

    if (!File_Template.is_open()) {
        std::cerr << std::endl
        << " Blad otwarcia do odczytu pliku: " << this->TakeFilename_TemplateSolid() << std::endl
        << std::endl;
        return false;
    }

    if (!File_Final.is_open()) {
        std::cerr << std::endl
        << " Blad otwarcia do odczytu pliku: " << this->TakeFilename_FinalSolid() << std::endl
        << std::endl;
        return false;
    }

    File_Template >> tmp;
    while(!File_Template.fail()){
        
        for(unsigned int VertexNumber = 0; VertexNumber < 4;++VertexNumber){
            if(tmp[2] > 0.5){
                tmp[0] = tmp[1] = 0;
            }
            else if(tmp[2] == 0.5){
                tmp[0] /= 2;
                tmp[1] /= 2;
            }
            tmp = this->TranformToParentialCoordinate(tmp);
            File_Final << tmp <<std::endl;
            File_Template >> tmp;

            assert(VertexNumber ==3 || !File_Template.fail());
        }
        File_Final << std::endl;
    }

    return !File_Final.fail();
}



