class Main inherits IO {
    a:Int <- 1;
    sum(num1:Int,num2:Int):Int{
        num1 + num2
    };
    f(n:Int):Int{
        {
            let sum:Int <- 1 in {
                while 0<n loop
                    {
                        sum <- sum * n;
                        n <- n-1;
                    }
                pool;
                sum;
            };
        }
    };
    main(): SELF_TYPE {
        {
            let b:Int <- 3,c:Int in
            {
                c <- 2;
                out_string("Hello, World.\n");
                out_int(sum(b,c));
            };
            out_string("123");
            out_int(f(5));
            out_string("\n");
            self;
        }

    };
};
