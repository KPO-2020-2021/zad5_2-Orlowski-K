#include "Peak.hh"

/*!
 *   \brief Konstruktor bezparametryczny
 *    Wywoluje konstruktor klasy nadrzednej Cuboid
 */
Peak::Peak():
    Cuboid(){
}

/*
unsigned int Peak::TakeNumber() const{
    unsigned int tmp = number_of_peaks;
    return tmp;
}

*/
Peak::~Peak(){
}


/*!
 *   \brief Konstruktor parametryczny klasy Peak
 *
 *   Wykorzystuje wywolanie konstruktora klasy Cuboid i zapisuje dane do pliku
 * 
 *   \param [in]  File1     - sciezka do pliku ze wzorcowymi brylami
 *   \param [in]  File2     - sciezka do pliku z docelowymi brylami
 *   \param [in]  V_scale   - wektor skalujacy
 *   \param [in]  V         - wektor opisujacy polozenie w przestrzeni
 *   \param [in]  angle     - kat orientacji bryly w przestrzeni
 *   \retval    Obiekt klasy Peak z zainicjowanymi polami
 */
Peak::Peak(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle):
    Cuboid(File1,File2,V_scale,V,angle){
        this->Count_Save_GlobalCoor();
}


/*!
 *   \brief Metoda zapisujaca dane globalne gory
 *    Wykorzystuje prostopadloscian do znieksztalcen
 *    a nastepnie zapisuje nowe dane do podanego pliku
 *
 *   \retval true  - udalo sie zapisac zmiany do plikow
 *   \retval false - w przeciwnym wypadku 
 */
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




