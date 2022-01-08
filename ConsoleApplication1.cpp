// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <pmmintrin.h>//SSE
#include <immintrin.h>//AVX

#include <iostream>
#include "RecordTimer.h"

int main()
{
    std::cout << "Hello World!\n";
    RecordTimer tm;
    tm.start();

    float *sum_avg = new float[10000000];
    for (int i = 0; i < 10000000; i++)
    {
        sum_avg[i] = i * 1.0 * i;
    }

    tm.end();
    double ticks = tm.getTick();
    std::cout << "无并行计算:" << ticks << std::endl;//耗时 45.6397

    tm.start();
    float *sum_avg2 = new float[10000000];
    __m128 m1;
    __m128* dst = (__m128*)sum_avg2;
    for (int i = 0; i < 10000000; i += 4)
    {
        m1 = _mm_set_ps(i + 3, i + 2, i + 1, i);
        *dst = _mm_mul_ps(m1, m1);
        dst++;
    }
    tm.end();
    ticks = tm.getTick();
    std::cout << "并行计算1:" << ticks << std::endl;//耗时22.8161

    tm.start();
    float *sum_avg3 = new float[10000000];
    __m256 m2;
    __m256* dst2 = (__m256*)sum_avg3;
    for (int i = 0; i < 10000000; i += 8)
    {
        m2 = _mm256_set_ps(i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1, i);
        *dst2 = _mm256_mul_ps(m2, m2);
        dst2++;
    }
    tm.end();
    ticks = tm.getTick();
    std::cout << "并行计算2:" << ticks << std::endl; //耗时10.7683
}
//int main()
//{
//    std::cout << "Hello World!\n";
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
