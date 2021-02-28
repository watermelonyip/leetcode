/*
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。说明:  1 是丑数，n 不超过1690。
思路：用数组存储计算出来的并且按升序排列好的丑数。为了每次计算出来的丑数按升序放入数组中，需要用三个变量分别记录*2，*3，*5的位置，使得每次从这几个数中取最小值放入数组中就能满足升序。
时间复杂度O(n)，空间复杂度O(n)。
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0)
            return 0;
        int* arr = new int[n + 1];
        arr[0] = 1;
        int index = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        for(; index < n; index++){
            int min = (arr[index2] * 2 < arr[index3] * 3) ? arr[index2] * 2 : arr[index3] * 3;
            min = (min < arr[index5] * 5) ? min : arr[index5] * 5;
            arr[index] = min;
            while(arr[index2] * 2 <= min)
                index2++;
            while(arr[index3] * 3 <= min)
                index3++;
            while(arr[index5] * 5 <= min)
                index5++;
        }
        int result = arr[n - 1];
        delete[] arr;
        return result;
    }
};
