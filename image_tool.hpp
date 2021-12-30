#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>
#include <ratio>
#include <numeric>
#include <algorithm>
#include <Windows.h>
#include<fstream>
#include "KDTree.hpp"
#include "KD_Tree.hpp"
#include "filter.hpp"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
extern "C" 
{
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
}
#include "stb_image.h"
#include "stb_image_write.h"
using namespace std;
#pragma endregion
class ColorArea
{
public:
    double r, b, g, c;
    ColorArea(double red, double green, double blue, double cis)
    {
        r = red;
        g = green;
        b = blue;
        c = cis;
    }
};
struct DATA
{
    int width = 0;
    int height = 0;
    pointVec Data;
};
string folder;
string filename;
string filetype;
bool load_image(std::vector<unsigned char>& image, const std::string& filename, int& x, int& y)
{
    int n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 4);
    if (data != nullptr)
    {
        image = std::vector<unsigned char>(data, data + x * y * 4);
    }
    stbi_image_free(data);
    return (data != nullptr);
}

DATA crawlPixel(std::string filename)
{
    cout << "Dang lay du lieu tu file " << filename << "...\n\n";
    point_t point;
    DATA data;
    std::vector<unsigned char> image;
    bool success = load_image(image, filename, data.width, data.height);
    if (!success)
    {
        std::cout << "Error loading image\n";
        exit(0);
    }
    const size_t RGBA = 4;
    for (int x = 0; x < data.width; x++)
    {
        for (int y = 0; y < data.height; y++)
        {
            size_t index = RGBA * (y * data.width + x);
            point = {
                (double)image[index + 0],
                (double)image[index + 1],
                (double)image[index + 2],
                (double)image[index + 3],
                (double)x,
                (double)y };
            data.Data.push_back(point);
        }
    }
    return data;
}

void WriteText(const string filename, pointVec Data)
{
    string filepath = folder + filename + ".txt";
    cout << "Dang xuat file " << filepath << "...\n\n";
    ofstream file;
    file.open(filepath);
    for (int i = 0; i < Data.size(); i++)
    {
        file << Data[i][0] << " "
            << Data[i][1] << " "
            << Data[i][2] << " "
            << Data[i][3] << " "
            << Data[i][4] << " "
            << Data[i][5] << "\n";
    }  
    file.close();
}
void writePNG(const char* filename, pointVec data, int width, int height)
{
    cout << "Dang xuat file" << filename << "...\n";
#define CHANNEL_NUM 4

    /*** NOTICE!! You have to use uint8_t array to pass in stb function  ***/
    // Because the size of ColorArea is normally 255, 8bit.
    // If you don't use this one, you will get a weird imge.
    int n = CHANNEL_NUM * (height * width);
    uint8_t* pixels = new uint8_t[n];

    ////////////// Clear ////////////
    for (int i = 0; i < n; i++)
    {
        pixels[i] = 255;
    }
    ////////////////////////////////

    n = data.size();
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        index = CHANNEL_NUM * (data[i][5] * width + data[i][4]);
        pixels[index++] = data[i][0];
        pixels[index++] = data[i][1];
        pixels[index++] = data[i][2];
        pixels[index++] = data[i][3];

    }


    // if CHANNEL_NUM is 4, you can use alpha channel in png
    stbi_write_png(filename, width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);

}


string getFilePath()
{
    int n;
    cout << "Nhap file anh: \n";
    cout << "1. logoHCMUTE\n"
        << "2. Bang Mau\n"
        << "3. logo55Y\n"
        << "4. cho\n"
        << "5. Dua Hau\n"
        << "0. Khac\n";
    cin >> n;
    if (n == 0)
    {
        string path;
        cout << "Path: ";
        cin >> path;
        return path;
    }
    else
    {
        switch (n)
        {
        case 1:
            folder = "./Image/logoHCMUTE/";
            filename = "logoHCMUTE";
            filetype = ".png";
            return (folder + filename + filetype);
        case 2:
            folder = "./Image/BangMau/";
            filename = "BangMau";
            filetype = ".jpg";
            return (folder + filename + filetype);
        case 3:
            folder = "./Image/logo55Y/";
            filename = "logo55Y";
            filetype = ".png";
            return (folder + filename + filetype);
        case 4:
            folder = "./Image/Cho/";
            filename = "cho";
            filetype = ".jpg";
            return (folder + filename + filetype);
        case 5:
            folder = "./Image/DuaHau/";
            filename = "duahau";
            filetype = ".jpg";
            return (folder + filename + filetype);
        default: exit(0);
        }
    }
}
void xuatFile(string filepath, pointVec result, int w, int h)
{
    filepath = folder + filepath + ".png";
    const char* c = filepath.c_str();
    writePNG(c,result,w,h);
}


void xuatFile(KDTree tree, DATA data)
{
    int n; 
    cout << "Xuat filt .txt?\n1.Yes\n2.No\n";
    cin >> n;

    pointVec result;
    result = red_filter(tree);
    xuatFile("Red", result, data.width, data.height);
    if (n == 1) WriteText("Red", result);
    result = green_filter(tree);
    xuatFile("Green", result, data.width, data.height);
    if (n == 1) WriteText("Green", result);
    result = blue_filter(tree);
    xuatFile("Blue", result, data.width, data.height);
    if (n == 1) WriteText("Blue", result);
    result = yellow_filter(tree);
    xuatFile("Yellow", result, data.width, data.height);
    if (n == 1) WriteText("Yellow", result);
    result = violet_filter(tree);
    xuatFile("Violet", result, data.width, data.height);
    if (n == 1) WriteText("Violet", result);
    result = lightBlue_filter(tree);
    xuatFile("LightBlue", result, data.width, data.height);
    if (n == 1) WriteText("LightBlue", result);

    result = orange_filter(tree);
    xuatFile("Orange", result, data.width, data.height);
    if (n == 1) WriteText("Orange", result);
    result = lightGreen_filter(tree);
    xuatFile("LightGreen", result, data.width, data.height);
    if (n == 1) WriteText("LightGreen", result);
    result = pink_filter(tree);
    xuatFile("Pink", result, data.width, data.height);
    if (n == 1) WriteText("Pink", result);
    result = lightViolet_filter(tree);
    xuatFile("lightViolet", result, data.width, data.height);
    if (n == 1) WriteText("Violet", result);
    result = black_filter(tree);
    xuatFile("BLack", result, data.width, data.height);
    if (n == 1) WriteText("Black", result);
}
