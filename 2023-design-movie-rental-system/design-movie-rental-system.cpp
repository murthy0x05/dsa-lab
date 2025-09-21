// class MovieRentingSystem {
//     typedef long long ll;
//     static const ll factor = 100000LL;
//     struct cmp1 {
//         bool operator() (const ll& a, const ll& b) const {
//             int price1 = a % factor;
//             int price2 = b % factor;
//             if (price1 != price2) {
//                 return price1 < price2;
//             } else {
//                 return (a / factor) < (b / factor); ///
//             }
//         }
//     };
//     struct cmp2 {
//         bool operator () (const ll& a, const ll& b) const {
//             ll msp1 = a, msp2 = b;

//             int price1 = msp1 % factor;
//             int price2 = msp2 % factor;
//             if (price1 != price2) {
//                 return price1 < price2;
//             }
            
//             msp1 /= factor; msp2 /= factor;
//             int shop1 = msp1 % factor;
//             int shop2 = msp2 % factor;;
//             if (shop1 != shop2) {
//                 return shop1 < shop2;
//             }

//             msp1 /= factor; msp2 /= factor;
//             return msp1 < msp2;
//         }
//     };
//     unordered_map<int, set<ll, cmp1>> movies;
//     set<ll, cmp2> rented;
//     int n;
// public:
//     MovieRentingSystem(int n, vector<vector<int>>& entries) : n(n) {
//         for (vector<int>& entry: entries) {
//             movies[entry[1]].insert(entry[0] * factor + entry[2]);
//         }
//     }
    
//     vector<int> search(int movie) {
//         set<ll, cmp1>& shops = movies[movie];
//         vector<int> result;
        
//         int i = 0;
//         for (const ll& sp: shops) {
//             if (i < 5) {
//                 result.push_back((sp / factor));
//                 i++;
//             } else {
//                 break;
//             }
//         }

//         return result;
//     }
    
//     void rent(int shop, int movie) {
//         ll sp = *movies[movie].lower_bound(shop * factor);
//         movies[movie].erase(sp);
//         rented.insert((((movie * factor) + shop) * factor) + (sp % factor));
//     }
    
//     void drop(int shop, int movie) {
//         ll msp = *rented.lower_bound(((movie * factor) + shop) * factor);
//         rented.erase(msp);
//         int price = msp % factor;
//         movies[movie].insert(shop * factor + price);
//     }
    
//     vector<vector<int>> report() {
//         vector<vector<int>> result;
        
//         int i = 0;
//         for (const ll& ele: rented) {
//             if (i < 5) {
//                 ll msp = ele;
//                 int p = msp % factor; msp /= factor;
//                 int s = msp % factor; msp /= factor;
//                 int m = msp;
//                 result.push_back({s, m});
//                 i++;
//             } else {
//                 break;
//             }
//         }

//         return result;
//     }
// };

// /**
//  * Your MovieRentingSystem object will be instantiated and called as such:
//  * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
//  * vector<int> param_1 = obj->search(movie);
//  * obj->rent(shop,movie);
//  * obj->drop(shop,movie);
//  * vector<vector<int>> param_4 = obj->report();
//  */

class MovieRentingSystem {
    typedef long long ll;
    static const ll factor = 1000000LL;

    struct cmp1 {
        bool operator() (const ll& a, const ll& b) const {
            int price1 = a % factor;
            int price2 = b % factor;
            if (price1 != price2) return price1 < price2;
            return (a / factor) < (b / factor); // shop ascending
        }
    };

    struct cmp2 {
        bool operator() (const ll& a, const ll& b) const {
            ll msp1 = a, msp2 = b;
            int price1 = msp1 % factor;
            int price2 = msp2 % factor;
            if (price1 != price2) return price1 < price2;
            msp1 /= factor; msp2 /= factor;
            int shop1 = msp1 % factor;
            int shop2 = msp2 % factor;
            if (shop1 != shop2) return shop1 < shop2;
            msp1 /= factor; msp2 /= factor;
            return msp1 < msp2; // movie ascending
        }
    };

    unordered_map<int, set<ll, cmp1>> movies;           // movie -> unrented shops set
    unordered_map<int, unordered_map<int, ll>> movieShopMap; // movie -> shop -> encoded_value
    set<ll, cmp2> rented;                               // rented movies set
    unordered_map<int, unordered_map<int, ll>> rentedMap;    // movie -> shop -> encoded_value

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            ll encoded = shop * factor + price;
            movies[movie].insert(encoded);
            movieShopMap[movie][shop] = encoded;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        int i = 0;
        for (const ll& sp : movies[movie]) {
            if (i >= 5) break;
            result.push_back(sp / factor);
            i++;
        }
        return result;
    }

    void rent(int shop, int movie) {
        ll encoded = movieShopMap[movie][shop];
        movies[movie].erase(encoded);
        movieShopMap[movie].erase(shop);

        ll rEncoded = ((ll)movie * factor + shop) * factor + (encoded % factor);
        rented.insert(rEncoded);
        rentedMap[movie][shop] = rEncoded;
    }

    void drop(int shop, int movie) {
        ll rEncoded = rentedMap[movie][shop];
        rented.erase(rEncoded);
        rentedMap[movie].erase(shop);

        ll encoded = shop * factor + (rEncoded % factor);
        movies[movie].insert(encoded);
        movieShopMap[movie][shop] = encoded;
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int i = 0;
        for (const ll& ele : rented) {
            if (i >= 5) break;
            ll msp = ele;
            int price = msp % factor;
            msp /= factor;
            int shop = msp % factor;
            msp /= factor;
            int movie = msp;
            result.push_back({shop, movie});
            i++;
        }
        return result;
    }
};
