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
        // seed
	srand(4);

    size_t npoints = 100000;
    std::vector<point_t> points = getListofGeneratedVectors(npoints); // Khởi tạo các điểm ngẫu nhiên
    KDTree tree(points);
    
    for (int i = 0; i < 100; i ++)
    {
        dem = 0;
        srand(i);
        point_t pt = generateVector();
        findNeighborhood(tree,pt,0.1);
        std::cout << dem << "\n";
    }
    return 0;
}
