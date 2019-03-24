/*
一、问题描述
　　给一个数组S，和一个目标数target，在S中找出三个数的和与target的差最小。返回这3个数字的和

　　例子：S={-1 2 1 -4}，target=1，返回2（-1+2+1=2）

二、问题解决
　　思路：模仿第15题的思路，确地一个i后，让j和k在i之后的区间不断逼近。用dis记录最小距离，用result记录最接近结果。按15题的思路走一遍就可以得出结果。
*/

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int dis = INT_MAX;
    int result = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        int a = nums.at(i);
        int j = i+1;
        int k = nums.size() - 1;
        while (j < k) {
            int b = nums.at(j);
            int c = nums.at(k);
            if (a + b + c - target == 0)
                return target;
            if (abs(a + b + c - target) < dis) {
                result = a + b + c;
                dis = abs(a + b + c - target);
            }
            if ((a + b + c) < target)
                j++;
            else
                k--;
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {-1,2,1,-4};
    cout << threeSumClosest(nums,1) << endl;

    system("pause");
    return 0;
}