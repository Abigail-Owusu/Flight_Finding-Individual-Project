
//
// Created by Abigail Animah Owusu on 21/11/2022.
//
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<vector>
#include "Route.h"
using namespace std;


class Node {
public:
    shared_ptr<Node> parent;
    string airport_code;
    int stops;
    shared_ptr<vector<Route> > successors;
    string airLineCode;

    Node(shared_ptr<Node> parent, string airportCode, int stops, shared_ptr<vector<Route> > successors,
         string airLineCode) {
        this->parent = parent;
        this->airport_code = airportCode;
        this->stops = stops;
        this->successors = successors;
        this->airLineCode = airLineCode;
    }

    string get_airport_code() {
        return this->airport_code;
    }

    int getStops(){
        return this->stops;
    }

    string getAirlineCode(){
        return this->airLineCode;
    }

    bool operator==(const Node&  node) {
        return node.airport_code == this->airport_code && node.airLineCode == this->airLineCode &&
        node.successors == this->successors;
    }

    /**This function returns a solution
     *
     * */
    vector<string> solution_path(){
        vector<string> airport_codes;
        vector<string> solution;
        vector<string> airline_codes;
        vector<int> stops;
        Node* this_node = this;

        while (this_node!= nullptr){
            airline_codes.push_back(this_node->getAirlineCode());
            airport_codes.push_back(this_node->get_airport_code());
            stops.push_back(this_node->getStops());
            this_node = this_node->parent.get();

        }
        reverse(airline_codes.begin(), airline_codes.end());
        reverse(airport_codes.begin(), airport_codes.end());

        for (int i = 0;i < airline_codes.size()-1;i++){
            string result = airline_codes.at(i+1) + " from " + airport_codes.at(i) + " to " +
                            airport_codes.at(i+1) + " " + to_string(stops.at(i)) + " stops.";
            solution.push_back(result);
        }
        return solution;

    }

};