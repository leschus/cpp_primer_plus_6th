// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma.h"
int main()
{
    using std::cout;
    using std::endl;

    // baseDMA shirt("Portabelly", 8);
    // lacksDMA balloon("red", "Blimpo", 4);
    // hasDMA map("Mercator", "Buffalo Keys", 5);

    // cout << "Displaying baseDMA object:\n";
    // cout << shirt << endl;
    // cout << "Displaying lacksDMA object:\n";
    // cout << balloon << endl;
    // cout << "Displaying hasDMA object:\n";
    // cout << map << endl;
    // lacksDMA balloon2(balloon);
    // cout << "Result of lacksDMA copy:\n";
    // cout << balloon2 << endl;
    // hasDMA map2;
    // map2 = map;
    // cout << "Result of hasDMA assignment:\n";
    // cout << map2 << endl;


    // 改成使用指针
    baseDMA *p_shirt = new baseDMA("Portabelly", 8);
    baseDMA *p_balloon = new lacksDMA("red", "Blimpo", 4);
    baseDMA *p_map = new hasDMA("Mercator", "Buffalo Keys", 5);

    cout << "Displaying baseDMA object:\n";
    cout << *p_shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << *p_balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << *p_map << endl;

    // std::cin.get();
    return 0;
}

/*
测试结果:

Displaying baseDMA object:
Label: Portabelly
Rating: 8

Displaying lacksDMA object:
Label: Blimpo
Rating: 4

Displaying hasDMA object:
Label: Buffalo Keys
Rating: 5

分析: 结果表明, 当基类指针指向派生类对象时, 将基类指针解引用后
    作为重载的<<运算符函数的参数, 无法触发动态联编.
     也就是说, 这种情况下, 总是执行的基类中的重载<<运算符函数.
     原因暂时没有找到.

*/
