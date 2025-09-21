class MovieRentingSystem {
    typedef long long ll;
    static const ll factor = 1000000LL;
    unordered_map<int, set<ll>> movies;
    unordered_map<int, unordered_map<int, int>> msp;
    set<ll> rented;
    int n;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) : n(n) {
        for (vector<int>& entry: entries) {
            movies[entry[1]].insert(entry[2] * factor + entry[0]);
            msp[entry[1]][entry[0]] = entry[2];
        }
    }
    
    vector<int> search(int movie) {
        set<ll>& shops = movies[movie];
        vector<int> result;
        
        int i = 0;
        for (const ll& ps: shops) {
            if (i < 5) {
                result.push_back((ps % factor));
                i++;
            } else {
                break;
            }
        }

        return result;
    }
    
    void rent(int shop, int movie) {
        int price = msp[movie][shop];
        movies[movie].erase(price * factor + shop);
        rented.insert((((price * factor) + shop) * factor) + movie);
    }
    
    void drop(int shop, int movie) {
        int price = msp[movie][shop];
        rented.erase((((price * factor) + shop) * factor) + movie);
        movies[movie].insert(price * factor + shop);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        
        int i = 0;
        for (const ll& ele: rented) {
            if (i < 5) {
                ll msp = ele;
                int m = msp % factor; msp /= factor;
                int s = msp % factor; msp /= factor;
                int p = msp;
                result.push_back({s, m});
                i++;
            } else {
                break;
            }
        }

        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */