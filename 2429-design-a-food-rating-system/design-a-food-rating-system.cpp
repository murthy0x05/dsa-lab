class FoodRatings {
    #define pii pair<int, int>
    vector<string> foods;
    map<string, int> fi;
    vector<int> ratings;
    vector<string> cuisines;
    function<bool(const pii&, const pii&)> cmp;
    map<string, priority_queue<pii, vector<pii>, decltype(cmp)>> heaps; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) : foods(foods), ratings(ratings), cuisines(cuisines) {
        cmp = [this](const pii& a, const pii& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return this -> foods[a.second] > this -> foods[b.second];
            }
        };
        for (int i = 0, n = foods.size(); i < n; i++) {
            fi[foods[i]] = i;
            if (!heaps.count(cuisines[i])) {
                heaps[cuisines[i]] = priority_queue<pii, vector<pii>, function<bool(const pii&, const pii&)>>(cmp);
            }
            heaps[cuisines[i]].push(make_pair(ratings[i], i));
        }
    }
    
    void changeRating(string food, int newRating) {
        ratings[fi[food]] = newRating;
        heaps[cuisines[fi[food]]].push({newRating, fi[food]});
    }
    
    string highestRated(string cuisine) {
        while (!heaps[cuisine].empty()) {
            pii rating = heaps[cuisine].top();
            if (rating.first != ratings[rating.second]) {
                heaps[cuisine].pop();
            } else {
                return foods[rating.second];
            }
        }

        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */