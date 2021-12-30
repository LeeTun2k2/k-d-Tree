#pragma once
#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

using point_t = std::vector< double >; // Điểm
using indexArr = std::vector< size_t >; // Tập hợp điểm
using pointIndex = typename std::pair< std::vector< double >, size_t >; //pair chứa vector + size

class KDNode {
public:
    using KDNodePtr = std::shared_ptr< KDNode >; //Pointer tự động hủy
    size_t index; //index auto size
    point_t x; //data
    KDNodePtr left; //Previous
    KDNodePtr right; //Next

    //////////// Constructor ////////////
    KDNode();
    KDNode(const point_t&, const size_t&, const KDNodePtr&,const KDNodePtr&);
    KDNode(const pointIndex&, const KDNodePtr&, const KDNodePtr&);
    ~KDNode();
    /////////// End Constructor////////////

    double coord(const size_t&); // getter

    // conversions
    explicit operator bool();
    explicit operator point_t();
    explicit operator size_t();
    explicit operator pointIndex();
};

using KDNodePtr = std::shared_ptr< KDNode >; //Pointer tự động hủy

KDNodePtr NewKDNodePtr();

// square euclidean distance
inline double dist2(const point_t&, const point_t&); //Bình phương khoảng cách giữa 2 điểm
inline double dist2(const KDNodePtr&, const KDNodePtr&);  //Bình phương khoảng cách giữa 2 node trên cây

// euclidean distance
inline double dist(const point_t&, const point_t&);  //khoảng cách giữa 2 điểm
inline double dist(const KDNodePtr&, const KDNodePtr&); //khoảng cách giữa 2 node trên cây

// Need for sorting
class comparer //so sánh
{
public:
    size_t idx; 
    explicit comparer(size_t idx_);
    inline bool compare_idx(const std::pair< std::vector< double >, size_t >&, const std::pair< std::vector< double >, size_t >&);
};

using pointIndexArr = typename std::vector< pointIndex >; // vector<pointIndex> lưu giá trị gần trong phạm vi
inline void sort_on_idx(const pointIndexArr::iterator&,  //
    const pointIndexArr::iterator&,  //
    size_t idx);

using pointVec = std::vector< point_t >; //Không gian chứa các điểm, aka vector<point_t>

class KDTree {
    KDNodePtr root;
    KDNodePtr leaf;

    KDNodePtr make_tree(const pointIndexArr::iterator& begin,  //
        const pointIndexArr::iterator& end,    //
        const size_t& length,                  //
        const size_t& level                    //
    );

public:
    KDTree() = default;
    explicit KDTree(pointVec point_array);

private:
    KDNodePtr nearest_(           //
        const KDNodePtr& branch,  //
        const point_t& pt,        //
        const size_t& level,      //
        const KDNodePtr& best,    //
        const double& best_dist   //
    );

    // default caller
    KDNodePtr nearest_(const point_t& pt);

public:
    point_t nearest_point(const point_t& pt);
    size_t nearest_index(const point_t& pt);
    pointIndex nearest_pointIndex(const point_t& pt);

private:
    pointIndexArr neighborhood_(  //
        const KDNodePtr& branch,  //
        const point_t& pt,        //
        const double& rad,        //
        const size_t& level       //
    );

public:
    pointIndexArr neighborhood(  //
        const point_t& pt,       //
        const double& rad);

    pointVec neighborhood_points(  //
        const point_t& pt,         //
        const double& rad);

    indexArr neighborhood_indices(  //
        const point_t& pt,          //
        const double& rad);
};
