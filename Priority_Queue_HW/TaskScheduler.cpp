#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Task {
    int priority;
    std::string name;
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

class TaskScheduler {
private:
    std::priority_queue<Task> pq;

public:
    void add(const Task& task) {
        pq.push(task);
    }

    Task next() {
        if (pq.empty()) throw std::runtime_error("No tasks available");
        Task t = pq.top();
        pq.pop();
        return t;
    }

    bool empty() const {
        return pq.empty();
    }
};

int main() {
    TaskScheduler ts;
    ts.add({5, "compile"});
    ts.add({10, "fix bug"});
    ts.add({7, "build"});

    auto t = ts.next();
    std::cout << t.name << ", priority " << t.priority << "\n";

    return 0;
}
