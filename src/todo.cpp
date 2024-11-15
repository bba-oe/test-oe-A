
#include <iostream>
#include <string>


const int MAX_SIZE = 100;  // Maximum number of items in the list
std::string todolist[MAX_SIZE];  // Array to store strings	
int currentSize = 0;  // Current number of items in the array


// Function to add an item to the list
bool addItem(const std::string& item) {
	
    if (currentSize < MAX_SIZE) {
        todolist[currentSize++] = item;  // Add item and increment size
        return true;
    }
    return false;  // Array is full
}

// Function to remove an item from the list
bool removeItem(const std::string& item) {
	
    for (int i = 0; i < currentSize; i++) {
        if (todolist[i] == item) {
			
            // Shift elements left to remove the item
            for (int j = i; j < currentSize - 1; j++) {
                todolist[j] = todolist[j + 1];
            }
            currentSize--;  // Decrease the size
            return true;
        }
    }
    return false;  // Item not found
}

// Function to print the list
void printList() {
	
	std::cout << "---------------\n";
    std::cout << "Stored strings:\n";
	std::cout << "---------------\n";
	
    for (int i = 0; i < currentSize; i++) {
        std::cout << todolist[i] << std::endl;
    }
}

int main() {

    // Add items to the list
    addItem("Buy milk");
    addItem("Create a git repo");
    addItem("Test your code");

    // Print list after adding items
    printList();

    // Remove an item and print updated list
    removeItem("Create a git repo");

    printList();
	
    removeItem("Test your code");
	removeItem("Buy milk");

	printList();

    return 0;
}
