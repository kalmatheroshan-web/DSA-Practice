#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // ---------------- MAP ----------------
    map<string, int> m; // Sorted by key

    // Insert
    m["Raj"] = 28;
    m["Boka"] = 90;
    m["Raj"] = 228; // Update value

    m.insert({"Roshan", 30});
    m.emplace("Alice", 50);

    cout << "Map:\n";
    for (auto p : m)
        cout << p.first << " " << p.second << endl;

    // Access
    cout << "\nRaj = " << m["Raj"] << endl;

    // at()
    cout << "Alice = " << m.at("Alice") << endl;

    // Find
    auto it = m.find("Boka");
    if (it != m.end())
        cout << "Found: " << it->first << " " << it->second << endl;

    // Count (0 or 1)
    cout << "Count(Raj): " << m.count("Raj") << endl;

    // Size
    cout << "Size: " << m.size() << endl;

    // Empty
    cout << "Empty: " << m.empty() << endl;

    // First & Last element
    cout << "First: " << m.begin()->first << endl;
    cout << "Last: " << prev(m.end())->first << endl;

    // lower_bound()
    auto lb = m.lower_bound("Raj");
    if (lb != m.end())
        cout << "Lower bound: " << lb->first << endl;

    // upper_bound()
    auto ub = m.upper_bound("Raj");
    if (ub != m.end())
        cout << "Upper bound: " << ub->first << endl;

    // Erase by key
    m.erase("Boka");

    // Erase by iterator
    if (!m.empty())
        m.erase(m.begin());

    cout << "\nAfter erase:\n";
    for (auto p : m)
        cout << p.first << " " << p.second << endl;

    // Swap
    map<string, int> m2;
    m2["Test"] = 100;

    m.swap(m2);

    cout << "\nAfter swap:\n";
    for (auto p : m)
        cout << p.first << " " << p.second << endl;

    // Clear
    m.clear();
    cout << "Size after clear: " << m.size() << endl;

    // ---------------- UNORDERED MAP ----------------
    unordered_map<int, string> um; // No sorting

    um[1] = "Roshan";
    um[2] = "Raj";
    um.emplace(3, "Alice");

    cout << "\nUnordered Map:\n";
    for (auto p : um)
        cout << p.first << " " << p.second << endl;

    if (um.find(2) != um.end())
        cout << "Found key 2\n";

    um.erase(1);

    cout << "Size: " << um.size() << endl;

    // ---------------- MULTIMAP ----------------
    multimap<string, int> mm; // Duplicate keys allowed

    mm.insert({"Roshan", 10});
    mm.insert({"Roshan", 20});
    mm.emplace("Raj", 30);
    mm.emplace("Raj", 40);

    cout << "\nMultimap:\n";
    for (auto p : mm)
        cout << p.first << " " << p.second << endl;

    // Count duplicate keys
    cout << "Count(Raj): " << mm.count("Raj") << endl;

    // Find first occurrence
    auto itr = mm.find("Raj");
    if (itr != mm.end())
        cout << "First Raj: " << itr->second << endl;

    // Equal range
    cout << "All Raj values:\n";
    auto range = mm.equal_range("Raj");
    for (auto i = range.first; i != range.second; i++)
        cout << i->first << " " << i->second << endl;

    // Erase all duplicate keys
    mm.erase("Raj");

    cout << "\nAfter erase:\n";
    for (auto p : mm)
        cout << p.first << " " << p.second << endl;

    return 0;
}