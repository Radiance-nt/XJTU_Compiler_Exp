class A {
    str : String;
	li :  List;
};

Class BB__ inherits A {
    newline() : Object
	{
		out_string("\n")
	};
};


class Main inherits IO
{
   main():SELF_TYPE
   {
        while true loop
        ({
            out_string("Hello,World!\n");
        })
        pool
   };
};
