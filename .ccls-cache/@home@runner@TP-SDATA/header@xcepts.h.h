//214

#ifndef Xcept
#define Xcept_

#include <exception>
#include <new>

class BadInitializersK
{
   public:
      BadInitializersK()
      {
  
      }

};

class NoMemK
{
   public:
      NoMemK()
      {
        
      }

};

void my_new_handlerK()
{
   throw NoMemK();
  
};

class OutOfBoundsK
{
   public:
      OutOfBoundsK()
      {
        
      }

};

class SizeMismatchK
{
   public:
      SizeMismatchK()
      {
        
      }

};

class MustBeZeroK
{
   public:
      MustBeZeroK()
      {
        
      }

};

class BadInputK
{
   public:
      BadInputK()
      {
        
      }

};

#endif