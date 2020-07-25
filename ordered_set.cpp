#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

/*
find_by_order(x) = find the index of a number x in log n time
order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
*/
