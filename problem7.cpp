#include <iostream>
#include <cmath>
using namespace std;

const int n = 5;
int a[n];

struct Node{
    bool is_present[n];
    Node* next;
};

int sum_up(Node node){
    int current_sum = 0;
    for (int i = 0; i < n; i++){
        if(node.is_present[i]){
            current_sum += a[i];
        }
    }
    if(node.next == nullptr){
        return current_sum;
    } else {
        return current_sum + sum_up(*node.next);
    }
}

int main() {
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }

    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;
    for (int i = 0; i < 5; i++){
        n1->is_present[i] = (i < 3);
        n2->is_present[i] = (1 <= i) && (i < 4);
        n3->is_present[i] = (2 <= i) && (i < 5);
    }

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    for (int i = 0; i < pow(2, n); i++){
        int j = n-1;
        while(a[j] == 1){
            a[j] = 0;
            j--;
        }
        a[j] = 1;
        for (int k = 0; k < n; k++){
            cout << a[k] << ' ';
        }

        cout << "Result: " << sum_up(*n1)%2 << endl;
    }

    return 0;
}
