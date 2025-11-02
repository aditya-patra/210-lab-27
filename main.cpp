#include <iostream>
#include <map>
#include <vector>
using namespace std;

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

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerLst.size() << endl;
    villagerLst.clear();
    cout << "Size after clear: " << villagerLst.size() << endl;

    return 0;
}
