#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <numeric>

using namespace std;

struct Interval
{
    int start, end;
};
struct Event
{
    int time, type;
}; // type: 0 for end, 1 for start

int main()
{
    // =========================================================================
    // SECTION 1: BASIC LAMBDAS
    // =========================================================================
    cout << "--- Basic Lambdas ---\n";

    // 1. Hello World
    auto hello = []()
    { cout << "Hello World\n"; };
    hello();

    // 2. With Arguments
    auto greet = [](string name)
    { cout << "Hello, " << name << "\n"; };
    greet("Alice");

    // 3. With Return Type (Explicit via trailing return type)
    auto add = [](int a, int b) -> int
    { return a + b; };
    cout << "3. Add: " << add(5, 3) << "\n";

    // 4. Without Return Type (Implicit deduction)
    auto multiply = [](int a, int b)
    { return a * b; };
    cout << "4. Multiply: " << multiply(4, 3) << "\n";

    // 5. Generic Lambda (C++14 'auto' parameters)
    auto print_generic = [](auto x)
    { cout << "5. Generic: " << x << "\n"; };
    print_generic(100);
    print_generic("C++ Rocks");

    // =========================================================================
    // SECTION 2: CAPTURE LIST
    // =========================================================================
    cout << "\n--- Capture List ---\n";
    int x = 10, y = 20;

    // 6. No Capture []
    auto no_capture = []()
    { return 0; };

    // 7. Capture by Value [=] (Creates a read-only snapshot copy)
    auto cap_by_value = [=]()
    { cout << "7. Capture value of x: " << x << "\n"; };
    cap_by_value();

    // 8. Capture by Reference [&] (Can modify original variables)
    auto cap_by_ref = [&]()
    { x += 5; };
    cap_by_ref();
    cout << "8. x after reference capture modification: " << x << "\n";

    // 9. Capture Specific Variable by value
    auto cap_specific_val = [y]()
    { cout << "9. Captured specific y: " << y << "\n"; };
    cap_specific_val();

    // 10. Capture Specific Reference
    auto cap_specific_ref = [&y]()
    { y += 10; };
    cap_specific_ref();
    cout << "10. y after specific reference capture: " << y << "\n";

    // 11. Mixed Capture (Capture everything by value, except y by reference)
    auto mixed_cap = [=, &y]()
    { y += x; };
    mixed_cap();

    // 12. Mutable Lambda (Allows modifying variables captured by value inside lambda scope)
    int val = 50;
    auto mutable_lam = [val]() mutable
    {
        val += 10;
        cout << "12. Inside mutable lambda: " << val << "\n";
    };
    mutable_lam();
    cout << "    Outside mutable lambda (original unchanged): " << val << "\n";

    // 13. Capture Expression / Generalized Capture (C++14 initialization inside capture)
    auto cap_expr = [z = x + y]()
    { cout << "13. Initialized z inside capture: " << z << "\n"; };
    cap_expr();

    // =========================================================================
    // SECTION 3: LAMBDA APPLICATIONS (STL & ALGORITHMS)
    // =========================================================================
    cout << "\n--- Lambda Applications ---\n";
    vector<int> vec = {4, 1, 3, 5, 2, 3};

    // 14. Immediately Invoked Lambda Expression (IIFE)
    int temporary_sum = [](int a, int b)
    { return a + b; }(15, 25);
    cout << "14. IIFE Sum: " << temporary_sum << "\n";

    // 15. sort() with custom descending order
    sort(vec.begin(), vec.end(), [](int a, int b)
         { return a > b; });

    // 16. sort(pair)
    vector<pair<int, int>> pairs = {{1, 5}, {2, 3}, {1, 2}};
    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first; });

    // 17. stable_sort() (Preserves relative order of equivalents)
    stable_sort(vec.begin(), vec.end(), [](int a, int b)
                { return a < b; });

    // 18. priority_queue Comparator (Max heap based on element value)
    auto pq_comp = [](int a, int b)
    { return a < b; };
    priority_queue<int, vector<int>, decltype(pq_comp)> pq(pq_comp);

    // 19. set Comparator
    auto set_comp = [](int a, int b)
    { return a > b; };
    set<int, decltype(set_comp)> custom_set(set_comp);

    // 20. map Comparator
    auto map_comp = [](int a, int b)
    { return a > b; };
    map<int, string, decltype(map_comp)> custom_map(map_comp);

    // 21. for_each()
    cout << "21. for_each layout: ";
    for_each(vec.begin(), vec.end(), [](int element)
             { cout << element << " "; });
    cout << "\n";

    // 22. count_if()
    int odds = count_if(vec.begin(), vec.end(), [](int n)
                        { return n % 2 != 0; });
    cout << "22. Odds count: " << odds << "\n";

    // 23. find_if()
    auto it = find_if(vec.begin(), vec.end(), [](int n)
                      { return n > 3; });
    if (it != vec.end())
        cout << "23. First element > 3: " << *it << "\n";

    // 24. remove_if() (Combined with erase for erase-remove idiom)
    vec.erase(remove_if(vec.begin(), vec.end(), [](int n)
                        { return n == 3; }),
              vec.end());

    // 25. transform() (Squaring numbers in place)
    transform(vec.begin(), vec.end(), vec.begin(), [](int n)
              { return n * n; });

    // 26. all_of()
    bool all_positive = all_of(vec.begin(), vec.end(), [](int n)
                               { return n > 0; });

    // 27. any_of()
    bool any_greater_than_20 = any_of(vec.begin(), vec.end(), [](int n)
                                      { return n > 20; });

    // 28. none_of()
    bool none_negative = none_of(vec.begin(), vec.end(), [](int n)
                                 { return n < 0; });

    // 29. partition() (Moves elements satisfying lambda to the front)
    partition(vec.begin(), vec.end(), [](int n)
              { return n % 2 == 0; });

    // 30. nth_element() (Finds the 2nd smallest element and partitions around it)
    nth_element(vec.begin(), vec.begin() + 1, vec.end(), [](int a, int b)
                { return a < b; });

    // =========================================================================
    // SECTION 4: ADVANCED LAMBDAS
    // =========================================================================
    cout << "\n--- Advanced Lambdas ---\n";

    // 31. Recursive Lambda (Using std::function to allow reference calling itself)
    function<int(int)> factorial = [&](int n) -> int
    {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    };
    cout << "31. Factorial(5): " << factorial(5) << "\n";

    // 32. Lambda Returning Another Lambda
    auto make_multiplier = [](int factor)
    {
        return [factor](int value)
        { return value * factor; };
    };
    auto triple = make_multiplier(3);
    cout << "32. Lambda returning lambda result: " << triple(10) << "\n";

    // 33. Store Lambda in a variable
    auto stored_lambda = [](int val)
    { return val * 2; };

    // 34. Pass Lambda as Function Parameter
    auto execute_callback = [](const function<void()> &cb)
    { cb(); };
    execute_callback([]()
                     { cout << "34. Callback executed successfully!\n"; });

    // 35. Return Lambda from Function (Demonstrated using auto keyword)
    auto get_printer = []()
    {
        return [](string msg)
        { cout << "35. " << msg << "\n"; };
    };
    get_printer()("Printed from returned lambda");

    // 36. std::function object polymorphic wrappers with Lambda
    function<int(int, int)> operation = [](int a, int b)
    { return a - b; };
    cout << "36. std::function: " << operation(20, 8) << "\n";

    // =========================================================================
    // SECTION 5: COMPETITIVE PROGRAMMING SCENARIOS
    // =========================================================================
    cout << "\n--- Competitive Programming ---\n";

    // 37. Frequency Sort
    map<int, int> freq = {{5, 3}, {2, 1}, {8, 2}}; // element -> frequency
    vector<int> elements = {5, 2, 8};
    sort(elements.begin(), elements.end(), [&freq](int a, int b)
         {
             return freq[a] < freq[b]; // Sorts elements ascending by their mapped frequency
         });

    // 38. Interval Sorting (Sort by ending time, common for greedy scheduling)
    vector<Interval> intervals = {{1, 4}, {2, 3}, {4, 6}};
    sort(intervals.begin(), intervals.end(), [](const Interval &i1, const Interval &i2)
         { return i1.end < i2.end; });

    // 39. Greedy Comparator (E.g., Largest Number generation from strings)
    vector<string> nums = {"3", "30", "34", "5", "9"};
    sort(nums.begin(), nums.end(), [](const string &a, const string &b)
         {
             return a + b > b + a; // Greedily combines string representations
         });

    // 40. Custom Binary Search Predicate (Simulating find first true condition)
    vector<int> space = {1, 2, 4, 8, 16};
    auto is_possible = [](int target)
    { return target >= 5; };
    auto low = lower_bound(space.begin(), space.end(), true, [&](int elem, bool target_val)
                           { return !is_possible(elem); });

    // 41. Dijkstra Comparator for minimum-distance priority queues
    vector<int> dist = {0, 10, 5, 20}; // Node indexing -> current tentative shortest path
    auto dijkstra_comp = [&dist](int node1, int node2)
    {
        return dist[node1] > dist[node2]; // Min-heap behavior based on distance array state
    };
    priority_queue<int, vector<int>, decltype(dijkstra_comp)> dijkstra_pq(dijkstra_comp);

    // 42. Event Sorting (Sweepline algorithms processing events chronologically)
    vector<Event> events = {{10, 1}, {15, 0}, {10, 0}};
    sort(events.begin(), events.end(), [](const Event &e1, const Event &e2)
         {
        if (e1.time == e2.time) return e1.type < e2.type; // Process terminations before starts if times match
        return e1.time < e2.time; });
    cout << "42. Events successfully sorted using Sweepline order rules.\n";

    return 0;
}