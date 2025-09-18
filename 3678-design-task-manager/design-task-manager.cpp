#pragma GCC optimize("O3,unroll-loops,Ofast")

class TaskManager {
    #define pii pair<int, int>
    struct cmp {
        bool operator()(const pii& a, const pii& b) const {
            if (a.second != b.second) {
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        }
    };
    unordered_map<int, vector<int>> tasks;
    set<pii, cmp> s;
public:
    inline TaskManager(vector<vector<int>>& t) {
        int n = t.size();
        
        for (vector<int>& task: t) {
            tasks[task[1]] = {task[0], task[2]};
            s.insert(make_pair(task[1], task[2]));
        }
    }
    
    inline void add(int userId, int taskId, int priority) {
        tasks[taskId] = {userId, priority};
        s.insert({taskId, priority});
    }
    
    inline void edit(int taskId, int newPriority) {
        s.erase({taskId, tasks[taskId][1]});
        tasks[taskId][1] = newPriority;
        s.insert({taskId, newPriority});
    }
    
    inline void rmv(int taskId) {
        s.erase({taskId, tasks[taskId][1]});
        tasks[taskId] = {-1, -1};
    }
    
    inline int execTop() {
        if (s.size()) {
            int uid = tasks[(*s.begin()).first][0];
            s.erase(s.begin());
            return uid;
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */