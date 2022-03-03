#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

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
    int population;
    
    bool operator <(const City& rhs) const
    {
        return name < rhs.name;
    }
    
//    City(const std::string& inputName, double lat, double lon) 
//    {
//        name = inputName;
//        coordinate.latitude = lat;
//        coordinate.longitude = lon;
//        this->population = 0;
//        std::cout << "constructor";
//    }
    
    City(const std::string& inputName, double lat, double lon)
        : name(inputName), population(0)
    {

    }
    
    City () {}
    
};

struct Country
{
    
private:
    std::set<City> cities;
    
public:
    std::string name;
    void addCity(const City& city)
    {
        cities.insert(city);
    }
    
    const std::set<City>& getCities() const
    {
        return cities;
    }
};



void fillCountries(std::istream& inFile, std::vector<Country>& countries)
{
    std::string line;
    // skip header
    std::getline(inFile, line);
    
    while (std::getline(inFile, line))
    {
        std::stringstream sstr(line);
        std::string buffer;
        
        // city,lat,lng,country,population
        
        
        // city name
        std::getline(sstr, buffer, ',');
        std::string name = buffer;

        
        
        
        // latitude
        std::getline(sstr, buffer, ',');
        double latitude = std::stod(buffer);

        // longitude
        std::getline(sstr, buffer, ',');
        
        double longitude = std::stod(buffer);

        // country name
        std::getline(sstr, buffer, ',');
        std::string countryName = buffer;
        
        // population
        std::getline(sstr, buffer, ',');
        int population = std::stoi(buffer);
        
        
        City newCity(name, latitude, longitude);
        
        
        City city2;
        
        bool cityFound = false;
        for (Country& country: countries)
        {
            if (country.name == countryName)
            {
                cityFound = true;
//                country.cities.insert(newCity);
//                country.cities.clear();
                country.addCity(newCity);
                break;
            }
        }
                
        if (!cityFound)
        {
            
            Country country;
            country.name = countryName;
            country.addCity(newCity);
            countries.push_back(country);
            // 1. make a new country
            // 2. Change its name. Add the city to the new country
            // 3. Add the new country to the vector
        }
        
        
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
    City cityA;
    City cityB;
    
    if (cityA < cityB)
    {
        
    }
    std::cout << cityA;
    std::vector<Country> countries;
    fillCountries(inputFile, countries);
    
    for (const Country& country: countries)
    {
        std::cout << country.name << std::endl;
        for (const City& city: country.getCities())
        {
            std::cout << city << std::endl;
        }
    }
    
    return 0;
}
