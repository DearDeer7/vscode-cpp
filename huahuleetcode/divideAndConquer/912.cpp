class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if(l > r) return;
        int i = l, j = r;
        int idx = l + rand() % (r - l + 1);
        int pivot = nums[idx];
        while(l <= r) {
            while(nums[i] < pivot) i++;
            while(nums[j] > pivot) j--;
            if(i <= j) swap(nums[i++], nums[j--]);
        }
        quickSort(nums, l, j);
        quickSort(nums, i, r);
    }

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
};

// // ling boy
// void sort(int d[],int l,int r){
//     if(r<=l) return;
//     int i=l,j=r;
//     while(1){
//         while(d[i]>d[j]) j--;
//         swap(d,i,j);
//         while(d[i]>d[j]) i++;
//         swap(d,i,j);  
//         if(i==j){
//             sort(d,l,i-1);
//             sort(d,r,j+1);
//             return;
//         }
//     }
// }
