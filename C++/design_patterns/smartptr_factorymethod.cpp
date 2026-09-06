/**
 * @file smartptr_factorymethod.cpp
 * @brief 智能指针的工厂方法模式
 *
 *不同产品交给不同工厂来管, 扩展性更强
 */

#include <iostream>
#include <memory>

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
  virtual std::unique_ptr<Animal> createAnimal() = 0;
  virtual ~AnimalFactory() = default;
};

class DogFactory : public AnimalFactory
{
public:
  std::unique_ptr<Animal> createAnimal() override
  {
    return std::make_unique<Dog>();
  }
};

class CatFactory : public AnimalFactory
{
public:
  std::unique_ptr<Animal> createAnimal() override
  {
    return std::make_unique<Cat>();
  }
};

int main()
{
  DogFactory dogFactory;
  CatFactory catFactory;

  auto dog = dogFactory.createAnimal();
  dog->speak();
  auto cat = catFactory.createAnimal();
  cat->speak();

  return 0;
}