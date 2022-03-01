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
    
    bool operator <(const City &b) const
    {
        return name < b.name;
    }
};

struct Country
{
    std::string name;
    std::set<City> cities;
};


std::pair<City, std::string>  parseLine(const std::string& line)
{
    std::stringstream sstr(line);
    
    std::string buffer;
    
    City newCity;
    
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
    
    return std::make_pair(newCity, countryName);
}


void fillCountries(std::istream& inFile, std::vector<Country>& countries)
{
    std::string line;
    std::getline(inFile, line);
    while(std::getline(inFile, line))
    {
        std::pair<City, std::string> data = parseLine(line);
        
        
        bool cityFound = false;
        for (Country& country: countries)
        {
            if (country.name == data.second)
            {
                // add the new element to the country.cities
                country.cities.insert(data.first);
                cityFound = true;
                break;
            }
        }
        
        if (!cityFound)
        {
            
            // 1) Make a new country object
            // 2) Change its name and add the current city to it
            // 3) Add the country object to the vector
            Country newCountry;
            newCountry.name = data.second;
            newCountry.cities.insert(data.first);
            countries.push_back(newCountry);
           
            
        }
        
        
//        if (std::find(countries.begin(), countries.end(), countryName) == countries.end())
//        {
            
//        }
        
    }
}

std::ostream& operator <<(std::ostream& out, const City& city)
{
    out << 1;
    
    return out;
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
    City city;
    std::cout << city;
    
    std::vector<Country> countries;
    
    fillCountries(inputFile, countries);
    
    for (const Country& country: countries)
    {
        std::cout << country.name << std::endl;
    }
    
    return 0;
}
