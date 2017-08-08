#include <unordered_map>
#include <unordered_set>

#ifndef Types_h
#define Types_h

typedef int64_t life_t;
typedef std::unordered_map< life_t, std::unordered_set<life_t> > CellSet;
typedef std::unordered_map< life_t, std::unordered_map<life_t, size_t> > CellMap;

#endif /* Types_h */
