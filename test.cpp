#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;

template<typename ELEMENT>
class queue {
public:
    queue(int capacity) {
        buffer_ = (ELEMENT*) malloc(capacity * sizeof(ELEMENT));
        head_ = 0;
        tail_ = -1;
        size_ = 0;
        capacity_ = capacity;
    }

    int dequeue() {
        if (size_ > 0) {
            int tmp = head_;
            ++head_;
            head_ = head_ % capacity_;
            --size_;
            return buffer_[tmp];
        } else {
            throw std::invalid_argument("nothing in the queue!");
        }
    }

    void enqueue(int element) {
        if (size_ == capacity_) {
            throw std::invalid_argument("queue is full!");
        }
        ++tail_;
        tail_ = tail_ % capacity_;
        buffer_[tail_] = element;
        ++size_;
    }

private:
    ELEMENT* buffer_;
    int head_;
    int tail_;
    int capacity_;
    int size_;
};



int main() {
    queue<double> q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();

    q.enqueue(4);
    q.enqueue(5);


    cout << q.dequeue() << q.dequeue() << q.dequeue() << endl;
    return 0;
}