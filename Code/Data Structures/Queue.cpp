class Link {
public:
    int element;
    Link *next;

    Link(const int element, Link *next) {
        this->element = element;
        this->next = next;
    }

    Link(Link *next) {
        this->next = next;
    }
};

struct queue {
private:
    Link *front;
    Link *rear;
    int size;

public:
    queue() {
        front = rear = new Link(NULL);
        size = 0;
    }

    ~queue() {
        clear();
        delete front;
    }

    void clear() {
        while (front->next != NULL) {
            Link *aux = front->next;
            rear = front;
            delete rear;
            front = aux;
        }
        rear = front;
        size = 0;
    }

    void enqueue(int number) {
        rear->next = new Link(number, NULL);
        rear = rear->next;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            return NULL;
        } else {
            int number = front->next->element;
            front->next = front->next->next;
            if (front->next == NULL) {
                rear = front;
            }
            size--;
            return number;
        }
    }

    int frontValue() {
        if (size == 0) {
            return NULL;
        } else {
            return front->next->element;
        }
    }

    int length() {
        return size;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }
};
