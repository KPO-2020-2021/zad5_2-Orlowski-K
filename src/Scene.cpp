#include "Scene.hh"



Scene::Scene(){
}


/*!
 *   \brief Konstruktor parametryczny klasy Scena
 *
 * 
 *   \param [in]  DroneContener      - kontener zawierajacy drony
 *   \param [in]  Filename           - sciezka do pliku z powierzchnia
 *   \param [in]  Link_2             - lacze do modulu z programem GNUPlot
 *   \retval  Tworzy obiekt klasy Scene z polami wypelnionymi przez podane wartosci
 */
Scene::Scene(std::vector<std::shared_ptr<Drone>> &DroneContener,std::list<std::shared_ptr<SceneObject>> &ObjectList,std::string Filename, PzG::LaczeDoGNUPlota &Link_2 ){
    Drones = DroneContener;
    Objects = ObjectList;
    Filename_Surface = Filename;
    Link = Link_2;
    Active = 0;
}


/*!
 *   \brief Metoda dodajaca drona do sceny
 *
 *   \param [in] NewDrone - dodawnay dron 
 *   \retval  Dodanie zadanego drona do pola konteneru w scenie
 */
void Scene::AddDrone(std::shared_ptr<Drone> NewDrone){
    Drones.push_back(NewDrone);
    
    DrawDrone(NewDrone);
    if(Drones.size() == 1)
        Active = 0;


}

/*!
 *   \brief Metoda dodajaca pliki drona do sceny
 *
 *   \param [in] Drone - wskaznik na danego dron a
 *   \retval  Dodanie plikow zadanego drona do rysowania na scenie
 */
void Scene::DrawDrone(std::shared_ptr<Drone> Drone){
    std::string Filename;

    Filename = Drone->TakeFilename_Body();
    
    Link.DodajNazwePliku( Filename.c_str() );
    for(unsigned int Ind = 0; Ind < 4 ; ++Ind){
        Filename = Drone->TakeFilename_Rotor((*Drone)[Ind]);
        Link.DodajNazwePliku(Filename.c_str());
    }
}


/*!
 *   \brief Metoda zmieniajaca aktywnego drona.
 *   Wyswietla aktywne drony wraz z polozeniami i pozwala uzytkownikowi na wybor.
 *   Numery dronow sa odzwierciedlone w kolejnosci dodawania ich do kontenera.
 *   Drony sa numerowane od 0 kolejnymi liczbami naturalnymi.
 *
 *   \retval  Zmiana wartosci pola Active sceny na podany przez uzytkownika.
 */
void Scene::SwitchActiveDrone(){

    std::cout << "Wybor aktywnego drona" << std::endl << std::endl;
    unsigned int option;
    for(unsigned int i=0; i < Drones.size(); ++i){
        std::cout << i << " - Polozenie (x,y): " << Drones.at(i)->TakeLayout()[0]<< "  " << Drones.at(i)->TakeLayout()[1];
        if( i == Active)
            std::cout << " <--- Dron aktywny";
        std::cout << std::endl << std::endl;
    }
    std::cout << "Wprowadz numer aktywnego drona > ";
    std::cin >> option;
    std::cout << std::endl << std::endl;

    if(option >= Drones.size()){
        std::cerr << std::endl << "Podany numer nie istnieje!!!" << std::endl;
        std::cout << "Powrot do menu. Brak zmiany !!!" << std::endl << std::endl;
    }
    else{
        Active = option;
    }

}

/*!
 *   \brief Metoda Metoda pozwalajaca na dostep do aktywnego drona z mozliwoscia modyfikacji
 *   \retval Dron z kontenera wskazywany przez parametr Actve
 */
std::shared_ptr<Drone> Scene::UseActiveDrone(){
    return Drones.at(Active);
}

/*!
 *   \brief Metoda Metoda pozwalajaca na dostep do aktywnego drona w trybie tylko do odczytu
 *   \retval Dron z kontenera wskazywany przez parametr Actve
 */
const std::shared_ptr<Drone> Scene::TakeActiveDrone() const{
    return Drones.at(Active);
}


/*!
 *   \brief Metoda dodajaca wskazniki na obiekty sceny do listy
 *
 *   \param [in] Drone - wskaznik na dany obiekt sceny
 *   \retval  Dodanie obiektow do listy sceny
 */
void Scene::AddObject(std::shared_ptr<SceneObject> NewObject){
    Objects.push_back(NewObject);
    std::string Filename;
    // Dla obiektow typu Drone wywolywana jest specjalna dodatkowa funkcjia z rzutowaniem
    if(NewObject->ObjectType() != "Drone"){
        Filename = NewObject->TakeFilename_FinalSolid();
        Link.DodajNazwePliku( Filename.c_str() );
    }
    else{
        this->AddDrone(std::dynamic_pointer_cast<Drone>(NewObject));
    }

}

/*!
 *   \brief Metoda usuwajaca wskazniki na obiekty sceny z listy
 *
 *   \param [in] number_of_element - numer elementu listy liczac od 1 (1 i 2 zabronione jako drony)
 * 
 *   \retval true  - udalo sie usunac 
 *   \retval false - w przeciwnym wypadku 
 */
bool Scene::DeleteObject(const unsigned int &number_of_element){
    std::list<std::shared_ptr<SceneObject>>::iterator Iter = Objects.begin();
    if(number_of_element - 1 > Objects.size())
        return false;
    else if(number_of_element -1 < 2){
        std::cout << "Nie usuwaj dronow!\n";
        return false;
    }
    else{
        std::advance(Iter,number_of_element - 1);
        Objects.erase(Iter);
    }
    return true;
}


/*!
 *   \brief Metoda wyswietlajaca elementy listy (pomijajac drony) wraz z indeksami do 1
 * 
 *   \retval true  - wyswietlono elementy listy 
 *   \retval false - lista jest pusta (nie liczac dronow) 
 */
bool Scene::ShowList() {
    unsigned int index = 0;

    if(Objects.size() == 2)
        return false;
    
    for(std::shared_ptr<SceneObject> &i : Objects){
        if(i->ObjectType() != "Drone")
            std::cout<< "  " << ++index << " - (" << i->Take()[0] << ", " << i->Take()[1] << ") "<< i->ObjectType() << std::endl;
        else{
            ++index;
        }
    }

    return true;
}


/*!
 *   \brief Metoda dodajaca pliki do rysowania na scenie
 */
void Scene::Redraw(){

    std::string Filename;
    Link.UsunWszystkieNazwyPlikow();
    Link.DodajNazwePliku(Filename_Surface.c_str());


    for(std::shared_ptr<SceneObject> &i : Objects){
        if(i->ObjectType() != "Drone"){
            Filename = i->TakeFilename_FinalSolid();
            Link.DodajNazwePliku(Filename.c_str());
        }
        else{
            DrawDrone(std::dynamic_pointer_cast<Drone>(i));
        }
    }

}