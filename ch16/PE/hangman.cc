// 猜单词游戏
// 在程序清单16.3基础上的改进. 从文件中读取一系列单词, 并用vector<string>保存.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

const char kFilename[] = "wordlist.txt";
const int kMaxFail = 6;   // 最多猜错次数, 超出该数值游戏失败

int main() {
  // 从wordlist.txt文件中读取单词, 保存在一个vector<string>对象wordlist中
  // 文件中的单词之间应该以空格/制表符/换行符进行分隔
  ifstream infile;
  infile.open(kFilename, ios_base::in); // 打开文件
  if (infile.fail()) {
    cout << "File open failed: " << kFilename << endl;
    exit(EXIT_FAILURE);
  }
  vector<string> wordlist;
  string tmp;
  while (infile >> tmp) // 每次从文件中读取一个单词
    wordlist.emplace_back(tmp); // 并将单词追加到wordlist中
  for (string s: wordlist) cout << s << " ";
  cout << endl;

  srand(time(0));
  char choice;
  cout << "Will you play a word game? <y/n> ";
  cin >> choice;
  choice = tolower(choice);
  while (choice == 'y') { // 开始游戏
    // 程序随机选定一个待猜的单词
    string target = wordlist[rand() % wordlist.size()];
    int length = target.size();
    string attempt(length, '-');
    string badchars;
    int guesses = kMaxFail;
    cout << "Guess my secret word. It has " << length << " letters, and you"
         << " guess one letter at a time. You get " << guesses
         << " wrong guesses.\n";
    cout << "Your word: " << attempt << endl;
    while (guesses > 0 && attempt != target) {
      char letter;
      cout << "Guess a letter: ";
      cin >> letter;
      if (badchars.find(letter) != string::npos ||
          attempt.find(letter) != string::npos) {
        // 输入的是已经猜过的字母时, 提示重新输入.
        // 注意: 之前猜过的字母要么保存在badchars中, 要么保存在attempt中
        cout << "You already guessed that. Try again.\n";
        continue;
      }
      int loc = target.find(letter);
      if (loc == string::npos) {
        cout << "Oh, bad guess!\n";
        --guesses;
        badchars += letter; // 将猜错的字母统一保存到badchars中
      }
      else {
        cout << "Good guess!\n";
        attempt[loc] = letter;
        // 如果该字母在待猜单词中出现多次, 则应该一并显示它们
        loc = target.find(letter, loc + 1);
        while (loc != string::npos) {
          attempt[loc] = letter;
          loc = target.find(letter, loc + 1);
        }
      }
      cout << "Your word: " << attempt << endl;
      if (attempt != target) {
        if (badchars.length() > 0)
          cout << "Bad guesses: " << badchars << endl;
        cout << guesses << " wrong guess(es) left.\n";
      }
    }
    if (guesses > 0)
      cout << "That's right!\n";
    else {
      cout << "Sorry, the word is " << target << ".\n";
      cout << "Will you play another? <y/n> ";
      cin >> choice;
      choice = tolower(choice);
    }
  }
  cout << "Bye.\n";
}