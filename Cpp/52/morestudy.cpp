template <typename T>
T sum(T a, T b){
    return a + b;
}
```

```cpp
template <class T1, class T2>
void printAll(T1 a, T2 b){
    cout << "T1 : " << a << endl;
    cout << "T2 : " << b << endl;
    cout << "T1 + T2 : " << a + b << endl;
}