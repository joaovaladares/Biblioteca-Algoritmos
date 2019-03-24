class Link {
public:
    char element;
    Link* next;

    Link(const char element, Link* next) {
        this->element = element;
        this->next = next;
    }
    Link(Link* next) {
        this->next = next;
    }
};

struct linkedStack {
    Link* top;
    int size;

    linkedStack() {
        top = NULL;
        size = 0;
    }
    ~linkedStack() {
        clear();
    }

    void clear() {
        while (top != NULL) {
            Link* aux = top;
            top = top->next;
            delete aux;
        }
        size = 0;
    }

    void push(char bracket){
        top = new Link(bracket, top);
        size++;
    }

    char pop() {
        if (top == NULL){
            return NULL;
        } else {
            char bracket = top->element;
            Link* aux = top->next;
            delete top;
            top = aux;
            size--;
            return bracket;
        }
    }

    char topValue() {
        if (top == NULL){
            return NULL;
        } else {
            return top->element;
        }
    }

    int length() {
        return size;
    }

    bool isEmpty(){
        if (this->top == NULL) {
            return true;
        } else {
            return false;
        }
    }
};