//209

#ifndef Xceptt
#define Xceptt_

#include <exception>
#include <new>

class BadInitializers
{
   public:
      BadInitializers()
      {
  
      }

};

class NoMem
{
   public:
      NoMem()
      {
        
      }

};

void my_new_handler()
{
   throw NoMem();
  
};

class OutOfBounds
{
   public:
      OutOfBounds()
      {
        
      }

};

class SizeMismatch
{
   public:
      SizeMismatch()
      {
        
      }

};

class MustBeZero
{
   public:
      MustBeZero()
      {
        
      }

};

class BadInput
{
   public:
      BadInput()
      {
        
      }

};

#endif