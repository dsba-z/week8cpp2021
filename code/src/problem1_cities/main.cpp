#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

//     Main task - to implement the function fillCountries to put countries into a container]
// (vector<Country> or map<std::string, Country>).

//     Intermediate steps:
//     1. Define operator< for both Cities and Countries based on their names.
//     2. Read cities as pairs <City, name of the country>.
//     3. Use the name of the country to find if there is such country in the container.
//     4. Add a country to the container or a city to an existing country.

struct Coordinate
{
    double longitude;
    double latitude;
};

struct City
{
    std::string name;
    Coordinate coordinate;
};

struct Country
{
    std::string name;
};



void fillCountries(std::istream& inFile, std::vector<Country>& countries)
{
    std::string line;
    std::getline(inFile, line);
    while(std::getline(inFile, line))
    {
        std::stringstream sstr(line);
        
        std::string buffer;
        
        City newCity;
        double coordinateLatitude;
        
        // city,lat,lng,country,population
        
        // city
        std::getline(sstr, buffer, ',');
        
        newCity.name = buffer;

        // lat
        std::getline(sstr, buffer, ',');
        newCity.coordinate.latitude = std::stod(buffer);
        
        // lng
        std::getline(sstr, buffer, ',');
        newCity.coordinate.longitude = std::stod(buffer);
        
        // country
        std::getline(sstr, buffer, ',');
        std::string countryName = buffer;
        
        // population
        std::getline(sstr, buffer, ',');
        
        bool cityFound = false;
        for (Country& country: countries)
        {
            if (country.name == countryName)
            {
                // add the new element to the country.cities
                cityFound = true;
                break;
            }
        }
        
        if (!cityFound)
        {
            // add a new country
            // add a new element to its cities
            // countries[countries.size() - 1].cities is the container of cities
        }
        
        
//        if (std::find(countries.begin(), countries.end(), countryName) == countries.end())
//        {
            
//        }
        
    }
}

int main()
{
    const std::string FILENAME = "../../data/problem1_cities/cities.csv";
    std::ifstream inputFile;
    inputFile.open(FILENAME);
    if(inputFile)
    {
        std::cout<<"OK\n";
    }
    
    std::vector<Country> countries;
    
    fillCountries(inputFile, countries);
    
    for (const Country& country: countries)
    {
        std::cout << country.name << std::endl;
    }
    
    return 0;
}
