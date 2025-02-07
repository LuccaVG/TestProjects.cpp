#include <iostream>
#include <unordered_map>
#include <string>
#include <optional>

// Define a struct to represent an item in the warehouse
struct Item {
    std::string name;
    int quantity;
};

class StorageSystem {
public:
    // Insert an item into the storage system
    void insert(const std::string& itemId, const Item& item) {
        storage[itemId] = item;
    }

    // Retrieve an item by item ID from the storage system
    std::optional<Item> retrieve(const std::string& itemId) const {
        auto it = storage.find(itemId);
        if (it != storage.end()) {
            return it->second;
        } else {
            return std::nullopt;
        }
    }

    // Delete an item from the storage system
    bool remove(const std::string& itemId) {
        return storage.erase(itemId) > 0;
    }

    // Print all items in the storage system
    void printAll() const {
        if (storage.empty()) {
            std::cout << "No items in the warehouse.\n";
            return;
        }
        for (const auto& pair : storage) {
            std::cout << "Item ID: " << pair.first << "\n"
                      << "Name: " << pair.second.name << "\n"
                      << "Quantity: " << pair.second.quantity << "\n"
                      << std::endl;
        }
    }

private:
    std::unordered_map<std::string, Item> storage;
};

void displayMenu() {
    std::cout << "\nWarehouse Storage System\n";
    std::cout << "1. Add item\n";
    std::cout << "2. Remove item\n";
    std::cout << "3. List all items\n";
    std::cout << "4. Exit\n";
    std::cout << "Select an option: ";
}

int getValidChoice() {
    std::string input;
    int choice;
    while (true) {
        std::getline(std::cin, input);
        try {
            choice = std::stoi(input);
            if (choice >= 1 && choice <= 4) {
                break;
            } else {
                std::cout << "Invalid input. Please enter a number between 1 and 4: ";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
        }
    }
    return choice;
}

int getValidQuantity() {
    std::string input;
    int quantity;
    while (true) {
        std::getline(std::cin, input);
        try {
            quantity = std::stoi(input);
            if (quantity >= 0) {
                break;
            } else {
                std::cout << "Invalid input. Please enter a non-negative integer for quantity: ";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a non-negative integer for quantity: ";
        }
    }
    return quantity;
}

int main() {
    StorageSystem warehouse;
    int choice;

    while (true) {
        displayMenu();
        choice = getValidChoice();

        if (choice == 1) {
            std::string itemId, name;
            int quantity;
            std::cout << "Enter item ID: ";
            std::getline(std::cin, itemId);
            std::cout << "Enter item name: ";
            std::getline(std::cin, name);
            std::cout << "Enter item quantity: ";
            quantity = getValidQuantity();
            warehouse.insert(itemId, {name, quantity});
            std::cout << "Item added successfully.\n";
        } else if (choice == 2) {
            std::string itemId;
            std::cout << "Enter item ID to remove: ";
            std::getline(std::cin, itemId);
            if (warehouse.remove(itemId)) {
                std::cout << "Item removed successfully.\n";
            } else {
                std::cout << "Item not found.\n";
            }
        } else if (choice == 3) {
            warehouse.printAll();
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
