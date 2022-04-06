/*
 * @Author: Metaphor
 */
/*
 * @Author: Metaphor
 */
#include "assistance.h"

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>

using namespace std;
 
 
class UnionFind {
private:
    int parent[100];// 父节点
 
    int maxIndex;
public:
    UnionFind(int maxIndex) {
        this->maxIndex = maxIndex;
        for(int i = 0; i <= maxIndex; i++) {
            parent[i] = -1;
        }
    }
 
 
    ~UnionFind() {
    }
    /*
        //递归findRoot
        int findRoot(int x) {
            if (parent[x] == -1) {
                return x;// 如果我自己就是-1，那么我就是根
            } else {
                return findRoot(parent[x]); // 如果我不是-1，找我parent的根
            }
        }
    */
    //非递归findRoot
    int findRoot(int x) {
        // 如果我自己就是-1，那么我就是根
        // 如果我不是-1，找我parent的根
        int current = x;
        while(parent[current] != -1) {
            current = parent[current];
        }
        return current;
    }
 
    bool isConnected(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
 
    bool connect(int x, int y) {
        cout << "**现在要connect" << x << " and " << y << endl;
        int xRoot = findRoot(x);
        int yRoot = findRoot(y);
        cout << "x的Root:" << xRoot << " and y的Root:" << yRoot << endl;
        if (xRoot == yRoot) {
            cout << "**已经直接或者间接联通，不做处理" << endl << endl;
            return false;
        } else {
            parent[yRoot] = xRoot;
            cout << "**经过修改，yroot的parent 改成了 xroot" << endl << endl;
            return true;
        }
    }
 
 
    void show() {
 
        cout << "---目前情况---" << endl;
        cout << "parent :";
        for (int i = 0; i <= maxIndex; i++) {
            cout  << parent[i] << "\t";
        }
        cout << endl;
 
        cout << "index  :";
        for (int i = 0; i <= maxIndex; i++) {
            cout  << i << "\t";
        }
        cout << endl;
 
        cout << "---打印完毕---" << endl << endl;
    }
 
 
 
};
 
// int main() {
//     UnionFind uf(8); // 生成 0 ~ 8  一共9个节点
//     cout << "开始！" << endl;
//     uf.show();
//     uf.connect(0, 1);
//     uf.show();
//     uf.connect(1, 2);
//     uf.show();
//     uf.connect(1, 3);
//     uf.show();
//     uf.connect(3, 4);
//     uf.show();
//     uf.connect(2, 4);
//     uf.show();
//     uf.connect(2, 5);
//     uf.show();
 
//     uf.connect(6, 7);
//     uf.show();
 
 
//     cout << uf.isConnected(3, 5) << endl;
//     cout << uf.isConnected(2, 4) << endl;
//     cout << uf.isConnected(3, 6) << endl;
//     cout << uf.isConnected(6, 8) << endl;
//     cout << uf.isConnected(4, 8) << endl;
//     return 0;
 
// };
 