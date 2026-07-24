class CustomStack {
public:
    vector<int> MyVec;
    int max = 0;
    CustomStack(int maxSize) { max = maxSize; }

    void push(int x) {
        if (MyVec.size() < max) {
            MyVec.push_back(x);
        }
    }

    int pop() {
        if (MyVec.empty())
            return -1;
        int n = MyVec[MyVec.size() - 1];
        MyVec.pop_back();
        return n;
    }

    void increment(int k, int val) {
        int size = k;
        if (k > MyVec.size())
            size = MyVec.size();
        for (int i = 0; i < size; i++) {
            MyVec[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */