		#include <iostream>
using namespace std; 

#define max 100

struct Element {
    char data;
    int priority;
};

struct PriorityQueue {
    Element arr[max];
    int size;
};

void siftUp(PriorityQueue *q) {
    int i = q->size - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (q->arr[p].priority < q->arr[i].priority) {
            swap(q->arr[p], q->arr[i]);
            i = p;
        } else {
            return;
        }
    }
}

void add(PriorityQueue *q, Element x) {
    q->arr[q->size] = x;
    q->size++;
    siftUp(q);
}

void siftDown(PriorityQueue *q) {
    int p = 0;
    int i = 2 * p + 1;
    while (i < q->size) {
        if (i + 1 < q->size && q->arr[i].priority < q->arr[i + 1].priority) {
            i++;
        }
        if (q->arr[p].priority < q->arr[i].priority) {
            swap(q->arr[p], q->arr[i]);
            p = i;
            i = 2 * p + 1;
        } else {
            return;
        }
    }
}

Element remove(PriorityQueue *q) {
    Element x = q->arr[0];
    q->arr[0] = q->arr[q->size - 1];
    q->size--;
    siftDown(q);
    return x;
}

// c) Kiem tra mot hang doi uu tien có rong khong
bool isEmpty(PriorityQueue q) {
    return q.size == 0;
}

// d) Tra ve phan tu dau tien cua hang doi uu tien, không lay ra khoi hang doi.
Element top(PriorityQueue q) {
    return q.arr[0]; 
}

int main() {
    PriorityQueue q;
    q.size = 0;

    add(&q, {'A', 3});
    add(&q, {'B', 4});
    add(&q, {'C', 1});

    Element x = remove(&q);
    cout << x.data << " " << x.priority << endl;

    x = remove(&q);
    cout << x.data << " " << x.priority << endl;

    // Kiem tra phan tu dau tien (khong lay ra)
    if (!isEmpty(q)) {
        Element t = top(q);
        cout << "Top: " << t.data << " " << t.priority << endl;
    }

    return 0;
}

