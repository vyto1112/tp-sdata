#ifndef Xcepts
#define Xcepts_

#include <exception>
#include <new>

class BadInitializersS
{
   public:
      BadInitializersS()
      {
  
      }

};

class NoMemS
{
   public:
      NoMemS()
      {
        
      }

};

void my_new_handlerS()
{
   throw NoMemS();
  
};

class OutOfBoundsS
{
   public:
      OutOfBoundsS()
      {
        
      }

};

class SizeMismatchS
{
   public:
      SizeMismatchS()
      {
        
      }

};

class MustBeZeroS
{
   public:
      MustBeZeroS()
      {
        
      }

};

class BadInputS
{
   public:
      BadInputS()
      {
        
      }

};

#endif