#pragma once
#include <iostream>
#include "KDTree.hpp"
#include "KD_Tree.hpp"
using namespace std;

#define RED RGB[0]
#define GREEN RGB[1]
#define BLUE RGB[2]
pointVec merge(pointVec a, pointVec b)
{
    pointVec c = {};
    c.reserve(a.size() + b.size());
    c.insert(c.end(), a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());
    return c;
}
#pragma region num_of_chanel_1
pointVec red_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {150,0,0};
    double radian = 30;
    double step = 45;
    pointVec result ={};
    pointVec data;
    while (RED < 255 || GREEN < 180 || BLUE < 180)
    {
        GREEN = 0;
        BLUE = 0;
        while (GREEN < RED && BLUE < RED)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            GREEN += step;
            BLUE += step;
            if (GREEN > 180 && BLUE > 180) break;
            if (GREEN > 180) GREEN = 180;
            if (BLUE > 180) BLUE = 180;
        }
        RED += step;
    }
    return result;
}

pointVec green_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {0,100,0};
    double radian = 30;
    double step = 45;
    pointVec result ={};
    pointVec data;
    while (RED < 180 || GREEN < 255 || BLUE < 180)
    {
        RED = 0;
        BLUE = 0;
        while (RED < GREEN && BLUE < GREEN)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            RED += step;
            BLUE += step;
            if (RED > 180 && BLUE > 180) break;
            if (RED > 180) RED = 180;
            if (BLUE > 180) BLUE = 180;
        }
        GREEN += step;
    }
    return result;
}

pointVec blue_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {0,0,150};
    double radian = 30;
    double step = 45;
    pointVec result ={};
    pointVec data;
    while (RED < 180 || GREEN < 180 || BLUE < 255)
    {
        RED = 0;
        GREEN = 0;
        while (RED < BLUE && GREEN < BLUE)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            RED += step;
            GREEN += step;
            if (GREEN > 180 && RED > 180) break;
            if (GREEN > 180) GREEN = 180;
            if (RED > 180) RED = 180;
        }
        BLUE += step;
    }
    return result;
}

#pragma endregion

#pragma region num_of_chanel_2
#pragma region _2_paralel_chanel
pointVec yellow_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {130,130,0};
    double radian = 30;
    double step = 45;
    pointVec result ={};
    pointVec data;
    while (RED < 255 || GREEN < 255 || BLUE < 255)
    {
        BLUE = 0;
        while (BLUE < RED && BLUE < GREEN)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            BLUE += step;
        }
        RED += step;
        GREEN += step;
    }
    return result;
}

pointVec violet_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {130,0,130};
    double radian = 30;
    double step = 45;
    pointVec result ={};
    pointVec data;
    while (RED < 255 || GREEN < 255 || BLUE < 255)
    {
        GREEN = 0;
        while (GREEN < RED && GREEN < BLUE)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            GREEN += step;
        }
        RED += step;
        BLUE += step;
    }
    return result;
}

pointVec lightBlue_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {0,130,130};
    double radian = 30;
    double step = 45;
    pointVec result ={};
    pointVec data;
    while (RED < 255 || GREEN < 255 || BLUE < 255)
    {
        RED = 0;
        while (RED < BLUE && RED < GREEN)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            RED += step;
        }
        BLUE += step;
        GREEN += step;
    }
    return result;
}
#pragma endregion

#pragma region _2_non-paralel_chanel
pointVec orange_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {190,100,0};
    double radian = 60;
    double step = 25;
    pointVec result ={};
    pointVec data;
    while (RED < 255 || GREEN < 175 || BLUE < 75)
    {
        BLUE = step/2;
        while (BLUE < GREEN - 100 && BLUE < 75)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            BLUE += step;
        }
        RED += step;
        GREEN += step;
        if (GREEN > 175) GREEN = 175;
    }
    RGB = {255,185,75};
    data = findNeighborhood(tree,RGB,radian);
    result = merge(result,data);
    return result;
}

pointVec lightGreen_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {100,190,0};
    double radian = 60;
    double step = 25;
    pointVec result ={};
    pointVec data;
    while (RED < 175 || GREEN < 255 || BLUE < 75)
    {
        BLUE = step/2;
        while (BLUE < RED - 100 && BLUE < 75)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            BLUE += step;
        }
        RED += step;
        GREEN += step;
        if (RED > 175) RED = 175;
    }
    RGB = {175,255,75};
    data = findNeighborhood(tree,RGB,radian);
    result = merge(result,data);
    return result;
}

pointVec pink_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {190,0,100};
    double radian = 60;
    double step = 25;
    pointVec result ={};
    pointVec data;
    while (RED < 255 || GREEN < 75 || BLUE < 175)
    {
        GREEN = step/2;
        while (GREEN < BLUE - 100 && GREEN < 75)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            GREEN += step;
        }
        RED += step;
        BLUE += step;
        if (BLUE > 175) BLUE = 175;
    }
    RGB = {255,75,175};
    data = findNeighborhood(tree,RGB,radian);
    result = merge(result,data);
    return result;
}

pointVec lightViolet_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {100,0,190};
    double radian = 60;
    double step = 25;
    pointVec result ={};
    pointVec data;
    while (RED < 175 || GREEN < 75 || BLUE < 255)
    {
        GREEN = step/2;
        while (GREEN < RED - 100 && GREEN < 75)
        {
            data = findNeighborhood(tree,RGB,radian);
            result = merge(result,data);
            GREEN += step;
        }
        RED += step;
        BLUE += step;
        if (RED > 175) RED = 175;
    }
    RGB = {175,75,255};
    data = findNeighborhood(tree,RGB,radian);
    result = merge(result,data);
    return result;
}
#pragma endregion
#pragma endregion

#pragma region num_of_channel_3

pointVec black_filter(KDTree tree)
{
    cout << "Dang loc du lieu...\n";
    point_t RGB = {0,0,0};
    double radian = 30;
    double step = 20;
    pointVec result ={};
    pointVec data;
    while (RED < 100 || GREEN < 100 || BLUE < 100)
    {
        data = findNeighborhood(tree,RGB,radian);
        result = merge(result,data);
        GREEN += step;
        RED += step;
        BLUE += step;
    }
    return result;
}

#pragma endregion