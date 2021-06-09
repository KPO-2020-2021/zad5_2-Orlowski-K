#include "Slope.hh"

Slope::Slope():
    Cuboid(){
       // ++number_of_peaks;
}
/*
unsigned int Peak::TakeNumber() const{
    return number_of_peaks;
}
*/

Slope::~Slope(){
    //--number_of_peaks;
}


/*!
 *   \brief Konstruktor parametryczny klasy Slope
 *
 *   Wykorzystuje wywolanie konstruktora klasy Cuboid i zapisuje dane do pliku
 * 
 *   \param [in]  File1     - sciezka do pliku ze wzorcowymi brylami
 *   \param [in]  File2     - sciezka do pliku z docelowymi brylami
 *   \param [in]  V_scale   - wektor skalujacy
 *   \param [in]  V         - wektor opisujacy polozenie w przestrzeni
 *   \param [in]  angle     - kat orientacji bryly w przestrzeni
 *   \retval    Obiekt klasy Slope z zainicjowanymi polami
 */
Slope::Slope(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle):
    Cuboid(File1,File2,V_scale,V,angle){
        this->Count_Save_GlobalCoor();
}



bool Slope::Count_Save_GlobalCoor(){
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
                tmp[0] = fabs(tmp[0]);
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