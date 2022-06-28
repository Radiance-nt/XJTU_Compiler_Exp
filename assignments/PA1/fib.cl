-- 斐波那契数列
class Main inherits IO {
    s:Int;
    f(n:Int):Int{
        {
            let a:Int <- 1,t:Int <- 1,sum:Int <- 1 in {
                if n<3 then
                    1
                else {
                        while 2<n loop
                            {
                                t <- sum;
                                sum <- sum + a;
                                a <- t;
                                n <- n-1;
                            }
                        pool;
                        sum;
                    }
                fi;
            };
        }
    };
    main(): SELF_TYPE {
        {
            out_string("请输入：");
            s <- in_int();
            out_int(f(s));
            out_string("\n");
            self;
        }
    };
};
