#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

// O(1) pointer for the median
// O(n log n) for auto sort the input arr

template<Typename T>
class MedianMaintainer{
    public:
	void insert(const T & value){
	    data.insert(value);
	    if(data.size() == 1){
		median_iter = data.begin();
	    }else if(value < *median_iter){
		if(data.size() % 2 == 0){
		    --median_iter;
		}
	    }else{
		if(data.size() % 2 == 1){
		    ++median_iter;
		}
	    }
	}
	
	void erase(const T & value){
	    if(data.empty()) return;

	    if(value <= *median_iter){
		if(data.size() % 2 == 0) ++median_iter;
	    }else{
		if(data.size() % 2 != 0) --median_iter;
	    }
	    data.erase(data.find(value));
	}

	int getMedian() const {
	    if(data.empty()) throw length_error("empty data");
	    if(data.size() % 2 == 0){
		return *next(median_iter);
	    }
	    return *median_iter;
	}
    private:
	multiset<T> data;
	typename multiset<T>::iterator median_iter;
};


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    MedianMaintainer<int> ms;
    // utils?
    // 1. For a n data -> need sort and check O(n log n)
    // 2. If the data change dynamically, we can do that operation on O(log n)
    // 3. Always median O(1)
    return 0;
}

