/**
 * @file simplefactory.cpp
 * @brief 简单工厂模式
 *
 * 简单工厂通过统一的创建接口，根据传入的类型创建不同的具体对象，
 * 从而将对象的创建逻辑与对象的使用逻辑分离。
 * 缺点: 每增加一种产品，都必须修改原来的工厂
 */

#include <iostream>
#include <string>

class Animal
{
public:
  virtual void speak() = 0;
  virtual ~Animal()
  {
    std::cout << "Animal destructor called" << std::endl;
  }
};

class Dog : public Animal
{
public:
  void speak() override
  {
    std::cout << "wangwang" << std::endl;
  }
  ~Dog() override
  {
    std::cout << "Dog destructor called" << std::endl;
  }
};

class Cat : public Animal
{
public:
  void speak() override
  {
    std::cout << "miaomiao" << std::endl;
  }
  ~Cat() override
  {
    std::cout << "Cat destructor called" << std::endl;
  }
};

class AnimalFactory
{
public:
  static Animal *createAnimal(const std::string &type)
  {
    if (type == "dog")
    {
      return new Dog();
    }
    else if (type == "cat")
    {
      return new Cat();
    }
    return nullptr;
  }
};

int main()
{
  Animal *animal1 = AnimalFactory::createAnimal("dog");
  if (animal1 != nullptr)
  {
    animal1->speak();
  }
  Animal *animal2 = AnimalFactory::createAnimal("cat");
  if (animal2 != nullptr)
  {
    animal2->speak();
  }
  delete animal1;
  delete animal2;
  return 0;
}