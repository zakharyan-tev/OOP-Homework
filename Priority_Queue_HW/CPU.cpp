#include <iostream>
#include <queue>
#include <string>

struct Task {
    int time;
    int priority;
    std::string name;

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

class CPU {
private:
    std::priority_queue<Task> pq;

public:
    void add(const Task& task) {
        pq.push(task);
    }

    Task run() {
        if (pq.empty()) throw std::runtime_error("No tasks to run");
        Task t = pq.top();
        pq.pop();
        return t;
    }

    bool empty() const {
        return pq.empty();
    }
};

int main() {
    CPU cpu;
    cpu.add({3, 10, "taskA"});
    cpu.add({1, 5, "taskB"});
    cpu.add({2, 7, "taskC"});

    auto next = cpu.run();
    std::cout << "{ priority = " << next.priority
              << ", time = " << next.time
              << ", name = \"" << next.name << "\" }\n";

    return 0;
}
