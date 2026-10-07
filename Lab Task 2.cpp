#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

namespace AddressBook {

class Address {
private:
    static std::unique_ptr<Address> singleton;

    Address() = default;
    static void CountReference() { /* reference counting placeholder */ }

public:
    Address(const Address&) = delete;
    Address& operator=(const Address&) = delete;

    static Address& GetSingleton() {
        if (!singleton) {
            singleton = std::make_unique<Address>();
        }
        return *singleton;
    }

    static void ClearSingleton() {
        if (singleton) {
            singleton.reset();
        }
    }
};

std::unique_ptr<Address> Address::singleton = nullptr;

class Person {
public:
    static std::string GetCityFromAddressFactory() {
        Address& pAddress = Address::GetSingleton();
        std::string city = "SampleCity";        // placeholder
        Address::ClearSingleton();
        return city;
    }

    void Save(const std::string& filename) const {
        if (!IsValidName(filename)) {
            throw std::invalid_argument("Invalid filename");
        }
        SaveAll(filename);
    }

private:
    bool IsValidName(const std::string& filename) const {
        return !filename.empty();
    }

    void SaveAll(const std::string& filename) const {
        std::cout << "Saving to " << filename << '\n';
    }
};

} // namespace AddressBook

int main() {
    using namespace AddressBook;

    Person person;
    try {
        std::string city = Person::GetCityFromAddressFactory();
        std::cout << "City: " << city << '\n';
        person.Save("example.txt");
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}