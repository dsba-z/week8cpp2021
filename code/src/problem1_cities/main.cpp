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
    int population;
    Coordinate coordinate;
    
    bool operator<(const City& rhs) const
    {
         return name < rhs.name;
    }
    
    City(std::string name, double lat, double lon, int population)
    {
        this->name = "default name";
        population = 0;
        coordinate.latitude = 0;
        coordinate.longitude = 0;
    }
//    City () {
        
//    }
    
};

struct Country
{
    std::string name;
private:
    
    std::set<City> cities;

public:
    
    bool operator==(const std::string& rhs)
    {
         return name == rhs;
    }
    
    void addNewCity(const City& city)
    {
        
    }
    
    int getNumberOfCities() const
    {
        return cities.size();
    }
    
};



void fillCountries(std::istream& inFile, std::vector<Country>& countries)
{
    std::string line;
    std::getline(inFile, line);
    while (std::getline(inFile, line))
    {
        std::string buffer;
        std::stringstream sstr(line);
        
        // city,lat,lng,country,population
//        City newCity;
        
        // city name
        std::getline(sstr, buffer, ',');
        std::string name = buffer;
        
        // lat
        std::getline(sstr, buffer, ',');
        double latitude = std::stod(buffer);
        
        
        // lng
        std::getline(sstr, buffer, ',');
        double longitude = std::stod(buffer);
        
        
        // country
        std::getline(sstr, buffer, ',');
        std::string countryName = buffer;
        
        
        // population
        std::getline(sstr, buffer, ',');
        int population = std::stoi(buffer);
        
        
        
        
        City newCity(name, latitude, longitude, population);
        
        std::pair<City, std::string> b({newCity, "123"});
        
        std::pair<City, std::string> a = std::make_pair(newCity, "213");
        
        bool cityFound = false;
        for (Country& country: countries)
        {
            if (country.name == countryName)
            {
                cityFound = true;
                country.cities.insert(newCity);
                // add city to country
                break;
            }
        }
                
        if (!cityFound)
        {
            Country country;
            
            // fill the country
            
            // name
            country.name = countryName;
            
            // vector (add current city)
            country.cities.insert(newCity);
            
            countries.push_back(country);
            // 1. make a new country
            // 2. Change its name. Add the city to the new country
            // 3. Add the new country to the vector
        }
        
        
//        if (std::find(countries.begin(), countries.end(), countryName) == countries.end())
//        {
//            // no such country
//            Country country;
            
//            // fill the country
            
//            // name
//            country.name = countryName;
            
//            // vector (add current city)
//            country.cities.push_back(newCity);
            
//            countries.push_back(country);
//        }
//        else
//        {
//            // there is such country
//            std::vector<Country>::iterator it = std::find(countries.begin(), countries.end(), countryName);
            
//            // use iterator "it" to modify the country
//            // add the new city to it
//            it->cities.push_back(newCity);
//        }
    }
}
// 1. fill the vector of Countries (you can use the code from GitHub)
// 2. Overload operator << for Cities (the function below this comment)
// 3. Change operator < for Cities to compare them by population (larger first)
// 4. Move data reading code from fillCountries to a separate function

std::ostream& operator <<(std::ostream& out, const City& city)
{
    out << 1;
    out << city.name;
    return out;
}

int main()
{
    const std::string FILENAME = "../../data/problem1_cities/cities.csv";
    std::ifstream inputFile;
    inputFile.open(FILENAME);
    
    std::vector<Country> countries;
    
    if(inputFile)
    {
        std::cout<<"OK\n";
        
        fillCountries(inputFile, countries);
        
    }
    
    for (const Country& country: countries)
    {
        std::cout << country.name << std::endl;
        std::cout << country.getNumberOfCities();
    }
    
    return 0;
}
