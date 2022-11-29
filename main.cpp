#include<iostream>
#include "helper_functions.h"
#include "Node.h"
#include "Route.h"
#include <unordered_map>
#include<vector>
#include<deque>
#include<unordered_set>
#include <algorithm>
using namespace std;

//a hashmap that takes the city and country as a key and value is a list of all airports codes
unordered_map<string, vector<string> > citycountry_airportcodes;

//this will take an airport code as the key and city and country as the value
unordered_map<string,string> airport_in_a_particular_country;

//takes in a sourceAirportCode code as the key and value as route object
unordered_map<string, vector<shared_ptr<Route > > > route_map;

/**
 * This function takes in a start city country and an end city country and returns a vector
 * @param  start_city_country,endCityCountry
 * @return a solution path if a solution has been found.
 * */
vector<string>bfs(string start_city_country, string endCityCountry) {

    cout<< "Finding path..."<< endl;

    deque<shared_ptr<Node> > frontier;
    unordered_set<string> explored;

    //retrieving all airport_codes in a specific city country
    vector<string> airport_codes = citycountry_airportcodes[start_city_country];


    if( !airport_codes.empty()){
        for (string airport_code: airport_codes) {
            //creating a new node
            shared_ptr<Node> airportNode = make_shared<Node>(nullptr,airport_code,
                                                             0, nullptr,"");
            frontier.push_back(airportNode);

        }}
    while (!frontier.empty()) {
        shared_ptr<Node> node_to_be_removed = frontier.front();
        frontier.pop_front();
        if (node_to_be_removed == nullptr){
            continue;
        }


        //adding removed node to the explored
        explored.insert(node_to_be_removed->get_airport_code());

        //successor airport_codes it can land in
        vector<shared_ptr<Route> > successors = route_map[node_to_be_removed->get_airport_code()];
        if (!successors.empty()){
            for (shared_ptr<Route> successor:
                    successors) {
                shared_ptr<Node> childNode = make_shared<Node>(node_to_be_removed,successor->getDesAirportCode(),
                                      successor->getStops(), nullptr,successor->getAirlineCode());
                string destination = airport_in_a_particular_country[childNode->get_airport_code()];
                if (destination == endCityCountry) {
                    cout << "Found a path!!\nCheck in the output file" << endl;
                    return childNode->solution_path();

                }
                if (std::find(frontier.begin(), frontier.end(),childNode)==frontier.end()
                && explored.find(childNode->get_airport_code()) == explored.end()){

                    frontier.push_back(childNode);
                }
            }
        }
    }
    cout << "No solution :(" << endl;
    return vector<string>();
}


int main(){
    //loading the data
    cout << "Loading files...\nThis might take a few minutes..." << endl;
    vector<vector< string> > airport_data = file_reader("airports.csv");
    vector<vector< string> > route_data = file_reader("routes.csv");

    //reading the files and populating the routeHashmaps
    for(vector<string> line: route_data){
        shared_ptr<Route> route = make_shared<Route>(line[0], line[2], stoi(line[7]));

        //making sure there are only distinct routes in the routeHashMap
        if(route_map.find(line[4]) != route_map.end()){
            vector< shared_ptr<Route> > new_route_list = route_map.at(line[4]);
            new_route_list.push_back(route);
            route_map[line[4]] = new_route_list;
        } else{
            vector<shared_ptr<Route> > unique_route_list;
            unique_route_list.push_back(route);
            route_map[line[4]] = unique_route_list;
        }
    }

    // populating airports in a particular city_country

    for (vector<string> line: airport_data){
        string city_country = line[2]+ ", "+ line[3];
        string airport_code = line[4];
        airport_in_a_particular_country[airport_code] = city_country;

        //populating allAirportsInACountryHashMap

        if (citycountry_airportcodes.find(city_country) != citycountry_airportcodes.end()){
            vector<string> newAirportList = citycountry_airportcodes.at(city_country);
            newAirportList.push_back(airport_code);
            citycountry_airportcodes[city_country] = newAirportList;
        } else{
            vector<string> uniqueAirportList;
            uniqueAirportList.push_back(airport_code);
            citycountry_airportcodes[city_country] = uniqueAirportList;
        }
    }

    //reading from an inputFile
    string start_location;
    string endLocation;

    string line;
    ifstream input_file("inputFile.txt");

    getline(input_file, start_location);//start city, country
    getline(input_file, endLocation);//end city, country


    ofstream Output_file("Output.txt");
    vector<string> path = bfs(start_location, endLocation);
    int flightNumber = 0;
    if (!path.empty()){
        for (string flight:
                path) {
            Output_file << flight << endl;
            flightNumber++;
        }
        Output_file << "Total flight: "<< flightNumber;
    }else {
        Output_file << "No solution";
    }
    Output_file.close();
}
