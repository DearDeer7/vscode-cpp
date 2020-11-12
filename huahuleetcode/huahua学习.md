# huahua学习

## 1. C++ api

### copy()

***prototype: std::copy(it begin, it end, T target)***

**function: copy a section of elements to another place with given begin address.**

```cpp
#include<algorithm>

vector<int> v{1,2,3,4};
vector<int> t(v.size());

// copy all contents of v to t;
std::copy(v.begin(), v.end(), t.begin());

// copy three elements from left of v to t;
std::copy(v.begin(), v.begin() + 3, t.begin());

// copy front element of v to the back of t;
std::copy(v.begin(), v.begin() + 1, t.end() - 1);
```

### count()

***prototype: std::count(it begin, it end, T target)***

**function:  count how many times of a target appears in a given section.**

```cpp
#include<algorithm>

vector<int> nums{1,1,1,2,2,2,2};

// count the number of '1' in nums
cout << count(nums.begin(), nums.end(), 1) << endl;
// output 3

// count the number of 1 in nums from 2th element
cout << count(nums.begin() + 2, nums.end(), 1) << endl;
// output 1
```

### count_if()

***prototype: std::count_if(it begin, it end, bool if_cond)***

**function:  count how many times of a target appears in a given section and meets the if condition.**

```cpp
#include<algorithm>

vector<int> nums{1,1,1,2,2,2,2};

// count how many elements over than 1
cout << count_if(nums.begin(), nums.end(), [=] (int a) { return a > 1; });
```

### accumulate()

***prototype: std::accumulate(it begin, it end, T init)*** 

***or std::accumulate(it begin, it end, T init, custom method)***

**function： calculate the sum of elements in the given range with or without custom method**

```cpp
#include<numeric>

vector<int> nums{1,2,2};
int init = 100;

// simplely calculate the sum of elements in nums
cout << accumulate(nums.begin(), nums.end(), init) << endl;
// same to sum = init + 1 + 2 + 2;
// output 105

// calculate the sum of elements in nums with multiply method
cout << accumulate(nums.begin(), nums.end(), init, [=] (int x, int y) { 
    return x * y;
}) << endl;
// same to  sum = init * 1 * 2 * 2;
// output 400

// calculate the sum of elements in nums with minus method
cout << accumulate(nums.begin(), nums.end(), init,  [=] (int x, int y) { 
    return x - y;
}) << endl;
// same to sum = init - 1 - 2 - 2;
// output 95
```

### typeid(a).name()

 C++输出某个数据的类型。

数据类型和返回值对应表：

```cpp
bool:                     b
 
char:                     c
signed char:              a
unsigned char:            h
 
(signed) short (int):     s
unsigned short (int):     t
 
(signed) (int):           i
unsigned (int):           j
 
(signed) long (int):      l
unsigned long (int):      m
 
(signed) long long (int): x
unsigned long long (int): y
 
float:                    f
double:                   d
long double:              e
```

例子：

```cpp
#include<typeinfo>

int x = 1;
double y = 1.0;
char ch = 'c';
cout << typeid(x).name() << " " 
    << typeid(y).name() << " " 
    << typeid(ch).name() << endl;
// output: i d c
```



### decltype()





## 2. algorithm template

### quickSort

```cpp
void quickSort(vector<int>& nums, int l, int r) {
    if(l > r) return;
    int i = l, j = r;
    int idx = l + rand() % (r - l + 1);
    int pivot = nums[idx];

    while(i <= j) {
        while(nums[i] < pivot) i++;
        while(nums[j] > pivot) j--;
        if(i <= j) swap(nums[i++], nums[j--]);
    }

    quickSort(nums, l, j);
    quickSort(nums, i, r);
}
```

### mergeSort

```cpp
void mergeSort(vector<int>& nums, int l, int r) {
    if(l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);

    vector<int> t(r - l + 1);
    int il = l, ir = mid + 1;
    int idx = 0;
    while(il <= mid || ir <= r) {
        if(ir == r+1 || (il <= mid && nums[il] < nums[ir])) {
            t[idx++] = nums[il++];
        }
        else t[idx++] = nums[ir++];
    }
    std::copy(t.begin(), t.end(), nums.begin() + l);
}
```
### Merge Two Sorted Lists

```cpp
ListNode* merge(ListNode *l1, ListNode* l2) {
    if(!l1 || !l2) return l1 ? l1 : l2;
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while(l1 && l2) {
        if(l1 ->val > l2->val) swap(l1, l2);
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
```



## 3.STL

### priority_queue

https://www.cnblogs.com/wu-xiao-facebook/p/11606383.html



## 4.bad behaviors

### while + assignment

```cpp
int a = 0, b = 1;

while( a = b++) {
    cout << a << endl;
}
// fisrt a = b, then b++, then cout a
// same to 
a = b;
b++;
while(a) {
    cout << a << endl;
    a = b;
    b++;
}
```

