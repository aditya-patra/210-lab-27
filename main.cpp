#include <iostream>
#include <map>
#include <tuple>
using namespace std;

// function to get menu input
int printMenu();

int main() {
    // declarations
    // store friendship level, species, catchphrase
    map<string, tuple<int, string, string>> villagerLst;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerLst["Audie"] = {9, "human", "We get it done"};
    villagerLst["Raymond"] = {10, "goblin", "Yum yum in my tum tum"};
    villagerLst.insert({"Marshal", {1, "Grinch", "Im mad"}});

    // access the map using a range-based for loop
    cout << "Villagers and their information (range-based for loop):" << endl;
    for (auto pair : villagerLst) {
        cout << pair.first << ": ";
        auto [lvl, species, phrase] = pair.second;
        cout << "Friendship Level " << lvl << " - Species " << species << " - Catchphrase " << phrase;
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerLst.begin(); 
                                               it != villagerLst.end(); ++it) {
        cout << it->first << ": ";
        auto [lvl, species, phrase] = it->second;
        cout << "Friendship Level " << lvl << " - Species " << species << " - Catchphrase " << phrase;
        cout << endl;
    }

    // delete an element
    villagerLst.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerLst.find(searchKey);
    if (it != villagerLst.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        auto [lvl, species, phrase] = it->second;
        cout << "Friendship Level " << lvl << " - Species " << species << " - Catchphrase " << phrase;
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    /*Menu-Driven Section*/

    while(true) {
        // print village
        cout << endl << endl;
        for (auto pair : villagerLst) {
            cout << pair.first << " ";
            auto [lvl, species, phrase] = pair.second;
            cout << "[" << lvl << ", " << species << ", " << phrase << "]";
            cout << endl;
        }
        // get user input
        int usrInput = printMenu();

        //increase friendship
        if (usrInput == 4) {
            break;
        }
        else if (usrInput == 1){
            string name;
            cout << "Enter villager name: ";
            cin >> name;
            int amt;
            cout << "Enter amount to increase friendship by: ";
            cin >> amt;
            get<0>(villagerLst.at(name)) += amt;
        }
        else if (usrInput == 2){
            string name;
            cout << "Enter villager name: ";
            cin >> name;
            int amt;
            cout << "Enter amount to decrease friendship by: ";
            cin >> amt;
            get<0>(villagerLst.at(name)) -= amt;
        }
        else if (usrInput == 3) {
            string name;
            cout << "Enter villager name: ";
            cin >> name;
            auto it = villagerLst.find(name);
            if (it != villagerLst.end()) {  // the iterator points to beyond the end of the map
                                            // if name is not found
                cout << "\nFound " << name << "'s favorite colors: ";
                auto [lvl, species, phrase] = it->second;
                cout << "[" << lvl << ", " << species << ", " << phrase << "]";
                cout << endl;
            } else
                cout << endl << name << " not found." << endl;
        }
        else{
            cout << "Invalid " << endl;
        }
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerLst.size() << endl;
    villagerLst.clear();
    cout << "Size after clear: " << villagerLst.size() << endl;

    return 0;
}

// function to get menu input
int printMenu(){
    int usrInput;
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;
    cin >> usrInput;
    return usrInput;
}