10 pow x == 1ex

circular array : copy array to the right

__builtin_popcount : used to count a number of 1's in an integer in its binary representation.
	
sweep line algo : O(nlogn)

__gcd(a, b) : inbuild method for finding gcd

std::set<int> s;
	std::set_union(odd.begin(), odd.end(),
				even.begin(), even.end(),
				std::inserter(s, s.begin()));


only applied in sorted array
return iterator
lower_bound (v.begin(), v.end(), x) : It uses binary function for comparision
lower_bound : first element which is not less than x
upper_bound : first element which is greater than x
binary_search(v.begin(), v.end(), x) : true/false


prefix array : partial_sum(v.begin(),v.end(),result_vector.begin());

In the questions of counting things, think about kind of some prefix sum array.


a pehle b baad me ........priority queue me baad wala top p hota hai

long long x = (ll)a * (ll)a;

initiate vector<vector<int>> of size n*m
vector<vector<int>> matrix(n, vector<int>(m, 0));

a+b = (a XOR b) + (a AND b)*2

don't forgot to remove leading zeros if returning ans in the form of string

convert to binary:
bitset<size_of_string>(n).to_string()

printing upto 2 digit after decimal 
cout << fixed << setprecision(2) << result << endl;

pow function gives wrong output sometimes 
example : pow(5,2) = 24 because it is 24.99999999
to overcome this we can add 0.5 and do typecasting
(int)(pow(5,2)+0.5)


DONT EVER TRUST LOG FUNCTION
and they are slow too.

check a double/float is an integer :
x-(int)x==0


xor :: AB`+A`B or (A+B)(A`+B`)

1<<i = 2powi

check ith bit from right is 1 or not
(n>>i==1)? true : false
i starts from 0


Floyd Algo : all pair shortest path

Delete consecutive duplicates in an array
v.resize(distance(v.begin(),unique(v.begin(),v.end())));
OR:
unique_copy(a.begin(),a.end(),b.begin());

product of three int can overflow long long

string to unsingned  ll
string x;
unsigned ll y = stoull(x,0,2);	//base 2

make_heap,push_heap,pop_heap,sort_heap,is_heap used to make vector as heap

// Priority queue syntax::
bool cmp(int a,int b){
	return a>b;
}
priority_queue<int,vector<int>,function<bool(int ,int)> pq(cmp);

class Compare{
public : //if use struct instead of class then no need of public
	bool operator()(int a , int b){
		return a>b;
	}	
};
priority_queue<int,vector<int>,Compare> pq;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 stack with while loop works as recursive function
 

 in dp of strings we have one extra column for null string
 
 position of maximum set bit from right 
 int pos = log2(x);

floor of a, b = a/b;
ceil of a,b = (a+b-1)/b;

for creating vector of unique element
sort(v.begin(),v.end());
v.erase(unique(v.begin(),v.end()),v.end());
