class Array
{
private:
    const int N = 20;
    int* arr = new int[N];
    int k = 0;
public:
    void typeOfFilling(int);
    void print();
    void processElements(int);
    void fillWithRandomNumbers();
    void fillUsingKeyboard();
};
