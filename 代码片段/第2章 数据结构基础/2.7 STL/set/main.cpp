set<int> s;
struct rec{...}; set<rec> s;
multiset<double> s;

if ((it = s.find(x)) != s.end()) s.erase(it);