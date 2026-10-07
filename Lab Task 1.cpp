#include <memory>
#include <string>
#include <stdexcept>

namespace AddressBook {

class Address {
private:
    static std::unique_ptr<Address> singleton;
    Address() = default;                       // prevent external construction

public:
    Address(const Address&) = delete;          // non-copyable
    Address& operator=(const Address&) = delete;

    static Address& GetSingleton() {
        if (!singleton) {
            singleton = std::make_unique<Address>();
        }
        return *singleton;
    }

    static void ClearSingleton() {
        singleton.reset();
    }

    std::string GetCity() const {
        throw std::runtime_error("GetCity not implemented");
    }
};

std::unique_ptr<Address> Address::singleton = nullptr;

class Person {
public:
    std::string GetCityFromAddressFactory() const {
        Address& address = Address::GetSingleton();
        std::string city = address.GetCity();
        Address::ClearSingleton();
        return city;
    }

    bool IsValidName(const std::string& filename) const {
        if (filename.empty()) {
            throw std::invalid_argument("Filename must not be empty");
        }
        return true;
    }

    void SaveAll(const std::string& filename) const {
        throw std::runtime_error("SaveAll not implemented");
    }
};

} // namespace AddressBook