#pragma region include
#include <iostream>
#include "KDTree.hpp"
#include "KD_Tree.hpp"
#include "image_tool.hpp"

using namespace std;
#pragma endregion


int main(int argc, char* argv[])
{
    DATA data = crawlPixel(getFilePath());
    cout << "Tao cay...\n";
    KDTree tree(data.Data);
    cout << "Tao cay Xong.\n";

    xuatFile(tree, data);
    cout << "Xong";
    return 0;
}




