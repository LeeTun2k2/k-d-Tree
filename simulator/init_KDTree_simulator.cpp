#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>
#include <ratio>
#include <numeric>
#include <algorithm>
#include "KDTree.hpp"
#include "KD_Tree.hpp"

double getNum() //Tạo 1 số thực ngẫu nhiên dạng double
{
	return ((double)rand() / (RAND_MAX));
}

std::vector<double> generateVector() //Sinh ra 1 Điểm dạng vector 3 chiều
{
    std::vector<double> temp(DIM);
	for (size_t idx = 0; idx < DIM; idx++)
    {
		temp[idx] = getNum();
    }
	return temp;
}

std::vector<std::vector<double>> getListofGeneratedVectors(size_t length) 
// Sinh ra một vector chứa Các điểm
{
    std::vector<std::vector<double>> temp(length);
	for (size_t idx = 0; idx < length; idx++)
    {
		temp[idx] = generateVector();
    }
	return temp;
}

int main()
{
    for (int i = 10000; i <= 200000; i+=10000)
    {
        // seed
	srand(4);

    size_t npoints = i;
    std::vector<point_t> points = getListofGeneratedVectors(npoints); // Khởi tạo các điểm ngẫu nhiên
    ///////////////////Bắt đầu tính thời gian tạo cây/////////////////
    auto start = std::chrono::high_resolution_clock::now(); ////high_resolution_clock::now() lấy thời gian thực có độc chính xác cao
    KDTree tree(points);
    auto stop = std::chrono::high_resolution_clock::now();
    ////////////////// Kết thúc tính thời gian tạo cây///////////////
    auto timespan = std::chrono::duration<double>(stop - start); ///duration = khoảng thời gian
    std::cout <<timespan.count() << "\n";
    }
    return 0;
}
