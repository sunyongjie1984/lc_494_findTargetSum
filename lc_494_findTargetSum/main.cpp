//
//  main.cpp
//  494_findTargetSum
//
//  Created by 孙永杰 on 2022/4/27.
//
/*
   给你一个整数数组 nums 和一个整数 target 。
   向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

   例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
   返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

   示例 1：
   输入：nums = [1,1,1,1,1], target = 3
   输出：5
   解释：一共有 5 种方法让最终目标和为 3 。
   -1 + 1 + 1 + 1 + 1 = 3
   +1 - 1 + 1 + 1 + 1 = 3
   +1 + 1 - 1 + 1 + 1 = 3
   +1 + 1 + 1 - 1 + 1 = 3
   +1 + 1 + 1 + 1 - 1 = 3

   示例 2：
   输入：nums = [1], target = 1
   输出：1
    

   提示：
   1 <= nums.length <= 20
   0 <= nums[i] <= 1000
   0 <= sum(nums[i]) <= 1000
   -1000 <= target <= 1000

   来源：力扣（LeetCode）
   链接：https://leetcode.cn/problems/target-sum
   著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
   */

#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <string.h>

class Solution_494 {
public:
    int findTargetSumWays2( std::vector< int >& nums, int target ) {
        const std::vector< int >::size_type size = nums.size( );
        int total = 1;
        bool flag[ size ];
        memset( flag, 0, sizeof( flag ) );
        total = pow( 2, size );
        int ret = 0;
        for ( int i = 0; i < total; ++i ) {
            // calculate flag, calculate binary format of number i
            std::bitset< 20 > tmp( i );
            {
                //i = 5;
                //std::cout << "hello";
            }
            int sum = 0;
            for ( int j = 0; j < size; ++j ) {
                tmp[ j ] ? sum += nums[ j ] : sum -= nums[ j ];
            }
            if ( sum == target) {
                ret += 1;
            }
        }
        return ret;
    }
    int findTargetSumWays( std::vector< int >& nums, int target ) {
        const std::vector< int >::size_type size = nums.size( );
        int total = 1;
        bool flag[ size ];
        memset( flag, 0, sizeof( flag ) );
        total = pow( 2, size );
        int ret = 0;
        for ( int i = 0; i < total; ++i ) {
            // calculate flag, calculate binary format of number i
            {
                int part_2 = i % 2;
                int part_1 = i / 2;
                int k = 0;
                flag[ k++ ] = part_2;
                while ( part_1 != 0) {
                    part_2 = part_1 % 2;
                    part_1 = part_1 / 2;
                    flag[ k++ ] = part_2;
                }
            }
            int sum = 0;
            for ( int j = 0; j < size; ++j ) {
                flag[ j ] ? sum += nums[ j ] : sum -= nums[ j ];
            }
            if ( sum == target ) {
                ret += 1;
            }
        }
        return ret;
    }
};

int main() {
    Solution_494 sum;
    //std::cout << sum.bitNumber( 7 ) << std::endl;
    //bool flags[3];
    //memset( flags, 0, sizeof( flags ));
    //std::cout << sum.bitNumber(5, flags) << std::endl;
    //std::cout << sum.bitNumber(7, flags) << std::endl;
    std::vector< int > a { 1, 1, 1, 1, 1 };
    std::vector< int > b { 1 };
    std::vector< int > c { 42, 24, 30, 14, 38, 27, 12, 29, 43, 42, 5, 18, 0, 1, 12, 44, 45, 50, 21, 47 };
    std::vector< int > d { 0, 38, 42, 31, 13, 10, 11, 12, 44, 16, 38, 17, 22, 28, 9, 27, 20, 35, 34, 39 };
    // 5
    std::cout << sum.findTargetSumWays( a, 3 ) << std::endl;
    std::cout << sum.findTargetSumWays2( a, 3 ) << std::endl;
    // 1
    std::cout << sum.findTargetSumWays( b, 1 ) << std::endl;
    std::cout << sum.findTargetSumWays2( b, 1 ) << std::endl;
    // 5602
    std::cout << sum.findTargetSumWays( c, 38 ) << std::endl;
    std::cout << sum.findTargetSumWays2( c, 38 ) << std::endl;
    // 6666
    std::cout << sum.findTargetSumWays( d, 2 ) << std::endl;
    std::cout << sum.findTargetSumWays2( d, 2 ) << std::endl;
    return 0;
}
