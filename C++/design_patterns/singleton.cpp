/**
 * @file singleton.cpp
 * @brief 单例模式的简单实现
 *
 * 确保程序运行期间该类只存在一个实例
 */
#include <iostream>
class Singleton
{
private:
  Singleton()
  {
    creatcount++;
    std::cout << "Singleton constructor called, creatcount:" << creatcount << std::endl;
  };
  inline static int creatcount = 0;

public:
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;

  static Singleton &getInstance()
  {
    static Singleton instance;
    std::cout << "getInstance() called, instance address:" << &instance << std::endl;
    return instance;
  }
};

int main()
{
  Singleton &a = Singleton::getInstance();
  Singleton &b = Singleton::getInstance();
  std::cout << "a address:" << &a << std::endl;
  std::cout << "b address:" << &b << std::endl;
}