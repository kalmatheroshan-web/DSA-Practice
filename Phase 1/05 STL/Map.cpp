#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{

    // O(logn)
    map<string, int> m;
    // key will be sorted order
    m["raj"] = 28;
    m["boka"] = 90;
    m["raj"] = 228;

    for (auto ele : m)
        cout << ele.first << " " << ele.second << endl;
    cout << endl;

    m.emplace("roshan", 30); // insert if doesn't exist

    // m.erase(); // m.erase(key);
    // m.erase(); // m.earse(m.begin() , m.end());

    for (auto ele : m)
        cout << ele.first << " " << ele.second << endl;

    auto itr = m.find("raj");
    cout << itr->first << " & " << itr->second << endl;

    m.clear();
    if (m.empty())
        cout << "it's empty" << endl;

    cout << "size " << m.size() << endl;

    unordered_map<int, string> un_m;
    un_m[1] = "Roshan";
    un_m[2] = "Zlamat";

    for (auto ele : un_m)
        cout << ele.first << " " << ele.second << endl;

    multimap<string, int> mmap;
    mmap.insert(make_pair("Roshan", 12));
    mmap.insert(make_pair("Roshan", 212));
    
    mmap.emplace(make_pair("Moshan", 12));
    mmap.emplace(make_pair("Moshan", 212));

    for (auto val : mmap)
        cout << val.first << " " << val.second << endl;

    return 0;
}