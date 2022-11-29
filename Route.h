//
// Created by Abigail Animah Owusu on 22/11/2022.
//

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
//
// Created by Abigail Animah Owusu on 22/11/2022.
//


using namespace std;


class Route{
private:
    string airlineCode;
    string desAirportCode;
    int stops;
public:
    //constructor
    Route(string airlineCode,string desAirportCode, int stops){
        this->airlineCode = airlineCode;
        this->desAirportCode = desAirportCode;
        this->stops = stops;
    }

    Route(){
        airlineCode = "";
        desAirportCode = "";
        stops = 0;
    }


    //getters and setters
    string getAirlineCode(){
        return airlineCode;
    }

    void setAirlineCode(string airlineCode){
        airlineCode= airlineCode;
    }


    void setDesAirportCode(string desAirport){
        desAirport = desAirportCode;
    }

    string getDesAirportCode(){
        return desAirportCode;
    }

    int getStops(){
        return stops;
    }

    void setStops(int stops){
        stops = stops;
    }



};