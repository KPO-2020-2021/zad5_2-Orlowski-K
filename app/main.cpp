// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <memory>

#include "exampleConfig.h"
#include "example.h"
#include "Vector3D.hh"
#include "Matrix3x3.hh"
#include "Drone.hh"
#include "Scene.hh"
#include "SceneObject.hh"
#include "Peak.hh"
#include "Slope.hh"
#include "Plateau.hh"
#include "../inc/lacze_do_gnuplota.hh"

#define SURFACE "../datasets/templates/surface.dat"
#define FILE_OBSTACLE "../datasets/templates/obstacle.dat"
#define FLIGHTHEIHGT 80


int main() {
    PzG::LaczeDoGNUPlota Link;
    unsigned int number_of_drones = 0;
    Vector3D Layout1 = {30,30,0}, Layout2 = {160,100,0};
    double   Orient1 = 0, Orient2 = 25, Angle = 0;
    double   FlightLen;

    std::shared_ptr<Drone> FirstDrone(new Drone()), SecondDrone(new Drone());
    std::shared_ptr<Peak>  FirstPeak(new Peak(FILE_OBSTACLE,"../datasets/dat/Peak1.dat",{20,20,60},{120,30,0},0) );
    std::shared_ptr<Peak>  SecondPeak(new Peak(FILE_OBSTACLE,"../datasets/dat/Peak2.dat",{40,40,50},{35,150,0},0) );
    std::shared_ptr<Slope> FirstSlope(new Slope(FILE_OBSTACLE,"../datasets/dat/Slope1.dat",{20,80,60},{60,90,0},0) );
    std::shared_ptr<Plateau> FirstPlateau(new Plateau(FILE_OBSTACLE,"../datasets/dat/Plateau1.dat",{50,60,15},{105,105,0},0) );

    std::vector<Vector3D>                   TracePoints;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;

    Scene Scene(Drones,Objects,SURFACE,Link);
    char option[1] = {'m'};

    FirstDrone->MakeDrone(Layout1,Orient1,number_of_drones);
    FirstDrone->Count_Save_GlobalCoor();

    SecondDrone->MakeDrone(Layout2,Orient2,number_of_drones);
    SecondDrone->Count_Save_GlobalCoor();

    FirstPeak->Count_Save_GlobalCoor();
    SecondPeak->Count_Save_GlobalCoor();
    FirstSlope->Count_Save_GlobalCoor();
    FirstPlateau->Count_Save_GlobalCoor();


    Scene.CreateSurface();
    Scene.AddObject(FirstDrone);
    Scene.AddObject(SecondDrone);
    Scene.AddObject(FirstPeak);
    Scene.AddObject(SecondPeak);
    Scene.AddObject(FirstSlope);
    Scene.AddObject(FirstPlateau);

    Link.ZmienTrybRys(PzG::TR_3D);
    Link.Inicjalizuj();

    Link.UstawZakresX(0, 200);
    Link.UstawZakresY(0, 200);
    Link.UstawZakresZ(0, 120);


    Link.UstawRotacjeXZ(64,65);

    Link.Rysuj();



    while(option[0] != 'k'){
        switch(option[0]){
            case 'a':
                Scene.SwitchActiveDrone();
                std::cout << "Polozenie Drona aktywnego (x,y): " << Scene.TakeActiveDrone()->TakeLayout()[0]<< "  " << Scene.TakeActiveDrone()->TakeLayout()[1] << std::endl << std::endl;
                std::cout << "Aktualna ilosc obiektow Vector: " << Layout1.show_active_vectors() << std::endl;
                std::cout << "  Laczna ilosc obiektow Vector: " << Layout1.show_all_vectors() << std::endl << std::endl;
                break;
            case 'p':
                std::cout << "Podaj kierunek lotu (kat w stopniach) > ";
                std::cin >> Angle;
                std::cout << "Podaj dlugosc lotu > ";
                std::cin >> FlightLen;
                std::cin.ignore(10000,'\n');

                Link.ZmienTrybRys(PzG::TR_3D);
                Link.Inicjalizuj();

                Link.UstawZakresX(0, 200);
                Link.UstawZakresY(0, 200);
                Link.UstawZakresZ(0, 120);


                Link.UstawRotacjeXZ(64,65);

                Link.Rysuj();
                std::cout << std::endl << "Nacisnij ENTER, aby pokazac sciezke przelotu drona " << std::flush;
                std::cin.ignore(10000,'\n');

                Scene.UseActiveDrone()->MakeTrack(Angle,FlightLen,TracePoints);
                Link.DodajNazwePliku(FLIGHT_TRACK);
                Link.Rysuj();
                
                std::cout << "Nacisnij ENTER, aby wykonac animacje lotu drona " << std::flush;
                std::cin.ignore(10000,'\n');


                if(!Scene.UseActiveDrone()->MakeVerticalFlight(FLIGHTHEIHGT,Link)) return 1;

                if(!Scene.UseActiveDrone()->Change_Orientation(Angle,Link)) return 1;

                if(!Scene.UseActiveDrone()->MakeHorizontalFlight(FlightLen,Link)) return 1;

                if(!Scene.UseActiveDrone()->MakeVerticalFlight(-FLIGHTHEIHGT,Link)) return 1;

                std::cout << std::endl << "Nacisnij ENTER, aby usunac sciezke ... " << std::flush;
                std::cin.ignore(10000,'\n');

                Link.UsunOstatniaNazwe();
                Link.Rysuj();
                
                std::cout << "Nacisnij ENTER, aby zakonczyc ... " << std::flush;
                std::cin.ignore(10000,'\n');
                std::cout << std::endl;
                
                std::cout << "Polozenie Drona aktywnego (x,y): " << Scene.TakeActiveDrone()->TakeLayout()[0]<< "  " << Scene.TakeActiveDrone()->TakeLayout()[1] << std::endl <<std::endl;
                std::cout << "Aktualna ilosc obiektow Vector: " << Layout1.show_active_vectors() << std::endl;
                std::cout << "  Laczna ilosc obiektow Vector: " << Layout1.show_all_vectors() << std::endl << std::endl;

                break;
            case 'm':
                std::cout << "Polozenie Drona aktywnego (x,y): " << Scene.TakeActiveDrone()->TakeLayout()[0] << "  "<<Scene.TakeActiveDrone()->TakeLayout()[1] << std::endl;
                std::cout << "a - wybierz aktywnego drona\n";
                std::cout << "p - zadaj parametry przelotu\n";
                std::cout << "r - obrot po oktagonie\n";
                std::cout << "m - wyswietl menu\n\n";
                std::cout << "k - koniec dzialania programu\n\n";
                std::cout << "Aktualna ilosc obiektow Vector: " << Layout1.show_active_vectors() << std::endl;
                std::cout << "  Laczna ilosc obiektow Vector: " << Layout1.show_all_vectors() << std::endl << std::endl;
                break;
            case 'r':
                Link.ZmienTrybRys(PzG::TR_3D);
                Link.Inicjalizuj();

                Link.UstawZakresX(0, 200);
                Link.UstawZakresY(0, 200);
                Link.UstawZakresZ(0, 120);


                Link.UstawRotacjeXZ(64,65);

                Link.Rysuj();
                std::cin.ignore(10000,'\n');

                if(!Scene.UseActiveDrone()->MakeVerticalFlight(FLIGHTHEIHGT,Link)) return 1;

                if(!Scene.UseActiveDrone()->MakeHorizontalFlight(10,Link)) return 1;

                if(!Scene.UseActiveDrone()->Change_Orientation(112.5,Link)) return 1;

                for (unsigned int i = 0; i < 8; ++i){
                    if(!Scene.UseActiveDrone()->MakeHorizontalFlight(10,Link)) return 1;
                    if(!Scene.UseActiveDrone()->Change_Orientation(45,Link)) return 1;
                }
                if(!Scene.UseActiveDrone()->Change_Orientation(67.5,Link)) return 1;
                if(!Scene.UseActiveDrone()->MakeHorizontalFlight(10,Link)) return 1;
                

                if(!Scene.UseActiveDrone()->MakeVerticalFlight(-FLIGHTHEIHGT,Link)) return 1;

                std::cout << "Polozenie Drona aktywnego (x,y): " << Scene.TakeActiveDrone()->TakeLayout()[0] << "  "<<Scene.TakeActiveDrone()->TakeLayout()[1] << std::endl;
                std::cout << "Aktualna ilosc obiektow Vector: " << Layout1.show_active_vectors() << std::endl;
                std::cout << "  Laczna ilosc obiektow Vector: " << Layout1.show_all_vectors() << std::endl << std::endl;

                break;

            default:
                exit(1);
        }
        std::cout << "Twoj wybor <m - menu> ";
        std::cin >> option;
        std::cout <<std::endl;
    }
    std::cout << "Koniec dzialania programu Dragonfly\n";





}
