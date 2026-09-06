/**
 * @file factorymethod.cpp
 * @brief 工厂方法模式
 *
 *不同产品交给不同工厂来管, 扩展性更强
 */

#include <iostream>

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
  virtual Animal *createAnimal() = 0;
  virtual ~AnimalFactory() = default;
};

class DogFactory : public AnimalFactory
{
public:
  Animal *createAnimal() override
  {
    return new Dog();
  }
};

class CatFactory : public AnimalFactory
{
public:
  Animal *createAnimal() override
  {
    return new Cat();
  }
};

int main()
{
  DogFactory dogFactory;
  CatFactory catFactory;

  Animal *dog = dogFactory.createAnimal();
  dog->speak();
  Animal *cat = catFactory.createAnimal();
  cat->speak();

  delete dog;
  dog = nullptr;
  delete cat;
  cat = nullptr;

  return 0;
}