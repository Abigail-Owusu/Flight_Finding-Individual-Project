//
// Created by Abigail Animah Owusu on 24/11/2022.
//
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>

using namespace std;


class Airport {
public:
    int airportID;
    string name;
    string city;
    string country;
    string IATACode;
    string ICAOCode;
    double latitude;
    double longitude;
    double altitude;
    double timezone;
    string DST;
    string tz;
    string type;
    string datasource;



    Airport(int airportID, string name, string city, string country, string IATACode,
            string ICAOCode, double latitude, double longitude, double altitude,
            double timezone, string DST, string tz, string type, string datasource) {

        this->airportID = airportID;
        this->name = name;
        this->city = city;
        this->country = country;
        this->IATACode = IATACode;
        this->ICAOCode = ICAOCode;
        this->latitude = latitude;
        this->longitude = longitude;
        this->altitude = altitude;
        this->timezone = timezone;
        this->DST = DST;
        this->tz = tz;
        this->type = type;
        this->datasource = datasource;
    }

    Airport() {
        this->airportID = 0;
        this->name = "";
        this->city = "";
        this->country = "";
        this->IATACode = "";
        this->ICAOCode = "";
        this->latitude = 0;
        this->longitude = 0;
        this->altitude = 0;
        this->timezone = 0;
        this->DST = "";
        this->tz = "";
        this->type = "";
        this->datasource = "";
    }



    int getAirportID() {
        return airportID;
    }


    string getName() {
        return name;
    }

    string getCity() {
        return city;
    }

    string getCountry() {
        return country;
    }

    string getIATACode() {
        return IATACode;
    }

    string getICAOCode() {
        return ICAOCode;
    }

    double getLatitude() {
        return latitude;
    }

    double getLongitude() {
        return longitude;
    }

    double getAltitude() {
        return altitude;
    }

    double getTimezone() {
        return timezone;
    }

    string getDST() {
        return DST;
    }

    string getTz() {
        return tz;
    }

    string getType() {
        return type;
    }

    string getDatasource() {
        return datasource;
    }
};