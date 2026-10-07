// ============================================================
// Lab No 5 (7384) - Legacy Code for SonarQube Analysis
// Example 1 + Example 2 combined
// ============================================================

#include <string>
#include <cstddef>

using std::string;

// Forward declaration
class Address;

// ============================================================
// EXAMPLE 1 - Legacy Code
// ============================================================

class Address_Example1 {
private:
    static Address_Example1* singleton;
    static void CountReference();

public:
    static Address_Example1* GetSingleton();
    static void ClearSingleton();
    char* GetCity();
};

Address_Example1* Address_Example1::singleton = NULL;

class Person_Example1 {
public:
    char* GetCityFromAddressFactory();
    bool IsValidName(string filename);
    void SaveAll(string filename);
};

// --- Example 1 Method Implementations ---

char* Person_Example1::GetCityFromAddressFactory()
{
    Address_Example1* pAddress = Address_Example1::GetSingleton();
    char* city = pAddress->GetCity();
    Address_Example1::ClearSingleton();
    return city;
}

bool Person_Example1::IsValidName(string filename)
{
    throw;
}

void Person_Example1::SaveAll(string filename)
{
    throw;
}

Address_Example1* Address_Example1::GetSingleton()
{
    if (singleton == NULL)
        singleton = new Address_Example1();
    return singleton;
}

void Address_Example1::ClearSingleton()
{
    CountReference();
    if (singleton != NULL)
    {
        delete singleton;
        singleton = NULL;
    }
}

void Address_Example1::CountReference()
{
    // placeholder - not implemented in legacy code
}

char* Address_Example1::GetCity()
{
    throw;
}

// ============================================================
// EXAMPLE 2 - Legacy Code
// ============================================================

class Address
{
private:
    static Address* singleton;
    static void CountReference();
public:
    static Address* GetSingleton();
    static void ClearSingleton();
};

Address* Address::singleton = NULL;

class Person
{
public:
    static char* GetCityFromAddressFactory();
    void Save(string filename);
private:
    bool IsValidName(string filename);
    void SaveAll(string filename);
};

// --- Example 2 Method Implementations ---

char* Person::GetCityFromAddressFactory()
{
    Address* pAddress = Address::GetSingleton();
    char* city = pAddress->GetCity();
    Address::ClearSingleton();
    return city;
}

void Person::Save(string filename)
{
    if (!IsValidName(filename))
    {
        throw;
    }
    SaveAll(filename);
}

bool Person::IsValidName(string filename)
{
    throw;
}

void Person::SaveAll(string filename)
{
    throw;
}

Address* Address::GetSingleton()
{
    if (singleton == NULL)
        singleton = new Address();
    return singleton;
}

void Address::ClearSingleton()
{
    CountReference();
    if (singleton != NULL)
    {
        delete singleton;
        singleton = NULL;
    }
}

void Address::CountReference()
{
    // placeholder
}

// ============================================================
// END OF LEGACY CODE
// ============================================================