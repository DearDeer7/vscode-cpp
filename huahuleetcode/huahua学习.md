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

### 生成排列数

**P(n, d)：** 从所给的`N`个数从选择`d`个生成所有的排列。

```cpp
vector<vector<int>> Permutations(vector<int>& nums, int d) {
    vector<vector<int>> ans; // 储存排列结果

    vector<int> cur; // 当前排列
    vector<int> used(nums.size(), 0); // 访问数组

    function<void(int)> dfs = [&] (int depth) { // dfs生成所有排列 depth递归深度
        if(depth == d) {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(used[i]) continue;
            used[i] = 1;
            cur.push_back(nums[i]);
            dfs(depth + 1);
            cur.pop_back();
            used[i] = 0;
        }
    };

    dfs(0);

    return ans;
}
```

## 生成组合数

**C(n, d)：** 从所给的`N`个数从选择`d`个生成所有的组合。

```cpp
vector<vector<int>> Combinations(vector<int>& nums, int d) {
    vector<vector<int>> ans; // 储存组合结果
    vector<int> cur; // 当前组合

    // dfs生成所有组合 depth递归深度 s起始位置
    function<void(int, int)> dfs = [&] (int depth, int s) { 
        if(depth == d) {
            ans.push_back(cur);
            return;
        }

        for(int i = s; i < nums.size(); ++i) { // 从s位置开始遍历
            cur.push_back(nums[i]);
            dfs(depth + 1, i + 1);
            cur.pop_back();
        }
    };

    dfs(0, 0);

    return ans;
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

## 5.Tricks

### 切换字母大小写

ASCII： 

A-Z 65 - 90

a-z 97 - 122

'a' - 'A' = 32 = (1 << 5) 即小写字母第五位都是0，大写字母第五位都是1

```cpp
void toggle(char& c) {
    c ^= (1 << 5);
}
```



