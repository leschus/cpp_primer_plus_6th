//  map是一般意义上的键-值关联容器
// 其键和值一一对应, 而不像multimap中的一个键可以对应多个值
// 键和值的类型可以不同, 因此map接收两个模板类型参数, 分别是key_type和value_type

#include <map>
#include <iostream>
#include <algorithm>
#include <string>

using std::map;
using std::pair;
using std::cout;
using std::endl;
using std::string;
using std::make_pair;

int main() {
  // 用map保存string到int的键值映射关系, 表示不同姓名学生的CET4考试成绩
  map<string, int> cet4_score;
  // 向map中添加元素的方式比较特殊.
  // 由于每个元素都是键和值的组合, 因此STL使用模板类pair来将键和值组合为一个对象.
  // 下面的语句创建一个string-int键值对. (由于键不可修改, 因此pair的第一个模板类型被声明为
  // const)
  pair<const string, int> foo("Foo", 0);
  // 通过first和second访问pair中的内容
  cout << foo.first << ", " << foo.second << endl;
  typedef pair<const string, int> Pair; // 通过typedef减少代码量
  //  另一种创建pair对象的方式是使用模板函数std::make_pair(), 从而不需要在创建pair时
  // 先在<>内说明模板类型, 而是由编译器自动识别.
  auto bar = make_pair("Bar", 0); // bar的类型为pair<const char *, int>
                                  // 由于存在const char *到string类型的隐式转换,
                                  // 因此可以将bar插入为cet4_score的元素
  // 通过insert向map中插入元素
  cet4_score.insert(Pair("Bob", 601));
  cet4_score.insert(Pair("Micheal", 589));
  cet4_score.insert(make_pair("Daisy", 568));
  cet4_score.insert(make_pair("Sean", 609));
  // 通过迭代器遍历map中的元素, 可以发现: map内部自动根据元素的key进行排序, 默认为升序
  map<string, int>::iterator it;
  for (it = cet4_score.begin(); it != cet4_score.end(); it++) {
    cout << it->first << ", " << it->second << endl;
  }
  // 通过基于范围的for循环遍历map中的元素
  for (auto e: cet4_score) {
    cout << e.first << ", " << e.second << endl;
  }
}