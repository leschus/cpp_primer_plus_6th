typedef int Item;

class List {
 public:
  List(int size = 0);
  ~List();
  bool append(const Item & item);
  bool full() const;
  bool empty() const;
  void visit(void (*pf)(Item &item)); // 访问列表中所有成员并执行操作(由函数pf指定)

 private:
  /* data */
  Item *plist_; // 使用动态数组实现列表
  int size_; // 列表的最大容量
  int current_idx; // 下一个追加至列表的元素的数组下标, 初始值为0, 最大值为size_-1
};