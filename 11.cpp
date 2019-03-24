/*
这题官方已经给出了很详细的解析图，这里https://www.cnblogs.com/likaiming/p/8270401.html

1、注意什么时候左指针加，什么时候右指针减 
*/

int maxArea(vector<int>& height) {
    int result = 0;
    int i = 0; int j = height.size() - 1;
    while (i < j) {
        int current = min(height.at(i), height.at(j));
        if (result < current*(j - i))
            result = current*(j - i);
        if (height[i] <= height[j])
            i++;
        else
            j--;
    }
    return result;
}

int main()
{
    vector<int> nums = { 1 ,8 ,6 ,2, 5 ,4 ,8, 3 ,7 };
    cout << maxArea(nums) << endl;

    system("pause");
    return 0;
}