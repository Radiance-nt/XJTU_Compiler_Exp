class A inherits B {};
class B inherits C {};
class C inherits A {};
class Main inherits IO
{
   main():SELF_TYPE
   {
      {
         out_string("Hello,World!\n");
      }
   };
};
