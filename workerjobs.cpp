#include <iostream>
#include <queue>
#include <vector>
//#include <functional> to use std::greater
using namespace std;

struct Node {
    int number;
    int job;
    int worker;
    int lowerbound;
    struct Node* parent;
    Node(int j, int w, int lb, Node* p, int n): job(j), worker(w), lowerbound(lb), parent(p), number(n) {}
};  

struct functor {
    bool operator()(const Node* a, const Node* b) const {
        // b is second, a is first
        // return b->lowerbound < a->lowerbound;
        if(b->lowerbound == a->lowerbound) {
            if(b->worker == a->worker)
                return b->number < a->number; // same level, expand one which was gen first
            else 
                return b->worker > a->worker; // deeper in the tree
        }
        else 
            return b->lowerbound < a->lowerbound; // expand one which has better lb
    }
};

int findLowerBound(vector<vector<int> >& costs, int start) {
    int sum=0;
    int n=costs.size();
    int min;
    for(int i=start+1; i<n; i++) {
        min=__INT_MAX__;
        for(int j=0; j<n; j++) {
            if(costs[i][j] < min) 
                min = costs[i][j];
        }
        sum+=min;
    }
    return sum;
}

int getPathCost(Node* E, vector<vector<int> >& costs) {
    if(E->parent == nullptr)
        return 0;
    return getPathCost(E->parent, costs)+costs[E->worker][E->job];
}

bool hasAssigned(int j, Node* E) {
    if(E->parent == nullptr)
        return false;
    if(j == E->job || hasAssigned(j, E->parent))
        return true;
    return false;
}

void print(Node* E) {
    if(E->parent == nullptr)
        return;
    print(E->parent);
    cout<<"worker "<<E->worker<<" -> "<<"job "<<E->job<<" lb = "<<E->lowerbound<<endl;
}
void findMinCost(vector<vector<int> >& costs) {
    int n=costs.size();
    int lb;
    priority_queue<Node*, vector<Node*>, functor> nodes;

    lb = findLowerBound(costs, -1);
    int count = 0;
    nodes.push(new Node(-1, -1, lb, nullptr, count++));
    while(true) {

        Node* E = nodes.top();
        cout<<"-------------"<<endl;
        cout<<"Node number: "<<E->number<<endl;
        print(E);
        nodes.pop();
        if(E->worker == n-1) {
            return;
        }
        // expand node E
        lb = findLowerBound(costs, E->worker+1);
        for(int j=0; j<n; j++) {
            // assign available jobs to worker E->worker+1
            if(!hasAssigned(j, E)) {
                nodes.push(new Node(j, E->worker+1, costs[E->worker+1][j]+getPathCost(E, costs)+lb, E, count++));
            }
        }
    }
}

int main() {
    int n;
    cout<<"enter n: ";
    cin>>n;
    vector<vector<int> > costs(n, vector<int>(n));
    cout<<"enter the nxn cost matrix: "<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) 
            cin>>costs[i][j];
    }
    findMinCost(costs);
}
